%{
#include <stdio.h>
%}

WHITESPACE   [ \t\n]
DIGIT  [0-9]

/* define additional states */

%x BLOCK_COMMENT

%%
"struct"	printf("T_STRUCT\n");
"end"		printf("T_END\n");
"func"		printf("T_FUNC\n");
"return"	printf("T_RETURN\n");
"with"		printf("T_WITH\n");
"do"		printf("T_DO\n");
"let"		printf("T_LET\n");
"in"		printf("T_IN\n");
"cond"		printf("T_COND\n");
"then"		printf("T_THEN\n");
"not"		printf("T_NOT\n");
"or"		printf("T_OR\n");

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

[0-9]+	{
	int res = (int) strtol(yytext, NULL, 10);

	printf("T_NUM\n");
}

[0-9][A-Fa-f0-9]*H 	{
	yytext[strlen(yytext)-1] = 0;

	int res = (int) strtol(yytext, NULL, 16);

	printf("T_NUM\n");
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


[A-Za-z][A-Za-z0-9_]*		printf("T_ID\n");

.		printf("Unrecognized character %s\n", yytext);

%%

main() {
	yylex();
}