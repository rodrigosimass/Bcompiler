%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "y.tab.h"
#define MAXINT 2147483647
#define MAXDBL 9223372036854775807
void yyerror(char *s);
int nested = 0;
%}
%x COM1 COM2 STRG
%%

<STRG>\"          BEGIN INITIAL;
<STRG>\\\"        strcat(yylval.s,yytext);
<STRG>.           strcat(yylval.s,(char)yytext);
<STRG>\n          strcat(yylval.s,(char)yytext);

<COM1>"=<"       nested++;
<COM1>"=>"       if(nested==0)BEGIN INITIAL;else nested--;
<COM1>.|\n       ;

<COM2>"\n"       BEGIN INITIAL;
<COM2>.          ;


"=<"            BEGIN COM1;
"=="            BEGIN COM2;
 
"void"          return VOID;
"integer"       return INTEGER;
"string"        return STRING;
"public"        return PUBLIC;
"number"        return NUMBER;
"const"         return CONST;
"if"            return IF;
"then"          return THEN;
"else"          return ELSE;
"while"         return WHILE;
"do"            return DO;
"for"           return FOR;
"in"            return IN;
"step"          return STEP;
"upto"          return UPTO;
"downto"        return DOWNTO;
"break"         return BREAK;
"continue"      return CONTINUE;

"="	            return EQ;
">="	        return GE;
"<="	        return LE;
"<>"	        return NE;
":="	        return ASSIGN;
"++"            return INC;
"--"	        return DEC;

[-+*/%!&|~^<>()?:;,\[\]{}#]	return *yytext;

[a-zA-Z][a-zA-Z_0-9]*       yylval.s = strdup(yytext); return NAME;

[1-9][0-9]*     errno = 0;yylval.i = strtol(yytext    , 0, 10);if (errno == ERANGE) yyerror("integer overflow");return INT;
"0"[0-7]*		errno = 0;yylval.i = strtol(yytext + 1, 0, 8 );if (errno == ERANGE) yyerror("integer overflow");return INT;
"0"[0-9]*		errno = 0;yylval.i = strtol(yytext + 1, 0, 10);if (errno == ERANGE) yyerror("integer overflow");return INT;
"0b"[01]+       errno = 0;yylval.i = strtol(yytext + 2, 0, 2 );if (errno == ERANGE) yyerror("integer overflow");return INT;

[0-9]+\.[0-9]+([eE][-+]?[1-9][0-9]*)?  errno = 0; yylval.d =  strtod(yytext,0);if (errno == ERANGE) yyerror("double overflow");return DBL;

\"			    BEGIN STRG;

[ \n\r\t]+		;
.			    yyerror("unknown character"); if (0) {REJECT; unput    (*yytext); input(); };
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }