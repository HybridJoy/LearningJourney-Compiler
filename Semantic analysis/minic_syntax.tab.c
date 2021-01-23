/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "minic_syntax.y" /* yacc.c:339  */

	#include <stdio.h>
	#include "treenode.h"
	#include "symboltable.h"
	#include <stdarg.h>
	#include <stdlib.h>

	// Syntax error number
	int syntaxErrorNum = 0;

	// Lexical error number
	extern int lexicalErrorNum;

#line 80 "minic_syntax.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "minic_syntax.tab.h".  */
#ifndef YY_YY_MINIC_SYNTAX_TAB_H_INCLUDED
# define YY_YY_MINIC_SYNTAX_TAB_H_INCLUDED
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
    TYPE = 258,
    ID = 259,
    INTEGER = 260,
    FLOATING = 261,
    STRING = 262,
    CHAR = 263,
    IF = 264,
    ELSE = 265,
    DO = 266,
    WHILE = 267,
    FOR = 268,
    BREAK = 269,
    CONTINUE = 270,
    RETURN = 271,
    QUALIFIER = 272,
    ADD = 273,
    SUB = 274,
    MULT = 275,
    DIV = 276,
    AND = 277,
    OR = 278,
    NOT = 279,
    ASSIGNOP = 280,
    COMPARE = 281,
    LOGICAND = 282,
    LOGICOR = 283,
    LOGICNOT = 284,
    LP = 285,
    RP = 286,
    LB = 287,
    RB = 288,
    LC = 289,
    RC = 290,
    SEMI = 291,
    COMMA = 292,
    DOT = 293,
    EOL = 294,
    SPACE = 295,
    COMMENT = 296,
    AERROR = 297,
    LOWER_THAN_ELSE = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "minic_syntax.y" /* yacc.c:355  */

	struct treeNode* node;

#line 168 "minic_syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_MINIC_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "minic_syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   718

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    84,    91,    95,   102,   109,   117,   125,
     130,   139,   144,   152,   160,   168,   176,   184,   191,   199,
     206,   214,   221,   229,   236,   242,   250,   276,   283,   287,
     293,   298,   305,   311,   317,   326,   337,   346,   356,   370,
     377,   384,   391,   400,   407,   414,   421,   428,   436,   451,
     458,   465,   475,   482,   486,   494,   502,   510,   515,   523,
     540,   547,   554,   561,   567,   574,   582,   590,   598,   606,
     613,   620,   628,   636,   643,   651,   658,   666,   673,   678,
     684,   690,   695,   701,   708,   715,   723,   730
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ID", "INTEGER", "FLOATING",
  "STRING", "CHAR", "IF", "ELSE", "DO", "WHILE", "FOR", "BREAK",
  "CONTINUE", "RETURN", "QUALIFIER", "ADD", "SUB", "MULT", "DIV", "AND",
  "OR", "NOT", "ASSIGNOP", "COMPARE", "LOGICAND", "LOGICOR", "LOGICNOT",
  "LP", "RP", "LB", "RB", "LC", "RC", "SEMI", "COMMA", "DOT", "EOL",
  "SPACE", "COMMENT", "AERROR", "LOWER_THAN_ELSE", "$accept", "Program",
  "CodeDefList", "CodeDef", "CodeDecList", "VarDec", "FunDec", "VarList",
  "ParamDec", "Compst", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -82

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-82)))

