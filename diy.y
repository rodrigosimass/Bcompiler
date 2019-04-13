%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabid.h"
#include "node.h"
#include "list.h"
extern int yylineno;
extern int yylex();
int yyerror(char *s);
int errors = 0;
int t;
int inLoop = 0;
long args = 0;
char * errorMsg1 = "Invalid type(s) of operand(s)";
char * errorMsg2 = "Break instruction must be inside a loop";
char * errorMsg3 = "Continue instruction must be inside a loop";
char * errorMsg4 = "Invalid invocation of function";
int verifyTypes(int operation, int operand1, int operand2);
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
%token POSDECR POSINCR PREDECR PREINCR PAREXPR INVOC INDEX EXPRS INSTR
%type<n> decls decl tipo init lit eparams bparams body param bparams instrs instr expr lval exprs

%%

ficheiro: decls    {rootNode= uniNode(FICH,$1);}
        ;

decls: decls decl  {$$=binNode(DECLS,$1,$2);}
     | /*vazio*/   {$$=nilNode(NIL);}
     ;

decl: PUBLIC CONST tipo '*' ID {IDpush();IDnew(15+$3->info,$5,0);}init{IDpop();} ';' {$$=seqNode(PCDECL,3,$3,strNode(ID,$5),$7);IDnew(15+$3->info+$7->info,$5,(long)$7->user);print_list($7->user);}
    | PUBLIC CONST tipo '*' ID ';'      {$$=seqNode(PCDECL,3,$3,strNode(ID,$5),nilNode(NIL));IDnew(15+$3->info,$5,0);}
    | PUBLIC CONST tipo ID {IDpush();IDnew($3->info,$4,0);}init{IDpop();} ';' {$$=seqNode(PCDECL,3,$3,strNode(ID,$4),$6);IDnew(5+$3->info+$6->info,$4,(long)$6->user);print_list($6->user);}
    | PUBLIC CONST tipo ID ';'          {$$=seqNode(PCDECL,3,$3,strNode(ID,$4),nilNode(NIL));IDnew(5+$3->info,$4,0);}
    | PUBLIC tipo '*' ID {IDpush();IDnew(10+$2->info,$4,0);}init{IDpop();} ';' {$$=seqNode(PDECL,3,$2,strNode(ID,$4),$6);IDnew(10+$2->info+$6->info,$4,(long)$6->user);print_list($6->user);}
    | PUBLIC tipo '*' ID ';'            {$$=seqNode(PDECL,3,$2,strNode(ID,$4),nilNode(NIL));IDnew(10+$2->info,$4,0);}
    | PUBLIC tipo ID {IDpush();IDnew($2->info,$3,0);}init{IDpop();} ';' {$$=seqNode(PDECL,3,$2,strNode(ID,$3),$5);IDnew($2->info+$5->info,$3,(long)$5->user);print_list($5->user);printf("end=%p\n",$5->user);}
    | PUBLIC tipo ID ';'                {$$=seqNode(PDECL,3,$2,strNode(ID,$3),nilNode(NIL));IDnew($2->info,$3,0);}
    | CONST tipo '*' ID {IDpush();IDnew(10+$2->info,$4,0);}init{IDpop();} ';'  {$$=seqNode(CDECL,3,$2,strNode(ID,$4),$6);IDnew(15+$2->info+$6->info,$4,(long)$6->user);print_list($6->user);}
    | CONST tipo '*' ID ';'             {yyerror("Non-public constants must be initialized\n");}
    | CONST tipo ID {IDpush();IDnew($2->info,$3,0);}init{IDpop();} ';' {$$=seqNode(CDECL,3,$2,strNode(ID,$3),$5);IDnew(5+$2->info+$5->info,$3,(long)$5->user);print_list($5->user);}
    | CONST tipo ID ';'                 {yyerror("Non-public constants must be initialized\n");}
    | tipo '*' ID {IDpush();IDnew(10+$1->info,$3,0);} init {IDpop();} ';' {$$=seqNode(DECL,3,$1,strNode(ID,$3),$5);IDnew(10+$1->info+$5->info,$3,(long)$5->user);print_list($5->user);}
    | tipo '*' ID ';'                   {$$=seqNode(DECL,3,$1,strNode(ID,$3),nilNode(NIL));IDnew(10+$1->info,$3,0);}
    | tipo ID {IDpush();IDnew($1->info,$2,0);}init{IDpop();} ';' {$$=seqNode(DECL,3,$1,strNode(ID,$2),$4);IDnew($1->info+$4->info,$2,(long)$4->user);print_list($4->user);}
    | tipo ID ';'                       {$$=seqNode(DECL,3,$1,strNode(ID,$2),nilNode(NIL));IDnew($1->info,$2,0);}
    ;

