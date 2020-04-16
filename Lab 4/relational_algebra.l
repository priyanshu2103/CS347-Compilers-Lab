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
{b}"CARTESIAN_PRODUCT"{b}|{b}"cartesian_project"{b}     {printf("%s ",yytext ); return CARTESIAN_PRODUCT;}
{b}"EQUI_JOIN"{b}|{b}"equi_join"{b}                     {printf("%s ",yytext );	return EQUI_JOIN;}
{b}"<="{b}|{b}">="{b}|{b}"="{b}|{b}"<>"{b}              {printf("%s ",yytext ); return OPER;}
{b}"<"{b}               																{printf("%s ",yytext ); return LT;}
{b}">"{b}               																{printf("%s ",yytext ); return GT;}
{b}"AND"{b}|{b}"and"{b}|{b}"OR"{b}|{b}"or"{b}           {printf("%s ",yytext ); return LOG;}
{b}"not"{b}|{b}"NOT"{b}                   							{printf("%s ",yytext ); return NOT;}
{b}","{b}                                       				{printf("%s ",yytext ); return COMMA;}
{b}"\."{b}                                      				{printf("%s ",yytext ); return DOT;}
{b}"("{b}                                       				{printf("%s ",yytext ); return LP;}
{b}")"{b}                                       				{printf("%s ",yytext ); return RP;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    				{printf("%s ",yytext ); return ID; }
{b}[0-9]+{b}                                    				{printf("%s ",yytext ); return INT; }
{b}"'"{b}																								{printf("%s ",yytext ); return QUOTE;}
\n 																											{printf("%s ",yytext ); return NEWLINE; }

%%
