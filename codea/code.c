typedef struct burm_state *STATEPTR_TYPE;

#define CODE
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "assembler.h"

#ifndef ALLOC
#define ALLOC(n) malloc(n)
#endif

#ifndef burm_assert
#define burm_assert(x,y) if (!(x)) { extern void abort(void); y; abort(); }
#endif

#define burm_stat_NT 1
#define burm_ret_NT 2
#define burm_expr_NT 3
#define burm_immediate_NT 4
#define burm_zero_NT 5
#define burm_zeroexpr_NT 6
#define burm_OP_Id_NT 7
int burm_max_nt = 7;

struct burm_state {
	int op;
	STATEPTR_TYPE left, right;
	short cost[8];
	struct {
		unsigned burm_stat:1;
		unsigned burm_ret:1;
		unsigned burm_expr:5;
		unsigned burm_immediate:4;
		unsigned burm_zero:3;
		unsigned burm_zeroexpr:4;
		unsigned burm_OP_Id:1;
	} rule;
};

static short burm_nts_0[] = { burm_ret_NT, 0 };
static short burm_nts_1[] = { burm_expr_NT, 0 };
static short burm_nts_2[] = { 0 };
static short burm_nts_3[] = { burm_immediate_NT, 0 };
static short burm_nts_4[] = { burm_expr_NT, burm_expr_NT, 0 };
static short burm_nts_5[] = { burm_immediate_NT, burm_expr_NT, 0 };
static short burm_nts_6[] = { burm_expr_NT, burm_immediate_NT, 0 };
static short burm_nts_7[] = { burm_zero_NT, 0 };
static short burm_nts_8[] = { burm_immediate_NT, burm_immediate_NT, 0 };
static short burm_nts_9[] = { burm_zeroexpr_NT, burm_zero_NT, 0 };
static short burm_nts_10[] = { burm_zero_NT, burm_zeroexpr_NT, 0 };
static short burm_nts_11[] = { burm_zeroexpr_NT, 0 };
static short burm_nts_12[] = { burm_zeroexpr_NT, burm_zeroexpr_NT, 0 };
static short burm_nts_13[] = { burm_OP_Id_NT, 0 };

short *burm_nts[] = {
	0,	/* 0 */
	burm_nts_0,	/* 1 */
	burm_nts_1,	/* 2 */
	burm_nts_2,	/* 3 */
	burm_nts_1,	/* 4 */
	burm_nts_3,	/* 5 */
	burm_nts_1,	/* 6 */
	burm_nts_4,	/* 7 */
	burm_nts_5,	/* 8 */
	burm_nts_6,	/* 9 */
	burm_nts_4,	/* 10 */
	burm_nts_5,	/* 11 */
	burm_nts_6,	/* 12 */
	burm_nts_4,	/* 13 */
	burm_nts_5,	/* 14 */
	burm_nts_6,	/* 15 */
	burm_nts_1,	/* 16 */
	burm_nts_4,	/* 17 */
	burm_nts_5,	/* 18 */
	burm_nts_6,	/* 19 */
	burm_nts_4,	/* 20 */
	burm_nts_5,	/* 21 */
	burm_nts_6,	/* 22 */
	burm_nts_1,	/* 23 */
	burm_nts_3,	/* 24 */
	burm_nts_7,	/* 25 */
	burm_nts_3,	/* 26 */
	burm_nts_8,	/* 27 */
	burm_nts_8,	/* 28 */
	burm_nts_8,	/* 29 */
	burm_nts_3,	/* 30 */
	burm_nts_8,	/* 31 */
	burm_nts_8,	/* 32 */
	burm_nts_2,	/* 33 */
	burm_nts_2,	/* 34 */
	burm_nts_2,	/* 35 */
	burm_nts_7,	/* 36 */
	burm_nts_2,	/* 37 */
	burm_nts_9,	/* 38 */
	burm_nts_10,	/* 39 */
	burm_nts_10,	/* 40 */
	burm_nts_9,	/* 41 */
	burm_nts_7,	/* 42 */
	burm_nts_3,	/* 43 */
	burm_nts_11,	/* 44 */
	burm_nts_12,	/* 45 */
	burm_nts_12,	/* 46 */
	burm_nts_12,	/* 47 */
	burm_nts_12,	/* 48 */
	burm_nts_12,	/* 49 */
	burm_nts_13,	/* 50 */
};