tipo: INTEGER {$$=nilNode(INTEGER);$$->info=1;}
    | STRING  {$$=nilNode(STRING);$$->info=2;}
    | NUMBER  {$$=nilNode(NUMBER);$$->info=3;}
    | VOID    {$$=nilNode(VOID);$$->info=4;}
    ;

init: ATR INT              {$$=uniNode(INITATR,intNode(INT,$2));$$->info=0;$$->user=0;}     
    | ATR CONST STR        {$$=uniNode(INITATR,strNode(STR,$3));$$->info=0;$$->user=0;} /*TODO acrescentar algo ao no que permita destinguir que e uma const*/
    | ATR STR              {$$=uniNode(INITATR,strNode(STR,$2));$$->info=0;$$->user=0;}
    | ATR REAL             {$$=uniNode(INITATR,realNode(REAL,$2));$$->info=0;$$->user=0;}
    | ATR ID               {$$=uniNode(INITATR,strNode(ID,$2));$$->info=0;$$->user=0;} /*TODO caso seja um ponteiro e ambos os lados tem a mesma base*/
    | '(' eparams ')' body {$$=binNode(INITELIPSIS,$2,$4);$$->info=20;$$->user=$2->user;}
    | '(' eparams ')'      {$$=binNode(INITELIPSIS,$2,nilNode(NIL));$$->info=20;$$->user=$2->user;}
    | '(' ')' body         {$$=binNode(INITELIPSIS,nilNode(NIL),$3);$$->info=20;$$->user=0;}
    | '(' ')'              {$$=binNode(INITELIPSIS,nilNode(NIL),nilNode(NIL));$$->info=20;$$->user=0;}
    ;

eparams: eparams ',' param {$$=binNode(EPARAMS,$1,$3);$1->user=add($1->user,$3->info);$$->user=$1->user;}
       | param             {$$=uniNode(PARAM,$1);$$->user=add($$->user,$1->info);}
       ;

param: tipo '*' ID {$$=binNode(PARAM,$1,strNode(ID,$3));$$->info=10+$1->info;IDnew(10+$1->info,$3,0);}
     | tipo ID     {$$=binNode(PARAM,$1,strNode(ID,$2));$$->info=$1->info;IDnew($1->info,$2,0);}
     ;

body: '{' bparams instrs '}' {$$=binNode(BODY,$2,$3);}
    | '{' instrs '}'         {$$=binNode(BODY,nilNode(NIL),$2);}
    | '{' bparams '}'        {$$=binNode(BODY,$2,nilNode(NIL));}
    | '{' '}'                {$$=binNode(BODY,nilNode(NIL),nilNode(NIL));}
    ; 

bparams: bparams  param ';' {$$=binNode(BPARAMS,$1,$2);}
       | param ';'          {$$=uniNode(PARAM,$1);}
       ;

instrs: instrs instr {$$=binNode(INSTRS,$1,$2);}
      | instr        {$$=uniNode(INSTR,$1);}
      ;

