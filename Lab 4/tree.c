# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
#include "tablevalidator.c"

void yyerror(const char *s);
/* interface to the lexer */
extern int yylineno; /* from lexer */
/* nodes in the abstract syntax tree */
struct ast
{
 int nodetype;
 struct ast *l;
 struct ast *r;
};

struct var_or_const
{
  int nodetype;
  int v_or_c;          //1 => v 2=> c
  char *name;
  int num_val;
  char * str_val;
  char * table_name;
  int idx;
};

// struct result
// {
//   int is_num_or_str;      // 1=>num 2=>str
//   int num_val;
//   char *str_val;
//   int res;
// };

typedef struct listnode
{
	struct var_or_const * data;
	struct listnode * prev;
	struct listnode * next;
}lNode;

typedef struct list
{
	struct listnode * head;
	struct listnode * tail;
}list;

/* build an AST */
struct ast *new_ast(int nodetype, struct ast *l, struct ast *r);
struct ast *new_num(int num);
struct ast *new_str(char *str);
struct ast *new_var(char *var_name);
/* evaluate an AST */
int eval(struct ast *);
/* delete and free an AST */
void treefree(struct ast *);

void select_func(struct ast *node,char * tablename , list *global_list)
{
  lNode * temp = global_list->head;
  while(temp)
  {
    struct var_or_const *v=temp->data;
    if(v->v_or_c==1)
    {
      int datatype=retrieveDatatype(v->name,tablename);
      if(datatype == 1)
      {
        v->nodetype=10;
      }
      else
      {
        v->nodetype=11;
      }
      int index=checkAttributeValidity(v->name,tablename);
      v->idx=index;
    }
    temp=temp->next;
  }

    char table[200];
    memset(table,0,sizeof(table));
    sprintf(table,"tables/%s.csv",tablename);
    FILE* fp = fopen(table, "r");
    char s[1000];
    char comma[]=",";
    fgets(s,sizeof(s),fp);
    sscanf(s,"%[^\n]comma",s);
    char *htoken = strtok(s,comma);
    while(htoken!=NULL)
    {
        printf("%s",htoken);
        htoken = strtok(NULL,comma);
        if(htoken!=NULL)
        {
          printf(",");
        }
    }
    printf("\n");
    while(fgets(s,sizeof(s),fp))
    {
      char *aux[100];
    	sscanf(s,"%[^\n]comma",s);
    	char *token = strtok(s,comma);
    	int j=0;
	    while(token!=NULL)
	    {
        aux[j]=token;
        // printf("jjjj %d\n",j);
        // printf("ToKeN %s\n",token);
        lNode * temp = global_list->head;
      	while(temp !=NULL)
      	{
          // printf("JjJjJjJjJj %d\n",j);
          struct var_or_const * v=temp->data;
          if(v->v_or_c == 1)
          {
            // printf("NaMe %s\n",v->name);
            int index=v->idx;
            if (index==-1)
            {
              yyerror("Attribute does not exist in given table");
              exit(0);
            }
            if(j == index )
  	        {
              if (v->nodetype == 10) // int
              {
                v->num_val=atoi(token);
              }
              else              // string
              {
                v->str_val=token;
              }
  	        }
          }
          temp=temp->next;
         }
        token = strtok(NULL,comma);
  	    j++;
       }
       int ans = eval(node);
       if(ans==1)
       {
         for(int i=0;i<j-1;i++)
         {
           printf("%s,",aux[i]);
         }
         printf("%s\n",aux[j-1]);
       }
    }
    fclose(fp);
}

void project_func(int count,char **project_attrs,char *table)
{
  for(int i=0;i<count;i++)
  {
     printf("kkkkkkkkk %s\n",project_attrs[i]);
  }
}

void equi_join_func(struct ast *node,char *table1, char *table2,list *global_list)
{

}

struct ast *new_ast(int nodetype, struct ast *l, struct ast *r)
{
 struct ast *a = malloc(sizeof(struct ast));

