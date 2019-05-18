/*
generated at Sat May 18 20:37:20 2019
by $Id: pburg.c,v 2.4 2014/02/12 17:04:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.4"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"
extern FILE *outfp;
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfinit_NT 1
#define yyblocop_NT 2
#define yyparams_NT 3
#define yybloco_NT 4
#define yylist_NT 5
#define yyend_NT 6
#define yydecls_NT 7
#define yybase_NT 8
#define yyexpr_NT 9
#define yyargs_NT 10
#define yybrk_NT 11
#define yyparam_NT 12
#define yytipo_NT 13

static YYCONST char *yyntname[] = {
	0,
	"finit",
	"blocop",
	"params",
	"bloco",
	"list",
	"end",
	"decls",
	"base",
	"expr",
	"args",
	"brk",
	"param",
	"tipo",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "FACTORIAL",
 "",
	/* 36 */ "RESERVA",
 "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "FINIT",
 "",
	/* 43 */ "MUL",
	/* 44 */ "SOMA",
	/* 45 */ "PARAMS",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "DECL",
	/* 61 */ "LT",
	/* 62 */ "EQ",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "",
	/* 92 */ "INDEX",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "",
	/* 124 */ "BLOCO",
	/* 125 */ "OR",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "LOCAL",
	/* 291 */ "POSINC",
	/* 292 */ "POSDEC",
	/* 293 */ "PTR",
	/* 294 */ "CALL",
	/* 295 */ "START",
	/* 296 */ "PARAM",
	/* 297 */ "NIL",
	""
};

struct yystate {
	short cost[14];
	struct {
		unsigned int yyfinit:2;
		unsigned int yyblocop:2;
		unsigned int yyparams:2;
		unsigned int yybloco:2;
		unsigned int yylist:2;
		unsigned int yyend:2;
		unsigned int yydecls:2;
		unsigned int yybase:2;
		unsigned int yyexpr:1;
		unsigned int yyargs:2;
		unsigned int yybrk:2;
		unsigned int yyparam:1;
		unsigned int yytipo:2;
	} rule;
};

