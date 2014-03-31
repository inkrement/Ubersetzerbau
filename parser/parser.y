/* Infix notation calculator--calc */

%{
#define YYSTYPE double

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

/**
 * end with 2 on syntax error
 */
void yyerror(const char* s) {
	exit(2);
}


%}

/* BISON Declarations */
%token with struct return num cond end id let in func

/* Grammar follows */
%%

Program: Def ';'
	| Def ';' Program
	;


Def: Funcdef
	| Structdef
	;


/***** stand *****/

// { id } in EBNF
id_rec: /*null*/
	| id
	| id id_rec
	;

Structdef: struct id ':' /* Strukturname */
	id_rec /* beliebig viele ids */
	end
	;

Funcdef: func id /* Funktionsname */
	'(' id_rec ')' /* Parameterdefinition */
	Stats end
	;

//EBNF: { Stat ';' }
Stats: /*null*/
	| Stat ';'
	| Stat ';' Stats
	;

Stat: return Expr
	| cond { Expr then Stats end ';' } end
	| let { id '=' Expr ';' } in Stats end
	| with Expr ':' id do Stats end
	| Lexpr '=' Expr /* Zuweisung */
	| Term
	;

Lexpr: id /* Schreibender Variablenzugriff */
	| Term '.' id /* Schreibender Feldzugriff */
	;

Expr: { not | '-' } Term
	| Term { '+' Term }
	| Term { '*' Term }
	| Term { or Term }
	| Term { '>' | '<>' } Term
	;

Term: '(' Expr ')'
	| num
	| Term '.' id /* Lesender Feldzugriff */
	| id /* Lesender Variablenzugriff */
	| id '(' { Expr ',' } [ Expr ] ')' /* Funktionsaufruf */
	;




%%

main() {
	//do { 
		yyparse();
	//} while(!feof(yyin));
}

