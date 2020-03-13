%{
#include <stdio.h>
#include<stdlib.h>
#include "part2.tab.h"
extern int yylex(void);
extern void yyterminate();
void yyerror(const char *s);
extern FILE* yyin;
int ln=1;
%}

%start stmt
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

stmt :       SELECT LT cond GT LP ID RP  {printf("Valid syntax\n");}
           | PROJECT LT attr_list GT LP ID RP  {printf("Valid syntax\n");}
           | LP ID RP CARTESIAN_PRODUCT LP ID RP  {printf("Valid syntax\n");}
           | LP ID RP EQUI_JOIN LT cond GT LP ID RP  {printf("Valid syntax\n");} ;

cond :       expr
           | expr LOG expr
           | NOT expr;

expr :       attr OPER attr
           | attr OPER INT
           | attr OPER QUOTE ID QUOTE
           | attr LT attr
           | attr LT INT
           | attr LT QUOTE ID QUOTE
           | attr GT attr
           | attr GT INT
           | attr GT QUOTE ID QUOTE;

attr_list :  attr
           | attr COMMA attr_list;
attr :       ID;

%%

int main()
{
  yyparse();
//  printf("Valid\n");
  return 0;
}
void yyerror(const char *s)
{
	printf("Line no %d ERROR: %s\n",ln,s);
}
