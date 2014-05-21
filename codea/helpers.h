#ifndef _HELPERS_H_
#define _HELPERS_H_

#include "tree.h"
#include "symbol_table.h"
#include "struct_table.h"

struct var_usage {
  char *name;
  char *reg;
  struct var_usage *next;
  int usage_count;
};

typedef struct var_usage var_usage;


void init_reg_usage();
void function_header(char *name, struct symbol_t *params);
char *get_next_reg(char *name, int skip_reg);
void record_var_usage(char* name);
void dump_usage();

#endif