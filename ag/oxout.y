/* output from Ox version G1.04 */
%{
%}
  

           
 
 
  
  
   
 
 



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

%{


struct yyyT1 { struct symbol_t* symbols; struct struct_table* structs;  struct symbol_t* visible_structs; }; 
typedef struct yyyT1 *yyyP1; 


struct yyyT2 { struct symbol_t* symbols; struct symbol_t* vars; struct struct_table* structs;  struct symbol_t* visible_structs; }; 
typedef struct yyyT2 *yyyP2; 


struct yyyT3 { struct symbol_t* felder; char *name; }; 
typedef struct yyyT3 *yyyP3; 


struct yyyT4 { struct struct_table* structs; }; 
typedef struct yyyT4 *yyyP4; 


struct yyyT5 { struct struct_table* struct_gen; struct struct_table* structs; }; 
typedef struct yyyT5 *yyyP5; 


struct yyyT6 { struct symbol_t* syms_gen; }; 
typedef struct yyyT6 *yyyP6; 


struct yyyT7 { char *name;}; 
typedef struct yyyT7 *yyyP7; 


struct yyyT8 { char *val; }; 
typedef struct yyyT8 *yyyP8; 
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

%{
#include <stdio.h>

int yyyYok = 1;
int yyyInitDone = 0;
char *yyySTsn;
yyyGNT *yyySTN;
int yyyGNSz = sizeof(yyyGNT);
int yyyProdNum,yyyRHSlength,yyyNattrbs,yyyTypeNum; 

extern yyyFT yyyRCIL[];

void yyyExecuteRRsection();
void yyyYoxInit();
void yyyYoxReset();
void yyyDecorate();
void yyyGenIntNode();
void yyyAdjustINRC();
void yyyPrune();
void yyyUnsolvedInstSearchTrav();
void yyyUnsolvedInstSearchTravAux();
void yyyerror();
void yyyShift();



#define yyyRSU(NUM1,NUM2,NUM3,NUM4) \
   yyyProdNum=NUM1;yyyRHSlength=NUM2;yyyNattrbs=NUM3;yyyTypeNum=NUM4;\
   if ((yychar <= 0) && (!yyyTermBuffer.isEmpty)) yyyShift(); 
%}


%%

yyyAugNonterm 
	:	{if (!yyyInitDone) 
		    {yyyYoxInit(); 
		     yyyInitDone = 1;
		    }
		 yyyYoxReset();
		}
		Input
		{
		 yyyDecorate(); yyyExecuteRRsection();
		}
	;
Input: Program
    {if(yyyYok){
yyyRSU(1,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+3);/*yyyPrune(1);*/}}
	;

Program:
	{if(yyyYok){
yyyRSU(2,0,2,5);
yyyGenIntNode();
 (((yyyP5)yyySTsn)->struct_gen) = (struct struct_table *) NULL; yyyAdjustINRC(yyyRCIL+3,yyyRCIL+6);}}
	| Program Structdef T_SEMICOLON
	{if(yyyYok){
yyyRSU(3,3,2,5);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+6,yyyRCIL+12);}}
	| Program Funcdef T_SEMICOLON
	{if(yyyYok){
yyyRSU(4,3,2,5);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+12,yyyRCIL+21);}}
	;

Funcdef: T_FUNC T_ID T_BRACKET_LEFT Params T_BRACKET_RIGHT Stats T_END
	{if(yyyYok){
yyyRSU(5,7,1,4);
yyyGenIntNode();
 (((yyyP1)(((char *)((yyySTN->cL)[5]))+yyyGNSz))->visible_structs) = NULL;
	yyyAdjustINRC(yyyRCIL+21,yyyRCIL+30);}}
	;

Structdef: T_STRUCT T_ID T_DOUBLE_POINT Felder T_END
	{if(yyyYok){
yyyRSU(6,5,2,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->name) = (((yyyP7)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->name);
		yyyAdjustINRC(yyyRCIL+30,yyyRCIL+36);/*yyyPrune(6);*/}}
	;

Params:
	{if(yyyYok){
yyyRSU(7,0,1,6);
yyyGenIntNode();
 (((yyyP6)yyySTsn)->syms_gen) = EMPTY_TABLE; yyyAdjustINRC(yyyRCIL+36,yyyRCIL+39);}}
	| Params T_ID
	{if(yyyYok){
yyyRSU(8,2,1,6);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+39,yyyRCIL+42);/*yyyPrune(8);*/}}
	;

Felder:
	{if(yyyYok){
yyyRSU(9,0,1,6);
yyyGenIntNode();
 (((yyyP6)yyySTsn)->syms_gen) = EMPTY_TABLE; yyyAdjustINRC(yyyRCIL+42,yyyRCIL+45);}}
	| Felder T_ID
	{if(yyyYok){
yyyRSU(10,2,1,6);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+45,yyyRCIL+48);/*yyyPrune(10);*/}}
	;

Stats: {if(yyyYok){
yyyRSU(11,0,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+48,yyyRCIL+48);}}| Stats Stat T_SEMICOLON{if(yyyYok){
yyyRSU(12,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+48,yyyRCIL+66);}};

LetRec: {if(yyyYok){
yyyRSU(13,0,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->vars) = EMPTY_TABLE; yyyAdjustINRC(yyyRCIL+66,yyyRCIL+69);}}
	| LetRec T_ID T_EQUAL Expr T_SEMICOLON
	{if(yyyYok){
yyyRSU(14,5,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+69,yyyRCIL+90);}}
	;

CondRec:
	{if(yyyYok){
yyyRSU(15,0,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+90,yyyRCIL+90);}}| CondRec Expr T_THEN Stats T_END T_SEMICOLON
	{if(yyyYok){
yyyRSU(16,6,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+90,yyyRCIL+117);}};

Stat: T_RETURN Expr
	{if(yyyYok){
yyyRSU(17,2,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+117,yyyRCIL+126);}}| T_COND CondRec T_END
	{if(yyyYok){
yyyRSU(18,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+126,yyyRCIL+135);}}| T_LET LetRec T_IN Stats T_END
	{if(yyyYok){
yyyRSU(19,5,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+135,yyyRCIL+153);}}
	| T_WITH Expr T_DOUBLE_POINT T_ID T_DO Stats T_END
	{if(yyyYok){
yyyRSU(20,7,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+153,yyyRCIL+171);}}
	| Lexpr T_EQUAL Expr
	{if(yyyYok){
yyyRSU(21,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+171,yyyRCIL+189);}}| Term
	{if(yyyYok){
yyyRSU(22,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+189,yyyRCIL+198);}};

Lexpr: T_ID
	{if(yyyYok){
yyyRSU(23,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+198,yyyRCIL+198);/*yyyPrune(23);*/}}
	| Term T_POINT T_ID
	{if(yyyYok){
yyyRSU(24,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+198,yyyRCIL+207);}}
	;

Expr: Term
	{if(yyyYok){
yyyRSU(25,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+207,yyyRCIL+216);}}| Sign Term
	{if(yyyYok){
yyyRSU(26,2,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+216,yyyRCIL+225);}}| PlusExpr
	{if(yyyYok){
yyyRSU(27,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+225,yyyRCIL+234);}}| MultExpr
	{if(yyyYok){
yyyRSU(28,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+234,yyyRCIL+243);}}| OrExpr
	{if(yyyYok){
yyyRSU(29,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+243,yyyRCIL+252);}}| Term T_GREATER Term
	{if(yyyYok){
yyyRSU(30,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+252,yyyRCIL+270);}}| Term T_NOT_EQUAL Term
	{if(yyyYok){
yyyRSU(31,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+270,yyyRCIL+288);}};

