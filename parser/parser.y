
%{
#include <stdlib.h>
#include <stdio.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern int yylineno;
void yyerror(char *e)
{
    printf("Parser error: '%s'..., line %d\n", e, yylineno);
    exit(2);
}

int yydebug=1;

%}
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON
%%

Program:
	| Program Structdef T_SEMICOLON
	| Program Funcdef T_SEMICOLON
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT IdList T_BRACKET_RIGHT Stats T_END
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT IdList T_END
	;

IdList:
	| IdList T_ID
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

Expr: Term
	| Sign Term
	| PlusExpr
	| MultExpr
	| OrExpr
	| Term T_GREATER Term
	| Term T_NOT_EQUAL Term
	;

PlusExpr: Term T_PLUS Term
	| PlusExpr T_PLUS Term
	;

MultExpr: Term T_MUL Term
	| MultExpr T_MUL Term
	;

OrExpr: Term T_OR Term
	| OrExpr T_OR Term
	;

Sign: 
	T_NOT
	| T_MINUS
	| Sign T_NOT
	| Sign T_MINUS
	;

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	| T_NUM
	| Term T_POINT T_ID
	| T_ID
	| T_ID T_BRACKET_LEFT  T_BRACKET_RIGHT
	| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	| T_ID T_BRACKET_LEFT ExprList T_COLON T_BRACKET_RIGHT
	;


ExprList: Expr | ExprList T_COLON Expr 
    ;

%%


int main() {
		yyparse();
}