#define YYTABLE_NINF -54

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,    17,    19,   -82,     9,   -10,    90,    -4,    84,     7,
     -82,   -82,    83,   108,    59,   -82,   386,    10,    55,   -82,
     252,   -82,   -82,    55,   -82,    33,    28,   -82,    35,   -82,
     -82,    13,   386,    67,   -82,   -82,   -82,   -82,   386,   386,
     386,   386,   638,    85,    86,   -82,   -82,    55,    55,   284,
     252,   -15,   -82,   110,   -82,   -82,   -82,   407,   355,   337,
     -25,   -25,     8,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   394,   119,   -82,   -82,   -15,    88,    91,
       1,    62,   316,    80,   102,     2,    60,   386,   -82,    95,
     284,    57,   -82,   -82,   -82,   -82,   428,   100,   -82,   -82,
     337,   337,   -25,   -25,   208,   208,   638,   680,   659,   659,
     347,   449,   -82,   -82,    55,   -82,   -82,   386,   386,   121,
     386,   386,   386,   386,   -82,   -82,   -82,   -82,   124,   -82,
     -82,   -82,   -82,   386,   -82,   -82,   -82,   -82,   470,   147,
     107,   491,   170,   512,   533,   -82,   -82,   -82,   316,   316,
     316,   386,   386,   316,   316,   316,   386,   386,   128,   -82,
     143,   554,   193,   -82,   -82,   -82,   575,   596,   316,   316,
     -82,   -82,   -82,   386,   386,   -82,   -82,   617,   216,   316,
     316,   316,   -82,   -82,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     0,     0,     9,     0,
       1,     3,     0,     0,     0,     5,     0,     0,     0,     8,
       0,     7,     6,     0,    22,     0,    24,    18,     0,    20,
      16,     0,     0,    78,    79,    80,    81,    82,     0,     0,
       0,     0,    13,     0,     0,    11,    10,     0,     0,     0,
       0,    25,    21,     0,    17,    19,    15,     0,     0,    70,
      63,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    12,    59,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,    52,    23,    84,    75,    87,     0,    85,    69,
      65,    66,    67,    68,    61,    62,    60,    64,    71,    72,
       0,     0,    77,    55,     0,    56,    54,     0,     0,     0,
       0,     0,     0,     0,    42,    33,    41,    32,     0,    26,
      27,    39,    29,     0,    74,    83,    76,    58,     0,     0,
       0,     0,     0,     0,     0,    40,    31,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    48,
      34,     0,     0,    45,    49,    36,     0,     0,     0,     0,
      46,    50,    37,     0,     0,    44,    35,     0,     0,     0,
       0,     0,    47,    51,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   150,   -82,   137,   111,   -82,    -8,   -82,   152,
      69,   -81,   113,   -82,   -44,   -82,   -16,    31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    77,     9,    25,    26,    88,
      89,    90,    49,    50,    78,    79,    91,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   119,   115,   124,    80,    28,    31,    73,    19,    98,
      16,    43,     1,    74,    55,    44,    57,    17,     5,    10,
      12,     6,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    15,    69,    70,    71,    72,   116,   125,    99,
      73,    20,    96,    21,    56,    93,    74,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   111,   131,    45,
      29,   126,    23,   117,    52,    53,    54,   158,   159,   160,
     137,   128,   163,   164,   165,    63,    64,    65,    66,    67,
      68,   120,    69,    70,    71,    72,    23,   175,   176,    73,
      30,    13,   118,   132,    57,    74,   127,    58,   182,   183,
     184,   138,   139,   122,   141,   142,   143,   144,   151,    16,
     121,    23,     8,    23,    24,   -11,    17,    96,    75,    76,
      14,    18,   -11,   112,   113,   145,   -11,   -11,   114,     8,
     129,   134,   123,   140,    51,   161,   162,   152,   168,    27,
     166,   167,    63,    64,    65,    66,    67,    68,   149,    69,
      70,    71,    72,   169,    11,    46,    73,   177,   178,   130,
     146,    22,    74,    92,   147,    63,    64,    65,    66,    67,
      68,   154,    69,    70,    71,    72,     0,     0,   150,    73,
       0,     0,     0,     0,     0,    74,     0,     0,    63,    64,
      65,    66,    67,    68,   171,    69,    70,    71,    72,     0,
       0,   155,    73,     0,     0,     0,     0,     0,    74,     0,
       0,    63,    64,    65,    66,    67,    68,   180,    69,    70,
      71,    72,     0,     0,   172,    73,    63,    64,    65,    66,
       0,    74,     0,     0,    63,    64,    65,    66,    67,    68,
      73,    69,    70,    71,    72,     0,    74,   181,    73,     0,
       0,     0,     0,    47,    74,    48,   -53,   -53,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,     0,
       0,   -53,     0,     0,     0,     0,   -53,     0,     0,     0,
       0,   -53,   -53,     0,     0,    32,   -53,   -53,    33,    34,
      35,    36,    37,    81,     0,    82,    83,    84,    85,    86,
      87,     0,     0,    38,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    40,    41,     0,     0,    32,    20,   -28,
      33,    34,    35,    36,    37,    81,     0,    82,    83,    84,
      85,    86,    87,     0,     0,    38,     0,     0,     0,     0,
      39,     0,     0,     0,     0,    40,    41,     0,    32,     0,
      20,    33,    34,    35,    36,    37,    32,    65,    66,    33,
      34,    35,    36,    37,     0,     0,    38,     0,     0,    73,
       0,    39,     0,     0,    38,    74,    40,    41,     0,    39,
     135,     0,     0,     0,    40,    41,    95,    32,     0,     0,
      33,    34,    35,    36,    37,   110,     0,     0,    33,    34,
      35,    36,    37,     0,     0,    38,     0,     0,     0,     0,
      39,     0,     0,    38,     0,    40,    41,     0,    39,     0,
       0,     0,     0,    40,    41,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,     0,    94,    73,
       0,     0,     0,     0,     0,    74,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,     0,     0,     0,
      73,     0,     0,     0,     0,   133,    74,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,     0,     0,
       0,    73,   136,     0,     0,     0,     0,    74,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,     0,
       0,   148,    73,     0,     0,     0,     0,     0,    74,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
       0,     0,   153,    73,     0,     0,     0,     0,     0,    74,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,     0,     0,     0,    73,     0,     0,     0,   156,     0,
      74,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,     0,     0,     0,    73,     0,     0,     0,   157,
       0,    74,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,     0,     0,   170,    73,     0,     0,     0,
       0,     0,    74,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,     0,     0,     0,    73,     0,     0,
       0,   173,     0,    74,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,     0,     0,     0,    73,     0,
       0,     0,   174,     0,    74,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,     0,     0,   179,    73,
       0,     0,     0,     0,     0,    74,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,     0,     0,     0,
      73,     0,     0,     0,     0,     0,    74,    63,    64,    65,
      66,    67,    68,     0,     0,    70,     0,     0,     0,     0,
       0,    73,     0,     0,     0,     0,     0,    74,    63,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      16,    82,     1,     1,    48,    13,    14,    32,     1,     1,
      25,     1,     3,    38,     1,     5,    32,    32,     1,     0,
      30,     4,    38,    39,    40,    41,    18,    19,    20,    21,
      22,    23,    36,    25,    26,    27,    28,    36,    36,    31,
      32,    34,    58,    36,    31,    53,    38,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     1,     4,
       1,     1,     3,     1,    31,    37,    31,   148,   149,   150,
     114,    87,   153,   154,   155,    18,    19,    20,    21,    22,
      23,     1,    25,    26,    27,    28,     3,   168,   169,    32,
      31,     1,    30,    36,   110,    38,    36,    30,   179,   180,
     181,   117,   118,     1,   120,   121,   122,   123,     1,    25,
      30,     3,     1,     3,    31,    25,    32,   133,    33,    33,
      30,    37,    32,     4,    36,     1,    36,    37,    37,    18,
      35,    31,    30,    12,    23,   151,   152,    30,    10,    31,
     156,   157,    18,    19,    20,    21,    22,    23,     1,    25,
      26,    27,    28,    10,     4,    18,    32,   173,   174,    90,
      36,     9,    38,    50,   133,    18,    19,    20,    21,    22,
      23,     1,    25,    26,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    18,    19,
      20,    21,    22,    23,     1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    18,    19,    20,    21,    22,    23,     1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    18,    19,    20,    21,
      -1,    38,    -1,    -1,    18,    19,    20,    21,    22,    23,
      32,    25,    26,    27,    28,    -1,    38,    31,    32,    -1,
      -1,    -1,    -1,     1,    38,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,     1,    34,    35,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,     1,    34,    35,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    29,    30,    -1,     1,    -1,
      34,     4,     5,     6,     7,     8,     1,    20,    21,     4,
       5,     6,     7,     8,    -1,    -1,    19,    -1,    -1,    32,
      -1,    24,    -1,    -1,    19,    38,    29,    30,    -1,    24,
      33,    -1,    -1,    -1,    29,    30,    31,     1,    -1,    -1,
       4,     5,     6,     7,     8,     1,    -1,    -1,     4,     5,
       6,     7,     8,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    19,    -1,    29,    30,    -1,    24,    -1,
      -1,    -1,    -1,    29,    30,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    37,    38,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    38,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    18,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      18,    19,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    -1,
      38,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
      -1,    38,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    36,    -1,    38,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    -1,    38,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    18,    19,    20,    21,
      22,    23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    18,    19,    20,
      21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    45,    46,    47,     1,     4,    48,    49,    50,
       0,    46,    30,     1,    30,    36,    25,    32,    37,     1,
      34,    36,    53,     3,    31,    51,    52,    31,    51,     1,
      31,    51,     1,     4,     5,     6,     7,     8,    19,    24,
      29,    30,    60,     1,     5,     4,    48,     1,     3,    56,
      57,    49,    31,    37,    31,     1,    31,    60,    30,    60,
      60,    60,    60,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    32,    38,    33,    33,    49,    58,    59,
      58,     9,    11,    12,    13,    14,    15,    16,    53,    54,
      55,    60,    56,    51,    31,    31,    60,    61,     1,    31,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       1,    60,     4,    36,    37,     1,    36,     1,    30,    55,
       1,    30,     1,    30,     1,    36,     1,    36,    60,    35,
      54,     1,    36,    37,    31,    33,    33,    58,    60,    60,
      12,    60,    60,    60,    60,     1,    36,    61,    31,     1,
      31,     1,    30,    31,     1,    31,    36,    36,    55,    55,
      55,    60,    60,    55,    55,    55,    60,    60,    10,    10,
      31,     1,    31,    36,    36,    55,    55,    60,    60,    31,
       1,    31,    55,    55,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    58,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     3,     3,     1,
       3,     1,     4,     3,     4,     4,     3,     4,     3,     4,
       3,     4,     3,     3,     1,     2,     4,     2,     0,     2,
       1,     3,     2,     2,     5,     7,     5,     6,     9,     2,
       3,     2,     2,     5,     7,     5,     6,     9,     5,     5,
       6,     9,     2,     0,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     2,     4,     3,     4,     3,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "minic_syntax.y" /* yacc.c:1646  */
    {
		  	if((yyvsp[0].node) == NULL)
		  	{
		  		(yyval.node) = NULL;
		  	}
		  	else
		  	{
		  		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Program", NULL, 1);
		  		(yyval.node)->children[0] = (yyvsp[0].node);
		  	}
		  	root = (yyval.node);
		  	if(syntaxErrorNum + lexicalErrorNum > 0)
		  	{
		  		printf("Total Error Numbers   : %d \n", syntaxErrorNum + lexicalErrorNum);
		  		printf("Lexical Error Numbers : %d \n", lexicalErrorNum);
		  		printf("Syntax Error Numbers  : %d \n", syntaxErrorNum);
		  		printf("please correct the mistake.\n");	  		
		  	}
				

		  	printf("\nprint syntax tree\n");
				PrintTreeNode((yyval.node), 0);
				printf("syntax print finish!\n");

				CreateSymbolTable((yyval.node));
				PrintSymbolTable();
				FreeSymbolTable();
		}
#line 1623 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "minic_syntax.y" /* yacc.c:1646  */
    {
			  	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDefList", NULL, 2);
			  	(yyval.node)->children[0] = (yyvsp[-1].node);
			  	(yyval.node)->children[1] = (yyvsp[0].node);
			}
#line 1633 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "minic_syntax.y" /* yacc.c:1646  */
    {
				(yyval.node) = NULL;
			}
#line 1641 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "minic_syntax.y" /* yacc.c:1646  */
    {
			CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDef", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
		}
#line 1652 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "minic_syntax.y" /* yacc.c:1646  */
    {
	    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDef", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
	    }
#line 1663 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "minic_syntax.y" /* yacc.c:1646  */
    {
	    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDef", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
	    }
#line 1674 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "minic_syntax.y" /* yacc.c:1646  */
    {
	    	syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	    }
#line 1685 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 126 "minic_syntax.y" /* yacc.c:1646  */
    {
				CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDecList", NULL, 1);
				(yyval.node)->children[0] = (yyvsp[0].node);
			}
#line 1694 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 131 "minic_syntax.y" /* yacc.c:1646  */
    {
	   			CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "CodeDecList", NULL, 3);
					(yyval.node)->children[0] = (yyvsp[-2].node);
					(yyval.node)->children[1] = (yyvsp[-1].node);
					(yyval.node)->children[2] = (yyvsp[0].node);
	   		}
