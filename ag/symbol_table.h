#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define EMPTY_TABLE (struct symbol_t *) NULL
#define UNIQUE 1
#define NOT_UNIQUE 0



/*
#define PARAMETER_SYMBOL 1
#define TYPE_STRUCT 1
#define TYPE_FELDNAME 2
#define TYPE_STRUKTURNAME 3
#define TYPE_FUNKTIONSNAME 4
#define TYPE_LET_ID 5
#define TYPE_PARAMNAME 6

*/

struct symbol_t {
	char *name;
	struct symbol_t *next;
};

struct struct_table{
	char *name;
	struct symbol_t *fields;
	struct struct_table *next;
};


struct symbol_t *table_lookup(struct symbol_t*, char*);
struct symbol_t *add_symbol(struct symbol_t*, char*, short);
struct struct_table* add_struct(struct struct_table*, char*, struct symbol_t*);
void assert_exists(struct struct_table *, struct symbol_t *, struct symbol_t *, char* );
struct symbol_t * load_struct(struct struct_table* , struct symbol_t* , char* );

/*struct symbol_t * load_struct(struct struct_table*, struct symbol_t*, char*);*/

/*Was soll man mit den Table anstelln koennen
struct symbol_t *new_table(void);
struct symbol_t *table_merge(struct symbol_t *table_one, struct symbol_t *table_two);
struct symbol_t* add_feldname(struct symbol_t *table, char *name);
struct symbol_t* tag_struct_elements(struct symbol_t *table, char *struct_name);
struct symbol_t* filter_feldnamen(struct symbol_t* feldnamen, char *struct_name);
void exists(struct symbol_t *param_context, struct symbol_t *struct_context, struct symbol_t *feldnamen, char *identifier);
void table_info(struct symbol_t *table);
struct symbol_t *assert_contains(struct symbol_t *table, char *identifier);


void debug(char *);
*/

#endif

