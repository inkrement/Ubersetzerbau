#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"

#define DEBUG_ME

void debug_symbol_table(struct symbol_t *table){
	int i=0;
	struct symbol_t *node = table;

	printf("tableinfo (%p): [", (void *) table);

	for(;node != EMPTY_TABLE;node=node->next){
		printf("%s(index: %d)", node->name, node->param_index);
		i = i + 1;
	}

	printf("] has %d elements\n", i);
}


struct symbol_t *table_lookup(struct symbol_t *table, char *identifier) {
	struct symbol_t* i = table;
	struct symbol_t *result = EMPTY_TABLE;

	#ifdef DEBUG_ME
		debug_symbol_table(table);
	#endif

	if(identifier == (char *) NULL){ return EMPTY_TABLE; }

	while(i != EMPTY_TABLE){
		if(0 ==  strcmp(i->name, identifier))
			result = add_symbol(result, i->name, NOT_UNIQUE, i->param_index, i->type, i->reg, i->offset);

		i = i->next;
	}

	return result;
}

struct symbol_t *table_merge(struct symbol_t *table_one, struct symbol_t *table_two){
	struct symbol_t *i, *result;

	if(table_one == EMPTY_TABLE) return table_two;

	i = table_two;
	result = table_one;

	while(i != EMPTY_TABLE ){
		result = add_symbol(result, i->name, UNIQUE, i->param_index, i->type, i->reg, i->offset);
		i = i->next;
	}

	return result;
}


struct symbol_t* add_symbol(struct symbol_t *table, char *name, short unique, int index, int type, char* reg, int offset) {
	struct symbol_t* item;

	#ifdef DEBUG_ME
		printf("Add Symbol - type(%d) name(%s) param_index(%d) reg(%s)\n", type, name, index, reg);
	#endif

	if (unique == 1 && (table_lookup(table, name) != EMPTY_TABLE)) { printf("Fail add_symbol %s\n", name ); exit(3); }

	item = (struct symbol_t*) malloc(sizeof(struct symbol_t));
	item->next = table;
	item->name = name;
	item->type = type;
	item->param_index = index;
	item->offset = offset;
	item->reg = reg;

	return item;
}



struct symbol_t* add_var(struct symbol_t *table, char *name, char* reg) {
	return add_symbol(table, name, UNIQUE, -1, TYPE_VAR, reg, 0);
}


struct symbol_t* add_field(struct symbol_t *table, char *name, int offset) {
	return add_symbol(table, name, UNIQUE, -1, TYPE_FIELD, (char*) NULL, offset);
}

struct symbol_t* add_param(struct symbol_t *table, char *name, int index) {
	return add_symbol(table, name, UNIQUE, index, TYPE_PARAM, (char*) NULL, 0);
}




struct symbol_t *table_clone(struct symbol_t *table) {
	struct symbol_t* item;

	if(table == EMPTY_TABLE) return EMPTY_TABLE;

	item = (struct symbol_t*) malloc(sizeof(struct symbol_t));

	item->name = table->name;

	if(table->next != EMPTY_TABLE) 
		item->next = table_clone(table->next);

	return item;
}

int symboltable_includes(struct symbol_t *table, char *name){
	if(table_lookup(table, name) == EMPTY_TABLE) return FALSE;

	return TRUE;
}