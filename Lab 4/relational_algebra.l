%{

#include<stdlib.h>
#include<string.h>
#include "relational_algebra.tab.h"

%}

b   [ ]*

%option noyywrap

%%

{b}"SELECT"{b}|{b}"select"{b}                           {printf("%s ",yytext ); return SELECT;}
{b}"PROJECT"{b}|{b}"project"{b}                         {printf("%s ",yytext ); return PROJECT;}
{b}"CARTESIAN_PRODUCT"{b}|{b}"cartesian_product"{b}     {printf("%s ",yytext ); return CARTESIAN_PRODUCT;}
{b}"EQUI_JOIN"{b}|{b}"equi_join"{b}                     {printf("%s ",yytext );	return EQUI_JOIN;}
{b}"<="{b}                                              {printf("%s ",yytext ); return LE;}
{b}">="{b}                                              {printf("%s ",yytext ); return GE;}
{b}"="{b}                                               {printf("%s ",yytext ); return EQ;}
{b}"<>"{b}                                              {printf("%s ",yytext ); return NEQ;}
{b}"<"{b}               																{printf("%s ",yytext ); return LT;}
{b}">"{b}               																{printf("%s ",yytext ); return GT;}
{b}"AND"{b}|{b}"and"{b}                                 {printf("%s ",yytext ); return AND;}
{b}"OR"{b}|{b}"or"{b}                                   {printf("%s ",yytext ); return OR;}
{b}"not"{b}|{b}"NOT"{b}                   							{printf("%s ",yytext ); return NOT;}
{b}","{b}                                       				{printf("%s ",yytext ); return COMMA;}
{b}"\."{b}                                      				{printf("%s ",yytext ); return DOT;}
{b}"("{b}                                       				{printf("%s ",yytext ); return LP;}
{b}")"{b}                                       				{printf("%s ",yytext ); return RP;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    				{yylval.id_attributes.id_name= strdup(yytext);  printf("%s ",yytext ); return ID; }
{b}[0-9]+{b}                                    				{yylval.val= atoi(yytext);  printf("%s ",yytext ); return INT; }
{b}"'"{b}																								{printf("%s ",yytext ); return QUOTE;}
\n 																											{printf("%s ",yytext ); return NEWLINE; }

%%
