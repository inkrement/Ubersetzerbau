/********Symboltabelle*********/

/*Ein Programm hat Funktionen, Strukturen und Felder*/
@attributes	{ struct symbol_t *functions; struct symbol_t *structs; struct symbol_t *fields;} Program

/*Sichtbare Symbole*/
@attributes	{ struct symbol_t *symbols;} Funcdef Stats Params

/*Parameter innerhalb einer Funktion*/
@attributes { struct symbol_t *params;} Params

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *name; } T_ID


%{
#define YYSTYPE double

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

int yydebug=1;

void yyerror(const char* s) {
	exit(2);
}


%}

/* BISON Declarations */
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON T_LEAF

/* Grammar follows */
%%

/*
	Statt leeren Programmgen/Ausdrücken, gibt es als Blattknoten das Attribut T_LEAF
*/

Program:
	@{
		@i @Program.functions@ = NULL;
		@i @Program.structs@ = NULL;
		@i @Program.fields@ = NULL;
	@}

	| Def T_SEMICOLON Program
	@{
		@i @Program.functions@ = NULL;
		@i @Program.structs@ = NULL;
		@i @Program.fields@ = NULL;
	@}
	;

Def: Funcdef
	| Structdef
	;

/*Parameter sind nur innerhalb einer Funktion sichtbar. Daher
eigene Regel. */
Params: Params T_ID
	/*Zum inneren Param neuen hinzufuegen in aeusseren speichern*/
	@{
		@i @Params.0.params@ = table_add(@Params.1.params@, @T_ID.name@, PARAMETER_SYMBOL);
	@}
	;

Rec_id: 
	| Rec_id T_ID
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT
	Rec_id
	T_END
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT T_BRACKET_RIGHT Stats T_END
	@{
		@i @Stats.symbols@ = table_merge(@Funcdef.symbols@, new_table());
	@}	

	| T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END

	@{
		@i @Stats.symbols@ = table_merge(@Funcdef.symbols@, @Params.symbols@);
	@}

Stats: Stats Stat T_SEMICOLON
	;


LetRec: LetRec T_ID T_EQUAL Expr T_SEMICOLON
	| T_LEAF
	;

CondRec: CondRec Expr T_THEN Stats T_END T_SEMICOLON
	| T_LEAF
	;

Stat: T_RETURN Expr
	| T_COND CondRec T_END
	| T_LET LetRec T_IN Stats T_END
	| T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	| Lexpr T_EQUAL Expr 
	| Term
	;

Lexpr: T_ID 
	| Term T_POINT T_ID 
	;

/* one or more not/minus*/
Vorzeichen: T_NOT
	| T_MINUS
	| Vorzeichen T_NOT
	| Vorzeichen T_MINUS
	| T_LEAF
	;

RecCompSym: RecCompSym T_GREATER 
	| RecCompSym T_NOT_EQUAL
	| T_LEAF
	;

Expr: Term /* sollte eigentlich úeberfluessig sein da bei der unteren regel notrec auch null sein kann. is es aber nicht */
	| Vorzeichen Term
	| Expr T_PLUS Term
	| Expr T_MUL Term
	| Expr T_OR Term
	| Term RecCompSym Term
	| T_LEAF
	;

ExprList: Expr
	| Expr T_COLON ExprList
	;

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	| T_NUM
	| Term T_POINT T_ID 
	| T_ID
	| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	;

%%

main() {
		yyparse();
}

