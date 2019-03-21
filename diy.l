%{
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "y.tab.h"
#define MAXINT 2147483647
#define MAXDBL 9223372036854775807
void yyerror(char *s);
int nested = 0;
int nltosemicolon = 0;
char c[2];
%}
%x XCOM1 XCOM2 XSTR
%%
"=<"             BEGIN XCOM1;
<XCOM1>"=<"       nested++;
<XCOM1>"=>"       if(nested==0)BEGIN INITIAL;else nested--;
<XCOM1>.|\n       ;

"=="             BEGIN XCOM2;
<XCOM2>"\n"       BEGIN INITIAL;
<XCOM2>.          ;
 
"void"          return VOID;
"integer"       return TYPEINTEGER;
"string"        return TYPESTRING;
"public"        return PUBLIC;
"number"        return TYPENUMBER;
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
">="	          return GE;
"<="	          return LE;
"<>"	          return NE;
":="	          return ASSIGN;
"++"            return INC;
"--"	          return DEC;

([)!]|[1-9][0-9]*|"0"[0-7]*|"0"[0-9]*|"0b"[01]+|[0-9]+\.[0-9]+([eE][-+]?[1-9][0-9]*)?|\"(.)*\")[ \r\t]*"\n" nltosemicolon=1;REJECT;

[-+*/%!&|~^<>()?:;,\[\]{}#]	return *yytext;


[a-zA-Z][a-zA-Z_0-9]*       yylval.s = strdup(yytext); return NAME;


[1-9][0-9]*     errno = 0;yylval.i = strtol(yytext    , 0, 10);if (errno == ERANGE) yyerror("integer overflow");return INT;
"0"[0-7]*		    errno = 0;yylval.i = strtol(yytext + 1, 0, 8 );if (errno == ERANGE) yyerror("integer overflow");return INT;
"0"[0-9]*		    errno = 0;yylval.i = strtol(yytext + 1, 0, 10);if (errno == ERANGE) yyerror("integer overflow");return INT;
"0b"[01]+       errno = 0;yylval.i = strtol(yytext + 2, 0, 2 );if (errno == ERANGE) yyerror("integer overflow");return INT;


[0-9]+\.[0-9]+([eE][-+]?[1-9][0-9]*)?  errno = 0; yylval.d =  strtod(yytext,0);if (errno == ERANGE) yyerror("double overflow");return DBL;


\"			         BEGIN XSTR;yylval.s = (char*)malloc(256);
<XSTR>\"          BEGIN INITIAL;return STR;
<XSTR>\\\"        strcat(yylval.s, "\"");
<XSTR>\\([0-9a-fA-F])*    c[0] = strtol(yytext+1,0,16); strcat(yylval.s, c);
<XSTR>.|\n        strcat(yylval.s, yytext);

[ \n\r\t]+		if(nltosemicolon==1){nltosemicolon = 0;return ';';}

.			    yyerror("unknown character"); if (0) {REJECT; unput    (*yytext); input(); };
%%
int yywrap(void) {
  if (YYSTATE == XCOM1) yyerror("unterminated comment");
  if (YYSTATE == XCOM2) yyerror("unterminated comment");
  if (YYSTATE == XSTR) yyerror("unterminated string");
  return 1;
} 
char *getyytext() { return yytext; }