PlusExpr: Term T_PLUS Term {if(yyyYok){
yyyRSU(32,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+288,yyyRCIL+306);}}| PlusExpr T_PLUS Term{if(yyyYok){
yyyRSU(33,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+306,yyyRCIL+324);}};
MultExpr: Term T_MUL Term {if(yyyYok){
yyyRSU(34,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+324,yyyRCIL+342);}}| MultExpr T_MUL Term{if(yyyYok){
yyyRSU(35,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+342,yyyRCIL+360);}};
OrExpr: Term T_OR Term {if(yyyYok){
yyyRSU(36,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+360,yyyRCIL+378);}}| OrExpr T_OR Term{if(yyyYok){
yyyRSU(37,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+378,yyyRCIL+396);}};

Sign: 
	T_NOT
	{if(yyyYok){
yyyRSU(38,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+396,yyyRCIL+396);/*yyyPrune(38);*/}}| T_MINUS
	{if(yyyYok){
yyyRSU(39,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+396,yyyRCIL+396);/*yyyPrune(39);*/}}| Sign T_NOT
	{if(yyyYok){
yyyRSU(40,2,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+396,yyyRCIL+396);/*yyyPrune(40);*/}}| Sign T_MINUS
	{if(yyyYok){
yyyRSU(41,2,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+396,yyyRCIL+396);/*yyyPrune(41);*/}};

Term: T_BRACKET_LEFT Expr T_BRACKET_RIGHT
	{if(yyyYok){
yyyRSU(42,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+396,yyyRCIL+405);}}| T_NUM
	{if(yyyYok){
yyyRSU(43,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+405,yyyRCIL+405);/*yyyPrune(43);*/}}| Term T_POINT T_ID
	{if(yyyYok){
yyyRSU(44,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+405,yyyRCIL+414);}}
	| T_ID
	{if(yyyYok){
yyyRSU(45,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+414,yyyRCIL+414);/*yyyPrune(45);*/}}
	| T_ID T_BRACKET_LEFT  T_BRACKET_RIGHT
	{if(yyyYok){
yyyRSU(46,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+414,yyyRCIL+414);/*yyyPrune(46);*/}}| T_ID T_BRACKET_LEFT ExprList T_BRACKET_RIGHT
	{if(yyyYok){
yyyRSU(47,4,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+414,yyyRCIL+423);}}| T_ID T_BRACKET_LEFT ExprList T_COLON T_BRACKET_RIGHT
	{if(yyyYok){
yyyRSU(48,5,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+423,yyyRCIL+432);}};

ExprList: Expr {if(yyyYok){
yyyRSU(49,1,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+432,yyyRCIL+441);}}| ExprList T_COLON Expr{if(yyyYok){
yyyRSU(50,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+441,yyyRCIL+459);}};


%%

int main() {
		yyparse();
}                                                      /*custom*/  
long yyyMaxNbytesNodeStg = 2000000; 
long yyyMaxNrefCounts =    500000; 
long yyyMaxNchildren =     60000; 
long yyyMaxStackSize =     2000; 
long yyySSALspaceSize =    20000; 
long yyyRSmaxSize =        1000; 
long yyyTravStackMaxSize = 2000; 


struct yyyTB yyyTermBuffer; 

char *yyyNodeAndStackSpace; 

char *yyyNodeSpace;
char *yyyNextNodeSpace; 
char *yyyAfterNodeSpace; 


 
struct yyyGenNode **yyyChildListSpace;  
struct yyyGenNode **yyyNextCLspace; 
struct yyyGenNode **yyyAfterChildListSpace; 



yyyRCT *yyyRefCountListSpace;
yyyRCT *yyyNextRCLspace;  
yyyRCT *yyyAfterRefCountListSpace;   



struct yyySolvedSAlistCell {yyyWAT attrbNum; 
                            long next; 
                           }; 
#define yyyLambdaSSAL 0 
long yyySSALCfreeList = yyyLambdaSSAL; 
long yyyNewSSALC = 1; 
 
struct yyySolvedSAlistCell *yyySSALspace; 


 
struct yyyStackItem {struct yyyGenNode *node; 
                     long solvedSAlist; 
                     struct yyyGenNode *oldestNode; 
                    };  

long yyyNbytesStackStg; 
struct yyyStackItem *yyyStack; 
struct yyyStackItem *yyyAfterStack; 
struct yyyStackItem *yyyStackTop; 



struct yyyRSitem {yyyGNT *node; 
                  yyyWST whichSym; 
                  yyyWAT wa;  
                 };  

struct yyyRSitem *yyyRS;  
struct yyyRSitem *yyyRSTop;  
struct yyyRSitem *yyyAfterRS;  
 





yyyFT yyyRCIL[] = {
0,1,1, yyyR,0,0, yyyR,0,3, 0,1,1, yyyR,0,1, 0,1,1, 
1,0,1, 5,0,1, 5,1,1, 5,2,0, yyyR,0,1, yyyR,1,0, 
yyyR,0,0, yyyR,0,1, yyyR,0,0, yyyR,0,1, 0,0,1, 0,1,1, 
0,2,1, 1,0,1, 1,1,1, 1,2,1, yyyR,1,0, yyyR,1,1, 
0,0,1, 0,2,1, 0,3,1, 3,0,1, 3,1,1, 3,2,1, 
0,0,1, 0,1,1, 0,2,1, 1,0,1, 1,1,1, 1,2,1, 
3,0,1, 3,1,1, 3,2,1, 1,0,1, 1,1,1, 1,2,1, 
1,0,1, 1,1,1, 1,2,1, 1,0,1, 1,2,1, 1,3,1, 
3,0,2, 3,1,1, 3,2,1, 1,0,1, 1,1,1, 1,2,1, 
5,0,2, 5,1,1, 5,2,1, 0,0,1, 0,1,1, 0,2,1, 
2,0,1, 2,1,1, 2,2,1, 0,0,1, 0,1,1, 0,2,1, 
0,0,1, 0,1,1, 0,2,1, 0,0,1, 0,1,1, 0,2,1, 
1,0,1, 1,1,1, 1,2,1, 0,0,1, 0,1,1, 0,2,1, 
0,0,1, 0,1,1, 0,2,1, 0,0,1, 0,1,1, 0,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
1,0,1, 1,1,1, 1,2,1, 0,0,1, 0,1,1, 0,2,1, 
2,0,1, 2,1,1, 2,2,1, 2,0,1, 2,1,1, 2,2,1, 
0,0,1, 0,1,1, 0,2,1, 0,0,1, 0,1,1, 0,2,1, 
2,0,1, 2,1,1, 2,2,1, 
};

short yyyIIIEL[] = {0,
0,2,3,7,11,19,25,26,29,30,
33,34,38,39,45,46,53,56,60,66,
74,78,80,82,86,88,91,93,95,97,
101,105,109,113,117,121,125,129,131,133,
136,139,143,145,149,151,155,160,166,168,

};

