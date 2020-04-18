# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
# include "table_validator.c"

void yyerror(const char *s);
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

//create list for leaf nodes of tree
lNode * create_node(struct var_or_const * data)
{
	lNode * temp = (lNode *)malloc(sizeof(lNode));
	temp->prev = NULL;
  temp->next = NULL;
  temp->data = data;
  return temp;
}

list * create_list()
{
  list * l = (list *)malloc(sizeof(list));
  l->head = l->tail = NULL;
  return l;
}

void list_pushback(list * l,struct var_or_const * data)
{
	lNode * temp = create_node(data);

	if(l->head==NULL)
	{
		l->head = temp;
		l->tail = l->head;
	}
	else
	{
		l->tail->next = temp;
		temp->prev = l->tail;
		l->tail = temp;
	}
}

/*for debugging*/
void printList(list * l)
{
	lNode * temp = l->head;
	while(temp !=NULL)
	{
		printf("fdfdfdfdf%d ", temp->data->nodetype);
		temp = temp->next;
	}
	printf("\n");
}

// select queries
void select_func(struct ast *node,char * tablename , list *global_list)
{
  printf("\n");
  bool is_empty=true;
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
      lNode * temp = global_list->head;
    	while(temp !=NULL)
    	{
        struct var_or_const * v=temp->data;
        if(v->v_or_c == 1)
        {
          int index=v->idx;
          if (index==-1)
          {
            printf("Attribute %s does not exist in table %s\n",v->name, tablename);
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
         is_empty=false;
         printf("%s,",aux[i]);
       }
       printf("%s\n",aux[j-1]);
     }
  }
  fclose(fp);
  if(is_empty)
  {
    printf("No rows selected\n");
  }
}

// project queries
void project_func(int count,char **project_attrs,char *tablename)
{
  printf("\n");
  bool is_empty=true;
  int indices[1000];
  for(int i=0;i<count;i++)
  {
    indices[i] = checkAttributeValidity(project_attrs[i],tablename);
    if(indices[i]==-1)
    {
      printf("Attribute %s does not exist in table %s\n",project_attrs[i],tablename);
      exit(0);
    }
  }
  for(int i=0;i<count-1;i++)
  {
    printf("%s,",project_attrs[i]);
  }
  printf("%s\n",project_attrs[count-1]);
  if(count==1)
  {
    Duplicates(project_attrs[0],tablename);
    return;
  }
  char table[200];
  memset(table,0,sizeof(tablename));
  sprintf(table,"tables/%s.csv",tablename);
  FILE* fp = fopen(table, "r");
  char s[1000];
  char comma[]=",";

  fgets(s,sizeof(s),fp);
  int ln=0;
  char dup[1000][1000];
  while(fgets(s,sizeof(s),fp))
  {
    char *aux[100];
    sscanf(s,"%[^\n]comma",s);
    char *token = strtok(s,comma);
    int j=0;
    bool is_first=true;
    while(token!=NULL)
    {
      for(int k=0;k<count;k++)
      {
        if(j==indices[k])
        {
          is_empty=false;
          if(is_first)
          {
            is_first=false;
            sprintf(dup[ln],"%s",token);
          }
          else
          {
            char k[1000];
            sprintf(k,",%s",token);
            strcat(dup[ln],k);
          }
          break;
        }
      }
      token = strtok(NULL,comma);
      j++;
    }
    ln++;
  }
  fclose(fp);
  if(is_empty)
  {
    printf("No rows selected\n");
    return;
  }


  for(int i=0;i<ln-1;i++)
  {
    for(int j=i+1;j<ln;j++)
    {
      char temp[1000];
      if (strcmp(dup[j], dup[i]) < 0)
      {
          strcpy(temp, dup[j]);
          strcpy(dup[j], dup[i]);
          strcpy(dup[i], temp);
      }
    }
  }

  char ans[1000][1000];
  memset(ans,0,sizeof(ans));
  int count2=0;
  for(int i=0;i<ln;i++)
  {
    if(i==0)
    {
      int size=getSize(dup[i]);
      for(int k=0;k<size;k++)
        ans[count2][k]=dup[i][k];
      count2++;
      continue;
    }
    if(strcmp(dup[i],dup[i-1])==0)
      continue;
    else
    {
      int size=getSize(dup[i]);
      for(int k=0;k<size;k++)
        ans[count2][k]=dup[i][k];
      count2++;
    }
  }

  int p=count2;
  for(int i=0;i<p;i++)
  {
    printf("%s\n",ans[i]);
  }
  return;
}

