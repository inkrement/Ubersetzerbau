/********Symboltabelle*********/

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *name; } T_ID Lexpr

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *val; } T_NUM

@attributes { struct symbol_t *struktur_namen; struct symbol_t *vars;} LetRec

@attributes { struct symbol_t *struktur_namen; struct symbol_t *feld_namen;} Program
@attributes { struct symbol_t *feld_namen; char *name;} Structdef
@attributes { struct symbol_t *feld_namen;} Fields
@attributes { struct symbol_t *vars;} Params
@attributes { struct symbol_t *struktur_namen; struct symbol_t *vars; struct symbol_t *feld_namen;} Funcdef Stats Stat CondRec With

/*Funcdef Params Stats Stat CondRec LetRec With Lexpr Term Expr ExprList*/


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
		@i @Program.struktur_namen@ = new_table();
		@i @Program.feld_namen@ = new_table();
	@}
	| Program Structdef T_SEMICOLON
	@{
		@i @Program.0.struktur_namen@ = add_symbol(@Program.1.struktur_namen@, @Structdef.name@, TYPE_STRUKTURNAME, UNIQUE);
		@i @Program.0.feld_namen@ = table_merge(@Program.1.feld_namen@, @Structdef.feld_namen@);
	@}
	| Program Funcdef T_SEMICOLON
	@{
		@i @Program.0.struktur_namen@ = @Program.1.struktur_namen@;
		@i @Funcdef.struktur_namen@ = @Program.0.struktur_namen@;
		@i @Program.0.feld_namen@ = @Program.1.feld_namen@;
		@i @Funcdef.feld_namen@ = @Program.0.feld_namen@;
	@}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	@{
		@i @Funcdef.vars@ = @Params.vars@;
		@t table_merge(@Funcdef.vars@, @Funcdef.feld_namen@);
		@i @Stats.feld_namen@ = @Funcdef.feld_namen@;
		@i @Stats.vars@ = @Funcdef.vars@;
		@i @Stats.struktur_namen@ = @Funcdef.struktur_namen@;		
	@}
	;

Params: /*no params*/
	@{
		@i @Params.vars@ = new_table();
	@}
	| Params T_ID
	@{
		@i @Params.0.vars@ = add_symbol(@Params.1.vars@, @T_ID.name@, TYPE_PARAMNAME, UNIQUE);
	@}
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT Fields T_END
	@{
		@i @Structdef.name@ = @T_ID.name@;
		@i @Structdef.feld_namen@ = tag_struct_elements(@Fields.feld_namen@, @T_ID.name@);

	@}
	;

Fields: /*no params*/
	@{
		@i @Fields.feld_namen@ = new_table();
	@}
	| Fields T_ID
	@{
		@i @Fields.0.feld_namen@ = add_feldname(@Fields.1.feld_namen@, @T_ID.name@);
	@}
	;

Stats:
	| Stats Stat T_SEMICOLON
	@{
		@i @Stats.1.feld_namen@ = @Stats.0.feld_namen@;
		@i @Stats.1.vars@ = @Stats.0.vars@;
		@i @Stats.1.struktur_namen@ = @Stats.0.struktur_namen@;
		@i @Stat.feld_namen@ = @Stats.1.feld_namen@;
		@i @Stat.vars@ = @Stats.1.vars@;
		@i @Stat.struktur_namen@ = @Stats.0.struktur_namen@;		
	@}
	;


LetRec:
	@{
		@i @LetRec.vars@ = new_table();
	@}
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	@{
		@i @LetRec.1.struktur_namen@ = @LetRec.0.struktur_namen@;
		@i @LetRec.0.vars@ = add_symbol(@LetRec.1.vars@, @T_ID.name@, TYPE_PARAMNAME, UNIQUE);
	@}
	;

CondRec:
	| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	@{
		@i @Stats.struktur_namen@ = @CondRec.struktur_namen@;
		@i @Stats.vars@ = @CondRec.vars@;
		@i @Stats.feld_namen@ = @CondRec.feld_namen@;
		@i @CondRec.1.struktur_namen@ = @CondRec.0.struktur_namen@;
		@i @CondRec.1.vars@ = @CondRec.0.vars@;
		@i @CondRec.1.feld_namen@ = @CondRec.0.feld_namen@;
	@}
	;


With: T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	@{
		@i @Stats.struktur_namen@ = @With.struktur_namen@;
		@i @Stats.vars@ = table_merge(@With.vars@, filter_feldnamen(@With.feld_namen@, @T_ID.name@));
		@i @Stats.feld_namen@ = @With.feld_namen@;
	@}
	| T_WITH Expr T_DOUBLE_POINT T_ID T_DO T_END
	;

Stat: T_RETURN Expr
	| T_COND CondRec T_END
	@{
		@i @CondRec.feld_namen@ = @Stat.feld_namen@;
		@i @CondRec.vars@ = @Stat.vars@;
		@i @CondRec.struktur_namen@ = @Stat.struktur_namen@;
	@}
	| T_LET LetRec T_IN Stats T_END
	@{
		@i @Stats.struktur_namen@ = @Stat.struktur_namen@;
		@i @Stats.feld_namen@ = @Stat.feld_namen@;
		@i @Stats.vars@ = table_merge(@Stat.vars@, @LetRec.vars@);
		@i @LetRec.struktur_namen@ = @Stat.struktur_namen@;

	@}
	| With
	@{
		@i @With.struktur_namen@ = @Stat.struktur_namen@;
		@i @With.vars@ = @Stat.vars@;
		@i @With.feld_namen@ = @Stat.feld_namen@;
	@}
	| Lexpr T_EQUAL Expr
	@{
		@t exists(@Stat.vars@, @Stat.struktur_namen@, @Stat.feld_namen@, @Lexpr.name@);
	@}
	| Term
	;


Lexpr: T_ID
	@{
		@i @Lexpr.name@ = @T_ID.name@;
	@}
	| Term T_POINT T_ID
	@{
		@i @Lexpr.name@ = @T_ID.name@;
	@}
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

