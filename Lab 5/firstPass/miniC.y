%{
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "codegenHelpers.h"
#include <stack>
#include <algorithm>

using namespace std;
#define YYERROR_VERBOSE 1

extern int yylex();
extern int yyparse();
extern int yyleng;
extern char* yytext;
extern int yylineno;
void yyerror(const char* s);

int ofc, nxtqd, sc, fnd, numPar;
string txt, condVar;
eletype rst;
vector<typeRecord*> typRecLst, gloVars;
stack<vector<typeRecord*> > paraLstStk;
typeRecord* variableRec;
vector<int> ddl;
vector<string> funcInstr, sthVar, dl;
registerSet Set_temp;
vector<funcEntry*> functionEntryRec, FuncCallPtrLst;
funcEntry* FuncActPtr;
funcEntry* FuncCallPtr;
bool errFnd;

vector<pair<string,int>> sVar;
%} 

%code requires{
    #include "codegenHelpers.h"
}

%union {
    float floatval;
    int intval;
    char *idName;
    int quad;

    struct expression expr;
    struct stmt stmtval;
    struct switchcaser switchCase;
    struct switchtemp switchTemp;
    struct whileexp whileexpval;
    struct shortcircuit shortCircuit;
    struct condition2temp ctemp;
}

%token INT FLOAT VOID NUMFLOAT NUMINT ID NEWLINE READ PRINT
%token COLON QUESTION DOT LCB RCB LSB RSB LP RP SEMI COMMA ASSIGN
%token IF ELSE CASE BREAK DEFAULT CONTINUE WHILE FOR RETURN SWITCH MAIN
%token LSHIFT RSHIFT PLUSASG MINASG MULASG MODASG DIVASG INCREMENT DECREMENT XOR BITAND BITOR PLUS MINUS DIV MUL MOD
%token NOT AND OR LT GT LE GE EQUAL NOTEQUAL

%type <idName> NUMFLOAT
%type <idName> NUMINT
%type <idName> ID
%type <expr> EXPR2 TERM FACTOR ID_ARR ASG ASG1 EXPR1 EXPR21 LHS FUNC_CALL BR_DIMLIST
%type <whileexpval> WHILEEXP IFEXP N3 P3 Q3 FOREXP TEMP1
%type <stmtval> BODY WHILESTMT IFSTMT M2 FORLOOP STMT STMT_LIST
%type <quad> M1 M3 Q4 
%type <shortCircuit> CONDITION1 CONDITION2
%type <switchCase> CASELIST
%type <switchTemp> TEMP2
%type <ctemp> TP1
%%

MAIN_PROG: PROG MAINFUNCTION
    | MAINFUNCTION
;

PROG: PROG FUNC_DEF
    | PROG VAR_DECL
    | FUNC_DEF
    | VAR_DECL
;

MAINFUNCTION: MAIN_HEAD LCB BODY RCB
    {
        delVarLst(FuncActPtr, sc);
        sc=0;
        FuncActPtr=NULL;
        string s = "function end";
        gen(funcInstr, s, nxtqd);
    }
;

MAIN_HEAD: INT MAIN LP RP
    {   
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string("main");
        FuncActPtr->returnType = INTEGER;
        FuncActPtr->numofpars = 0;
        FuncActPtr->parameterList.clear();
        FuncActPtr->variableList.clear();  
        FuncActPtr->functionOffset = 0;      ;
        typRecLst.clear();
        searchFunction(FuncActPtr, functionEntryRec, fnd);
        if (fnd) {
            cout << "ERROR : Line no. " << yylineno << ", Function " << FuncActPtr->name <<  " is getting re-declared." << endl;
            delete FuncActPtr;
            FuncActPtr = NULL;
        }   
        else {
            addFunction(FuncActPtr, functionEntryRec);
            string s = "function begin main";
            sc = 2; 
            gen(funcInstr, s, nxtqd);
        }
    }
;

FUNC_DEF: FUNC_HEAD LCB BODY RCB
    {
        delVarLst(FuncActPtr, sc); 
        string s = "function end";
        FuncActPtr = NULL;
        sc = 0;
        gen(funcInstr, s, nxtqd);
    }
;

FUNC_HEAD: RES_ID LP DECL_PLIST RP
    {
        int fnd = 0;
        searchFunction(FuncActPtr, functionEntryRec, fnd);
        if(fnd){
            cout << "ERROR : Line no. " << yylineno << ": Function " << FuncActPtr->name <<  " is being re-declared" << endl;
            errFnd = true;
            delete FuncActPtr;
        }   
        else{
            FuncActPtr->numofpars = typRecLst.size();
            FuncActPtr->functionOffset = 0;
            FuncActPtr->parameterList = typRecLst;
            typRecLst.clear();
            addFunction(FuncActPtr, functionEntryRec);
            string s = "function begin _" + FuncActPtr->name;
            sc = 2; 
            gen(funcInstr, s, nxtqd);
        }
    }
; 

RES_ID: T ID       
    {   
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string($2);
        FuncActPtr->returnType = rst;
    } 
    | VOID ID
    {
        sc=1;
        FuncActPtr = new funcEntry;
        FuncActPtr->name = string($2);
        FuncActPtr->returnType = NULLVOID;
    }
;




DECL_PLIST: DECL_PL
    | %empty
;

DECL_PL: DECL_PL COMMA DECL_PARAM
    {
        typeRecord* pn = NULL;
        int fnd = 0;
        searchPars(variableRec->name, typRecLst, fnd, pn);
        if(fnd){
            cout << "ERROR : Line no. " << yylineno << " Redeclaration of parameter " << variableRec->name <<endl;
        } else {
            typRecLst.push_back(variableRec);
        }
        
    }
    | DECL_PARAM
    {  
        typeRecord* pn = NULL;
        int fnd = 0;
        searchPars(variableRec->name, typRecLst, fnd , pn );
        if (fnd){
            cout << "ERROR : Line no. " << yylineno << ": Redeclaration of parameter " << variableRec->name <<endl;
        } else {
            typRecLst.push_back(variableRec);
        }
    }
;

DECL_PARAM: T ID
    {
        variableRec = new typeRecord;
        variableRec->name = string($2);
        variableRec->sc = sc;
        variableRec->type = SIMPLE;
        variableRec->tag = VARIABLE;
        variableRec->eleType = rst;
    }
;

BODY: STMT_LIST
    {
		$$.brkLst = new vector<int>;
        merge($$.brkLst, $1.brkLst);
        $$.nxtLst = new vector<int>;
        merge($$.nxtLst, $1.nxtLst);
        $$.contLst = new vector<int>;
        merge($$.contLst, $1.contLst);
    }
    | %empty 
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector<int>;
    }