// cartesian product queries
void cartesian_product_func(char *tablename1,char *tablename2)
{
  printf("\n");
  bool is_empty=true;
  char table1[200];
  char table2[200];
  memset(table1,0,sizeof(tablename1));
  memset(table2,0,sizeof(tablename2));
  sprintf(table1,"tables/%s.csv",tablename1);
  sprintf(table2,"tables/%s.csv",tablename2);
  FILE* fp1 = fopen(table1, "r");
  FILE* fp2 = fopen(table2, "r");
  char s1[1000];
  char s2[1000];

  char comma[]=",";
  // if(!fgets(s1,sizeof(s1),fp1))
  // {
  //   yyerror("Table 1 empty");
  //   exit(0);
  // }
  fgets(s1,sizeof(s1),fp1);
  sscanf(s1,"%[^\n]comma",s1);
  char *token = strtok(s1,comma);
  bool is_first=true;
  while(token!=NULL)
  {
    if(is_first)
    {
      is_first=false;
      printf("%s",token);
    }
    else
    {
      printf(",%s",token);
    }
    token = strtok(NULL,comma);
  }
  fgets(s2,sizeof(s2),fp2);
  sscanf(s2,"%[^\n]comma",s2);
  token = strtok(s2,comma);
  while(token!=NULL)
  {
    printf(",%s",token);
    token = strtok(NULL,comma);
  }
  printf("\n");
  fclose(fp2);
  while(fgets(s1,sizeof(s1),fp1))
  {
    char aux[2000];
    char temp[2000];
    sscanf(s1,"%[^\n]comma",s1);
    char *token1 = strtok(s1,comma);
    bool is_first=true;
    while(token1!=NULL)
    {
      if(is_first)
      {
        is_first=false;
        sprintf(aux,"%s",token1);
      }
      else
      {
        sprintf(temp,",%s",token1);
        strcat(aux,temp);
      }
      token1 = strtok(NULL,comma);
    }
    fp2 = fopen(table2, "r");
    fgets(s2,sizeof(s2),fp2);
    while(fgets(s2,sizeof(s2),fp2))
    {
      is_empty=false;
      printf("%s",aux);
      sscanf(s2,"%[^\n]comma",s2);
      char *token2 = strtok(s2,comma);
      while(token2!=NULL)
      {
        printf(",%s",token2);
        token2 = strtok(NULL,comma);
      }
      printf("\n");
    }
    fclose(fp2);
  }
  fclose(fp1);
  if(is_empty)
  {
    printf("No rows selected\n");
  }
}