long yyyIIEL[] = {
0,0,2,4,6,8,10,10,12,14,15,15,
16,16,17,17,18,18,21,21,23,23,24,24,
25,25,26,27,28,29,30,31,32,33,36,39,
42,45,45,49,53,57,58,58,61,61,64,67,
70,73,73,76,76,76,79,79,82,85,85,88,
88,91,91,95,95,98,98,101,101,104,104,105,
105,108,108,111,114,114,117,120,123,126,127,130,
133,133,134,137,140,143,143,146,149,152,155,158,
161,164,167,170,170,173,176,179,179,182,185,188,
188,191,194,197,197,200,203,206,206,209,212,215,
215,218,221,224,224,227,230,233,233,236,236,236,
236,236,236,236,236,236,236,236,239,239,242,242,
245,246,249,252,252,253,256,257,260,261,261,261,
264,265,265,268,268,271,272,272,275,275,275,278,
281,284,287,287,
};

long yyyIEL[] = {
0,2,2,2,2,2,4,6,
6,8,10,10,14,16,16,16,
18,18,20,20,20,20,20,20,
22,24,24,24,26,28,28,28,
30,32,32,32,32,36,40,44,
44,44,44,44,44,44,44,44,
44,44,48,48,52,56,56,58,
58,58,60,60,60,60,60,60,
60,66,72,78,78,78,78,78,
78,78,78,78,78,80,82,84,
84,84,84,86,88,90,90,90,
90,94,98,102,102,104,104,104,
104,104,104,108,114,118,118,118,
118,120,120,120,120,124,128,132,
132,132,132,132,132,132,134,136,
138,138,138,138,138,138,138,138,
140,142,144,144,144,144,144,146,
148,150,150,150,150,152,154,156,
156,156,156,158,160,162,162,162,
162,164,166,168,168,168,168,170,
172,174,174,174,174,178,182,186,
186,186,186,186,186,186,190,194,
198,198,198,198,198,198,198,202,
206,210,210,210,210,210,210,210,
214,218,222,222,222,222,222,222,
222,226,230,234,234,234,234,234,
234,234,238,242,246,246,246,246,
246,246,246,250,254,258,258,258,
258,258,258,258,262,266,270,270,
270,270,270,270,270,272,274,276,
276,276,276,276,276,276,276,278,
280,282,282,282,282,282,282,282,
282,282,282,282,282,282,284,286,
288,288,288,288,288,290,292,294,
294,294,294,294,296,298,300,300,
300,300,304,308,312,312,312,312,
312,312,312,
};

yyyFT yyyEntL[] = {
1,1,1,1,0,0,0,0,0,0,2,0,1,1,0,0,
6,1,6,0,0,1,0,0,0,0,0,0,0,0,0,0,
2,0,1,0,2,1,1,1,2,2,1,2,4,0,1,0,
4,1,1,2,4,2,1,3,0,1,0,1,4,0,2,0,
1,0,4,1,2,1,1,1,4,2,2,2,1,2,2,0,
2,1,2,2,2,0,2,1,2,2,2,0,4,0,4,1,
2,2,4,2,2,3,4,0,2,0,6,0,6,1,2,1,
6,0,6,2,2,2,6,0,3,0,1,0,3,1,1,1,
3,2,1,2,1,0,1,1,1,2,1,0,1,1,1,2,
1,0,1,1,1,2,2,0,2,1,2,2,1,0,1,1,
1,2,1,0,1,1,1,2,1,0,1,1,1,2,3,0,
1,0,3,1,1,1,3,2,1,2,3,0,1,0,3,1,
1,1,3,2,1,2,3,0,1,0,3,1,1,1,3,2,
1,2,3,0,1,0,3,1,1,1,3,2,1,2,3,0,
1,0,3,1,1,1,3,2,1,2,3,0,1,0,3,1,
1,1,3,2,1,2,3,0,1,0,3,1,1,1,3,2,
1,2,3,0,1,0,3,1,1,1,3,2,1,2,2,0,
2,1,2,2,1,0,1,1,1,2,3,0,3,1,3,2,
3,0,3,1,3,2,1,0,1,1,1,2,3,0,1,0,
3,1,1,1,3,2,1,2,
};

#define yyyPermitUserAlloc  0 


void yyyfatal(msg)
  char *msg; 
{fprintf(stderr,msg);exit(-1);} 



#define yyyNSof   'n' 
#define yyyRCof   'r' 
#define yyyCLof   'c' 
#define yyySof    's' 
#define yyySSALof 'S' 
#define yyyRSof   'q' 
#define yyyTSof   't' 



void yyyHandleOverflow(which) 
  char which; 
  {char *msg1,*msg2; 
   long  oldSize,newSize; 
   switch(which) 
     {
      case yyyNSof   : 
           msg1 = "node storage overflow: ";
           oldSize = yyyMaxNbytesNodeStg; 
           break; 
      case yyyRCof   : 
           msg1 = "dependee count overflow: ";
           oldSize = yyyMaxNrefCounts; 
           break; 
      case yyyCLof   : 
           msg1 = "child list overflow: ";
           oldSize = yyyMaxNchildren; 
           break; 
      case yyySof    : 
           msg1 = "parse-tree stack overflow: ";
           oldSize = yyyMaxStackSize; 
           break; 
      case yyySSALof : 
           msg1 = "SSAL overflow: ";
           oldSize = yyySSALspaceSize; 
           break; 
      case yyyRSof   : 
           msg1 = "ready set overflow: ";
           oldSize = yyyRSmaxSize; 
           break; 
      case yyyTSof   : 
           msg1 = "traversal stack overflow: ";
           oldSize = yyyTravStackMaxSize; 
           break; 
      default        :;  
     }
   newSize = (3*oldSize)/2; 
   if (newSize < 100) newSize = 100; 
   fprintf(stderr,msg1); 
   fprintf(stderr,"size was %d.\n",oldSize); 
   if (yyyPermitUserAlloc) 
      msg2 = "     Try -Y%c%d option.\n"; 
      else 
      msg2 = "     Have to modify evaluator:  -Y%c%d.\n"; 
   fprintf(stderr,msg2,which,newSize); 
   exit(-1); 
  }



void yyySignalEnts(node,startP,stopP) 
  register yyyGNT *node; 
  register yyyFT *startP,*stopP;  
  {register yyyGNT *dumNode; 

   while (startP < stopP)  
     {
      if (!(*startP)) dumNode = node;  
         else dumNode = (node->cL)[(*startP)-1];   
      if (!(--((dumNode->refCountList)[*(startP+1)]
              ) 
           )
         ) 
         { 
          if (++yyyRSTop == yyyAfterRS) 
             {yyyHandleOverflow(yyyRSof); 
              break; 
             }
          yyyRSTop->node = dumNode; 
          yyyRSTop->whichSym = *startP;  
          yyyRSTop->wa = *(startP+1);  
         }  
      startP += 2;  
     }  
  } 




#define yyyCeiling(num,inc) (((inc) * ((num)/(inc))) + (((num)%(inc))?(inc):0)) 



int yyyAlignSize = 4;
int yyyNdSz[9];

int yyyNdPrSz[9];

typedef int yyyCopyType;

int yyyNdCopySz[9];
long yyyBiggestNodeSize = 0;