#line 1705 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 140 "minic_syntax.y" /* yacc.c:1646  */
    {
	   		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "VarDec", NULL, 1);
				(yyval.node)->children[0] = (yyvsp[0].node);
	   }
#line 1714 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 145 "minic_syntax.y" /* yacc.c:1646  */
    {
	   		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "VarDec", NULL, 4);
				(yyval.node)->children[0] = (yyvsp[-3].node);
				(yyval.node)->children[1] = (yyvsp[-2].node);
				(yyval.node)->children[2] = (yyvsp[-1].node);
				(yyval.node)->children[3] = (yyvsp[0].node);
	   }
#line 1726 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 153 "minic_syntax.y" /* yacc.c:1646  */
    {
				CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "VarDec", NULL, 3);
				(yyval.node)->children[0] = (yyvsp[-2].node);
				(yyval.node)->children[1] = (yyvsp[-1].node);
				(yyval.node)->children[2] = (yyvsp[0].node);
		}
#line 1737 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 161 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Expected type 'int'\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1748 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "minic_syntax.y" /* yacc.c:1646  */
    {
	   		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "FunDec", NULL, 4);
				(yyval.node)->children[0] = (yyvsp[-3].node);
				(yyval.node)->children[1] = (yyvsp[-2].node);
				(yyval.node)->children[2] = (yyvsp[-1].node);
				(yyval.node)->children[3] = (yyvsp[0].node);
	   }