;

STMT_LIST: STMT_LIST STMT 
    {
		$$.brkLst = new vector<int>;
        merge($$.brkLst, $1.brkLst);
        merge($$.brkLst, $2.brkLst);
        $$.nxtLst = new vector<int>;
        merge($$.nxtLst, $1.nxtLst);
        merge($$.nxtLst, $2.nxtLst);
        $$.contLst = new vector<int>;
        merge($$.contLst, $1.contLst);
        merge($$.contLst, $2.contLst);
    }
    | STMT 
    {
    	$$.brkLst = new vector<int>;
        merge($$.brkLst, $1.brkLst);
        $$.nxtLst = new vector<int>;
        merge($$.nxtLst, $1.nxtLst);
        $$.contLst = new vector<int>;
        merge($$.contLst, $1.contLst);
    }
;

STMT: VAR_DECL
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
    }
    | ASG SEMI
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        if ($1.type != NULLVOID && $1.type != ERRORTYPE)
            Set_temp.freeRegister(*($1.registerName));
    } 
    | FORLOOP
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
    }
    | IFSTMT
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        merge($$.contLst, $1.contLst);
        merge($$.brkLst, $1.brkLst);

    }
    | WHILESTMT
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
    }
    | SWITCHCASE
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
    }
    | LCB {sc++;} BODY RCB 
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        delVarLst(FuncActPtr, sc);
        sc--;
        merge($$.contLst, $3.contLst);
        merge($$.brkLst, $3.brkLst);
    }
    | BREAK SEMI
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        $$.brkLst->push_back(nxtqd);  
        gen(funcInstr, "goto L", nxtqd);      
    }
    | CONTINUE SEMI
    {

        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        $$.contLst->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
    | RETURN ASG1 SEMI 
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        if ($2.type != ERRORTYPE && FuncActPtr != NULL) {
            if (FuncActPtr->returnType == NULLVOID && $2.type != NULLVOID) {
                cout << "ERROR : Line no. " << yylineno << " Function " << FuncActPtr->name << " should return void type, not " << $2.type << endl;
            }
            else if (FuncActPtr->returnType != NULLVOID && $2.type == NULLVOID) {
                cout << "ERROR : Line no. " << yylineno << ": function " << FuncActPtr->name << " should return non-void type" << endl;
            }
            else {
                string s;
                if (FuncActPtr->returnType != NULLVOID && $2.type != NULLVOID) {
                    if ($2.type == INTEGER && FuncActPtr->returnType == FLOATING)  {
                        string floatReg = Set_temp.getFloatRegister();
                        s = floatReg + " = " + "convertToFloat(" + *($2.registerName) + ")";
                        cout << "Warning : " << "Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd);
                        s = "return " + floatReg;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*($2.registerName));
                        Set_temp.freeRegister(floatReg);
                    }
                    else if ($2.type == FLOATING && FuncActPtr->returnType == INTEGER) {
                        string intReg = Set_temp.getRegister();
                        s = intReg + " = " + "convertToInt(" + *($2.registerName) + ")";
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion"<< endl;
                        gen(funcInstr, s, nxtqd);
                        s = "return " + intReg;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*($2.registerName));
                        Set_temp.freeRegister(intReg);                        
                    }
                    else {
                        s = "return " + *($2.registerName);
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*($2.registerName));
                    }
                }
                else if (FuncActPtr->returnType == NULLVOID && $2.type == NULLVOID) {
                    s = "return";
                    gen(funcInstr, s, nxtqd);
                }
                else {
                    errFnd = 1;
                    cout << "ERROR : Line no. " << yylineno << ": Exactly one of function " << FuncActPtr->name << "and this return statement has void return type" << endl;
                    if ($2.type != NULLVOID) Set_temp.freeRegister(*($2.registerName));
                } 
            }
        }
    }
    | READ ID_ARR SEMI
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        if($2.type == ERRORTYPE){
            errFnd = true;
        }
        else{
            string registerName;
            if ($2.type == INTEGER){
                registerName = Set_temp.getRegister();
            }
            else {
                registerName = Set_temp.getFloatRegister();
            }
            string s;
            s = "read " + registerName;
            gen(funcInstr, s, nxtqd);
            s = (*($2.registerName)) + " = " +  registerName;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(registerName);
            if ($2.offsetRegName != NULL) Set_temp.freeRegister(*($2.offsetRegName));
        }
    }
    | PRINT ID_ARR SEMI
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        if($2.type == ERRORTYPE){
            errFnd = true;
        }
        else{
            string registerName;
            if ($2.type == INTEGER){
                registerName = Set_temp.getRegister();
            }
            else {
                registerName = Set_temp.getFloatRegister();
            }
            string s = registerName + " = " + (*($2.registerName)) ;
            gen(funcInstr, s, nxtqd);
            s = "print " + registerName;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(registerName);
            if ($2.offsetRegName != NULL) Set_temp.freeRegister(*($2.offsetRegName));
        }
    }
    | error SEMI
    {
        errFnd = 1;
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + ": Syntax error" << endl;
    }
    | error
    {
        errFnd = 1;
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + ": Syntax error" << endl;
    }
;

VAR_DECL: D SEMI 
;

D: T L
    { 
        patchDT(rst, typRecLst, sc);
        if(sc > 1){
            insertSymTable(typRecLst, FuncActPtr);
            
        }
        else if(sc == 0){
            insertGVars(typRecLst, gloVars);
        }
        typRecLst.clear();
    }
;

T:  INT         { rst = INTEGER; }
    | FLOAT     { rst = FLOATING; }
;    

L: DEC_ID_ARR
    | L COMMA DEC_ID_ARR      
;