void yyyNodeSizeCalc()
  {int i;
   yyyGNSz = yyyCeiling(yyyGNSz,yyyAlignSize); 
   yyyNdSz[0] = 0;
   yyyNdSz[1] = sizeof(struct yyyT1);
   yyyNdSz[2] = sizeof(struct yyyT2);
   yyyNdSz[3] = sizeof(struct yyyT3);
   yyyNdSz[4] = sizeof(struct yyyT4);
   yyyNdSz[5] = sizeof(struct yyyT5);
   yyyNdSz[6] = sizeof(struct yyyT6);
   yyyNdSz[7] = sizeof(struct yyyT7);
   yyyNdSz[8] = sizeof(struct yyyT8);
   for (i=0;i<9;i++) 
       {yyyNdSz[i] = yyyCeiling(yyyNdSz[i],yyyAlignSize); 
        yyyNdPrSz[i] = yyyNdSz[i] + yyyGNSz;
        if (yyyBiggestNodeSize < yyyNdSz[i])
           yyyBiggestNodeSize = yyyNdSz[i];
        yyyNdCopySz[i] = yyyCeiling(yyyNdSz[i],sizeof(yyyCopyType)) / 
                         sizeof(yyyCopyType); 
       }
  }




void yyySolveAndSignal() {
register long yyyiDum,*yyypL;
register int yyyws,yyywa;
register yyyGNT *yyyRSTopN,*yyyRefN; 
register void *yyyRSTopNp; 


yyyRSTopNp = (yyyRSTopN = yyyRSTop->node)->parent;
yyyRefN= (yyyws = (yyyRSTop->whichSym))?((yyyGNT *)yyyRSTopNp):yyyRSTopN;
yyywa = yyyRSTop->wa; 
yyyRSTop--;
switch(yyyRefN->prodNum) {
case 1:  /***yacc rule 1***/
  switch (yyyws) {
  case 1:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP5)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen);     break;
    }
  break;
  }
break;
case 2:  /***yacc rule 2***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 3:  /***yacc rule 3***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->struct_gen) = add_struct((((yyyP5)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen), (((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), (((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->felder));
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP5)(((char *)yyyRefN)+yyyGNSz))->structs);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 4:  /***yacc rule 4***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->struct_gen) = (((yyyP5)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen);     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 1:
(((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP5)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP4)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP5)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    }
  break;
  }
break;
case 5:  /***yacc rule 5***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  case 6:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP6)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->syms_gen);
		    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP4)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    }
  break;
  }
break;
case 6:  /***yacc rule 6***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->felder) = (((yyyP6)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->syms_gen);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 7:  /***yacc rule 7***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 8:  /***yacc rule 8***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->syms_gen) = add_symbol((((yyyP6)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->syms_gen), (((yyyP7)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), UNIQUE);     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 9:  /***yacc rule 9***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 10:  /***yacc rule 10***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->syms_gen) = add_symbol((((yyyP6)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->syms_gen), (((yyyP7)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), UNIQUE);     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 11:  /***yacc rule 11***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 12:  /***yacc rule 12***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 13:  /***yacc rule 13***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 14:  /***yacc rule 14***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->vars) = add_symbol((((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->vars), (((yyyP7)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), UNIQUE);     break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 3:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 15:  /***yacc rule 15***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 16:  /***yacc rule 16***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 17:  /***yacc rule 17***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 18:  /***yacc rule 18***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 19:  /***yacc rule 19***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 3:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = table_merge((((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->vars));
	    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 20:  /***yacc rule 20***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    }
  break;
  case 6:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = load_struct((((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs),(((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP7)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->name));
	    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 21:  /***yacc rule 21***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 22:  /***yacc rule 22***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 23:  /***yacc rule 23***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 24:  /***yacc rule 24***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 25:  /***yacc rule 25***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 26:  /***yacc rule 26***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 27:  /***yacc rule 27***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 28:  /***yacc rule 28***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 29:  /***yacc rule 29***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 30:  /***yacc rule 30***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 31:  /***yacc rule 31***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 32:  /***yacc rule 32***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 33:  /***yacc rule 33***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 34:  /***yacc rule 34***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 35:  /***yacc rule 35***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 36:  /***yacc rule 36***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 37:  /***yacc rule 37***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 38:  /***yacc rule 38***/
  switch (yyyws) {
  }
break;
case 39:  /***yacc rule 39***/
  switch (yyyws) {
  }
break;
case 40:  /***yacc rule 40***/
  switch (yyyws) {
  }
break;
case 41:  /***yacc rule 41***/
  switch (yyyws) {
  }
break;
case 42:  /***yacc rule 42***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 43:  /***yacc rule 43***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 44:  /***yacc rule 44***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 45:  /***yacc rule 45***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 46:  /***yacc rule 46***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  }
break;
case 47:  /***yacc rule 47***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 48:  /***yacc rule 48***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 49:  /***yacc rule 49***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 50:  /***yacc rule 50***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
} /* switch */ 

if (yyyws)  /* the just-solved instance was inherited. */ 
   {if (yyyRSTopN->prodNum) 
       {yyyiDum = yyyIIEL[yyyIIIEL[yyyRSTopN->prodNum]] + yyywa;
        yyySignalEnts(yyyRSTopN,yyyEntL + yyyIEL[yyyiDum],
                                yyyEntL + yyyIEL[yyyiDum+1]
                     );
       }
   } 
   else     /* the just-solved instance was synthesized. */ 
   {if ((char *)yyyRSTopNp >= yyyNodeSpace) /* node has a parent. */ 
       {yyyiDum = yyyIIEL[yyyIIIEL[((yyyGNT *)yyyRSTopNp)->prodNum] + 
                          yyyRSTopN->whichSym 
                         ] + 
                  yyywa;
        yyySignalEnts((yyyGNT *)yyyRSTopNp,
                      yyyEntL + yyyIEL[yyyiDum],
                      yyyEntL + yyyIEL[yyyiDum+1] 
                     );
       } 
       else   /* node is still on the stack--it has no parent yet. */ 
       {yyypL = &(((struct yyyStackItem *)yyyRSTopNp)->solvedSAlist); 
        if (yyySSALCfreeList == yyyLambdaSSAL) 
           {yyySSALspace[yyyNewSSALC].next = *yyypL; 
            if ((*yyypL = yyyNewSSALC++) == yyySSALspaceSize) 
               yyyHandleOverflow(yyySSALof); 
           }  
           else
           {yyyiDum = yyySSALCfreeList; 
            yyySSALCfreeList = yyySSALspace[yyySSALCfreeList].next; 
            yyySSALspace[yyyiDum].next = *yyypL; 
            *yyypL = yyyiDum;  
           } 
        yyySSALspace[*yyypL].attrbNum = yyywa; 
       } 
   }

} /* yyySolveAndSignal */ 






#define condStg unsigned int conds;
#define yyyClearConds {yyyTST->conds = 0;}
#define yyySetCond(n) {yyyTST->conds += (1<<(n));}
#define yyyCond(n) ((yyyTST->conds & (1<<(n)))?1:0)



struct yyyTravStackItem {yyyGNT *node; 
                         char isReady;
                         condStg
                        };



