%{

#include <cstdio>
#include <cstdlib>
#include <vector>
#include "c_comp.tab.h"

using namespace std;

extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);
int eval_int_func(char *f_name);
float eval_float_func(char *f_name);
void eval_void_func(char *f_name);
func_call_details * get_func_details(char *);
void eval_func();

typedef struct func_arg
{
  char *arg_name;
  int arg_type;
  int i_val;
  float f_val;
} func_arg;

typedef struct func_call_details
{
  int f_type;
  char *f_name;
  int i_val;
  float f_val;
  int n_args;
  vector <func_arg *> args;
} func_call_details;

vector <func_call_details *> func_list;

int arg_no;
int check_arg_no;
vector <func_arg *> func_arg_list;
// the above 3 won't work in multiple func calls, need to keep a stack of these as well
// need to add print statement to see results

stack <func_call_details *> func_stack;
func_call_details *fc_temp;
int decl_type_check;
// f_type 0 void 1 int 2 float
%}

%union {int ival ; float fval; char * str; struct s{int id_type; char *id_name; int i_val; float f_val;} id_attributes; func_call_details * f_attributes;}
%start stmts
%token PLUS
%token MINUS
%token MULT
%token DIV
%token LE
%token GE
%token EQ
%token NEQ
%token LT
%token GT
%token AND
%token OR
%token EXCL
%token COMMA
%token COL
%token SEMI
%token LC
%token RC
%token LP
%token RP
%token VOID
%token INT_DECL
%token FLOAT_DECL
%token <id_attributes> ID
%token <ival> INT
%token <fval> FLOAT
%token IF
%token ELSE
%token SWITCH
%token CASE
%token FOR
%token WHILE
%token BREAK
%token DEFAULT

%type <id_attributes> assign;
%type <id_attributes> id_assign_list;

%type <id_attributes> arith_expr;
%type <id_attributes> arith_arg;

%type <f_attributes> func_call;
%type <f_attributes> func_decl;
%type <f_attributes> func_def;

%%

stmts : stmt | stmt stmts;
stmt : stmt_wo_func | stmt_with_func;

stmt_wo_func : var_decl | arith | func_call SEMI  | switch_case | for_loop | while_loop;
stmt_with_func : func_decl | func_def;

var_decl : INT_DECL {decl_type_check=1;} id_list | FLOAT_DECL {decl_type_check=2;} id_list;

id_list : assign SEMI {if($1.id_type!=decl_type_check) {cout<<"typE mismatch\n"; exit(0);}}| assign COMMA id_list {if($1.id_type!=decl_type_check) {cout<<"typE mismatch\n"; exit(0);}};
assign : ID {$$.id_type = $1.id_type = decl_type_check;}| ID EQ id_assign_list {$1.id_type=decl_type_check; if($1.id_type!=$3.id_type) {cout<<"tYPe mismatch\n"; exit(0);} $$.id_type = $1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val=$3.i_val;} else {$$.f_val=$1.f_val=$3.f_val;}}; // here check variable does or does not already exist also assign it's values only if it exists
id_assign_list : ID {$$.id_type = $1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val;} else {$$.f_val=$1.f_val;}}| ID EQ INT {if($1.id_type!=1) {cout<<"TYpe mismatch\n"; exit(0);} $1.i_val=$3; $$.id_type=1; $$.i_val=$1.i_val;}| ID EQ FLOAT {if($1.id_type!=2) {cout<<"TYpe mismatch\n"; exit(0);} $1.f_val=$3; $$.id_type=2; $$.f_val=$1.f_val;}| ID EQ arith_expr {if($1.id_type!=$3.id_type) {cout<<"tyPe mismatch\n"; exit(0);} $$.id_type=$1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val=$3.i_val;} else {$$.f_val=$1.f_val=$3.f_val;}}| ID EQ func_call {if($1.id_type!=$3->f_type) {cout<<"tyPe mismatch\n"; exit(0);} $$.id_type=$1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val=$3->i_val;} else {$$.f_val=$1.f_val=$3->f_val;}}| ID EQ id_assign_list {if($1.id_type!=$3.id_type) {cout<<"tyPe mismatch\n"; exit(0);} $$.id_type=$1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val=$3.i_val;} else {$$.f_val=$1.f_val=$3.f_val;}};

arith : arith_expr SEMI;

