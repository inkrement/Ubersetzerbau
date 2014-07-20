#ifndef STRUCT_TABLE_H
#define STRUCT_TABLE_H

#include "symbol_table.h"
#define NO_STRUCT (struct struct_table*) NULL

struct struct_table{
	char *name;
	struct symbol_t *fields;
	struct struct_table *next;
};

struct symbol_t *table_clone(struct symbol_t *);
struct symbol_t *table_merge(struct symbol_t *, struct symbol_t *);
struct struct_table* add_struct(struct struct_table*, char*, struct symbol_t*);

void check_struct_exists(struct struct_table *, char *);
void debug_struct_table(struct struct_table *);
struct symbol_t * load_struct(struct struct_table* , struct symbol_t* , char*);
void assert_exists_feldkontext(struct struct_table *, struct symbol_t *, char* );
void assert_single_occurence(struct struct_table *, struct symbol_t *, struct symbol_t *);
void assert_exists(struct symbol_t *, char* );
void assert_unused_fieldname(struct struct_table*, char *);
void assert_unused_fieldnames(struct struct_table* , struct symbol_t* );

struct struct_table* get_struct_by_field(struct struct_table* , char *);
struct struct_table* get_struct_by_name(struct struct_table*, char *);
int get_field_offset(struct struct_table* , char *);


#endif