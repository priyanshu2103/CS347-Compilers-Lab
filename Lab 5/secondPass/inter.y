%{
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <fstream>
#include "symTabParser.h"
using namespace std;

#define INTSIZE 4
#define FLOATSIZE 4

extern int yylex();
extern int yyparse();
extern int yylineno;
extern char* yytext;
extern int yyleng;
void yyerror(char* s);

FILE *mips;
string actFunc, retVal;
int parOffset, ftLabel = 0;
vector<funcEntry> funcLst;
vector<typeRecord> gblVars;
void saveRegisters(int frameSize);
void retrieveRegisters(int frameSize);  
bool isGlobal;  
%}

%union {
    int intval;
    float floatval;
    char *idName;
}

%token FUNCTION BEG END IF GOTO PARAM REFPARAM CALL LSB RSB RETURN NEWLINE
%token CONVERTINT CONVERTFLOAT LP RP
%token USERVAR REGINT REGFLOAT LABEL NUMINT NUMFLOAT PRINT READ
%token COMMA COLON SEMI
%token PLUS MINUS MUL DIV MOD
%token EQUAL NOTEQUAL OR AND LT GT LE GE ASSIGN NEG

%type <idName> NUMFLOAT NUMINT REGINT REGFLOAT LABEL USERVAR 

%%

STMT_LIST: STMT_LIST STMT NEWLINE
    | STMT NEWLINE
;