DEC_ID_ARR: ID
    {   
        typeRecord* vn = NULL;
        int fnd = 0;
        if(FuncActPtr!=NULL && sc > 0){
            searchVars(string($1), FuncActPtr, fnd, vn, sc);
            if (fnd) {
                if(vn->isValid==true){
                    cout << "ERROR : Line no. :" << yylineno << " The Variable " << string($1) << " is already declared at same level " << sc << endl ;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        vn->maxdloffset = max(vn->maxdloffset,1);
                        vn->type=SIMPLE;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string($1);
                        variableRec->sc = sc;
                        variableRec->isValid=true;
                        variableRec->type = SIMPLE;
                        variableRec->tag = VARIABLE;
                        variableRec->maxdloffset=1;
                        typRecLst.push_back(variableRec);
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string($1), FuncActPtr->parameterList, fnd , pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string($1) << " is already declared in parameters " << endl ;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string($1);
                    variableRec->sc = sc;
                    variableRec->isValid=true;
                    variableRec->type = SIMPLE;
                    variableRec->tag = VARIABLE;
                    variableRec->maxdloffset=1;
                    typRecLst.push_back(variableRec);
                }
            }
            else {
                variableRec = new typeRecord;
                variableRec->name = string($1);
                variableRec->sc = sc;
                variableRec->isValid=true;
                variableRec->maxdloffset=1;
                variableRec->type = SIMPLE;
                variableRec->tag = VARIABLE;
                typRecLst.push_back(variableRec);
            }
        }
        else if(sc == 0){
            searchGVars(string($1), gloVars, fnd, vn, sc);
            if (fnd) {
                cout << "ERROR : Line no. :" << yylineno << " The Variable " << string($1) << " is already declared at global level " << endl ;
            }
            else{
                variableRec = new typeRecord;
                variableRec->name = string($1);
                variableRec->isValid=true;
                variableRec->type = SIMPLE;
                variableRec->sc = sc;
                variableRec->maxdloffset=1;
                variableRec->tag = VARIABLE;
                typRecLst.push_back(variableRec);   
            }
        } 
        else {
            errFnd = true;
        }
        
    }
    | ID ASSIGN ASG
    {
        typeRecord* vn = NULL;
        int fnd = 0;
        if(FuncActPtr!=NULL){
            searchVars(string($1), FuncActPtr, fnd, vn, sc);
            bool varCreated = false;;
            if (fnd) {
                if(vn->isValid==true){
                    cout << " ERROR : Line no. :" << yylineno << " The Variable " << string($1) << " is already declared at same level " << sc << endl ;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        vn->maxdloffset = max(vn->maxdloffset,1);
                        vn->type=SIMPLE;
                        varCreated = true;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string($1);
                        variableRec->type = SIMPLE;
                        variableRec->sc = sc;
                        variableRec->isValid=true;
                        variableRec->tag = VARIABLE;
                        variableRec->maxdloffset=1;
                        typRecLst.push_back(variableRec);
                        varCreated = true;
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string($1), FuncActPtr->parameterList, fnd , pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string($1) << " is already declared at parameter level " << endl ;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string($1);
                    variableRec->sc = sc;
                    variableRec->maxdloffset=1;
                    variableRec->isValid=true;
                    variableRec->type = SIMPLE;
                    variableRec->tag = VARIABLE;
                    typRecLst.push_back(variableRec);
                    varCreated = true;
                }
            }
            else {
                variableRec = new typeRecord;
                variableRec->name = string($1);
                variableRec->type = SIMPLE;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                variableRec->maxdloffset=1;
                variableRec->isValid=true;
                typRecLst.push_back(variableRec);
                varCreated = true;
            }
            if(varCreated){
                if ($3.type == ERRORTYPE) {
                    errFnd = true;
                }
                else if ($3.type == NULLVOID) {
                    cout << "ERROR : Line no. " << yylineno << ": Cannot assign void to non-void type " << string($1) << endl;
                    errFnd = true;
                }
                else {
                    string registerName;
                    if (rst == INTEGER && $3.type == FLOATING) {
                        registerName = Set_temp.getRegister();
                        string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd);
                        Set_temp.freeRegister(*($3.registerName));
                    }
                    else if(rst == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                        registerName = Set_temp.getFloatRegister();
                        string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")"; 
                        cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                        gen(funcInstr, s, nxtqd); 
                        Set_temp.freeRegister(*($3.registerName));
                    }
                    else {
                        registerName = *($3.registerName);
                    }
                    string dataType = eletypeMapper(rst);
                    dataType += "_" + to_string(sc);
                    string s =  "_" + string($1) + "_" + dataType + " = " + registerName ;
                    gen(funcInstr, s, nxtqd);
                    Set_temp.freeRegister(registerName);
                }   
            }
        }
        else if(sc == 0){
            cout << "ERROR : Line No " << yylineno << " ID assignments not allowed in global level variable " << string($1) << endl;
            errFnd = true;
        }
        else {
            errFnd = true;
        }
    }
    | ID DEC_BR_DIMLIST
    {  
        if (FuncActPtr != NULL) {
            typeRecord* vn = NULL;
            int fnd = 0;
            searchVars(string($1), FuncActPtr, fnd, vn,sc); 
            if (fnd) {
                if(vn->isValid==true){
                    cout << "ERROR : Line no. " << yylineno << " The Variable " << string($1) << " is already declared at same level " << sc << endl;
                }
                else{
                    if(vn->eleType == rst){
                        vn->isValid=true;
                        int a=1;
                        for(auto it : ddl){
                            a*=(it);
                        }
                        vn->maxdloffset = max(vn->maxdloffset,a);
                        if(vn->type==ARRAY){
                            vn->dl.clear();           
                        }
                        vn->type=ARRAY;
                        vn->dl = ddl;
                    }
                    else {
                        variableRec = new typeRecord;
                        variableRec->name = string($1);
                        variableRec->type = ARRAY;
                        variableRec->sc = sc;
                        variableRec->dl = ddl;
                        variableRec->tag = VARIABLE;
                        variableRec->isValid=true;
                        int a=1;
                        for(auto it : ddl){
                            a*=(it);
                        }
                        variableRec->maxdloffset = a;
                        typRecLst.push_back(variableRec);
                    }
                }
            }
            else if (sc == 2) {
                typeRecord* pn = NULL;
                searchPars(string($1), FuncActPtr->parameterList, fnd, pn);
                if (fnd) {
                    cout << "ERROR : Line no. " << yylineno << "The Variable " << string($1) << " is already declared at parameter level " << endl;
                } 
                else {
                    variableRec = new typeRecord;
                    variableRec->name = string($1);
                    variableRec->type = ARRAY;
                    variableRec->dl = ddl;
                    variableRec->isValid=true;
                    variableRec->tag = VARIABLE;
                    variableRec->sc = sc;
                    
                    int a=1;
                    for(auto it : ddl){
                        a*=(it);
                    }
                    variableRec->maxdloffset = a;
                    typRecLst.push_back(variableRec);
                }
            }
            else{
                variableRec = new typeRecord;        
                variableRec->name = string($1);
                variableRec->type = ARRAY;
                variableRec->dl = ddl;
                variableRec->isValid=true;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                
                int a=1;
                for(auto it : ddl){
                    a*=(it);
                }
                variableRec->maxdloffset = a;
                typRecLst.push_back(variableRec);
            }
        } 
        else if(sc == 0){
            typeRecord* vn = NULL;
            searchGVars(string($1), gloVars, fnd, vn, sc);
            if (fnd) {
                cout << "ERROR : Line no. " << yylineno << " The Variable " << string($1) << " is already declared at global level " << endl;
            }
            else{
                variableRec = new typeRecord;
                variableRec->name = string($1);
                variableRec->type = ARRAY;
                variableRec->tag = VARIABLE;
                variableRec->sc = sc;
                variableRec->dl = ddl;
                variableRec->isValid=true;
                int a=1;
                for(auto it : ddl){
                    a*=(it);
                }
                variableRec->maxdloffset = a;
                typRecLst.push_back(variableRec);   
            }
        }   
        else{
            errFnd = 1;
        }
        ddl.clear();
    }
