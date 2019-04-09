%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
extern int yylineno;
extern int yylex();
int yyerror(char *s);
%}
%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
    Node *n;        /* tree node */
};
%right THEN ELSE /*TODO https://stackoverflow.com/questions/12731922/reforming-the-grammar-to-remove-shift-reduce-conflict-in-if-then-else*/
%right ATR
%left '|'
%left '&'
%nonassoc '~'
%left '=' NE
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%nonassoc '!' INCR DECR SIMETRIC ADDRESSOF DEREFERENCING
%nonassoc '[' '('

%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC ELSE

%token FICH NIL DECLS DECL INIT EMPTYBODY
%type<n> decls decl tipo init lit params body

%%

ficheiro: decls    {printNode(binNode(FICH,$1,nilNode(NIL)),0,yynames);}
        ;

decls: decls decl  {$$=binNode(DECLS,$1,$2);}
     | /*vazio*/   {$$=nilNode(NIL);}
     ;

decl: PUBLIC CONST tipo '*' ID init ';' {$$=binNode(DECL,$3,$6);}
    | PUBLIC CONST tipo '*' ID ';'      {$$=binNode(DECL,$3,nilNode(NIL));}
    | PUBLIC CONST tipo ID init ';'     {$$=binNode(DECL,$3,$5);}
    | PUBLIC CONST tipo ID ';'          {$$=binNode(DECL,$3,nilNode(NIL));}
    | PUBLIC tipo '*' ID init ';'       {$$=binNode(DECL,$2,$5);}
    | PUBLIC tipo '*' ID ';'            {$$=binNode(DECL,$2,nilNode(NIL));}
    | PUBLIC tipo ID init ';'           {$$=binNode(DECL,$2,$4);}
    | PUBLIC tipo ID ';'                {$$=binNode(DECL,$2,nilNode(NIL));}
    | CONST tipo '*' ID init ';'        {$$=binNode(DECL,$2,$5);}
    | CONST tipo '*' ID ';'             {$$=binNode(DECL,$2,nilNode(NIL));}
    | CONST tipo ID init ';'            {$$=binNode(DECL,$2,$4);}
    | CONST tipo ID ';'                 {$$=binNode(DECL,$2,nilNode(NIL));}
    | tipo '*' ID init ';'              {$$=binNode(DECL,$1,$4);}
    | tipo '*' ID ';'                   {$$=binNode(DECL,$1,nilNode(NIL));}
    | tipo ID init ';'                  {$$=binNode(DECL,$1,$3);}
    | tipo ID ';' {}                    {$$=binNode(DECL,$1,nilNode(NIL));}
    ;

tipo: INTEGER {$$=nilNode(INTEGER);}
    | STRING  {$$=nilNode(STRING);}
    | NUMBER  {$$=nilNode(NUMBER);}
    | VOID {$$=nilNode(VOID);/*TODO so no caso de estar a inicializar uma funcao*/}
    ;

init: ATR INT              {$$=intNode(INT,$2);}     
    | ATR CONST STR        {$$=strNode(STR,$3);}
    | ATR STR              {$$=strNode(STR,$2);}
    | ATR REAL             {$$=realNode(REAL,$2);}
    | ATR ID               {$$=strNode(STR,$2);}
    | '(' params ')' body  {$$=binNode(INIT,$2,$4);}
    | '(' params ')'       {$$=binNode(INIT,$2,nilNode(NIL));}
    | '(' ')' body         {$$=binNode(INIT,nilNode(NIL),$3);}
    | '(' ')'              {$$=nilNode(EMPTYBODY);}
    | ID                   {$$=strNode(STR,$1);/*TODO caso seja um ponteiro e ambos os lados tem a mesma base*/}
    ;

params: params ',' param
      | param
      ;

param: tipo '*' ID
     | tipo ID
     ;

body: '{'bParams instrs'}';

bParams: bParams param ';'
       | /*vazio*/
       ;

instrs: instrs instr
      |
      ;