STMT: ASG
    | FLOATASG
    | GOTO LABEL
    {
        fprintf(mips, "j %s\n", $2);
    }
    | LABEL COLON
    {
        fprintf(mips, "%s:\n", $1);
    }
    | IFSTMT
    | PARAM REGINT
    {
        parOffset += INTSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", INTSIZE); 
        fprintf(mips, "sw $t%c, 0($sp)\n", $2[1]);    
    }
    | PARAM REGFLOAT
    {
        parOffset += FLOATSIZE;
        fprintf(mips, "sub $sp, $sp, %d\n", FLOATSIZE);   
        fprintf(mips, "mfc1 $s0, $f%s\n", $2+1);             
        fprintf(mips, "sw $s0, 0($sp)\n");                 
    }
    | REFPARAM REGINT 
    {
        retVal = string($2);
    }
    | REFPARAM REGFLOAT
    {
        retVal = string($2);
    }
    | CALL USERVAR COMMA NUMINT
    {
        int frameSize = getFunctionOffset(funcLst, actFunc); 
        saveRegisters(frameSize+parOffset);       
        fprintf(mips, "jal %s\n", $2);                     
        retrieveRegisters(frameSize+parOffset);   
        if(retVal==""){

        } else if(retVal[0] == 'F'){
            fprintf(mips, "move $s0, $v0\n");  
            fprintf(mips, "mtc1 $s0, $f%s\n", retVal.c_str()+1);   
        } else {
            fprintf(mips, "move $t%c, $v0\n", retVal[1]);   
        }
        int funcParamOffset = getParset(funcLst, string($2));
        fprintf(mips, "add $sp, $sp, %d\n", funcParamOffset); 
        parOffset-=funcParamOffset;
        retVal = "";
    }
    | FUNCTION BEG USERVAR 
    {
        actFunc = string($3);
        fprintf(mips, "%s:\n", $3);
        int frameSize = getFunctionOffset(funcLst, actFunc);
        fprintf(mips, "subu $sp, $sp, %d\n", frameSize);
        fprintf(mips, "sw $ra, %d($sp)\n", frameSize-INTSIZE);
        fprintf(mips, "sw $fp, %d($sp)\n", frameSize-2*INTSIZE);
        fprintf(mips, "move $fp, $sp\n");
    }
    | FUNCTION END
    {
        int frameSize = getFunctionOffset(funcLst, actFunc);
        fprintf(mips, "end_%s:\n", actFunc.c_str());
        fprintf(mips, "move $sp, $fp\n");                          
        fprintf(mips, "lw $ra, %d($sp)\n", frameSize-INTSIZE);     
        fprintf(mips, "lw $fp, %d($sp)\n", frameSize-2*INTSIZE);   
        fprintf(mips, "addu $sp, $sp, %d\n", frameSize);           
        fprintf(mips, "j $ra\n");                                  
    }
    | RETURN 
    {
        fprintf(mips, "j end_%s\n", actFunc.c_str());
    }
    | RETURN REGINT
    {
        fprintf(mips, "move $v0, $t%c\n", $2[1]);
        fprintf(mips, "j end_%s\n", actFunc.c_str());
    }
    | RETURN REGFLOAT
    {
        fprintf(mips, "mfc1 $s0, $f%s\n", $2+1);
        fprintf(mips, "move $v0, $s0\n");
        fprintf(mips, "j end_%s\n", actFunc.c_str());
    }
    | PRINT REGINT
    {
        fprintf(mips, "move $a0, $t%s\n", $2+1);
        fprintf(mips, "li $v0 1\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");
        fprintf(mips, "la $a0, endline\n");
        fprintf(mips, "syscall\n");
    }
    | PRINT REGFLOAT
    {
        fprintf(mips, "mov.s $f12, $f%s\n", $2+1);
        fprintf(mips, "li $v0 2\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "li $v0, 4\n");
        fprintf(mips, "la $a0, endline\n");
        fprintf(mips, "syscall\n");
    }
    | READ REGINT
    {
        fprintf(mips, "li $v0 5\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "move $t%s, $v0\n", $2+1);
    }
    | READ REGFLOAT
    {
        fprintf(mips, "li $v0 6\n");
        fprintf(mips, "syscall\n");
        fprintf(mips, "mov.s $f%s, $f0\n", $2+1);
    }
;


ASG: USERVAR ASSIGN REGINT
    {
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "sw $t%c, %d($sp)\n", $3[1], offset);
        } else {
            fprintf(mips, "sw $t%s, %s\n", $3+1, $1); 
        }
    }
    | USERVAR LSB NUMINT RSB ASSIGN REGINT
    {
       
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", $3[1], offset);
    }
    | USERVAR LSB REGINT RSB ASSIGN REGINT
    {
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", $6+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $1);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $3+1);
            fprintf(mips,"sw $t%s, 0($s0)\n", $6+1);
        }
    }
    | REGINT ASSIGN USERVAR
    {
        int offset = getset(funcLst, gblVars, actFunc, string($3), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "lw $t%c, %d($sp)\n", $1[1], offset);
        } else {
            fprintf(mips, "lw $t%c, %s\n", $1[1], $3);
        }
    }
    | REGINT ASSIGN USERVAR LSB REGINT RSB
    {
        int offset = getset(funcLst, gblVars, actFunc, string($3), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $5+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", $1+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"la $s0, %s\n", $3);
            fprintf(mips,"addu $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"lw $t%s, 0($s0)\n", $1+1);
        }
    }
    | REGINT ASSIGN USERVAR LSB NUMINT RSB
    {
        int offset = getset(funcLst, gblVars, actFunc, string($3), 0, isGlobal)+parOffset;
        fprintf(mips, "sw $t%c, %d($sp)\n", $1[1], offset);
    }
    | REGINT ASSIGN NUMINT
    {
        fprintf(mips, "li $t%c, %s\n", $1[1], $3);
    }
    | REGINT ASSIGN REGINT
    {
        fprintf(mips, "move $t%c, $t%c\n", $1[1], $3[3]);
    }
    | REGINT ASSIGN CONVERTINT LP REGFLOAT RP
    {
        fprintf(mips, "cvt.w.s $f%s, $f%s\n", $5+1, $5+1);
        fprintf(mips, "mfc1 $t%c, $f%s\n", $1[1], $5+1);
    }
    | REGINT ASSIGN REGINT PLUS NUMINT
    {
        fprintf(mips, "addu $t%c, $t%c, %s\n", $1[1], $3[1], $5);
    }
    | REGINT ASSIGN REGINT MINUS NUMINT
    {
        fprintf(mips, "subu $t%c, $t%c, %s\n", $1[1], $3[1], $5);
    }
    | REGINT ASSIGN REGINT PLUS REGINT
    {
        fprintf(mips, "add $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT MINUS REGINT
    {
        fprintf(mips, "sub $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT MUL REGINT
    {
        fprintf(mips, "mul $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT DIV REGINT
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
        fprintf(mips, "mflo $t%c\n", $1[1]);
    }
    | REGINT ASSIGN REGINT MOD REGINT
    {
        fprintf(mips, "div $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
        fprintf(mips, "mfhi $t%c\n", $1[1]);
    }
    | REGINT ASSIGN REGINT EQUAL REGINT
    {
        fprintf(mips, "seq $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT NOTEQUAL REGINT
    {
        fprintf(mips, "sne $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT AND REGINT 
    {
        fprintf(mips, "sne $t%c, $t%c, 0\n", $3[1], $3[1]);
        fprintf(mips, "sne $t%c, $t%c, 0\n", $5[1], $5[1]);
        fprintf(mips, "and $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT OR REGINT
    {
        fprintf(mips, "or $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT LT REGINT
    {
        fprintf(mips, "slt $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT GT REGINT
    {
        fprintf(mips, "sgt $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT LE REGINT
    {
        fprintf(mips, "sle $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
    | REGINT ASSIGN REGINT GE REGINT
    {
        fprintf(mips, "sge $t%c, $t%c, $t%c\n", $1[1], $3[1], $5[1]);
    }
;

FLOATASG: USERVAR ASSIGN REGFLOAT
    {
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "s.s $f%s, %d($sp)\n", $3+1, offset);
        } else {
            fprintf(mips, "s.s $f%s, %s\n", $3+1, $1);
        }
    }
    | USERVAR LSB NUMINT RSB ASSIGN REGFLOAT
    {
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        fprintf(mips, "s.s $f%s, %d($sp)\n", $3+1, offset);
    }
    | USERVAR LSB REGINT RSB ASSIGN REGFLOAT
    {
        int offset = getset(funcLst, gblVars, actFunc, string($1), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"li $s1, %d\n", offset);
            fprintf(mips,"addu $s0, $sp, $s1\n");
            fprintf(mips,"sub $s0, $s0, $t%s\n", $3+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", $6+1);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $3+1, $3+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $1);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $3+1);
            fprintf(mips,"s.s $f%s, 0($s0)\n", $6+1);
        }
    }
    | REGFLOAT ASSIGN USERVAR
    {
        int offset = getset(funcLst, gblVars, actFunc, string($3), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "l.s $f%s, %d($sp)\n", $1+1, offset);
        } else {
            fprintf(mips, "l.s $f%s, %s\n", $1+1, $3);
        }
    }
    | REGFLOAT ASSIGN USERVAR LSB REGINT RSB
    {
        int offset = getset(funcLst, gblVars, actFunc, string($3), 0, isGlobal)+parOffset;
        if(!isGlobal){
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips, "subu $s0, $sp, $t%s\n", $5+1);
            fprintf(mips, "l.s $f%s, %d($s0)\n", $1+1, offset);
        } else {
            fprintf(mips, "mul $t%s, $t%s, %d\n", $5+1, $5+1, INTSIZE);
            fprintf(mips,"la $s1, %s\n", $3);
            fprintf(mips,"addu $s0, $s1, $t%s\n", $5+1);
            fprintf(mips,"l.s $f%s, 0($s0)\n", $1+1);
        }
    }
    | REGFLOAT ASSIGN CONVERTFLOAT LP REGINT RP
    {
        fprintf(mips, "mtc1 $t%c, $f%s\n", $5[1], $1+1);
        fprintf(mips, "cvt.s.w $f%s, $f%s\n", $1+1, $1+1);
    }
    | REGFLOAT ASSIGN NUMFLOAT
    {
        fprintf(mips, "li.s $f%s, %s\n", $1+1, $3);
    }
    | REGFLOAT ASSIGN REGFLOAT
    {
        fprintf(mips, "mov.s $f%s, $f%s\n", $1+1, $3+1);
    }
    | REGFLOAT ASSIGN REGFLOAT PLUS REGFLOAT
    {
        fprintf(mips, "add.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT MINUS REGFLOAT
    {
        fprintf(mips, "sub.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT MUL REGFLOAT
    {
        fprintf(mips, "mul.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGFLOAT ASSIGN REGFLOAT DIV REGFLOAT
    {
        fprintf(mips, "div.s $f%s, $f%s, $f%s\n", $1+1, $3+1, $5+1);
    }
    | REGINT ASSIGN REGFLOAT EQUAL REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT NOTEQUAL REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT AND REGFLOAT
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $3+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT OR REGFLOAT
    {
        fprintf(mips, "li.d $f31, 0\n");
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $3+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "c.eq.s $f%s, $f31\n", $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT LT REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT GT REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT LE REGFLOAT
    {
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "c.le.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
    | REGINT ASSIGN REGFLOAT GE REGFLOAT
    {
        fprintf(mips, "li $t%c, 1\n", $1[1]);
        fprintf(mips, "c.lt.s $f%s, $f%s\n", $3+1, $5+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $t%c, 0\n", $1[1]);
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        ftLabel++;
    }
;

IFSTMT: IF REGINT EQUAL REGINT GOTO LABEL
    {
        fprintf(mips, "beq $t%c, $t%c, %s\n", $2[1], $4[1], $6);
    }
    | IF REGINT NOTEQUAL REGINT GOTO LABEL
    {
        fprintf(mips, "bne $t%c, $t%c, %s\n", $2[1], $4[1], $6);
    }
    | IF REGINT EQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "beq $t%c, %s, %s\n", $2[1], $4, $6);
    }
    | IF REGINT NOTEQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "bne $t%c, %s, %s\n", $2[1], $4, $6);
    }
    | IF REGFLOAT EQUAL REGFLOAT GOTO LABEL
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $2+1, $4+1);
        fprintf(mips, "bc1t FLOAT%d\n", ftLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        ftLabel++;
    }
    | IF REGFLOAT NOTEQUAL REGFLOAT GOTO LABEL
    {
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f%s\n", $2+1, $4+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        ftLabel++;
    }
    | IF REGFLOAT EQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", $2+1);
        fprintf(mips, "bc1t FLOAT%d\n", ftLabel);
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        ftLabel++;
    }
    | IF REGFLOAT NOTEQUAL NUMINT GOTO LABEL
    {
        fprintf(mips, "mtc1 $0, $f31\n");
        fprintf(mips, "cvt.s.w $f31, $f31\n");
        fprintf(mips, "li $s0, 1\n");
        fprintf(mips, "c.eq.s $f%s, $f31\n", $2+1);
        fprintf(mips, "bc1f FLOAT%d\n", ftLabel); // goto label float when equal to 0
        fprintf(mips, "li $s0, 0\n");
        fprintf(mips, "FLOAT%d:\n", ftLabel);
        fprintf(mips, "beq $s0, 1, %s\n", $6);
        ftLabel++;
    }
;

%%

void saveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "sw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "s.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void retrieveRegisters(int frameSize){
    for(int i=0; i<10; i++){
        fprintf(mips, "lw $t%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+1)*INTSIZE);
    }
    for(int i=0; i<11; i++){
        fprintf(mips, "l.s $f%d, %d($sp)\n", i, frameSize-2*INTSIZE-(i+11)*INTSIZE);
    }
}

void yyerror(char *s)
{      
    printf("\nSyntax error %s at line %d\n", s, yylineno);
    fflush(stdout);
}

int main(int argc, char **argv)
{
    rdSymTab(funcLst, gblVars);
    retVal = ""; 
    isGlobal = false;
    mips = fopen("mips.s", "w");
    fflush(mips);
    fprintf(mips,".data\n");
    for(auto it : gblVars){
        fprintf(mips, "%s: .space %d\n", it.name.c_str(), 4*(it.variableoffset));
    }
    fprintf(mips,"endline: .asciiz \"\\n\"\n");
    fprintf(mips,".text\n");
    parOffset = 0;
    ftLabel = 0;
    yyparse();
    fflush(mips);
    fclose(mips);
}
