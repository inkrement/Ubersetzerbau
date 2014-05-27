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
#define burm_immediate_NT 3
#define burm_expr_NT 4
#define burm_zero_NT 5
#define burm_zeroexpr_NT 6
#define burm_OP_Id_NT 7
int burm_max_nt = 7;

struct burm_state {
	int op;
	STATEPTR_TYPE left, right;
	short cost[8];
	struct {
		unsigned burm_stat:3;
		unsigned burm_ret:1;
		unsigned burm_immediate:4;
		unsigned burm_expr:5;
		unsigned burm_zero:3;
		unsigned burm_zeroexpr:4;
		unsigned burm_OP_Id:1;
	} rule;
};

static short burm_nts_0[] = { burm_ret_NT, 0 };
static short burm_nts_1[] = { burm_immediate_NT, 0 };
static short burm_nts_2[] = { burm_expr_NT, 0 };
static short burm_nts_3[] = { burm_immediate_NT, burm_expr_NT, 0 };
static short burm_nts_4[] = { burm_expr_NT, burm_expr_NT, 0 };
static short burm_nts_5[] = { burm_expr_NT, burm_immediate_NT, 0 };
static short burm_nts_6[] = { 0 };
static short burm_nts_7[] = { burm_immediate_NT, burm_immediate_NT, 0 };
static short burm_nts_8[] = { burm_zero_NT, 0 };
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
	burm_nts_2,	/* 4 */
	burm_nts_1,	/* 5 */
	burm_nts_2,	/* 6 */
	burm_nts_1,	/* 7 */
	burm_nts_2,	/* 8 */
	burm_nts_3,	/* 9 */
	burm_nts_4,	/* 10 */
	burm_nts_5,	/* 11 */
	burm_nts_4,	/* 12 */
	burm_nts_3,	/* 13 */
	burm_nts_5,	/* 14 */
	burm_nts_2,	/* 15 */
	burm_nts_4,	/* 16 */
	burm_nts_3,	/* 17 */
	burm_nts_5,	/* 18 */
	burm_nts_4,	/* 19 */
	burm_nts_3,	/* 20 */
	burm_nts_5,	/* 21 */
	burm_nts_2,	/* 22 */
	burm_nts_6,	/* 23 */
	burm_nts_2,	/* 24 */
	burm_nts_6,	/* 25 */
	burm_nts_4,	/* 26 */
	burm_nts_3,	/* 27 */
	burm_nts_5,	/* 28 */
	burm_nts_1,	/* 29 */
	burm_nts_1,	/* 30 */
	burm_nts_1,	/* 31 */
	burm_nts_7,	/* 32 */
	burm_nts_7,	/* 33 */
	burm_nts_7,	/* 34 */
	burm_nts_8,	/* 35 */
	burm_nts_6,	/* 36 */
	burm_nts_6,	/* 37 */
	burm_nts_6,	/* 38 */
	burm_nts_8,	/* 39 */
	burm_nts_6,	/* 40 */
	burm_nts_9,	/* 41 */
	burm_nts_10,	/* 42 */
	burm_nts_8,	/* 43 */
	burm_nts_1,	/* 44 */
	burm_nts_11,	/* 45 */
	burm_nts_12,	/* 46 */
	burm_nts_12,	/* 47 */
	burm_nts_12,	/* 48 */
	burm_nts_13,	/* 49 */
	burm_nts_12,	/* 50 */
};

char burm_arity[] = {
	0,	/* 0 */
	1,	/* 1=OP_NOT */
	2,	/* 2=OP_OR */
	2,	/* 3=OP_NEQ */
	2,	/* 4=OP_ADD */
	2,	/* 5=OP_MUL */
	1,	/* 6=OP_NEG */
	0,	/* 7=OP_ID */
	0,	/* 8=OP_Number */
	1,	/* 9=OP_Field */
	1,	/* 10=OP_Return */
	0,	/* 11=OP_Zero */
	0,	/* 12=OP_One */
	0,	/* 13=OP_Args */
	0,	/* 14=OP_NOP */
	2,	/* 15=OP_GREATER */
	2,	/* 16=OP_LEXPR */
	0,	/* 17=OP_Assign */
	1,	/* 18=OP_With */
	0,	/* 19 */
	0,	/* 20=OP_Fieldvariable */
};

