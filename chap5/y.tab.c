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
#line 1 "tiger.y"

#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "errormsg.h"
#include "absyn.h"

#define YYDEBUG 1

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
  EM_error(EM_tokPos, "%s", s);
}


/* Line 268 of yacc.c  */
#line 91 "y.tab.c"

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
     ID = 258,
     STRING = 259,
     INT = 260,
     OR = 261,
     AND = 262,
     GE = 263,
     GT = 264,
     LE = 265,
     LT = 266,
     NEQ = 267,
     EQ = 268,
     MINUS = 269,
     PLUS = 270,
     DIVIDE = 271,
     TIMES = 272,
     UMINUS = 273,
     COMMA = 274,
     COLON = 275,
     SEMICOLON = 276,
     LPAREN = 277,
     RPAREN = 278,
     LBRACK = 279,
     RBRACK = 280,
     LBRACE = 281,
     RBRACE = 282,
     DOT = 283,
     ASSIGN = 284,
     ARRAY = 285,
     IF = 286,
     THEN = 287,
     ELSE = 288,
     WHILE = 289,
     FOR = 290,
     TO = 291,
     DO = 292,
     LET = 293,
     IN = 294,
     END = 295,
     OF = 296,
     BREAK = 297,
     NIL = 298,
     FUNCTION = 299,
     VAR = 300,
     TYPE = 301
   };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INT 260
#define OR 261
#define AND 262
#define GE 263
#define GT 264
#define LE 265
#define LT 266
#define NEQ 267
#define EQ 268
#define MINUS 269
#define PLUS 270
#define DIVIDE 271
#define TIMES 272
#define UMINUS 273
#define COMMA 274
#define COLON 275
#define SEMICOLON 276
#define LPAREN 277
#define RPAREN 278
#define LBRACK 279
#define RBRACK 280
#define LBRACE 281
#define RBRACE 282
#define DOT 283
#define ASSIGN 284
#define ARRAY 285
#define IF 286
#define THEN 287
#define ELSE 288
#define WHILE 289
#define FOR 290
#define TO 291
#define DO 292
#define LET 293
#define IN 294
#define END 295
#define OF 296
#define BREAK 297
#define NIL 298
#define FUNCTION 299
#define VAR 300
#define TYPE 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 20 "tiger.y"

	int pos;
	int ival;
	string sval;
  A_var var;
  A_exp exp;
  A_dec dec;
  A_ty ty;
  A_decList decList;
  A_expList expList;
  A_field field;
  A_fieldList fieldList;
  A_efield efield;
  A_efieldList efieldList;



