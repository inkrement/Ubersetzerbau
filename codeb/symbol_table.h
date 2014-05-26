#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define EMPTY_TABLE (struct symbol_t *) NULL
#define TRUE 1
#define FALSE 0
#define UNIQUE 1
#define NOT_UNIQUE 0

#define TYPE_FIELD 0
#define TYPE_PARAM 1
#define TYPE_VAR 2

struct symbol_t {
	char *name;
	struct symbol_t *next;
	short type;
	int offset;
	int param_index;
	char* reg;
};

void debug_symbol_table(struct symbol_t *);
struct symbol_t *table_lookup(struct symbol_t*, char*);
struct symbol_t* add_symbol(struct symbol_t *, char *, short , int , int , char*, int );
struct symbol_t* add_var(struct symbol_t *, char *, char* );
struct symbol_t* add_field(struct symbol_t *, char *, int);
struct symbol_t* add_param(struct symbol_t *, char *, int );

#endif