void yyyDoTraversals()
{struct yyyTravStackItem *yyyTravStack,*yyyTST,*yyyAfterTravStack;
 register yyyGNT *yyyTSTn,**yyyCLptr1,**yyyCLptr2; 
 register int yyyi,yyyRL,yyyPass;

 if (!yyyYok) return;
 if ((yyyTravStack = 
                 ((struct yyyTravStackItem *) 
                  malloc((yyyTravStackMaxSize * 
                                  sizeof(struct yyyTravStackItem)
                                 )
                        )
                 )
     )
     == 
     (struct yyyTravStackItem *)NULL
    ) 
    {fprintf(stderr,"malloc error in traversal stack allocation\n"); 
     exit(-1); 
    } 

yyyAfterTravStack = yyyTravStack + yyyTravStackMaxSize; 
yyyTravStack++; 


for (yyyi=0; yyyi<1; yyyi++) {
yyyTST = yyyTravStack; 
yyyTST->node = yyyStack->node;
yyyTST->isReady = 0;
yyyClearConds

while(yyyTST >= yyyTravStack)
  {yyyTSTn = yyyTST->node;
   if (yyyTST->isReady)  
      {yyyPass = 1;
       goto yyyTravSwitch;
yyyTpop:
       yyyTST--;
      } 
      else 
      {yyyPass = 0;
       goto yyyTravSwitch;
yyyTpush:
       yyyTST->isReady = 1;  
       if (yyyTSTn->prodNum)
          if (yyyRL)
             {yyyCLptr2 = yyyTSTn->cL; 
              while 
                ((yyyCLptr2 != yyyNextCLspace)
                 &&
                 ((*yyyCLptr2)->parent == yyyTSTn) 
                )  
                {if (++yyyTST == yyyAfterTravStack)
                    yyyHandleOverflow(yyyTSof);
                    else
                    {yyyTST->node = *yyyCLptr2; 
                     yyyTST->isReady = 0; 
                     yyyClearConds
                    }
                 yyyCLptr2++; 
                } 
             } /* right to left */
             else  /* left to right */
             {yyyCLptr1 = yyyCLptr2 = yyyTSTn->cL; 
              while 
                ((yyyCLptr2 != yyyNextCLspace)
                 &&
                 ((*yyyCLptr2)->parent == yyyTSTn) 
                )  
                yyyCLptr2++; 
              while (yyyCLptr2-- > yyyCLptr1)
                if (++yyyTST == yyyAfterTravStack)
                   yyyHandleOverflow(yyyTSof);
                   else
                   {yyyTST->node = *yyyCLptr2; 
                    yyyTST->isReady = 0; 
                    yyyClearConds
                   }
             } /* left to right */
      } /* else */
   continue;
yyyTravSwitch:
				switch(yyyTSTn->prodNum)	{
case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 2:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 3:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 4:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 5:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 6:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 7:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 8:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 9:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 10:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 11:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 12:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 13:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 14:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 15:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 16:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 17:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 18:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 19:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 20:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { check_struct_exists((((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP7)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->name));
		}
				break;
					}

break;
case 21:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 22:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 23:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists((((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->visible_structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP7)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name)); }
				break;
					}

break;
case 24:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists_feldkontext((((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP7)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->name)); }
				break;
					}

break;
case 25:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 26:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 27:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 28:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 29:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 30:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 31:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 32:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 33:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 34:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 35:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 36:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 37:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 38:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 39:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 40:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 41:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 42:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 43:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 44:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists_feldkontext((((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP7)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->name)); }
				break;
					}

break;
case 45:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists((((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->visible_structs), (((yyyP1)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP7)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name)); }
				break;
					}

break;
case 46:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 47:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 48:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 49:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
case 50:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}

break;
								} /* switch */ 
   if (yyyPass) goto yyyTpop; else goto yyyTpush; 
  } /* while */ 
 } /* for */ 
} /* yyyDoTraversals */ 

void yyyExecuteRRsection()  {
   int yyyi; 
   long yyynRefCounts; 
   long cycleSum = 0;
   long nNZrc = 0;

   if (!yyyYok) return; 
   yyynRefCounts = yyyNextRCLspace - yyyRefCountListSpace; 
   for (yyyi=0;yyyi<yyynRefCounts;yyyi++) 
     if (yyyRefCountListSpace[yyyi])
        {cycleSum += yyyRefCountListSpace[yyyi]; nNZrc++;} 
   if (nNZrc) 
      {
       fprintf(stderr,"\n\n\n**********\n");
       fprintf(stderr,
               "cycle detected in completed parse tree");
       fprintf(stderr,
               " after decoration.\n");
       fprintf(stderr,
         "searching parse tree for %d unsolved instances:\n",
               nNZrc
              );
       yyyUnsolvedInstSearchTravAux(yyyStackTop->node);
      }
   yyyDoTraversals();
} /* yyyExecuteRRsection */ 



yyyWAT yyyLRCIL[2] = {0,0,
};



void yyyYoxInit()                                  /*stock*/  
  { 

   yyyNodeSizeCalc(); 

   if ((yyyTermBuffer.snBufPtr = 
        (char *) malloc((yyyBiggestNodeSize + sizeof(yyyCopyType)))
       )  
       == 
       ((char *) NULL) 
      )   
      yyyfatal("malloc error in yyyTermBuffer allocation\n");  
  
  
   yyyNbytesStackStg = yyyMaxStackSize*sizeof(struct yyyStackItem); 
   yyyNbytesStackStg = ((yyyNbytesStackStg/yyyAlignSize)+1)*yyyAlignSize;  
   if ((yyyNodeAndStackSpace = 
        (char *) malloc((yyyNbytesStackStg + 
                                 yyyMaxNbytesNodeStg + 
                                 yyyGNSz + 
                                 yyyBiggestNodeSize + 
                                 sizeof(yyyCopyType) 
                                )
                       )
       )  
       == 
       ((char *) NULL) 
      )   
      yyyfatal("malloc error in ox node and stack space allocation\n");
   yyyStack = (struct yyyStackItem *) yyyNodeAndStackSpace; 
   yyyAfterStack = yyyStack + yyyMaxStackSize;  
   yyyNodeSpace = yyyNodeAndStackSpace + yyyNbytesStackStg;
   yyyAfterNodeSpace = yyyNodeSpace + yyyMaxNbytesNodeStg;
 
 
   if ((yyyRS = (struct yyyRSitem *) 
         malloc(((yyyRSmaxSize+1)*sizeof(struct yyyRSitem)))
       )  
       == 
       ((struct yyyRSitem *) NULL) 
      )   
      yyyfatal("malloc error in ox ready set space allocation\n");  
   yyyRS++; 
   yyyAfterRS = yyyRS + yyyRSmaxSize; 

 
   if ((yyyChildListSpace = 
        (yyyGNT **) malloc((yyyMaxNchildren*sizeof(yyyGNT *)))
       )  
       == 
       ((yyyGNT **) NULL) 
      )   
      yyyfatal("malloc error in ox child list space allocation\n");  
   yyyAfterChildListSpace = yyyChildListSpace + yyyMaxNchildren; 

 
   if ((yyyRefCountListSpace = 
        (yyyRCT *) malloc((yyyMaxNrefCounts * sizeof(yyyRCT)))
       )  
       == 
       ((yyyRCT *) NULL) 
      )   
      yyyfatal("malloc error in ox reference count list space allocation\n");  
   yyyAfterRefCountListSpace = yyyRefCountListSpace + yyyMaxNrefCounts;  
  
 
   if ((yyySSALspace = (struct yyySolvedSAlistCell *) 
          malloc(((yyySSALspaceSize+1) * 
                          sizeof(struct yyySolvedSAlistCell))
                         ) 
       ) 
       == 
       ((struct yyySolvedSAlistCell *) NULL) 
      ) 
      yyyfatal("malloc error in stack solved list space allocation\n"); 
  } /* yyyYoxInit */ 



void yyyYoxReset() 
  { 
   yyyTermBuffer.isEmpty = 1; 
   yyyStackTop = yyyStack; 
   while (yyyStackTop != yyyAfterStack) 
     (yyyStackTop++)->solvedSAlist = yyyLambdaSSAL; 
   yyyStackTop = yyyStack - 1; 
   yyyNextNodeSpace = yyyNodeSpace; 
   yyyRSTop = yyyRS - 1; 
   yyyNextCLspace = yyyChildListSpace;
   yyyNextRCLspace = yyyRefCountListSpace; 
  }  



