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
#define burm_assign_NT 3
#define burm_immediate_NT 4
#define burm_expr_NT 5
#define burm_fieldchain_NT 6
#define burm_zero_NT 7
#define burm_zeroexpr_NT 8
#define burm_cond_NT 9
int burm_max_nt = 9;

struct burm_state {
	int op;
	STATEPTR_TYPE left, right;
	short cost[10];
	struct {
		unsigned burm_stat:4;
		unsigned burm_ret:2;
		unsigned burm_assign:2;
		unsigned burm_immediate:4;
		unsigned burm_expr:5;
		unsigned burm_fieldchain:2;
		unsigned burm_zero:3;
		unsigned burm_zeroexpr:3;
		unsigned burm_cond:2;
	} rule;
};

static short burm_nts_0[] = { burm_ret_NT, 0 };
static short burm_nts_1[] = { burm_assign_NT, 0 };
static short burm_nts_2[] = { burm_immediate_NT, 0 };
static short burm_nts_3[] = { burm_expr_NT, 0 };
static short burm_nts_4[] = { burm_fieldchain_NT, burm_expr_NT, 0 };
static short burm_nts_5[] = { burm_fieldchain_NT, 0 };
static short burm_nts_6[] = { burm_expr_NT, burm_expr_NT, 0 };
static short burm_nts_7[] = { burm_expr_NT, burm_assign_NT, 0 };
static short burm_nts_8[] = { burm_immediate_NT, burm_expr_NT, 0 };
static short burm_nts_9[] = { burm_expr_NT, burm_immediate_NT, 0 };
static short burm_nts_10[] = { 0 };
static short burm_nts_11[] = { burm_immediate_NT, burm_immediate_NT, 0 };
static short burm_nts_12[] = { burm_zero_NT, 0 };
static short burm_nts_13[] = { burm_zeroexpr_NT, burm_zero_NT, 0 };
static short burm_nts_14[] = { burm_zero_NT, burm_zeroexpr_NT, 0 };
static short burm_nts_15[] = { burm_zeroexpr_NT, 0 };
static short burm_nts_16[] = { burm_zeroexpr_NT, burm_zeroexpr_NT, 0 };
static short burm_nts_17[] = { burm_cond_NT, 0 };
static short burm_nts_18[] = { burm_expr_NT, burm_cond_NT, 0 };

short *burm_nts[] = {
	0,	/* 0 */
	burm_nts_0,	/* 1 */
	burm_nts_1,	/* 2 */
	burm_nts_2,	/* 3 */
	burm_nts_3,	/* 4 */
	burm_nts_3,	/* 5 */
	burm_nts_3,	/* 6 */
	burm_nts_4,	/* 7 */
	burm_nts_5,	/* 8 */
	burm_nts_5,	/* 9 */
	burm_nts_3,	/* 10 */
	burm_nts_6,	/* 11 */
	burm_nts_3,	/* 12 */
	burm_nts_2,	/* 13 */
	burm_nts_7,	/* 14 */
	burm_nts_3,	/* 15 */
	burm_nts_8,	/* 16 */
	burm_nts_6,	/* 17 */
	burm_nts_9,	/* 18 */
	burm_nts_2,	/* 19 */
	burm_nts_10,	/* 20 */
	burm_nts_3,	/* 21 */
	burm_nts_10,	/* 22 */
	burm_nts_8,	/* 23 */
	burm_nts_6,	/* 24 */
	burm_nts_9,	/* 25 */
	burm_nts_6,	/* 26 */
	burm_nts_9,	/* 27 */
	burm_nts_8,	/* 28 */
	burm_nts_8,	/* 29 */
	burm_nts_9,	/* 30 */
	burm_nts_6,	/* 31 */
	burm_nts_6,	/* 32 */
	burm_nts_8,	/* 33 */
	burm_nts_9,	/* 34 */
	burm_nts_3,	/* 35 */
	burm_nts_11,	/* 36 */
	burm_nts_2,	/* 37 */
	burm_nts_2,	/* 38 */
	burm_nts_11,	/* 39 */
	burm_nts_11,	/* 40 */
	burm_nts_12,	/* 41 */
	burm_nts_10,	/* 42 */
	burm_nts_10,	/* 43 */
	burm_nts_10,	/* 44 */
	burm_nts_12,	/* 45 */
	burm_nts_10,	/* 46 */
	burm_nts_13,	/* 47 */
	burm_nts_14,	/* 48 */
	burm_nts_12,	/* 49 */
	burm_nts_2,	/* 50 */
	burm_nts_15,	/* 51 */
	burm_nts_16,	/* 52 */
	burm_nts_16,	/* 53 */
	burm_nts_16,	/* 54 */
	burm_nts_16,	/* 55 */
	burm_nts_17,	/* 56 */
	burm_nts_3,	/* 57 */
	burm_nts_18,	/* 58 */
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
	2,	/* 17=OP_Assign */
	1,	/* 18=OP_With */
	0,	/* 19 */
	0,	/* 20=OP_Fieldvariable */
	2,	/* 21=OP_Cond */
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
	11,
	56,
};

