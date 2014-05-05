#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define PARAMETER_SYMBOL 1
#define EMPTY_TABLE (struct symbol_t *) NULL
#define TYPE_STRUCT 1
#define TYPE_FELDNAME 2
#define TYPE_STRUKTURNAME 3
#define TYPE_FUNKTIONSNAME 4
#define TYPE_LET_ID 5
#define UNIQUE 1
#define NOT_UNIQUE 0

struct symbol_t {
	char *name;
	struct symbol_t *next;
	short type;
};

/*Was soll man mit den Table anstelln koennen*/
struct symbol_t *new_table(void);
struct symbol_t *lookup(struct symbol_t *table, char *name);
struct symbol_t *table_merge(struct symbol_t *table_one, struct symbol_t *table_two);
struct symbol_t *add_symbol(struct symbol_t *table, char *identifier, short type, short unique);
void is_struct(struct symbol_t *table, char *identifier);
void exists(struct symbol_t *table, char *identifier);
void check(struct symbol_t *table, char *identifier);
void check_table(struct  symbol_t* t1, struct symbol_t* t2);

#endif

