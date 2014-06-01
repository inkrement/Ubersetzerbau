@autoinh structs visible_structs symbols

@attributes { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs;}  Stats
@attributes { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs; struct treenode* node;} Stat Lexpr Term Expr CondRec PlusExpr MultExpr OrExpr ExprList SignExpr
@attributes { struct symbol_t* symbols; struct symbol_t* vars; struct struct_table* structs;  struct symbol_t* visible_structs; struct treenode* node;} LetRec

@attributes { struct symbol_t* felder; char *name; } Structdef
@attributes { struct struct_table* structs; }  Funcdef
@attributes { struct struct_table* struct_gen; struct struct_table* structs; } Program 
@attributes { struct symbol_t* syms_gen; int index; }  Params
@attributes { struct symbol_t* syms_gen; int offset; }  Felder 
@attributes { char *name;} T_ID
@attributes { char *val; } T_NUM

@traversal @preorder reg
@traversal @postorder t

@traversal @preorder codegen

%{
#include <stdlib.h>
#include <stdio.h>
#include "symbol_table.h"
#include "struct_table.h"
#include "tree.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

extern int yylineno;
void yyerror(char *e)
{
    exit(2);
}

%}
%token T_WITH T_STRUCT T_RETURN T_NUM T_COND T_END T_ID T_LET T_IN T_FUNC T_OR T_NOT T_DO T_THEN T_BRACKET_LEFT T_BRACKET_RIGHT T_DOUBLE_POINT T_SEMICOLON T_EQUAL T_POINT T_MINUS T_PLUS T_MUL T_GREATER T_NOT_EQUAL T_COLON
%%

Input: Program
    @{ 
    	@i @Program.structs@ = @Program.struct_gen@;

    	@codegen printf("\t.text\n");
    @}
	;

Program:
	@{ @i @Program.struct_gen@ = (struct struct_table *) NULL; @}
	| Program Structdef T_SEMICOLON
	@{
		@i @Program.0.struct_gen@ = add_struct(@Program.1.struct_gen@, @Structdef.name@, @Structdef.felder@);
		@i @Program.1.structs@ = @Program.0.structs@;

		@t assert_unused_fieldnames(@Program.1.struct_gen@, @Structdef.felder@);
	@}
	| Program Funcdef T_SEMICOLON
	@{
		@i @Program.0.struct_gen@ = @Program.1.struct_gen@;
	@}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	@{
		@i @Stats.symbols@ = @Params.syms_gen@;
		@i @Stats.visible_structs@ = NULL;

		@codegen function_header(@T_ID.name@, @Params.syms_gen@);
	@}
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT Felder T_END
	@{
		@i @Structdef.name@ = @T_ID.name@;
		@i @Structdef.felder@ = @Felder.syms_gen@;
	@}
	;

Params:
	@{
		@i @Params.syms_gen@ = EMPTY_TABLE;
		@i @Params.index@ = -1;
	@}
	| Params T_ID
	@{
		@i @Params.0.syms_gen@ = add_param(@Params.1.syms_gen@, @T_ID.name@, @Params.index@);
		@i @Params.0.index@ = @Params.1.index@ + 1;
	@}
	;

Felder:
	@{ 
		@i @Felder.syms_gen@ = EMPTY_TABLE;
		@i @Felder.offset@ = -1;
	@}
	| Felder T_ID
	@{ 
		@i @Felder.0.syms_gen@ = add_field(@Felder.1.syms_gen@, @T_ID.name@, @Felder.offset@);
		@i @Felder.0.offset@ = @Felder.1.offset@ + 1;
	@}

	;

Stats: 
	| Stats Stat T_SEMICOLON
	@{
		 @t debug_tree(@Stat.node@);

		 @codegen @revorder(@Stat.node@->op == OP_Return) burm_label(@Stat.node@); burm_reduce(@Stat.node@, 1);
	@}
	;

LetRec:
	@{ 
		@i @LetRec.vars@ = EMPTY_TABLE;
		@i @LetRec.node@ = new_leaf(OP_NOP);
	@}
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	@{
		@i @LetRec.0.vars@ = add_var(@LetRec.1.vars@, @T_ID.name@, newreg());
		@i @LetRec.0.node@ = new_node(OP_Assign, @Expr.node@, @LetRec.1.node@);

		@reg @Expr.node@->reg = getRegister(@T_ID.name@);
	@}
	;

