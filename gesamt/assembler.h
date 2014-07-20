#ifndef __ASSEMBLER_H__
#define __ASSEMBLER_H__
#include "symbol_table.h"

#define FIELD_OFFSET 8
#define LEFT_CHILD(p) ((p)->child[0])
#define RIGHT_CHILD(p) ((p)->child[1])
#define REG(p) ((p)->reg)
#define LC_REG(p) ((p)->child[0]->reg)
#define RC_REG(p) ((p)->child[1]->reg)

struct reg_usage {
  char *symbol_name;
  char *reg;
  struct reg_usage *next;
  int usage_count;
  short tmp;
};

typedef struct reg_usage var_usage;

extern char *param_regs[];
extern char *regs[];
extern var_usage *vars;


void print_cond_label(int);
short isUsed(char*);
void setRegister(char*, char*);
char *getRegister(char*);
short isTmpReg(char *);
void debug_reg_usage(var_usage*);
void ret(void);
char *getByteRegister(char *);
char *getParamRegister(int);
char *strclone(char*);
int count(struct symbol_t*);
void function_header(char *, struct symbol_t *);
void freereg(char *);
void reg_usage_inc(char* );
char* newreg();
char* get_op_register(char*);
void retrn(void);
void save_regs();
void restore_regs();
void call_func(char*);
void claimreg(char *);
void move(char *, char *);
void move_from_relative(char *, char *, int);
void move_to_relative(char *, char *, int );
void movei(long , char *);
void add(char *, char *);
void addi(long , char *);
void mul(char *, char *);
void muli(long , char *);
void and(char *, char *);
void andi(long , char *);
void or(char *, char *);
void ori(long , char *);
void neg(char *);
void not(char *);
void smallerequal(char *, char *, char* );
void smallerequali(long , char *, char *);
void smallerequali2(char *, long , char *);
void address(char *, char *);
void addressi(long , char *);
void notequal(char *, char *, char *);
void notequali(long , char *, char *);
void notequali2(char *, long , char *);
char* gettmpReg2(char* , char* );
char* gettmpReg3(char* , char* , char* );
void push(char* );
void pop(char* );
void greater(char *, char *, char *);
void greateri(long , char *, char *);
void greateri2(char *, long , char *);
void cond(char* , int );

#endif