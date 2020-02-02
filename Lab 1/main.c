# include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "lex.h"
#include "lex.c"
int main ()
{
	FILE * fp_sym = fopen("./symbolTable.txt", "w");
	fclose(fp_sym);
	int current_tok;
	int id_seq;
	FILE * fp_temp;

	id_seq=1;
	current_tok=lex();                     //lex() defined in lex.c
	while(current_tok != EOI)              //EOI and other MACROS in lex.h
	{
		//printf("%d\n",current_tok);
		switch(current_tok)                 //print appropriate token
      {
        case SEMI:
        printf("< ; >");
          	break;
        case PLUS:
        printf("< + >");
        	break;
        case MINUS:
        printf( "< - >");
        	break;
        case TIMES:
        printf("< * >");
        	break;
        case DIV:
        printf("< / >");
        	break;
        case LP:
        printf("< ( >");
        	break;
        case RP:
        printf("< ) >");
        	break;
        case LT:
        printf("< < >");
        	break;
        case GT:
        printf("< > >");
        	break;
        case COL:
        printf( "< : >");
        	break;
        case EQ:
        printf( "< = >");
        	break;
        case IF:
        printf("< IF >");
          break;
        case THEN:
        printf("< THEN >");
          break;
        case WHILE:
        printf("< WHILE >");
          break;
        case DO:
        printf("< DO >");
          break;
        case BEGIN:
        printf("< BEGIN >");
          break;
        case END:
        printf("< END >");
          break;
        case NUM_OR_ID:                   //case of ID checked before num in lex, so effectively this is NUM only.
        {
        	char identifier[100];            //yytext and yyleng defined in lex.c, to track current position in input
          char *p=yytext;
          int i;
          for(i=0;i<yyleng;i++)
          {
            identifier[i]=*p++;
          }
          identifier[i]='\0';
          printf( "< CONST,%s >", identifier);
        }
        
        break;
        case ID:
        {
        	char identifier[100];
    			char *p=yytext;
    			int i;
    			for(i=0;i<yyleng;i++)
    			{
    				identifier[i]=*p++;
    			}
		    	identifier[i]='\0';
        	fp_temp = fopen("./symbolTable.txt", "r");    //make a symbol table to save all encountered ID
        	char symText[1024];
        	int count=0;

        	while(fgets(symText, INT_MAX, fp_temp) != NULL){       //read each line of symbol table and compare with current identifier
            if(strcmp(strtok(symText, " "), identifier) == 0)
              break;
            count++;
          }

          fclose(fp_temp);

          if(count >= id_seq-1){                                  //if new identifier, put it in symbol table and print its token
            FILE* fp_temp =  fopen("./symbolTable.txt", "a+");
          	fprintf(fp_temp, "%s %d\n", identifier, id_seq);
          	printf( "< ID,%d >", id_seq);
          	id_seq++;
            fclose(fp_temp);

          }
          else{
            char* token;
            token = strtok(NULL, " ");
            token[strlen(token)-1] = '\0';
            printf( "< ID,%s >", token);
          }
          
        	break;
       	}  
        default: break;
       }
       printf("\n");
       current_tok=lex(); //get next token

	}


	//statements();
	return 0;
}