;

DEC_BR_DIMLIST: LSB NUMINT RSB
    {
        ddl.push_back(atoi($2));
    }
    | DEC_BR_DIMLIST LSB NUMINT RSB 
    {
        ddl.push_back(atoi($3));
    }
;

FUNC_CALL: ID LP PARAMLIST RP
    {
        FuncCallPtr = new funcEntry;
        FuncCallPtr->name = string($1);
        FuncCallPtr->numofpars = typRecLst.size();
        FuncCallPtr->parameterList = typRecLst;
        
        int fnd = 0;
        int vfound=0;
        typeRecord* vn;
        searchVars(FuncCallPtr->name,FuncActPtr,vfound,vn,sc);
        if (vfound) {
            $$.type = ERRORTYPE;
            cout<< "ERROR : Line no." << yylineno << " The object being called "<< FuncCallPtr->name << " is not a function or function pointer"<< endl;
        }
        else {
            compareFunction(FuncCallPtr,functionEntryRec,fnd);
            $$.type = ERRORTYPE;
            if (fnd == 0) {
                cout << "ERROR : Line no. " << yylineno << " There does not exist a function with name " << string($1)  << endl;
            }
            else if (fnd == -1) {
                cout << "ERROR : Line no. " << yylineno << " Call parameter list does not match with defined paramters of function " << string($1) << endl;
            }
            else {
                $$.type = FuncCallPtr->returnType;
                if(FuncCallPtr->returnType == INTEGER){
                    $$.registerName = new string(Set_temp.getRegister());
                    gen(funcInstr, "refparam " + (*($$.registerName)), nxtqd);
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size() + 1 ), nxtqd);      
                }
                else if(FuncCallPtr->returnType == FLOATING){
                    $$.registerName = new string(Set_temp.getFloatRegister());
                    gen(funcInstr, "refparam " + (*($$.registerName)), nxtqd);
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size() + 1 ), nxtqd);      
                }
                else if (FuncCallPtr->returnType == NULLVOID) {
                    $$.registerName = NULL;
                    gen(funcInstr, "call _" + FuncCallPtr->name + ", " + to_string(typRecLst.size()), nxtqd);      
                }
                else {
                    cout << "ERROR : Line no. " << yylineno << ": Illegal return type of function " << FuncCallPtr->name << endl;
                }
            }
        }
        typRecLst.clear();
        typRecLst.swap(paraLstStk.top());
        paraLstStk.pop();
    }
;

PARAMLIST: PLIST
    | {paraLstStk.push(typRecLst); typRecLst.clear();} %empty 
;

PLIST: PLIST COMMA ASG
    {
        variableRec = new typeRecord;
        variableRec->eleType = $3.type;
        if ($3.type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            variableRec->name = *($3.registerName);
            variableRec->type = SIMPLE;
            gen(funcInstr, "param " +  *($3.registerName), nxtqd);   
            Set_temp.freeRegister(*($3.registerName));
        }
        typRecLst.push_back(variableRec);
    }
    | {paraLstStk.push(typRecLst); typRecLst.clear();} ASG
    {
        variableRec = new typeRecord;
        variableRec->eleType = $2.type;
        if ($2.type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            variableRec->name = *($2.registerName);
            variableRec->type = SIMPLE; 
            gen(funcInstr, "param " +  *($2.registerName), nxtqd);   
            Set_temp.freeRegister(*($2.registerName));
        }
        typRecLst.push_back(variableRec);
    }
;

