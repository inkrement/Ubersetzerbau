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
	printf("%s\n", s);
	exit(2);
}


%}

/* BISON Declarations */
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN

/* Grammar follows */
%%

Program: /* empty program */
	| Def ';' Program
	;

Def: Funcdef
	| Structdef
	;

Rec_id: /* empty */
	| T_ID Rec_id
	;

Structdef: T_STRUCT T_ID ':'
	Rec_id
	T_END
	;

Funcdef: T_FUNC T_ID 
	'(' Rec_id ')'
	Stats T_END
	;

Stats: /*empty Statement*/
	| Stat ';' Stats
	;


LetRec: /*empty*/
	| T_ID '=' Expr ';' LetRec
	;

CondRec: /*empty*/
	| Expr T_THEN Stats T_END ';' CondRec
	;

Stat: T_RETURN Expr
	| T_COND CondRec T_END
	| T_LET LetRec T_IN Stats T_END
	| T_WITH Expr ':' T_ID T_DO Stats T_END
	| Lexpr '=' Expr 
	| Term
	;

Lexpr: T_ID 
	| Term '.' T_ID 
	;

NotRec: /*empty*/
	| T_NOT
	| '-'
	| NotRec NotRec
	;

RecCompSym: /*empty*/
	| '>' RecCompSym
	| "<>" RecCompSym
	;

Expr: NotRec Term
	| Expr '+' Term
	| Expr '*' Term
	| Expr T_OR Term
	| Term RecCompSym Term
	;

ExprList: /*empty*/
	| Expr
	| Expr ',' ExprList

Term: '(' Expr ')'
	| T_NUM
	| Term '.' T_ID 
	| T_ID
	| T_ID '(' ExprList ')'
	;



%%

main() {
	//do { 
		yyparse();
	//} while(!feof(yyin));
}

