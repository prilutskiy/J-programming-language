/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "jlang.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define YYDEBUG 1	
extern int lineNumber;

// Óçåë äåðåâà	
struct treeNode
{
	int nodeType;          // Òèï óçëà äåðåâà / ñåìàíòè÷åñêîãî çíà÷åíèÿ
	union
	{
		struct treeNode *node;
		struct variableInfo* var;
		struct constantInfo *constant;
		struct procedureInfo* func;    			
		struct paramsListNode* params;
	} value;
	struct treeNode *left;
	struct treeNode *right;
};


//--------------------------------------------------
struct procedureInfo
{
    char *name;
    char type;
    struct paramsListNode *params;
    struct treeNode *operations;
	struct variableListNode* varDeclaratons;
};

struct funcTableNode
{
    struct procedureInfo *func;
    struct funcTableNode *next;
};
//----------------------------------------------------

struct parameterInfo
{
    char* name;
    char type;
    struct variableInfo* var;
	struct treeNode* node;
};

struct paramsListNode
{
    struct parameterInfo* param;
    struct paramsListNode* next;
};
//---------------------------------------------------

struct arrayInfo
{
    int sizeOfElement;
    int length;
    void *ptr;
};

struct constantInfo
{
    char type;
    union
    {
        int intValue;
        char charValue;
        struct arrayInfo* arrValue;
    } value;
};

//-------------------------------------------------
struct variableInfo
{
    int isParam;
    char* name;
    char type;
    union
    {
        int intValue;
        char charValue;
        struct arrayInfo* arrayValue;
    } value;
};

struct variableListNode
{
    struct variableInfo *var;
    struct variableListNode *next;
};
//--------------------------------------------------


//struct treeNode* treeRoot = NULL;       // Êîðåíü äåðåâà
struct funcTableNode* FuncTable = NULL; // Ñïèñîê ôóíêöèé
struct variableListNode* curVarList = NULL; // Ñïèñîê îáúÿâëåííûõ ïåðåìåííûõ òåêóùåé ôóíêöèè
struct paramsListNode* curParamList = NULL;

int errors = 0;

// Äîáàâëåíèå óçëà â äåðåâî
struct treeNode* GetTreeNode(char nType, struct treeNode* Left, struct treeNode* Right);

// Äîáàâèòü ôóíêöèþ â ñïèñîê
struct procedureInfo* Addprocedure(char fType, char *fName, struct paramsListNode* Params);

// Ïðîâåðèòü íàëè÷èå ôóíêöèè â ñïèñêå
struct procedureInfo* Checkprocedure(char *fName);

// Äîáàâèòü ïàðàìåòð â ñïèñîê
struct paramsListNode* AddToParamsList(struct treeNode* node, struct variableInfo *pVar);

// Âåðíóòü ñòðóêòóðó ïåðåìåííîé
struct variableInfo* GetVar(char vType, char *vName, int isParam);

// Äîáàâèòü ïåðåìåííóþ â òåêóùèé ñïèñîê
struct variableListNode* AddToVariableList(struct variableInfo *Var);

// Ïðîâåðèòü, îáúÿâëåíà ëè ïåðåìåííàÿ
struct variableInfo* CheckVariable(char *vName);

struct paramsListNode* AddToArgsList(struct treeNode* node, struct paramsListNode *Next);

void ShowproceduresSemantic();

void ShowMainSemantic();


void printParameters(struct paramsListNode *params);
void printVariableDeclarations(struct variableListNode* varDeclaratons);
void printOperators(struct treeNode *operations, int depth);
void printType(int type);


#line 205 "jlang.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "jlang.tab.h".  */
#ifndef YY_YY_JLANG_TAB_H_INCLUDED
# define YY_YY_JLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    CHAR = 260,
    POINTER = 261,
    LINK = 262,
    PROCEDURE = 263,
    OUTP = 264,
    INP = 265,
    MAIN = 266,
    WHILE = 267,
    IDENT = 268,
    COMMA = 269,
    SEMICOLON = 270,
    STRING = 271,
    ASSIGNMENT = 272,
    NUMBER = 273,
    left_sqBracket = 274,
    right_sqBracket = 275,
    LEFT_BRACKET = 276,
    RIGHT_BRACKET = 277,
    RIGHT_FIGURE = 278,
    LEFT_FIGURE = 279,
    comment = 280,
    mono_comment = 281,
    not = 282,
    division = 283,
    minus = 284,
    plus = 285,
    compare = 286,
    not_equal = 287,
    mul_equal = 288,
    div_equal = 289,
    minus_equal = 290,
    plus_equal = 291,
    inc = 292,
    dec = 293,
    more_equal = 294,
    less_equal = 295,
    more = 296,
    less = 297,
    and = 298,
    or = 299,
    quest = 300,
    uminus = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 141 "jlang.y" /* yacc.c:355  */

    struct treeNode* node;
	struct 
	{
		char* ptr;
		int lineNumber;
	} str;
	
	long num;