CondRec:
	@{
		/*anscheinend keine expression < 0 also leeres Blatt ohne Operation*/
		@i @CondRec.node@ = new_leaf(OP_NOP);
	@}
	| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	@{		
		/*Wenn Expr < 0 then new Stat node und aus rekursion raus. Wie auf value von Expr zugreifen? Oder direkt im Assemblercode setzen*/
		/*jmp richtig setzen*/
		/*Bei erster Expression, die groesser 0 ist aus der rekursion raus.*/
		

		@i @CondRec.node@ = new_node(OP_CONDREC, @Expr.node@, (treenode *) NULL);
	@}
	;

Stat: T_RETURN Expr
	@{ 
		@i @Stat.node@ = new_node(OP_Return, @Expr.node@, (treenode*) NULL);

		@reg @Stat.node@->reg = newreg(); @Expr.node@->reg = @Stat.node@->reg;
	@}
	| T_COND CondRec T_END
	@{
		@i @Stat.node@ = @CondRec.node@;
	@}
	| T_LET LetRec T_IN Stats T_END
	@{
		@i @Stats.symbols@ = table_merge(@Stat.symbols@, @LetRec.vars@);
		@i @Stat.node@ = @LetRec.node@;
	@}
	| T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	@{
		@t assert_struct_exists(@Stat.structs@, @T_ID.name@);

		@i @Stats.symbols@ = load_struct(@Stat.structs@, @Stat.symbols@, @T_ID.name@);
		@i @Stat.node@ = new_node(OP_With, @Expr.node@, (treenode*) NULL);

		@reg @Stat.node@->reg = newreg(); @Expr.node@->reg = @Stat.node@->reg;
		@codegen setfieldreg(@Stat.structs@, @Stats.symbols@, @T_ID.name@, @Stat.node@->reg);
	@}
	| Lexpr T_EQUAL Expr
	@{
		@i @Stat.node@ = new_node(OP_LEXPR, @Lexpr.node@, @Expr.node@);

		@reg @Stat.node@->reg = newreg(); @Expr.node@->reg = @Stat.node@->reg;
	@}
	| Term
	@{
		@i @Stat.node@ = NULL;
	@}
	;

Lexpr: T_ID
	@{
		@t assert_exists(@Lexpr.symbols@, @T_ID.name@);
		
		@i @Lexpr.node@ = new_id_leaf(@Lexpr.symbols@, @T_ID.name@);

		@reg @Lexpr.node@->reg = getRegister(@T_ID.name@);
	@}
	| Term T_POINT T_ID
	@{
		@t assert_exists_feldkontext(@Lexpr.structs@, @Lexpr.symbols@, @T_ID.name@);
		@i @Lexpr.node@ = new_leaf(OP_NOP);
	@}
	;

SignExpr: Term
	@{
		@i @SignExpr.node@ = @Term.node@;
        @reg @Term.node@->reg = @SignExpr.node@->reg;
	@}
	|
	T_MINUS SignExpr
	@{
		@i @SignExpr.0.node@ = new_node(OP_NEG, @SignExpr.1.node@, (treenode *) NULL);
		@reg @SignExpr.1.node@->reg = @SignExpr.0.node@->reg;
	@}
	|
	T_NOT SignExpr
	@{
		@i @SignExpr.0.node@ = new_node(OP_NOT, @SignExpr.1.node@, (treenode *) NULL);
		@reg @SignExpr.1.node@->reg = @SignExpr.0.node@->reg;
	@}
	;