/* Line 293 of yacc.c  */
#line 237 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 249 "y.tab.c"

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    17,    21,    25,
      29,    33,    37,    41,    45,    49,    53,    57,    61,    63,
      65,    69,    71,    73,    76,    83,    90,    95,   100,   109,
     111,   117,   121,   123,   127,   132,   136,   138,   142,   147,
     151,   153,   157,   160,   161,   163,   165,   167,   172,   174,
     178,   182,   185,   186,   190,   191,   195,   200,   207,   215,
     225,   227,   231,   235,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    65,    -1,    65,    29,    49,
      -1,    51,    -1,    49,    17,    49,    -1,    49,    16,    49,
      -1,    49,    15,    49,    -1,    49,    14,    49,    -1,    49,
      13,    49,    -1,    49,    12,    49,    -1,    49,    11,    49,
      -1,    49,    10,    49,    -1,    49,     9,    49,    -1,    49,
       8,    49,    -1,    49,     7,    49,    -1,    49,     6,    49,
      -1,    53,    -1,    43,    -1,    22,    50,    23,    -1,     5,
      -1,     4,    -1,    14,    49,    -1,     3,    24,    49,    25,
      41,    49,    -1,    31,    49,    32,    49,    33,    49,    -1,
      31,    49,    32,    49,    -1,    34,    49,    37,    49,    -1,
      35,     3,    29,    49,    36,    49,    37,    49,    -1,    42,
      -1,    38,    56,    39,    50,    40,    -1,    49,    21,    50,
      -1,    49,    -1,     3,    22,    23,    -1,     3,    22,    52,
      23,    -1,    49,    19,    52,    -1,    49,    -1,     3,    26,
      27,    -1,     3,    26,    54,    27,    -1,    55,    19,    54,
      -1,    55,    -1,     3,    13,    49,    -1,    57,    56,    -1,
      -1,    58,    -1,    63,    -1,    64,    -1,    46,     3,    13,
      59,    -1,     3,    -1,    26,    60,    27,    -1,    30,    41,
       3,    -1,    62,    61,    -1,    -1,    19,    62,    61,    -1,
      -1,     3,    20,     3,    -1,    45,     3,    29,    49,    -1,
      45,     3,    20,     3,    29,    49,    -1,    44,     3,    22,
      60,    23,    13,    49,    -1,    44,     3,    22,    60,    23,
      20,     3,    13,    49,    -1,     3,    -1,     3,    28,     3,
      -1,    65,    28,     3,    -1,     3,    24,    49,    25,    -1,
      65,    24,    49,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    99,   100,   102,   103,   105,   106,   108,   109,   111,
     112,   114,   117,   118,   120,   121,   122,   125,   127,   128,
     129,   131,   132,   134,   135,   137,   140,   141,   144,   145,
     148,   149,   150,   151,   152
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "OR", "AND", "GE",
  "GT", "LE", "LT", "NEQ", "EQ", "MINUS", "PLUS", "DIVIDE", "TIMES",
  "UMINUS", "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK",
  "RBRACK", "LBRACE", "RBRACE", "DOT", "ASSIGN", "ARRAY", "IF", "THEN",
  "ELSE", "WHILE", "FOR", "TO", "DO", "LET", "IN", "END", "OF", "BREAK",
  "NIL", "FUNCTION", "VAR", "TYPE", "$accept", "program", "exp", "expseq",
  "funcall", "argseq", "rec_creation", "efield_seq", "efield", "decs",
  "dec", "tydec", "ty", "tyfields", "tail_tyfields", "tyfield", "vardec",
  "fundec", "lvalue", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    57,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     1,     2,     6,     6,     4,     4,     8,     1,
       5,     3,     1,     3,     4,     3,     1,     3,     4,     3,
       1,     3,     2,     0,     1,     1,     1,     4,     1,     3,
       3,     2,     0,     3,     0,     3,     4,     6,     7,     9,
       1,     3,     3,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,    22,    21,     0,     0,     0,     0,     0,    43,
      29,    19,     0,     2,     5,    18,     3,     0,     0,     0,
       0,    23,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    44,    45,    46,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    36,     0,     0,     0,    37,     0,    40,    61,
       0,    20,     0,     0,     0,     0,     0,     0,     0,    42,
      17,    16,    15,    14,    13,    12,    11,    10,     9,     8,
       7,     6,     0,    62,     4,     0,    34,    63,     0,    38,
       0,    31,    26,    27,     0,    52,     0,     0,     0,     0,
      64,    35,     0,    41,    39,     0,     0,     0,     0,    54,
       0,    56,    48,    52,     0,    47,    30,    24,    25,     0,
       0,     0,     0,    51,     0,     0,     0,     0,    55,     0,
       0,    54,    57,    49,    50,    28,    58,     0,    53,     0,
      59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    12,    22,    23,    14,    53,    15,    57,    58,    30,
      31,    32,   115,   108,   123,   109,    33,    34,    16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
      77,    43,   -58,   -58,    77,    77,    77,    77,     2,   -32,
     -58,   -58,    19,   286,   -58,   -58,    30,    52,    77,     5,
      31,   -58,   256,    10,   189,    14,     6,    49,    50,    57,
      22,   -32,   -58,   -58,   -58,   -58,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    65,
      77,   -58,   272,    47,   216,    60,   -58,    51,    58,   -58,
      77,   -58,    77,    77,    77,    62,   -19,    66,    77,   -58,
     164,   164,   203,   203,   203,   203,   203,   203,    -1,    -1,
     -58,   -58,   236,   -58,   286,    77,   -58,    48,    77,   -58,
      89,   -58,   177,   286,   146,    90,    93,    77,    46,    61,
     -58,   -58,    77,   286,   -58,    77,    77,    78,    80,    81,
      75,   286,   -58,    90,    68,   -58,   -58,   286,   286,   134,
     104,   -11,    90,   -58,    77,    83,   110,    77,   -58,    77,
     111,    81,   286,   -58,   -58,   286,   286,   103,   -58,    77,
     286
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,     0,   -57,   -58,    32,   -58,    28,   -58,    91,
     -58,   -58,   -58,     8,    -8,     3,   -58,   -58,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      13,    96,   129,    91,    21,    26,    24,    25,    55,   130,
      97,    99,    27,    28,    29,    46,    47,    52,    54,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    56,    61,    59,    64,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   112,
      84,    63,    65,    66,    48,     1,     2,     3,    49,    50,
      67,    68,    92,    93,    94,    17,     4,    18,    83,    19,
      86,    20,   113,    88,     5,    51,   114,    90,    89,    98,
       1,     2,     3,     6,    95,    52,     7,     8,   103,   102,
       9,     4,    55,   107,    10,    11,   110,   111,   120,     5,
     122,   116,   117,   121,   124,   118,   119,   128,     6,   126,
     133,     7,     8,   134,   137,     9,   139,   101,   104,    10,
      11,   125,    69,   138,   132,   131,     0,   135,     0,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,   127,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,   106,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     0,     0,     0,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    62,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,    87,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
       0,   100,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,    60,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    85,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-58))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
       0,    20,    13,    60,     4,     3,     6,     7,     3,    20,
      29,    68,    44,    45,    46,    16,    17,    17,    18,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    27,    23,     3,    29,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,     3,
      50,    37,     3,     3,    24,     3,     4,     5,    28,    29,
       3,    39,    62,    63,    64,    22,    14,    24,     3,    26,
      23,    28,    26,    13,    22,    23,    30,    19,    27,    13,
       3,     4,     5,    31,    22,    85,    34,    35,    88,    41,
      38,    14,     3,     3,    42,    43,     3,    97,    20,    22,
      19,    40,   102,    23,    29,   105,   106,     3,    31,    41,
      27,    34,    35,     3,     3,    38,    13,    85,    90,    42,
      43,   113,    31,   131,   124,   122,    -1,   127,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    36,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      33,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    32,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    21,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    19,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    14,    22,    31,    34,    35,    38,
      42,    43,    48,    49,    51,    53,    65,    22,    24,    26,
      28,    49,    49,    50,    49,    49,     3,    44,    45,    46,
      56,    57,    58,    63,    64,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    24,    28,
      29,    23,    49,    52,    49,     3,    27,    54,    55,     3,
      21,    23,    32,    37,    29,     3,     3,     3,    39,    56,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,     3,    49,    19,    23,    25,    13,    27,
      19,    50,    49,    49,    49,    22,    20,    29,    13,    50,
      25,    52,    41,    49,    54,    33,    36,     3,    60,    62,
       3,    49,     3,    26,    30,    59,    40,    49,    49,    49,
      20,    23,    19,    61,    29,    60,    41,    37,     3,    13,
      20,    62,    49,    27,     3,    49,    49,     3,    61,    13,
      49
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
#line 69 "tiger.y"
    { absyn_root = (yyvsp[(1) - (1)].exp); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 70 "tiger.y"
    { (yyval.exp) = A_VarExp(EM_tokPos, (yyvsp[(1) - (1)].var)); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 71 "tiger.y"
    { (yyval.exp) = A_AssignExp(EM_tokPos, (yyvsp[(1) - (3)].var), (yyvsp[(3) - (3)].exp)); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 72 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 73 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_timesOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 74 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_divideOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 75 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_plusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 76 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 77 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_eqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 78 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_neqOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 79 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_ltOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 80 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_leOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 81 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_gtOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 82 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_geOp, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 83 "tiger.y"
    { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].exp), A_IntExp(EM_tokPos, 0)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 84 "tiger.y"
    { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(1) - (3)].exp), A_IntExp(EM_tokPos, 1), (yyvsp[(3) - (3)].exp)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 85 "tiger.y"
    { (yyval.exp) = (yyvsp[(1) - (1)].exp); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 86 "tiger.y"
    { (yyval.exp) = A_NilExp(EM_tokPos); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 87 "tiger.y"
    { (yyval.exp) = A_SeqExp(EM_tokPos, (yyvsp[(2) - (3)].expList)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 88 "tiger.y"
    { (yyval.exp) = A_IntExp(EM_tokPos, yylval.ival); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 89 "tiger.y"
    { (yyval.exp) = A_StringExp(EM_tokPos, yylval.sval); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 90 "tiger.y"
    { (yyval.exp) = A_OpExp(EM_tokPos, A_minusOp, A_IntExp(0, 0), (yyvsp[(2) - (2)].exp)); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 91 "tiger.y"
    { (yyval.exp) = A_ArrayExp(EM_tokPos, S_Symbol((yyvsp[(1) - (6)].sval)), (yyvsp[(3) - (6)].exp), (yyvsp[(6) - (6)].exp)); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 92 "tiger.y"
    { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(2) - (6)].exp), (yyvsp[(4) - (6)].exp), (yyvsp[(6) - (6)].exp)); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 93 "tiger.y"
    { (yyval.exp) = A_IfExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp), A_NilExp(0)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 94 "tiger.y"
    { (yyval.exp) = A_WhileExp(EM_tokPos, (yyvsp[(2) - (4)].exp), (yyvsp[(4) - (4)].exp)); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 95 "tiger.y"
    { (yyval.exp) = A_ForExp(EM_tokPos, S_Symbol((yyvsp[(2) - (8)].sval)), (yyvsp[(4) - (8)].exp), (yyvsp[(6) - (8)].exp), (yyvsp[(8) - (8)].exp)); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 96 "tiger.y"
    { (yyval.exp) = A_BreakExp(EM_tokPos); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 97 "tiger.y"
    { (yyval.exp) = A_LetExp(EM_tokPos, (yyvsp[(2) - (5)].decList), (yyvsp[(4) - (5)].expList)); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 99 "tiger.y"
    { (yyval.expList) = A_ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].expList)); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 100 "tiger.y"
    { (yyval.expList) = A_ExpList((yyvsp[(1) - (1)].exp), NULL); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 102 "tiger.y"
    { (yyval.exp) = A_CallExp(EM_tokPos, S_Symbol((yyvsp[(1) - (3)].sval)), NULL); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 103 "tiger.y"
    { (yyval.exp) = A_CallExp(EM_tokPos, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].expList)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 105 "tiger.y"
    { (yyval.expList) = A_ExpList((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].expList)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 106 "tiger.y"
    { (yyval.expList) = A_ExpList((yyvsp[(1) - (1)].exp), NULL); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 108 "tiger.y"
    { (yyval.exp) = A_RecordExp(EM_tokPos, S_Symbol((yyvsp[(1) - (3)].sval)), NULL); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 109 "tiger.y"
    { (yyval.exp) = A_RecordExp(EM_tokPos, S_Symbol((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].efieldList)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 111 "tiger.y"
    { (yyval.efieldList) = A_EfieldList((yyvsp[(1) - (3)].efield), (yyvsp[(3) - (3)].efieldList)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 112 "tiger.y"
    { (yyval.efieldList) = A_EfieldList((yyvsp[(1) - (1)].efield), NULL); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 114 "tiger.y"
    { (yyval.efield) = A_Efield(S_Symbol((yyvsp[(1) - (3)].sval)), (yyvsp[(3) - (3)].exp)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 117 "tiger.y"
    { (yyval.decList) = A_DecList((yyvsp[(1) - (2)].dec), (yyvsp[(2) - (2)].decList)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 118 "tiger.y"
    { (yyval.decList) = NULL; }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 120 "tiger.y"
    { (yyval.dec) = (yyvsp[(1) - (1)].dec); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 121 "tiger.y"
    { (yyval.dec) = (yyvsp[(1) - (1)].dec); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 122 "tiger.y"
    { (yyval.dec) = (yyvsp[(1) - (1)].dec); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 125 "tiger.y"
    { (yyval.dec) = A_TypeDec(EM_tokPos, S_Symbol((yyvsp[(2) - (4)].sval)), (yyvsp[(4) - (4)].ty)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 127 "tiger.y"
    { (yyval.ty) = A_NameTy(S_Symbol((yyvsp[(1) - (1)].sval))); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 128 "tiger.y"
    { (yyval.ty) = A_RecordTy((yyvsp[(2) - (3)].fieldList)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 129 "tiger.y"
    { (yyval.ty) = A_ArrayTy(S_Symbol((yyvsp[(3) - (3)].sval))); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 131 "tiger.y"
    { (yyval.fieldList) = A_FieldList((yyvsp[(1) - (2)].field), (yyvsp[(2) - (2)].fieldList)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 132 "tiger.y"
    { (yyval.fieldList) = NULL; }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 134 "tiger.y"
    { (yyval.fieldList) = A_FieldList((yyvsp[(2) - (3)].field), (yyvsp[(3) - (3)].fieldList)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 135 "tiger.y"
    { (yyval.fieldList) = NULL; }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 137 "tiger.y"
    { (yyval.field) = A_Field(EM_tokPos, S_Symbol((yyvsp[(1) - (3)].sval)), S_Symbol((yyvsp[(3) - (3)].sval))); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 140 "tiger.y"
    { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[(2) - (4)].sval)), NULL, (yyvsp[(4) - (4)].exp)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 141 "tiger.y"
    { (yyval.dec) = A_VarDec(EM_tokPos, S_Symbol((yyvsp[(2) - (6)].sval)), S_Symbol((yyvsp[(4) - (6)].sval)), (yyvsp[(6) - (6)].exp)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 144 "tiger.y"
    {(yyval.dec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[(2) - (7)].sval)), (yyvsp[(4) - (7)].fieldList), NULL, (yyvsp[(7) - (7)].exp)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 145 "tiger.y"
    {(yyval.dec) = A_Fundec(EM_tokPos, S_Symbol((yyvsp[(2) - (9)].sval)), (yyvsp[(4) - (9)].fieldList), S_Symbol((yyvsp[(7) - (9)].sval)), (yyvsp[(9) - (9)].exp)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 148 "tiger.y"
    { (yyval.var) = A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[(1) - (1)].sval))); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 149 "tiger.y"
    { (yyval.var) = A_FieldVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[(1) - (3)].sval))), S_Symbol((yyvsp[(3) - (3)].sval))); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 150 "tiger.y"
    { (yyval.var) = A_FieldVar(EM_tokPos, (yyvsp[(1) - (3)].var), S_Symbol((yyvsp[(3) - (3)].sval))); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 151 "tiger.y"
    { (yyval.var) = A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[(1) - (4)].sval))), (yyvsp[(3) - (4)].exp)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 152 "tiger.y"
    { (yyval.var) = A_SubscriptVar(EM_tokPos, (yyvsp[(1) - (4)].var), (yyvsp[(3) - (4)].exp)); }
    break;



/* Line 1806 of yacc.c  */
#line 2067 "y.tab.c"
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



