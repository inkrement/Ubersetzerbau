%{
#include <stdio.h>
#include "oxout.tab.h"
#include <string.h>

%}

WHITESPACE   [ \t\n]

/* define additional states */

%x BLOCK_COMMENT

%%
"struct"	return T_STRUCT;
"end"		return T_END;
"func"		return T_FUNC;
"return"	return T_RETURN;
"with"		return T_WITH;
"do"		return T_DO;
"let"		return T_LET;
"in"		return T_IN;
"cond"		return T_COND;
"then"		return T_THEN;
"not"		return T_NOT;
"or"		return T_OR;

"("			return T_BRACKET_LEFT;
")"			return T_BRACKET_RIGHT;
":"			return T_DOUBLE_POINT;
";"			return T_SEMICOLON;
"="			return T_EQUAL;
"."			return T_POINT;
"-"			return T_MINUS;
"+"			return T_PLUS;
"*"			return T_MUL;
">"			return T_GREATER;
"<>"		return T_NOT_EQUAL;
","			return T_COLON;

[0-9]+		return T_NUM; @{ @T_NUM.val@ = atoi(yytext+1); @}

[0-9][A-Fa-f0-9]*H 	return T_NUM; @{ unsigned int hex = 0; sscanf(yytext, "%X", &hex); @T_NUM.val@ = hex; @}



{WHITESPACE}+ {}


<INITIAL>{
     "/*"              BEGIN(BLOCK_COMMENT);
}
<BLOCK_COMMENT>{
	"*/"      BEGIN(INITIAL);
	[^*\n]+   {}
	"*"       {}
	\n        yylineno++;
}


[A-Za-z][A-Za-z0-9_]* return T_ID; @{ @T_ID.name@=strdup(yytext); @}

.		exit(1);

<BLOCK_COMMENT><<EOF>> exit(1);

%%
