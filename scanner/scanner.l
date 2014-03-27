%{
#include <stdio.h>
%}

WHITESPACE   [ \t\n]
DIGIT  [0-9]

/* define additional states */

%x BLOCK_COMMENT

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
","			printf(",\n");

[0-9]+	printf("num %s\n", yytext);
[0-9][A-Fa-f0-9]*H 	{

	int hex;
	sscanf("%hH", yytext, &hex);
	

	printf("num %d\n", hex);
}



{WHITESPACE}+ {}


<INITIAL>{
     "/*"              BEGIN(BLOCK_COMMENT);
}
<BLOCK_COMMENT>{
	"*/"      BEGIN(INITIAL);
	[^*\n]+   // eat comment in chunks
	"*"       // eat the lone star
	\n        yylineno++;
}


[A-Za-z][A-Za-z0-9_]*		printf("id %s\n", yytext);

.		printf("Unrecognized character %s\n", yytext);

%%

main() {
	yylex();
}