void yyyDecorate() 
  { 
   while (yyyRSTop >= yyyRS) 
      yyySolveAndSignal();  
  } 



void yyyShift() 
  {yyyRCT *rcPdum; 
   register yyyCopyType *CTp1,*CTp2,*CTp3; 
   register yyyWAT *startP,*stopP;  

   if ((++yyyStackTop) == yyyAfterStack) 
      yyyHandleOverflow(yyySof);
   CTp2 = (yyyCopyType *)(yyyStackTop->oldestNode = 
                          yyyStackTop->node = 
                          (yyyGNT *)yyyNextNodeSpace 
                         ); 
   yyyTermBuffer.isEmpty = 1;
   ((yyyGNT *)CTp2)->parent = (void *)yyyStackTop; 
   ((yyyGNT *)CTp2)->cL = yyyNextCLspace;  
   rcPdum = ((yyyGNT *)CTp2)->refCountList = yyyNextRCLspace;  
   ((yyyGNT *)CTp2)->prodNum = 0; 
   if ((yyyNextRCLspace += yyyTermBuffer.nAttrbs) 
       > 
       yyyAfterRefCountListSpace 
      ) 
      yyyHandleOverflow(yyyRCof); 
   startP = yyyTermBuffer.startP;  
   stopP = yyyTermBuffer.stopP;  
   while (startP < stopP) rcPdum[*(startP++)] = 0; 
   if ((yyyNextNodeSpace += yyyNdPrSz[yyyTermBuffer.typeNum]) 
       > 
       yyyAfterNodeSpace 
      ) 
      yyyHandleOverflow(yyyNSof);  
   CTp1 = (yyyCopyType *)(yyyTermBuffer.snBufPtr); 
   CTp2 = (yyyCopyType *)(((char *)CTp2) + yyyGNSz); 
   CTp3 = CTp2 + yyyNdCopySz[yyyTermBuffer.typeNum]; 
   while (CTp2 < CTp3) *CTp2++ = *CTp1++; 
  } 



void yyyGenIntNode() 
  {register yyyWST i;
   register struct yyyStackItem *stDum;  
   register yyyGNT *gnpDum; 

   if ((stDum = (yyyStackTop -= (yyyRHSlength-1))) >= yyyAfterStack) 
      yyyHandleOverflow(yyySof);
   yyySTsn = ((char *)(yyySTN = (yyyGNT *)yyyNextNodeSpace)) + yyyGNSz; 
   yyySTN->parent       =  (void *)yyyStackTop;  
   yyySTN->cL           =  yyyNextCLspace; 
   yyySTN->refCountList =  yyyNextRCLspace; 
   yyySTN->prodNum      =  yyyProdNum; 
   if ((yyyNextCLspace+yyyRHSlength) > yyyAfterChildListSpace) 
      yyyHandleOverflow(yyyCLof); 
   for (i=1;i<=yyyRHSlength;i++) 
     {gnpDum = *(yyyNextCLspace++) = (stDum++)->node;  
      gnpDum->whichSym = i;  
      gnpDum->parent = (void *)yyyNextNodeSpace; 
     } 
   if ((yyyNextRCLspace += yyyNattrbs) > yyyAfterRefCountListSpace) 
      yyyHandleOverflow(yyyRCof); 
   if ((yyyNextNodeSpace += yyyNdPrSz[yyyTypeNum]) > yyyAfterNodeSpace) 
      yyyHandleOverflow(yyyNSof);  
  } 



#define yyyDECORfREQ 50 



void yyyAdjustINRC(startP,stopP) 
  register yyyFT *startP,*stopP;
  {yyyWST i;
   long SSALptr,SSALptrHead,*cPtrPtr; 
   long *pL; 
   struct yyyStackItem *stDum;  
   yyyGNT *gnpDum; 
   long iTemp;
   register yyyFT *nextP;
   static unsigned short intNodeCount = yyyDECORfREQ;

   nextP = startP;
   while (nextP < stopP) 
     {if ((*nextP) == yyyR)  
         {(yyySTN->refCountList)[*(nextP+1)] = *(nextP+2);
         } 
         else 
         {(((yyySTN->cL)[*nextP])->refCountList)[*(nextP+1)] = *(nextP+2);
         } 
      nextP += 3;  
     }
   pL = yyyIIEL + yyyIIIEL[yyyProdNum]; 
   stDum = yyyStackTop;  
   for (i=1;i<=yyyRHSlength;i++) 
     {pL++; 
      SSALptrHead = SSALptr = *(cPtrPtr = &((stDum++)->solvedSAlist)); 
      if (SSALptr != yyyLambdaSSAL) 
         {*cPtrPtr = yyyLambdaSSAL; 
          do 
            {
             iTemp = (*pL+yyySSALspace[SSALptr].attrbNum);
             yyySignalEnts(yyySTN,
                           yyyEntL + yyyIEL[iTemp],
                           yyyEntL + yyyIEL[iTemp+1]
                          );  
             SSALptr = *(cPtrPtr = &(yyySSALspace[SSALptr].next)); 
            } 
            while (SSALptr != yyyLambdaSSAL);  
          *cPtrPtr = yyySSALCfreeList;  
          yyySSALCfreeList = SSALptrHead;  
         } 
     } 
   nextP = startP + 2;
   while (nextP < stopP) 
     {if (!(*nextP))
         {if ((*(nextP-2)) == yyyR)  
             {pL = &(yyyStackTop->solvedSAlist); 
              if (yyySSALCfreeList == yyyLambdaSSAL) 
                 {yyySSALspace[yyyNewSSALC].next = *pL; 
                  if ((*pL = yyyNewSSALC++) == yyySSALspaceSize) 
                     yyyHandleOverflow(yyySSALof); 
                 }  
                 else
                 {iTemp = yyySSALCfreeList; 
                  yyySSALCfreeList = yyySSALspace[yyySSALCfreeList].next; 
                  yyySSALspace[iTemp].next = *pL; 
                  *pL = iTemp;  
                 } 
              yyySSALspace[*pL].attrbNum = *(nextP-1); 
             } 
             else 
             {if ((gnpDum = (yyySTN->cL)[*(nextP-2)])->prodNum != 0)
                 {
                  iTemp = yyyIIEL[yyyIIIEL[gnpDum->prodNum]] + *(nextP-1);
                  yyySignalEnts(gnpDum, 
                                yyyEntL + yyyIEL[iTemp],  
                                yyyEntL + yyyIEL[iTemp+1] 
                               );    
                 }  
             } 
         } 
      nextP += 3; 
     } 
   yyyStackTop->node = yyySTN;
   if (!yyyRHSlength) yyyStackTop->oldestNode = yyySTN; 
   if (!--intNodeCount) 
      {intNodeCount = yyyDECORfREQ; 
       yyyDecorate(); 
      } 
  } 



