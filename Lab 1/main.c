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
	//FILE * fp_tok = fopen("./token.txt", "w");
	int current_tok;
	int id_seq;
	FILE * fp_temp;

	id_seq=1;
	current_tok=lex();
	while(current_tok != EOI)
	{
		//printf("%d\n",current_tok);
		switch(current_tok)
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
        case NUM_OR_ID:
        {
        	char identifier[100];
          char *p=yytext;
          int i;
          for(i=0;i<yyleng;i++)
          {
            identifier[i]=*p++;
          }
          identifier[i]='\0';
          printf( "%s\n", identifier);
        }
        //printf(fp_tok,"<const,%s>",val);
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
        	fp_temp = fopen("./symbolTable.txt", "r");
        	char symText[1024];
        	int count=0;

        	while(fgets(symText, INT_MAX, fp_temp) != NULL){
            

            if(strcmp(strtok(symText, " "), identifier) == 0){
              break;
            }
            count++;

          }

          fclose(fp_temp);

          


          if(count >= id_seq-1){
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
       current_tok=lex();
	}


	//statements();
	//fclose(fp_tok);
	return 0;
}