Expr: Term
	@{ 
		@i @Expr.node@ = @Term.node@;
		@reg @Term.node@->reg = @Expr.node@->reg; 
	@}
	| T_MINUS SignExpr
	@{
		@i @Expr.node@ = new_node(OP_NEG, @SignExpr.node@, (treenode *) NULL);
		@reg @SignExpr.node@->reg = @Expr.node@->reg;
	@}
	| T_NOT SignExpr
	@{
		@i @Expr.node@ = new_node(OP_NOT, @SignExpr.node@, (treenode *) NULL);
		@reg @SignExpr.node@->reg = @Expr.node@->reg;
	@}
	| PlusExpr
	@{
		@i @Expr.node@ = @PlusExpr.node@;
		@reg @PlusExpr.node@->reg = @Expr.node@->reg;
	@}
	| MultExpr
	@{
		@i @Expr.node@ = @MultExpr.node@;
		@reg @MultExpr.node@->reg = @Expr.node@->reg;
	@}
	| OrExpr
	@{
		@i @Expr.node@ = @OrExpr.node@;
		@reg @OrExpr.node@->reg = @Expr.node@->reg;
	@}
	| Term T_GREATER Term
	@{
		@i @Expr.node@ = new_node(OP_GREATER, @Term.0.node@, @Term.1.node@);
		@reg @Term.0.node@->reg = @Expr.node@->reg; @Term.1.node@->reg = newreg();
	@}
	| Term T_NOT_EQUAL Term
	@{
		@i @Expr.node@ = new_node(OP_NEQ, @Term.0.node@, @Term.1.node@);
		@reg @Term.0.node@->reg = @Expr.node@->reg; @Term.1.node@->reg = newreg();
	@}
	;

PlusExpr: Term T_PLUS Term
	@{ 
		@i @PlusExpr.node@ = new_node(OP_ADD, @Term.0.node@, @Term.1.node@);

		@reg @Term.0.node@->reg = @PlusExpr.node@->reg; @Term.1.node@->reg = newreg();
	@}
	| PlusExpr T_PLUS Term
	@{ 
		@i @PlusExpr.0.node@ = new_node(OP_ADD, @Term.node@,@PlusExpr.1.node@);

        @reg @Term.node@->reg = @PlusExpr.0.node@->reg; @PlusExpr.1.node@->reg = newreg();
	@}
	;

MultExpr: Term T_MUL Term 
	@{
		@i @MultExpr.node@ = new_node(OP_MUL, @Term.0.node@, @Term.1.node@);
		@reg @Term.0.node@->reg = @MultExpr.node@->reg; @Term.1.node@->reg = newreg();
	@}
	| MultExpr T_MUL Term
	@{
		@i @MultExpr.0.node@ = new_node(OP_MUL, @Term.node@, @MultExpr.1.node@);
		@reg @Term.node@->reg = @MultExpr.0.node@->reg; @MultExpr.1.node@->reg = newreg();
	@}
	;

OrExpr: Term T_OR Term
	@{ 
		@i @OrExpr.node@ = new_node(OP_OR, @Term.0.node@, @Term.1.node@);
		
		@reg @Term.node@->reg = @OrExpr.node@->reg; @Term.1.node@->reg = newreg();
	@}
	| OrExpr T_OR Term
	@{ 

		@i @OrExpr.0.node@ = new_node(OP_OR, @Term.node@, @OrExpr.1.node@);
		@reg @Term.node@->reg = @OrExpr.0.node@->reg; @OrExpr.1.node@->reg = newreg();
	@}
	;

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	@{
		@i @Term.node@ = @Expr.node@;
	@}
	| T_NUM
	@{
		@i @Term.node@ = new_number_leaf(@T_NUM.val@);
	@}
	| Term T_POINT T_ID
	@{
		@t assert_exists_feldkontext(@Term.structs@, @Term.symbols@, @T_ID.name@); 
		
		@i @Term.0.node@ = new_field_leaf(@T_ID.name@, @Term.1.node@, get_field_offset(@Term.structs@, @T_ID.name@));

		@reg @Term.1.node@->reg = @Term.0.node@->reg;
	@}
	| T_ID
	@{
		@t assert_exists(@Term.symbols@, @T_ID.name@);

		@i @Term.node@ = new_id_leaf(@Term.symbols@, @T_ID.name@);
	@}
	| T_ID T_BRACKET_LEFT  T_BRACKET_RIGHT
	@{ @i @Term.node@ = new_leaf(OP_NOP); @}
	| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	@{ @i @Term.node@ = new_leaf(OP_NOP); @}
	| T_ID T_BRACKET_LEFT ExprList T_COLON T_BRACKET_RIGHT
	@{ @i @Term.node@ = new_leaf(OP_NOP); @}
	;

ExprList: Expr 
	@{ @i @ExprList.node@ = NULL; @}
	| ExprList T_COLON Expr
	@{
		@i @ExprList.0.node@ = new_node(OP_Args, @ExprList.1.node@, @Expr.node@);
	@}
	;

%%

int main() {
		yyparse();
}