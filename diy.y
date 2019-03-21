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
	int i;		
	double d;
	char* s;	    
};

%token <i> INT
%token <d> DBL
%token <s> STR NAME
%token VOID TYPEINTEGER TYPESTRING PUBLIC TYPENUMBER CONST IF THEN ELSE 
%token WHILE DO FOR IN STEP UPTO DOWNTO BREAK CONTINUE
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
		    if (tk > YYERRCODE) {
				printf("%d:\t%s\n", tk, yyname[tk]);
				/*if (yyname[tk]=="NAME")
					printf("NAME=%s\n",yylval.s);*/
			}
		    else
			    printf("%d:\t%c\n", tk, tk);
	    return 0;
    }
