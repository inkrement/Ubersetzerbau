

struct yyyT1 { struct symbol_t *functions; struct symbol_t *structs; struct symbol_t *fields;}; 
typedef struct yyyT1 *yyyP1; 


struct yyyT2 { struct symbol_t *symbols;}; 
typedef struct yyyT2 *yyyP2; 


struct yyyT3 { struct symbol_t *params;}; 
typedef struct yyyT3 *yyyP3; 


struct yyyT4 { char *name; }; 
typedef struct yyyT4 *yyyP4; 
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

