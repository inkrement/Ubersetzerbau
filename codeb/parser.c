/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 2 "oxout.y"


/* Line 268 of yacc.c  */
#line 21 "oxout.y"

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


/* Line 268 of yacc.c  */
#line 41 "oxout.y"



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



/* Line 268 of yacc.c  */
#line 127 "oxout.y"

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


/* Line 268 of yacc.c  */
#line 214 "oxout.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_WITH = 258,
     T_STRUCT = 259,
     T_RETURN = 260,
     T_NUM = 261,
     T_COND = 262,
     T_END = 263,
     T_ID = 264,
     T_LET = 265,
     T_IN = 266,
     T_FUNC = 267,
     T_OR = 268,
     T_NOT = 269,
     T_DO = 270,
     T_THEN = 271,
     T_BRACKET_LEFT = 272,
     T_BRACKET_RIGHT = 273,
     T_DOUBLE_POINT = 274,
     T_SEMICOLON = 275,
     T_EQUAL = 276,
     T_POINT = 277,
     T_MINUS = 278,
     T_PLUS = 279,
     T_MUL = 280,
     T_GREATER = 281,
     T_NOT_EQUAL = 282,
     T_COLON = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 284 "oxout.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    10,    14,    18,    26,
      32,    33,    36,    37,    40,    41,    45,    46,    52,    53,
      60,    63,    67,    73,    81,    85,    87,    89,    93,    95,
      98,   101,   103,   106,   109,   111,   113,   115,   119,   123,
     127,   131,   135,   139,   143,   147,   151,   153,   157,   159,
     163,   168,   174,   176
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      30,     0,    -1,    -1,    31,    32,    -1,    33,    -1,    -1,
      33,    35,    20,    -1,    33,    34,    20,    -1,    12,     9,
      17,    36,    18,    38,     8,    -1,     4,     9,    19,    37,
       8,    -1,    -1,    36,     9,    -1,    -1,    37,     9,    -1,
      -1,    38,    41,    20,    -1,    -1,    39,     9,    21,    44,
      20,    -1,    -1,    40,    44,    16,    38,     8,    20,    -1,
       5,    44,    -1,     7,    40,     8,    -1,    10,    39,    11,
      38,     8,    -1,     3,    44,    19,     9,    15,    38,     8,
      -1,    42,    21,    44,    -1,    48,    -1,     9,    -1,    48,
      22,     9,    -1,    48,    -1,    23,    43,    -1,    14,    43,
      -1,    48,    -1,    23,    43,    -1,    14,    43,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    26,    48,    -1,    48,
      27,    48,    -1,    48,    24,    48,    -1,    45,    24,    48,
      -1,    48,    25,    48,    -1,    46,    25,    48,    -1,    48,
      13,    48,    -1,    47,    13,    48,    -1,    17,    44,    18,
      -1,     6,    -1,    48,    22,     9,    -1,     9,    -1,     9,
      17,    18,    -1,     9,    17,    49,    18,    -1,     9,    17,
      49,    28,    18,    -1,    44,    -1,    49,    28,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   162,   173,   181,   185,   190,   197,   206,
     215,   221,   229,   235,   244,   247,   255,   262,   271,   276,
     283,   288,   293,   298,   303,   308,   316,   321,   328,   334,
     340,   347,   352,   357,   362,   367,   372,   377,   382,   389,
     394,   401,   406,   413,   418,   425,   430,   436,   441,   446,
     451,   456,   463,   468
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_WITH", "T_STRUCT", "T_RETURN",
  "T_NUM", "T_COND", "T_END", "T_ID", "T_LET", "T_IN", "T_FUNC", "T_OR",
  "T_NOT", "T_DO", "T_THEN", "T_BRACKET_LEFT", "T_BRACKET_RIGHT",
  "T_DOUBLE_POINT", "T_SEMICOLON", "T_EQUAL", "T_POINT", "T_MINUS",
  "T_PLUS", "T_MUL", "T_GREATER", "T_NOT_EQUAL", "T_COLON", "$accept",
  "yyyAugNonterm", "$@1", "Input", "Program", "Funcdef", "Structdef",
  "Params", "Felder", "Stats", "LetRec", "CondRec", "Stat", "Lexpr",
  "SignExpr", "Expr", "PlusExpr", "MultExpr", "OrExpr", "Term", "ExprList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    31,    30,    32,    33,    33,    33,    34,    35,
      36,    36,    37,    37,    38,    38,    39,    39,    40,    40,
      41,    41,    41,    41,    41,    41,    42,    42,    43,    43,
      43,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    49,    49
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     3,     3,     7,     5,
       0,     2,     0,     2,     0,     3,     0,     5,     0,     6,
       2,     3,     5,     7,     3,     1,     1,     3,     1,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       4,     5,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     3,     4,     0,     0,     0,     0,
       0,     0,     7,     6,    12,    10,     0,     0,     9,    13,
      11,    14,     0,     0,     0,    46,    18,     8,    48,    16,
       0,     0,     0,    25,    48,     0,     0,     0,    34,    35,
      36,    31,    20,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    33,    28,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    49,    52,     0,
       0,    14,    45,    24,    47,    30,    29,     0,    40,    42,
      44,    43,    47,    39,    41,    37,    38,    14,    50,     0,
       0,     0,    14,     0,    51,    53,     0,    22,     0,     0,
      17,    23,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,     5,     8,     9,    17,    16,    22,
      45,    43,    31,    32,    52,    37,    38,    39,    40,    41,
      69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
     -70,     4,   -70,   -70,   -70,    18,    -1,    17,    30,    33,
      19,    41,   -70,   -70,   -70,   -70,    40,    -6,   -70,   -70,
     -70,   -70,    85,    10,    10,   -70,   -70,   -70,   -11,   -70,
      10,    39,    36,    42,    46,    66,    66,    49,    53,    57,
      65,   113,   -70,    37,    38,     0,    63,   -70,    10,    75,
      66,    66,   -70,    64,   -70,    76,   136,   136,   136,   136,
      78,   136,   136,   136,   136,   -70,    80,   -70,   -70,   -13,
      77,   -70,   -70,   -70,    79,   -70,   -70,    82,    64,    64,
      64,    64,   -70,    64,    64,    64,    64,   -70,   -70,    56,
      10,    98,   -70,   111,   -70,   -70,    89,   -70,   124,    90,
     -70,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -69,
     -70,   -70,   -70,   -70,   -19,   -23,   -70,   -70,   -70,   -22,
     -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int8 yytable[] =
{
      33,    42,    91,    20,     3,    88,    44,    46,    10,    70,
     -26,    71,    21,    53,    53,    89,    25,    54,    93,    34,
      66,    68,     6,    98,    35,    73,    11,    30,    53,    53,
       7,    75,    76,    36,    78,    79,    80,    81,    14,    83,
      84,    85,    86,    25,    25,    65,    34,    34,    18,    19,
      12,    35,    35,    13,    30,    30,    67,    48,    15,    47,
      36,    36,    25,    44,    49,    34,    95,    96,    55,    33,
      35,    33,    25,    30,    94,    34,    33,    56,    58,    36,
      50,    72,    57,    30,    74,    77,    60,    82,    23,    51,
      24,    25,    26,    27,    28,    29,    87,    92,    90,     0,
     -27,    23,    30,    24,    25,    26,    97,    28,    29,   100,
     102,     0,     0,     0,    23,    30,    24,    25,    26,    99,
      28,    29,     0,     0,     0,     0,    59,    23,    30,    24,
      25,    26,   101,    28,    29,    60,     0,    61,    62,    63,
      64,    30,    25,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    30
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-70))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      22,    24,    71,     9,     0,    18,    17,    30,     9,     9,
      21,    11,    18,    35,    36,    28,     6,    36,    87,     9,
      43,    44,     4,    92,    14,    48,     9,    17,    50,    51,
      12,    50,    51,    23,    56,    57,    58,    59,    19,    61,
      62,    63,    64,     6,     6,     8,     9,     9,     8,     9,
      20,    14,    14,    20,    17,    17,    18,    21,    17,    20,
      23,    23,     6,    17,    22,     9,    89,    90,    19,    91,
      14,    93,     6,    17,    18,     9,    98,    24,    13,    23,
      14,    18,    25,    17,     9,     9,    22,     9,     3,    23,
       5,     6,     7,     8,     9,    10,    16,    15,    21,    -1,
      21,     3,    17,     5,     6,     7,     8,     9,    10,    20,
      20,    -1,    -1,    -1,     3,    17,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    13,     3,    17,     5,
       6,     7,     8,     9,    10,    22,    -1,    24,    25,    26,
      27,    17,     6,    -1,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,     0,    32,    33,     4,    12,    34,    35,
       9,     9,    20,    20,    19,    17,    37,    36,     8,     9,
       9,    18,    38,     3,     5,     6,     7,     8,     9,    10,
      17,    41,    42,    48,     9,    14,    23,    44,    45,    46,
      47,    48,    44,    40,    17,    39,    44,    20,    21,    22,
      14,    23,    43,    48,    43,    19,    24,    25,    13,    13,
      22,    24,    25,    26,    27,     8,    44,    18,    44,    49,
       9,    11,    18,    44,     9,    43,    43,     9,    48,    48,
      48,    48,     9,    48,    48,    48,    48,    16,    18,    28,
      21,    38,    15,    38,    18,    44,    44,     8,    38,     8,
      20,     8,    20
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 162 "oxout.y"
    {if (!yyyInitDone) 
		    {yyyYoxInit(); 
		     yyyInitDone = 1;
		    }
		 yyyYoxReset();
		}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 169 "oxout.y"
    {
		 yyyDecorate(); yyyExecuteRRsection();
		}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 174 "oxout.y"
    {if(yyyYok){
yyyRSU(1,1,0,0);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+0,yyyRCIL+3);/*yyyPrune(1);*/}}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 181 "oxout.y"
    {if(yyyYok){
yyyRSU(2,0,2,6);
yyyGenIntNode();
 (((yyyP6)yyySTsn)->struct_gen) = (struct struct_table *) NULL; yyyAdjustINRC(yyyRCIL+3,yyyRCIL+6);}}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 186 "oxout.y"
    {if(yyyYok){
yyyRSU(3,3,2,6);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+6,yyyRCIL+12);}}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 191 "oxout.y"
    {if(yyyYok){
yyyRSU(4,3,2,6);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+12,yyyRCIL+21);}}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 198 "oxout.y"
    {if(yyyYok){
yyyRSU(5,7,1,5);
yyyGenIntNode();
 (((yyyP1)(((char *)((yyySTN->cL)[5]))+yyyGNSz))->visible_structs) = NULL;

		yyyAdjustINRC(yyyRCIL+21,yyyRCIL+30);}}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 207 "oxout.y"
    {if(yyyYok){
yyyRSU(6,5,2,4);
yyyGenIntNode();
 (((yyyP4)yyySTsn)->name) = (((yyyP9)(((char *)((yyySTN->cL)[1]))+yyyGNSz))->name);
		yyyAdjustINRC(yyyRCIL+30,yyyRCIL+36);/*yyyPrune(6);*/}}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 215 "oxout.y"
    {if(yyyYok){
yyyRSU(7,0,2,7);
yyyGenIntNode();
 (((yyyP7)yyySTsn)->syms_gen) = EMPTY_TABLE;
		 (((yyyP7)yyySTsn)->index) = -1;
	yyyAdjustINRC(yyyRCIL+36,yyyRCIL+42);}}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 222 "oxout.y"
    {if(yyyYok){
yyyRSU(8,2,2,7);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+42,yyyRCIL+48);/*yyyPrune(8);*/}}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 229 "oxout.y"
    {if(yyyYok){
yyyRSU(9,0,2,8);
yyyGenIntNode();
 (((yyyP8)yyySTsn)->syms_gen) = EMPTY_TABLE;
		 (((yyyP8)yyySTsn)->offset) = -1;
	yyyAdjustINRC(yyyRCIL+48,yyyRCIL+54);}}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 236 "oxout.y"
    {if(yyyYok){
yyyRSU(10,2,2,8);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+54,yyyRCIL+60);/*yyyPrune(10);*/}}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 244 "oxout.y"
    {if(yyyYok){
yyyRSU(11,0,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+60,yyyRCIL+60);}}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 248 "oxout.y"
    {if(yyyYok){
yyyRSU(12,3,3,1);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+60,yyyRCIL+78);}}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 255 "oxout.y"
    {if(yyyYok){
yyyRSU(13,0,6,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->vars) = EMPTY_TABLE;
		 (((yyyP3)yyySTsn)->node) = new_leaf(OP_NOP);
		 (((yyyP3)yyySTsn)->reg) = NULL;
	yyyAdjustINRC(yyyRCIL+78,yyyRCIL+87);}}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 263 "oxout.y"
    {if(yyyYok){
yyyRSU(14,5,6,3);
yyyGenIntNode();
 (((yyyP3)yyySTsn)->reg) = newreg();
		yyyAdjustINRC(yyyRCIL+87,yyyRCIL+114);}}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 271 "oxout.y"
    {if(yyyYok){
yyyRSU(15,0,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = new_leaf(OP_NOP);
		yyyAdjustINRC(yyyRCIL+114,yyyRCIL+117);}}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 277 "oxout.y"
    {if(yyyYok){
yyyRSU(16,6,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+117,yyyRCIL+147);}}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 284 "oxout.y"
    {if(yyyYok){
yyyRSU(17,2,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+147,yyyRCIL+159);}}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 289 "oxout.y"
    {if(yyyYok){
yyyRSU(18,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+159,yyyRCIL+171);}}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 294 "oxout.y"
    {if(yyyYok){
yyyRSU(19,5,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+171,yyyRCIL+192);}}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 299 "oxout.y"
    {if(yyyYok){
yyyRSU(20,7,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+192,yyyRCIL+213);}}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 304 "oxout.y"
    {if(yyyYok){
yyyRSU(21,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+213,yyyRCIL+234);}}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 309 "oxout.y"
    {if(yyyYok){
yyyRSU(22,1,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = NULL;
	yyyAdjustINRC(yyyRCIL+234,yyyRCIL+246);}}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 317 "oxout.y"
    {if(yyyYok){
yyyRSU(23,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+246,yyyRCIL+249);}}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 322 "oxout.y"
    {if(yyyYok){
yyyRSU(24,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+249,yyyRCIL+261);}}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 329 "oxout.y"
    {if(yyyYok){
yyyRSU(25,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+261,yyyRCIL+273);}}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 335 "oxout.y"
    {if(yyyYok){
yyyRSU(26,2,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+273,yyyRCIL+285);}}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 341 "oxout.y"
    {if(yyyYok){
yyyRSU(27,2,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+285,yyyRCIL+297);}}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 348 "oxout.y"
    {if(yyyYok){
yyyRSU(28,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+297,yyyRCIL+309);}}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 353 "oxout.y"
    {if(yyyYok){
yyyRSU(29,2,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+309,yyyRCIL+321);}}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 358 "oxout.y"
    {if(yyyYok){
yyyRSU(30,2,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+321,yyyRCIL+333);}}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 363 "oxout.y"
    {if(yyyYok){
yyyRSU(31,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+333,yyyRCIL+345);}}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 368 "oxout.y"
    {if(yyyYok){
yyyRSU(32,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+345,yyyRCIL+357);}}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 373 "oxout.y"
    {if(yyyYok){
yyyRSU(33,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+357,yyyRCIL+369);}}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 378 "oxout.y"
    {if(yyyYok){
yyyRSU(34,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+369,yyyRCIL+390);}}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 383 "oxout.y"
    {if(yyyYok){
yyyRSU(35,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+390,yyyRCIL+411);}}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 390 "oxout.y"
    {if(yyyYok){
yyyRSU(36,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+411,yyyRCIL+432);}}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 395 "oxout.y"
    {if(yyyYok){
yyyRSU(37,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+432,yyyRCIL+453);}}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 402 "oxout.y"
    {if(yyyYok){
yyyRSU(38,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+453,yyyRCIL+474);}}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 407 "oxout.y"
    {if(yyyYok){
yyyRSU(39,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+474,yyyRCIL+495);}}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 414 "oxout.y"
    {if(yyyYok){
yyyRSU(40,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+495,yyyRCIL+516);}}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 419 "oxout.y"
    {if(yyyYok){
yyyRSU(41,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+516,yyyRCIL+537);}}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 426 "oxout.y"
    {if(yyyYok){
yyyRSU(42,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+537,yyyRCIL+549);}}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 431 "oxout.y"
    {if(yyyYok){
yyyRSU(43,1,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = new_number_leaf((((yyyP10)(((char *)((yyySTN->cL)[0]))+yyyGNSz))->val));
	yyyAdjustINRC(yyyRCIL+549,yyyRCIL+552);/*yyyPrune(43);*/}}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 437 "oxout.y"
    {if(yyyYok){
yyyRSU(44,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+552,yyyRCIL+564);}}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 442 "oxout.y"
    {if(yyyYok){
yyyRSU(45,1,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+564,yyyRCIL+567);}}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 447 "oxout.y"
    {if(yyyYok){
yyyRSU(46,3,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = new_leaf(OP_NOP); yyyAdjustINRC(yyyRCIL+567,yyyRCIL+570);/*yyyPrune(46);*/}}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 452 "oxout.y"
    {if(yyyYok){
yyyRSU(47,4,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = new_leaf(OP_NOP); yyyAdjustINRC(yyyRCIL+570,yyyRCIL+582);}}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 457 "oxout.y"
    {if(yyyYok){
yyyRSU(48,5,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = new_leaf(OP_NOP); yyyAdjustINRC(yyyRCIL+582,yyyRCIL+594);}}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 464 "oxout.y"
    {if(yyyYok){
yyyRSU(49,1,4,2);
yyyGenIntNode();
 (((yyyP2)yyySTsn)->node) = NULL; yyyAdjustINRC(yyyRCIL+594,yyyRCIL+606);}}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 469 "oxout.y"
    {if(yyyYok){
yyyRSU(50,3,4,2);
yyyGenIntNode();
yyyAdjustINRC(yyyRCIL+606,yyyRCIL+627);}}
    break;



/* Line 1806 of yacc.c  */
#line 2140 "oxout.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 476 "oxout.y"


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
yyyR,0,0, yyyR,1,0, yyyR,0,2, yyyR,1,1, yyyR,0,0, yyyR,1,0, 
yyyR,0,2, yyyR,1,1, 0,0,1, 0,1,1, 0,2,1, 1,0,1, 
1,1,1, 1,2,1, yyyR,1,0, yyyR,4,0, yyyR,5,0, yyyR,1,1, 
yyyR,4,2, yyyR,5,0, 0,0,1, 0,2,1, 0,3,1, 3,0,1, 
3,1,1, 3,2,1, yyyR,3,0, yyyR,3,2, 0,0,1, 0,1,1, 
0,2,1, 1,0,1, 1,1,1, 1,2,1, 3,0,1, 3,1,1, 
3,2,1, yyyR,3,1, 1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 
1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 1,0,1, 1,2,1, 
1,3,1, 3,0,2, 3,1,1, 3,2,1, yyyR,3,1, 1,0,1, 
1,1,1, 1,2,1, 5,0,2, 5,1,1, 5,2,1, yyyR,3,2, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
yyyR,3,0, 0,0,1, 0,1,1, 0,2,1, yyyR,3,1, yyyR,3,2, 
0,0,1, 0,1,1, 0,2,1, yyyR,3,1, 0,0,1, 0,1,1, 
0,2,1, yyyR,3,1, 1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 
1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 0,0,1, 0,1,1, 
0,2,1, yyyR,3,1, 1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 
1,0,1, 1,1,1, 1,2,1, yyyR,3,1, 0,0,1, 0,1,1, 
0,2,1, yyyR,3,1, 0,0,1, 0,1,1, 0,2,1, yyyR,3,1, 
0,0,1, 0,1,1, 0,2,1, yyyR,3,2, 0,0,1, 0,1,1, 
0,2,1, 2,0,1, 2,1,1, 2,2,1, yyyR,3,2, 0,0,1, 
0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, yyyR,3,2, 
0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
yyyR,3,2, 0,0,1, 0,1,1, 0,2,1, 2,0,1, 2,1,1, 
2,2,1, yyyR,3,2, 0,0,1, 0,1,1, 0,2,1, 2,0,1, 
2,1,1, 2,2,1, yyyR,3,2, 0,0,1, 0,1,1, 0,2,1, 
2,0,1, 2,1,1, 2,2,1, yyyR,3,2, 0,0,1, 0,1,1, 
0,2,1, 2,0,1, 2,1,1, 2,2,1, yyyR,3,2, 0,0,1, 
0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, yyyR,3,1, 
1,0,1, 1,1,1, 1,2,1, yyyR,3,0, yyyR,3,2, 0,0,1, 
0,1,1, 0,2,1, yyyR,3,1, yyyR,3,0, yyyR,3,0, 2,0,1, 
2,1,1, 2,2,1, yyyR,3,0, 2,0,1, 2,1,1, 2,2,1, 
yyyR,3,0, 0,0,1, 0,1,1, 0,2,1, yyyR,3,2, 0,0,1, 
0,1,1, 0,2,1, 2,0,1, 2,1,1, 2,2,1, 
};

short yyyIIIEL[] = {0,
0,2,3,7,11,19,25,26,29,30,
33,34,38,39,45,46,53,56,60,66,
74,78,80,82,86,88,91,94,96,99,
102,104,106,108,112,116,120,124,128,132,
136,140,144,146,150,152,156,161,167,169,

};

long yyyIIEL[] = {
0,0,2,4,6,8,10,10,12,14,15,15,
16,16,17,17,19,19,22,22,24,24,25,25,
27,27,29,31,33,34,36,38,40,41,44,47,
50,54,54,60,66,72,73,73,77,77,81,85,
89,93,93,96,96,96,100,100,104,108,108,112,
112,116,116,122,122,125,125,129,129,133,133,134,
134,137,137,141,145,145,149,153,157,161,162,166,
170,170,171,175,179,183,183,187,191,191,195,199,
203,207,207,211,215,215,219,223,227,231,235,239,
243,247,251,251,255,259,263,263,267,271,275,275,
279,283,287,287,291,295,299,299,303,307,311,311,
315,319,323,323,327,331,335,335,339,343,343,347,
347,351,352,356,360,360,361,365,366,370,371,371,
371,375,376,376,380,380,384,385,385,389,389,389,
393,397,401,405,405,
};

long yyyIEL[] = {
0,2,2,2,2,2,4,6,
6,8,10,10,14,16,16,16,
18,18,20,20,20,20,20,20,
20,22,24,24,24,24,24,26,
28,30,32,32,32,32,34,36,
38,40,40,40,40,44,48,52,
52,52,52,52,52,52,52,52,
52,52,52,52,52,56,56,60,
64,64,64,64,66,66,66,68,
68,70,70,70,70,72,72,72,
72,72,78,84,90,90,90,90,
90,92,92,92,92,94,94,94,
94,96,98,100,100,100,100,100,
102,104,106,108,108,108,108,108,
110,114,118,122,122,122,124,124,
124,126,126,126,126,126,130,136,
140,140,140,140,140,142,144,144,
144,144,148,152,156,156,156,156,
156,158,158,158,158,160,162,164,
166,166,166,166,166,166,168,168,
168,168,170,172,176,178,178,178,
178,178,180,182,184,186,188,188,
188,188,188,190,192,194,196,196,
196,196,196,198,200,202,204,204,
204,204,204,206,208,210,212,212,
212,212,212,214,216,218,220,220,
220,220,220,222,224,226,228,228,
228,228,228,230,232,234,236,236,
236,236,236,238,240,242,244,244,
244,244,244,246,248,250,252,252,
252,252,252,254,258,262,266,266,
266,266,266,268,268,268,268,270,
274,278,282,282,282,282,282,284,
284,284,284,286,290,294,298,298,
298,298,298,300,300,300,300,302,
306,310,314,314,314,314,314,316,
316,316,316,318,322,326,330,330,
330,330,330,332,332,332,332,334,
338,342,346,346,346,346,346,348,
348,348,348,350,354,358,362,362,
362,362,362,364,364,364,364,366,
370,374,378,378,378,378,378,380,
380,380,380,382,384,386,388,388,
388,388,388,390,390,390,390,390,
392,394,398,400,400,400,400,400,
402,404,406,406,406,406,408,408,
408,408,408,408,410,412,414,414,
414,414,414,414,414,416,418,420,
420,420,420,420,420,420,422,424,
426,426,426,426,426,426,430,434,
438,438,438,438,438,440,440,440,
440,442,
};

yyyFT yyyEntL[] = {
1,1,1,1,0,0,0,0,0,0,2,0,1,1,0,0,
6,1,6,0,0,1,0,0,0,0,0,0,0,1,0,0,
0,0,0,0,0,1,0,0,2,0,1,0,2,1,1,1,
2,2,1,2,4,0,1,0,4,1,1,2,4,2,1,3,
0,1,0,4,0,1,0,4,4,0,2,0,1,0,4,1,
2,1,1,1,4,2,2,2,1,2,0,3,0,3,2,0,
2,1,2,2,0,3,2,0,2,1,2,2,0,3,2,0,
4,0,4,1,2,2,4,2,2,3,4,0,0,3,2,0,
6,0,6,1,2,1,6,0,6,2,2,2,0,3,6,0,
3,0,1,0,3,1,1,1,3,2,1,2,0,3,0,3,
1,0,1,1,1,2,0,3,0,3,1,0,0,3,1,1,
1,2,0,3,0,3,1,0,1,1,1,2,0,3,2,0,
2,1,2,2,0,3,2,0,2,1,2,2,0,3,1,0,
1,1,1,2,0,3,2,0,2,1,2,2,0,3,2,0,
2,1,2,2,0,3,1,0,1,1,1,2,0,3,1,0,
1,1,1,2,0,3,1,0,1,1,1,2,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,3,0,
1,0,3,1,1,1,3,2,1,2,0,3,0,3,2,0,
2,1,2,2,0,3,0,3,1,0,0,3,1,1,1,2,
0,3,0,3,0,3,0,3,3,0,3,1,3,2,3,0,
3,1,3,2,1,0,1,1,1,2,3,0,1,0,3,1,
1,1,3,2,1,2,0,3,0,3,
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
int yyyNdSz[11];

int yyyNdPrSz[11];

typedef int yyyCopyType;

int yyyNdCopySz[11];
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
   yyyNdSz[9] = sizeof(struct yyyT9);
   yyyNdSz[10] = sizeof(struct yyyT10);
   for (i=0;i<11;i++) 
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
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP6)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen);

    	    break;
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
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->struct_gen) = add_struct((((yyyP6)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen), (((yyyP4)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), (((yyyP4)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->felder));
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 1:
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP6)(((char *)yyyRefN)+yyyGNSz))->structs);

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
 (((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->struct_gen) = (((yyyP6)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->struct_gen);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 1:
(((yyyP6)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP6)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP5)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP6)(((char *)yyyRefN)+yyyGNSz))->structs);
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
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP7)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->syms_gen);
		    break;
    case 1:
(((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP5)(((char *)yyyRefN)+yyyGNSz))->structs);
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
 (((yyyP4)(((char *)yyyRSTopN)+yyyGNSz))->felder) = (((yyyP8)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->syms_gen);
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
 (((yyyP7)(((char *)yyyRSTopN)+yyyGNSz))->syms_gen) = add_param((((yyyP7)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->syms_gen), (((yyyP9)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), (((yyyP7)(((char *)yyyRefN)+yyyGNSz))->index));
		    break;
    case 1:
 (((yyyP7)(((char *)yyyRSTopN)+yyyGNSz))->index) = (((yyyP7)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->index) + 1;

		    yyySignalEnts(yyyRefN,yyyEntL+24,yyyEntL+26);
    break;
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
 (((yyyP8)(((char *)yyyRSTopN)+yyyGNSz))->syms_gen) = add_field((((yyyP8)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->syms_gen), (((yyyP9)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), (((yyyP8)(((char *)yyyRefN)+yyyGNSz))->offset));
		    break;
    case 1:
 (((yyyP8)(((char *)yyyRSTopN)+yyyGNSz))->offset) = (((yyyP8)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->offset) + 1;
	    yyySignalEnts(yyyRefN,yyyEntL+32,yyyEntL+34);
    break;
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP1)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
 (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->vars) = add_var((((yyyP3)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->vars), (((yyyP9)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->name), (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->reg));
		    break;
    case 4:
 (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_Assign, (((yyyP2)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->node), (((yyyP3)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node)); (((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->node)->reg = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->reg);

		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 2:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 3:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP3)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_cond_node((((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), get_if_id());
		    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
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
case 17:  /***yacc rule 17***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_Return, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode*) NULL);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 18:  /***yacc rule 18***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node);     break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 19:  /***yacc rule 19***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 2:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 3:
(((yyyP3)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 4:  /**/
    switch (yyywa) {
    case 0:
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = table_merge((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP3)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->vars));
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
case 20:  /***yacc rule 20***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_With, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode*) NULL); 
		    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
 (((yyyP1)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = load_struct((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs), (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyRefN->cL)[3]))+yyyGNSz))->name));
	
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
case 21:  /***yacc rule 21***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_LEXPR, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 23:  /***yacc rule 23***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_id_leaf((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->name));
	    break;
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
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_field_leaf(OP_Field, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), get_field_offset((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs), (((yyyP9)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->name)));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 26:  /***yacc rule 26***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_NEG, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode *) NULL);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 27:  /***yacc rule 27***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_NOT, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode *) NULL);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 28:  /***yacc rule 28***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 29:  /***yacc rule 29***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_NEG, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode *) NULL);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 30:  /***yacc rule 30***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_NOT, (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node), (treenode *) NULL);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 31:  /***yacc rule 31***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 32:  /***yacc rule 32***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 33:  /***yacc rule 33***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 34:  /***yacc rule 34***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_GREATER, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 35:  /***yacc rule 35***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_NEQ, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 36:  /***yacc rule 36***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_ADD, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 37:  /***yacc rule 37***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_ADD, (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node),(((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 38:  /***yacc rule 38***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_MUL, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 39:  /***yacc rule 39***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_MUL, (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 40:  /***yacc rule 40***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_OR, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 41:  /***yacc rule 41***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_OR, (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 42:  /***yacc rule 42***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = (((yyyP2)(((char *)((yyyRefN->cL)[1]))+yyyGNSz))->node);
	    break;
    }
  break;
  case 2:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_field_leaf((((yyyP9)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->name), (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), get_field_offset((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs), (((yyyP9)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->name)));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_id_leaf((((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->name));
	    break;
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  }
break;
case 50:  /***yacc rule 50***/
  switch (yyyws) {
  case 0:  /**/
    switch (yyywa) {
    case 3:
 (((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->node) = new_node(OP_Args, (((yyyP2)(((char *)((yyyRefN->cL)[0]))+yyyGNSz))->node), (((yyyP2)(((char *)((yyyRefN->cL)[2]))+yyyGNSz))->node));
	    break;
    }
  break;
  case 1:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
    break;
    }
  break;
  case 3:  /**/
    switch (yyywa) {
    case 0:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->symbols) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->symbols);
    break;
    case 1:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->structs);
    break;
    case 2:
(((yyyP2)(((char *)yyyRSTopN)+yyyGNSz))->visible_structs) = (((yyyP2)(((char *)yyyRefN)+yyyGNSz))->visible_structs);
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


for (yyyi=0; yyyi<2; yyyi++) {
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
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { printf("\t.text\n");
    }
				break;
					}
		break;
			}

break;
case 2:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 3:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_unused_fieldnames((((yyyP6)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->struct_gen), (((yyyP4)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->felder));
	}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 4:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 5:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { function_header((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->name), (((yyyP7)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->syms_gen));
	}
				break;
					}
		break;
			}

break;
case 6:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 7:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 8:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { setRegister((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->name), getParamRegister((((yyyP7)(((char *)yyyTSTn)+yyyGNSz))->index)));
	}
				break;
					}
		break;
			}

break;
case 9:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 10:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 11:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 12:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { debug_tree((((yyyP2)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->node));

		 }
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

if (! ((((yyyP2)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->node)->op == OP_Return)) yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { }
if (yyyCond(1) != yyyPass) { /* printf("%d\n", get_id());*/ burm_label((((yyyP2)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->node)); burm_reduce((((yyyP2)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->node), 1);
	}
				break;
					}
		break;
			}

break;
case 13:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 14:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { setRegister((((yyyP9)(((char *)((yyyTSTn->cL)[1]))+yyyGNSz))->name), (((yyyP3)(((char *)yyyTSTn)+yyyGNSz))->reg));
	}
				break;
					}
		break;
			}

break;
case 15:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

if (! (1)) yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { }
if (yyyCond(1) != yyyPass) { print_cond_label((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->node)->value);
	}
				break;
					}
		break;
			}

break;
case 16:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

if (! (1)) yyySetCond(1)

				case 1:

if (yyyCond(0) != yyyPass) { }
if (yyyCond(1) != yyyPass) { print_cond_label((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->node)->value);
	}
				break;
					}
		break;
			}

break;
case 17:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 18:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 19:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 20:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_struct_exists((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP9)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->name));

		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;yyySetCond(0)

				case 1:

if (yyyCond(0) != yyyPass) { setfieldreg((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP1)(((char *)((yyyTSTn->cL)[5]))+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyTSTn->cL)[3]))+yyyGNSz))->name), (((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->node)->reg);
	}
				break;
					}
		break;
			}

break;
case 21:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 22:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 23:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name));
		
		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 24:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists_feldkontext((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->name));
		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 25:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 26:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 27:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 28:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 29:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 30:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 31:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 32:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 33:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 34:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 35:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 36:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 37:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 38:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 39:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 40:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 41:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 42:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 43:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 44:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists_feldkontext((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->structs), (((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyTSTn->cL)[2]))+yyyGNSz))->name)); 
		
		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 45:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

if (yyyCond(0) != yyyPass) { assert_exists((((yyyP2)(((char *)yyyTSTn)+yyyGNSz))->symbols), (((yyyP9)(((char *)((yyyTSTn->cL)[0]))+yyyGNSz))->name));

		}
				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 46:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 47:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 48:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 49:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
			}

break;
case 50:
	switch(yyyi)	{ 
		case 0:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
		break;
		case 1:
			switch(yyyPass)	{
				case 0:
yyyRL = 0;
				case 1:

				break;
					}
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


#define yyyNsorts 10


int yyyProdsInd[] = {
   0,
   0,   2,   3,   7,  11,  19,  25,  26,  29,  30,
  33,  34,  38,  39,  45,  46,  53,  56,  60,  66,
  74,  78,  80,  82,  86,  88,  91,  94,  96,  99,
 102, 104, 106, 108, 112, 116, 120, 124, 128, 132,
 136, 140, 144, 146, 150, 152, 156, 161, 167, 169,
 173,
};


int yyyProds[][2] = {
{ 581,   0},{1013,   6},{1013,   6},{1013,   6},{1013,   6},
{ 172,   4},{ 748,   0},{1013,   6},{1013,   6},{ 165,   5},
{ 748,   0},{ 165,   5},{ 758,   0},{ 722,   9},{ 220,   0},
{  18,   7},{  14,   0},{  63,   1},{ 821,   0},{ 172,   4},
{1140,   0},{ 722,   9},{ 623,   0},{ 804,   8},{ 821,   0},
{  18,   7},{  18,   7},{  18,   7},{ 722,   9},{ 804,   8},
{ 804,   8},{ 804,   8},{ 722,   9},{  63,   1},{  63,   1},
{  63,   1},{ 246,   2},{ 748,   0},{1081,   3},{1081,   3},
{1081,   3},{ 722,   9},{ 834,   0},{ 430,   2},{ 748,   0},
{1153,   2},{1153,   2},{1153,   2},{ 430,   2},{ 547,   0},
{  63,   1},{ 821,   0},{ 748,   0},{ 246,   2},{1050,   0},
{ 430,   2},{ 246,   2},{ 822,   0},{1153,   2},{ 821,   0},
{ 246,   2},{ 930,   0},{1081,   3},{ 132,   0},{  63,   1},
{ 821,   0},{ 246,   2},{ 457,   0},{ 430,   2},{ 623,   0},
{ 722,   9},{  98,   0},{  63,   1},{ 821,   0},{ 246,   2},
{ 286,   2},{ 834,   0},{ 430,   2},{ 246,   2},{ 997,   2},
{ 286,   2},{ 722,   9},{ 286,   2},{ 997,   2},{ 616,   0},
{ 722,   9},{ 328,   2},{ 997,   2},{ 328,   2},{ 443,   0},
{ 328,   2},{ 328,   2},{1126,   0},{ 328,   2},{ 430,   2},
{ 997,   2},{ 430,   2},{ 443,   0},{ 328,   2},{ 430,   2},
{1126,   0},{ 328,   2},{ 430,   2},{ 349,   2},{ 430,   2},
{ 418,   2},{ 430,   2},{ 394,   2},{ 430,   2},{ 997,   2},
{ 806,   0},{ 997,   2},{ 430,   2},{ 997,   2},{ 838,   0},
{ 997,   2},{ 349,   2},{ 997,   2},{ 442,   0},{ 997,   2},
{ 349,   2},{ 349,   2},{ 442,   0},{ 997,   2},{ 418,   2},
{ 997,   2},{1224,   0},{ 997,   2},{ 418,   2},{ 418,   2},
{1224,   0},{ 997,   2},{ 394,   2},{ 997,   2},{ 998,   0},
{ 997,   2},{ 394,   2},{ 394,   2},{ 998,   0},{ 997,   2},
{ 997,   2},{ 220,   0},{ 430,   2},{  14,   0},{ 997,   2},
{  57,  10},{ 997,   2},{ 997,   2},{ 616,   0},{ 722,   9},
{ 997,   2},{ 722,   9},{ 997,   2},{ 722,   9},{ 220,   0},
{  14,   0},{ 997,   2},{ 722,   9},{ 220,   0},{ 867,   2},
{  14,   0},{ 997,   2},{ 722,   9},{ 220,   0},{ 867,   2},
{ 744,   0},{  14,   0},{ 867,   2},{ 430,   2},{ 867,   2},
{ 867,   2},{ 744,   0},{ 430,   2},
};


int yyySortsInd[] = {
  0,
  0,  3,  7, 13, 15, 16, 18, 20, 22, 23,
 24,
};


int yyySorts[] = {
  965,   97,   20,  965,   97,   20,  809,  965,  152,   97,
   20,  809,  131,  836,  381,   97,  717,   97,  755,   64,
  755,  981,  381,  423,
};



char *yyyStringTab[] = {
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,"T_BRACKET_RIGHT",
0,0,0,"Params",0,
"visible_structs",0,0,0,0,
0,0,"unused",0,"unsigned",
0,0,0,0,"struct_table",
0,0,0,0,0,
"ADD",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"T_NUM",0,0,
0,0,0,"Stats","index",
"LEXPR",0,0,0,0,
0,0,0,"struct",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"structs","T_DO",0,
0,0,0,0,0,
0,0,0,0,0,
0,"n",0,0,"exists",
0,0,"t",0,0,
"tree",0,"y",0,0,
0,0,0,0,0,
0,"reg","T_IN",0,0,
0,0,0,0,0,
"newreg",0,0,0,0,
0,0,0,0,0,
"setfieldreg",0,"vars",0,"EMPTY",
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
"T_BRACKET_LEFT",0,"NULL","reduce",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"Stat",0,0,0,
0,0,0,"NEG",0,
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
0,0,0,"SignExpr",0,
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
0,"name",0,0,0,
0,0,0,0,0,
0,0,0,0,"OrExpr",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"strdup",0,"MultExpr",0,
0,0,0,"val",0,
"label",0,0,0,0,
"Expr",0,0,0,0,
0,0,0,"load",0,
0,0,"T_PLUS","T_MINUS",0,
0,0,0,"Assign",0,
0,0,0,0,0,
0,0,"T_WITH",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"printf",0,0,0,
0,0,0,0,0,
0,"leaf",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"With",0,0,0,0,
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
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"Input",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"T_POINT",0,0,0,
0,0,0,"T_DOUBLE_POINT",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"codegen",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"GREATER",0,0,
0,0,0,0,0,
0,0,0,0,0,
"MUL",0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"struct_gen",0,0,
0,"OP","T_ID",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"OR",0,0,
0,0,0,0,"T_COLON",
0,0,0,"T_SEMICOLON",0,
0,0,0,0,0,
"syms_gen",0,0,"T_FUNC","Args",
0,"print",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"value",0,
0,0,0,0,0,
0,0,0,0,"Felder",
0,"T_GREATER","var",0,"node",
0,0,0,0,0,
0,0,0,0,0,
0,"T_END","T_COND",0,0,
0,0,0,0,0,
0,0,0,0,"T_EQUAL",
0,"felder",0,"T_NOT_EQUAL","header",
0,0,0,"treenode",0,
0,0,"getParamRegister",0,"feldkontext",
0,0,"TABLE",0,"setRegister",
0,"text",0,0,0,
0,0,0,0,0,
0,0,"ExprList",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"NEQ",0,
0,0,0,0,0,
0,0,0,0,0,
0,"function","param","id","NOP",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,"if",0,
0,0,0,0,0,
"T_LET","cond",0,0,0,
"debug","fieldnames",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"get",0,0,
0,0,0,0,0,
0,0,0,0,0,
"symbols",0,0,0,0,
0,0,"number",0,0,
0,0,0,0,0,
0,"offset",0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"Term","T_OR",0,
0,0,0,0,0,
0,0,0,0,"op",
0,0,0,"Program",0,
0,0,0,0,0,
0,0,0,"yytext",0,
0,0,0,0,0,
0,0,0,0,"merge",
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
"T_RETURN",0,0,0,0,
0,0,0,0,0,
0,"Return","Field",0,0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"LetRec",0,0,0,
0,0,0,0,0,
0,0,"dec","field",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,"table","sscanf",0,
0,0,0,0,0,
0,0,0,0,0,
0,0,0,0,0,
0,"T_NOT",0,0,0,
0,"long",0,0,0,
0,0,0,0,"burm",
"T_STRUCT",0,0,0,0,
"add",0,0,0,0,
0,"new",0,"CondRec",0,
0,0,0,0,0,
0,0,0,0,0,
"NOT",0,0,0,0,
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




