/********Symboltabelle*********/

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *name; } T_ID

/*Ein Programm hat Funktionen, Strukturen und Felder*/
@attributes	{ struct symbol_t *structs; struct symbol_t *fields;} Program

/*Sichtbare Symbole*/
@attributes	{ struct symbol_t *symbols;} Funcdef Stats Expr Stat CondRec

/*Parameter innerhalb einer Funktion*/
@attributes { struct symbol_t *vars;} Params LetRec

/*Strukturnamen*/
@attributes { struct symbol_t *strukturname;} Structdef


/*Feldnamen*/
@attributes { struct symbol_t *feldname;} Rec_id

@attributes { char* strukturname; struct symbol_t *symbols; } WITH

@traversal @postorder t

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
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON

/* Grammar follows */
%%

Program: /*empty Program*/
	@{
		@i @Program.structs@ = new_table();
		@i @Program.fields@ = new_table();
	@}
	| Program Structdef T_SEMICOLON
	@{
		@i @Program.0.fields@ = @Program.1.fields@;
		@i @Program.0.structs@ = add_symbol(@Program.1.structs@, @Structdef.strukturname@, TYPE_STRUKTURNAME, UNIQUE);
	@}
	| Program Funcdef T_SEMICOLON
	@{
		@i @Program.0.fields@ = @Program.1.fields@;
		@i @Program.0.structs@ = @Program.1.structs@;

		//inherit
		@i @Funcdef.symbols@ = table_merge(@Program.structs@, @Program.fields@);
	@}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	@{
		//inherit
		@i @Stats.symbols@ = table_merge(@Funcdef.symbols@, @Params.vars@);
	@}
	;

Params: /*no params*/
	@{
		@i @Params.vars@ = new_table();
	@}
	| Params T_ID
	@{
		@i @Params.0.vars@ = table_add_symbol(@Params.1.vars@, @T_ID.name@, PARAMETER_SYMBOL);
	@}
	;

Rec_id: 
	@{
		@i @Rec_id.feldname@ = NULL;
	@}
	| Rec_id T_ID
	@{
		@i @Rec_id.0.feldname@ = add_symbol(@Rec_id.1.feldname@, @T_ID.name@, TYPE_FELDNAME, UNIQUE);
	@}
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT
	Rec_id
	T_END
	@{
		@i @Structdef.strukturname@ = @T_ID.name@;
	@}
	;

Stats: 
	| Stats Stat T_SEMICOLON
	@{
		@i @Stat.symbols@ = @Stats.0.symbols@;
		@i @Stats.1.symbols@ = @Stats.0.symbols@;
	@}
	;


LetRec:
	@{
		@i @LetRec.vars@ = new_table();
	@}
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	@{
		@i @Expr.symbols@ = table_merge(@LetRec.0.vars@, @LetRec.1.vars@);
		@i @LetRec.vars@ = new_table();
	@}
	;

CondRec:
	| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	@{
		//inherit
		@i @Expr.symbols@ = @CondRec.symbols@;
		@i @CondRec.1.symbols@ = @CondRec.0.symbols@;
		@i @Stats.symbols@ = @CondRec.0.symbols@;
	@}
	;

Stat: T_RETURN Expr
	@{
		@i @Expr.symbols@ = @Stat.symbols@;
	@}
	| T_COND CondRec T_END
	@{
		@i @CondRec.symbols@ = @Stat.symbols@;
	@}
	| T_LET LetRec T_IN Stats T_END
	@{
		@i @Stats.symbols@ = @LetRec.vars@;
	@}
	| WITH
	@{
		@i @WITH.symbols@ = @Stat.symbols@;
	@}
	| Lexpr T_EQUAL Expr 
	@{
		@i @Expr.symbols@ = @Stat.symbols@;
	@}
	| Term
	;

WITH: T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	@{
		@i @WITH.strukturname@ = is_struct(T_ID);
		@i @Stats.symbols@ = @WITH.symbols@;
		@i @Expr.symbols@ = @WITH.symbols@;
	@}
	;

Lexpr: T_ID 
	| Term T_POINT T_ID 
	;

/* one or more not/minus*/
Vorzeichen: T_NOT
	| T_MINUS
	| Vorzeichen T_NOT
	| Vorzeichen T_MINUS
	;

RecCompSym:
	| RecCompSym T_GREATER 
	| RecCompSym T_NOT_EQUAL
	;

Expr: 
	| Term /* sollte eigentlich úeberfluessig sein da bei der unteren regel notrec auch null sein kann. is es aber nicht */
	| Vorzeichen Term
	| Expr T_PLUS Term
	| Expr T_MUL Term
	| Expr T_OR Term
	| Term RecCompSym Term
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

