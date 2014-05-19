#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define EMPTY_TABLE (struct symbol_t *) NULL
#define UNIQUE 1
#define NOT_UNIQUE 0

struct symbol_t {
	char *name;
	struct symbol_t *next;
	short type;
	int stack_offset;
	int usage_count;
	int param_index;
};

void debug_symbol_table(struct symbol_t *);
struct symbol_t *table_lookup(struct symbol_t*, char*);
struct symbol_t *add_symbol(struct symbol_t*, char*, short, int);

#endif