#line 303 "jlang.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_JLANG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 318 "jlang.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   171,   175,   199,   200,   207,   224,   239,
     252,   271,   273,   274,   278,   288,   309,   330,   332,   333,
     344,   348,   353,   361,   377,   386,   404,   408,   412,   418,
     422,   430,   438,   446,   464,   469,   473,   477,   484,   502,
     506,   521,   533,   537,   541,   545,   549,   553,   557,   564,
     568,   575,   579,   587,   591,   595,   599,   603,   611,   615,
     619,   628,   632,   636,   640,   644,   659,   668,   683,   687,
     701,   709,   710,   711,   712,   713,   714,   715,   716,   717
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "CHAR", "POINTER", "LINK",
  "PROCEDURE", "OUTP", "INP", "MAIN", "WHILE", "IDENT", "COMMA",
  "SEMICOLON", "STRING", "ASSIGNMENT", "NUMBER", "left_sqBracket",
  "right_sqBracket", "LEFT_BRACKET", "RIGHT_BRACKET", "RIGHT_FIGURE",
  "LEFT_FIGURE", "comment", "mono_comment", "not", "division", "minus",
  "plus", "compare", "not_equal", "mul_equal", "div_equal", "minus_equal",
  "plus_equal", "inc", "dec", "more_equal", "less_equal", "more", "less",
  "and", "or", "quest", "uminus", "$accept", "axiom", "main_func",
  "procedures", "procedureDeclaration", "procedure", "declaration_arg",
  "declaration_args", "declaration", "declarations", "args", "arg",
  "operators", "Code_block", "WHILE_cycle", "OUTP_func", "INP_func",
  "operator", "array_access", "statement", "logical_expr",
  "logical_or_expr", "logical_and_expr", "plus_expr", "mul_expr",
  "unary_expr", "primary", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -27

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,    42,    70,    78,    32,   -62,    76,    28,   -62,     7,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,    12,
      36,    47,    12,    12,    33,    75,    76,    76,   -62,   -62,
      33,    74,    90,    94,    44,   -62,   112,   124,   124,    80,
     -62,   107,   113,    33,   109,   116,   115,    83,    91,    72,
     108,    62,   -62,    25,   129,   122,   135,   127,   -62,    37,
     137,   112,   124,   124,    37,   130,    53,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   124,   -62,   124,   124,   124,   124,
     124,   124,   124,   124,    46,    65,    69,   -62,   -62,   -62,
      71,    76,   140,   146,   -62,   -62,   -62,   -62,   144,   145,
     147,   115,    77,     9,   -62,   -62,   115,    83,    83,    83,
      83,    83,    83,    91,    72,   -62,   108,   -62,   108,   -62,
      62,   148,   153,   -62,    12,   151,   -62,   -62,   111,   -62,
      37,   -62,   157,   158,    33,   -62,    33,   -62,   -62,   -62,
     -62,   160,   150,   154,   -62,   -62,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    73,    71,    72,     0,     3,     0,     0,     5,     0,
      76,    79,    74,    77,    75,    78,     1,     2,     6,     0,
       0,     0,     0,     0,     0,     0,    11,    11,    19,    18,
       0,     0,     0,     0,    67,    66,     0,     0,     0,     0,
      35,     0,     0,     0,    70,     0,    39,    42,    49,    51,
      53,    58,    61,     0,    12,     0,     0,     0,    28,     0,
       0,     0,     0,     0,    20,     0,    67,    70,    65,    62,
       8,    36,    37,    27,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    63,    64,    14,
       0,    11,     0,     9,     7,    23,    25,    24,     0,     0,
       0,    40,     0,     0,    21,    68,    41,    46,    43,    48,
      47,    45,    44,    50,    52,    57,    55,    56,    54,    60,
      59,     0,     0,    13,     0,     0,    32,    33,     0,    38,
       0,    69,     0,     0,     0,    10,     0,    31,    30,    22,
      15,     0,     0,     0,    16,     4,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   170,   -62,   -62,   172,   -62,   -20,   -62,   -18,
     -62,   -61,   -29,   -62,   -62,   -62,   -62,    51,   -24,   -25,
     -36,    82,    98,    99,    29,   -28,   -62,     2
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    54,    55,    23,    24,
     103,    98,    39,   137,    40,    41,    42,    43,    67,    45,
      46,    47,    48,    49,    50,    51,    52,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    58,     9,   104,    28,    29,    44,    57,     9,    68,
      69,    65,    44,    22,    73,     1,     2,     3,    20,    44,
      21,   -17,   -17,   130,   -17,   -17,   101,   102,    56,    56,
     -17,   131,    16,   -17,    30,   -17,   100,    44,   106,   -17,
      89,   -17,    31,    32,    90,    33,    34,   115,    10,    11,
      95,    35,    19,    96,    36,    97,   -26,    26,   120,    66,
      37,    62,    38,    63,    35,    64,   117,    36,    27,   139,
     119,   123,    63,    37,    64,    38,    12,    13,    66,     1,
       2,     3,    66,    35,    14,    15,    36,    35,    53,   121,
      36,   122,    37,    56,    38,    59,    37,   129,    38,    87,
      88,    84,    85,    70,    44,   142,   134,   143,    76,    77,
      44,    60,    44,   116,   118,    61,    78,    79,    80,    81,
      31,    32,    71,    33,    34,    34,    74,    82,    72,    35,
      35,    75,    36,    36,    83,   136,    86,    66,    37,    37,
      38,    38,    35,    91,    92,    36,    76,    77,    93,    94,
      99,    37,   105,    38,    78,    79,    80,    81,   107,   108,
     109,   110,   111,   112,   124,   125,   126,   127,   132,   128,
     133,   135,   140,   145,   141,   144,    17,   146,    18,   138,
     113,     0,   114
};

