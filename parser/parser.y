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
%token with struct return num cond end id let in func or not do then

/* Grammar follows */
%%

Program: /* empty program */
	| Def ';'
	| Def ';' Program
	;

Def: Funcdef
	| Structdef
	;

Rec_id: /* empty */
	| id 
	| id Rec_id
	;

Structdef: struct id ':'
	Rec_id
	end
	;

Funcdef: func id 
	'(' Rec_id ')'
	Stats end
	;

Stats: /*empty Statement*/
	| Stat ';'
	| Stat ';' Stats
	;


LetRec: /*empty*/
	| id '=' Expr ';'
	| id '=' Expr ';' LetRec
	;

CondRec: /*empty*/
	| Expr then Stats end ';'
	| Expr then Stats end ';' CondRec
	;

Stat: return Expr
	| cond CondRec end
	| let LetRec in Stats end
	| with Expr ':' id do Stats end
	| Lexpr '=' Expr 
	| Term
	;

Lexpr: id 
	| Term '.' id 
	;

NotRec: /*empty*/
	| not
	| '-'
	| NotRec NotRec
	;

RecCompSym: /*empty*/
	| '>' RecCompSym
	| "<>" RecCompSym
	;

Expr: Term
	| Expr '+' Term
	| Expr '*' Term
	| Expr or Term
	| Term RecCompSym Term
	;

ExprList: /*empty*/
	| Expr ','
	| Expr
	| Expr ',' ExprList

Term: '(' Expr ')'
	| num
	| Term '.' id 
	| id
	| id '(' ExprList ')'
	;



%%

main() {
	//do { 
		yyparse();
	//} while(!feof(yyin));
}

