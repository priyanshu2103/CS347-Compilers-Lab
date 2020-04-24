%{

#include <stdio.h>
#include <stdlib.h>
#include "c_comp.tab.h"

extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);

%}

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
%token ID
%token INT
%token FLOAT
%token IF
%token ELSE
%token SWITCH
%token CASE
%token FOR
%token WHILE
%token BREAK
%token DEFAULT

%%

stmts : stmt | stmt stmts;
stmt : stmt_wo_func | stmt_with_func;

stmt_wo_func : var_decl | arith | func_call | if_else | switch_case | for_loop | while_loop;
stmt_with_func : func_decl | func_def;

var_decl : INT_DECL int_id_list | FLOAT_DECL float_id_list;

int_id_list : int_assign SEMI | int_assign COMMA int_id_list;
int_assign : ID | ID EQ int_id_assign_list;
int_id_assign_list : ID | ID EQ INT | ID EQ int_arith | ID EQ func_call | ID EQ int_id_assign_list;  // check type of func_call

float_id_list : float_assign SEMI | float_assign COMMA float_id_list;
float_assign : ID | ID EQ float_id_assign_list;
float_id_assign_list : ID | ID EQ FLOAT | ID EQ float_arith | ID EQ func_call | ID EQ float_id_assign_list;

arith : int_arith SEMI | float_arith SEMI;

int_arith : int_arith_arg PLUS int_arith_arg | int_arith_arg MINUS int_arith_arg | int_arith_arg MULT int_arith_arg | int_arith_arg DIV int_arith_arg;
int_arith_arg : ID | INT | int_arith | func_call | LP int_arith RP; // check div by 0 and type of func_call

float_arith : float_arith_arg PLUS float_arith_arg | float_arith_arg MINUS float_arith_arg | float_arith_arg MULT float_arith_arg | float_arith_arg DIV float_arith_arg;
float_arith_arg : ID | FLOAT | float_arith | func_call | LP float_arith RP; // check div by 0 and type of func_call

func_call : ID LP call_arg_list RP;
call_arg_list : ID | ID COMMA call_arg_list;

func_decl : VOID ID LP decl_arg_list RP SEMI | INT ID LP decl_arg_list RP SEMI | FLOAT ID LP decl_arg_list RP SEMI;
decl_arg_list : decl_arg | decl_arg COMMA decl_arg_list;
decl_arg : INT_DECL | FLOAT_DECL | INT_DECL ID | FLOAT_DECL ID;

func_def : VOID ID LP def_arg_list RP stmt_wo_func | VOID ID LP def_arg_list RP LC body RC | INT_DECL ID LP def_arg_list RP stmt_wo_func | INT_DECL ID LP def_arg_list RP LC body RC | FLOAT_DECL ID LP def_arg_list RP stmt_wo_func | FLOAT_DECL ID LP def_arg_list RP LC body RC;
def_arg_list : def_arg | def_arg COMMA def_arg_list;
def_arg : INT_DECL ID | FLOAT_DECL ID;  // see no ID name is repeated in this list, can use unordered_map

body : stmt_wo_func | stmt_wo_func body;

if_else : mif | uif;

mif : IF LP cond RP mif ELSE mif | simple_stmt | LC simple_stmts RC;
uif : IF LP cond RP if_else | IF LP cond RP mif ELSE uif;

simple_stmts : simple_stmt | simple_stmt simple_stmts;
simple_stmt : var_decl | arith | func_call | switch_case;


cond : and_expr | and_expr OR cond;

and_expr : expr | expr AND and_expr;

expr : int_arith_arg LT int_arith_arg | int_arith_arg GT int_arith_arg | int_arith_arg LE int_arith_arg | int_arith_arg GE int_arith_arg | int_arith_arg EQ EQ int_arith_arg | int_arith_arg NEQ int_arith_arg |
       float_arith_arg LT float_arith_arg | float_arith_arg GT float_arith_arg | float_arith_arg LE float_arith_arg | float_arith_arg GE float_arith_arg | float_arith_arg EQ EQ float_arith_arg | float_arith_arg NEQ float_arith_arg |
       EXCL cond;

switch_case : SWITCH ID COL LC cases RC | SWITCH LP ID RP LC cases RC;

cases : case default | case cases;
case : CASE INT COL body break | CASE INT COL LC body RC break  | CASE LP INT RP COL body break | CASE LP INT RP COL LC body RC break |
       CASE FLOAT COL body break | CASE FLOAT COL LC body RC break | CASE LP FLOAT RP COL body break | CASE LP FLOAT RP COL LC body RC break ;
default : /* empty */ | DEFAULT COL body break | DEFAULT COL LC body RC break;
break : /* empty */ | BREAK SEMI;

for_loop : FOR LP for_expr RP stmt_wo_func | FOR LP for_expr RP LC body RC;
for_expr : for_first for_second for_third;
for_first : /* empty */ | var_decl | int_id_list | float_id_list;
for_second : /* empty */ | cond SEMI;
for_third : /* empty */ | ID EQ int_id_assign_list | ID EQ float_id_assign_list;             // not included i++ types

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
