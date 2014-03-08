%{
#include <stdio.h>
%}

WHITESPACE   [ \t\n]
DIGIT  [0-9]

/* define additional states */

%x C_COMMENT

%%

[A-Za-z]+[A-Za-Z0-9_]*		printf("id %s", yytext);

"struct"	printf("struct");
"end"		printf("end");
"func"		printf("func");
"return"	printf("return");
"with"		printf("with");
"do"		printf("do");
"let"		printf("let");
"in"		printf("in");
"cond"		printf("cond");
"then"		printf("then");
"not"		printf("not");
"or"		printf("or");

"("			printf("(");
")"			printf(")");
":"			printf(":");
";"			printf(";");
"."			printf(".");
"-"			printf("_");
"+"			printf("+");
"*"			printf("*");
">"			printf(">");
"<>"		printf("<>");


{WHITESPACE}+ {}

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>.    { }


.		printf("Unrecognized character %s", yytext);

%%

main() {
	yylex();
}