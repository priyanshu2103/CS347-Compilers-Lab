/* interface to the lexer */
extern int yylineno; /* from lexer */
void yyerror(char *s, ...);
/* nodes in the abstract syntax tree */
struct ast {
 int nodetype;
 struct ast *l;
 struct ast *r;
};

struct var_or_const{
  int nodetype;
  int v_or_c;          //1 => v 2=> c
  char *name;
  int num_val;
  char * str_val;
};

struct result{
  int is_num_or_str;      // 1=>num 2=>str
  int num_val;
  char *str_val;
  int res;
};
/* build an AST */
struct ast *new_ast(int nodetype, struct ast *l, struct ast *r);
struct ast *new_num(int num);
struct ast *new_str(char *str);
struct ast *new_var(char *var_name);
/* evaluate an AST */
struct result *eval(struct ast *);
/* delete and free an AST */
void treefree(struct ast *);

void select_func(struct ast *node,char * table);