instr: IF expr THEN instr
     | IF expr THEN instr ELSE instr
     | DO instr WHILE expr ';'
     | FOR lval IN expr UPTO expr STEP expr DO instr 
     | FOR lval IN expr UPTO expr DO instr 
     | FOR lval IN expr DOWNTO expr STEP expr DO instr 
     | FOR lval IN expr DOWNTO expr DO instr 
     | expr';'
     | body
     | BREAK INT ';'
     | BREAK ';'
     | CONTINUE INT ';'
     | CONTINUE ';'
     | lval '#' expr ';' 
     ;

expr: lval
    | lit
    | lval ATR expr
    | expr '|' expr {/*TODO aplicavel a inteiros apenas TODO nao avaliar segundo argumento de nao for necessario*/}
    | expr '&' expr {/*TODO aplicavel a inteiros apenas TODO nao avaliar segundo argumento de nao for necessario*/}
    | '~' expr      {/*TODO aplicavel a inteiros apenas*/}
    | expr '=' expr {/*TODO inteiros reais e strings*/}
    | expr NE expr  {/*TODO inteiros reais e strings*/}
    | expr GE expr  {/*TODO inteiros reais e strings*/}
    | expr LE expr  {/*TODO inteiros reais e strings*/}
    | expr '<' expr {/*TODO inteiros reais e strings*/}
    | expr '>' expr {/*TODO inteiros reais e strings*/}
    | expr '-' expr {/*TODO expr tem que ser um valor inteiro or real TODO resultado e promovido a real caso haja apenas 1 real*/}
    | expr '+' expr {/*TODO expr tem que ser um valor inteiro or real TODO resultado e promovido a real caso haja apenas 1 real*/}
    | expr '%' expr {/*TODO expr tem que ser um valor inteiro or real TODO resultado e promovido a real caso haja apenas 1 real*/}
    | expr '/' expr {/*TODO expr tem que ser um valor inteiro or real TODO resultado e promovido a real caso haja apenas 1 real*/}
    | expr '*' expr {/*TODO expr tem que ser um valor inteiro or real TODO resultado e promovido a real caso haja apenas 1 real*/}
    | lval DECR   {/*TODO lvlal tem que ser do tipo inteiro*/}  
    | lval INCR   {/*TODO lvlal tem que ser do tipo inteiro*/}  
    | DECR lval   {/*TODO lvlal tem que ser do tipo inteiro*/}  
    | INCR lval   {/*TODO lvlal tem que ser do tipo inteiro*/}  
    | "-" expr %prec SIMETRIC{/*TODO expr tem que ser um valor inteiro or real*/}
    | expr '!' {/*TODO expr tem que ser um valor inteiro*/}
    | '&' lval %prec ADDRESSOF       
    | '*' lval %prec DEREFERENCING
    | '('expr')'
    | ID'('exprs')' {/*TODO ID tem que referir uma função previamente declarada ou definida. TODO verificar tipo ordem e dimensao dor args*/}
    | ID'(' ')' {/*TODO ID tem que referir uma função previamente declarada ou definida.*/}
    ;

lval: ID
    | ID'['expr']' {/*TODO ID deverá designar apenas uma variável ou constante do tipo ponteiro. */}
    ;

exprs: exprs ',' expr
    | expr
    ;

lit: STR  {$$=strNode(STR,$1);/*TODO verificar se podem ter o mesmo nome STR*/}
   | INT  {$$=intNode(INT,$1);/*TODO verificar se podem ter o mesmo nome STR*/}
   | REAL {$$=realNode(REAL,$1);/*TODO verificar se podem ter o mesmo nome STR*/}
   ;
 
%%
int yyerror(char *s) { fprintf(stderr, "ERROR in line %d: %s\n", yylineno, s); return 0; }
char *dupstr(const char*s) { return strdup(s); }

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

int main(int argc, char *argv[]) {

/*  extern YYSTYPE yylval;
 int tk;
 while ((tk = yylex())) 
  if (tk > YYERRCODE)
   printf("%d:\t%s\n", tk, yyname[tk]);
  else
   printf("%d:\t%c\n", tk, tk);
 return 0; */
 yyparse();
}

