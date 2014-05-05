/********Symboltabelle*********/

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *name; } T_ID Structdef

/*Namen der IDs werden im scanner mitgeliefert*/
@attributes { char *val; } T_NUM

@attributes { struct symbol_t *struktur_namen; } Program Funcdef Stats Stat With LetRec CondRec


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
	@}
	| Program Structdef T_SEMICOLON
	@{
		@i @Program.1.struktur_namen@ = @Program.0.struktur_namen@;
	@}
	| Program Funcdef T_SEMICOLON
	@{
		@i @Program.1.struktur_namen@ = @Program.0.struktur_namen@;
		@i @Funkdef.struktur_namen@ = @Program.0.struktur_namen@;
	@}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	@{
		@i @Stats.struktur_namen@ = @Funcdef.struktur_namen@;
	@}
	;

Params: /*no params*/
	| Params T_ID
	;

Rec_id: 
	| Rec_id T_ID
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT Rec_id T_END
	@{
		@i @Structdef.name@ = @T_ID.name@;
	@}
	;

Stats: 
	| Stats Stat T_SEMICOLON
	;


LetRec:
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	;

CondRec:
	| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	;


With: T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	;

Stat: T_RETURN Expr
	| T_COND CondRec T_END
	| T_LET LetRec T_IN Stats T_END
	| With
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

