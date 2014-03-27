%{
#include <stdio.h>
%}

WHITESPACE   [ \t\n]
DIGIT  [0-9]

/* define additional states */

%x C_COMMENT

%%
"struct"	printf("struct\n");
"end"		printf("end\n");
"func"		printf("func\n");
"return"	printf("return\n");
"with"		printf("with\n");
"do"		printf("do\n");
"let"		printf("let\n");
"in"		printf("in\n");
"cond"		printf("cond\n");
"then"		printf("then\n");
"not"		printf("not\n");
"or"		printf("or\n");

"("			printf("(\n");
")"			printf(")\n");
":"			printf(":\n");
";"			printf(";\n");
"="			printf("=\n");
"."			printf(".\n");
"-"			printf("_\n");
"+"			printf("+\n");
"*"			printf("*\n");
">"			printf(">\n");
"<>"		printf("<>\n");
","		printf(",\n");


{WHITESPACE}+ {}

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>.    { printf("");}

[A-Za-z][A-Za-z0-9_]*		printf("id %s\n", yytext);

.		printf("Unrecognized character %s\n", yytext);

%%

main() {
	yylex();
}