 if(!a) {
 yyerror("out of space");
 exit(0);
 }
 a->nodetype = nodetype;
 a->l = l;
 a->r = r;
 return a;
}

struct ast *new_num(int d)
{
 struct var_or_const *a = malloc(sizeof(struct var_or_const));
 if(!a) {
  yyerror("out of space");
  exit(0);
  }
  a->nodetype = 10;
  a->num_val = d;
  a->v_or_c=2;
  return (struct ast *)a;
 }

 struct ast *new_str(char *n)
 {
  struct var_or_const *a = malloc(sizeof(struct var_or_const));
  if(!a) {
   yyerror("out of space");
   exit(0);
   }
   a->nodetype = 11;
   a->str_val = n;
   a->v_or_c=2;
   return (struct ast *)a;
 }

 struct ast *new_var(char *n)
 {
  struct var_or_const *a = malloc(sizeof(struct var_or_const));
  if(!a) {
   yyerror("out of space");
   exit(0);
   }
   a->nodetype=-1;
   a->name = n;
   a->v_or_c=1;
   return (struct ast *)a;
 }

int eval(struct ast *a)
{
 // struct result *temp = malloc(sizeof(struct result));
 int temp;
 switch(a->nodetype) {
 case 0: {temp = eval(a->l);break;}
 case 1: {temp = eval(a->l) & eval(a->r);break;}
 case 2: {temp = eval(a->l) | eval(a->r);break;}
 case 3: {temp = (eval(a->l) == 1) ? 0 : 1;break;}
 case 4:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10)
   {
     yyerror("NA on data types other than int");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   temp = (t1->num_val <= t2->num_val) ? 1 : 0;
   break;
}
 case 5:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10)
   {
     yyerror("NA on data types other than int");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   temp = (t1->num_val >= t2->num_val) ? 1 : 0;
   break;
}
 case 6:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10 && a->l->nodetype!=11)
   {
     yyerror("NA on data types other than int or string");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   if(t1->nodetype==10)
   {
     temp = (t1->num_val == t2->num_val) ? 1 : 0;
   }
   else
   {
     temp = (strcmp(t1->str_val, t2->str_val) == 0) ? 1 : 0;
   }
   break;
}
 case 7:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10 && a->l->nodetype!=11)
   {
     yyerror("NA on data types other than int or string");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   if(t1->nodetype==10)
   {
     temp = (t1->num_val != t2->num_val) ? 1 : 0;
   }
   else
   {
     temp = (strcmp(t1->str_val, t2->str_val) != 0) ? 1 : 0;
   }
   break;
}
 case 8:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10)
   {
     yyerror("NA on data types other than int");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   temp = (t1->num_val < t2->num_val) ? 1 : 0;
   break;
 }
 case 9:
 {
   if(a->l->nodetype!=a->r->nodetype)
   {
     yyerror("type mismatch");
     exit(0);
   }
   if(a->l->nodetype != 10)
   {
     yyerror("NA on data types other than int");
     exit(0);
   }
   struct var_or_const * t1 = (struct var_or_const *) (a->l);
   struct var_or_const * t2 = (struct var_or_const *) (a->r);
   temp = (t1->num_val > t2->num_val) ? 1 : 0;
   break;
}
 // case 10: {temp->is_num_or_str=1; temp->num_val = ((struct var_or_const *)a)->num_val;break;}
 // case 11: {temp->is_num_or_str=2; temp->str_val = ((struct var_or_const *)a)->str_val;break;}
 default: printf("internal error: bad node %d\n", a->nodetype);
 }
 return temp;
}
void
treefree(struct ast *a)
{
 switch(a->nodetype) {
 /* two subtrees */
 case 4 ... 9:
 case 1:
 case 2:
 treefree(a->r);
 /* one subtree */
 case 0:
 case 3:
 treefree(a->l);
 /* no subtree */
 case 10:
 case 11:
 free(a);
 break;
 default: printf("internal error: free bad node %c\n", a->nodetype);
 }
}
