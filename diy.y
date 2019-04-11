%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabid.h"
#include "node.h"
extern int yylineno;
extern int yylex();
int yyerror(char *s);
int errors = 0;
Node *rootNode;
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
%nonassoc '!' INCR DECR SIM ADDR DREF
%nonassoc '[' '('

%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC ELSE

%token FICH NIL DECLS DECL PCDECL PDECL CDECL INIT EMPTYBODY INIT EPARAMS BPARAMS PARAM EXPR BODY INSTRS FORUP FORDW BREAK LVAL LIT INITATR INITELIPSIS
%token POSDECR POSINCR PREDECR PREINCR PAREXPR INVOC INDEX EXPRS
%type<n> decls decl tipo init lit eparams bparams body id param bparams instrs instr expr lval exprs

%%

ficheiro: decls    {rootNode= uniNode(FICH,$1);}
        ;

decls: decls decl  {$$=binNode(DECLS,$1,$2);}
     | /*vazio*/   {$$=nilNode(NIL);}
     ;

decl: PUBLIC CONST tipo '*' ID init ';' {$$=seqNode(PCDECL,3,$3,strNode(ID,$5),$6);IDnew(15+$3->info+$6->info,$5,0);}
    | PUBLIC CONST tipo '*' ID ';'      {$$=seqNode(PCDECL,3,$3,strNode(ID,$5),nilNode(NIL));IDnew(15+$3->info,$5,0);}
    | PUBLIC CONST tipo ID init ';'     {$$=seqNode(PCDECL,3,$3,strNode(ID,$4),$5);IDnew(5+$3->info+$5->info,$4,0);}
    | PUBLIC CONST tipo ID ';'          {$$=seqNode(PCDECL,3,$3,strNode(ID,$4),nilNode(NIL));IDnew(5+$3->info,$4,0);}
    | PUBLIC tipo '*' ID init ';'       {$$=seqNode(PDECL,3,$2,strNode(ID,$4),$5);IDnew(10+$2->info+$5->info,$4,0);}
    | PUBLIC tipo '*' ID ';'            {$$=seqNode(PDECL,3,$2,strNode(ID,$4),nilNode(NIL));IDnew(10+$2->info,$4,0);}
    | PUBLIC tipo ID init ';'           {$$=seqNode(PDECL,3,$2,strNode(ID,$3),$4);IDnew($2->info+$4->info,$3,0);}
    | PUBLIC tipo ID ';'                {$$=seqNode(PDECL,3,$2,strNode(ID,$3),nilNode(NIL));IDnew($2->info,$3,0);}
    | CONST tipo '*' ID init ';'        {$$=seqNode(CDECL,3,$2,strNode(ID,$4),$5);IDnew(15+$2->info+$5->info,$4,0);}
    | CONST tipo '*' ID ';'             {yyerror("Non-public constants must be initialized\n");}
    | CONST tipo ID init ';'            {$$=seqNode(CDECL,3,$2,strNode(ID,$3),$4);IDnew(5+$2->info+$4->info,$3,0);}
    | CONST tipo ID ';'                 {yyerror("Non-public constants must be initialized\n");}
    | tipo '*' ID init ';'              {$$=seqNode(DECL,3,$1,strNode(ID,$3),$4);IDnew(10+$1->info+$4->info,$3,0);}
    | tipo '*' ID ';'                   {$$=seqNode(DECL,3,$1,strNode(ID,$3),nilNode(NIL));IDnew(10+$1->info,$3,0);}
    | tipo ID init ';'                  {$$=seqNode(DECL,3,$1,strNode(ID,$2),$3);IDnew($1->info+$3->info,$2,0);}
    | tipo ID ';'                       {$$=seqNode(DECL,3,$1,strNode(ID,$2),nilNode(NIL));IDnew($1->info,$2,0);}
    ;

tipo: INTEGER {$$=nilNode(INTEGER);$$->info=1;}
    | STRING  {$$=nilNode(STRING);$$->info=2;}
    | NUMBER  {$$=nilNode(NUMBER);$$->info=3;}
    | VOID    {$$=nilNode(VOID);$$->info=4;}
    ;

init: ATR INT              {$$=uniNode(INITATR,intNode(INT,$2));$$->info=0;}     
    | ATR CONST STR        {$$=uniNode(INITATR,strNode(STR,$3));$$->info=0;} /*TODO acrescentar algo ao no que permita destinguir que e uma const*/
    | ATR STR              {$$=uniNode(INITATR,strNode(STR,$2));$$->info=0;}
    | ATR REAL             {$$=uniNode(INITATR,realNode(REAL,$2));$$->info=0;}
    | ATR ID               {$$=uniNode(INITATR,strNode(ID,$2));$$->info=0;} /*TODO caso seja um ponteiro e ambos os lados tem a mesma base*/
    | '(' eparams ')' body {$$=binNode(INITELIPSIS,$2,$4);$$->info=20;}
    | '(' eparams ')'      {$$=binNode(INITELIPSIS,$2,nilNode(NIL));$$->info=20;}
    | '(' ')' body         {$$=binNode(INITELIPSIS,nilNode(NIL),$3);$$->info=20;}
    | '(' ')'              {$$=binNode(INITELIPSIS,nilNode(NIL),nilNode(NIL));$$->info=20;}
    ;

