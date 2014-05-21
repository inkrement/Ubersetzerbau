#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

char cur_function[100];
char *regs[]= {"rax", "r10", "r11", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
int reg_usage[] = {0,     0,     0,    0,    0,     0,     0,     0,     0};
char *param_regs[]={"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
var_usage *vars;

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

char *get_next_reg(char *name, int skip_reg) {
  char *reg_names[]={"rax", "r10", "r11", "r9", "r8", "rcx", "rdx", "rsi", "rdi"};
  int index, a;

  if(name==(char *)NULL) {
    index=0;
  }
  else {
    for(a=0;a<9;a++) {
      if(!strcmp(name,reg_names[a])) {
        index=a+1;
        break;
      }
    }
  }
  if(skip_reg) {
    index++;
  }



  #ifdef DEBUG_ME
    printf("get_next_reg: %s\n",reg_names[index]);
  #endif

  return reg_names[index];
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

  while(cur_var != NULL) {
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
  }
}