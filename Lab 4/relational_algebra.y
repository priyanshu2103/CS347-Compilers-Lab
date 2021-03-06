%{

#include <stdio.h>
#include <stdlib.h>
#include "relational_algebra.tab.h"
#include "helper.c"

extern int yylex(void);
extern void yyterminate();

list *global_list;
char *project_attrs[100];
int proj_attr_count=0;

enum id_val{attribute=1,table=2};

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
%type <a> mul_cond
%type <a> mul_and_expr
%type <a> mul_expr

%%

stmts : stmt |
        stmt NEWLINE |
        stmt NEWLINE stmts;

stmt : SELECT {list *select_list = create_list();global_list=select_list;} LT cond GT LP ID RP
       {
         if(!tableValidity($7.id_name))
         {
           printf("Table %s does not exist\n",$7.id_name);
           exit(0);
         }
         select_func($4,$7.id_name,global_list);
       }|

       PROJECT {proj_attr_count=0;} LT attr_list GT LP ID RP
       {
         if(!tableValidity($7.id_name))
         {
           printf("Table %s does not exist\n",$7.id_name);
           exit(0);
         }
         project_func(proj_attr_count,project_attrs,$7.id_name);
       }|

       LP ID RP CARTESIAN_PRODUCT LP ID RP
       {
         if(!tableValidity($2.id_name))
         {
           printf("Table %s does not exist\n",$2.id_name);
           exit(0);
         }
         if(!tableValidity($6.id_name))
         {
           printf("Table %s does not exist\n",$6.id_name);
           exit(0);
         }
         cartesian_product_func($2.id_name,$6.id_name);
       }|

       LP ID RP EQUI_JOIN {list *equi_join_list = create_list();global_list=equi_join_list;} LT mul_cond GT LP ID RP
       {
         if(!tableValidity($2.id_name))
         {
           printf("Table %s does not exist\n",$2.id_name);
           exit(0);
         }
         if(!tableValidity($10.id_name))
         {
           printf("Table %s does not exist\n",$10.id_name);
           exit(0);
         }
         equi_join_func($7,$2.id_name,$10.id_name,global_list);
       };

cond : and_expr
       {
         $$=new_ast(0,$1,NULL);
       }|

       and_expr OR cond
       {
         $$=new_ast(2,$1,$3);
       };

and_expr : expr
           {
              $$=new_ast(0,$1,NULL);
           }|

           expr AND and_expr
           {
              $$=new_ast(1,$1,$3);
           };

expr : ID LE ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(4,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID LE INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(4,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID GE ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(5,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID GE INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(5,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID EQ ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(6,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID EQ INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(6,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID EQ QUOTE ID QUOTE
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_str($4.id_name);
          $$=new_ast(6,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID NEQ ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(7,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID NEQ INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(7,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID NEQ QUOTE ID QUOTE
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_str($4.id_name);
          $$=new_ast(7,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID LT ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(8,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID LT INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(8,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID GT ID
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_var($3.id_name);
          $$=new_ast(9,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       ID GT INT
       {
          struct ast *temp1=new_var($1.id_name);
          struct ast *temp2=new_num($3);
          $$=new_ast(9,temp1,temp2);
          struct var_or_const *v1 = (struct var_or_const *) temp1;
          struct var_or_const *v2 = (struct var_or_const *) temp2;

          list_pushback(global_list,v1);
          list_pushback(global_list,v2);
       }|

       NOT cond
       {
          $$=new_ast(3,$2,NULL);
       };

attr_list : ID
            {
                project_attrs[proj_attr_count]=$1.id_name;
                proj_attr_count++;
            }|

            ID
            {
                project_attrs[proj_attr_count]=$1.id_name;
                proj_attr_count++;
            } COMMA attr_list;

mul_cond : mul_and_expr
           {
              $$=new_ast(0,$1,NULL);
           }|

           mul_and_expr OR mul_cond
           {
              $$=new_ast(2,$1,$3);
           };

mul_and_expr : mul_expr
               {
                  $$=new_ast(0,$1,NULL);
               }|

               mul_expr AND mul_and_expr
               {
                  $$=new_ast(1,$1,$3);
               };

mul_expr : ID DOT ID EQ ID DOT ID
           {
              if(!tableValidity($1.id_name))
              {
                printf("Table %s does not exist\n",$1.id_name);
                exit(0);
              }
              if(!tableValidity($5.id_name))
              {
                printf("Table %s does not exist\n",$5.id_name);
                exit(0);
              }
              if(checkAttributeValidity($3.id_name,$1.id_name)==-1)
              {
                printf("Table %s does not contain attribute %s\n",$1.id_name,$3.id_name);
                exit(0);
              }
              if(checkAttributeValidity($7.id_name,$5.id_name)==-1)
              {
                printf("Table %s does not contain attribute %s\n",$5.id_name,$7.id_name);
                exit(0);
              }

              struct ast *temp1=new_var($3.id_name);
              struct ast *temp2=new_var($7.id_name);
              $$=new_ast(6,temp1,temp2);
              struct var_or_const *v1 = (struct var_or_const *) temp1;
              struct var_or_const *v2 = (struct var_or_const *) temp2;
              v1->table_name=$1.id_name;
              v2->table_name=$5.id_name;

              list_pushback(global_list,v1);
              list_pushback(global_list,v2);
           };

%%

int main()
{
  yyparse();
  return 0;
}
void yyerror(const char *s)
{
  printf("ERROR: %s\n", s);
  exit(0);
}