static const yytype_int16 yycheck[] =
{
      24,    30,     0,    64,    22,    23,    30,    27,     6,    37,
      38,    36,    36,     1,    43,     3,     4,     5,    11,    43,
      13,     9,    10,    14,    12,    13,    62,    63,    26,    27,
      18,    22,     0,    21,     1,    23,    61,    61,    74,    27,
      15,    29,     9,    10,    19,    12,    13,     1,     6,     7,
      13,    18,    24,    16,    21,    18,    23,    21,    86,    13,
      27,    17,    29,    19,    18,    21,     1,    21,    21,   130,
       1,    91,    19,    27,    21,    29,     6,     7,    13,     3,
       4,     5,    13,    18,     6,     7,    21,    18,    13,    18,
      21,    20,    27,    91,    29,    21,    27,    20,    29,    37,
      38,    29,    30,    23,   128,   134,   124,   136,    31,    32,
     134,    21,   136,    84,    85,    21,    39,    40,    41,    42,
       9,    10,    15,    12,    13,    13,    17,    44,    15,    18,
      18,    15,    21,    21,    43,    24,    28,    13,    27,    27,
      29,    29,    18,    14,    22,    21,    31,    32,    13,    22,
      13,    27,    22,    29,    39,    40,    41,    42,    76,    77,
      78,    79,    80,    81,    24,    19,    22,    22,    20,    22,
      17,    20,    15,    23,    16,    15,     6,    23,     6,   128,
      82,    -1,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    48,    49,    50,    51,    52,    74,
       6,     7,     6,     7,     6,     7,     0,    49,    52,    24,
      11,    13,     1,    55,    56,    74,    21,    21,    56,    56,
       1,     9,    10,    12,    13,    18,    21,    27,    29,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    13,    53,    54,    74,    54,    59,    21,
      21,    21,    17,    19,    21,    66,    13,    65,    72,    72,
      23,    15,    15,    59,    17,    15,    31,    32,    39,    40,
      41,    42,    44,    43,    29,    30,    28,    37,    38,    15,
      19,    14,    22,    13,    22,    13,    16,    18,    58,    13,
      66,    67,    67,    57,    58,    22,    67,    68,    68,    68,
      68,    68,    68,    69,    70,     1,    71,     1,    71,     1,
      72,    18,    20,    54,    24,    19,    22,    22,    22,    20,
      14,    22,    20,    17,    56,    20,    24,    60,    64,    58,
      15,    16,    59,    59,    15,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    51,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    59,    59,    59,    60,
      60,    61,    62,    63,    64,    64,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    72,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     9,     1,     2,     5,     5,     2,
       4,     0,     1,     3,     3,     6,     7,     0,     2,     2,
       0,     1,     3,     1,     1,     1,     0,     2,     2,     3,
       1,     5,     4,     4,     2,     1,     2,     2,     4,     1,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     2,     2,     2,     2,     1,     1,     3,     4,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 176 "jlang.y" /* yacc.c:1646  */
    {
			if(/*errors == 0*/  1)
			{
				// Ïå÷àòàåì èíôîðìàöèþ î ôóíêöèÿõ
				ShowproceduresSemantic();
				
				// Ïå÷àòàåì èíôîðìàöèþ î MAIN
				printf("\n\n/MAIN/: ");
				
				printf("\n/Parameters/: ");
				printParameters(curParamList);
				
				printf("\n/Variable declarations/: ");
				printVariableDeclarations(curVarList);
				
				printf("\n/Operators/: ");
				printOperators((yyvsp[-1].node), 0);
			}
			
		}
#line 1526 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 208 "jlang.y" /* yacc.c:1646  */
    {
				// Äîáàâëÿåì ôóíêöèþ â ñïèñîê è âîçâðàùàåì å¸ ñòðóêòóðó
				struct procedureInfo* func = Addprocedure((yyvsp[-4].num), (yyvsp[-3].str).ptr, curParamList);
				curParamList = NULL;
				if(func == NULL)
				{
					printf("\nline %d: procedure %s redeclared\n", (yyvsp[-3].str).lineNumber, (yyvsp[-3].str).ptr);
					errors++;
				}
				
				(yyval.node) = GetTreeNode(-1, NULL, NULL);
				(yyval.node)->value.func = func;
			}
#line 1544 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 225 "jlang.y" /* yacc.c:1646  */
    {
			if ((yyvsp[-4].node)->value.func != NULL)
			{
				(yyval.node) = (yyvsp[-4].node);
				
				struct procedureInfo* func = (yyvsp[-4].node)->value.func;			
				func->operations = (yyvsp[-1].node);  		// Îïåðàöèè âíóòðè ôóíêöèè
				func->varDeclaratons = curVarList;	// Ñïèñîê îáúÿâëåííûõ ïåðåìåííûõ
			}			
			curVarList = NULL;  // Íà÷àëî íîâîãî ñïèñêà ïåðåìåííûõ äëÿ ñëåäóþùåé ôóíêöèè
		}
#line 1560 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 240 "jlang.y" /* yacc.c:1646  */
    {
			struct variableInfo* var = GetVar((yyvsp[-1].num), (yyvsp[0].str).ptr, 1);			
			struct variableListNode* varList = AddToVariableList(var);
			
			if(varList == NULL)
			{
				printf("\nline %d: variable %s redeclared\n", (yyvsp[0].str).lineNumber, (yyvsp[0].str).ptr);
				errors++;
			}
			else AddToParamsList(NULL, var);

		}
#line 1577 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 253 "jlang.y" /* yacc.c:1646  */
    {
			struct variableInfo* var; 
			if((yyvsp[-3].num) == 0) 
				var = GetVar(3, (yyvsp[-2].str).ptr, 1);
			else if((yyvsp[-3].num) == 1) 
				var = GetVar(5, (yyvsp[-2].str).ptr, 1);
			
			
			struct variableListNode* varList = AddToVariableList(var);			
			if(varList == NULL)
			{
				printf("\nline %d: variable %s redeclared\n", (yyvsp[-2].str).lineNumber, (yyvsp[-2].str).ptr);
				errors++;
			}
			else AddToParamsList(NULL, var);
		}
#line 1598 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 279 "jlang.y" /* yacc.c:1646  */
    {
				struct variableInfo* var = GetVar((yyvsp[-2].num), (yyvsp[-1].str).ptr, 0);
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)	
				{				
					printf("\nline %d: variable %s redeclared\n", (yyvsp[-1].str).lineNumber, (yyvsp[-1].str).ptr);
					errors++;
				}
			}
