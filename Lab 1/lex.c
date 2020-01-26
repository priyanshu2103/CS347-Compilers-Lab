#include "lex.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* yytext = ""; /* Lexeme (not '\0'
                      terminated)              */
int yyleng   = 0;  /* Lexeme length.           */
int yylineno = 0;  /* Input line number        */

int lex(void){

   static char input_buffer[1024];
   char        *current;

   current = yytext + yyleng; /* Skip current
                                 lexeme (reset previous)       */

   while(1){       /* Get the next one         */
      while(!*current ){
         /* Get new lines, skipping any leading
         * white space on the line,
         * until a nonblank line is found.
         */

         current = input_buffer;
         if(!gets(input_buffer)){
            *current = '\0' ;

            return EOI;
         }
         ++yylineno;
         while(isspace(*current))
            ++current;
      }
      for(; *current; ++current){
         /* Get the next token */
      	 //printf("%c\n",*current);
         yytext = current;
         yyleng = 1;
         switch( *current ){
           case ';':
            return SEMI;
           case '+':
            return PLUS;
           case '-':
            return MINUS;
           case '*':
            return TIMES;
           case '/':
            return DIV;
           case '(':
            return LP;
           case ')':
            return RP;
           case '<':
            return LT;
           case '>':
            return GT;
           case '=':
            return EQ;
           case ':':
            return COL;
           case '\n':
           case '\t':
           case ' ' :
            break;
           default:
            if(!isalnum(*current))
               fprintf(stderr, "Not alphanumeric <%c>\n", *current);
            else
            {
            	char val[100];
            	int i=0;
                while(isalnum(*current))
                {
               		val[i++]=*current;
			   		++current;
                }
                val[i]='\0';
                yyleng = current - yytext;
                if(!strcmp(val,"if"))
                {
               		return IF;
                }
                else if(!strcmp(val,"then"))
                {
               		return THEN;
                }
                else if(!strcmp(val,"while"))
                {
               		return WHILE;
                }
                else if(!strcmp(val,"do"))
                {
               		return DO;
                }
                else if(!strcmp(val,"begin"))
                {
               		return BEGIN;
                }
                else if(!strcmp(val,"end"))
                {
               		return END;
                }
                else if(val[0]>='a' && val[0]<='z' || val[0]>='A' && val[0]<='Z')
                {
               		return ID;
                }
                return NUM_OR_ID;
            }
            break;
         }
      }
   }
}


static int Lookahead = -1; /* Lookahead token  */

int match(int token){
   /* Return true if "token" matches the
      current lookahead symbol.                */

    if(Lookahead == -1)					// for the first time 
    	Lookahead = lex();
    //printf("%d\n",Lookahead);
    return token == Lookahead;
}

void advance(void){
/* Advance the lookahead to the next
   input symbol.                               */

    Lookahead = lex();					// every time after the first time, we are using advance()
}
