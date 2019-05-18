/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"
/* $Id: diy.y,v 1.0 2019/02/06 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();
void yyerror(char *s);
void declare(int pub, int cnst, Node *type, char *name, Node *value);
void function(int pub, Node *type, char *name, Node *body);
extern int yyselect(Node *);
void enter(int pub, int typ, char *name);
int checkargs(char *name, Node *args);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
static char *fpar;
#line 24 "diy.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define REAL 258
#define ID 259
#define STR 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define FOR 265
#define IN 266
#define UPTO 267
#define DOWNTO 268
#define STEP 269
#define BREAK 270
#define CONTINUE 271
#define VOID 272
#define INTEGER 273
#define STRING 274
#define NUMBER 275
#define CONST 276
#define PUBLIC 277
#define INCR 278
#define DECR 279
#define IFX 280
#define ELSE 281
#define ATR 282
#define NE 283
#define GE 284
#define LE 285
#define UMINUS 286
#define NOT 287
#define REF 288
#define LOCAL 289
#define POSINC 290
#define POSDEC 291
#define PTR 292
#define CALL 293
#define START 294
#define PARAM 295
#define NIL 296
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,   20,    0,   21,    0,
   19,   19,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    3,    3,    4,    4,    5,
    5,   22,    6,    7,    7,    8,   10,   10,    9,   23,
    9,   24,    9,   25,    9,    9,    9,    9,    9,    9,
    9,   14,   14,   15,   15,   11,   11,   18,   18,   13,
   13,   12,   12,   16,   16,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,
};
static const YYINT yylen[] = {                            2,
    0,    3,    5,    6,    5,    6,    0,    6,    0,    6,
    0,    1,    1,    1,    1,    2,    2,    2,    3,    3,
    4,    3,    4,    3,    4,    4,    3,    1,    2,    1,
    3,    0,    6,    0,    3,    2,    1,    1,    1,    0,
    6,    0,   10,    0,   10,    4,    6,    2,    1,    4,
    2,    0,    1,    3,    3,    0,    2,    0,    1,    1,
    2,    1,    3,    1,    4,    1,    2,    3,    1,    1,
    1,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    4,    3,
};
static const YYINT yydefred[] = {                         1,
    0,    0,   12,    0,    2,    0,    0,    0,    0,    0,
    0,    9,   16,   17,   18,    0,    0,    0,    0,    0,
    3,    5,    0,    0,   10,    4,    6,    0,    0,    0,
    0,    0,    0,    8,    0,    0,    0,   30,   20,   24,
   19,   22,    0,    0,    0,   28,   32,   27,    0,   36,
    0,    0,   23,   21,   25,   34,   29,   26,   31,    0,
    0,   69,   71,    0,   70,   40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   39,   49,    0,   60,    0,
    0,    0,   51,    0,    0,    0,    0,    0,    0,    0,
   76,   77,   74,   73,   72,   67,    0,   35,    0,    0,
   61,    0,   53,   78,   79,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   75,   48,    0,   95,    0,    0,   37,    0,   38,    0,
    0,   93,   59,    0,    0,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,   94,    0,    0,    0,    0,   54,   55,   50,
    0,    0,    0,    0,    0,   41,   47,    0,    0,    0,
    0,    0,    0,   42,   44,    0,    0,   43,   45,
};
static const YYINT yydgoto[] = {                          1,
   36,   22,   25,   48,   37,   77,   60,   38,  127,  128,
  171,  125,   80,  102,  129,   87,   82,  134,    4,   23,
   18,   56,   86,  176,  177,
};
static const YYINT yysindex[] = {                         0,
 -234,  -36,    0, -190,    0, -226,   -5,   12,   31, -210,
 -180,    0,    0,    0,    0, -162,  -56,   49,  -52,  -44,
    0,    0,   49,  -35,    0,    0,    0,   39,   40,   45,
   50, -149, -170,    0,  -42, -145,  -23,    0,    0,    0,
    0,    0,   59,   61,   69,    0,    0,    0,   71,    0,
  -42, -210,    0,    0,    0,    0,    0,    0,    0,  761,
   76,    0,    0,  -24,    0,    0,  828, -137, -137, -137,
 -137,  828,  828, -137,  828,    0,    0,   81,    0,  840,
  -22,   94,    0,  828,  713,  840, -233,  105,   38, -132,
    0,    0,    0,    0,    0,    0,  131,    0, -113, -113,
    0,   20,    0,    0,    0,  828,  828,  828,  828,  828,
  828,  828,  828,  828,  828,  828,  828,  828,  828,  828,
    0,    0,  161,    0,   11,  349,    0, -116,    0,  840,
  828,    0,    0,   90,   92,    0,  349,  246,  380,  387,
  418,  418,   70,   70,   70,   70,  138,  138,  130,  130,
  130,    0,    0,  828,  828, -111,   63,    0,    0,    0,
  349,  277,  840,  828,  828,    0,    0,  312,  312,  828,
  -84,  -82,  349,    0,    0,  840,  840,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
 -114,    0,    0,    0,    0,    0,  -78,  -77,  -76,    0,
    0,    0,    0,    0,    0,    0,  144,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   64,
  338,    0,    0,    0,    0,    0,   33,    0,   -3,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  127,  127,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  633,    0,  203,    9,
  608,  676,  415,  729,  764,  799,  511,  549,  444,  455,
  481,    0,    0,    0,    0,  651,    0,    0,    0,    0,
   75,    0,    0,    0,    0,    0,    0,  -73,  -73,    0,
    0,    0,  -71,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   15,  176,  173,  146,    0,  -15,    0,  -28,  -29, -115,
   32,    0,    0,    0,  120,  776, 1041,  102,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1211
static const YYINT yytable[] = {                         64,
   33,   64,   21,   64,   64,   35,   26,   64,   64,   64,
   64,   64,  107,   64,  156,   85,   46,   51,   11,   49,
   52,    2,    5,   59,   16,   64,   64,   64,   64,   64,
   79,   78,   12,   64,   64,   49,   13,   64,   64,   64,
   64,   64,    3,   64,  104,  105,   91,  167,  106,   91,
  101,  153,   91,   14,  154,   64,   64,   64,   64,   64,
  178,  179,    7,    8,    9,   66,   84,   91,   62,   66,
   66,   62,   15,   66,   66,   66,   66,   66,   17,   66,
   47,    6,    7,    8,    9,   10,   44,   45,   24,   64,
   64,   66,   66,   66,   66,  121,   19,   39,   40,  120,
  109,   91,  121,   41,  118,  116,  120,  117,   42,  119,
   43,  118,  116,   50,  117,   63,  119,   53,   63,   54,
   64,   89,  115,  110,  114,   66,  121,   55,   84,   57,
  120,  109,   91,  131,   83,  118,  116,  121,  117,   98,
  119,  120,  109,  133,  136,  155,  118,  116,  158,  117,
  159,  119,  122,  115,  110,  114,   66,   11,   11,   11,
   11,   11,  121,  121,  115,  110,  114,  120,  109,  163,
  121,  132,  118,  116,  120,  117,  174,  119,  175,  118,
   13,   14,   15,    7,  119,   58,  108,   56,   52,   57,
  115,  110,  114,  121,   27,   34,   58,  120,  109,  103,
  172,  135,  118,  116,    0,  117,    0,  119,    0,    0,
    0,    0,   28,   29,   30,   31,    0,  108,    0,    0,
  115,  110,  114,    0,    0,   20,    0,   64,  108,   20,
   64,   32,    0,   64,   64,   64,    0,    7,    8,    9,
    0,    0,    0,   92,   64,   64,   92,    0,   64,   64,
   64,   64,    0,  152,  108,  104,  105,   64,    0,  106,
   64,   92,   64,   64,   64,   64,    0,    0,    0,   91,
    0,    0,   91,    0,    0,   91,   91,   91,  121,   64,
   64,   64,  120,  109,  108,    0,    0,  118,  116,    0,
  117,    0,  119,   66,    0,   92,   66,    0,    0,   66,
   66,   66,    0,    0,  160,  115,  110,  114,    0,  121,
    0,    0,    0,  120,  109,   66,   66,   66,  118,  116,
    0,  117,    0,  119,    0,    0,   92,    0,    0,  164,
  165,    0,    0,    0,    0,  166,  115,  110,  114,    0,
    0,    0,    0,    0,  121,  111,  112,  113,  120,  109,
    0,    0,    0,  118,  116,    0,  117,    0,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  130,  108,
   66,  115,  110,  114,   66,   66,  111,  112,  113,   66,
   66,  121,   66,    0,   66,  120,  109,  111,  112,  113,
  118,  116,    0,  117,    0,  119,   66,   66,   66,   66,
  108,    0,    0,    0,    0,    0,    0,    0,  115,  110,
  114,    0,  121,  111,  112,  113,  120,  109,    0,  121,
    0,  118,  116,  120,  117,    0,  119,    0,  118,  116,
    0,  117,    0,  119,    0,  108,    0,    0,    0,  115,
  110,  114,    0,  111,  112,  113,  115,  110,  114,    0,
  121,    0,   87,    0,  120,   87,    0,    0,   87,  118,
  116,   66,  117,   92,  119,    0,   92,    0,    0,   92,
   92,   92,  108,   87,   87,   87,   87,  115,    0,  114,
   82,   82,    0,    0,   82,   82,   82,   82,   82,    0,
   82,   83,   83,    0,    0,   83,   83,   83,   83,   83,
    0,   83,   82,   82,   82,   82,    0,   87,    0,    0,
    0,    0,    0,   83,   83,   83,   83,   84,   84,    0,
    0,   84,   84,   84,   84,   84,    0,   84,  111,  112,
  113,    0,    0,    0,    0,    0,   82,    0,   87,   84,
   84,   84,   84,    0,    0,    0,    0,   83,   80,    0,
    0,   80,    0,   80,   80,   80,    0,    0,    0,  111,
  112,  113,    0,    0,    0,    0,    0,   82,    0,   80,
   80,   80,   80,   84,    0,    0,    0,    0,   83,    0,
  170,    0,    0,    0,    0,    0,   81,    0,    0,   81,
    0,   81,   81,   81,  111,  112,  113,    0,    0,    0,
    0,    0,    0,   80,   84,    0,    0,   81,   81,   81,
   81,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   66,   66,   66,    0,    0,    0,    0,    0,    0,    0,
    0,  111,  112,  113,   80,    0,    0,    0,    0,    0,
    0,   81,    0,    0,    0,   90,    0,    0,   90,    0,
    0,   90,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  111,  112,  113,    0,   90,    0,   90,  111,
  112,  113,   81,   68,    0,   87,   68,    0,   87,    0,
    0,   87,   87,   87,    0,    0,    0,    0,   46,    0,
   46,   68,   46,    0,    0,   46,    0,   87,   87,   87,
   90,  112,  113,    0,   82,    0,    0,   82,    0,   46,
   82,   82,   82,   89,    0,   83,   89,    0,   83,   89,
    0,   83,   83,   83,    0,   68,   82,   82,   82,    0,
    0,   90,    0,    0,   89,    0,   89,   83,   83,   83,
    0,   84,    0,    0,   84,    0,    0,   84,   84,   84,
   71,    0,   75,  124,   74,    0,    0,   73,    0,    0,
    0,    0,    0,   84,   84,   84,   88,    0,   89,   88,
    0,   80,   88,   46,   80,   46,   46,   80,   80,   80,
    0,    0,    0,    0,    0,    0,    0,   88,   88,   88,
   88,    0,    0,   80,   80,   80,    0,    0,   71,   89,
   75,   86,   74,    0,   86,   73,    0,   86,    0,   81,
    0,    0,   81,    0,    0,   81,   81,   81,    0,   76,
    0,   88,   86,   86,   86,   86,    0,    0,    0,    0,
    0,   81,   81,   81,    0,   81,   85,    0,   72,   85,
    0,    0,   85,   90,   91,   92,   93,    0,    0,   96,
    0,    0,   88,    0,    0,   81,   86,   85,   85,   85,
   85,   81,    0,    0,    0,   71,    0,   75,   90,   74,
    0,   90,   73,    0,   90,   90,   90,   71,    0,   75,
    0,   74,    0,   47,   73,    0,   72,   86,    0,    0,
   90,   85,    0,   68,    0,    0,   68,    0,   76,   68,
   68,   68,    0,    0,    0,   81,   46,   46,   46,   46,
   46,   46,   46,   46,    0,   46,    0,    0,    0,    0,
   46,   46,   85,    0,    0,    0,    0,    0,   46,   46,
    0,    0,    0,    0,    0,    0,   89,    0,   81,   89,
    0,    0,   89,   89,   89,    0,    0,    0,    0,    0,
    0,   81,   81,   72,    0,    0,    0,    0,   89,    0,
    0,    0,   47,    0,    0,   72,    0,    0,    0,   62,
   63,   64,   65,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   88,
   69,   70,   88,    0,    0,   88,   88,   88,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   88,   88,   88,    0,    0,   61,   62,   63,   64,
   65,   66,    0,   67,   86,   68,    0,   86,    0,    0,
   86,   86,   86,    7,    8,    9,    0,    0,   69,   70,
    0,    0,    0,    0,    0,    0,   86,   86,   86,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   85,
    0,    0,   85,    0,    0,   85,   85,   85,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   85,   85,   85,   62,   63,   64,   65,    0,    0,
    0,    0,    0,    0,    0,   61,   62,   63,   64,   65,
   66,    0,   67,    0,   68,   69,   70,   88,    0,   99,
  100,    0,   94,   95,    0,   97,    0,   69,   70,    0,
    0,    0,    0,    0,  123,  126,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  137,  138,  139,  140,
  141,  142,  143,  144,  145,  146,  147,  148,  149,  150,
  151,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  157,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  161,  162,    0,    0,    0,    0,
    0,    0,    0,    0,  168,  169,    0,    0,    0,    0,
  173,
};
static const YYINT yycheck[] = {                         33,
   45,   35,   59,   37,   38,   41,   59,   41,   42,   43,
   44,   45,   35,   47,  130,   40,   59,   41,    4,   35,
   44,  256,   59,   52,   10,   59,   60,   61,   62,   33,
   60,   60,  259,   37,   38,   51,   42,   41,   42,   43,
   44,   45,  277,   47,  278,  279,   38,  163,  282,   41,
   80,   41,   44,   42,   44,   59,   60,   61,   62,   93,
  176,  177,  273,  274,  275,   33,   91,   59,   41,   37,
   38,   44,   42,   41,   42,   43,   44,   45,  259,   47,
  123,  272,  273,  274,  275,  276,  257,  258,   40,   93,
  124,   59,   60,   61,   62,   33,  259,   59,   59,   37,
   38,   93,   33,   59,   42,   43,   37,   45,   59,   47,
  260,   42,   43,  259,   45,   41,   47,   59,   44,   59,
  124,  259,   60,   61,   62,   93,   33,   59,   91,   59,
   37,   38,  124,  266,   59,   42,   43,   33,   45,   59,
   47,   37,   38,  257,  125,  262,   42,   43,   59,   45,
   59,   47,   59,   60,   61,   62,  124,  272,  273,  274,
  275,  276,   33,   33,   60,   61,   62,   37,   38,  281,
   33,   41,   42,   43,   37,   45,  261,   47,  261,   42,
  259,  259,  259,   40,   47,   59,  124,  261,  125,  261,
   60,   61,   62,   33,   19,   23,   51,   37,   38,   80,
  169,  100,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,   -1,  124,   -1,   -1,
   60,   61,   62,   -1,   -1,  282,   -1,  261,  124,  282,
  264,  276,   -1,  267,  268,  269,   -1,  273,  274,  275,
   -1,   -1,   -1,   41,  278,  279,   44,   -1,  282,  283,
  284,  285,   -1,   93,  124,  278,  279,  261,   -1,  282,
  264,   59,  266,  267,  268,  269,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   33,  283,
  284,  285,   37,   38,  124,   -1,   -1,   42,   43,   -1,
   45,   -1,   47,  261,   -1,   93,  264,   -1,   -1,  267,
  268,  269,   -1,   -1,   59,   60,   61,   62,   -1,   33,
   -1,   -1,   -1,   37,   38,  283,  284,  285,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,  124,   -1,   -1,  267,
  268,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   33,  283,  284,  285,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  264,  124,
   33,   60,   61,   62,   37,   38,  283,  284,  285,   42,
   43,   33,   45,   -1,   47,   37,   38,  283,  284,  285,
   42,   43,   -1,   45,   -1,   47,   59,   60,   61,   62,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,   -1,   33,  283,  284,  285,   37,   38,   -1,   33,
   -1,   42,   43,   37,   45,   -1,   47,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   60,
   61,   62,   -1,  283,  284,  285,   60,   61,   62,   -1,
   33,   -1,   38,   -1,   37,   41,   -1,   -1,   44,   42,
   43,  124,   45,  261,   47,   -1,  264,   -1,   -1,  267,
  268,  269,  124,   59,   60,   61,   62,   60,   -1,   62,
   37,   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,
   47,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
   -1,   47,   59,   60,   61,   62,   -1,   93,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,  283,  284,
  285,   -1,   -1,   -1,   -1,   -1,   93,   -1,  124,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   93,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,  124,   -1,   59,
   60,   61,   62,   93,   -1,   -1,   -1,   -1,  124,   -1,
  269,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   43,   44,   45,  283,  284,  285,   -1,   -1,   -1,
   -1,   -1,   -1,   93,  124,   -1,   -1,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  283,  284,  285,   -1,   59,   -1,   61,  283,
  284,  285,  124,   41,   -1,  261,   44,   -1,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   38,   -1,
   40,   59,   42,   -1,   -1,   45,   -1,  283,  284,  285,
   93,  284,  285,   -1,  261,   -1,   -1,  264,   -1,   59,
  267,  268,  269,   38,   -1,  261,   41,   -1,  264,   44,
   -1,  267,  268,  269,   -1,   93,  283,  284,  285,   -1,
   -1,  124,   -1,   -1,   59,   -1,   61,  283,  284,  285,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   38,   -1,   40,   41,   42,   -1,   -1,   45,   -1,   -1,
   -1,   -1,   -1,  283,  284,  285,   38,   -1,   93,   41,
   -1,  261,   44,  123,  264,  125,  126,  267,  268,  269,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,
   62,   -1,   -1,  283,  284,  285,   -1,   -1,   38,  124,
   40,   38,   42,   -1,   41,   45,   -1,   44,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   59,
   -1,   93,   59,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,   -1,   60,   38,   -1,  126,   41,
   -1,   -1,   44,   68,   69,   70,   71,   -1,   -1,   74,
   -1,   -1,  124,   -1,   -1,   80,   93,   59,   60,   61,
   62,   86,   -1,   -1,   -1,   38,   -1,   40,  261,   42,
   -1,  264,   45,   -1,  267,  268,  269,   38,   -1,   40,
   -1,   42,   -1,  123,   45,   -1,  126,  124,   -1,   -1,
  283,   93,   -1,  261,   -1,   -1,  264,   -1,   59,  267,
  268,  269,   -1,   -1,   -1,  130,  256,  257,  258,  259,
  260,  261,  262,  263,   -1,  265,   -1,   -1,   -1,   -1,
  270,  271,  124,   -1,   -1,   -1,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,  163,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,  176,  177,  126,   -1,   -1,   -1,   -1,  283,   -1,
   -1,   -1,  123,   -1,   -1,  126,   -1,   -1,   -1,  257,
  258,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
  278,  279,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,  256,  257,  258,  259,
  260,  261,   -1,  263,  261,  265,   -1,  264,   -1,   -1,
  267,  268,  269,  273,  274,  275,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,  284,  285,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,   -1,  263,   -1,  265,  278,  279,   67,   -1,  270,
  271,   -1,   72,   73,   -1,   75,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   84,   85,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,
  120,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  131,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  154,  155,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  164,  165,   -1,   -1,   -1,   -1,
  170,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 296
#define YYUNDFTOKEN 324
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","IFX","ELSE",
"ATR","NE","GE","LE","UMINUS","NOT","REF","LOCAL","POSINC","POSDEC","PTR",
"CALL","START","PARAM","NIL",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file :",
"file : file error ';'",
"file : file public tipo ID ';'",
"file : file public CONST tipo ID ';'",
"file : file public tipo ID init",
"file : file public CONST tipo ID init",
"$$1 :",
"file : file public tipo ID $$1 finit",
"$$2 :",
"file : file public VOID ID $$2 finit",
"public :",
"public : PUBLIC",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"tipo : INTEGER '*'",
"tipo : STRING '*'",
"tipo : NUMBER '*'",
"init : ATR ID ';'",
"init : ATR INT ';'",
"init : ATR '-' INT ';'",
"init : ATR STR ';'",
"init : ATR CONST STR ';'",
"init : ATR REAL ';'",
"init : ATR '-' REAL ';'",
"finit : '(' params ')' blocop",
"finit : '(' ')' blocop",
"blocop : ';'",
"blocop : bloco ';'",
"params : param",
"params : params ',' param",
"$$3 :",
"bloco : '{' $$3 decls list end '}'",
"decls :",
"decls : decls param ';'",
"param : tipo ID",
"stmt : base",
"stmt : brk",
"base : ';'",
"$$4 :",
"base : DO $$4 stmt WHILE expr ';'",
"$$5 :",
"base : FOR lv IN expr UPTO expr step DO $$5 stmt",
"$$6 :",
"base : FOR lv IN expr DOWNTO expr step DO $$6 stmt",
"base : IF expr THEN stmt",
"base : IF expr THEN stmt ELSE stmt",
"base : expr ';'",
"base : bloco",
"base : lv '#' expr ';'",
"base : error ';'",
"end :",
"end : brk",
"brk : BREAK intp ';'",
"brk : CONTINUE intp ';'",
"step :",
"step : STEP expr",
"intp :",
"intp : INT",
"list : base",
"list : list base",
"args : expr",
"args : args ',' expr",
"lv : ID",
"lv : ID '[' expr ']'",
"expr : lv",
"expr : '*' lv",
"expr : lv ATR expr",
"expr : INT",
"expr : STR",
"expr : REAL",
"expr : '-' expr",
"expr : '~' expr",
"expr : '&' lv",
"expr : expr '!'",
"expr : INCR lv",
"expr : DECR lv",
"expr : lv INCR",
"expr : lv DECR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr '=' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : ID '(' args ')'",
"expr : ID '(' ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 204 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");
    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires no arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = RIGHT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INT && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = LEFT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}

int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* real := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := real */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void function(int pub, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	}
	printNode(body,stdout,yynames);
	yyselect(body);
}
#line 742 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 58 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 4:
#line 59 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 5:
#line 60 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 6:
#line 61 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 7:
#line 62 "diy.y"
	{ enter(yystack.l_mark[-2].i, yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s); }
