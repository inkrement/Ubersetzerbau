#ifndef __ASSEMBLER_H__
#define __ASSEMBLER_H__

void functionStart(char *name);
char *nextRegister(char *name);
char *getParamRegister(int number);
void retrn(void);
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
void and(char *fst, char *snd);
void andi(long fst, char *snd);
void or(char *fst, char *snd);
void ori(long fst, char *snd);
void address(char *src, char *dst);
void addressi(long value, char *dst);
void move_offset(char *src, char *dst, int offset);

#endif