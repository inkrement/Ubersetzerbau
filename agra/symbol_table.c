#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"


struct symbol_t *new_table(void) {
	printf("DEBUG: new table\n");
	return EMPTY_TABLE;
}

struct symbol_t *table_lookup(struct symbol_t *table, char *identifier) {
	
	struct symbol_t* item;

	printf("DEBUG LOOKUP: %s\n", identifier);

	if(table == EMPTY_TABLE) return EMPTY_TABLE;

	item = table;

	printf("DEBUG: table lookup\n");

	while(item->name != identifier && item->next != EMPTY_TABLE)
		item = item->next;

	return (item->name == identifier)?item:EMPTY_TABLE;
}

void check(struct symbol_t *table, char *identifier){
	if (table_lookup(table, identifier) != EMPTY_TABLE){
		printf("CHECK: %s is in table. EXIT!\n", identifier);
		exit(3);
	}
	printf("CHECK: %s is NOT in table.\n", identifier);
}

void check_table(struct  symbol_t* t1, struct symbol_t* t2)
{
	struct  symbol_t* node;

	if(t1 == EMPTY_TABLE) return;

	for(node = t1; node->next != EMPTY_TABLE; node->next)
		check(t2, node->name);
}

struct symbol_t *table_clone(struct symbol_t *table) {
	
	struct symbol_t* item;

	printf("DEBUG: table clone\n");

	if(table == EMPTY_TABLE) return EMPTY_TABLE;

	item = (struct symbol_t*) malloc(sizeof(struct symbol_t));

	item->type = table->type;
	item->name = table->name;

	if(table->next != EMPTY_TABLE) 
		item->next = table_clone(table->next);

	return item;
}

/*
 * merges zwei tables
 */
struct symbol_t *table_merge(struct symbol_t *table_one, struct symbol_t *table_two){

	struct symbol_t *first, *second, *i;

	printf("DEBUG: table merge\n");

	if(table_one == EMPTY_TABLE) return table_two;
	if(table_two == EMPTY_TABLE) return table_one;


	first=table_clone(table_one);
	second=table_clone(table_two);

	i = first;

	while(i->next != EMPTY_TABLE) i = i->next;

	i->next = second;

	return first;
}


/**
 * add symbol to table
 *
 * bei unique = 1 check! wenn nicht einfach hinzufügen
 */
struct symbol_t* add_symbol(struct symbol_t *table, char *name, short type, short unique) {
	struct symbol_t* item = (struct symbol_t*) malloc(sizeof(struct symbol_t));

	printf("DEBUG: add symbol(%s/%d/%d)\n", name, type, unique);

	/* fehler wenn schon vorkommt */
	if (unique == 1 && (table_lookup(table, name) != EMPTY_TABLE)) {
		printf("DEBUG: add_symbol(%s) EXIT 3\n", name);
		exit(3);
	}

	item->next = table;
	item->name = name;
	item->type = type;

	return item;
}




void is_struct(struct symbol_t *table, char *identifier){
	struct symbol_t* item = table_lookup(table, identifier);
	printf("DEBUG: is struct\n");

	if(item != EMPTY_TABLE && item->type != TYPE_STRUCT) exit(3);
}

/*

main(){
	struct symbol_t* test = new_table();


}*/