arith_expr : arith_arg PLUS arith_arg {if($1.id_type!=$3.id_type) {cout<<"Type mismatch\n"; exit(0);} if($1.id_type==1) {$$.i_val=$1.i_val + $3.i_val;} else {$$.f_val=$1.f_val + $3.f_val;}}| arith_arg MINUS arith_arg {if($1.id_type!=$3.id_type) {cout<<"Type mismatch\n"; exit(0);} if($1.id_type==1) {$$.i_val=$1.i_val + $3.i_val;} else {$$.f_val=$1.f_val + $3.f_val;}}| arith_arg MULT arith_arg {if($1.id_type!=$3.id_type) {cout<<"Type mismatch\n"; exit(0);} if($1.id_type==1) {$$.i_val=$1.i_val + $3.i_val;} else {$$.f_val=$1.f_val + $3.f_val;}}| arith_arg DIV arith_arg {if($1.id_type!=$3.id_type) {cout<<"Type mismatch\n"; exit(0);} if($1.id_type==1) {$$.i_val=$1.i_val + $3.i_val;} else {$$.f_val=$1.f_val + $3.f_val;}};
arith_arg : ID {$$.id_type=$1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val;} else {$$.f_val=$1.f_val;}}| INT {$$.id_type=1; $$.i_val=$1;}| FLOAT {$$.id_type=2; $$.f_val=$1;}| arith_expr {$$.id_type=$1.id_type; if($1.id_type==1) {$$.i_val=$1.i_val;} else {$$.f_val=$1.f_val;}}| func_call {$$.id_type=$1->f_type; if($$.id_type==1) {$$.i_val=$1->i_val;} else {$$.f_val=$1->f_val;}}| LP arith_expr RP {$$.id_type = $2.id_type; if($2.id_type==1) {$$.i_val=$2.i_val;} else {$$.f_val=$2.f_val;}}; // check div by 0 and type of func_call

func_call : ID {func_call_details * fc= get_func_details($1.id_name); arg_no= fc->n_args; func_arg_list= fc->args; check_arg_no=0; $<f_attributes>$->f_type=fc->f_type;} LP call_arg_list RP {if($$->f_type==1) {$$->i_val = eval_int_func($1.id_name)} else if($$->f_type==2) {$$->f_val = eval_float_func($1.id_name)} else {eval_void_func($1.id_name)}};
call_arg_list : /* empty */ | call_arg | call_arg COMMA call_arg_list;
call_arg : ID {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != $1.id_type) {cout<<"type mismatch while calling\n"; exit(0);} if(fa->arg_type==1) {fa->i_val=$1.i_val;} else {fa->f_val=$1.f_val;}}|
           INT {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != 1) {cout<<"type mismatch while calling\n"; exit(0);} fa->i_val=$1;}|
           FLOAT {if(check_arg_no >= arg_no) {cout<<"no of args error\n"; exit(0);} func_arg * fa=func_arg_list[check_arg_no]; check_arg_no++; if(fa->arg_type != 2) {cout<<"type mismatch while calling\n"; exit(0);} fa->f_val=$1;};     // here variable scope part is left, also can use convert_int_to_float if want to allow typecast