static short burm_decode_ret[] = {
	0,
	12,
	13,
};

static short burm_decode_assign[] = {
	0,
	14,
	15,
};

static short burm_decode_immediate[] = {
	0,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
};

static short burm_decode_expr[] = {
	0,
	8,
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
	30,
	31,
	32,
	33,
	34,
	35,
};

static short burm_decode_fieldchain[] = {
	0,
	9,
	10,
};

static short burm_decode_zero[] = {
	0,
	45,
	46,
	47,
	48,
};

static short burm_decode_zeroexpr[] = {
	0,
	49,
	50,
	51,
	52,
	53,
	54,
	55,
};

static short burm_decode_cond[] = {
	0,
	57,
	58,
};

int burm_rule(STATEPTR_TYPE state, int goalnt) {
	burm_assert(goalnt >= 1 && goalnt <= 9, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	if (!state)
		return 0;
	switch (goalnt) {
	case burm_stat_NT:
		return burm_decode_stat[state->rule.burm_stat];
	case burm_ret_NT:
		return burm_decode_ret[state->rule.burm_ret];
	case burm_assign_NT:
		return burm_decode_assign[state->rule.burm_assign];
	case burm_immediate_NT:
		return burm_decode_immediate[state->rule.burm_immediate];
	case burm_expr_NT:
		return burm_decode_expr[state->rule.burm_expr];
	case burm_fieldchain_NT:
		return burm_decode_fieldchain[state->rule.burm_fieldchain];
	case burm_zero_NT:
		return burm_decode_zero[state->rule.burm_zero];
	case burm_zeroexpr_NT:
		return burm_decode_zeroexpr[state->rule.burm_zeroexpr];
	case burm_cond_NT:
		return burm_decode_cond[state->rule.burm_cond];
	default:
		burm_assert(0, PANIC("Bad goal nonterminal %d in burm_rule\n", goalnt));
	}
	return 0;
}

static void burm_closure_ret(STATEPTR_TYPE, int);
static void burm_closure_assign(STATEPTR_TYPE, int);
static void burm_closure_immediate(STATEPTR_TYPE, int);
static void burm_closure_expr(STATEPTR_TYPE, int);
static void burm_closure_fieldchain(STATEPTR_TYPE, int);
static void burm_closure_zero(STATEPTR_TYPE, int);
static void burm_closure_cond(STATEPTR_TYPE, int);

static void burm_closure_ret(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_stat_NT]) {
		p->cost[burm_stat_NT] = c + 0;
		p->rule.burm_stat = 1;
	}
}

static void burm_closure_assign(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_stat_NT]) {
		p->cost[burm_stat_NT] = c + 0;
		p->rule.burm_stat = 2;
	}
}

static void burm_closure_immediate(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_zeroexpr_NT]) {
		p->cost[burm_zeroexpr_NT] = c + 0;
		p->rule.burm_zeroexpr = 2;
	}
	if (c + 1 < p->cost[burm_expr_NT]) {
		p->cost[burm_expr_NT] = c + 1;
		p->rule.burm_expr = 5;
		burm_closure_expr(p, c + 1);
	}
}

static void burm_closure_expr(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_fieldchain_NT]) {
		p->cost[burm_fieldchain_NT] = c + 0;
		p->rule.burm_fieldchain = 2;
		burm_closure_fieldchain(p, c + 0);
	}
}

