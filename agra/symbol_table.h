#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define PARAMETER_SYMBOL 1

struct symbol_t {
	char *name;
	struct symbol_t *next_elem;
	short type;
};

/*Was soll man mit den Table anstelln koennen*/
struct symbol_t *new_table(void);
struct symbol_t *lookup(struct symbol_t *table, char *name);
struct symbol_t *table_merge(struct symbol_t *table_one, struct symbol_t *table_two);
struct symbol_t *table_add_symbol(struct symbol_t *table, char *identifier, short type);

#endif