static short burm_decode_stat[] = {
	0,
	1,
	2,
	3,
	4,
	5,
	6,
	7,
};

static short burm_decode_ret[] = {
	0,
	15,
};

static short burm_decode_immediate[] = {
	0,
	30,
	31,
	32,
	33,
	34,
	35,
	36,
	37,
	38,
};

static short burm_decode_expr[] = {
	0,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	16,
	17,
	18,
	19,
	20,
	21,
	22,
	23,
	24,
	25,
	26,
	27,
	28,
	29,
};

static short burm_decode_zero[] = {
	0,
	39,
	40,
	41,
	42,
};

static short burm_decode_zeroexpr[] = {
	0,
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
	case burm_immediate_NT:
		return burm_decode_immediate[state->rule.burm_immediate];
	case burm_expr_NT:
		return burm_decode_expr[state->rule.burm_expr];
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
		p->rule.burm_expr = 21;
	}
}

static void burm_closure_zero(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 1;
	}
	if (c + 0 < p->cost[burm_immediate_NT]) {
		p->cost[burm_immediate_NT] = c + 0;
		p->rule.burm_immediate = 6;
		burm_closure_immediate(p, c + 0);
	}
}

static void burm_closure_OP_Id(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 7;
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
				p->rule.burm_immediate = 1;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NOT(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 1;
			}
		}
		break;
	case 2: /* OP_OR */
		assert(l && r);
		{	/* expr: OP_OR(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 4;
			}
		}
		{	/* expr: OP_OR(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 3;
			}
		}
		{	/* expr: OP_OR(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 2;
			}
		}
		break;
	case 3: /* OP_NEQ */
		assert(l && r);
		{	/* zeroexpr: OP_NEQ(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 6;
			}
		}
		{	/* immediate: OP_NEQ(immediate,immediate) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_immediate_NT]) {
				p->cost[burm_immediate_NT] = c + 0;
				p->rule.burm_immediate = 3;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NEQ(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 7;
			}
		}
		{	/* expr: OP_NEQ(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 6;
			}
		}
		{	/* expr: OP_NEQ(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 5;
			}
		}
		break;
	case 4: /* OP_ADD */
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
				p->rule.burm_immediate = 4;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_ADD(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 10;
			}
		}
		{	/* expr: OP_ADD(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 9;
			}
		}
		{	/* expr: OP_ADD(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 8;
			}
		}
		break;
	case 5: /* OP_MUL */
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
				p->rule.burm_immediate = 5;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_MUL(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 13;
			}
		}
		{	/* expr: OP_MUL(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 12;
			}
		}
		{	/* expr: OP_MUL(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 11;
			}
		}
		break;
	case 6: /* OP_NEG */
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
				p->rule.burm_immediate = 2;
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
	case 7: /* OP_ID */
		{
			static struct burm_state z = { 7, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					1,	/* expr: OP_ID */
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					15,	/* expr: OP_ID */
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 8: /* OP_Number */
		{
			static struct burm_state z = { 8, 0, 0,
				{	0,
					32767,
					32767,
					0,	/* immediate: OP_Number */
					1,	/* expr: immediate */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					7,	/* immediate: OP_Number */
					21,	/* expr: immediate */
					0,
					2,	/* zeroexpr: immediate */
					0,
				}
			};
			return &z;
		}
	case 9: /* OP_Field */
		assert(l);
		{	/* expr: OP_Field(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 16;
			}
		}
		break;
	case 10: /* OP_Return */
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
	case 11: /* OP_Zero */
		{
			static struct burm_state z = { 11, 0, 0,
				{	0,
					32767,
					32767,
					0,	/* immediate: OP_Zero */
					1,	/* expr: immediate */
					0,	/* zero: OP_Zero */
					0,	/* zeroexpr: zero */
					32767,
				},{
					0,
					0,
					8,	/* immediate: OP_Zero */
					21,	/* expr: immediate */
					2,	/* zero: OP_Zero */
					1,	/* zeroexpr: zero */
					0,
				}
			};
			return &z;
		}
	case 12: /* OP_One */
		{
			static struct burm_state z = { 12, 0, 0,
				{	0,
					32767,
					32767,
					0,	/* immediate: OP_One */
					1,	/* expr: immediate */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					9,	/* immediate: OP_One */
					21,	/* expr: immediate */
					0,
					2,	/* zeroexpr: immediate */
					0,
				}
			};
			return &z;
		}
	case 13: /* OP_Args */
		{
			static struct burm_state z = { 13, 0, 0,
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
	case 14: /* OP_NOP */
		{
			static struct burm_state z = { 14, 0, 0,
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
	case 15: /* OP_GREATER */
		assert(l && r);
		{	/* zeroexpr: OP_GREATER(zeroexpr,zeroexpr) */
			c = l->cost[burm_zeroexpr_NT] + r->cost[burm_zeroexpr_NT] + 0;
			if (c + 0 < p->cost[burm_zeroexpr_NT]) {
				p->cost[burm_zeroexpr_NT] = c + 0;
				p->rule.burm_zeroexpr = 8;
			}
		}
		{	/* expr: OP_GREATER(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 20;
			}
		}
		{	/* expr: OP_GREATER(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 19;
			}
		}
		{	/* expr: OP_GREATER(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 18;
			}
		}
		break;
	case 16: /* OP_LEXPR */
		assert(l && r);
		if (	/* stat: OP_LEXPR(OP_Fieldvariable,immediate) */
			l->op == 20 /* OP_Fieldvariable */
		) {
			c = r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 7;
			}
		}
		if (	/* stat: OP_LEXPR(OP_Fieldvariable,expr) */
			l->op == 20 /* OP_Fieldvariable */
		) {
			c = r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 6;
			}
		}
		if (	/* stat: OP_LEXPR(OP_ID,immediate) */
			l->op == 7 /* OP_ID */
		) {
			c = r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 5;
			}
		}
		if (	/* stat: OP_LEXPR(OP_ID,expr) */
			l->op == 7 /* OP_ID */
		) {
			c = r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 4;
			}
		}
		break;
	case 17: /* OP_Assign */
		{
			static struct burm_state z = { 17, 0, 0,
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
	case 18: /* OP_With */
		assert(l);
		{	/* stat: OP_With(expr) */
			c = l->cost[burm_expr_NT] + 0;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 3;
			}
		}
		{	/* stat: OP_With(immediate) */
			c = l->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 2;
			}
		}
		break;
	case 20: /* OP_Fieldvariable */
		{
			static struct burm_state z = { 20, 0, 0,
				{	0,
					32767,
					32767,
					32767,
					1,	/* expr: OP_Fieldvariable */
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					17,	/* expr: OP_Fieldvariable */
					0,
					0,
					0,
				}
			};
			return &z;
		}
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
	case 49: /* zeroexpr: OP_Id */
	case 44: /* zeroexpr: immediate */
	case 43: /* zeroexpr: zero */
	case 35: /* immediate: zero */
	case 29: /* expr: immediate */
	case 1: /* stat: ret */
		kids[0] = p;
		break;
	case 45: /* zeroexpr: OP_NEG(zeroexpr) */
	case 39: /* zero: OP_NEG(zero) */
	case 31: /* immediate: OP_NEG(immediate) */
	case 30: /* immediate: OP_NOT(immediate) */
	case 24: /* expr: OP_Field(expr) */
	case 22: /* expr: OP_NEG(expr) */
	case 15: /* ret: OP_Return(expr) */
	case 8: /* expr: OP_NOT(expr) */
	case 3: /* stat: OP_With(expr) */
	case 2: /* stat: OP_With(immediate) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 7: /* stat: OP_LEXPR(OP_Fieldvariable,immediate) */
	case 6: /* stat: OP_LEXPR(OP_Fieldvariable,expr) */
	case 5: /* stat: OP_LEXPR(OP_ID,immediate) */
	case 4: /* stat: OP_LEXPR(OP_ID,expr) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 50: /* zeroexpr: OP_GREATER(zeroexpr,zeroexpr) */
	case 48: /* zeroexpr: OP_NEQ(zeroexpr,zeroexpr) */
	case 47: /* zeroexpr: OP_MUL(zeroexpr,zeroexpr) */
	case 46: /* zeroexpr: OP_ADD(zeroexpr,zeroexpr) */
	case 42: /* zero: OP_MUL(zero,zeroexpr) */
	case 41: /* zero: OP_MUL(zeroexpr,zero) */
	case 34: /* immediate: OP_MUL(immediate,immediate) */
	case 33: /* immediate: OP_ADD(immediate,immediate) */
	case 32: /* immediate: OP_NEQ(immediate,immediate) */
	case 28: /* expr: OP_GREATER(expr,immediate) */
	case 27: /* expr: OP_GREATER(immediate,expr) */
	case 26: /* expr: OP_GREATER(expr,expr) */
	case 21: /* expr: OP_MUL(expr,immediate) */
	case 20: /* expr: OP_MUL(immediate,expr) */
	case 19: /* expr: OP_MUL(expr,expr) */
	case 18: /* expr: OP_ADD(expr,immediate) */
	case 17: /* expr: OP_ADD(immediate,expr) */
	case 16: /* expr: OP_ADD(expr,expr) */
	case 14: /* expr: OP_NEQ(expr,immediate) */
	case 13: /* expr: OP_NEQ(immediate,expr) */
	case 12: /* expr: OP_NEQ(expr,expr) */
	case 11: /* expr: OP_OR(expr,immediate) */
	case 10: /* expr: OP_OR(expr,expr) */
	case 9: /* expr: OP_OR(immediate,expr) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 40: /* zero: OP_Zero */
	case 38: /* immediate: OP_One */
	case 37: /* immediate: OP_Zero */
	case 36: /* immediate: OP_Number */
	case 25: /* expr: OP_Fieldvariable */
	case 23: /* expr: OP_ID */
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
 or(bnode->child[0]->reg,bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 11:
 ori(bnode->child[1]->value,bnode->child[0]->reg); move(bnode->child[0]->reg, bnode->reg);
    break;
  case 12:
 notequal(bnode->child[0]->reg, bnode->child[1]->reg, bnode->reg);
    break;
  case 13:
 notequali(bnode->child[0]->value, bnode->child[1]->reg, bnode->reg);
    break;
  case 14:
 notequali(bnode->child[1]->value, bnode->child[0]->reg, bnode->reg);
    break;
  case 15:
 move(bnode->reg, "%rax"); ret();
    break;
  case 16:
 add(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 30:
 bnode->value = ! bnode->child[0]->value;
    break;
  case 17:
 addi(bnode->child[0]->value, bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 31:
 bnode->value = - bnode->child[0]->value;
    break;
  case 18:
 addi(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 32:
 bnode->value = (bnode->child[0]->value != bnode->child[1]->value)? 1 : 0;
    break;
  case 19:
 mul(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 33:
 bnode->value = bnode->child[0]->value + bnode->child[1]->value;
    break;
  case 34:
 bnode->value = bnode->child[0]->value * bnode->child[1]->value;
    break;
  case 35:
 bnode->value = 0;
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
 printf("\ttodo width imm: reg %s\n", bnode->reg);movei(bnode->child[0]->value, bnode->reg);
    break;
  case 3:
 printf("\ttodo width expr: reg %s\n", bnode->reg);move(bnode->child[0]->reg, bnode->reg);
    break;
  case 4:
 move(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 5:
 movei(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 6:
 printf("expr"); move(bnode->child[1]->reg, bnode->child[0]->reg);
    break;
  case 7:
 printf("expr"); movei(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 8:
 not(bnode->reg);
    break;
  case 9:
 ori(bnode->child[0]->value,bnode->child[1]->reg); move(bnode->child[1]->reg, bnode->reg);
    break;
  case 20:
 muli(bnode->child[0]->value, bnode->child[1]->reg);
    break;
  case 21:
 muli(bnode->child[1]->value, bnode->child[0]->reg);
    break;
  case 22:
 neg(bnode->reg);
    break;
  case 23:
 printf("load id\n"); if(bnode->param_index != -1) move(getParamRegister(bnode->param_index), bnode->reg);
    break;
  case 24:
 move_offset(bnode->child[0]->reg, bnode->reg, bnode->offset);
    break;
  case 25:
 move_offset(getRegister(bnode->name), bnode->reg, bnode->offset);
    break;
  case 26:
 greater(bnode->child[1]->reg, bnode->child[0]->reg, bnode->reg);
    break;
  case 40:

    break;
  case 27:
 greateri(bnode->child[1]->value,bnode->child[0]->reg, bnode->reg);
    break;
  case 41:

    break;
  case 28:
 greateri2(bnode->child[1]->reg,bnode->child[0]->value, bnode->reg);
    break;
  case 42:

    break;
  case 29:
 movei(bnode->value, bnode->reg);
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