#line 1760 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "minic_syntax.y" /* yacc.c:1646  */
    {
	   		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "FunDec", NULL, 3);
				(yyval.node)->children[0] = (yyvsp[-2].node);
				(yyval.node)->children[1] = (yyvsp[-1].node);
				(yyval.node)->children[2] = (yyvsp[0].node);
	   }
#line 1771 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1782 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 192 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1793 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1804 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 207 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1815 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 215 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Wrong Function Name\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1826 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 222 "minic_syntax.y" /* yacc.c:1646  */
    {
		    syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Wrong Function Name\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	   }
#line 1837 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 230 "minic_syntax.y" /* yacc.c:1646  */
    {
						CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "VarList", NULL, 3);
						(yyval.node)->children[0] = (yyvsp[-2].node);
						(yyval.node)->children[1] = (yyvsp[-1].node);
						(yyval.node)->children[2] = (yyvsp[0].node);
				}
#line 1848 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "minic_syntax.y" /* yacc.c:1646  */
    {
						CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "VarList", NULL, 1);
						(yyval.node)->children[0] = (yyvsp[0].node);
				}
#line 1857 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 243 "minic_syntax.y" /* yacc.c:1646  */
    {
		    CreateTreeNode(&(yyval.node),1, (yyloc).first_line, "ParamDec", NULL, 2);
		    (yyval.node)->children[0] = (yyvsp[-1].node);
		    (yyval.node)->children[1] = (yyvsp[0].node);
  	     }
#line 1867 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 251 "minic_syntax.y" /* yacc.c:1646  */
    {
	   		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Compst", NULL, 4);
				(yyval.node)->children[0] = (yyvsp[-3].node);
				(yyval.node)->children[1] = (yyvsp[-2].node);
				(yyval.node)->children[2] = (yyvsp[-1].node);
				(yyval.node)->children[3] = (yyvsp[0].node);
	   }
#line 1879 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 277 "minic_syntax.y" /* yacc.c:1646  */
    {
		 	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "StmtList", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
		 }
#line 1889 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 283 "minic_syntax.y" /* yacc.c:1646  */
    {
	     	(yyval.node) = NULL;
	     }
#line 1897 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 288 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
	 }
#line 1907 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 294 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
	 }
#line 1916 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 299 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
	 }
#line 1927 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 306 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
	 }
#line 1937 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 312 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
	 }