break;
case 8:
#line 62 "diy.y"
	{ function(yystack.l_mark[-4].i, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 9:
#line 63 "diy.y"
	{ enter(yystack.l_mark[-2].i, 4, yystack.l_mark[0].s); }
break;
case 10:
#line 63 "diy.y"
	{ function(yystack.l_mark[-4].i, intNode(VOID, 4), yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 11:
#line 66 "diy.y"
	{ yyval.i = 0; }
break;
case 12:
#line 67 "diy.y"
	{ yyval.i = 1; }
break;
case 13:
#line 70 "diy.y"
	{ yyval.n = intNode(INTEGER, 1); }
break;
case 14:
#line 71 "diy.y"
	{ yyval.n = intNode(STRING, 2); }
break;
case 15:
#line 72 "diy.y"
	{ yyval.n = intNode(NUMBER, 3); }
break;
case 16:
#line 73 "diy.y"
	{ yyval.n = intNode(INTEGER, 11); }
break;
case 17:
#line 74 "diy.y"
	{ yyval.n = intNode(STRING, 12); }
break;
case 18:
#line 75 "diy.y"
	{ yyval.n = intNode(NUMBER, 13); }
break;
case 19:
#line 78 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[-1].s); yyval.n->info = IDfind(yystack.l_mark[-1].s, 0) + 10; }
break;
case 20:
#line 79 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 21:
#line 80 "diy.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 22:
#line 81 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[-1].s); yyval.n->info = 2; }
break;
case 23:
#line 82 "diy.y"
	{ yyval.n = strNode(CONST, yystack.l_mark[-1].s); yyval.n->info = 2+5; }
break;
case 24:
#line 83 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 25:
#line 84 "diy.y"
	{ yyval.n = realNode(REAL, -yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 26:
#line 87 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 27:
#line 88 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, nilNode(NIL)); }
break;
case 28:
#line 91 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 29:
#line 92 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 31:
#line 96 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 32:
#line 99 "diy.y"
	{ IDpush(); }
break;
case 33:
#line 99 "diy.y"
	{ yyval.n = binNode('{', yystack.l_mark[-1].n ? binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n) : yystack.l_mark[-2].n, yystack.l_mark[-3].n); IDpop(); }
break;
case 34:
#line 102 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 35:
#line 103 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 36:
#line 106 "diy.y"
	{ yyval.n = binNode(PARAM, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s));
                                  IDnew(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, 0);
                                  if (IDlevel() == 1) fpar[++fpar[0]] = yystack.l_mark[-1].n->value.i;
                                }
break;
case 39:
#line 116 "diy.y"
	{ yyval.n = nilNode(VOID); }
break;
case 40:
#line 117 "diy.y"
	{ ncicl++; }
break;
case 41:
#line 117 "diy.y"
	{ yyval.n = binNode(WHILE, binNode(DO, nilNode(START), yystack.l_mark[-3].n), yystack.l_mark[-1].n); ncicl--; }
break;
case 42:
#line 118 "diy.y"
	{ ncicl++; }
break;
case 43:
#line 118 "diy.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(LE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('+', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 44:
#line 119 "diy.y"
	{ ncicl++; }
break;
case 45:
#line 119 "diy.y"
	{ yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(GE, uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('-', uniNode(PTR, yystack.l_mark[-8].n), yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 46:
#line 120 "diy.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 47:
#line 121 "diy.y"
	{ yyval.n = binNode(ELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); }
break;
case 48:
#line 122 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 49:
#line 123 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 50:
#line 124 "diy.y"
	{ yyval.n = binNode('#', yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 51:
#line 125 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 52:
#line 128 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 54:
#line 131 "diy.y"
	{ yyval.n = intNode(BREAK, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid break argument"); }
break;
case 55:
#line 132 "diy.y"
	{ yyval.n = intNode(CONTINUE, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid continue argument"); }
break;
case 56:
#line 135 "diy.y"
	{ yyval.n = intNode(INT, 1); }
break;
case 57:
#line 136 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 58:
#line 139 "diy.y"
	{ yyval.i = 1; }
break;
case 61:
#line 144 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 62:
#line 147 "diy.y"
	{ yyval.n = binNode(',', nilNode(NIL), yystack.l_mark[0].n); }
break;
case 63:
#line 148 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 64:
#line 151 "diy.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos);
                          if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s);
                          else yyval.n = intNode(LOCAL, pos);
			  yyval.n->info = typ;
			}
break;
case 65:
#line 156 "diy.y"
	{ Node *n;
                            long pos; int siz, typ = IDfind(yystack.l_mark[-3].s, &pos);
                            if (typ / 10 != 1 && typ % 5 != 2) yyerror("not a pointer");
                            if (pos == 0) n = strNode(ID, yystack.l_mark[-3].s);
                            else n = intNode(LOCAL, pos);
                            yyval.n = binNode('[', n, yystack.l_mark[-1].n);
			    if (typ >= 10) typ -= 10;
                            else if (typ % 5 == 2) typ = 1;
			    if (typ >= 5) typ -= 5;
			    yyval.n->info = typ;
			  }
break;
case 66:
#line 169 "diy.y"
	{ yyval.n = uniNode(PTR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 67:
#line 170 "diy.y"
	{ yyval.n = uniNode(PTR, uniNode(PTR, yystack.l_mark[0].n)); if (yystack.l_mark[0].n->info % 5 == 2) yyval.n->info = 1; else if (yystack.l_mark[0].n->info / 10 == 1) yyval.n->info = yystack.l_mark[0].n->info % 10; else yyerror("can dereference lvalue"); }
break;
case 68:
#line 171 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); if (yyval.n->info % 10 > 5) yyerror("constant value to assignment"); if (noassign(yystack.l_mark[-2].n, yystack.l_mark[0].n)) yyerror("illegal assignment"); yyval.n->info = yystack.l_mark[-2].n->info; }
break;
case 69:
#line 172 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 70:
#line 173 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 71:
#line 174 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info = 3; }
break;
case 72:
#line 175 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; nostring(yystack.l_mark[0].n, yystack.l_mark[0].n);}
break;
case 73:
#line 176 "diy.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 0); }
break;
case 74:
#line 177 "diy.y"
	{ yyval.n = uniNode(REF, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info + 10; }
break;
case 75:
#line 178 "diy.y"
	{ yyval.n = uniNode('!', yystack.l_mark[-1].n); yyval.n->info = 3; intonly(yystack.l_mark[-1].n, 0); }
break;
case 76:
#line 179 "diy.y"
	{ yyval.n = uniNode(INCR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 77:
#line 180 "diy.y"
	{ yyval.n = uniNode(DECR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 78:
#line 181 "diy.y"
	{ yyval.n = uniNode(POSINC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 79:
#line 182 "diy.y"
	{ yyval.n = uniNode(POSDEC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 80:
#line 183 "diy.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 184 "diy.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 185 "diy.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 186 "diy.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 187 "diy.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 85:
#line 188 "diy.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 86:
#line 189 "diy.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 87:
#line 190 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 88:
#line 191 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 89:
#line 192 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 90:
#line 193 "diy.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 91:
#line 194 "diy.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 92:
#line 195 "diy.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 93:
#line 196 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 94:
#line 197 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                            yyval.n->info = checkargs(yystack.l_mark[-3].s, yystack.l_mark[-1].n); }
break;
case 95:
#line 199 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(VOID));
                          yyval.n->info = checkargs(yystack.l_mark[-2].s, 0); }
break;
#line 1311 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
