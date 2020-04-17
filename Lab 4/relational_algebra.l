%{

#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "relational_algebra.tab.h"
char *trimwhitespace(char *str);

%}

b   [ ]*

%option noyywrap

%%

{b}"SELECT"{b}|{b}"select"{b}                           {return SELECT;}
{b}"PROJECT"{b}|{b}"project"{b}                         {return PROJECT;}
{b}"CARTESIAN_PRODUCT"{b}|{b}"cartesian_product"{b}     {return CARTESIAN_PRODUCT;}
{b}"EQUI_JOIN"{b}|{b}"equi_join"{b}                     {return EQUI_JOIN;}
{b}"<="{b}                                              {return LE;}
{b}">="{b}                                              {return GE;}
{b}"="{b}                                               {return EQ;}
{b}"<>"{b}                                              {return NEQ;}
{b}"<"{b}               																{return LT;}
{b}">"{b}               																{return GT;}
{b}"AND"{b}|{b}"and"{b}                                 {return AND;}
{b}"OR"{b}|{b}"or"{b}                                   {return OR;}
{b}"not"{b}|{b}"NOT"{b}                   							{return NOT;}
{b}","{b}                                       				{return COMMA;}
{b}"\."{b}                                      				{return DOT;}
{b}"("{b}                                       				{return LP;}
{b}")"{b}                                       				{return RP;}
{b}[A-Za-z_][0-9A-Za-z_]*{b}                    				{yylval.id_attributes.id_name=trimwhitespace(strdup(yytext));  return ID; }
{b}[0-9]+{b}                                    				{yylval.val= atoi(yytext);  return INT; }
{b}"'"{b}																								{return QUOTE;}
\n 																											{return NEWLINE; }

%%

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}
