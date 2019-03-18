%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
<COM1>"=>"       if(nested==0) BEGIN INITIAL;else nested--;
<COM1>.|\n       ECHO;

<COM2>"\n"       BEGIN INITIAL;
<COM2>.          ECHO;

\"			    BEGIN STR;

"=<"            BEGIN COM1;
"=="            BEGIN COM2;


[ \n\r\t]+		;
.			    ;
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