#line 1947 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 318 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 5);
			(yyval.node)->children[0] = (yyvsp[-4].node);
			(yyval.node)->children[1] = (yyvsp[-3].node);
			(yyval.node)->children[2] = (yyvsp[-2].node);
			(yyval.node)->children[3] = (yyvsp[-1].node);
			(yyval.node)->children[4] = (yyvsp[0].node);
	 }
#line 1960 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 327 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 7);
			(yyval.node)->children[0] = (yyvsp[-6].node);
			(yyval.node)->children[1] = (yyvsp[-5].node);
			(yyval.node)->children[2] = (yyvsp[-4].node);
			(yyval.node)->children[3] = (yyvsp[-3].node);
			(yyval.node)->children[4] = (yyvsp[-2].node);
			(yyval.node)->children[5] = (yyvsp[-1].node);
			(yyval.node)->children[6] = (yyvsp[0].node);
	 }
#line 1975 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 338 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 5);
			(yyval.node)->children[0] = (yyvsp[-4].node);
			(yyval.node)->children[1] = (yyvsp[-3].node);
			(yyval.node)->children[2] = (yyvsp[-2].node);
			(yyval.node)->children[3] = (yyvsp[-1].node);
			(yyval.node)->children[4] = (yyvsp[0].node);
	 }
#line 1988 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 347 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 6);
			(yyval.node)->children[0] = (yyvsp[-5].node);
			(yyval.node)->children[1] = (yyvsp[-4].node);
			(yyval.node)->children[2] = (yyvsp[-3].node);
			(yyval.node)->children[3] = (yyvsp[-2].node);
			(yyval.node)->children[4] = (yyvsp[-1].node);
			(yyval.node)->children[5] = (yyvsp[0].node);
	 }
#line 2002 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 357 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Stmt", NULL, 9);
			(yyval.node)->children[0] = (yyvsp[-8].node);
			(yyval.node)->children[1] = (yyvsp[-7].node);
			(yyval.node)->children[2] = (yyvsp[-6].node);
			(yyval.node)->children[3] = (yyvsp[-5].node);
			(yyval.node)->children[4] = (yyvsp[-4].node);
			(yyval.node)->children[5] = (yyvsp[-3].node);
			(yyval.node)->children[6] = (yyvsp[-2].node);
			(yyval.node)->children[7] = (yyvsp[-1].node);
			(yyval.node)->children[8] = (yyvsp[0].node);
	 }
#line 2019 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 371 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2030 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 378 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2041 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 385 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2052 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 392 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2063 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 401 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2074 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 408 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2085 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 415 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2096 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 422 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2107 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 429 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ( \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2118 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 437 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2129 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 452 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2140 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 459 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2151 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 466 "minic_syntax.y" /* yacc.c:1646  */
    {
	 		syntaxErrorNum = syntaxErrorNum + 1;
		    printf("Line %d : %d (Syntax Error) Missing \" ) \"\n", (yyloc).first_line, (yyloc).last_column);
		    // make the syntax analysis to the normal state 
		    yyerrok;
	 }
#line 2162 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 476 "minic_syntax.y" /* yacc.c:1646  */
    {
			CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "DefList", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
		}
#line 2172 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 482 "minic_syntax.y" /* yacc.c:1646  */
    {
	    	(yyval.node) = NULL;
	    }
#line 2180 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 487 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Def", NULL, 3);
		(yyval.node)->children[0] = (yyvsp[-2].node);
		(yyval.node)->children[1] = (yyvsp[-1].node);
		(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2191 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 495 "minic_syntax.y" /* yacc.c:1646  */
    {
    	syntaxErrorNum = syntaxErrorNum + 1;
		printf("Line %d : %d (Syntax Error) Not Defination Type\n", (yyloc).first_line, (yyloc).last_column);
		// make the syntax analysis to the normal state 
		yyerrok;
    }
#line 2202 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 503 "minic_syntax.y" /* yacc.c:1646  */
    {
    	syntaxErrorNum = syntaxErrorNum + 1;
		printf("Line %d : %d (Syntax Error) Missing \" ; \"\n", (yyloc).first_line, (yyloc).last_column);
		// make the syntax analysis to the normal state 
		yyerrok;
    }
#line 2213 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 511 "minic_syntax.y" /* yacc.c:1646  */
    {
			CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "DecList", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
		}
#line 2222 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 516 "minic_syntax.y" /* yacc.c:1646  */
    {
	    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "DecList", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
	    }
#line 2233 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 524 "minic_syntax.y" /* yacc.c:1646  */
    {
		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Dec", NULL, 1);
		(yyval.node)->children[0] = (yyvsp[0].node);
	}
#line 2242 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 541 "minic_syntax.y" /* yacc.c:1646  */
    {
		CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
		(yyval.node)->children[0] = (yyvsp[-2].node);
		(yyval.node)->children[1] = (yyvsp[-1].node);
		(yyval.node)->children[2] = (yyvsp[0].node);
	}
#line 2253 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 548 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2264 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 555 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2275 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 562 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
    }
