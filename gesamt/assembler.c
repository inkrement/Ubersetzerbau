#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assembler.h"

char *param_regs[]={"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
char *regs[]= {"%rax", "%r10", "%r11", "%r9", "%r8", "%rcx", "%rdx", "%rsi", "%rdi"};
var_usage *vars = (var_usage *) NULL;

long if_id = 0;

long get_if_id() {
  return ++if_id;
}

void print_cond_label(int val){
  if(val==0) printf("\tjmp cond_%li\n", if_id + 1);
  printf("cond_%d:\n", val + 1);
}

/*
  returns 1 if reg is used
  retunns 0 if not
*/
short isUsed(char* reg){
  var_usage *i = vars;

  while(i != NULL){
    if(0 == strcmp(i->reg, reg)) return 1;
    i=i->next;
  }

    return 0;
}

void setRegister(char* symbol, char* reg){
  var_usage *var = vars;
  int i;

  #ifdef DEBUG_ME
    printf("set register %s for symbol %s\n", reg, symbol);
  #endif

  /*find register*/
  while(var != NULL){
    if (var->symbol_name == NULL) {
      var= var->next;
      continue;
    }
    if(0==strcmp(var->symbol_name, symbol)){
      var->reg=reg;
      return;
    }
    var= var->next;
  }

  for(i=0;i<10;i++){
    if(i==9){
      /*printf("This should never happen! register %s does not exist!\n", reg);
      exit(4);*/
      break;
    }
    if(0 == strcmp(regs[i], reg)) break;
  }

  var = (var_usage *) malloc(sizeof(var_usage));
  var->next = vars;
  var->symbol_name = symbol;
  var->reg = reg;
  var->tmp = 0;
  vars = var;
}


char *getRegister(char* symbol){
  var_usage *loop = vars;

  #ifdef DEBUG_ME
    printf("get register for %s\n", symbol);
    debug_reg_usage(vars);
  #endif

    while(loop != NULL){
      if(loop->symbol_name == (char*) NULL){
        loop = loop->next;
        continue;
      }
      if(0 == strcmp(loop->symbol_name, symbol)) {

        #ifdef DEBUG_ME
          printf("found register %s for %s\n",loop->reg, symbol);
        #endif

        return loop->reg;
      }
      loop = loop->next;
    }

    printf("could not find register for symbol %s\n", symbol);
    exit(4);
}

short isTmpReg(char *regname){
  var_usage *loop = vars;

  #ifdef DEBUG_ME
    printf("test if register is only a temporary one for %s\n", regname);
    debug_reg_usage(vars);
  #endif

    while(loop != NULL){
      if(0 == strcmp(loop->reg, regname)) {

        #ifdef DEBUG_ME
          printf("found register-usage from %s\n", regname);
        #endif

        return loop->tmp;
      }
      loop = loop->next;
    }

    return 0;
}


void debug_reg_usage(var_usage* usage){
  var_usage *loop = vars;
  printf("REGISTER usage:\n");
  while(loop != NULL){
    printf("%s: %s\n", loop->symbol_name, loop->reg);
    loop = loop->next;
  }
}

void ret(void) {
    if_id = 0;
  printf("\tret\n");
}

char *getByteRegister(char *name){
	char *registers[]={"%rax", "%r11", "%r10", "%r9", "%r8", "%rcx", "%rdx", "%rsi", "%rdi"};
	char *byteRegisters[]={"%al", "%r11b", "%r10b", "%r9b", "%r8b", "%cl", "%dl", "%sil", "%dil"};
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
	char *registers[]={"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

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
  vars = (var_usage *) NULL;

  printf("\n\t.globl %s\n\t.type %s, @function\n%s:\n", name, name, name);
}


/* register functions */
void freereg(char *reg) {
  var_usage *reg_usage = vars;
  var_usage *old = vars;

  #ifdef DEBUG_ME
    printf("free %s\n", reg);
  #endif

  if(reg_usage != (var_usage *) NULL){
    if(0 == strcmp(reg_usage->reg, reg)){
        vars = vars->next;
        return;
    }

    reg_usage = reg_usage->next;
  }

  while(reg_usage != (var_usage *) NULL){

    if(0 == strcmp(reg_usage->reg, reg) ){
      old->next = reg_usage->next;
      return;
    }

    reg_usage = reg_usage->next;
    old = old->next;
  }

}

void reg_usage_inc(char* reg){
  var_usage *reg_usage = vars;

  /* try to find reg */
  while(reg_usage != (var_usage *) NULL){
    if(reg_usage->reg != (char*) NULL){
      if(0 == strcmp(reg_usage->reg, reg)){
        reg_usage->usage_count++;
        break;
      }
    } 
    reg_usage=reg_usage->next;
  }
}


char* newreg() {
  int i = 0;
  var_usage *var;

  /** TODO remove regusage and use ony vars */


  while(i < 9 && isUsed(regs[i])) {
    ++i;
  }

  if(isUsed(regs[i])) {
    printf("not enough registers!\n");
    exit(4);
  }

  var = (var_usage *)malloc(sizeof(var_usage));
  var->symbol_name = (char*) NULL;
  var->usage_count = 1;
  var->next = vars;
  var->tmp = 1;
  var->reg = regs[i];
  vars = var;

  #ifdef DEBUG_ME
    printf("new Register %s allocated\n", var->reg);
  #endif

  return regs[i];
}

char* get_op_register(char* reg){
  if(isTmpReg(reg)){
    return reg;
  }
  else{
    return newreg();
  }
}


void retrn(void) {
	printf("\tret\n");
}


/* function call helpers */
void save_regs() {
  int i;

  printf("/************** start function call **************/\n");
  printf("/* save registers */\n");
  for(i = 0; i < 9; ++i) {
    if(isUsed(regs[i])) {
      printf("\tpush %s\n", regs[i]);
    }  
  }
}

void restore_regs() {
  int i;
  printf("/* restore registers */\n");
  for(i = 8; i >= 0; --i) {
    if(isUsed(regs[i])) {
      printf("\tpop %s\n", regs[i]);
    }  
  }


  printf("/*************** end of function call ***************/\n");
}

void call_func(char* name) {
  printf("/* call %s */\n", name);
  printf("\tcall %s\n", name);
}

void claimreg(char *reg) {
  int i = 0;

  while( strcmp(reg, regs[i]) != 0 ) {
    ++i;
  }

  if( strcmp(reg, regs[i]) != 0) {
    printf("unknown regigster: %s\n", reg);
    exit(4);
  }

  reg_usage_inc(regs[i]);
}





void move(char *src, char *dst) {
#ifdef DEBUG_ME
  if(src == NULL || dst == NULL) {
    printf("null register! src: %s, dst: %s\n", src, dst);
  }
#endif

  if(strcmp(src,dst)) {
    printf("\tmovq %s, %s\n",src,dst);
  } 
#ifdef DEBUG_ME 
  else {
    printf("didn't move %s to %s\n", src, dst);
  }
#endif

}


void move_from_relative(char *src, char *dst, int offset) {
#ifdef DEBUG_ME
  if(src == NULL || dst == NULL) {
    printf("null register! src: %s, dst: %s\n", src, dst);
  }
#endif
    printf("\tmovq %d(%s), %s\n", offset * FIELD_OFFSET, src, dst);
}

void move_to_relative(char *src, char *dst, int offset) {
#ifdef DEBUG_ME
  if(src == NULL || dst == NULL) {
    printf("null register! src: %s, dst: %s\n", src, dst);
  }
#endif
    printf("\tmovq %s, %d(%s)\n", src, offset * FIELD_OFFSET, dst);
}

void movei(long value, char *reg){
	printf("\tmovq $%d, %s\n", (int) value, reg);
}

void add(char *src, char *dst){
	printf("\taddq %s, %s\n", src, dst);
}

void addi(long value, char *dst){
	if(value != 0)
		printf("\taddq $%d, %s\n", (int) value, dst);
}

void mul(char *src, char *dst){
	printf("\timulq %s, %s\n", src, dst);
}

void muli(long value, char *dst){
	if(value != 1)
		printf("\timulq $%d, %s\n",(int) value, dst);
}

void and(char *fst, char *snd){
	if(strcmp(fst,snd))
		printf("\tand %s, %s\n",fst,snd);
}

void andi(long fst, char *snd){
	printf("\tand $%li, %s\n",fst, snd);
}

void or(char *fst, char *snd){
	if(strcmp(fst,snd))
		printf("\tor %s, %s\n",fst,snd);
}

void ori(long fst, char *snd){
	printf("\tor $%d, %s\n",(int) fst, snd);
}

void neg(char *reg){
	printf("\tnegq %s\n", reg);
}

void not(char *reg){
	printf("\tnotq %s\n", reg);
}

void smallerequal(char *fst, char *snd, char* dst){
  printf("\t# smallerequal\n");

	printf("\tcmp %s, %s\n", fst, snd);
	printf("\tsetle %s\n",getByteRegister(dst));
	printf("\tand $1, %s\n",dst);
}

void smallerequali(long fst, char *snd, char *dst){
  printf("\t# smallerequali\n");

	printf("\tcmp $%li, %s\n", fst, snd);
	printf("\tsetle %s\n",getByteRegister(dst));
	printf("\tand $1, %s\n",dst);
}

void smallerequali2(char *fst, long snd, char *dst){
  printf("\t# smallerequali2\n");

	printf("\tcmp $%li, %s\n", snd, fst);
	printf("\tsetnle %s\n", getByteRegister(dst));
	printf("\tand $1, %s\n", dst);
}

void address(char *src, char *dst){
	printf("\tmovq (%s), %s\n", src, dst);
}

void addressi(long src, char *dst){
	printf("\tmovq ($%li), %s\n", src, dst);
}

void notequal(char *fst, char *snd, char *dst){
	printf("\tcmp %s, %s\n", fst, snd);
	printf("\tsetne %s\n",getByteRegister(dst));
	printf("\tand $1, %s\n",dst);
	printf("\tneg %s\n", dst);
}

void notequali(long fst, char *snd, char *dst){
	printf("\tcmpq $%d, %s\n", (int) fst, snd);
	printf("\tsetne %s\n",getByteRegister(dst));
	printf("\tand $1, %s\n",dst);
	printf("\tneg %s\n", dst);
}

void notequali2(char *fst, long snd, char *dst){
	printf("\tcmpq $%s, %d\n", fst, (int) snd);
	printf("\tsetne %s\n",getByteRegister(dst));
	printf("\tand $1, %s\n",dst);
	printf("\tneg %s\n", dst);
}

char* gettmpReg2(char* blackitem, char* blackitem2){
  int i=0;

  while(0 == strcmp(regs[i], blackitem) || 0 == strcmp(regs[i], blackitem2)) i++;
  return regs[i];
}

char* gettmpReg3(char* blackitem, char* blackitem2, char* blackitem3){
  int i=0;

  while(0 == strcmp(regs[i], blackitem) || 0 == strcmp(regs[i], blackitem2) || 0 == strcmp(regs[i], blackitem3)) i++;
  return regs[i];
}

void push(char* reg){
  printf("\tpush %s\n", reg);
}

void pop(char* reg){
  printf("\tpop %s\n", reg);
}

/**
 * moves the greatest operand to dst
 */
void greater(char *fst, char *snd, char *dst){
  char* tmp = gettmpReg3(fst, snd, dst);
  printf("\t# greater\n");
  push(tmp);

  printf("\tmovq $0, %s\n", dst);
  printf("\tmovq $-1, %s\n", tmp);
  printf("\tcmpq %s, %s\n", snd, fst);
  printf("\tcmovgq %s, %s\n", tmp, dst);

  pop(tmp);
}

void greateri(long fst, char *snd, char *dst){
  char* tmp = gettmpReg2(snd, dst);
  printf("\t# greateri between %li and %s to %s (reg & imm)\n", fst, snd, dst);
  push(tmp);

  printf("\tmovq $0, %s\n", dst);
  printf("\tmovq $-1, %s\n", tmp);

  printf("\tcmpq $%d, %s\n",(int) fst, snd);
  printf("\tcmovlq %s, %s\n", tmp, dst);

  pop(tmp);
}

void greateri2(char *fst, long snd, char *dst){
  char* tmp = gettmpReg2(fst, dst);
  printf("\t# greateri2\n");
  push(tmp);

  printf("\tmovq $0, %s\n", dst);
  printf("\tmovq $-1, %s\n", tmp);

  /* cmpq is like sub just without storing the result.
    flags = snd - fst */
  printf("\tcmpq $%d, %s\n", (int) snd, fst);

  /* le instead of g because first operand has to be the imm*/
  printf("\tcmovgq %s, %s\n", tmp, dst);
  pop(tmp);
}


void cond(char* condition, int num){
  printf("\tcmp $0, %s\n", condition);
  printf("\tjl cond_%d\n", num);
}