instr: IF expr THEN instr                              {$$=seqNode(IF,3,$2,$4,nilNode(NIL));}
     | IF expr THEN instr ELSE instr                   {$$=seqNode(IF,3,$2,$4,$6);}
     | DO {inLoop++;} instr WHILE expr ';'                         {$$=binNode(DO,$2,$5);inLoop--;}
     | FOR lval IN expr UPTO expr STEP expr DO {inLoop++;}instr    {$$=seqNode(FORUP,5,$2,$4,$6,$8,$11);inLoop--;}
     | FOR lval IN expr UPTO expr DO {inLoop++;} instr             {$$=seqNode(FORUP,5,$2,$4,$6,nilNode(NIL),$9);inLoop--;}
     | FOR lval IN expr DOWNTO expr STEP expr DO {inLoop++;} instr {$$=seqNode(FORDW,5,$2,$4,$6,$8,$11);inLoop--;}
     | FOR lval IN expr DOWNTO expr DO {inLoop++;} instr           {$$=seqNode(FORDW,5,$2,$4,$6,nilNode(NIL),$9);inLoop--;}
     | expr';'           {$$=uniNode(EXPR,$1);}
     | body              {$$=uniNode(BODY,$1);}
     | BREAK INT ';'     {if(inLoop)$$=uniNode(BREAK,intNode(INT,$2));else yyerror(errorMsg2);}
     | BREAK ';'         {if(inLoop)$$=uniNode(BREAK,nilNode(NIL));else yyerror(errorMsg2);}
     | CONTINUE INT ';'  {if(inLoop)$$=uniNode(CONTINUE,intNode(INT,$2));else yyerror(errorMsg3);}
     | CONTINUE ';'      {if(inLoop)$$=uniNode(CONTINUE,nilNode(NIL));else yyerror(errorMsg3);}
     | lval '#' expr ';' {$$=binNode('#',$1,$3);}
     ;