void yyyPrune(prodNum) 
  long prodNum;
  {  
   int i,n; 
   register char *cp1,*cp2;  
   register yyyRCT *rcp1,*rcp2,*rcp3;  
   long cycleSum = 0;
   long nNZrc = 0;
   yyyRCT *tempNextRCLspace;
   
   yyyDecorate();
   tempNextRCLspace = yyyNextRCLspace;
   yyyNextRCLspace = 
     (rcp1 = rcp2 = (yyyStackTop->oldestNode)->refCountList) + yyyNattrbs;
   rcp3 = (yyyStackTop->node)->refCountList; 
   while (rcp2 < rcp3) 
     if (*rcp2++) {cycleSum += *(rcp2 - 1); nNZrc++;} 
   if (nNZrc) 
      {
       fprintf(stderr,"\n\n\n----------\n");
       fprintf(stderr,
         "cycle detected during pruning of a subtree\n");
       fprintf(stderr,
         "  at whose root production %d is applied.\n",prodNum);
       yyyNextRCLspace = tempNextRCLspace; 
       fprintf(stderr,
         "prune aborted: searching subtree for %d unsolved instances:\n",
               nNZrc
              );
       yyyUnsolvedInstSearchTrav(yyyStackTop->node);
       return; 
      }
   for (i=0;i<yyyNattrbs;i++) rcp1[i] = rcp3[i]; 
   yyyNextCLspace = (yyyStackTop->oldestNode)->cL; 
   yyyNextNodeSpace = (char *)(yyyStackTop->oldestNode) + 
                      (n = yyyNdPrSz[yyyTypeNum]);
   cp1 = (char *)yyyStackTop->oldestNode; 
   cp2 = (char *)yyyStackTop->node; 
   for (i=0;i<n;i++) *cp1++ = *cp2++; 
   yyyStackTop->node = yyyStackTop->oldestNode; 
   (yyyStackTop->node)->refCountList = rcp1; 
   (yyyStackTop->node)->cL = yyyNextCLspace; 
  } 



void yyyGenLeaf(nAttrbs,typeNum,startP,stopP) 
  int nAttrbs,typeNum; 
  yyyWAT *startP,*stopP; 
  {
   if  (!(yyyTermBuffer.isEmpty)) yyyShift(); 
   yyyTermBuffer.isEmpty = 0;
   yyyTermBuffer.typeNum = typeNum; 
   yyyTermBuffer.nAttrbs = nAttrbs; 
   yyyTermBuffer.startP = startP; 
   yyyTermBuffer.stopP = stopP; 
   
  } 



void yyyerror()
  {yyyYok = 0; 
  } 



/* read the command line for changes in sizes of 
                  the evaluator's data structures */
void yyyCheckForResizes(argc,argv) 
  int argc; 
  char *argv[]; 
  {int i; 
   long dum; 
 
   if (!yyyPermitUserAlloc) return; 
   for (i=1;i<argc;i++) 
     { 
      if ((argv[i][0] != '-') || (argv[i][1] != 'Y')) continue; 
      if (strlen(argv[i]) < 4) goto yyyErrO1; 
      if (sscanf(argv[i]+3,"%d",&dum) != 1) goto yyyErrO1;
      if (dum < 2) dum = 2;
      switch (argv[i][2]) 
        {case yyyNSof:   yyyMaxNbytesNodeStg = dum; break; 
         case yyyRCof:   yyyMaxNrefCounts    = dum; break; 
         case yyyCLof:   yyyMaxNchildren     = dum; break; 
         case yyySof:    yyyMaxStackSize     = dum; break; 
         case yyySSALof: yyySSALspaceSize    = dum; break; 
         case yyyRSof:   yyyRSmaxSize        = dum; break; 
         case yyyTSof:   yyyTravStackMaxSize = dum; break; 
         default : goto yyyErrO1; 
        }
      continue;  
   yyyErrO1 : fprintf(stderr,"invalid command line option: %s\n",
                             argv[i] 
                     ); 
     } 
  } 
   
   
   


#define yyyLastProdNum 50


#define yyyNsorts 8


int yyyProdsInd[] = {
   0,
   0,   2,   3,   7,  11,  19,  25,  26,  29,  30,
  33,  34,  38,  39,  45,  46,  53,  56,  60,  66,
  74,  78,  80,  82,  86,  88,  91,  93,  95,  97,
 101, 105, 109, 113, 117, 121, 125, 129, 131, 133,
 136, 139, 143, 145, 149, 151, 155, 160, 166, 168,
 172,
};


int yyyProds[][2] = {
{ 581,   0},{1013,   5},{1013,   5},{1013,   5},{1013,   5},
{ 172,   3},{ 748,   0},{1013,   5},{1013,   5},{ 165,   4},
{ 748,   0},{ 165,   4},{ 758,   0},{ 722,   7},{ 220,   0},
{  18,   6},{  14,   0},{  63,   1},{ 821,   0},{ 172,   3},
{1140,   0},{ 722,   7},{ 623,   0},{ 804,   6},{ 821,   0},
{  18,   6},{  18,   6},{  18,   6},{ 722,   7},{ 804,   6},
{ 804,   6},{ 804,   6},{ 722,   7},{  63,   1},{  63,   1},
{  63,   1},{ 246,   1},{ 748,   0},{1081,   2},{1081,   2},
{1081,   2},{ 722,   7},{ 834,   0},{ 430,   1},{ 748,   0},
{1153,   1},{1153,   1},{1153,   1},{ 430,   1},{ 547,   0},
{  63,   1},{ 821,   0},{ 748,   0},{ 246,   1},{1050,   0},
{ 430,   1},{ 246,   1},{ 822,   0},{1153,   1},{ 821,   0},
{ 246,   1},{ 930,   0},{1081,   2},{ 131,   0},{  63,   1},
{ 821,   0},{ 246,   1},{ 457,   0},{ 430,   1},{ 623,   0},
{ 722,   7},{  98,   0},{  63,   1},{ 821,   0},{ 246,   1},
{ 286,   1},{ 834,   0},{ 430,   1},{ 246,   1},{ 997,   1},
{ 286,   1},{ 722,   7},{ 286,   1},{ 997,   1},{ 616,   0},
{ 722,   7},{ 430,   1},{ 997,   1},{ 430,   1},{ 384,   0},
{ 997,   1},{ 430,   1},{ 349,   1},{ 430,   1},{ 418,   1},
{ 430,   1},{ 394,   1},{ 430,   1},{ 997,   1},{ 806,   0},
{ 997,   1},{ 430,   1},{ 997,   1},{ 838,   0},{ 997,   1},
{ 349,   1},{ 997,   1},{ 442,   0},{ 997,   1},{ 349,   1},
{ 349,   1},{ 442,   0},{ 997,   1},{ 418,   1},{ 997,   1},
{1224,   0},{ 997,   1},{ 418,   1},{ 418,   1},{1224,   0},
{ 997,   1},{ 394,   1},{ 997,   1},{ 998,   0},{ 997,   1},
{ 394,   1},{ 394,   1},{ 998,   0},{ 997,   1},{ 384,   0},
{1126,   0},{ 384,   0},{ 443,   0},{ 384,   0},{ 384,   0},
{1126,   0},{ 384,   0},{ 384,   0},{ 443,   0},{ 997,   1},
{ 220,   0},{ 430,   1},{  14,   0},{ 997,   1},{  57,   8},
{ 997,   1},{ 997,   1},{ 616,   0},{ 722,   7},{ 997,   1},
{ 722,   7},{ 997,   1},{ 722,   7},{ 220,   0},{  14,   0},
{ 997,   1},{ 722,   7},{ 220,   0},{ 867,   1},{  14,   0},
{ 997,   1},{ 722,   7},{ 220,   0},{ 867,   1},{ 744,   0},
{  14,   0},{ 867,   1},{ 430,   1},{ 867,   1},{ 867,   1},
{ 744,   0},{ 430,   1},
};