#line 1612 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 289 "jlang.y" /* yacc.c:1646  */
    {					
				struct variableInfo* var = GetVar(3, (yyvsp[-4].str).ptr, 0); // Òèï ïåðåìåííîé - ìàññèâ
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)	
				{				
					printf("\nline %d: variable %s redeclared\n", (yyvsp[-4].str).lineNumber, (yyvsp[-4].str).ptr);
					errors++;
				}
				else
				{
					struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
					array->length = (yyvsp[-2].num);
					if((yyvsp[-5].num) == 0)				
						array->sizeOfElement = 1;	// CHAR				
					else if((yyvsp[-5].num) == 1)				
						array->sizeOfElement = 2;	// INT	
						
					var->value.arrayValue = array;
				}
			}
#line 1637 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 310 "jlang.y" /* yacc.c:1646  */
    {
				struct variableInfo* var = GetVar(4, (yyvsp[-5].str).ptr, 0); // Òèï ïåðåìåííîé - ìàññèâ
				struct variableListNode* varList = AddToVariableList(var);
				if(varList == NULL)		
				{
					printf("\nline %d: variable %s redeclared\n", (yyvsp[-5].str).lineNumber, (yyvsp[-5].str).ptr);
					errors++;
				}
				else
				{
					struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
					array->sizeOfElement = 1;
					array->length = strlen((yyvsp[-1].str).ptr) + 1;
					array->ptr = (yyvsp[-1].str).ptr;
						
					var->value.arrayValue = array;
				}
			}
#line 1660 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 334 "jlang.y" /* yacc.c:1646  */
    {
				errors++;
			}
#line 1668 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 344 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = GetTreeNode(4, NULL, NULL);
		(yyval.node)->value.params = NULL;
	}
#line 1677 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 349 "jlang.y" /* yacc.c:1646  */
    {			
		(yyval.node) = GetTreeNode(4, NULL, NULL);
        (yyval.node)->value.params = AddToArgsList((yyvsp[0].node), NULL);
	}
#line 1686 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 354 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = GetTreeNode(4, NULL, NULL);
        (yyval.node)->value.params = AddToArgsList((yyvsp[0].node), (yyvsp[-2].node)->value.params);
	}
#line 1695 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "jlang.y" /* yacc.c:1646  */
    {
		struct variableInfo* var = CheckVariable((yyvsp[0].str).ptr);
		if(var == NULL)
		{
			printf("\nline %d: variable %s undeclared\n", (yyvsp[0].str).lineNumber, (yyvsp[0].str).ptr);
			(yyval.node) = NULL;
			errors++;
		}
		else
		{
			(yyval.node) = GetTreeNode(0, NULL, NULL);
			(yyval.node)->value.var = var;
		}
				
	}
#line 1715 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 378 "jlang.y" /* yacc.c:1646  */
    {
		struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
		constant->type = 0; // Òèï êîíñòàíòû - NUMBER
        constant->value.intValue = (yyvsp[0].num);
		
		(yyval.node) = GetTreeNode(1, NULL, NULL);
		(yyval.node)->value.constant = constant;
	}
#line 1728 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 387 "jlang.y" /* yacc.c:1646  */
    {	
		struct arrayInfo* array = (struct arrayInfo*)malloc(sizeof(struct arrayInfo));
		array->sizeOfElement = 1;
        array->length = strlen((yyvsp[0].str).ptr) + 1;
        array->ptr = (yyvsp[0].str).ptr;
		
		struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
		constant->type = 1; // Òèï êîíñòàíòû - ñòðîêà
        constant->value.arrValue = array;
        
		(yyval.node) = GetTreeNode(1, NULL, NULL);
		(yyval.node)->value.constant = constant;		
	}
#line 1746 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 404 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
			}
#line 1754 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 409 "jlang.y" /* yacc.c:1646  */
    {				
				(yyval.node) = GetTreeNode(3, (yyvsp[0].node), (yyvsp[-1].node));
			}
#line 1762 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 413 "jlang.y" /* yacc.c:1646  */
    {
				errors++;
			}
#line 1770 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 419 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[-1].node);
			}
#line 1778 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 423 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(3, NULL, (yyvsp[0].node));
			}
#line 1786 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 431 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(11, (yyvsp[-2].node), (yyvsp[0].node));	
			}
#line 1794 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 439 "jlang.y" /* yacc.c:1646  */
    {				
				(yyval.node) = GetTreeNode(12, NULL, (yyvsp[-1].node)); // Òèï 12 - PRINT
				// Ïðàâàÿ âåòâü - àðãóìåíò print'à
			}
#line 1803 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 447 "jlang.y" /* yacc.c:1646  */
    {
				struct variableInfo* var = CheckVariable((yyvsp[-1].str).ptr);
				if(var == NULL)
				{
					printf("\nline %d: variable %s undeclared\n", (yyvsp[-1].str).lineNumber, (yyvsp[-1].str).ptr);
					(yyval.node) = NULL;
					errors++;
				}
				else
				{
					(yyval.node) = GetTreeNode(13, NULL, NULL); 
					(yyval.node)->value.var = var;
				}				
			}
#line 1822 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 465 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 1830 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 470 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1838 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 474 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 1846 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 478 "jlang.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 1854 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 485 "jlang.y" /* yacc.c:1646  */
    {
			struct variableInfo* var = CheckVariable((yyvsp[-3].str).ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", (yyvsp[-3].str).lineNumber, (yyvsp[-3].str).ptr);
				(yyval.node) = NULL;
				errors++;
			}
			else
			{
				(yyval.node) = GetTreeNode(44, NULL, (yyvsp[-1].node));
				(yyval.node)->value.var = var;
			}		
		}
#line 1873 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 503 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 1881 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 507 "jlang.y" /* yacc.c:1646  */
    {
			struct variableInfo* var = CheckVariable((yyvsp[-2].str).ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", (yyvsp[-2].str).lineNumber, (yyvsp[-2].str).ptr);
				(yyval.node) = NULL;
				errors++;
			}
			else
			{
				(yyval.node) = GetTreeNode(7, NULL, (yyvsp[0].node));
				(yyval.node)->value.var = var;
			}
		}
#line 1900 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 522 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(8, (yyvsp[-2].node), (yyvsp[0].node));
		}
#line 1908 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 534 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[0].node);
			}
#line 1916 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 538 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(40, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1924 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 542 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(35, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1932 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 546 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(36, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1940 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 550 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(39, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1948 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 554 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(37, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1956 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 558 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(38, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1964 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 565 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[0].node);
			}
#line 1972 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 569 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(42, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1980 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 576 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[0].node);
			}
#line 1988 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 580 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(43, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 1996 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 588 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[0].node);
			}
#line 2004 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 592 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(30, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 2012 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 596 "jlang.y" /* yacc.c:1646  */
    {
				(yyval.node) = GetTreeNode(31, (yyvsp[-2].node), (yyvsp[0].node));
			}
#line 2020 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 600 "jlang.y" /* yacc.c:1646  */
    {
				errors++;
			}
#line 2028 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 604 "jlang.y" /* yacc.c:1646  */
    {
				errors++;
			}
#line 2036 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 612 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 2044 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 616 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(33, (yyvsp[-2].node), (yyvsp[0].node));
		}
#line 2052 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 620 "jlang.y" /* yacc.c:1646  */
    {
			errors++;
		}
#line 2060 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 629 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 2068 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 633 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(45, NULL, (yyvsp[0].node));
		}
#line 2076 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 637 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(46, NULL, (yyvsp[-1].node));
		}
#line 2084 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 641 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(47, NULL, (yyvsp[-1].node));
		}
#line 2092 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 645 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = GetTreeNode(41, NULL, (yyvsp[0].node));
		}
#line 2100 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 660 "jlang.y" /* yacc.c:1646  */
    {
			struct constantInfo* constant = (struct constantInfo*)malloc(sizeof(struct constantInfo));
			constant->type = 0; // Òèï êîíñòàíòû - NUMBER
			constant->value.intValue = (yyvsp[0].num);
			
			(yyval.node) = GetTreeNode(1, NULL, NULL);
			(yyval.node)->value.constant = constant;
		}
#line 2113 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 669 "jlang.y" /* yacc.c:1646  */
    {
			struct variableInfo* var = CheckVariable((yyvsp[0].str).ptr);
			if(var == NULL)
			{
				printf("\nline %d: variable %s undeclared\n", (yyvsp[0].str).lineNumber, (yyvsp[0].str).ptr);
				(yyval.node) = NULL;
				errors++;
			}
			else
			{
				(yyval.node) = GetTreeNode(0, NULL, NULL);
				(yyval.node)->value.var = var;
			}
		}
#line 2132 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 684 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[-1].node);
		}
#line 2140 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 688 "jlang.y" /* yacc.c:1646  */
    {
			struct procedureInfo* func = Checkprocedure((yyvsp[-3].str).ptr);
			if(func == NULL)	
			{			
				printf("\nline %d: procedure %s undeclared!\n", (yyvsp[-3].str).lineNumber, (yyvsp[-3].str).ptr);
				errors++;
			}
			else
			{
				(yyval.node) = GetTreeNode(14, NULL, (yyvsp[-1].node));
				(yyval.node)->value.func = func;
			}
		}
#line 2158 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 702 "jlang.y" /* yacc.c:1646  */
    {
			(yyval.node) = (yyvsp[0].node);
		}
#line 2166 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 709 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 0;}
#line 2172 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 710 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 1;}
#line 2178 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 711 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 2;}
#line 2184 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 712 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 3; }
#line 2190 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 713 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 4; }
#line 2196 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 714 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 5; }
#line 2202 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 715 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 6; }
#line 2208 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 716 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 7; }
#line 2214 "jlang.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 717 "jlang.y" /* yacc.c:1646  */
    { (yyval.num) = 8; }
#line 2220 "jlang.tab.c" /* yacc.c:1646  */
    break;


#line 2224 "jlang.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 719 "jlang.y" /* yacc.c:1906  */


struct treeNode* GetTreeNode(char nType, struct treeNode* Left, struct treeNode* Right)
{
	struct treeNode* node = (struct treeNode*)malloc(sizeof(struct treeNode));
    node->nodeType = nType;
    node->left = Left;
    node->right = Right;
    return node;
}

struct procedureInfo* Addprocedure(char fType, char *fName, struct paramsListNode* Params)
{
	// Ïðîâåðêà ïîâòîðíîãî îáúÿâëåíèÿ
	struct funcTableNode* workNode = FuncTable;
    while(workNode)
    {
        if(strcmp(fName, workNode->func->name) == 0)
			return NULL;		
        workNode = workNode->next;
    }

	struct procedureInfo* funcInfo = (struct procedureInfo*)malloc(sizeof(struct procedureInfo));	
    funcInfo->name = (char*)malloc(strlen(fName)+1);
	strcpy(funcInfo->name, fName);	
    funcInfo->type = fType;    
    funcInfo->params = Params;
	
	
	// Äîáàâëåíèå â ñïèñîê ôóíêöèé
    struct funcTableNode* funcNode = (struct funcTableNode*)malloc(sizeof(struct funcTableNode));
    funcNode->func = funcInfo;
    funcNode->next = NULL;

    workNode = FuncTable;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = funcNode;
    }
    else
    {
        FuncTable = funcNode;
    }

    return funcInfo;
}

struct procedureInfo* Checkprocedure(char *fName)
{
	struct funcTableNode* workNode = FuncTable;
	while(workNode)
	{
		if(strcmp(workNode->func->name, fName) == 0)
			return workNode->func;
			
		workNode = workNode->next;
	}
	return NULL;
}

struct paramsListNode* AddToParamsList(struct treeNode* node, struct variableInfo *pVar)
{
    struct parameterInfo *parameter = (struct parameterInfo*)malloc(sizeof(struct parameterInfo));
    parameter->var = pVar;
	parameter->node = node;
	
    struct  paramsListNode* listNode = (struct paramsListNode*)malloc(sizeof(struct paramsListNode));
    listNode->next = NULL;
    listNode->param = parameter;	
	
	struct  paramsListNode* workNode = curParamList;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = listNode;
    }
    else
    {
        curParamList = listNode;
    }
	return listNode;
}

// Âåðíóòü ñòðóêòóðó ïåðåìåííîé
struct variableInfo* GetVar(char vType, char *vName, int isParam)
{
    struct variableInfo* var = (struct variableInfo*)malloc(sizeof(struct variableInfo));
    var->type = vType;
	var->isParam = isParam;
	
	var->value.intValue = 0;
	var->value.charValue = 0;

    var->name = (char*)malloc(strlen(vName)+1);
    strcpy(var->name, vName);
    return var;
}

struct variableInfo* CheckVariable(char *vName)
{
	struct variableListNode* workNode = curVarList;
	while(workNode)
	{
		if(strcmp(workNode->var->name, vName) == 0)
			return workNode->var;
			
		workNode = workNode->next;
	}
	return NULL;
}

struct variableListNode* AddToVariableList(struct variableInfo *Var)
{	
	// Ïðîâåðêà íà ïîâòîð îáúÿâëåíèÿ
	struct variableListNode* workNode = curVarList;
	while(workNode)
	{
		if(strcmp(workNode->var->name, Var->name) == 0)
			return NULL;			
		workNode = workNode->next;
	}

	// Äîáàâëåíèå â ñïèñîê
    struct  variableListNode* listNode = (struct variableListNode*)malloc(sizeof(struct variableListNode));
    listNode->next = NULL;
    listNode->var = Var;
			
	workNode = curVarList;
    if(workNode)
    {
        while(workNode->next)
            workNode = workNode->next;
			
        workNode->next = listNode;
    }
    else
    {
        curVarList = listNode;
    }
	return listNode;
}

void printType(int type)
{
	if(type == 0) printf("int"); 
	else if (type == 1) printf("char"); 
	else if (type == 2) printf("void");
}

void printParameters(struct paramsListNode *params)
{
	struct  paramsListNode* workNode = params;
	while(workNode)
	{
		struct parameterInfo* parameter = workNode->param;
		
		printType(parameter->var->type);
		if(workNode->next == NULL)	printf(" %s", parameter->var->name);
		else printf(" %s, ", parameter->var->name);	
		
		workNode = workNode->next;
	}
}

void printVariableDeclarations(struct variableListNode* varDeclaratons)
{
	struct  variableListNode* workNode = varDeclaratons;
	while(workNode)
	{
		struct variableInfo* var = workNode->var;
		if(var->isParam == 0)
		{
			printType(var->type);
			if(workNode->next == NULL)	printf(" %s", var->name);
			else printf(" %s, ", var->name);
		}	
		workNode = workNode->next;
	}
}

void printSpaces(int num)
{
	int i;
	printf("\n");
	for(i = 0; i < num; i++)
		printf("   ");
}

void printLogicTree(struct treeNode *root)
{
	if(!root) return;
	if((root->nodeType < 0) || (root->nodeType > 1 && root->nodeType < 14) || (root->nodeType > 14 && root->nodeType < 30)
		|| (root->nodeType > 47)) return;	
	  
	printLogicTree(root->left);
	
	switch(root->nodeType)
	{
		case 30:
			printf("+");
			break;
		case 31:
			printf("-");
			break;
		case 32:
			printf("*");
			break;
		case 33:
			printf("/");
			break;
		case 34:
			printf("=");
			break;
		case 35:
			printf("<");
			break;
		case 36:
			printf(">");
			break;
		case 37:
			printf("<=");
			break;
		case 38:
			printf(">=");
			break;
		case 39:
			printf("==");
			break;
		case 40:
			printf("!=");
			break;
		case 41:
			printf("!");
			break;
		case 42:
			printf("||");
			break;
		case 43:
			printf("&&");
			break;
			
		case 44:  // ìàññèâ
			printf(root->value.var->name);
			printf("["); 
			printLogicTree(root->right); 
			printf("]");
			return;
		
		case 45:
			printf("-");
			printLogicTree(root->right); 
			return;
			
		case 46:			
			printLogicTree(root->right); 
			printf("++");
			return;
			
		case 47:
			printLogicTree(root->right); 
			printf("--");
			return;
			
		case 14:  // Âûçîâ ôóíêöèè
			printf("%s(..)", root->value.func->name);
			return;
			
		case 0: // Ïåðåìåííàÿ
			printf(root->value.var->name);
			break;
			
		case 1: // Êîíñòàíòà
			printf("%d", root->value.constant->value.intValue);
			break;
	}
		
	printLogicTree(root->right);
}


void printOperators(struct treeNode *operations, int depth)
{
	struct treeNode* rightNode;
	struct treeNode* workNode = operations;
	
	while(workNode)
	{
		printSpaces(depth);
		
		rightNode = workNode->right;
		if(rightNode) //printf(" %d", workNode->right->nodeType);
		{
			switch(rightNode->nodeType)
			{
				case 7:
					printf("assignment: %s = ", rightNode->value.var->name);
					printLogicTree(rightNode->right);
					break;
				
				case 8:
					printf("assignment: %s[", rightNode->left->value.var->name);
					printLogicTree(rightNode->left->right);
					printf("] = ");
					printLogicTree(rightNode->right);
					break;
					
				case 9:  // for
					printf("FOR: ");
					printLogicTree(rightNode->left); printf("; ");
					printLogicTree(rightNode->right->left); printf("; ");
					printLogicTree(rightNode->right->right);
					
					printOperators(rightNode->value.node, depth+1);						
					break;
					
				case 10: // if
					printf("IF: ");
					printLogicTree(rightNode->value.node);
					printOperators(rightNode->left, depth+1);	
					
					if(rightNode->right)
					{
						printSpaces(depth);
						printf("ELSE:");
						printOperators(rightNode->right, depth+1);
					}
					break;
					
				case 11: // while
					printf("WHILE: ");
					printLogicTree(rightNode->left);
					printOperators(rightNode->right, depth+1);
					break;
					
				case 12: // print
					printf("PRINT: ");
					if(rightNode->right->nodeType == 0)
						printf(rightNode->right->value.var->name);
					else if(rightNode->right->nodeType == 1)
					{
						if(rightNode->right->value.constant->type == 0)
							printf("%d", rightNode->right->value.constant->value.intValue);
						else if(rightNode->right->value.constant->type == 1)
							printf(rightNode->right->value.constant->value.arrValue->ptr);
					}					
					break;
				
				case 13: // scan	
					printf("SCAN: ");
					printf(rightNode->value.var->name);					
					break;
					
				case 14: // procedure call
					printf("%s(..)", rightNode->value.func->name);					
					break;
					
				case 15: // return
					printf("RETURN ");
					printLogicTree(rightNode->right);
					break;
					
				default:
					printLogicTree(rightNode);
			}
		}
	
		
		
		//----------------------------------------------------
		workNode = workNode->left;
	}
}

void ShowproceduresSemantic()
{
	struct funcTableNode* workNode = FuncTable;
	while(workNode)
	{
		struct procedureInfo* func = workNode->func;
		//--------------------------------------
		printf("\n\n/procedure/: ");
		printType(func->type);
		printf(" %s", func->name);
		
		printf("\n/Parameters/: ");
		printParameters(func->params);
		
		printf("\n/Variable declarations/: ");
		printVariableDeclarations(func->varDeclaratons);
		
		printf("\n/Operators/: ");
		printOperators(func->operations, 0);
		
		//--------------------------------------	
		workNode = workNode->next;
		printf("\n---------------------------------------");
	}
}


struct paramsListNode* AddToArgsList(struct treeNode* node, struct paramsListNode *Next)
{
    struct parameterInfo *parameter = (struct parameterInfo*)malloc(sizeof(struct parameterInfo));
    parameter->var = NULL;
	parameter->node = node;
	
    struct  paramsListNode* listNode = (struct paramsListNode*)malloc(sizeof(struct paramsListNode));
    listNode->next = Next;
    listNode->param = parameter;
    return listNode;
}