#line 2285 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 568 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2296 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 575 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) + ((yyvsp[-1].node)->value);
    }
#line 2308 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 583 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) - ((yyvsp[-1].node)->value);
    }
#line 2320 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 591 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) * ((yyvsp[-1].node)->value);
    }
#line 2332 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 599 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) / ((yyvsp[-1].node)->value);
    }
#line 2344 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 607 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2355 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 614 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
			(yyval.node)->value = -((yyvsp[0].node)->value);
    }
#line 2366 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 621 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) && ((yyvsp[-1].node)->value);
    }
#line 2378 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 629 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
			(yyval.node)->value = ((yyvsp[-2].node)->value) || ((yyvsp[-1].node)->value);
    }
#line 2390 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 637 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 2);
			(yyval.node)->children[0] = (yyvsp[-1].node);
			(yyval.node)->children[1] = (yyvsp[0].node);
			(yyval.node)->value = ! ((yyvsp[0].node)->value);
    }
#line 2401 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 644 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 4);
			(yyval.node)->children[0] = (yyvsp[-3].node);
			(yyval.node)->children[1] = (yyvsp[-2].node);
			(yyval.node)->children[2] = (yyvsp[-1].node);
			(yyval.node)->children[3] = (yyvsp[0].node);
    }
#line 2413 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 652 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2424 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 659 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 4);
			(yyval.node)->children[0] = (yyvsp[-3].node);
			(yyval.node)->children[1] = (yyvsp[-2].node);
			(yyval.node)->children[2] = (yyvsp[-1].node);
			(yyval.node)->children[3] = (yyvsp[0].node);
    }
#line 2436 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 667 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
    }
#line 2447 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 674 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
    }
#line 2456 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 679 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
			(yyval.node)->value = (yyvsp[0].node)->value;
    }
#line 2466 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 685 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
			(yyval.node)->value = (yyvsp[0].node)->value;
    }
#line 2476 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 691 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
    }
#line 2485 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 696 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Exp", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
    }
#line 2494 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 702 "minic_syntax.y" /* yacc.c:1646  */
    {
    	 	syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Expected type 'int'\n", (yyloc).first_line, (yyloc).last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
    }
#line 2505 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 709 "minic_syntax.y" /* yacc.c:1646  */
    {
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ( \" \n", (yyloc).first_line, (yyloc).last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
#line 2516 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 716 "minic_syntax.y" /* yacc.c:1646  */
    {
				syntaxErrorNum = syntaxErrorNum + 1;
				printf("Line %d : %d (Syntax Error) Missing \" ) \" \n", (yyloc).first_line, (yyloc).last_column);
				// make the syntax analysis to the normal state 
				yyerrok;
		}
#line 2527 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 724 "minic_syntax.y" /* yacc.c:1646  */
    {
    	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Args", NULL, 3);
			(yyval.node)->children[0] = (yyvsp[-2].node);
			(yyval.node)->children[1] = (yyvsp[-1].node);
			(yyval.node)->children[2] = (yyvsp[0].node);
     }
#line 2538 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 731 "minic_syntax.y" /* yacc.c:1646  */
    {
     	CreateTreeNode(&(yyval.node), 1, (yyloc).first_line, "Args", NULL, 1);
			(yyval.node)->children[0] = (yyvsp[0].node);
     }
#line 2547 "minic_syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2551 "minic_syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 736 "minic_syntax.y" /* yacc.c:1906  */


int yyerror(char* msg) 
{
    return 0;
}

int main()
{
    yyparse();
    return 0;
}