static void burm_closure_fieldchain(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_expr_NT]) {
		p->cost[burm_expr_NT] = c + 0;
		p->rule.burm_expr = 1;
		burm_closure_expr(p, c + 0);
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

static void burm_closure_cond(STATEPTR_TYPE p, int c) {
	if (c + 0 < p->cost[burm_stat_NT]) {
		p->cost[burm_stat_NT] = c + 0;
		p->rule.burm_stat = 9;
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
		p->cost[8] =
		p->cost[9] =
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
				p->rule.burm_expr = 7;
				burm_closure_expr(p, c + 0);
			}
		}
		break;
	case 2: /* OP_OR */
		assert(l && r);
		{	/* expr: OP_OR(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 11;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_OR(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 10;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_OR(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 9;
				burm_closure_expr(p, c + 0);
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
				p->rule.burm_immediate = 4;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NEQ(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 14;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_NEQ(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 13;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_NEQ(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 12;
				burm_closure_expr(p, c + 0);
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
				p->rule.burm_immediate = 1;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_ADD(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 4;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_ADD(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 3;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_ADD(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 2;
				burm_closure_expr(p, c + 0);
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
		{	/* expr: OP_MUL(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 17;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_MUL(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 16;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_MUL(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 15;
				burm_closure_expr(p, c + 0);
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
				p->rule.burm_immediate = 3;
				burm_closure_immediate(p, c + 0);
			}
		}
		{	/* expr: OP_NEG(expr) */
			c = l->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 21;
				burm_closure_expr(p, c + 0);
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
					32767,
					1,	/* expr: OP_ID */
					1,	/* fieldchain: expr */
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					8,	/* expr: OP_ID */
					2,	/* fieldchain: expr */
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
					32767,
					0,	/* immediate: OP_Number */
					1,	/* expr: immediate */
					1,	/* fieldchain: expr */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					0,
					7,	/* immediate: OP_Number */
					5,	/* expr: immediate */
					2,	/* fieldchain: expr */
					0,
					2,	/* zeroexpr: immediate */
					0,
				}
			};
			return &z;
		}
	case 9: /* OP_Field */
		assert(l);
		{	/* fieldchain: OP_Field(fieldchain) */
			c = l->cost[burm_fieldchain_NT] + 0;
			if (c + 0 < p->cost[burm_fieldchain_NT]) {
				p->cost[burm_fieldchain_NT] = c + 0;
				p->rule.burm_fieldchain = 1;
				burm_closure_fieldchain(p, c + 0);
			}
		}
		break;
	case 10: /* OP_Return */
		assert(l);
		{	/* ret: OP_Return(immediate) */
			c = l->cost[burm_immediate_NT] + 1;
			if (c + 0 < p->cost[burm_ret_NT]) {
				p->cost[burm_ret_NT] = c + 0;
				p->rule.burm_ret = 2;
				burm_closure_ret(p, c + 0);
			}
		}
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
					32767,
					0,	/* immediate: OP_Zero */
					1,	/* expr: immediate */
					1,	/* fieldchain: expr */
					0,	/* zero: OP_Zero */
					0,	/* zeroexpr: zero */
					32767,
				},{
					0,
					0,
					0,
					8,	/* immediate: OP_Zero */
					5,	/* expr: immediate */
					2,	/* fieldchain: expr */
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
					32767,
					0,	/* immediate: OP_One */
					1,	/* expr: immediate */
					1,	/* fieldchain: expr */
					32767,
					0,	/* zeroexpr: immediate */
					32767,
				},{
					0,
					0,
					0,
					9,	/* immediate: OP_One */
					5,	/* expr: immediate */
					2,	/* fieldchain: expr */
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
				p->rule.burm_zeroexpr = 7;
			}
		}
		{	/* expr: OP_GREATER(expr,immediate) */
			c = l->cost[burm_expr_NT] + r->cost[burm_immediate_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 20;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_GREATER(immediate,expr) */
			c = l->cost[burm_immediate_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 19;
				burm_closure_expr(p, c + 0);
			}
		}
		{	/* expr: OP_GREATER(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_expr_NT]) {
				p->cost[burm_expr_NT] = c + 0;
				p->rule.burm_expr = 18;
				burm_closure_expr(p, c + 0);
			}
		}
		break;
	case 16: /* OP_LEXPR */
		assert(l && r);
		{	/* stat: OP_LEXPR(expr,expr) */
			c = l->cost[burm_expr_NT] + r->cost[burm_expr_NT] + 3;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 8;
			}
		}
		if (	/* stat: OP_LEXPR(OP_Field(fieldchain),expr) */
			l->op == 9 /* OP_Field */
		) {
			c = l->left->cost[burm_fieldchain_NT] + r->cost[burm_expr_NT] + 1;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 7;
			}
		}
		if (	/* stat: OP_LEXPR(expr,OP_ID) */
			r->op == 7 /* OP_ID */
		) {
			c = l->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 6;
			}
		}
		if (	/* stat: OP_LEXPR(OP_ID,expr) */
			l->op == 7 /* OP_ID */
		) {
			c = r->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 5;
			}
		}
		break;
	case 17: /* OP_Assign */
		assert(l && r);
		if (	/* assign: OP_Assign(expr,OP_NOP) */
			r->op == 14 /* OP_NOP */
		) {
			c = l->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_assign_NT]) {
				p->cost[burm_assign_NT] = c + 0;
				p->rule.burm_assign = 2;
				burm_closure_assign(p, c + 0);
			}
		}
		{	/* assign: OP_Assign(expr,assign) */
			c = l->cost[burm_expr_NT] + r->cost[burm_assign_NT] + 2;
			if (c + 0 < p->cost[burm_assign_NT]) {
				p->cost[burm_assign_NT] = c + 0;
				p->rule.burm_assign = 1;
				burm_closure_assign(p, c + 0);
			}
		}
		break;
	case 18: /* OP_With */
		assert(l);
		{	/* stat: OP_With(expr) */
			c = l->cost[burm_expr_NT] + 0;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 4;
			}
		}
		{	/* stat: OP_With(immediate) */
			c = l->cost[burm_immediate_NT] + 0;
			if (c + 0 < p->cost[burm_stat_NT]) {
				p->cost[burm_stat_NT] = c + 0;
				p->rule.burm_stat = 3;
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
					32767,
					1,	/* expr: OP_Fieldvariable */
					1,	/* fieldchain: expr */
					32767,
					32767,
					32767,
				},{
					0,
					0,
					0,
					0,
					6,	/* expr: OP_Fieldvariable */
					2,	/* fieldchain: expr */
					0,
					0,
					0,
				}
			};
			return &z;
		}
	case 21: /* OP_Cond */
		assert(l && r);
		{	/* cond: OP_Cond(expr,cond) */
			c = l->cost[burm_expr_NT] + r->cost[burm_cond_NT] + 2;
			if (c + 0 < p->cost[burm_cond_NT]) {
				p->cost[burm_cond_NT] = c + 0;
				p->rule.burm_cond = 2;
				burm_closure_cond(p, c + 0);
			}
		}
		if (	/* cond: OP_Cond(expr,OP_NOP) */
			r->op == 14 /* OP_NOP */
		) {
			c = l->cost[burm_expr_NT] + 2;
			if (c + 0 < p->cost[burm_cond_NT]) {
				p->cost[burm_cond_NT] = c + 0;
				p->rule.burm_cond = 1;
				burm_closure_cond(p, c + 0);
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
	case 56: /* stat: cond */
	case 50: /* zeroexpr: immediate */
	case 49: /* zeroexpr: zero */
	case 41: /* immediate: zero */
	case 19: /* expr: immediate */
	case 10: /* fieldchain: expr */
	case 8: /* expr: fieldchain */
	case 2: /* stat: assign */
	case 1: /* stat: ret */
		kids[0] = p;
		break;
	case 57: /* cond: OP_Cond(expr,OP_NOP) */
	case 51: /* zeroexpr: OP_NEG(zeroexpr) */
	case 45: /* zero: OP_NEG(zero) */
	case 38: /* immediate: OP_NEG(immediate) */
	case 37: /* immediate: OP_NOT(immediate) */
	case 35: /* expr: OP_NEG(expr) */
	case 21: /* expr: OP_NOT(expr) */
	case 15: /* assign: OP_Assign(expr,OP_NOP) */
	case 13: /* ret: OP_Return(immediate) */
	case 12: /* ret: OP_Return(expr) */
	case 9: /* fieldchain: OP_Field(fieldchain) */
	case 6: /* stat: OP_LEXPR(expr,OP_ID) */
	case 4: /* stat: OP_With(expr) */
	case 3: /* stat: OP_With(immediate) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 5: /* stat: OP_LEXPR(OP_ID,expr) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 7: /* stat: OP_LEXPR(OP_Field(fieldchain),expr) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(p);
		break;
	case 58: /* cond: OP_Cond(expr,cond) */
	case 55: /* zeroexpr: OP_GREATER(zeroexpr,zeroexpr) */
	case 54: /* zeroexpr: OP_NEQ(zeroexpr,zeroexpr) */
	case 53: /* zeroexpr: OP_MUL(zeroexpr,zeroexpr) */
	case 52: /* zeroexpr: OP_ADD(zeroexpr,zeroexpr) */
	case 48: /* zero: OP_MUL(zero,zeroexpr) */
	case 47: /* zero: OP_MUL(zeroexpr,zero) */
	case 40: /* immediate: OP_MUL(immediate,immediate) */
	case 39: /* immediate: OP_NEQ(immediate,immediate) */
	case 36: /* immediate: OP_ADD(immediate,immediate) */
	case 34: /* expr: OP_GREATER(expr,immediate) */
	case 33: /* expr: OP_GREATER(immediate,expr) */
	case 32: /* expr: OP_GREATER(expr,expr) */
	case 31: /* expr: OP_MUL(expr,expr) */
	case 30: /* expr: OP_MUL(expr,immediate) */
	case 29: /* expr: OP_MUL(immediate,expr) */
	case 28: /* expr: OP_NEQ(immediate,expr) */
	case 27: /* expr: OP_NEQ(expr,immediate) */
	case 26: /* expr: OP_NEQ(expr,expr) */
	case 25: /* expr: OP_OR(expr,immediate) */
	case 24: /* expr: OP_OR(expr,expr) */
	case 23: /* expr: OP_OR(immediate,expr) */
	case 18: /* expr: OP_ADD(expr,immediate) */
	case 17: /* expr: OP_ADD(expr,expr) */
	case 16: /* expr: OP_ADD(immediate,expr) */
	case 14: /* assign: OP_Assign(expr,assign) */
	case 11: /* stat: OP_LEXPR(expr,expr) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 46: /* zero: OP_Zero */
	case 44: /* immediate: OP_One */
	case 43: /* immediate: OP_Zero */
	case 42: /* immediate: OP_Number */
	case 22: /* expr: OP_ID */
	case 20: /* expr: OP_Fieldvariable */
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
 
    break;
  case 11:
 REG(bnode) = newreg(); move(RC_REG(bnode), REG(bnode)); move(REG(bnode), LC_REG(bnode)); 
    break;
  case 12:
 move(LC_REG(bnode), "%rax"); ret();
    break;
  case 13:
 movei(LEFT_CHILD(bnode)->value, "%rax"); ret();
    break;
  case 14:
 move(LC_REG(bnode), REG(bnode) ); 
    break;
  case 15:
 move(LC_REG(bnode), REG(bnode) ); 
    break;
  case 16:
 synth_reg(bnode, RIGHT_CHILD(bnode)); addi(LEFT_CHILD(bnode)->value, REG(bnode));
    break;
  case 30:
 synth_reg(bnode, LEFT_CHILD(bnode)); muli(RIGHT_CHILD(bnode)->value, REG(bnode));
    break;
  case 17:
 synth_reg(bnode, RIGHT_CHILD(bnode)); add(LC_REG(bnode), REG(bnode));
    break;
  case 31:
 synth_reg(bnode, RIGHT_CHILD(bnode)); mul(LC_REG(bnode), REG(bnode));
    break;
  case 18:
 synth_reg(bnode, LEFT_CHILD(bnode)); addi(RIGHT_CHILD(bnode)->value, REG(bnode));
    break;
  case 32:
 synth_reg(bnode, RIGHT_CHILD(bnode)); greater(LC_REG(bnode), RC_REG(bnode), REG(bnode));
    break;
  case 19:
 REG(bnode) = newreg(); movei(bnode->value, REG(bnode));
    break;
  case 33:
 synth_reg(bnode, RIGHT_CHILD(bnode)); greateri(LEFT_CHILD(bnode)->value, RC_REG(bnode), REG(bnode));
    break;
  case 34:
 synth_reg(bnode, LEFT_CHILD(bnode)); greateri(RIGHT_CHILD(bnode)->value, LC_REG(bnode), REG(bnode));
    break;
  case 35:
 synth_reg(bnode, LEFT_CHILD(bnode)); neg(bnode->reg);
    break;
  case 36:
 bnode->value = LEFT_CHILD(bnode)->value + bnode->child[1]->value;
    break;
  case 50:

    break;
  case 37:
 bnode->value = ! LEFT_CHILD(bnode)->value;
    break;
  case 51:

    break;
  case 38:
 bnode->value = - LEFT_CHILD(bnode)->value;
    break;
  case 52:

    break;
  case 39:
 bnode->value = (LEFT_CHILD(bnode)->value != bnode->child[1]->value)? 1 : 0;
    break;
  case 53:

    break;
  case 54:

    break;
  case 55:
 
    break;
  case 56:

    break;
  case 1:

    break;
  case 57:
	cond(LC_REG(bnode), bnode->value);
    break;
  case 2:

    break;
  case 58:
	cond(LC_REG(bnode), bnode->value);
    break;
  case 3:
 REG(bnode) = newreg(); movei(bnode->child[0]->value, REG(bnode));
    break;
  case 4:
 REG(bnode) = newreg(); move(LC_REG(bnode), REG(bnode)); freereg(LC_REG(bnode));
    break;
  case 5:
 move(RC_REG(bnode), getRegister(LEFT_CHILD(bnode)->name));
    break;
  case 6:
 move(getRegister(RIGHT_CHILD(bnode)->name), LC_REG(bnode));
    break;
  case 7:
 move_to_relative(RC_REG(bnode), LC_REG(LEFT_CHILD(bnode)), LEFT_CHILD(bnode)->offset);
    break;
  case 8:
 
    break;
  case 9:
 REG(bnode) = newreg(); move_from_relative(LC_REG(bnode), REG(bnode), bnode->offset);
    break;
  case 20:
 REG(bnode) = getRegister(bnode->name);
    break;
  case 21:
 synth_reg(bnode, LEFT_CHILD(bnode)); not(bnode->reg); 
    break;
  case 22:
 REG(bnode) = getRegister(bnode->name);
    break;
  case 23:
 synth_reg(bnode, RIGHT_CHILD(bnode)); ori(LEFT_CHILD(bnode)->value, REG(bnode));
    break;
  case 24:
 synth_reg(bnode, RIGHT_CHILD(bnode)); or(LC_REG(bnode), REG(bnode));
    break;
  case 25:
 synth_reg(bnode, LEFT_CHILD(bnode)); ori(RIGHT_CHILD(bnode)->value, REG(bnode));
    break;
  case 26:
 synth_reg(bnode, RIGHT_CHILD(bnode)); notequal(LC_REG(bnode), RC_REG(bnode), REG(bnode));
    break;
  case 40:
 bnode->value = LEFT_CHILD(bnode)->value * bnode->child[1]->value;
    break;
  case 27:
 synth_reg(bnode, LEFT_CHILD(bnode)); notequali(RIGHT_CHILD(bnode)->value, LC_REG(bnode), REG(bnode));
    break;
  case 41:
 bnode->value = 0;
    break;
  case 28:
 synth_reg(bnode, RIGHT_CHILD(bnode)); notequali(LEFT_CHILD(bnode)->value, RC_REG(bnode), REG(bnode));
    break;
  case 42:
 
    break;
  case 29:
 synth_reg(bnode, RIGHT_CHILD(bnode)); muli(LEFT_CHILD(bnode)->value, REG(bnode));
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
