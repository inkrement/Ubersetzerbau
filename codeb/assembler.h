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

char *strclone(char*);

void init_reg_usage();
void function_header(char *name, struct symbol_t *params);
char *get_next_reg(char *name, int skip_reg);
void record_var_usage(char* name);

char *getRegister(char*);
void setRegister(char*, char*);

char *getParamRegister(int number);
void ret(void);

void move(char *src, char *dst);
void movei(long value, char *dst);
void add(char *scr, char *dst);
void addi(long value, char *dst);
void mul(char *scr, char *dst);
void muli(long value, char *dst);
void neg(char *reg);
void not(char *reg);
void smallerequal(char *fst, char *snd, char* dst);
void smallerequali(long value, char *fst, char *dst);
void smallerequali2(char *fst, long snd, char *dst);
void notequal(char *fst, char *snd, char *dst);
void notequali(long value, char *fst, char *dst);
void notequali2(char *fst, long snd, char *dst);
void and(char *fst, char *snd);
void andi(long fst, char *snd);
void or(char *fst, char *snd);
void ori(long fst, char *snd);
void address(char *src, char *dst);
void addressi(long value, char *dst);
void move_offset(char *src, char *dst, int offset);

void greater(char *fst, char *snd, char *dst);
void greateri(long value, char *fst, char *dst);
void greateri2(char *fst, long snd, char *dst);

#endif