// equi join queries
void equi_join_func(struct ast *node,char *tablename1, char *tablename2,list *global_list)
{
  printf("\n");
  bool is_empty=true;
  lNode * temp = global_list->head;
  while(temp)
  {
    struct var_or_const *v=temp->data;
    if(v->v_or_c==1)
    {
      int datatype=retrieveDatatype(v->name,v->table_name);
      if (datatype == 1)
      {
        v->nodetype=10;
      }
      else
      {
        v->nodetype=11;
      }
      int index=checkAttributeValidity(v->name,v->table_name);
      v->idx=index;
    }
    temp=temp->next;
  }

  char table1[200];
  char table2[200];
  memset(table1,0,sizeof(tablename1));
  memset(table2,0,sizeof(tablename2));
  sprintf(table1,"tables/%s.csv",tablename1);
  sprintf(table2,"tables/%s.csv",tablename2);
  FILE* fp1 = fopen(table1, "r");
  FILE* fp2 = fopen(table2, "r");
  char s1[1000];
  char s2[1000];

  char comma[]=",";
  fgets(s1,sizeof(s1),fp1);
  sscanf(s1,"%[^\n]comma",s1);
  char *token = strtok(s1,comma);
  bool is_first=true;
  while(token!=NULL)
  {
    if(is_first)
    {
      is_first=false;
      printf("%s",token);
    }
    else
    {
      printf(",%s",token);
    }
    token = strtok(NULL,comma);
  }
  fgets(s2,sizeof(s2),fp2);
  sscanf(s2,"%[^\n]comma",s2);
  token = strtok(s2,comma);
  while(token!=NULL)
  {
    printf(",%s",token);
    token = strtok(NULL,comma);
  }
  printf("\n");
  fclose(fp1);
  fclose(fp2);
//......................header printed.......................//

  fp1 = fopen(table1, "r");
  fgets(s1,sizeof(s1),fp1);
  while(fgets(s1,sizeof(s1),fp1))
  {
    char *aux1[200];
  	sscanf(s1,"%[^\n]comma",s1);
  	char *token1 = strtok(s1,comma);
  	int j1=0;
    while(token1!=NULL)
    {
      aux1[j1]=token1;
      lNode * temp = global_list->head;
    	while(temp !=NULL)
    	{
        struct var_or_const * v=temp->data;
        if(strcmp(v->table_name,tablename1)==0)
        {
          if(v->v_or_c == 1)
          {
            int index=v->idx;
            if (index==-1)
            {
              printf("Attribute %s does not exist in table %s\n",v->name, tablename1);
              exit(0);
            }
            if(j1 == index )
            {
              if (v->nodetype == 10) // int
              {
                v->num_val=atoi(token1);
              }
              else              // string
              {
                v->str_val=token1;
              }
            }
          }
        }
        temp=temp->next;
       }
       token1 = strtok(NULL,comma);
	     j1++;
    }

    fp2 = fopen(table2, "r");
    fgets(s2,sizeof(s2),fp2);
    while(fgets(s2,sizeof(s2),fp2))
    {
      char *aux2[200];
    	sscanf(s2,"%[^\n]comma",s2);
    	char *token2 = strtok(s2,comma);
    	int j2=0;
      while(token2!=NULL)
      {
        aux2[j2]=token2;
        lNode * temp = global_list->head;
      	while(temp !=NULL)
      	{
          struct var_or_const * v=temp->data;
          if(strcmp(v->table_name,tablename2)==0)
          {
            if(v->v_or_c == 1)
            {
              int index=v->idx;
              if (index==-1)
              {
                printf("Attribute %s does not exist in table %s\n",v->name, tablename2);
                exit(0);
              }
              if(j2 == index )
              {
                if (v->nodetype == 10) // int
                {
                  v->num_val=atoi(token2);
                }
                else              // string
                {
                  v->str_val=token2;
                }
              }
            }
          }
          temp=temp->next;
         }
         token2 = strtok(NULL,comma);
  	     j2++;
      }
      int ans = eval(node);
      if(ans==1)
      {
        is_empty=false;
        for(int i=0;i<j1;i++)
        {
          printf("%s,",aux1[i]);
        }
        for(int i=0;i<j2-1;i++)
        {
          printf("%s,",aux2[i]);
        }
        printf("%s\n",aux2[j2-1]);
      }
    }
    fclose(fp2);
  }
  fclose(fp1);
  if(is_empty)
  {
    printf("No rows selected\n");
  }
}

// new ast (non-leaf) node
struct ast *new_ast(int nodetype, struct ast *l, struct ast *r)
{
  struct ast *a = malloc(sizeof(struct ast));
  if(!a)
  {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = nodetype;
  a->l = l;
  a->r = r;
  return a;
}

// new leaf node with int datatype
struct ast *new_num(int d)
{
  struct var_or_const *a = malloc(sizeof(struct var_or_const));
  if(!a)
  {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 10;
  a->num_val = d;
  a->v_or_c=2;
  return (struct ast *)a;
}

// new leaf node with str datatype
struct ast *new_str(char *n)
{
  struct var_or_const *a = malloc(sizeof(struct var_or_const));
  if(!a)
  {
    yyerror("out of space");
    exit(0);
  }
  a->nodetype = 11;
  a->str_val = n;
  a->v_or_c=2;
  return (struct ast *)a;
}

// new leaf node which is a variable
struct ast *new_var(char *n)
{
  struct var_or_const *a = malloc(sizeof(struct var_or_const));
  if(!a)
  {
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
  int temp;
  switch(a->nodetype)
  {
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

    default: printf("internal error: bad node %d\n", a->nodetype);
  }
  return temp;
}


void treefree(struct ast *a)
{
 switch(a->nodetype)
 {
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
