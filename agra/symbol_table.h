#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

struct symbol_t {
	char *name;
	struct symbol_t *next_elem;
	short type;
};

/*Was soll man mit den Table anstelln koennen*/
struct symbol_t *new_table(void){
	return (struct symbol_t *)NULL;
}

struct symbol_t *lookup(struct symbol_t *table, char *name);

#endif