ASG: CONDITION1
    {
        $$.type = $1.type;
        if($$.type != ERRORTYPE && $$.type != NULLVOID) {
            $$.registerName = $1.registerName;
            if($1.jmpLst!=NULL){
                vector<int>* qList = new vector<int>;
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch($1.jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*($$.registerName)) + " = 1",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                qList->clear();
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
            }
        }
    }
    | LHS ASSIGN ASG
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            string registerName;
            $$.type = $1.type;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS PLUSASG ASG
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";  
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, tempReg;
            if($1.type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*($1.registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*($1.registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " + " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS MINASG ASG
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")"; 
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, tempReg;
            if($1.type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*($1.registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*($1.registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " - " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS MULASG ASG
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR :Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")"; 
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";  
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, tempReg;
            if($1.type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*($1.registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*($1.registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " * " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS DIVASG ASG
    {
        if ($3.type == ERRORTYPE || $1.type == ERRORTYPE ) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, tempReg;
            if($1.type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*($1.registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*($1.registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " / " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS MODASG ASG
    {
        if (  $3.type == ERRORTYPE || $1.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if ($3.type == NULLVOID) {
            cout << "ERROR : Line no. " << yylineno << " Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else {
            string registerName;
            $$.type = $1.type;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = Set_temp.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = Set_temp.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                gen(funcInstr, s, nxtqd); 
                Set_temp.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, tempReg;
            if($1.type == INTEGER){
                tempReg = Set_temp.getRegister();
                s = tempReg + " = " + (*($1.registerName));
                gen(funcInstr, s, nxtqd);
            }
            else{
                tempReg = Set_temp.getFloatRegister();
                s = tempReg + " = " + (*($1.registerName));   
                gen(funcInstr, s, nxtqd);
            }
            s = registerName + " = " + registerName + " % " + tempReg;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(tempReg);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(funcInstr, s, nxtqd);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) Set_temp.freeRegister(*($1.offsetRegName));
        }
    }
;

LHS: ID_ARR  
    {
        $$.type = $1.type;
        if ($$.type != ERRORTYPE) {
            $$.registerName = $1.registerName;
            $$.offsetRegName = $1.offsetRegName;
        } 
    } 
;

SWITCHCASE: SWITCH LP ASG RP TEMP1 LCB  CASELIST RCB 
    {
        delVarLst(FuncActPtr,sc);
        sc--;

        int q=nxtqd;
        vector<int>* qList = new vector<int>;
        qList->push_back(q);
        gen(funcInstr, "goto L", nxtqd);
        backpatch($5.falseList, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        reverse($7.casepair->begin(), $7.casepair->end());
        for(auto it : *($7.casepair)){
            if(it.first == "default"){
                gen(funcInstr, "goto L"+to_string(it.second), nxtqd);
            }
            else{
                gen(funcInstr, "if "+ (*($3.registerName)) +" == "+ it.first + " goto L" + to_string(it.second), nxtqd);
            }
        }
        $7.casepair->clear();
        backpatch(qList, nxtqd, funcInstr);
        backpatch($7.brkLst, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
;

TEMP1: %empty
    {
        $$.begin=nxtqd;
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
        sc++;
    }
;

TEMP2:%empty
    {
        $$.casepair = new vector<pair<string,int>>;

    }
;

CASELIST:
    CASE MINUS NUMINT TEMP2 {
        $4.casepair->push_back(make_pair("-"+string($3), nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        } COLON BODY 
    CASELIST
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        $$.casepair = new vector<pair<string,int>>;
        merge($$.brkLst, $8.brkLst);
        merge($$.contLst,$8.contLst);
        merge($$.nxtLst, $8.nxtLst);
        merge($$.contLst,$7.contLst);
        merge($$.nxtLst, $7.nxtLst);
        merge($$.brkLst, $7.brkLst);
        mergeSwitch($$.casepair, $8.casepair);
        mergeSwitch($$.casepair, $4.casepair);
    }
    |
    CASE NUMINT TEMP2 {
        $3.casepair->push_back(make_pair(string($2), nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        } COLON BODY 
    CASELIST
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        $$.casepair = new vector<pair<string,int>>;
        merge($$.brkLst, $6.brkLst);
        merge($$.contLst,$6.contLst);
        merge($$.nxtLst, $6.nxtLst);
        merge($$.contLst,$7.contLst);
        merge($$.brkLst, $7.brkLst);
        merge($$.nxtLst, $7.nxtLst);
        mergeSwitch($$.casepair, $7.casepair);
        mergeSwitch($$.casepair, $3.casepair);
    }
    | %empty
    {
        $$.brkLst = new vector<int>;
        $$.nxtLst = new vector<int>;
        $$.contLst = new vector <int>;
        $$.casepair = new vector<pair<string,int>>;
    }
    | DEFAULT COLON TEMP2 {
        $3.casepair->push_back(make_pair("default", nxtqd));
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
     BODY {
        $$.nxtLst = new vector<int>;
        $$.brkLst = new vector<int>;
        $$.casepair = new vector<pair<string,int>>;
        $$.contLst = new vector <int>;
        merge($$.brkLst, $5.brkLst);
        merge($$.contLst,$5.contLst);
        merge($$.nxtLst, $5.nxtLst);
        mergeSwitch($$.casepair, $3.casepair);
    }
;

M3: %empty
    { 
        $$ = nxtqd;
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
    }
;

N3: %empty
    { 
        $$.begin = nxtqd; 
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
;

P3: %empty 
    { 
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
        $$.begin = nxtqd; 
        gen(funcInstr, "L"+to_string(nxtqd)+":", nxtqd);
    }
;

Q3: %empty
    {
        $$.begin = nxtqd;
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nxtqd);
    }
;

Q4: %empty
    {
        $$ = nxtqd;
    }
;

FORLOOP: FOREXP Q4 LCB BODY RCB
    {
        delVarLst(FuncActPtr, sc);
        sc--;
        gen(funcInstr, "goto L" + to_string($1.begin), nxtqd); 
        merge($1.falseList,$4.brkLst);
        backpatch($4.contLst,$1.begin, funcInstr);
        backpatch($1.falseList, nxtqd, funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
    }
;

FOREXP: FOR LP ASG1 SEMI M3 ASG1 Q3 {
        if($6.type!=NULLVOID){
            gen(funcInstr, "if "+ (*($6.registerName)) + " == 0 goto L", nxtqd);
        }
    } P3 SEMI ASG1 N3 RP 
    {
        backpatch($12.falseList,$5,funcInstr);
        backpatch($9.falseList,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd); 
        $$.falseList = new vector<int>;
        if($6.type!=NULLVOID){
            $$.falseList->push_back($7.begin);            
        }
        $$.begin = $9.begin;
        sc++;
        if($3.type!=NULLVOID){
            Set_temp.freeRegister(*($3.registerName));
        }
        if($6.type!=NULLVOID){
            Set_temp.freeRegister(*($6.registerName));
        }
        if($11.type!=NULLVOID){
            Set_temp.freeRegister(*($11.registerName));
        }
    }
    | FOR error RP
    {
        errFnd = 1;
        $$.falseList = new vector<int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + " Syntax error in for loop, discarded token till RP" << endl;
        sc++;
    }
;

ASG1: ASG
    {
        $$.type= $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName;
        }
    }
    | %empty {
        $$.type = NULLVOID;
    }
;

M1: %empty
    {
        $$=nxtqd;
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
;

M2: %empty
    {
        $$.nxtLst = new vector<int>;
        ($$.nxtLst)->push_back(nxtqd);
        gen(funcInstr, "goto L", nxtqd);
    }
;

IFSTMT: IFEXP LCB BODY RCB 
    {
        delVarLst(FuncActPtr,sc);
        sc--;
        $$.brkLst = new vector<int>;
        $$.nxtLst= new vector<int>;
        $$.contLst= new vector<int>;
        merge($$.brkLst, $3.brkLst);
        merge($$.nxtLst, $1.falseList);
        merge($$.contLst, $3.contLst);
        backpatch($$.nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
    | IFEXP LCB BODY RCB {delVarLst(FuncActPtr,sc);} M2 ELSE M1 LCB BODY RCB
    {
        delVarLst(FuncActPtr,sc);
        sc--;
        $$.brkLst = new vector<int>;
        $$.nxtLst= new vector<int>;
        $$.contLst= new vector<int>;
        backpatch($1.falseList,$8,funcInstr);
        merge($$.nxtLst,$6.nxtLst );
        backpatch($$.nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
        merge($$.brkLst, $3.brkLst);
        merge($$.contLst, $3.contLst);
        merge($$.brkLst, $10.brkLst);
        merge($$.contLst, $10.contLst);
    }
;

IFEXP: IF LP ASG RP 
    {
        if($3.type != ERRORTYPE && $3.type!=NULLVOID){
            $$.falseList = new vector <int>;
            $$.falseList->push_back(nxtqd);
            if($3.type == NULLVOID){
                cout << "ERROR : Line no. " << yylineno << "if statement condition can't be empty" << endl;
                errFnd=true;
            }
            gen(funcInstr, "if "+ (*($3.registerName)) + " == 0 goto L", nxtqd);
            sc++;
            Set_temp.freeRegister(*($3.registerName));
        } 
    }
    | IF error RP
    {
        $$.falseList = new vector <int>;
        errFnd = 1;
        cout << "ERROR : Line no. " + to_string(yylineno) + " There is Syntax error in if statement, discarding tokens till RP" << endl;
        sc++;
    }
;

WHILESTMT:  WHILEEXP LCB BODY RCB 
    {
        delVarLst(FuncActPtr,sc);
        sc--;

        gen(funcInstr, "goto L" + to_string($1.begin), nxtqd);
        backpatch($3.nxtLst, $1.begin, funcInstr);
        backpatch($3.contLst, $1.begin, funcInstr);
        $$.nxtLst = new vector<int>;
        merge($$.nxtLst, $1.falseList);
        merge($$.nxtLst, $3.brkLst);
        backpatch($$.nxtLst,nxtqd,funcInstr);
        gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
    }
;

WHILEEXP: WHILE M1 LP ASG RP
    {
        sc++;
        if($4.type == NULLVOID || $4.type == ERRORTYPE){
            errFnd = true;
            cout << "ERROR : Line no. " << yylineno << " The Expression in if statement can't be empty"<<endl;
        }
        else{
            $$.falseList = new vector<int>;
            ($$.falseList)->push_back(nxtqd);
            gen(funcInstr, "if " + *($4.registerName) + "== 0 goto L", nxtqd);
            $$.begin = $2; 
        }
    }
    | WHILE error RP
    {   
        $$.falseList = new vector<int>;
        cout << "ERROR : Line no. " + to_string(yylineno) + " There's a Syntax error in while loop, discarding tokens till RP" << endl;
        sc++;
    }
;

TP1: %empty
{
    $$.temp = new vector<int>;
}
;

CONDITION1: CONDITION1 TP1
    {
        if($1.type!=ERRORTYPE){
            $2.temp->push_back(nxtqd);
            gen(funcInstr, "if " + *($1.registerName) + "!= 0 goto L", nxtqd);

        }
    }
     OR CONDITION2
    {
        if( $5.type==ERRORTYPE || $1.type==ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $5.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << " Both the expessions are NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());
            vector<int>* qList = new vector<int>;
            if($5.jmpLst!=NULL){
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch($5.jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*($5.registerName)) + " = 0",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                qList->clear();
            }
            
            $$.jmpLst = new vector<int>;
            merge($$.jmpLst,$1.jmpLst);
            
            merge($$.jmpLst, $2.temp);
            ($$.jmpLst)->push_back(nxtqd);
            gen(funcInstr, "if " + *($5.registerName) + "!= 0 goto L", nxtqd);
            string s = (*($$.registerName)) + " = 0";   
            gen(funcInstr,s,nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($5.registerName)); 
        }
    }
    | CONDITION2
    {
        $$.type = $1.type;
        if ($$.type != ERRORTYPE && $$.type != NULLVOID) {
            $$.registerName = $1.registerName; 
            if($1.jmpLst!=NULL){
                vector<int>* qList = new vector<int>;
                qList->push_back(nxtqd);
                gen(funcInstr,"goto L",nxtqd);
                backpatch($1.jmpLst, nxtqd, funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                gen(funcInstr,(*($$.registerName)) + " = 0",nxtqd) ;
                backpatch(qList,nxtqd,funcInstr);
                gen(funcInstr, "L" + to_string(nxtqd) + ":", nxtqd);
                qList->clear();   
            }
        }
    }
;  


CONDITION2: CONDITION2 TP1
    {
      if ($1.type!=ERRORTYPE ){

          ($2.temp)->push_back(nxtqd);
         gen(funcInstr, "if " + *($1.registerName) + " == 0 " +" goto L", nxtqd);
      } 
    }
    AND EXPR1 
    {
        if (  $5.type==ERRORTYPE || $1.type==ERRORTYPE) {
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $5.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ": Both the expessions are NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());
            $$.jmpLst = new vector<int>;
            merge($$.jmpLst,$1.jmpLst);
            vector<int>* qList = new vector<int>;
            
            merge($$.jmpLst, $2.temp);
            ($$.jmpLst)->push_back(nxtqd);
            gen(funcInstr, "if " + *($5.registerName) + " == 0 "+" goto L", nxtqd);

            string s = (*($$.registerName)) + " = 1";   
            gen(funcInstr,s,nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($5.registerName));   
        }
    }
    | EXPR1
    {
        $$.type = $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName; 
            $$.jmpLst = new vector<int>;
            $$.jmpLst=NULL;   
        }
    }
;

EXPR1: NOT EXPR21
    {
        $$.type = $2.type;
        if ($2.type != ERRORTYPE && $2.type != NULLVOID) {
            $$.registerName = $2.registerName;
            string s = (*($$.registerName)) + " = ~" + (*($2.registerName));   
            gen(funcInstr, s, nxtqd);
        }
    }
    | EXPR21
    {
        $$.type = $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName;    
        }
    }
;

EXPR21: EXPR2 EQUAL EXPR2
    {
        if ( $3.type == ERRORTYPE || $1.type == ERRORTYPE ) {
            $$.type = ERRORTYPE;
        }
        else if( $3.type == NULLVOID || $1.type == NULLVOID ){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << " Both the expessions should not be  NULL" << endl;
        }
        else {
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " == " + (*($3.registerName))   ;
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 NOTEQUAL EXPR2
    {
        if( $3.type == ERRORTYPE || $1.type == ERRORTYPE ){
            $$.type = ERRORTYPE;
        }
        else if( $3.type == NULLVOID || $1.type == NULLVOID ){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions cannot be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " != " + (*($3.registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 LT EXPR2 
    {
        if( $3.type == ERRORTYPE || $1.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if( $3.type == NULLVOID || $1.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " < " + (*($3.registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 GT EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " > " + (*($3.registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 LE EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
            errFnd = true;
        }
        else if( $3.type == NULLVOID || $1.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " <= " + (*($3.registerName));   
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 GE EXPR2
    {
        if( $3.type == ERRORTYPE || $1.type == ERRORTYPE ){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(Set_temp.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " >= " + (*($3.registerName));  
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(*($1.registerName));
            Set_temp.freeRegister(*($3.registerName));  
        }   
    } 
    | EXPR2 
    {
        $$.type = $1.type; 
        if($$.type == ERRORTYPE){
            errFnd = true;
        }
        else{
            if($1.type != NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName; 
            }
        }    
    }
;

EXPR2:  EXPR2 PLUS TERM
    {
        if ( $3.type == ERRORTYPE || $1.type == ERRORTYPE ) {
            $$.type = ERRORTYPE; 
            errFnd = true; 
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(Set_temp.getRegister());
                else
                    $$.registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " + " + (*($3.registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($1.registerName));
                Set_temp.freeRegister(*($3.registerName));   
            }
            else {
                cout << "ERROR : Line no. " << yylineno <<" Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | EXPR2 MINUS TERM
    {
        if ( $3.type == ERRORTYPE || $1.type == ERRORTYPE ) {
            $$.type = ERRORTYPE;
            errFnd = true;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(Set_temp.getRegister());
                else
                    $$.registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " - " + (*($3.registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($1.registerName));
                Set_temp.freeRegister(*($3.registerName));   
            }
            else {
                cout << "ERROR : Line no. " << yylineno << " Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | TERM 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            if($1.type!= NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName;
            }         
        } 
    }
;

TERM: TERM MUL FACTOR
    {
        if ( $3.type == ERRORTYPE || $1.type == ERRORTYPE) {
            $$.type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(Set_temp.getRegister());
                else
                    $$.registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " * " + (*($3.registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($1.registerName));
                Set_temp.freeRegister(*($3.registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | TERM DIV FACTOR  
    {
        if ($3.type == ERRORTYPE || $1.type == ERRORTYPE) {
        $$.type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+" Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = Set_temp.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << "Warning : Line No. "+to_string(yylineno)+":Implicit Type Conversion" << endl;
                    Set_temp.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(funcInstr, s, nxtqd);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(Set_temp.getRegister());
                else
                    $$.registerName = new string(Set_temp.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " / " + (*($3.registerName));   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($1.registerName));
                Set_temp.freeRegister(*($3.registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }   
    }  
    | TERM MOD FACTOR
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;  
        }
        else {
            if ($1.type == INTEGER && $3.type == INTEGER) {
                $$.type = INTEGER;
                $$.registerName = new string(Set_temp.getRegister());  
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " % " + (*($3.registerName));;   
                gen(funcInstr, s, nxtqd);
                Set_temp.freeRegister(*($1.registerName));
                Set_temp.freeRegister(*($3.registerName));   
            }
            else {
                cout << "Error: " << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }   
    }
    | FACTOR 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            errFnd = true;
        }
        else {
            if($1.type != NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName;
            }  
        } 
    }
;

FACTOR: ID_ARR  
    { 
        $$.type = $1.type;
        if ($$.type != ERRORTYPE) {
            if ($$.type == INTEGER)
                $$.registerName = new string(Set_temp.getRegister());
            else $$.registerName = new string(Set_temp.getFloatRegister());
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) ;
            gen(funcInstr, s, nxtqd);
            if($1.offsetRegName != NULL){
                Set_temp.freeRegister((*($1.offsetRegName)));
            }
        }
    }
    | MINUS ID_ARR
    {
        $$.type = $2.type;
        if($2.type != ERRORTYPE){
            string s="";
            if ($$.type == INTEGER){
                $$.registerName = new string(Set_temp.getRegister());
                string temp=Set_temp.getRegister();
                string temp1=Set_temp.getRegister();
                gen(funcInstr, temp + " = 0", nxtqd);
                gen(funcInstr, temp1 + " = " +  (*($2.registerName)), nxtqd);
                s = (*($$.registerName)) + " = " + temp + " -" + temp1 ;
                Set_temp.freeRegister(temp);
                Set_temp.freeRegister(temp1);
            }
            else{ 
                $$.registerName = new string(Set_temp.getFloatRegister());
                string temp=Set_temp.getFloatRegister();
                string temp1=Set_temp.getRegister();
                gen(funcInstr, temp + " = 0", nxtqd);
                gen(funcInstr, temp1 + " = " +  (*($2.registerName)), nxtqd);
                s = (*($$.registerName)) + " = 0 -" + temp1 ;
                Set_temp.freeRegister(temp);
                Set_temp.freeRegister(temp1);
            }
            gen(funcInstr, s, nxtqd);
            if($2.offsetRegName != NULL){
                Set_temp.freeRegister((*($2.offsetRegName)));
            }
        }       
    }
    | MINUS NUMINT
    {
        $$.type = INTEGER; 
        $$.registerName = new string(Set_temp.getRegister());
        string s = (*($$.registerName)) + " = -" + string($2) ;
        gen(funcInstr, s, nxtqd);  
        
    }
    | NUMINT    
    { 
        $$.type = INTEGER; 
        $$.registerName = new string(Set_temp.getRegister());
        string s = (*($$.registerName)) + " = " + string($1) ;
        gen(funcInstr, s, nxtqd);  
    }
    | MINUS NUMFLOAT
    {
        $$.type = FLOATING;
        $$.registerName = new string(Set_temp.getFloatRegister());
        string s = (*($$.registerName)) + " = " + string($2) ;
        gen(funcInstr, s, nxtqd);  
    }
    | NUMFLOAT  
    { 
        $$.type = FLOATING;
        $$.registerName = new string(Set_temp.getFloatRegister());
        string s = (*($$.registerName)) + " = " + string($1) ;
        gen(funcInstr, s, nxtqd);  
    }
    | FUNC_CALL 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            if ($1.type == NULLVOID){
                delete FuncCallPtr;
            }
            else {
                $$.registerName = $1.registerName;
                delete FuncCallPtr;
            }
        }; 
    }
    | LP ASG RP 
    { 
        $$.type = $2.type; 
        if ($2.type != ERRORTYPE) {
            $$.registerName = $2.registerName;
        }
    }
    | ID_ARR INCREMENT
    {
        if ($1.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = Set_temp.getRegister();
            $$.registerName = new string(newReg); 
            string s = newReg + " = " + (*($1.registerName)) ;
            gen(funcInstr, s, nxtqd); 
            string newReg2 = Set_temp.getRegister();
            s = newReg2 + " = " + newReg + " + 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*($1.registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg2);
            if($1.offsetRegName != NULL){
                Set_temp.freeRegister((*($1.offsetRegName)));
            }
        }
        else {
            $$.type = ERRORTYPE;
            cout << "Error: " << "Line no. " << yylineno << " Cannot increment a variable of non-integer type "<< *($1.registerName) << endl; 
        }
    } 
    | ID_ARR DECREMENT
    {
        if ($1.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = Set_temp.getRegister();
            $$.registerName = new string(newReg);
            string s = newReg + " = " + (*($1.registerName)); 
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            s = newReg2 + " = " + newReg + " - 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*($1.registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg2); 
            if($1.offsetRegName != NULL){
                Set_temp.freeRegister((*($1.offsetRegName)));
            }    
        }
        else {
            $$.type = ERRORTYPE;
            cout << "ERROR : Line no. " << yylineno << " Cannot increment non-integer type variable " << *($1.registerName) << endl; 
        }
    } 
    | INCREMENT ID_ARR
    {
        if ($2.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = Set_temp.getRegister();
            string s = newReg + " = " + (*($2.registerName));
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            $$.registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " + 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*($2.registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg); 
            if($2.offsetRegName != NULL){
                Set_temp.freeRegister((*($2.offsetRegName)));
            }     
        }
        else {
            $$.type = ERRORTYPE;
            cout << "Error: Line no. " << yylineno << " Cannot increment non-integer type variable "<<*($2.registerName) << endl; 
        }
    } 
    | DECREMENT ID_ARR
    {
        if ($2.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = Set_temp.getRegister();
            string s = newReg + " = " + (*($2.registerName)); 
            gen(funcInstr, s, nxtqd);
            string newReg2 = Set_temp.getRegister();
            $$.registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " - 1"; 
            gen(funcInstr, s, nxtqd);
            s = (*($2.registerName)) + " = " + newReg2; 
            gen(funcInstr, s, nxtqd);
            Set_temp.freeRegister(newReg);
            if($2.offsetRegName != NULL){
                Set_temp.freeRegister((*($2.offsetRegName)));
            }         
        }
        else {
            $$.type = ERRORTYPE;
            cout << "Error Line no. " << yylineno << " Cannot increment a variable of non-integer type" << *($2.registerName) << endl; 
        }
    }
;

ID_ARR: ID
    {   
        typeRecord* vn = NULL;
        int fnd = 0;
        searchCallVars(string($1), FuncActPtr, fnd, vn, gloVars); 
        $$.offsetRegName = NULL;
        if(fnd){
            if (vn->type == SIMPLE) {
                $$.type = vn->eleType;
                string dataType = eletypeMapper($$.type);
                dataType += "_" + to_string(vn->sc);
                $$.registerName = new string("_" + string($1) + "_" + dataType);
            }
            else {
                $$.type = ERRORTYPE;
                cout << "Error: Line no. " << yylineno <<  $1 << " is declared as an array but is being used as a singleton" << endl; 
            }
        }
        else {
            if (FuncActPtr != NULL)
                searchPars(string ($1), FuncActPtr->parameterList, fnd, vn);
            if (fnd) {
                if (vn->type == SIMPLE) {
                    $$.type = vn->eleType;
                    string dataType = eletypeMapper($$.type);
                    dataType += "_" + to_string(vn->sc);
                    $$.registerName = new string("_" + string($1) + "_" + dataType);
                }
                else {
                    $$.type = ERRORTYPE;
                    cout << "Error: Line no. " << yylineno <<  $1 << " is declared as an array but is being used as a singleton" << endl;
                }
            }
            else {
                $$.type = ERRORTYPE;
                cout << "Error: " << "Line no. " << yylineno << " Undeclared identifier " << $1 << endl;
            }
        }
    }
    | ID BR_DIMLIST
    {
        int fnd = 0;
        typeRecord* vn = NULL;
        $$.offsetRegName = NULL; 
        if($2.type == ERRORTYPE){
            errFnd = true;
            $$.type = ERRORTYPE;
        }
        else{
            searchCallVars(string($1), FuncActPtr, fnd, vn, gloVars); 
            if(fnd){
                if (vn->type == ARRAY) {
                    if (dl.size() == vn->dl.size()) {
                        $$.type = vn->eleType;
                        string offsetRegister = Set_temp.getRegister();
                        string dimlistRegister = Set_temp.getRegister();
                        string s = offsetRegister + " = 0";
                        gen(funcInstr, s, nxtqd);
                        for (int i = 0; i < vn->dl.size(); i++) {
                            s = offsetRegister + " = " + offsetRegister + " + " + dl[i];
                            gen(funcInstr, s, nxtqd);
                            if (i != vn->dl.size()-1) {
                                s = dimlistRegister + " = " + to_string(vn->dl[i+1]);
                                gen(funcInstr, s, nxtqd);                                
                                s = offsetRegister + " = " + offsetRegister + " * " + dimlistRegister;
                                gen(funcInstr, s, nxtqd);
                            }
                            Set_temp.freeRegister(dl[i]);
                        }
                        string dataType = eletypeMapper($$.type);
                        dataType += "_" + to_string(vn->sc); 
                        s = "_" + string($1) + "_" + dataType ;
                        s += "[" + offsetRegister + "]";
                        $$.registerName = new string(s);
                        Set_temp.freeRegister(dimlistRegister);
                        $$.offsetRegName = new string(offsetRegister);
                        
                    }
                    else {
                        $$.type = ERRORTYPE;
                        cout << "Error: " << "Line no. " << yylineno << " Dimension mismatch: " << $1 << " should have " << dl.size() <<" dimensions" << endl;
                    }
                }
                else {
                    $$.type = ERRORTYPE;
                    cout << "Error: " << "Line no. " << yylineno << " " <<  string($1) << " is declared as a singleton but is being used as an array" << endl; 
                }
            }
            else {
                $$.type = ERRORTYPE;
                cout << "Error: " << "Line no. " << yylineno << " " << "Undeclared identifier " << $1 << endl;
            }
            dl.clear();
        }
    }
;

BR_DIMLIST: LSB ASG RSB
    {
        if ($2.type == INTEGER) {
            dl.push_back(*($2.registerName));
        }
        else {
            cout << "Error: " << "Line no. " << yylineno << " " << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }
    }    
    | BR_DIMLIST LSB ASG RSB 
    {
        if ($3.type == INTEGER) {
            dl.push_back(*($3.registerName));
        }
        else {
            cout << "Error: " << "Line no. " << yylineno << " " << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }  
    }
;

%%

void yyerror(const char *s)
{      
    errFnd=1;
    fprintf (stderr, "%s\n", s);
}

int main(int argc, char **argv)
{
    nxtqd = 0;
    sc = 0;
    fnd = 0;
    ofc = 0;
    errFnd=false;
    sthVar.clear();
    dl.clear();
    
    yyparse();
    populateOffsets(functionEntryRec, gloVars);
    ofstream outinter;
    outinter.open("./output/intermediate.txt");
    if(!errFnd){
        for(auto it:funcInstr){
            outinter<<it<<endl;
        }
        cout << BOLD(FGRN("Intermediate Code Generated")) << endl;
    } else {
        cout << BOLD(FRED("Exited without intermediate code generation")) << endl;
    }
    outinter.close();
}
