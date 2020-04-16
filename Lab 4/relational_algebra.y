%{

#include <stdio.h>
#include <stdlib.h>
#include "relational_algebra.tab.h"
#include "tree.c"
extern int yylex(void);
extern void yyterminate();

enum id_val{attribute=1,table=2};
//currently taking OPER as <=
// not included float yet
// use snprintf while printing so that we can print together at last or after each statement and not print if syntax error
// need to see if rhs is int in <=,>=,<,> cases
// 0 as it is
// 1 and
// 2 or
// 3 not 4 <= 5 >= 6 = 7 <> 8 < 9 > 10 int 11 string
%}

%union {struct ast *a;int val;char * str;struct s{int id_type; char *id_name; int num_val; int str_val;} id_attributes;}
%start stmts
%token SELECT
%token PROJECT
%token CARTESIAN_PRODUCT
%token EQUI_JOIN
%token LE
%token GE
%token EQ
%token NEQ
%token LT
%token GT
%token AND
%token OR
%token NOT
%token COMMA
%token DOT
%token LP
%token RP
%token <id_attributes> ID
%token <val> INT
%token QUOTE
%token NEWLINE

%type <a> cond
%type <a> and_expr
%type <a> expr

%%

stmts : stmt {printf("1\n");}| stmt NEWLINE| stmt NEWLINE stmts;
stmt : SELECT LT cond GT LP ID RP {printf("2\n"); select_func($3,$6.id_name);}|
       PROJECT LT attr_list GT LP ID RP |
       LP ID RP CARTESIAN_PRODUCT LP ID RP |
       LP ID RP EQUI_JOIN LT mul_cond GT LP ID RP;
cond : and_expr {printf("3\n"); $$=new_ast(0,$1,NULL);}|
       and_expr OR cond {$$=new_ast(2,$1,$3);};
and_expr : expr {printf("4\n");$$=new_ast(0,$1,NULL);}|
          expr AND and_expr {$$=new_ast(1,$1,$3);};
expr : ID LE ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(4,temp1,temp2);}|
       ID LE INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(4,temp1,temp2);}|
       ID GE ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(5,temp1,temp2);}|
       ID GE INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(5,temp1,temp2);}|
       ID EQ ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(6,temp1,temp2);}|
       ID EQ INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(6,temp1,temp2);}|
       ID EQ QUOTE ID QUOTE {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($4.id_name); $$=new_ast(6,temp1,temp2);}|
       ID NEQ ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(7,temp1,temp2);}|
       ID NEQ INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(7,temp1,temp2);}|
       ID NEQ QUOTE ID QUOTE {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($4.id_name); $$=new_ast(7,temp1,temp2);}|
       ID LT ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(8,temp1,temp2);}|
       ID LT INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(8,temp1,temp2);}|
       ID GT ID {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_var($3.id_name); $$=new_ast(9,temp1,temp2);}|
       ID GT INT {struct ast *temp1=new_var($1.id_name); struct ast *temp2=new_num($3); $$=new_ast(9,temp1,temp2);}|
       NOT expr {$$=new_ast(3,$2,NULL);};
attr_list : ID |
            ID COMMA attr_list;
mul_cond : mul_and_expr |
           mul_and_expr OR mul_cond;
mul_and_expr : mul_expr |
              mul_expr AND mul_and_expr;
mul_expr : mul_attr EQ mul_attr;
mul_attr : ID DOT ID;

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
