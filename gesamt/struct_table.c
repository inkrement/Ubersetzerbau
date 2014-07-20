#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "struct_table.h"
#include "symbol_table.h"
#include "assembler.h"

int get_field_offset(struct struct_table* structs, char *fieldname){
	int offset = -1;
	struct symbol_t* field;
	struct struct_table* structure = get_struct_by_field(structs, fieldname);

	if(structure != NO_STRUCT){
		field = structure->fields;

		while(field != EMPTY_TABLE && 0 != strcmp(field->name, fieldname))
			field = field->next;
		

		while(field != EMPTY_TABLE){
			offset++;

			field = field->next;
		}
	}

	return offset;
}

struct struct_table* get_struct_by_field(struct struct_table* structs, char *fieldname){
	struct symbol_t* fields;

	while(structs != NO_STRUCT){
		fields = structs->fields;

		while(fields != EMPTY_TABLE){
			if(0 == strcmp(fields->name, fieldname)) return structs;

			fields = fields->next;
		}

		structs = structs->next;
	}

	/*TRACE(("no Struct with field %s found.", fieldname));*/

	return structs;
}

void setfieldreg(struct struct_table* structs, struct symbol_t* symbols, char* name, char* reg){
	struct struct_table* str = get_struct_by_name(structs, name);
	struct symbol_t* s;
	char* indirect_address;

	#ifdef DEBUG_ME
		printf("setfieldreg %s for %s\n",reg, name);
	#endif

	if(str == (struct struct_table*) NULL){
		printf("Could not find struct with name %s\n", name);
		exit(4);
	}

	while(symbols != EMPTY_TABLE){
		s = table_lookup(str->fields, symbols->name);

		if(s != EMPTY_TABLE) {

			#ifdef DEBUG_ME
				printf("(setgieldreg) found symbol to update: %s, %s\n", symbols->name, reg);
			#endif
			asprintf(&indirect_address, "%d(%s)", symbols->offset*FIELD_OFFSET, reg);
			setRegister(symbols->name, strclone(indirect_address));
			s->reg = reg;
		}

		symbols = symbols->next;
	}


}


struct struct_table* get_struct_by_name(struct struct_table* structs, char *structname){
	while(structs != NO_STRUCT){
		if(0 == strcmp(structs->name, structname)) return structs;

		structs = structs->next;
	}

	return structs;
}

void assert_unused_fieldname(struct struct_table* structs, char *fieldname){
	if( get_struct_by_field(structs, fieldname) != NO_STRUCT) exit(3);
}

void assert_unused_fieldnames(struct struct_table* structs, struct symbol_t* fields){
	while(fields != EMPTY_TABLE){
		if( get_struct_by_field(structs, fields->name) != NO_STRUCT) exit(3);
		fields = fields->next;
	}	
}


void assert_struct_exists(struct struct_table *structs, char *structname) {
  if(get_struct_by_name(structs, structname) == NO_STRUCT) exit(3);
}


struct struct_table* add_struct(struct struct_table *table, char *name, struct symbol_t *fields) {
	struct struct_table* item;

	item = table;
	while (item != (struct struct_table*) NULL){
		if(0 ==  strcmp(item->name, name)) {
			printf("Fail add_struct\n" );
			exit(3);
		}
		item = item->next;
	}

	item = (struct struct_table*) malloc(sizeof(struct struct_table));
	item->next = table;
	item->name = name;
	item->fields = fields;

	return item;
}


void debug_struct_table(struct struct_table *table){
	int i=0;
	struct struct_table *node = table;

	printf("struct_table (%p): [", (void *) table);

	for(;node != (struct struct_table*) NULL;node=node->next){
		printf("%s", node->name);
		i = i + 1;
	}

	printf("] has %d elements\n", i);
}



void assert_exists(struct symbol_t *symbols, char* name){

	/* search in lookuptable */
	while(symbols != EMPTY_TABLE){
		if(0 == strcmp(symbols->name, name)) return;
		symbols = symbols->next;
	}

	printf("assertion failed. No symbol with name %s\n", name);
	exit(3);
}


void assert_exists_feldkontext(struct struct_table *struct_table, struct symbol_t *symbols, char* name){

	while(struct_table != (struct struct_table *) NULL){
		if(table_lookup(struct_table->fields, name) != EMPTY_TABLE) return;

		struct_table = struct_table->next;
	}

	debug_struct_table(struct_table);
	debug_symbol_table(symbols);

	/* search in lookuptable */
	while(symbols != (struct symbol_t *) NULL){
		if(0 == strcmp(symbols->name, name)) return;
		symbols = symbols->next;
	}

	printf("Fail feldkontext\n" );
	exit(3);
}

void assert_single_occurence(struct struct_table *struct_table, struct symbol_t *visible_structs, struct symbol_t *symbols){
	struct symbol_t *sym = table_clone(symbols);

	while(struct_table != (struct struct_table *) NULL){
		/* if visible */
		if(table_lookup(visible_structs, struct_table->name) != EMPTY_TABLE) 
			sym = table_merge(sym, struct_table->fields);
		
		struct_table = struct_table->next;
	}
}


struct symbol_t * load_struct(struct struct_table* str_t, struct symbol_t* sym_t, char* struct_name){
	struct struct_table* s = str_t;

	#ifdef DEBUG_ME
		printf("Load Struct: %s\n", struct_name);
		debug_struct_table(str_t);
	#endif


	while(s != (struct struct_table*) NULL){
		if(0 == strcmp(s->name, struct_name)) break;
		s = s->next;
	}

	if (s == (struct struct_table*) NULL){
		printf("no such struct found!\n"); 
		exit(3);
	}

	return table_merge(s->fields, sym_t);
}
