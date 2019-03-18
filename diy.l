%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "node.h"
#include "y.tab.h"
char *dupstr(const char *s);
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
"integer"       ;
"string"        ;
"public"        ;
"number"        ;
"const"         ;
"if"            ;
"then"          ;
"else"          ;
"while"         ;
"do"            ;
"for"           ;
"in"            ;
"step"          ;
"upto"          ;
"downto"        ;
"break"         ;
"continue"      ;

"="	            ;
">="	        ;
"<="	        ;
"<>"	        ;
":="	        ;
"++"            ;
"--"	        ;

[a-zA-Z][a-zA-Z_0-9]* ECHO;

\"			    BEGIN STR;

[ \n\r\t]+		ECHO;
.			    ;
%%
int yywrap(void) {
  if (YYSTATE == COM1 || YYSTATE == COM2) yyerror("unterminated comment");
  if (YYSTATE == STR) yyerror("unterminated string");
  return 1;
} 
char *getyytext() { return yytext; }