char burm_arity[] = {
	0,	/* 0 */
	1,	/* 1=OP_NOT */
	2,	/* 2=OP_OR */
	0,	/* 3=OP_EQ */
	0,	/* 4=OP_GT */
	0,	/* 5=OP_GEQ */
	0,	/* 6=OP_LS */
	2,	/* 7=OP_LEQ */
	2,	/* 8=OP_NEQ */
	2,	/* 9=OP_ADD */
	2,	/* 10=OP_MUL */
	1,	/* 11=OP_NEG */
	0,	/* 12=OP_ID */
	0,	/* 13=OP_Number */
	1,	/* 14=OP_Field */
	1,	/* 15=OP_Return */
	0,	/* 16=OP_Zero */
	0,	/* 17=OP_One */
	0,	/* 18=OP_Args */
	0,	/* 19=OP_Call */
	1,	/* 20=OP_ReadMem */
	0,	/* 21=OP_IF */
	0,	/* 22=OP_Stats */
	0,	/* 23=OP_NOP */
	0,	/* 24=OP_Assign */
	2,	/* 25=OP_AND */
};

static short burm_decode_stat[] = {
	0,
	1,
};

static short burm_decode_ret[] = {
	0,
	2,
};

static short burm_decode_expr[] = {
	0,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
};

static short burm_decode_immediate[] = {
	0,
	25,
	26,
	27,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	35,
};

static short burm_decode_zero[] = {
	0,
	36,
	37,
	38,
	39,
	40,
	41,
};

static short burm_decode_zeroexpr[] = {
	0,
	42,
	43,
	44,
	45,
	46,
	47,
	48,
	49,
	50,
};

static short burm_decode_OP_Id[] = {
	0,
};

int burm_rule(STATEPTR_TYPE state, int goalnt) {
	burm_assert(goalnt >= 1 && goalnt <= 7, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	if (!state)
		return 0;
	switch (goalnt) {
	case burm_stat_NT:
		return burm_decode_stat[state->rule.burm_stat];
	case burm_ret_NT:
		return burm_decode_ret[state->rule.burm_ret];
	case burm_expr_NT:
		return burm_decode_expr[state->rule.burm_expr];
	case burm_immediate_NT:
		return burm_decode_immediate[state->rule.burm_immediate];
	case burm_zero_NT:
		return burm_decode_zero[state->rule.burm_zero];
	case burm_zeroexpr_NT:
		return burm_decode_zeroexpr[state->rule.burm_zeroexpr];
	case burm_OP_Id_NT:
		return burm_decode_OP_Id[state->rule.burm_OP_Id];
	default:
		burm_assert(0, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	}
	return 0;
}

static void burm_closure_ret(STATEPTR_TYPE, int);
static void burm_closure_immediate(STATEPTR_TYPE, int);
static void burm_closure_zero(STATEPTR_TYPE, int);
static void burm_closure_OP_Id(STATEPTR_TYPE, int);

static void burm_closure_ret(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_stat_NT]) {
		p->cost[burm_stat_NT] = c + 0;
		p->rule.burm_stat = 1;
	}
}

static void burm_closure_immediate(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 2;
	}
	if (c + 1 < p->cost[burm_expr_NT]) {
		p->cost[burm_expr_NT] = c + 1;
		p->rule.burm_expr = 3;
	}
}

static void burm_closure_zero(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 1;
	}
	if (c + 0 < p->cost[burm_immediate_NT]) {
		p->cost[burm_immediate_NT] = c + 0;
		p->rule.burm_immediate = 1;
		burm_closure_immediate(p, c + 0);
	}
}

static void burm_closure_OP_Id(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 9;
	}
}

