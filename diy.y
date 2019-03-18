%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tabid.h"
#ifndef YYERRCODE
#define YYERRCODE 256
#endif
#define YYDEBUG 1
extern int yylex();
%}

%union {
	int i;			/* integer value */
	char *s;	    /* symbol name or string literal */
};

%token <i> INT
%token VOID INTEGER STRING PUBLIC NUMBER CONST IF THEN ELSE 
%token WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE NAME
%token EQ GE LE NE ASSIGN INC DEC
%%
file	:
	;
%%
int yyerror(char *s) { printf("%s\n",s); return 1; }
    char *dupstr(const char*s) { return strdup(s); }
    int main(int argc, char *argv[]) {
	    extern YYSTYPE yylval;
	    int tk;
	    while ((tk = yylex())) 
		    if (tk > YYERRCODE)
			    printf("%d:\t%s\n", tk, yyname[tk]);
		    else
			    printf("%d:\t%c\n", tk, tk);
	    return 0;
    }