expr: lval          {$$=uniNode(LVAL,$1);$$->info=$1->info;}
    | lit           {$$=uniNode(LIT,$1);$$->info=$1->info;}
    | lval ATR expr {$$=binNode(ATR,$1,$3);    t=verifyTypes(ATR,$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '|' expr {$$=binNode('|',$1,$3);    t=verifyTypes('|',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '&' expr {$$=binNode('&',$1,$3);    t=verifyTypes('&',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | '~' expr      {$$=uniNode('~',$2);       t=verifyTypes('~',$2->info,1);        if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '=' expr {$$=binNode('=',$1,$3);    t=verifyTypes('=',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr NE expr  {$$=binNode(NE,$1,$3);     t=verifyTypes(NE,$1->info,$3->info);  if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr GE expr  {$$=binNode(GE,$1,$3);     t=verifyTypes(GE,$1->info,$3->info);  if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr LE expr  {$$=binNode(LE,$1,$3);     t=verifyTypes(LE,$1->info,$3->info);  if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '<' expr {$$=binNode('<',$1,$3);    t=verifyTypes('<',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '>' expr {$$=binNode('>',$1,$3);    t=verifyTypes('>',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '-' expr {$$=binNode('-',$1,$3);    t=verifyTypes('-',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '+' expr {$$=binNode('+',$1,$3);    t=verifyTypes('+',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '%' expr {$$=binNode('%',$1,$3);    t=verifyTypes('%',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '/' expr {$$=binNode('/',$1,$3);    t=verifyTypes('/',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '*' expr {$$=binNode('*',$1,$3);    t=verifyTypes('*',$1->info,$3->info); if(t)$$->info=t;else yyerror(errorMsg1);}
    | lval DECR     {$$=uniNode(POSDECR,$1);   t=verifyTypes(POSDECR,$1->info,1);    if(t)$$->info=t;else yyerror(errorMsg1);}  
    | lval INCR     {$$=uniNode(POSINCR,$1);   t=verifyTypes(POSINCR,$1->info,1);    if(t)$$->info=t;else yyerror(errorMsg1);}  
    | DECR lval     {$$=uniNode(PREDECR,$2);   t=verifyTypes(PREDECR,$2->info,1);    if(t)$$->info=t;else yyerror(errorMsg1);}  
    | INCR lval     {$$=uniNode(PREINCR,$2);   t=verifyTypes(PREINCR,$2->info,1);    if(t)$$->info=t;else yyerror(errorMsg1);}  
    | "-" expr %prec SIM  {$$=uniNode(SIM,$2); t=verifyTypes(SIM,$2->info,1);        if(t)$$->info=t;else yyerror(errorMsg1);}
    | expr '!'            {$$=uniNode('!',$1); t=verifyTypes('!',$1->info,1);        if(t)$$->info=t;else yyerror(errorMsg1);}
    | '&' lval %prec ADDR {$$=uniNode(ADDR,$2);t=verifyTypes(ADDR,$2->info,1);       if(t)$$->info=t;else yyerror(errorMsg1);}     
    | '*' lval %prec DREF {$$=uniNode(DREF,$2);t=verifyTypes(DREF,$2->info,1);       if(t)$$->info=t;else yyerror(errorMsg1);} 
    | '('expr')'          {$$=uniNode(PAREXPR,$2);$$->info=$2->info;}
    | ID'('exprs')'       {$$=binNode(INVOC,strNode(ID,$1),$3);IDfind($1,&args);printf("end=%p\n",&args);if(!compareLists((NODE*)args,$3->user))$$->info = IDfind($1,0);else yyerror(errorMsg4);} 
    | ID'(' ')'           {$$=binNode(INVOC,strNode(ID,$1),nilNode(NIL));$$->info = IDfind($1,0);} /*TODO verificar ordem e tipo de argumentos*/
    ;

lval: ID           {$$=strNode(ID,$1); $$->info = IDfind($1,0);/* printf("%d\n",$$->info); */}
    | ID'['expr']' {$$=binNode(INDEX,strNode(ID,$1),$3); int i=verifyTypes(INDEX,IDfind($1,0),$3->info); if(i)$$->info=i;else yyerror("Invalid type of operands.");}
    ;

exprs: exprs ',' expr {$$=binNode(EXPRS,$1,$3);$1->user=add($1->user,$3->info);$$->user=$1->user;}
    | expr            {$$=uniNode(EXPR,$1);$$->user=add($$->user,$1->info);}
    ;

lit: STR  {$$=strNode(STR,$1); $$->info=2;}
   | INT  {$$=intNode(INT,$1);$$->info=1;}
   | REAL {$$=realNode(REAL,$1);$$->info=3;}
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

int verifyTypes(int operation, int o1, int o2) {
    printf("%s: o1=%d, o2=%d\n",yynames[operation], o1,o2);
    if(o1>20)
        o1 = o1-20;
    if (o2>20)
        o2 = o2-20;
    if (operation== ADDR) {
        if (o1<10)
            return o1 +10;
    }
    if (operation == ATR) {
        /*TODO impedir funcoes e constantes*/
        /*TODO verificar tipos*/
        if (o1%10<5) /*NON CONSTANTS*/
            return o1;
    }
    if (operation == INDEX || operation == DREF) {
        if (o2 == 1 || o2 == 6) {
            if ((o1 >10 && o1 <20)||o1==2||o1==7) {
                if (o1==2 || o1==7)
                    return 1;
                if (o1 == 12 || o2 == 17)
                    return o1 - 11;
                else
                    return o1 -10;
            }
        }
    }
    if (operation == SIM) {
        if (o1 ==1 || o1 == 3 || o1 == 6 || o1 == 8) /*INTEGERS AND REALS*/
            return o1;
    }
    if (operation == '!') {
        if (o1 ==1 || o1 == 6 ) /*INTEGERs*/
            return 1;
    }
    if (operation == PREDECR ||operation == POSDECR || operation == PREINCR ||operation == POSINCR) {
        if (o1 == 1) /*INTEGERS*/
            return 1;
    }
    if (operation == '*' ||operation == '/' || operation == '%' ||operation == '+' ||operation == '-') {
        if ((o1 == 1 || o1 == 6 || o1 == 3 || o1 == 8) && (o2 == 1 || o2 == 6 || o2 == 3 || o2 == 8)) {
            if (o1==3||o1==8||o2==3||o2==8) /*one operand is real: return real*/
                return 3;
            else /*all operands are int so return int*/
                return 1;
        }
    }
    if (operation == LE ||operation == GE || operation == NE ||operation == '>' ||operation == '<' || operation == '=') {
        if ((o1==2||o1==7||o1==1||o1==6) && (o2==2||o2==7||o2==1||o2==6))
            return 1;
        if ((o1 == 1 || o1 == 6 || o1 == 3 || o1 == 8) && (o2 == 1 || o2 == 6 || o2 == 3 || o2 == 8)) {
            return 1;
        }
    }
    if (operation == '~' ||operation == '|' || operation == '&') {
        if ((o1 == 1 || o1 == 6) && ((o2 == 1) || o2 == 6))/*INTEGERS*/
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

 if (yyparse() != 0 || errors > 0) {
    fprintf(stderr, "%d errors\n", errors);
    return 1;
  }
  printNode(rootNode,stdout,yynames);
  return 0;
}