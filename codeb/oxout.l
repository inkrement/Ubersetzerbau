/* output from Ox version G1.04 */
%{
#include <stdio.h>
#include "oxout.tab.h"
#include <string.h>

%}

WHITESPACE   [ \t\n]

/* define additional states */

%x BLOCK_COMMENT


%{


struct yyyT1 { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs;}; 
typedef struct yyyT1 *yyyP1; 


struct yyyT2 { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs; struct treenode* node;}; 
typedef struct yyyT2 *yyyP2; 


struct yyyT3 { struct symbol_t* symbols; struct symbol_t* vars; struct struct_table* structs;  struct symbol_t* visible_structs; struct treenode* node; char* reg;}; 
typedef struct yyyT3 *yyyP3; 


struct yyyT4 { struct symbol_t* felder; char *name; }; 
typedef struct yyyT4 *yyyP4; 


struct yyyT5 { struct struct_table* structs; }; 
typedef struct yyyT5 *yyyP5; 


struct yyyT6 { struct struct_table* struct_gen; struct struct_table* structs; }; 
typedef struct yyyT6 *yyyP6; 


struct yyyT7 { struct symbol_t* syms_gen; int index; }; 
typedef struct yyyT7 *yyyP7; 


struct yyyT8 { struct symbol_t* syms_gen; int offset; }; 
typedef struct yyyT8 *yyyP8; 


struct yyyT9 { char *name;}; 
typedef struct yyyT9 *yyyP9; 


struct yyyT10 { char *val; }; 
typedef struct yyyT10 *yyyP10; 
                                                      /*custom*/  
typedef unsigned char yyyWAT; 
typedef unsigned char yyyRCT; 
typedef unsigned short yyyPNT; 
typedef unsigned char yyyWST; 

#include <limits.h>
#define yyyR UCHAR_MAX  

 /* funny type; as wide as the widest of yyyWAT,yyyWST,yyyRCT  */ 
typedef unsigned short yyyFT;

                                                      /*stock*/  




struct yyyGenNode {void *parent;  
                   struct yyyGenNode **cL; /* child list */ 
                   yyyRCT *refCountList; 
                   yyyPNT prodNum;                      
                   yyyWST whichSym; /* which child of parent? */ 
                  }; 

typedef struct yyyGenNode yyyGNT; 



struct yyyTB {int isEmpty; 
              int typeNum; 
              int nAttrbs; 
              char *snBufPtr; 
              yyyWAT *startP,*stopP; 
             };  




extern struct yyyTB yyyTermBuffer; 
extern yyyWAT yyyLRCIL[]; 
extern void yyyGenLeaf(); 


%}
%%
"struct"	{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_STRUCT;}
"end"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_END;}
"func"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_FUNC;}
"return"	{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_RETURN;}
"with"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_WITH;}
"do"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_DO;}
"let"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_LET;}
"in"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_IN;}
"cond"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_COND;}
"then"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_THEN;}
"not"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_NOT;}
"or"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_OR;}

"("			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_BRACKET_LEFT;}
")"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_BRACKET_RIGHT;}
":"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_DOUBLE_POINT;}
";"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_SEMICOLON;}
"="			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_EQUAL;}
"."			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_POINT;}
"-"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_MINUS;}
"+"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_PLUS;}
"*"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_MUL;}
">"			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_GREATER;}
"<>"		{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_NOT_EQUAL;}
","			{yyyGenLeaf(0,0,yyyLRCIL+0,yyyLRCIL+0);return T_COLON;}

[0-9]+		{yyyGenLeaf(1,10,yyyLRCIL+0,yyyLRCIL+1); unsigned long dec = 0; sscanf(yytext, "%d", &dec); (((yyyP10)(yyyTermBuffer.snBufPtr))->val) = dec; return (T_NUM);}  

[0-9][A-Fa-f0-9]*H 	{yyyGenLeaf(1,10,yyyLRCIL+0,yyyLRCIL+1); unsigned long hex = 0; sscanf(yytext, "%X", &hex); (((yyyP10)(yyyTermBuffer.snBufPtr))->val) = hex; return (T_NUM);}  



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


[A-Za-z][A-Za-z0-9_]* {yyyGenLeaf(1,9,yyyLRCIL+1,yyyLRCIL+2); (((yyyP9)(yyyTermBuffer.snBufPtr))->name)=strdup(yytext); return T_ID;} 

.		exit(1);

<BLOCK_COMMENT><<EOF>> exit(1);

%%