eparams: eparams ',' param {$$=binNode(EPARAMS,$1,$3);}
      | param            {$$=uniNode(PARAM,$1);}
      ;

param: tipo '*' ID {$$=binNode(PARAM,$1,strNode(ID,$3));}
     | tipo ID     {$$=binNode(PARAM,$1,strNode(ID,$2));}
     ;

body: '{'bparams instrs'}' {$$=binNode(BODY,$2,$3);}
    ; 

bparams: bparams param ';' {$$=binNode(BPARAMS,$1,$2);}
       | /*vazio*/         {$$=nilNode(NIL);}
       ;

instrs: instrs instr {$$=binNode(INSTRS,$1,$2);}
      |              {$$=nilNode(NIL);}
      ;

instr: IF expr THEN instr                              {$$=seqNode(IF,3,$2,$4,nilNode(NIL));}
     | IF expr THEN instr ELSE instr                   {$$=seqNode(IF,3,$2,$4,$6);}
     | DO instr WHILE expr ';'                         {$$=binNode(DO,$2,$4);}
     | FOR lval IN expr UPTO expr STEP expr DO instr   {$$=seqNode(FORUP,5,$2,$4,$6,$8,$10);}
     | FOR lval IN expr UPTO expr DO instr             {$$=seqNode(FORUP,5,$2,$4,$6,nilNode(NIL),$8);}
     | FOR lval IN expr DOWNTO expr STEP expr DO instr {$$=seqNode(FORDW,5,$2,$4,$6,$8,$10);}
     | FOR lval IN expr DOWNTO expr DO instr           {$$=seqNode(FORDW,5,$2,$4,$6,nilNode(NIL),$8);}
     | expr';'           {$$=uniNode(EXPR,$1);}
     | body              {$$=uniNode(BODY,$1);}
     | BREAK INT ';'     {$$=uniNode(BREAK,intNode(INT,$2));}
     | BREAK ';'         {$$=uniNode(BREAK,nilNode(NIL));}
     | CONTINUE INT ';'  {$$=uniNode(CONTINUE,intNode(INT,$2));}
     | CONTINUE ';'      {$$=uniNode(CONTINUE,nilNode(NIL));}
     | lval '#' expr ';' {$$=binNode('#',$1,$3);}
     ;

expr: lval          {$$=uniNode(LVAL,$1); if($$->attrib==PAREXPR)yyerror("Expression inside parentesis can't be a left value");}
    | lit           {$$=uniNode(LIT,$1);}
    | lval ATR expr {$$=binNode(ATR,$1,$3);}
    | expr '|' expr {$$=binNode('|',$1,$3);}
    | expr '&' expr {$$=binNode('&',$1,$3);}
    | '~' expr      {$$=uniNode('~',$2);}
    | expr '=' expr {$$=binNode('=',$1,$3);}
    | expr NE expr  {$$=binNode(NE,$1,$3);}
    | expr GE expr  {$$=binNode(GE,$1,$3);}
    | expr LE expr  {$$=binNode(LE,$1,$3);}
    | expr '<' expr {$$=binNode('<',$1,$3);}
    | expr '>' expr {$$=binNode('>',$1,$3);}
    | expr '-' expr {$$=binNode('-',$1,$3);}
    | expr '+' expr {$$=binNode('+',$1,$3);}
    | expr '%' expr {$$=binNode('%',$1,$3);}
    | expr '/' expr {$$=binNode('/',$1,$3);}
    | expr '*' expr {$$=binNode('*',$1,$3);}
    | lval DECR     {$$=uniNode(POSDECR,$1);}  
    | lval INCR     {$$=uniNode(POSINCR,$1);}  
    | DECR lval     {$$=uniNode(PREDECR,$2);}  
    | INCR lval     {$$=uniNode(PREINCR,$2);}  
    | "-" expr %prec SIM  {$$=uniNode(SIM,$2);}
    | expr '!'            {$$=uniNode('!',$1);}
    | '&' lval %prec ADDR {$$=uniNode(ADDR,$2);}     
    | '*' lval %prec DREF {$$=uniNode(DREF,$2);} 
    | '('expr')'          {$$=uniNode(PAREXPR,$2);}
    | ID'('exprs')'       {$$=binNode(INVOC,strNode(ID,$1),$3);} 
    | ID'(' ')'           {$$=binNode(INVOC,strNode(ID,$1),nilNode(NIL));} 
    ;

lval: ID           {$$=strNode(ID,$1);}
    | ID'['expr']' {$$=binNode(INDEX,strNode(ID,$1),$3);}
    ;

exprs: exprs ',' expr {$$=binNode(EXPRS,$1,$3);}
    | expr            {$$=uniNode(EXPR,$1);}
    ;

lit: STR  {$$=strNode(STR,$1);}
   | INT  {$$=intNode(INT,$1);}
   | REAL {$$=realNode(REAL,$1);}
   ;
 
%%
int yyerror(char *s) {errors++; fprintf(stderr, "ERROR in line %d: %s\n", yylineno, s); return 0; }
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
 if (yyparse() != 0 || errors > 0) {
    fprintf(stderr, "%d errors\n", errors);
    return 1;
  }
  printNode(rootNode,stdout,yynames);
  return 0;
}

