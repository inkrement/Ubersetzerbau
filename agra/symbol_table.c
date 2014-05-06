#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"


struct symbol_t *new_table(void) {
	printf("DEBUG: new table\n");
	return EMPTY_TABLE;
}

struct symbol_t *table_lookup(struct symbol_t *table, char *identifier) {
	struct symbol_t* i = table;
	struct symbol_t *result = EMPTY_TABLE;

	if(identifier == (char *) NULL){
		printf("LOOKUP_EMPTY_IDENTIFER!\n");
		return EMPTY_TABLE;
	}

	printf("DEBUG: table lookup %s in %p\n", identifier, (void *) table);

	while(i != EMPTY_TABLE){
		if(0 ==  strcmp(i->name, identifier))
			result = add_symbol(result, i->name, i->type, NOT_UNIQUE);

		i = i->next;
	}

	printf("TABLE lookup found following: ");
	table_info(result);

	return result;
}

struct symbol_t* tag_struct_elements(struct symbol_t *table, char *struct_name){
	struct symbol_t *loop=table;

	while (loop != EMPTY_TABLE){
		loop->struct_name = struct_name;
		loop = loop->next;
	}
		
		return table;
}

void exists(struct symbol_t *param_context, struct symbol_t *struct_context,struct symbol_t *feldnamen, char *identifier){
	struct symbol_t *feld_query;

	if(table_lookup(param_context, identifier) != EMPTY_TABLE)
		return;

	feld_query = table_lookup(feldnamen, identifier);
	while (feld_query != EMPTY_TABLE){
		if (table_lookup(struct_context, feld_query->struct_name) != EMPTY_TABLE)
			return;
		feld_query = feld_query->next;
	}

	exit(3);
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
	struct symbol_t *i, *result, *next;

	printf("DEBUG: table merge\n");

	if(table_one == EMPTY_TABLE) return table_two;

	i = table_two;
	result = table_one;


	while(i != EMPTY_TABLE ){
		result = add_symbol(result, i->name, i->type, UNIQUE);
		i = i->next;
	}

	return result;
}


/**
 * add symbol to table
 *
 * bei unique = 1 check! wenn nicht einfach hinzufügen
 */
struct symbol_t* add_symbol(struct symbol_t *table, char *name, short type, short unique) {
	struct symbol_t* item = (struct symbol_t*) malloc(sizeof(struct symbol_t));

	table_info(table);
	printf("DEBUG: add symbol(%s/%d/%d/unique) to %p\n", name, type, unique,(void *) table);

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


struct symbol_t* add_feldname(struct symbol_t *table, char *name) {
	struct symbol_t *item, *feldnamen;

	printf("DEBUG: add feldname(%s) to %p\n", name,(void *) table);

	feldnamen = table_lookup(table, name);

	while(feldnamen!=EMPTY_TABLE){
		if(feldnamen->type == TYPE_FELDNAME) exit(3);
		feldnamen=feldnamen->next;
	}

	item = (struct symbol_t*) malloc(sizeof(struct symbol_t));

	item->next = table;
	item->name = name;
	item->type = TYPE_FELDNAME;

	return item;
}

void table_info(struct symbol_t *table){
	int i=0;
	struct symbol_t *node = table;

	printf("tableinfo (%p): [", (void *) table);

	for(;node != EMPTY_TABLE;node=node->next){
		printf("%s", node->name);
		i = i + 1;
	}

	printf("] has %d elements\n", i);
}


struct symbol_t* filter_feldnamen(struct symbol_t* feldnamen, char *struct_name){
	struct symbol_t* res, *loop;

	if((char*)struct_name==NULL) return EMPTY_TABLE;

	res = new_table();
	loop = feldnamen;

	while(feldnamen != EMPTY_TABLE){
		if(feldnamen->struct_name != (char*) NULL){
			if(0 == strcmp(feldnamen->struct_name, struct_name)){
				res = add_symbol(res, loop->name, loop->type, UNIQUE);
			}
		}

		feldnamen = feldnamen->next;
	}


	return tag_struct_elements(res, struct_name);
}