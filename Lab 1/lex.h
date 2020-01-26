#define EOI	0	/* End of input			*/
#define SEMI 1	/* ; 				*/
#define PLUS 2	/* + 				*/
#define MINUS 3
#define TIMES 4	/* * 				*/
#define DIV 5
#define LP 6	/* (				*/
#define RP 7	/* )				*/
#define NUM_OR_ID 8	/* Decimal Number or Identifier */
#define ID 9  
#define IF 10
#define THEN 11
#define WHILE 12
#define DO 13
#define BEGIN 14
#define END 15
#define LT 16
#define GT 17
#define EQ 18
#define COL 19
extern char *yytext;		/* in lex.c			*/
extern int yyleng;
extern int yylineno;
extern char *newname();
extern void freename(char *);   
int match(int);
void advance(void);
