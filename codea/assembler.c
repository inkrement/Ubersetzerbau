#include <stdio.h>
#include <string.h>
#include "assembler.h"

void functionStart(char *name) {
	printf(".globl %s\n", name);
	printf("\t.type %s, @function\n", name);
	printf("%s:\n",name);
}

char *nextRegister(char *name) {
	char *registers[]={"rax", "r11", "r10", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
	int index, i;
	if(name==(char *)NULL) {
		index=0;
	}
	else {
		for(i=0;i<9;i++) {
			if(!strcmp(name,registers[i])) {
				index=i+1;
				break;
			}
		}
	}
	return registers[index];
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
	#ifdef DEBUG_ME
	    printf("get param register with index: %d (%s)\n", index, registers[index]);
	#endif

	return registers[index];
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
    printf("\tmovq (%%%s,%d,8), %%%s\n",src, offset, dst);
}

void movei(long value, char *reg){
	printf("\tmovq $%li, %%%s\n", value, reg);
}

void add(char *src, char *dst){
	printf("\taddq %%%s, %%%s\n", src, dst);
}

void addi(long value, char *dst){
	if(value != 0)
		printf("\taddq $%li, %%%s\n", value, dst);
}

void mul(char *src, char *dst){
	printf("\timulq %%%s, %%%s\n", src, dst);
}

void muli(long value, char *dst){
	if(value != 1)
		printf("\timulq $%li, %%%s\n", value, dst);
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
	printf("\tor $%li, %%%s\n",fst, snd);
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


void loadfield(char *fieldname, int offset, char* reg){
	printf("\tmovq %s+%d(%%rip), %%%s\n", fieldname, offset, reg);
}


void setfield(char *fieldname, int offset, char* reg){
	printf("\tmovq %%%s, %s+%d(%%rip)\n", reg, fieldname, offset);
}

void notequal(char *fst, char *snd, char *dst){
	printf("\tcmp %%%s, %%%s\n", fst, snd);
	printf("\tsetne %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void notequali(long fst, char *snd, char *dst){
	printf("\tcmpq $%li, %%%s\n", fst, snd);
	printf("\tsetne %%%s\n",getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void notequali2(char *fst, long snd, char *dst){
	printf("\tcmpq $%s, %%%li\n", fst, snd);
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
	printf("\tcmp %%%li, %%%s\n", fst, snd);
	printf("\tsetg %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}

void greateri2(char *fst, long snd, char *dst){
	printf("\tcmp %%%s, %%%li\n", fst, snd);
	printf("\tsetg %%%s\n", getByteRegister(dst));
	printf("\tand $1, %%%s\n",dst);
	printf("\tneg %%%s\n", dst);
}