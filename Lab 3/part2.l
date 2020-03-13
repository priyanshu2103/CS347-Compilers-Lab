/* Declaring two counters one for number
of lines other for number of characters */
%{
#define SELECT 1
#define PROJECT 2
#define CARTESIAN_PRODUCT 3
#define EQUI_JOIN 4
#define LTE 5
#define GTE 6
#define NOT_EQUAL 7
#define LT 8
#define GT 9
#define EQUAL 10
#define AND 11
#define OR 12
#define NOT 13
#define COMMA 14
#define DOT 15
#define LP 16
#define RP 17
#define ID 18
#define INT 19
%}


%%

"SELECT|select"                           {printf("<%s> ",yytext ); return SELECT;}
"PROJECT|project"                         {printf("<%s> ",yytext ); return PROJECT;}
"CARTESIAN_PRODUCT|cartesian_project"     {printf("<%s> ",yytext ); return CARTESIAN_PRODUCT;}
"EQUI_JOIN|equi_join"                     {printf("<%s> ",yytext );	return EQUI_JOIN;}
"<="                                      {printf("<%s> ",yytext ); return LTE;}
">="                                      {printf("<%s> ",yytext ); return GTE;}
"!="                                      {printf("<%s> ",yytext ); return NOT_EQUAL;} 
"<"                                       {printf("<%s> ",yytext ); return LT;}
">"                                       {printf("<%s> ",yytext ); return GT;} 
"="                                       {printf("<%s> ",yytext ); return EQUAL;}             
"AND|and"                                 {printf("<%s> ",yytext ); return AND;}
"OR|or"                                   {printf("<%s> ",yytext ); return OR;}
"NOT|not"                                 {printf("<%s> ",yytext ); return NOT;}
","                                       {printf("<%s> ",yytext ); return COMMA;}
"\."                                      {printf("<%s> ",yytext ); return DOT;}
"("                                       {printf("<%s> ",yytext ); return LP;}
")"                                       {printf("<%s> ",yytext ); return RP;}
[A-Za-z_][0-9A-Za-z_]*                    {printf("<%s> ",yytext ); return ID; }
[0-9]+                                    {printf("<%s> ",yytext ); return INT; }
%%

int yywrap(){}
int main()
{
	yylex();
}