int yyySortsInd[] = {
  0,
  0,  3,  7,  9, 10, 12, 13, 14,
 15,
};


int yyySorts[] = {
  965,   97,   20,  965,  152,   97,   20,  836,  381,   97,
  717,   97,  755,  381,  423,
};



char *yyyStringTab[] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"T_BRACKET_RIGHT",
0,0,0,"Params",0,
"visible_structs",0,0,0,0,
0,0,0,0,"unsigned",
0,0,0,0,"struct_table",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"T_NUM",0,0,
0,0,0,"Stats",0,
0,0,0,0,0,
0,0,0,"struct",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"structs","T_DO",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"exists",
0,0,"t",0,0,
0,0,"y",0,0,
0,0,0,0,0,
0,"T_IN",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"vars",0,"EMPTY",
0,0,0,0,0,
0,0,0,0,0,
"Funcdef",0,0,0,0,
0,0,"Structdef",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"T_BRACKET_LEFT",0,"NULL",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"Stat",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"Lexpr",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"assert",0,0,0,
0,0,0,0,"PlusExpr",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"name",0,0,"Sign",
0,0,0,0,0,
0,0,0,0,"OrExpr",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"strdup",0,"MultExpr",0,
0,0,0,"val",0,
0,0,0,0,0,
"Expr",0,0,0,0,
0,0,0,"load",0,
0,0,"T_PLUS","T_MINUS",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"T_WITH",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"symbol_t",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"T_THEN",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"atoi",
0,0,0,0,0,
0,0,0,0,0,
0,"Input",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"check","T_POINT",0,0,0,
0,0,0,"T_DOUBLE_POINT",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"UNIQUE",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"struct_gen",0,0,
0,0,"T_ID",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"T_COLON",
0,0,0,"T_SEMICOLON",0,
0,0,0,0,0,
"syms_gen",0,0,"T_FUNC",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"Felder",
0,"T_GREATER",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"T_END","T_COND","symbol",0,
0,0,0,0,0,
0,0,0,0,"T_EQUAL",
0,"felder",0,"T_NOT_EQUAL",0,
0,0,0,0,0,
0,0,0,0,"feldkontext",
0,0,"TABLE",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"ExprList",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"T_LET",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"symbols",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"Term","T_OR",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"Program",0,
0,0,0,0,0,
0,0,0,"yytext",0,
0,"int",0,0,0,
0,0,0,0,"merge",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"T_RETURN",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"LetRec",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"table","sscanf",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"T_NOT",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"T_STRUCT",0,0,0,0,
"add",0,0,0,0,
0,0,0,"CondRec",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"hex",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"T_MUL",
0,0,0,0,0,
0,
};



#define yyySizeofProd(num) (yyyProdsInd[(num)+1] - yyyProdsInd[(num)])

#define yyyGSoccurStr(prodNum,symPos) \
   (yyyStringTab[yyyProds[yyyProdsInd[(prodNum)] + (symPos)][0]])

#define yyySizeofSort(num) (yyySortsInd[(num)+1] - yyySortsInd[(num)])

#define yyySortOf(prodNum,symPos) \
  (yyyProds[yyyProdsInd[(prodNum)] + (symPos)][1]) 

#define yyyAttrbStr(prodNum,symPos,attrbNum)                      \
  (yyyStringTab[yyySorts[yyySortsInd[yyySortOf(prodNum,symPos)] + \
                         (attrbNum)                               \
                        ]                                         \
               ]                                                  \
  )



void yyyShowProd(i)
  int i;
  {int j,nSyms;

   nSyms = yyySizeofProd(i);
   for (j=0; j<nSyms; j++)
     {
      fprintf(stderr,"%s",yyyGSoccurStr(i,j));
      if (j == 0) fprintf(stderr," : "); else fprintf(stderr," ");
     }
   fprintf(stderr,";\n");
  }



void yyyShowProds()
  {int i; for (i=1; i<=yyyLastProdNum; i++) yyyShowProd(i);}



void yyyShowSymsAndSorts()
  {int i; 

   for (i=1; i<=yyyLastProdNum; i++) 
     {int j, nSyms;

      fprintf(stderr,
              "\n\n\n---------------------------------- %3.1d\n",i);
      /* yyyShowProd(i); */ 
      nSyms = yyySizeofProd(i); 
      for (j=0; j<nSyms; j++) 
        {int k, sortSize;

         fprintf(stderr,"%s\n",yyyGSoccurStr(i,j));
         sortSize = yyySizeofSort(yyySortOf(i,j));
         for (k=0; k<sortSize; k++) 
            fprintf(stderr,"  %s\n",yyyAttrbStr(i,j,k));
         if (j == 0) fprintf(stderr,"->\n"); 
              else 
              fprintf(stderr,"\n"); 
        }
     }
  }



void yyyCheckNodeInstancesSolved(np)
  yyyGNT *np;
  {int mysort,sortSize,i,prodNum,symPos,inTerminalNode;
   int nUnsolvedInsts = 0;

   if (np->prodNum != 0)
     {inTerminalNode = 0;
      prodNum = np->prodNum;
      symPos = 0;
     }
   else
     {inTerminalNode = 1;
      prodNum = ((yyyGNT *)(np->parent))->prodNum;
      symPos = np->whichSym;
     }
   mysort = yyySortOf(prodNum,symPos);
   sortSize = yyySizeofSort(mysort);
   for (i=0; i<sortSize; i++)
     if ((np->refCountList)[i] != 0) nUnsolvedInsts += 1;
   if (nUnsolvedInsts)
     {fprintf(stderr,
      "\nFound node that has %d unsolved attribute instance(s).\n",
              nUnsolvedInsts
             );
      fprintf(stderr,"Node is labeled \"%s\".\n",
             yyyGSoccurStr(prodNum,symPos));
      if (inTerminalNode)
        {fprintf(stderr,
                 "Node is terminal.  Its parent production is:\n  ");
         yyyShowProd(prodNum);
        }
      else
        {fprintf(stderr,"Node is nonterminal.  ");
         if (((char *)(np->parent)) >= yyyNodeSpace)
           {fprintf(stderr,
                    "Node is %dth child in its parent production:\n  ",
                   np->whichSym
                  );
            yyyShowProd(((yyyGNT *)(np->parent))->prodNum);
           }
         fprintf(stderr,
                 "Node is on left hand side of this production:\n  ");
         yyyShowProd(np->prodNum);
        }
      fprintf(stderr,"The following instances are unsolved:\n");
      for (i=0; i<sortSize; i++)
        if ((np->refCountList)[i] != 0)
          fprintf(stderr,"     %-16s still has %1d dependencies.\n",
                  yyyAttrbStr(prodNum,symPos,i),(np->refCountList)[i]);
     }
  }



void yyyUnsolvedInstSearchTravAux(pNode)
  yyyGNT *pNode;
  {yyyGNT **yyyCLpdum;
   int i;
  
   yyyCheckNodeInstancesSolved(pNode); 
   yyyCLpdum = pNode->cL;
   while
     ((yyyCLpdum != yyyNextCLspace) && ((*yyyCLpdum)->parent == pNode))
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }



void yyyUnsolvedInstSearchTrav(pNode)
  yyyGNT *pNode;
  {yyyGNT **yyyCLpdum;
   int i;
  
   yyyCLpdum = pNode->cL;
   while
     ((yyyCLpdum != yyyNextCLspace) && ((*yyyCLpdum)->parent == pNode))
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }



