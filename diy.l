%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
void yyerror(char *s);
int nested = 0;
%}
%x COM1 COM2 STR
%%

<STR>\"          BEGIN INITIAL;
<STR>.           ;

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

[a-zA-Z_][a-zA-Z_0-9]* yylval.s = strdup(yytext); return NAME;


[0][0-9]*		yylval.i = strtol(yytext, 0, 10); return INT;
[1-9][0-9]*     return INT;

\"			    BEGIN STR;

[ \n\r\t]+		;
.			    yyerror("unknown character"); if (0) {REJECT; unput    (*yytext); input(); };
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