func_decl : VOID ID {func_call_details * fc= get_func_details($2.id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=0; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP decl_arg_list RP SEMI {$$->args=func_arg_list; $$->n_args=arg_no; func_list.push_back($$);} |
            INT_DECL ID {func_call_details * fc= get_func_details($2.id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=1; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP decl_arg_list RP SEMI {$$->args=func_arg_list; $$->n_args=arg_no; func_list.push_back($$);} |
            FLOAT_DECL ID {func_call_details * fc= get_func_details($2.id_name); if(fc) {cout<<"func already exists\n"; exit(0);} fc=new func_call_details(); fc->f_type=2; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP decl_arg_list RP SEMI {$$->args=func_arg_list; $$->n_args=arg_no; func_list.push_back($$);};
decl_arg_list : /* empty */ | decl_arg | decl_arg COMMA decl_arg_list;
decl_arg : INT_DECL {func_arg * fa=new func_arg(); fa->arg_type=1; func_arg_list[arg_no++]= fa;}| FLOAT_DECL {func_arg * fa=new func_arg(); fa->arg_type=2; func_arg_list[arg_no++]= fa;}| INT_DECL ID {func_arg * fa=new func_arg(); fa->arg_type=1; func_arg_list[arg_no++]= fa;}| FLOAT_DECL ID {func_arg * fa=new func_arg(); fa->arg_type=2; func_arg_list[arg_no++]= fa;};  // can't set name as it can be different during definition

func_def : VOID ID {func_call_details * fc=new func_call_details(); fc->f_type=0; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP stmt_wo_func
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);}|

           VOID ID {func_call_details * fc=new func_call_details(); fc->f_type=0; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP LC body RC
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);}|

           INT_DECL ID {func_call_details * fc=new func_call_details(); fc->f_type=1; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP stmt_wo_func
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);}|

           INT_DECL ID {func_call_details * fc=new func_call_details(); fc->f_type=1; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP LC body RC
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);}|

           FLOAT_DECL ID {func_call_details * fc=new func_call_details(); fc->f_type=2; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP stmt_wo_func
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);}|

           FLOAT_DECL ID {func_call_details * fc=new func_call_details(); fc->f_type=2; fc->f_name=$2.id_name; arg_no=0; vector<func_arg *> templist; func_arg_list=templist; $<f_attributes>$=fc;} LP def_arg_list RP LC body RC
           {$$->args=func_arg_list; $$->n_args=arg_no; func_call_details *fc1= get_func_details($$->f_name); if(fc1) {if(fc1->f_type != $$->f_type || fc1->n_args !=$$->n_args) {cout<<"multiple func definition\n"; exit(0);} for(int i=0;i<fc1->n_args;i++) {if(fc1->args[i]->arg_type!=$$->args[i]->arg_type) {cout<<"multiple func definition\n"; exit(0);}}} func_list.push_back($$);};

def_arg_list : /* empty */ | def_arg | def_arg COMMA def_arg_list;
def_arg : INT_DECL ID {func_arg * fa=new func_arg(); fa->arg_type=1; fa->arg_name=$2.id_name; func_arg_list[arg_no++]= fa;}| FLOAT_DECL ID {func_arg * fa=new func_arg(); fa->arg_type=2; fa->arg_name=$2.id_name; func_arg_list[arg_no++]= fa;};  // see no ID name is repeated in this list, can use unordered_map

body : stmt_wo_func | stmt_wo_func body;

//if_else : mif | uif;

//mif : IF LP cond RP mif ELSE mif | simple_stmt | LC simple_stmts RC;
//uif : IF LP cond RP if_else | IF LP cond RP mif ELSE uif;

//simple_stmts : simple_stmt | simple_stmt simple_stmts;
//simple_stmt : var_decl | arith | func_call | switch_case;


cond : and_expr | and_expr OR cond;

and_expr : expr | expr AND and_expr;

expr : arith_expr LT arith_expr | arith_expr GT arith_expr | arith_expr LE arith_expr | arith_expr GE arith_expr | arith_expr EQ EQ arith_expr | arith_expr NEQ arith_expr |
       EXCL cond;

switch_case : SWITCH ID COL LC cases RC | SWITCH LP ID RP LC cases RC;

cases : case default | case cases;
case : CASE INT COL body break | CASE INT COL LC body RC break  | CASE LP INT RP COL body break | CASE LP INT RP COL LC body RC break |
       CASE FLOAT COL body break | CASE FLOAT COL LC body RC break | CASE LP FLOAT RP COL body break | CASE LP FLOAT RP COL LC body RC break ;
default : /* empty */ | DEFAULT COL body break | DEFAULT COL LC body RC break;
break : /* empty */ | BREAK SEMI;

for_loop : FOR LP for_expr RP stmt_wo_func | FOR LP for_expr RP LC body RC;
for_expr : for_first for_second for_third;
for_first : /* empty */ | var_decl | id_list;
for_second : /* empty */ | cond SEMI;
for_third : /* empty */ | ID EQ id_assign_list;             // not included i++ types

while_loop : WHILE LP cond RP stmt_wo_func | WHILE LP cond RP LC body RC;

%%


int main()
{
  yyparse();
  printf("\nValid\n");
  return 0;
}

void yyerror(const char *s)
{
  printf("ERROR: %s\n", s);
  exit(0);
}

bool search(char *f_name)
{

}

int eval_int_func(char *f_name)
{

}

float eval_float_func(char *f_name)
{

}

void eval_void_func(char *f_name)
{

}

func_call_details * get_func_details(char *f_name)
{
  // first find if func exists it should return
  func_call_details *fc;
  return fc;
  // or return null

}

void eval_func()
{

}
