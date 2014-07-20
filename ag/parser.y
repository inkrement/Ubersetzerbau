@autoinh structs visible_structs symbols

@attributes { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs; }  Stats Stat Lexpr Term Expr CondRec PlusExpr MultExpr OrExpr ExprList
@attributes { struct symbol_t* symbols; struct symbol_t* vars; struct struct_table* structs;  struct symbol_t* visible_structs; } LetRec
@attributes { struct symbol_t* felder; char *name; } Structdef
@attributes { struct struct_table* structs; }  Funcdef
@attributes { struct struct_table* struct_gen; struct struct_table* structs; } Program 
@attributes { struct symbol_t* syms_gen; }  Felder Params
@attributes { char *name;} T_ID
@attributes { char *val; } T_NUM

@traversal @postorder t

%{
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern int yylineno;
void yyerror(char *e)
{
    exit(2);
}

%}
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO 
%token T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON
%%

Input: Program
    @{ @i @Program.structs@ = @Program.struct_gen@; @}
	;

Program:
	@{ @i @Program.struct_gen@ = (struct struct_table *) NULL; @}
	| Program Structdef T_SEMICOLON
	@{
		@i @Program.0.struct_gen@ = add_struct(@Program.1.struct_gen@, @Structdef.name@, @Structdef.felder@);
		@i @Program.1.structs@ = @Program.0.structs@;
	@}
	| Program Funcdef T_SEMICOLON
	@{ @i @Program.0.struct_gen@ = @Program.1.struct_gen@; @}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	@{
		@i @Stats.symbols@ = @Params.syms_gen@;
		@i @Stats.visible_structs@ = NULL;
	@}
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT Felder T_END
	@{
		@i @Structdef.name@ = @T_ID.name@;
		@i @Structdef.felder@ = @Felder.syms_gen@;
	@}
	;

Params:
	@{ @i @Params.syms_gen@ = EMPTY_TABLE; @}
	| Params T_ID
	@{ @i @Params.0.syms_gen@ = add_symbol(@Params.1.syms_gen@, @T_ID.name@, UNIQUE); @}
	;

Felder:
	@{ @i @Felder.syms_gen@ = EMPTY_TABLE; @}
	| Felder T_ID
	@{ @i @Felder.0.syms_gen@ = add_symbol(@Felder.1.syms_gen@, @T_ID.name@, UNIQUE); @}
	;

Stats: | Stats Stat T_SEMICOLON;

LetRec: @{ @i @LetRec.vars@ = EMPTY_TABLE; @}
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	@{ @i @LetRec.0.vars@ = add_symbol(@LetRec.1.vars@, @T_ID.name@, UNIQUE); @}
	;

CondRec:
	| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	;

Stat: T_RETURN Expr
	| T_COND CondRec T_END
	| T_LET LetRec T_IN Stats T_END
	@{
		@i @Stats.symbols@ = table_merge(@Stat.symbols@, @LetRec.vars@);
	@}
	| T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	@{
		@t check_struct_exists(@Stat.structs@, @T_ID.name@);
		@i @Stats.symbols@ = load_struct(@Stat.structs@,@Stat.symbols@, @T_ID.name@);
	@}
	| Lexpr T_EQUAL Expr
	| Term
	;

Lexpr: T_ID
	@{ @t assert_exists(@Lexpr.structs@, @Lexpr.visible_structs@, @Lexpr.symbols@, @T_ID.name@); @}
	| Term T_POINT T_ID
	@{ @t assert_exists_feldkontext(@Lexpr.structs@, @Lexpr.symbols@, @T_ID.name@); @}
	;

Expr: Term
	| Sign Term
	| PlusExpr
	| MultExpr
	| OrExpr
	| Term T_GREATER Term
	| Term T_NOT_EQUAL Term
	;

PlusExpr: Term T_PLUS Term | PlusExpr T_PLUS Term;
MultExpr: Term T_MUL Term | MultExpr T_MUL Term;
OrExpr: Term T_OR Term | OrExpr T_OR Term;

Sign: 
	T_NOT
	| T_MINUS
	| Sign T_NOT
	| Sign T_MINUS
	;

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	| T_NUM
	| Term T_POINT T_ID
	@{ @t assert_exists_feldkontext(@Term.structs@, @Term.symbols@, @T_ID.name@); @}
	| T_ID
	@{ @t assert_exists(@Term.structs@, @Term.visible_structs@, @Term.symbols@, @T_ID.name@); @}
	| T_ID T_BRACKET_LEFT  T_BRACKET_RIGHT
	| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	| T_ID T_BRACKET_LEFT ExprList T_COLON T_BRACKET_RIGHT
	;

ExprList: Expr | ExprList T_COLON Expr;

%%

int main() {
		yyparse();
}