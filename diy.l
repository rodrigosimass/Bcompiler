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

[ \n\r\t]+		;
.			    ;
%%
int yywrap(void) { return 1; }
char *getyytext() { return yytext; }
int character(char *s)
{
  int val, i, pos;
  for (val = pos = i = 0; s[pos] != '\'' && i < 4; i++, pos++) {
    if (s[pos] == '*')
      switch(s[++pos]) {
        case '*': case '(': case ')':  case '\'': case '"':  break;
	case 't': s[pos] = '\t'; break;
	case 'n': s[pos] = '\n'; break;
	case '0': s[pos] = '\0'; break;
	default: yyerror("invalid character escape sequence"); break;
      }
    val |= s[pos] << (i*8);
  }
  if (i == 4 && s[pos] != '\'') yyerror("character sequence too long");
  return val;
}

int octal(char *s)
{
  int i, a = 0, b = 0;

  for (i = 0; i < strlen(s); i++) {
    if (s[i] < '0' || s[i] > '9') break;
    b = b * 8 + s[i] - '0';
    if (b < a) {
      yyerror("octal overflow");
      break;
    }
    a = b;
  }
  return a;
}
