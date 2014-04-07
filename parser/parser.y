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
	//printf("%s\n", s);
	exit(2);
}


%}

/* BISON Declarations */
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON

/* Grammar follows */
%%

Program: /* empty program */ 
	| Program Def T_SEMICOLON
	;

Def: Funcdef
	| Structdef
	;

Rec_id: /* empty */
	| T_ID Rec_id
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT
	Rec_id
	T_END
	;

Funcdef: T_FUNC T_ID 
	T_BRACKET_LEFT Rec_id T_BRACKET_RIGHT
	Stats T_END
	;

Stats: /*empty Statement*/
	| Stat T_SEMICOLON Stats
	;


LetRec: /*empty*/
	| T_ID T_EQUAL Expr T_SEMICOLON LetRec
	;

CondRec: /*empty*/
	| Expr T_THEN Stats T_END T_SEMICOLON CondRec
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

NotRec: /*empty*/
	| T_NOT
	| T_MINUS
	| NotRec NotRec
	;

RecCompSym: /*empty*/
	| T_GREATER RecCompSym
	| T_NOT_EQUAL RecCompSym
	;

Expr: NotRec Term
	| Expr T_PLUS Term
	| Expr T_MUL Term
	| Expr T_OR Term
	| Term RecCompSym Term
	;

ExprList: /*empty*/
	| Expr
	| Expr T_COLON ExprList

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	| T_NUM
	| Term T_POINT T_ID 
	| T_ID
	| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	;



%%

main() {
	//do { 
		yyparse();
	//} while(!feof(yyin));
}