static short yynts_0[] = { yyblocop_NT, yyparams_NT, 0 };
static short yynts_1[] = { yyblocop_NT, 0 };
static short yynts_2[] = { 0 };
static short yynts_3[] = { yybloco_NT, 0 };
static short yynts_4[] = { yylist_NT, yyend_NT, yydecls_NT, 0 };
static short yynts_5[] = { yylist_NT, yydecls_NT, 0 };
static short yynts_6[] = { yybase_NT, 0 };
static short yynts_7[] = { yylist_NT, yybase_NT, 0 };
static short yynts_8[] = { yyexpr_NT, 0 };
static short yynts_9[] = { yyargs_NT, 0 };
static short yynts_10[] = { yyargs_NT, yyexpr_NT, 0 };
static short yynts_11[] = { yybrk_NT, 0 };
static short yynts_12[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_13[] = { yyparam_NT, 0 };
static short yynts_14[] = { yyparams_NT, yyparam_NT, 0 };
static short yynts_15[] = { yytipo_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_2,	/* 9 */
	yynts_8,	/* 10 */
	yynts_3,	/* 11 */
	yynts_9,	/* 12 */
	yynts_8,	/* 13 */
	yynts_10,	/* 14 */
	yynts_2,	/* 15 */
	yynts_11,	/* 16 */
	yynts_2,	/* 17 */
	yynts_2,	/* 18 */
	yynts_2,	/* 19 */
	yynts_12,	/* 20 */
	yynts_13,	/* 21 */
	yynts_14,	/* 22 */
	yynts_15,	/* 23 */
	yynts_2,	/* 24 */
	yynts_2,	/* 25 */
	yynts_2,	/* 26 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"finit: FINIT(blocop,params)",
/* 2 */	"finit: FINIT(blocop,NIL)",
/* 3 */	"blocop: NIL",
/* 4 */	"blocop: bloco",
/* 5 */	"bloco: BLOCO(DECL(list,end),decls)",
/* 6 */	"bloco: BLOCO(list,decls)",
/* 7 */	"list: base",
/* 8 */	"list: DECL(list,base)",
/* 9 */	"base: VOID",
/* 10 */	"base: expr",
/* 11 */	"base: bloco",
/* 12 */	"expr: CALL(ID,args)",
/* 13 */	"args: PARAMS(NIL,expr)",
/* 14 */	"args: PARAMS(args,expr)",
/* 15 */	"end: NIL",
/* 16 */	"end: brk",
/* 17 */	"brk: BREAK",
/* 18 */	"brk: CONTINUE",
/* 19 */	"decls: NIL",
/* 20 */	"decls: DECL(decls,param)",
/* 21 */	"params: param",
/* 22 */	"params: PARAMS(params,param)",
/* 23 */	"param: PARAM(tipo,ID)",
/* 24 */	"tipo: STRING",
/* 25 */	"tipo: INTEGER",
/* 26 */	"tipo: NUMBER",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_finit[] = {
	0,
	1,
	2,
};

static short yydecode_blocop[] = {
	0,
	3,
	4,
};

static short yydecode_params[] = {
	0,
	21,
	22,
};

static short yydecode_bloco[] = {
	0,
	5,
	6,
};

static short yydecode_list[] = {
	0,
	7,
	8,
};

static short yydecode_end[] = {
	0,
	15,
	16,
};

static short yydecode_decls[] = {
	0,
	19,
	20,
};

static short yydecode_base[] = {
	0,
	9,
	10,
	11,
};

static short yydecode_expr[] = {
	0,
	12,
};

static short yydecode_args[] = {
	0,
	13,
	14,
};

static short yydecode_brk[] = {
	0,
	17,
	18,
};

static short yydecode_param[] = {
	0,
	23,
};

static short yydecode_tipo[] = {
	0,
	24,
	25,
	26,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 13)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfinit_NT:	return yydecode_finit[((struct yystate *)state)->rule.yyfinit];
	case yyblocop_NT:	return yydecode_blocop[((struct yystate *)state)->rule.yyblocop];
	case yyparams_NT:	return yydecode_params[((struct yystate *)state)->rule.yyparams];
	case yybloco_NT:	return yydecode_bloco[((struct yystate *)state)->rule.yybloco];
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yyend_NT:	return yydecode_end[((struct yystate *)state)->rule.yyend];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyargs_NT:	return yydecode_args[((struct yystate *)state)->rule.yyargs];
	case yybrk_NT:	return yydecode_brk[((struct yystate *)state)->rule.yybrk];
	case yyparam_NT:	return yydecode_param[((struct yystate *)state)->rule.yyparam];
	case yytipo_NT:	return yydecode_tipo[((struct yystate *)state)->rule.yytipo];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_bloco(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_brk(NODEPTR_TYPE, int);
static void yyclosure_param(NODEPTR_TYPE, int);

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 11, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 1);
	}
	yytrace(a, 4, c + 1, p->cost[yyblocop_NT]);
	if (c + 1 < p->cost[yyblocop_NT]) {
		p->cost[yyblocop_NT] = c + 1;
		p->rule.yyblocop = 2;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 7, c + 1, p->cost[yylist_NT]);
	if (c + 1 < p->cost[yylist_NT]) {
		p->cost[yylist_NT] = c + 1;
		p->rule.yylist = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 10, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 2;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_brk(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 16, c + 1, p->cost[yyend_NT]);
	if (c + 1 < p->cost[yyend_NT]) {
		p->cost[yyend_NT] = c + 1;
		p->rule.yyend = 2;
	}
}

static void yyclosure_param(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 21, c + 1, p->cost[yyparams_NT]);
	if (c + 1 < p->cost[yyparams_NT]) {
		p->cost[yyparams_NT] = c + 1;
		p->rule.yyparams = 1;
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* FACTORIAL */
		break;
	case 35: /* RESERVA */
		break;
	case 37: /* MOD */
		break;
	case 38: /* AND */
		break;
	case 40: /* FINIT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* finit: FINIT(blocop,params) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyblocop_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparams_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfinit_NT]);
		if (c + 0 < p->cost[yyfinit_NT]) {
			p->cost[yyfinit_NT] = c + 0;
			p->rule.yyfinit = 1;
		}
		if (	/* finit: FINIT(blocop,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyblocop_NT] + 1;
			yytrace(a, 2, c + 0, p->cost[yyfinit_NT]);
			if (c + 0 < p->cost[yyfinit_NT]) {
				p->cost[yyfinit_NT] = c + 0;
				p->rule.yyfinit = 2;
			}
		}
		break;
	case 42: /* MUL */
		break;
	case 43: /* SOMA */
		break;
	case 44: /* PARAMS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* args: PARAMS(NIL,expr) */
			OP_LABEL(LEFT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yyargs_NT]);
			if (c + 0 < p->cost[yyargs_NT]) {
				p->cost[yyargs_NT] = c + 0;
				p->rule.yyargs = 1;
			}
		}
		/* args: PARAMS(args,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyargs_NT]);
		if (c + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = c + 0;
			p->rule.yyargs = 2;
		}
		/* params: PARAMS(params,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyparams_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 1;
		yytrace(a, 22, c + 0, p->cost[yyparams_NT]);
		if (c + 0 < p->cost[yyparams_NT]) {
			p->cost[yyparams_NT] = c + 0;
			p->rule.yyparams = 2;
		}
		break;
	case 45: /* SUB */
		break;
	case 47: /* DIV */
		break;
	case 59: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* list: DECL(list,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 8, c + 0, p->cost[yylist_NT]);
		if (c + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = c + 0;
			p->rule.yylist = 2;
		}
		/* decls: DECL(decls,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 0;
		yytrace(a, 20, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		break;
	case 60: /* LT */
		break;
	case 61: /* EQ */
		break;
	case 62: /* GT */
		break;
	case 91: /* INDEX */
		break;
	case 123: /* BLOCO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* bloco: BLOCO(DECL(list,end),decls) */
			OP_LABEL(LEFT_CHILD(a)) == 59 /* DECL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyend_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 1;
			yytrace(a, 5, c + 0, p->cost[yybloco_NT]);
			if (c + 0 < p->cost[yybloco_NT]) {
				p->cost[yybloco_NT] = c + 0;
				p->rule.yybloco = 1;
				yyclosure_bloco(a, c + 0);
			}
		}
		/* bloco: BLOCO(list,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 1;
		yytrace(a, 6, c + 0, p->cost[yybloco_NT]);
		if (c + 0 < p->cost[yybloco_NT]) {
			p->cost[yybloco_NT] = c + 0;
			p->rule.yybloco = 2;
			yyclosure_bloco(a, c + 0);
		}
		break;
	case 124: /* OR */
		break;
	case 257: /* INT */
		break;
	case 258: /* REAL */
		break;
	case 259: /* ID */
		break;
	case 260: /* STR */
		break;
	case 261: /* DO */
		break;
	case 262: /* WHILE */
		break;
	case 263: /* IF */
		break;
	case 264: /* THEN */
		break;
	case 265: /* FOR */
		break;
	case 266: /* IN */
		break;
	case 267: /* UPTO */
		break;
	case 268: /* DOWNTO */
		break;
	case 269: /* STEP */
		break;
	case 270: /* BREAK */
		/* brk: BREAK */
		yytrace(a, 17, 1 + 0, p->cost[yybrk_NT]);
		if (1 + 0 < p->cost[yybrk_NT]) {
			p->cost[yybrk_NT] = 1 + 0;
			p->rule.yybrk = 1;
			yyclosure_brk(a, 1 + 0);
		}
		break;
	case 271: /* CONTINUE */
		/* brk: CONTINUE */
		yytrace(a, 18, 1 + 0, p->cost[yybrk_NT]);
		if (1 + 0 < p->cost[yybrk_NT]) {
			p->cost[yybrk_NT] = 1 + 0;
			p->rule.yybrk = 2;
			yyclosure_brk(a, 1 + 0);
		}
		break;
	case 272: /* VOID */
		/* base: VOID */
		yytrace(a, 9, 1 + 0, p->cost[yybase_NT]);
		if (1 + 0 < p->cost[yybase_NT]) {
			p->cost[yybase_NT] = 1 + 0;
			p->rule.yybase = 1;
			yyclosure_base(a, 1 + 0);
		}
		break;
	case 273: /* INTEGER */
		/* tipo: INTEGER */
		yytrace(a, 25, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 2;
		}
		break;
	case 274: /* STRING */
		/* tipo: STRING */
		yytrace(a, 24, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 1;
		}
		break;
	case 275: /* NUMBER */
		/* tipo: NUMBER */
		yytrace(a, 26, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 3;
		}
		break;
	case 276: /* CONST */
		break;
	case 277: /* PUBLIC */
		break;
	case 278: /* INCR */
		break;
	case 279: /* DECR */
		break;
	case 280: /* IFX */
		break;
	case 281: /* ELSE */
		break;
	case 282: /* ATR */
		break;
	case 283: /* NE */
		break;
	case 284: /* GE */
		break;
	case 285: /* LE */
		break;
	case 286: /* UMINUS */
		break;
	case 287: /* NOT */
		break;
	case 288: /* REF */
		break;
	case 289: /* LOCAL */
		break;
	case 290: /* POSINC */
		break;
	case 291: /* POSDEC */
		break;
	case 292: /* PTR */
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 12, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(tipo,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yytipo_NT] + 1;
			yytrace(a, 23, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 1;
				yyclosure_param(a, c + 0);
			}
		}
		break;
	case 296: /* NIL */
		/* blocop: NIL */
		yytrace(a, 3, 1 + 0, p->cost[yyblocop_NT]);
		if (1 + 0 < p->cost[yyblocop_NT]) {
			p->cost[yyblocop_NT] = 1 + 0;
			p->rule.yyblocop = 1;
		}
		/* end: NIL */
		yytrace(a, 15, 1 + 0, p->cost[yyend_NT]);
		if (1 + 0 < p->cost[yyend_NT]) {
			p->cost[yyend_NT] = 1 + 0;
			p->rule.yyend = 1;
		}
		/* decls: NIL */
		yytrace(a, 19, 1 + 0, p->cost[yydecls_NT]);
		if (1 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 1 + 0;
			p->rule.yydecls = 1;
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 22: /* params: PARAMS(params,param) */
	case 20: /* decls: DECL(decls,param) */
	case 14: /* args: PARAMS(args,expr) */
	case 8: /* list: DECL(list,base) */
	case 6: /* bloco: BLOCO(list,decls) */
	case 1: /* finit: FINIT(blocop,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 23: /* param: PARAM(tipo,ID) */
	case 2: /* finit: FINIT(blocop,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 26: /* tipo: NUMBER */
	case 25: /* tipo: INTEGER */
	case 24: /* tipo: STRING */
	case 19: /* decls: NIL */
	case 18: /* brk: CONTINUE */
	case 17: /* brk: BREAK */
	case 15: /* end: NIL */
	case 9: /* base: VOID */
	case 3: /* blocop: NIL */
		break;
	case 21: /* params: param */
	case 16: /* end: brk */
	case 11: /* base: bloco */
	case 10: /* base: expr */
	case 7: /* list: base */
	case 4: /* blocop: bloco */
		kids[0] = p;
		break;
	case 5: /* bloco: BLOCO(DECL(list,end),decls) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 13: /* args: PARAMS(NIL,expr) */
	case 12: /* expr: CALL(ID,args) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[3];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* finit: FINIT(blocop,params) */
#line 18 "diy.brg"
{}
		break;
	case 2: /* finit: FINIT(blocop,NIL) */
#line 19 "diy.brg"
{}
		break;
	case 3: /* blocop: NIL */
#line 21 "diy.brg"
{}
		break;
	case 4: /* blocop: bloco */
#line 22 "diy.brg"
{}
		break;
	case 5: /* bloco: BLOCO(DECL(list,end),decls) */
#line 24 "diy.brg"
{}
		break;
	case 6: /* bloco: BLOCO(list,decls) */
#line 25 "diy.brg"
{}
		break;
	case 7: /* list: base */
#line 27 "diy.brg"
{}
		break;
	case 8: /* list: DECL(list,base) */
#line 28 "diy.brg"
{}
		break;
	case 9: /* base: VOID */
#line 30 "diy.brg"
{}
		break;
	case 10: /* base: expr */
#line 31 "diy.brg"
{}
		break;
	case 11: /* base: bloco */
#line 32 "diy.brg"
{}
		break;
	case 12: /* expr: CALL(ID,args) */
#line 34 "diy.brg"
{fprintf(outfp,"pfCALL \n %s\n",LEFT_CHILD(p)->value.s);}
		break;
	case 13: /* args: PARAMS(NIL,expr) */
#line 36 "diy.brg"
{}
		break;
	case 14: /* args: PARAMS(args,expr) */
#line 37 "diy.brg"
{}
		break;
	case 15: /* end: NIL */
#line 39 "diy.brg"
{}
		break;
	case 16: /* end: brk */
#line 40 "diy.brg"
{}
		break;
	case 17: /* brk: BREAK */
#line 42 "diy.brg"
{}
		break;
	case 18: /* brk: CONTINUE */
#line 43 "diy.brg"
{}
		break;
	case 19: /* decls: NIL */
#line 45 "diy.brg"
{}
		break;
	case 20: /* decls: DECL(decls,param) */
#line 46 "diy.brg"

		break;
	case 21: /* params: param */
#line 48 "diy.brg"
{}
		break;
	case 22: /* params: PARAMS(params,param) */
#line 49 "diy.brg"
{}
		break;
	case 23: /* param: PARAM(tipo,ID) */
#line 51 "diy.brg"
{}
		break;
	case 24: /* tipo: STRING */
#line 53 "diy.brg"
{}
		break;
	case 25: /* tipo: INTEGER */
#line 54 "diy.brg"
{}
		break;
	case 26: /* tipo: NUMBER */
#line 55 "diy.brg"
{}
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfinit == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 60 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;