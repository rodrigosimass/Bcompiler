%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
extern int yylex();
void yyerror(char *s);
extern long lbl;
char *mklbl(long);
void variable(char*,Node*,Node*), function(char*,int,Node*), externs();

static char buf[80]; /* error messages */
static int gt, pos, dim(Node*);
static void *gtr, *root, *swr, gotos();
static Node *name(Node*), *swf(Node*), *swg(int pop);
%}

%union {
	int i;			/* integer value */
	char *s;	    /* symbol name or string literal */
	Node *n;	/* tree node */
};

%token VOID
%%
file	:
	;
%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
