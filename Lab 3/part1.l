/* Declaring two counters one for number
of lines other for number of characters */
%{
#include<stdbool.h>
#include<string.h>
#include<math.h>
int obj_def=0;
int class_def=0;
int constr_def=0;
int inh_class_def=0;
bool commentflag=false;
bool multcomm=false;
bool quoteflag=false;
char ClassName[1024][1024];
int idx=0;
bool searchClassName(char *);
%}

/***rule 1 counts the number of lines,
rule 2 counts the number of characters
and rule 3 specifies when to stop
taking input***/
%%

"//"   {if(!quoteflag &&!multcomm)
			{
				if(!commentflag)
					commentflag=true;
			}
			printf("2 %s\n",yytext);
		 }
\n   {
commentflag=false;
}
"/*"   {if(!quoteflag && !commentflag)
			{
				multcomm=true;
			}
			printf("3 %s\n",yytext);
		 }
"*/"  {
				if(!quoteflag)
					multcomm=false;
				printf("4 %s\n",yytext);
		 }
\" {
			if(quoteflag) quoteflag=false;
			else quoteflag=true;
			printf("5 %s\n",yytext);
		}
new[ ][a-zA-Z][a-zA-Z0-9_]*[(] {if(!commentflag && !quoteflag && !multcomm)
 														{
															char *t=yytext;
															int y=yyleng;
															t+=4;
															y-=4;
															char s[1024];
															for(int i=0;i<y-1;i++)
															{
																s[i]=*t;
																t++;
															}
															s[y-1]='\0';
															if(searchClassName(s))
															{
																obj_def++;
															}
															else
															{

															}
														}
													}
class[ ][a-zA-Z][a-zA-Z0-9_]* {if(!commentflag && !quoteflag &&!multcomm)
 														{
															class_def++;
															printf("bef\n");
															char *t=yytext;
															int y=yyleng;
															t+=6;
															y-=6;
															printf("aft\n");
															char s[1024];
															for(int i=0;i<y;i++)
															{
																s[i]=*t;
																t++;
															}
															s[y]='\0';
															for(int i=0;i<y;i++)
															{
																ClassName[idx][i]=s[i];
															}
															ClassName[idx][y]='\0';
															idx++;
														}
													}
class[ ][a-zA-Z][a-zA-Z0-9_]*[ ]extends[ ][a-zA-Z][a-zA-Z0-9_]*	 {if(!commentflag && !quoteflag &&!multcomm)
 														{
															class_def++;
															inh_class_def++;
															char *t=yytext;
															int y=yyleng;
															t+=6;
															y-=6;
															char s[1024];
															int i;
															for(i=0;i<y;i++)
															{
																if(*t==' ') break;
																s[i]=*t;
																t++;
															}
															s[i]='\0';
															for(int j=0;j<i;j++)
															{
																ClassName[idx][j]=s[j];
															}
															ClassName[idx][i]='\0';
															idx++;
														}
													}
[a-zA-Z][a-zA-Z0-9_]*[(] {   char *t=yytext;
														 int y=yyleng;
														 char s[1024];
														 for(int i=0;i<y-1;i++)
														 {
														 	s[i]=*t;
															t++;
													  	}
														 s[y-1]='\0';
														 if(searchClassName(s))
														 {
														  constr_def++;
														 }
}
%%

/*** User code section***/
int yywrap(){}

bool searchClassName(char* s)
{
	for(int i=0;i<1024;i++)
	{
		if(strcmp(ClassName[i],s)==0)
			return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	yylex();
	printf("Object Definitions %d\n",obj_def);
	printf("Class Definitions %d\n",class_def);
	printf("Constructor Definitions %d\n",constr_def);
	printf("Inherited Class Definitions %d\n",inh_class_def);
	for(int i=0;i<idx;i++)
	{
		printf("%s\n",ClassName[i]);
	}
	return 0;
}