STATEPTR_TYPE burm_state(int op, STATEPTR_TYPE left, STATEPTR_TYPE right) {
	int c;
	STATEPTR_TYPE p, l = left, r = right;

	if (burm_arity[op] > 0) {
		p = (STATEPTR_TYPE)ALLOC(sizeof *p);
		burm_assert(p, PANIC("ALLOC returned NULL in burm_state\n"));
		p->op = op;
		p->left = l;
		p->right = r;
		p->rule.burm_stat = 0;
		p->cost[1] =
		p->cost[2] =
		p->cost[3] =
		p->cost[4] =
		p->cost[5] =
		p->cost[6] =
		p->cost[7] =
			32767;
	}
	switch (op) {
	case 1: /* OP_NOT */
		assert(l);
		{	/* immediate: OP_NOT(immediate) */
			c = l->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 2;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NOT(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 4;
			}
		}
		break;
	case 2: /* OP_OR */
		assert(l && r);
		{	/* expr: OP_OR(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 13;
			}
		}
		{	/* expr: OP_OR(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 12;
			}
		}
		{	/* expr: OP_OR(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 11;
			}
		}
		break;
	case 3: /* OP_EQ */
		{
			static struct burm_state z = { 3, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 4: /* OP_GT */
		{
			static struct burm_state z = { 4, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 5: /* OP_GEQ */
		{
			static struct burm_state z = { 5, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 6: /* OP_LS */
		{
			static struct burm_state z = { 6, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 7: /* OP_LEQ */
		assert(l && r);
		{	/* zeroexpr: OP_LEQ(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 7;
			}
		}
		{	/* immediate: OP_LEQ(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 7;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_LEQ(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 17;
			}
		}
		{	/* expr: OP_LEQ(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 16;
			}
		}
		{	/* expr: OP_LEQ(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 15;
			}
		}
		break;
	case 8: /* OP_NEQ */
		assert(l && r);
		{	/* zeroexpr: OP_NEQ(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 8;
			}
		}
		{	/* immediate: OP_NEQ(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 8;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NEQ(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 20;
			}
		}
		{	/* expr: OP_NEQ(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 19;
			}
		}
		{	/* expr: OP_NEQ(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 18;
			}
		}
		break;
	case 9: /* OP_ADD */
		assert(l && r);
		{	/* zeroexpr: OP_ADD(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 4;
			}
		}
		{	/* immediate: OP_ADD(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 3;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_ADD(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 7;
			}
		}
		{	/* expr: OP_ADD(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 6;
			}
		}
		{	/* expr: OP_ADD(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 5;
			}
		}
		break;
	case 10: /* OP_MUL */
		assert(l && r);
		{	/* zeroexpr: OP_MUL(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 5;
			}
		}
		{	/* zero: OP_MUL(zero,zeroexpr) */
			c = l->cost[burm_zero_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zero_NT]) {
				p->cost[burm_zero_NT] = c + 0;
				p->rule.burm_zero = 4;
				burm_closure_zero(p, c + 0);
			}
		}
		{	/* zero: OP_MUL(zeroexpr,zero) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zero_NT] + 0;
			if (c + 0 < p->cost[burm_zero_NT]) {
				p->cost[burm_zero_NT] = c + 0;
				p->rule.burm_zero = 3;
				burm_closure_zero(p, c + 0);
			}
		}
		{	/* immediate: OP_MUL(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 4;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_MUL(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 10;
			}
		}
		{	/* expr: OP_MUL(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 9;
			}
		}
		{	/* expr: OP_MUL(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 8;
			}
		}
		break;
	case 11: /* OP_NEG */
		assert(l);
		{	/* zeroexpr: OP_NEG(zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 3;
			}
		}
		{	/* zero: OP_NEG(zero) */
			c = l->cost[burm_zero_NT] + 0;
			if (c + 0 < p->cost[burm_zero_NT]) {
				p->cost[burm_zero_NT] = c + 0;
				p->rule.burm_zero = 1;
				burm_closure_zero(p, c + 0);
			}
		}
		{	/* immediate: OP_NEG(immediate) */
			c = l->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 6;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NEG(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 14;
			}
		}
		break;
	case 12: /* OP_ID */
		{
			static struct burm_state z = { 12, 0, 0,
				{	0,
					32767,
					32767,
					1,	/* expr: OP_ID */
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					1,	/* expr: OP_ID */
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 13: /* OP_Number */
		{
			static struct burm_state z = { 13, 0, 0,
				{	0,
					32767,
					32767,
					1,	/* expr: immediate */
					0,	/* immediate: OP_Number */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					3,	/* expr: immediate */
					9,	/* immediate: OP_Number */
					0,
					2,	/* zeroexpr: immediate */
					0,
				}
			};
			return &z;
		}
	case 14: /* OP_Field */
		assert(l);
		{	/* expr: OP_Field(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 2;
			}
		}
		break;
	case 15: /* OP_Return */
		assert(l);
		{	/* ret: OP_Return(expr) */
			c = l->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_ret_NT]) {
				p->cost[burm_ret_NT] = c + 0;
				p->rule.burm_ret = 1;
				burm_closure_ret(p, c + 0);
			}
		}
		break;
	case 16: /* OP_Zero */
		{
			static struct burm_state z = { 16, 0, 0,
				{	0,
					32767,
					32767,
					1,	/* expr: immediate */
					0,	/* immediate: OP_Zero */
					0,	/* zero: OP_Zero */
					0,	/* zeroexpr: zero */
					32767,
				},{
					0,
					0,
					3,	/* expr: immediate */
					10,	/* immediate: OP_Zero */
					2,	/* zero: OP_Zero */
					1,	/* zeroexpr: zero */
					0,
				}
			};
			return &z;
		}
	case 17: /* OP_One */
		{
			static struct burm_state z = { 17, 0, 0,
				{	0,
					32767,
					32767,
					1,	/* expr: immediate */
					0,	/* immediate: OP_One */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					3,	/* expr: immediate */
					11,	/* immediate: OP_One */
					0,
					2,	/* zeroexpr: immediate */
					0,
				}
			};
			return &z;
		}
	case 18: /* OP_Args */
		{
			static struct burm_state z = { 18, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 19: /* OP_Call */
		{
			static struct burm_state z = { 19, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 20: /* OP_ReadMem */
		assert(l);
		{	/* expr: OP_ReadMem(immediate) */
			c = l->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 22;
			}
		}
		{	/* expr: OP_ReadMem(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 21;
			}
		}
		break;
	case 21: /* OP_IF */
		{
			static struct burm_state z = { 21, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 22: /* OP_Stats */
		{
			static struct burm_state z = { 22, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 23: /* OP_NOP */
		{
			static struct burm_state z = { 23, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 24: /* OP_Assign */
		{
			static struct burm_state z = { 24, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 25: /* OP_AND */
		assert(l && r);
		{	/* zeroexpr: OP_AND(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 6;
			}
		}
		{	/* zero: OP_AND(zeroexpr,zero) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zero_NT] + 0;
			if (c + 0 < p->cost[burm_zero_NT]) {
				p->cost[burm_zero_NT] = c + 0;
				p->rule.burm_zero = 6;
				burm_closure_zero(p, c + 0);
			}
		}
		{	/* zero: OP_AND(zero,zeroexpr) */
			c = l->cost[burm_zero_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zero_NT]) {
				p->cost[burm_zero_NT] = c + 0;
				p->rule.burm_zero = 5;
				burm_closure_zero(p, c + 0);
			}
		}
		{	/* immediate: OP_AND(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 5;
				burm_closure_immediate(p, c + 0);
			}
		}
		break;
	default:
		burm_assert(0, PANIC("Bad operator %d in burm_state\n", op));
	}
	return p;
}

#ifdef STATE_LABEL
static void burm_label1(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_label\n"));
	switch (burm_arity[OP_LABEL(p)]) {
	case 0:
		STATE_LABEL(p) = burm_state(OP_LABEL(p), 0, 0);
		break;
	case 1:
		burm_label1(LEFT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)), 0);
		break;
	case 2:
		burm_label1(LEFT_CHILD(p));
		burm_label1(RIGHT_CHILD(p));
		STATE_LABEL(p) = burm_state(OP_LABEL(p),
			STATE_LABEL(LEFT_CHILD(p)),
			STATE_LABEL(RIGHT_CHILD(p)));
		break;
	}
}

STATEPTR_TYPE burm_label(NODEPTR_TYPE p) {
	burm_label1(p);
	return STATE_LABEL(p)->rule.burm_stat ? STATE_LABEL(p) : 0;
}

NODEPTR_TYPE *burm_kids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	burm_assert(p, PANIC("NULL tree in burm_kids\n"));
	burm_assert(kids, PANIC("NULL kids in burm_kids\n"));
	switch (eruleno) {
	case 50: /* zeroexpr: OP_Id */
	case 43: /* zeroexpr: immediate */
	case 42: /* zeroexpr: zero */
	case 25: /* immediate: zero */
	case 5: /* expr: immediate */
	case 1: /* stat: ret */
		kids[0] = p;
		break;
	case 44: /* zeroexpr: OP_NEG(zeroexpr) */
	case 36: /* zero: OP_NEG(zero) */
	case 30: /* immediate: OP_NEG(immediate) */
	case 26: /* immediate: OP_NOT(immediate) */
	case 24: /* expr: OP_ReadMem(immediate) */
	case 23: /* expr: OP_ReadMem(expr) */
	case 16: /* expr: OP_NEG(expr) */
	case 6: /* expr: OP_NOT(expr) */
	case 4: /* expr: OP_Field(expr) */
	case 2: /* ret: OP_Return(expr) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 37: /* zero: OP_Zero */
	case 35: /* immediate: OP_One */
	case 34: /* immediate: OP_Zero */
	case 33: /* immediate: OP_Number */
	case 3: /* expr: OP_ID */
		break;
	case 49: /* zeroexpr: OP_NEQ(zeroexpr,zeroexpr) */
	case 48: /* zeroexpr: OP_LEQ(zeroexpr,zeroexpr) */
	case 47: /* zeroexpr: OP_AND(zeroexpr,zeroexpr) */
	case 46: /* zeroexpr: OP_MUL(zeroexpr,zeroexpr) */
	case 45: /* zeroexpr: OP_ADD(zeroexpr,zeroexpr) */
	case 41: /* zero: OP_AND(zeroexpr,zero) */
	case 40: /* zero: OP_AND(zero,zeroexpr) */
	case 39: /* zero: OP_MUL(zero,zeroexpr) */
	case 38: /* zero: OP_MUL(zeroexpr,zero) */
	case 32: /* immediate: OP_NEQ(immediate,immediate) */
	case 31: /* immediate: OP_LEQ(immediate,immediate) */
	case 29: /* immediate: OP_AND(immediate,immediate) */
	case 28: /* immediate: OP_MUL(immediate,immediate) */
	case 27: /* immediate: OP_ADD(immediate,immediate) */
	case 22: /* expr: OP_NEQ(expr,immediate) */
	case 21: /* expr: OP_NEQ(immediate,expr) */
	case 20: /* expr: OP_NEQ(expr,expr) */
	case 19: /* expr: OP_LEQ(expr,immediate) */
	case 18: /* expr: OP_LEQ(immediate,expr) */
	case 17: /* expr: OP_LEQ(expr,expr) */
	case 15: /* expr: OP_OR(expr,immediate) */
	case 14: /* expr: OP_OR(immediate,expr) */
	case 13: /* expr: OP_OR(expr,expr) */
	case 12: /* expr: OP_MUL(expr,immediate) */
	case 11: /* expr: OP_MUL(immediate,expr) */
	case 10: /* expr: OP_MUL(expr,expr) */
	case 9: /* expr: OP_ADD(expr,immediate) */
	case 8: /* expr: OP_ADD(immediate,expr) */
	case 7: /* expr: OP_ADD(expr,expr) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	default:
		burm_assert(0, PANIC("Bad external rule number %d in burm_kids\n", eruleno));
	}
	return kids;
}

int burm_op_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_op_label\n"));
	return OP_LABEL(p);
}

STATEPTR_TYPE burm_state_label(NODEPTR_TYPE p) {
	burm_assert(p, PANIC("NULL tree in burm_state_label\n"));
	return STATE_LABEL(p);
}

NODEPTR_TYPE burm_child(NODEPTR_TYPE p, int index) {
	burm_assert(p, PANIC("NULL tree in burm_child\n"));
	switch (index) {
	case 0:	return LEFT_CHILD(p);
	case 1:	return RIGHT_CHILD(p);
	}
	burm_assert(0, PANIC("Bad index %d in burm_child\n", index));
	return 0;
}

#endif


void burm_reduce(NODEPTR_TYPE bnode, int goalnt)
{
  int ruleNo = burm_rule (STATE_LABEL(bnode), goalnt);
  short *nts = burm_nts[ruleNo];
  NODEPTR_TYPE kids[100];
  int i;

  if (ruleNo==0) {
    fprintf(stderr, "tree cannot be derived from start symbol");
    exit(1);
  }
  burm_kids (bnode, ruleNo, kids);
  for (i = 0; nts[i]; i++)
    burm_reduce (kids[i], nts[i]);    /* reduce kids */

#if DEBUG
  printf ("%s", burm_string[ruleNo]);  /* display rule */
#endif

  switch (ruleNo) {
  case 10:
 mul(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 11:
 muli(bnode->child[0]->value, bnode->child[1]->reg);
    break;
  case 12:
 muli(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 13:
 or(bnode->child[0]->reg,bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 14:
 ori(bnode->child[0]->value,bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 15:
 ori(bnode->child[1]->value,bnode->child[0]->reg); move(bnode->child[0]->reg, bnode->reg);
    break;
  case 16:
 neg(bnode->reg);
    break;
  case 30:
 bnode->value = - bnode->child[0]->value;
    break;
  case 17:
 smallerequal(bnode->child[1]->reg, bnode->child[0]->reg, bnode->reg);
    break;
  case 31:
 bnode->value = (bnode->child[0]->value <= bnode->child[1]->value)? 1 : 0;
    break;
  case 18:
 smallerequali2(bnode->child[1]->reg,bnode->child[0]->value, bnode->reg);
    break;
  case 32:
 bnode->value = (bnode->child[0]->value != bnode->child[1]->value)? 1 : 0;
    break;
  case 19:
 smallerequali(bnode->child[1]->value,bnode->child[0]->reg, bnode->reg);
    break;
  case 33:

    break;
  case 34:

    break;
  case 35:

    break;
  case 36:

    break;
  case 50:

    break;
  case 37:

    break;
  case 38:

    break;
  case 39:

    break;
  case 1:

    break;
  case 2:
 move(bnode->reg, "rax"); retrn();
    break;
  case 3:
 if(bnode->param_index != -1) move(getParamRegister(bnode->param_index), bnode->reg);
    break;
  case 4:
 move_offset(bnode->child[0]->reg, bnode->reg, bnode->offset);
    break;
  case 5:
 movei(bnode->value, bnode->reg);
    break;
  case 6:
 not(bnode->reg);
    break;
  case 7:
 add(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 8:
 addi(bnode->child[0]->value, bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 9:
 addi(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 20:
 notequal(bnode->child[0]->reg, bnode->child[1]->reg, bnode->reg);
    break;
  case 21:
 notequali(bnode->child[0]->value, bnode->child[1]->reg, bnode->reg);
    break;
  case 22:
 notequali(bnode->child[1]->value, bnode->child[0]->reg, bnode->reg);
    break;
  case 23:
 address(bnode->child[0]->reg, bnode->reg);
    break;
  case 24:
 addressi(bnode->child[0]->value, bnode->reg);
    break;
  case 25:
 bnode->value = 0;
    break;
  case 26:
 bnode->value = ! bnode->child[0]->value;
    break;
  case 40:

    break;
  case 27:
 bnode->value = bnode->child[0]->value + bnode->child[1]->value;
    break;
  case 41:

    break;
  case 28:
 bnode->value = bnode->child[0]->value * bnode->child[1]->value;
    break;
  case 42:

    break;
  case 29:
 bnode->value = bnode->child[0]->value & bnode->child[1]->value;
    break;
  case 43:

    break;
  case 44:

    break;
  case 45:

    break;
  case 46:

    break;
  case 47:

    break;
  case 48:

    break;
  case 49:

    break;
  default:    assert (0);
  }
}
