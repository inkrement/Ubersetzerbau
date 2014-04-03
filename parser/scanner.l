%{
#include <stdio.h>
#include "parser.tab.h"
%}

WHITESPACE   [ \t\n]
DIGIT  [0-9]

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

"("			printf("(\n");
")"			printf(")\n");
":"			printf(":\n");
";"			printf(";\n");
"="			printf("=\n");
"."			printf(".\n");
"-"			printf("-\n");
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

.		exit(1);

%%
