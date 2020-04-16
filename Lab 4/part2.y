%{

#include <stdio.h>
#include<stdlib.h>
#include "part2.tab.h"
extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);

%}

%start stmts
%token SELECT
%token PROJECT
%token CARTESIAN_PRODUCT
%token EQUI_JOIN
%token OPER
%token LT
%token GT
%token LOG
%token NOT
%token COMMA
%token DOT
%token LP
%token RP
%token ID
%token INT
%token QUOTE
%token NEWLINE
%%

stmts : stmt | stmt NEWLINE| stmt NEWLINE stmts;
stmt : SELECT LT cond GT LP ID RP | PROJECT LT attr_list GT LP ID RP | LP ID RP CARTESIAN_PRODUCT LP ID RP | LP ID RP EQUI_JOIN LT cond GT LP ID RP;
cond : expr | expr LOG expr | NOT expr;
expr : attr OPER attr | attr OPER INT | attr OPER QUOTE ID QUOTE | attr LT attr | attr LT INT | attr LT QUOTE ID QUOTE | attr GT attr | attr GT INT | attr GT QUOTE ID QUOTE;
attr_list : attr | attr COMMA attr_list;
attr : ID | ID DOT ID;
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
