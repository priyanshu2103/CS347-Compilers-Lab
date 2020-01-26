#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include "lex.h"
char *Names[] = { "_t0", "_t1", "_t2", "_t3", "_t4", "_t5", "_t6", "_t7" };   
char **Namep  = Names;   
   
extern char *newname()   
{   
    if( Namep >= &Names[ sizeof(Names)/sizeof(*Names) ] )   // max t0-t7 entries
    {   
        fprintf( stderr, "%d: Expression too complex\n", yylineno );   
        exit( 1 );   
    }   
    return( *Namep++ );   
}   
   
extern void freename(char *s)   
{   
    if( Namep > Names )   // can only go back if > 0 (Names => 0) 
    	*--Namep = s;   
    else   
    	fprintf(stderr, "%d: (Internal error) Name stack underflow\n", yylineno );   
}   
