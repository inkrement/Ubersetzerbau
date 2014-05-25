#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assembler.h"


char cur_function[100];
char *regs[]= {"rax", "r10", "r11", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
int reg_usage[] = {0,     0,     0,    0,    0,     0,     0,     0,     0};
char *param_regs[]={"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
var_usage *vars = (var_usage *) NULL;

void ret(void) {
  printf("\tret\n");
}

void functionStart(char *name) {
	printf(".globl %s\n", name);
	printf("\t.type %s, @function\n", name);
	printf("%s:\n",name);
}

char *getByteRegister(char *name){
	char *registers[]={"rax", "r11", "r10", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
	char *byteRegisters[]={"al", "r11b", "r10b", "r9b", "r8b", "cl", "dl", "sil", "dil"};
	int index,i;
	if(name==(char *)NULL){
		index=0;
	}
	else{
		for(i=0;i<9;i++){
			if(!strcmp(name,registers[i])){
				index=i;
				break;
			}
		}
	}
	return byteRegisters[index];
}

char *getParamRegister(int index) {
	char *registers[]={"rdi", "rsi", "rdx", "rcx", "r8", "r9"};

  if(index > 5){
    printf("getParamRegister. Not able to get register for index: %d\n", index);
    exit(4);
  }

  #ifdef DEBUG_ME
      printf("get param register with index: %d (%s)\n", index, registers[index]);
  #endif

	return registers[index];
}


char *strclone(char* str){
  char* ptr2 = (char*) malloc(strlen(str)+1);
  strcpy(ptr2, str);

  return ptr2;
}


int count(struct symbol_t* symbols){
  int i;
  for(i=0;symbols != EMPTY_TABLE;i++)
    symbols = symbols->next;

  return i;
}


void function_header(char *name, struct symbol_t *params) {
  int i;
  var_usage *end;
  struct symbol_t *cur_parm = params;

  /* clean regs */
  for(i = 0; i < 9; ++i)
    reg_usage[i] = 0;  

  /* init params */
  vars = NULL;

  i = 0;
  
  while(cur_parm != EMPTY_TABLE) {
    var_usage *var = (var_usage *) malloc(sizeof(var_usage));
    var->name = strclone(cur_parm->name);
    var->usage_count = 0;
    var->reg = strclone( param_regs[i] );

    if(vars == NULL) {
      vars = var;
      end = vars;
    } else {
      end->next = var;
      end = end->next;
    }

    cur_parm = cur_parm->next;
  }

  init_reg_usage();
  printf("\n\t.globl %s\n\t.type %s, @function\n%s:\n", name, name, name);

  /* store name of current function to prefix jump labels */
  strcpy(cur_function, name);
}


/* register functions */
void freereg(char *reg) {
  int i = 0;

  while( strcmp(reg, regs[i]) != 0 ) {
    ++i;
  }

  if( strcmp(reg, regs[i]) != 0) {
    printf("unknown regigster: %s\n", reg);
    exit(4);
  }

  reg_usage[i] -= 1;
}


char* newreg() {
  int i = 0;

  while(i < 9 && reg_usage[i] != 0) {
    ++i;
  }

  if(reg_usage[i] != 0) {
    printf("not enough registers!\n");
    exit(4);
  }

  reg_usage[i] = 1;
  return regs[i];
}



void imm_ret(void) {
  printf("\tmovq $0, %%rax\n\tret\n");
}


/* called once for each time a variable is seen */
void record_var_usage(char* name) {
  var_usage *cur_var = vars;
  var_usage *prev;

  while(cur_var != NULL && strcmp(cur_var->name, name) != 0) {
    prev = cur_var;
    cur_var = cur_var->next;
  }

  if(cur_var == NULL) {
    /* var is not in our list yet */
    var_usage *var = (var_usage *)malloc(sizeof(var_usage));
    var->name = strclone(name);
    var->usage_count = 1;

    if(vars == NULL) {
      vars = var;
    } else {
      prev->next = var;
    }
  }
  else {
    cur_var->usage_count += 1;
  }

}


void init_reg_usage() {
  var_usage *cur_var = vars;
  int i;

  /*
  while(cur_var != (var_usage *) NULL) {
    i = 0;

    if(cur_var->reg == NULL) {
      printf("error: var has no register - %s\n", cur_var->name);
      exit(4);
    }
    while( strcmp(cur_var->reg, regs[i]) != 0 ) {
      ++i;
    }

    reg_usage[i] = cur_var->usage_count;
    cur_var = cur_var->next;
  }*/
}

void retrn(void) {
	printf("\tret\n");
}

void move(char *src, char *dst) {
#ifdef DEBUG_ME
  if(src == NULL || dst == NULL) {
    printf("null register! src: %d, dst: %d\n", src, dst);
  }
#endif

  if(strcmp(src,dst)) {
    printf("\tmovq %%%s, %%%s\n",src,dst);
  } 
#ifdef DEBUG_ME 
  else {
    printf("didn't move %s to %s", src, dst);
  }
#endif

}


void move_offset(char *src, char *dst, int offset) {
#ifdef DEBUG_ME
  if(src == NULL || dst == NULL) {
    printf("null register! src: %d, dst: %d\n", src, dst);
  }
#endif
    printf("\tmovq %d(%%%s), %%%s\n", offset*8, src, dst);
}

void movei(long value, char *reg){
	printf("\tmovq $%d, %%%s\n", (int) value, reg);
}

void add(char *src, char *dst){
	printf("\taddq %%%s, %%%s\n", src, dst);
}

void addi(long value, char *dst){
	if(value != 0)
		printf("\taddq $%d, %%%s\n", (int) value, dst);
}

void mul(char *src, char *dst){
	printf("\timulq %%%s, %%%s\n", src, dst);
}

void muli(long value, char *dst){
	if(value != 1)
		printf("\timulq $%d, %%%s\n",(int) value, dst);
}

void and(char *fst, char *snd){
	if(strcmp(fst,snd))
		printf("\tand %%%s, %%%s\n",fst,snd);
}

void andi(long fst, char *snd){
	printf("\tand $%li, %%%s\n",fst, snd);
}

void or(char *fst, char *snd){
	if(strcmp(fst,snd))
		printf("\tor %%%s, %%%s\n",fst,snd);
}

void ori(long fst, char *snd){
	printf("\tor $%d, %%%s\n",(int) fst, snd);
}

void neg(char *reg){
	printf("\tnegq %%%s\n", reg);
}

void not(char *reg){
	printf("\tnotq %%%s\n", reg);
}

void smallerequal(char *fst, char *snd, char* dst){
	printf("\tcmp %%%s, %%%s\n", fst, snd);
	printf("\tsetle %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
}

void smallerequali(long fst, char *snd, char *dst){
	printf("\tcmp $%li, %%%s\n", fst, snd);
	printf("\tsetle %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
}

void smallerequali2(char *fst, long snd, char *dst){
	printf("\tcmp $%li, %%%s\n", snd, fst);
	printf("\tsetnle %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n", dst);
}

void address(char *src, char *dst){
	printf("\tmovq (%%%s), %%%s\n", src, dst);
}

void addressi(long src, char *dst){
	printf("\tmovq ($%li), %%%s\n", src, dst);
}

void notequal(char *fst, char *snd, char *dst){
	printf("\tcmp %%%s, %%%s\n", fst, snd);
	printf("\tsetne %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void notequali(long fst, char *snd, char *dst){
	printf("\tcmpq $%d, %%%s\n", (int) fst, snd);
	printf("\tsetne %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void notequali2(char *fst, long snd, char *dst){
	printf("\tcmpq $%s, %%%d\n", fst, (int) snd);
	printf("\tsetne %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}


void greater(char *fst, char *snd, char *dst){
	printf("\tcmp %%%s, %%%s\n", fst, snd);
	printf("\tsetg %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void greateri(long fst, char *snd, char *dst){
	printf("\tcmp $%d, %%%s\n", (int) fst, snd);
	printf("\tsetg %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void greateri2(char *fst, long snd, char *dst){
  printf("\tcmp $%d, %%%s\n", (int) snd, fst);
	printf("\tsetg %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}