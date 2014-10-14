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
#line 1 "parse.y"
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/* Modified by Brett Kercher - February-May, 2014

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "instvars.c"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;



/* Line 268 of yacc.c  */
#line 137 "y.tab.c"

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
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PLUS = 261,
     MINUS = 262,
     TIMES = 263,
     DIVIDE = 264,
     ASSIGN = 265,
     EQ = 266,
     NE = 267,
     LT = 268,
     LE = 269,
     GE = 270,
     GT = 271,
     POINT = 272,
     DOT = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     DIV = 277,
     MOD = 278,
     IN = 279,
     COMMA = 280,
     SEMICOLON = 281,
     COLON = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     DOTDOT = 287,
     ARRAY = 288,
     BEGINBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FILEFILE = 296,
     FOR = 297,
     FUNCTION = 298,
     GOTO = 299,
     IF = 300,
     LABEL = 301,
     NIL = 302,
     OF = 303,
     PACKED = 304,
     PROCEDURE = 305,
     PROGRAM = 306,
     RECORD = 307,
     REPEAT = 308,
     SET = 309,
     THEN = 310,
     TO = 311,
     TYPE = 312,
     UNTIL = 313,
     VAR = 314,
     WHILE = 315,
     WITH = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 301 "y.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    14,    18,    22,    26,    30,    34,
      36,    39,    43,    45,    49,    53,    57,    59,    63,    66,
      70,    74,    78,    80,    84,    87,    91,    95,    97,   101,
     104,   108,   110,   113,   120,   124,   128,   130,   132,   136,
     140,   146,   150,   154,   156,   160,   162,   166,   172,   179,
     186,   191,   196,   198,   200,   204,   207,   210,   212,   215,
     220,   224,   226,   230,   232,   235,   236,   240,   244,   248,
     252,   256,   260,   264,   268,   270,   274,   278,   280,   284,
     286,   290,   292,   294,   297,   299,   301,   303,   305,   309,
     312,   317,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    18,    -1,    51,     3,    28,    83,
      29,    26,    66,    -1,    34,    84,    89,    -1,    46,    67,
      65,    -1,    46,    67,    75,    -1,    46,    67,    72,    -1,
      46,    67,    69,    -1,    69,    -1,    68,    26,    -1,     5,
      25,    68,    -1,     5,    -1,    36,    70,    65,    -1,    36,
      70,    66,    -1,    36,    70,    75,    -1,    72,    -1,    71,
      26,    70,    -1,    71,    26,    -1,     3,    11,    95,    -1,
      57,    73,    65,    -1,    57,    73,    75,    -1,    75,    -1,
      74,    26,    73,    -1,    74,    26,    -1,     3,    11,    78,
      -1,    59,    76,    65,    -1,    65,    -1,    77,    26,    76,
      -1,    77,    26,    -1,    82,    27,    78,    -1,    80,    -1,
      17,    80,    -1,    33,    30,    79,    31,    48,    78,    -1,
      52,    81,    40,    -1,    80,    25,    79,    -1,    80,    -1,
       3,    -1,    28,    82,    29,    -1,    95,    32,    95,    -1,
      82,    27,    78,    26,    81,    -1,    82,    27,    78,    -1,
       3,    25,    82,    -1,     3,    -1,    92,    25,    83,    -1,
      92,    -1,    34,    84,    89,    -1,    45,    92,    55,    84,
      90,    -1,    42,    91,    56,    92,    37,    84,    -1,    42,
      91,    38,    92,    37,    84,    -1,    53,    85,    58,    92,
      -1,    60,    92,    37,    84,    -1,    87,    -1,    91,    -1,
       5,    27,    84,    -1,    44,     5,    -1,    84,    86,    -1,
      84,    -1,    26,    85,    -1,     3,    28,    88,    29,    -1,
      92,    25,    83,    -1,    92,    -1,    26,    84,    89,    -1,
      40,    -1,    39,    84,    -1,    -1,    96,    10,    92,    -1,
      93,    11,    93,    -1,    93,    13,    93,    -1,    93,    16,
      93,    -1,    93,    12,    93,    -1,    93,    14,    93,    -1,
      93,    15,    93,    -1,    93,    24,    93,    -1,    93,    -1,
      92,     6,    94,    -1,    92,     7,    94,    -1,    94,    -1,
      94,     8,    95,    -1,    95,    -1,    28,    92,    29,    -1,
      96,    -1,     5,    -1,     7,    96,    -1,     4,    -1,    87,
      -1,    47,    -1,     3,    -1,    96,    18,     3,    -1,    96,
      17,    -1,    96,    30,    97,    31,    -1,    92,    25,    97,
      -1,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    84,    84,    87,    91,    95,    96,    97,    98,    99,
     102,   105,   106,   109,   110,   111,   112,   115,   116,   119,
     123,   124,   125,   128,   129,   132,   136,   137,   140,   141,
     144,   147,   148,   149,   152,   155,   156,   158,   159,   160,
     163,   164,   166,   167,   170,   171,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   187,   188,   191,   195,
     198,   199,   202,   203,   206,   207,   210,   213,   214,   215,
     216,   217,   218,   219,   220,   223,   224,   225,   227,   228,
     231,   232,   233,   234,   235,   236,   237,   240,   241,   242,
     243,   246,   247
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "header", "block", "lblock", "labelspecs", "labelgroup", "cblock",
  "constspecs", "constgroup", "tblock", "typespecs", "typegroup", "vblock",
  "varspecs", "vargroup", "type", "index", "simpletype", "fieldlist",
  "idlist", "argument", "statement", "statements", "endstates", "funcall",
  "funargs", "endpart", "endif", "assignment", "expr", "simexpr", "term",
  "factor", "variable", "exprlist", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    66,    66,    66,    66,    66,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      72,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    87,
      88,    88,    89,    89,    90,    90,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    97,    97
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     7,     3,     3,     3,     3,     3,     1,
       2,     3,     1,     3,     3,     3,     1,     3,     2,     3,
       3,     3,     1,     3,     2,     3,     3,     1,     3,     2,
       3,     1,     2,     6,     3,     3,     1,     1,     3,     3,
       5,     3,     3,     1,     3,     1,     3,     5,     6,     6,
       4,     4,     1,     1,     3,     2,     2,     1,     2,     4,
       3,     1,     3,     1,     2,     0,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     3,     2,
       4,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     2,     0,    87,    84,
      82,     0,     0,    86,     0,    85,    45,    74,    77,    79,
      81,     0,    87,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
       0,    61,    80,     0,    75,    76,    44,     0,    67,    70,
      68,    71,    72,    69,    73,    78,    88,    92,     0,    59,
       0,     0,     0,     0,     0,     0,    27,     3,     9,    16,
      22,     0,    90,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    52,    53,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,    43,     0,     0,     0,    91,     0,
       0,     0,    55,     0,    57,     0,     0,     0,    63,     4,
       0,     0,    13,    14,    15,    18,     0,     5,     8,     7,
       6,    10,     0,    20,    21,    24,     0,    26,    29,     0,
      54,    46,     0,     0,     0,     0,    56,     0,     0,     0,
      66,    19,    17,    11,    37,     0,     0,     0,     0,    25,
      31,     0,    23,    42,    28,    30,     0,     0,    65,    58,
      50,    51,    62,    32,    87,     0,     0,     0,     0,     0,
       0,     0,     0,    47,    38,     0,    36,    34,     0,    39,
      49,    48,    64,     0,     0,    41,     0,    35,     0,    33,
      40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    66,    67,    89,    90,    68,    86,    87,
      69,    92,    93,    70,    95,    96,   149,   175,   150,   167,
      97,    14,   104,   105,   136,    15,    40,   109,   173,    83,
      47,    17,    18,    19,    20,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -129
static const yytype_int16 yypact[] =
{
     -49,     9,    29,    15,     3,  -129,  -129,     6,    12,  -129,
    -129,    39,     6,  -129,    42,  -129,    83,   174,    69,  -129,
     175,     6,  -129,   175,    77,    60,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,  -129,    92,     6,
      78,   149,  -129,   112,    69,    69,  -129,   105,   174,   174,
     174,   174,   174,   174,   174,  -129,  -129,   156,    91,  -129,
       6,    94,   106,   120,   134,   147,  -129,  -129,  -129,  -129,
    -129,     6,  -129,  -129,   145,    94,    39,   159,     6,    94,
       6,    -5,  -129,  -129,   103,   164,   112,   151,   158,    13,
     173,   189,   -14,   176,   178,   167,   187,   188,  -129,    94,
      -5,    37,  -129,     0,   190,   146,    30,    94,  -129,  -129,
       6,     6,  -129,  -129,  -129,   106,   120,  -129,  -129,  -129,
    -129,  -129,    11,  -129,  -129,   134,   147,  -129,   147,    11,
    -129,  -129,     6,     6,    94,    94,  -129,     6,    94,    -5,
     105,  -129,  -129,  -129,   150,    98,   137,   184,   147,  -129,
    -129,   185,  -129,  -129,  -129,  -129,    55,    67,   179,  -129,
     105,  -129,  -129,  -129,   166,   191,    98,   181,   192,     6,
      94,    94,    94,  -129,  -129,   193,   197,  -129,    11,  -129,
    -129,  -129,  -129,   180,    98,   199,    11,  -129,   147,  -129,
    -129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,    84,   140,  -129,   107,   138,   114,  -129,
     141,   108,  -129,    43,   104,  -129,  -126,    47,  -128,    46,
    -122,    -3,   -53,   100,  -129,   -56,  -129,   -70,  -129,   160,
      20,   177,   170,   -35,   -11,   168
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      23,    55,     1,   155,   153,    82,    26,    27,    81,     8,
       9,    10,     4,    11,   144,     9,    10,   163,    11,    82,
      61,   107,   100,    82,   165,    46,   168,    16,   145,     5,
     131,     7,    24,     6,    12,   108,    26,    27,   176,   146,
      21,    41,    22,    82,   147,    65,   130,    61,    16,    62,
      84,    82,   185,    13,   139,   134,   176,    73,    13,    57,
     189,    26,    27,   148,    84,    84,   168,   138,    84,   162,
      64,    25,    65,    26,    27,   132,   141,    36,    82,    82,
      16,   158,    82,    26,    27,   161,    43,   151,    84,    26,
      27,    57,   170,   133,   151,    56,    84,     8,   103,    74,
     106,   144,     9,    10,   171,    11,    42,    59,    28,    85,
     151,    26,    27,   110,    82,    82,    82,   180,   181,   182,
      37,    38,    72,    84,    84,    88,   146,    84,    75,   114,
     140,   151,   120,    39,   179,   124,    76,    91,    77,    78,
     164,     9,    10,   151,    11,    13,    61,    79,    62,   151,
      94,   151,   156,   157,    80,    26,    27,   160,    63,    84,
      84,    84,    26,    27,   102,    12,    24,   -87,   -87,    64,
     112,    65,    99,   117,    60,   111,   123,   115,    21,   127,
     -87,    71,   -87,   116,    13,    29,    30,    31,    32,    33,
      34,   126,    37,    38,    21,   -43,    44,    45,    35,   121,
     122,    61,   125,   126,   137,    39,    48,    49,    50,    51,
      52,    53,    54,   128,   166,   129,   135,   169,   172,   178,
     174,   177,   184,   143,   183,   188,   113,   118,   186,   142,
     119,   187,   154,   152,   190,   159,   101,     0,     0,    98
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-129))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      11,    36,    51,   129,   126,    61,     6,     7,    61,     3,
       4,     5,     3,     7,     3,     4,     5,   145,     7,    75,
      34,    26,    75,    79,   146,    28,   148,     7,    17,     0,
     100,    28,    12,    18,    28,    40,     6,     7,   166,    28,
      28,    21,     3,    99,    33,    59,    99,    34,    28,    36,
      61,   107,   178,    47,   107,    55,   184,    60,    47,    39,
     186,     6,     7,    52,    75,    76,   188,    37,    79,   139,
      57,    29,    59,     6,     7,    38,   111,     8,   134,   135,
      60,   134,   138,     6,     7,   138,    26,   122,    99,     6,
       7,    71,    37,    56,   129,     3,   107,     3,    78,     5,
      80,     3,     4,     5,    37,     7,    29,    29,    25,     3,
     145,     6,     7,    10,   170,   171,   172,   170,   171,   172,
      17,    18,    31,   134,   135,     5,    28,   138,    34,    86,
     110,   166,    89,    30,   169,    92,    42,     3,    44,    45,
       3,     4,     5,   178,     7,    47,    34,    53,    36,   184,
       3,   186,   132,   133,    60,     6,     7,   137,    46,   170,
     171,   172,     6,     7,     5,    28,   146,    17,    18,    57,
      86,    59,    27,    89,    25,    11,    92,    26,    28,    95,
      30,    25,    32,    25,    47,    11,    12,    13,    14,    15,
      16,    25,    17,    18,    28,    29,    26,    27,    24,    26,
      11,    34,    26,    25,    58,    30,    29,    30,    31,    32,
      33,    34,    35,    26,    30,    27,    26,    32,    39,    27,
      29,    40,    25,   116,    31,    26,    86,    89,    48,   115,
      89,   184,   128,   125,   188,   135,    76,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,    64,     3,     0,    18,    28,     3,     4,
       5,     7,    28,    47,    83,    87,    92,    93,    94,    95,
      96,    28,     3,    96,    92,    29,     6,     7,    25,    11,
      12,    13,    14,    15,    16,    24,     8,    17,    18,    30,
      88,    92,    29,    26,    94,    94,    83,    92,    93,    93,
      93,    93,    93,    93,    93,    95,     3,    92,    97,    29,
      25,    34,    36,    46,    57,    59,    65,    66,    69,    72,
      75,    25,    31,    83,     5,    34,    42,    44,    45,    53,
      60,    84,    87,    91,    96,     3,    70,    71,     5,    67,
      68,     3,    73,    74,     3,    76,    77,    82,    97,    27,
      84,    91,     5,    92,    84,    85,    92,    26,    40,    89,
      10,    11,    65,    66,    75,    26,    25,    65,    69,    72,
      75,    26,    11,    65,    75,    26,    25,    65,    26,    27,
      84,    89,    38,    56,    55,    26,    86,    58,    37,    84,
      92,    95,    70,    68,     3,    17,    28,    33,    52,    78,
      80,    95,    73,    82,    76,    78,    92,    92,    84,    85,
      92,    84,    89,    80,     3,    82,    30,    81,    82,    32,
      37,    37,    39,    90,    29,    79,    80,    40,    27,    95,
      84,    84,    84,    31,    25,    78,    48,    79,    26,    78,
      81
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
#line 84 "parse.y"
    { parseresult = (yyvsp[(1) - (2)]); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 88 "parse.y"
    { (yyval) = makeprogram((yyvsp[(1) - (7)]), (yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]), (yyvsp[(7) - (7)])); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 92 "parse.y"
    { (yyval) = makeprogn((yyvsp[(1) - (3)]),cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 95 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 96 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 97 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 98 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 105 "parse.y"
    { instlabel((yyvsp[(1) - (3)])); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 106 "parse.y"
    { instlabel((yyvsp[(1) - (1)])); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 109 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 110 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 111 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 119 "parse.y"
    { instconst((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 123 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 124 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 132 "parse.y"
    { insttype((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 136 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 144 "parse.y"
    { instvars((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 148 "parse.y"
    { (yyval) =  instpoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 149 "parse.y"
    { (yyval) = instarray((yyvsp[(3) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 152 "parse.y"
    { (yyval) = instrec((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 155 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 158 "parse.y"
    { (yyval) = findtype((yyvsp[(1) - (1)])); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 159 "parse.y"
    { (yyval) = instenum((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 160 "parse.y"
    { (yyval) = instdotdot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 163 "parse.y"
    { (yyval) = cons(instfields((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)])), (yyvsp[(5) - (5)])); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 164 "parse.y"
    { (yyval) = instfields((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 166 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 167 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (1)]), NULL); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 170 "parse.y"
    { (yyval) = makeprogn((TOKEN) talloc(), cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 171 "parse.y"
    { (yyval) = makeprogn((TOKEN) talloc(), (yyvsp[(1) - (1)])); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 175 "parse.y"
    { (yyval) = makeprogn((yyvsp[(1) - (3)]),cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 176 "parse.y"
    { (yyval) = makeif((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 177 "parse.y"
    { (yyval) = makefor(1, (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 178 "parse.y"
    { (yyval) = makefor(-1, (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 179 "parse.y"
    { (yyval) = makerepeat((yyvsp[(1) - (4)]), makeprogn((TOKEN)talloc(), (yyvsp[(2) - (4)])), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 180 "parse.y"
    { (yyval) = makewhile((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 183 "parse.y"
    { (yyval) = dolabel((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 184 "parse.y"
    { (yyval) = dogoto((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 187 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 191 "parse.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 195 "parse.y"
    { (yyval) = makefuncall((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 198 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 199 "parse.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 202 "parse.y"
    { (yyval) = cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 203 "parse.y"
    { (yyval) = NULL; }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 206 "parse.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 207 "parse.y"
    { (yyval) = NULL; }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 210 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 213 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 214 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 215 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 216 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 217 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 218 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 219 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 223 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 224 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 227 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 231 "parse.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 234 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 237 "parse.y"
    { (yyval) = donil((yyvsp[(1) - (1)])); }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 240 "parse.y"
    { (yyval) = findid((yyvsp[(1) - (1)])); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 241 "parse.y"
    { (yyval) = arrayref((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (TOKEN)talloc());}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 242 "parse.y"
    { (yyval) = dopoint((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 243 "parse.y"
    { (yyval) = arrayref((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));}
    break;



/* Line 1806 of yacc.c  */
#line 2173 "y.tab.c"
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
#line 250 "parse.y"


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG       	 0             /* set bits here for debugging, 0 = off  */
#define DB_CONS      	 1             /* bit to trace cons */
#define DB_BINOP     	 2             /* bit to trace binop */
#define DB_MAKEIF    	 4             /* bit to trace makeif */
#define DB_MAKEPROGN 	 8             /* bit to trace makeprogn */
#define DB_PARSERES  	16             /* bit to trace parseresult */
#define DB_MAKEPROGRAM	32          /* bit to trace makeprogram */
#define DB_MAKEFOR   	64         	/* bit to trace makefor */
#define DB_MAKEFUNCALL	128
#define DB_INSTALLCONST 256
#define DB_UNARYOP		512

 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labels[5] = {0,0,0,0,0};

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }
  
TOKEN donil(TOKEN niltok)
{
	niltok->tokentype = NUMBERTOK;
	niltok->datatype = POINTER;
	niltok->intval = 0;
	return niltok;
}  
  
TOKEN findid(TOKEN tok)
{
	SYMBOL toksym = searchst(tok->stringval);
	if(toksym != NULL)
	{
		//If its a constant, smash it into its number
		if(toksym->kind == CONSTSYM)
		{
			tok->tokentype = NUMBERTOK;
			tok->datatype = toksym->basicdt;
			
			switch(toksym->basicdt)
			{
			case REAL:
				tok->realval = toksym->constval.realnum;
			break;
			case INTEGER:
				tok->intval = toksym->constval.intnum;
			break;
			}
		}
		else //If it's not a constant, set up symbol table pointers
		{
			SYMBOL typ = toksym->datatype;
			tok->symentry = toksym;
			tok->symtype = typ;
			tok->datatype = typ->basicdt;
		}
	}
	
	return tok;
}

TOKEN makefloat(TOKEN tok)
{
	/*tok->datatype = REAL;
	
	if(tok->tokentype == NUMBERTOK)
	{
		tok->realval = (float)tok->intval;
		return tok;
	}*/
	
	TOKEN floattok = (TOKEN) talloc();
	floattok->tokentype = OPERATOR;
	floattok->whichval = FLOATOP;
	floattok->datatype = REAL;
	
	return unaryop(floattok, tok);
}

TOKEN makefix(TOKEN tok)
{
	/*
	tok->datatype = INTEGER;
	if(tok->tokentype == NUMBERTOK)
	{
		tok->intval = (int)tok->realval;
		return tok;
	}
	*/

	TOKEN inttok = (TOKEN) talloc();
	inttok->tokentype = OPERATOR;
	inttok->whichval = FIXOP;
	inttok->datatype = INTEGER;
	
	return unaryop(inttok, tok);
}

TOKEN unaryop(TOKEN op, TOKEN lhs)
{
	op->operands = lhs;          /* link operands to operator       */
	lhs->link = NULL;             /* terminate op list    */
	if (DEBUG & DB_UNARYOP)
	{ 
		printf("unaryop\n");
		dbugprinttok(op);
		dbugprinttok(lhs);
	};
return op;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
{ 
	
	
	if(lhs->datatype != rhs->datatype)
	{
		if(op->whichval > 0 && op->whichval <= 4) // +, -, *, /
		{
			if(lhs->datatype == REAL && rhs->datatype == INTEGER)
			{
				rhs = makefloat(rhs);
			}
			else if(lhs->datatype == INTEGER && rhs->datatype == REAL)
			{
				lhs = makefloat(lhs);
			}
		}
		else if(op->whichval == ASSIGNOP)
		{
		      if(lhs->datatype == REAL)
		      {
					rhs = makefloat(rhs);
		      }
		      else if(lhs->datatype == INTEGER)
		      {
				if(lhs->tokentype == NUMBERTOK || lhs->tokentype == IDENTIFIERTOK)
					rhs = makefix(rhs);
		      }
		}
	}
	op->datatype = lhs->datatype;
	op->operands = lhs;          /* link operands to operator       */
	lhs->link = rhs;             /* link second operand to first    */
	rhs->link = NULL;            /* terminate operand list          */
	if (DEBUG & DB_BINOP)
	{ 
		printf("binop\n");
		dbugprinttok(op);
		dbugprinttok(lhs);
		dbugprinttok(rhs);
	};
return op;
}

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }
   
TOKEN makeprogram(TOKEN tok, TOKEN name, TOKEN arguments, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGRAMOP;
     tok->operands = name;
	 name->link = arguments;
	 arguments->link = statements;
     if (DEBUG & DB_MAKEPROGRAM)
       { printf("makeprogram\n");
         dbugprinttok(tok);
         dbugprinttok(name);
		 dbugprinttok(arguments);
		 dbugprinttok(statements);
       };
     return tok;
   }
   
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{  
	int labelnum = labelnumber;
	
	TOKEN i1 = (TOKEN) talloc();
	i1->tokentype = IDENTIFIERTOK;
	i1->symentry = asg->operands->symentry;
	strcpy(i1->stringval, asg->operands->stringval);
	
	TOKEN i2 = (TOKEN) talloc();
	i2->tokentype = IDENTIFIERTOK;
	i2->symentry = asg->operands->symentry;
	strcpy(i2->stringval, asg->operands->stringval);
	
	TOKEN i3 = (TOKEN) talloc();
	i3->tokentype = IDENTIFIERTOK;
	i3->symentry = asg->operands->symentry;
	strcpy(i3->stringval, asg->operands->stringval);
	printf("offs: %i\n", i3->symentry->offset);
	
	// <=
	TOKEN lessthan = (TOKEN) talloc();
	lessthan->tokentype = OPERATOR;
	lessthan->whichval = LE - OPERATOR_BIAS;
	
	// :=
	TOKEN assign = (TOKEN) talloc();
	assign->tokentype = OPERATOR;
	assign->whichval = ASSIGN - OPERATOR_BIAS;
	
	// +
	TOKEN plus = (TOKEN) talloc();
	plus->tokentype = OPERATOR;
	plus->whichval = PLUSOP;
	
	// number token for the number one
	TOKEN one = (TOKEN) talloc();
	one->tokentype = NUMBERTOK;
	one->datatype = INTEGER;
	one->intval = 1;
	
	//i = i + 1 token
	TOKEN temp = (TOKEN) talloc();
	temp = binop(plus, i1, one);
	tok = binop(assign, i2, temp);
	
	
	TOKEN label = makelabel();
	
	TOKEN forstatements = NULL;
	forstatements = cons(makegoto(labelnum), forstatements);
	forstatements = cons(tok , forstatements);
	forstatements = cons(statement, forstatements);
	forstatements = makeprogn((TOKEN) talloc(), forstatements);
	
	TOKEN iftok = makeif(tokb,  binop(lessthan, i3, endexpr), forstatements, NULL);

	iftok = cons(label, iftok);
	iftok = cons(asg, iftok);
	
	
	if (DEBUG & DB_MAKEFOR)
	{ 
		printf("makefor\n");
		dbugprinttok(tok);
		dbugprinttok(asg);
		dbugprinttok(tokb);
		dbugprinttok(endexpr);
		dbugprinttok(tokc);
		dbugprinttok(statement);
	};
	return makeprogn(tokc, iftok);
}	

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr)
{
      int labelnum = labelnumber;
      
      //label -> statements -> if
      
      TOKEN label = makelabel();
      TOKEN repeat = NULL;
      
      repeat = cons(makeif(tok, expr, makeprogn((TOKEN)talloc(), NULL), makegoto(labelnum)), repeat);
      repeat = cons(statements, repeat);
      repeat = cons(label, repeat);
      
      return makeprogn(tokb, repeat);
}

TOKEN makegoto(int label)
{
	TOKEN gototok = (TOKEN) talloc();
	TOKEN numbertok = (TOKEN) talloc();
	
	gototok->tokentype = OPERATOR;
	gototok->whichval = GOTOOP;
	
	numbertok->tokentype = NUMBERTOK;
	numbertok->datatype = INTEGER;
	numbertok->intval = label;
	
	gototok->operands = numbertok;

	return gototok;
}

TOKEN makelabel()
{
	TOKEN labeltok = (TOKEN) talloc();
	TOKEN numbertok = (TOKEN) talloc();
	
	labeltok->tokentype = OPERATOR;
	labeltok->whichval = LABELOP;
	
	numbertok->tokentype = NUMBERTOK;
	numbertok->datatype = INTEGER;
	numbertok->intval = labelnumber;
	
	labeltok->operands = numbertok;
	
	labelnumber++;
	
	return labeltok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
	SYMBOL funsym = searchst(fn->stringval);

	if(funsym != NULL)
	{
		fn->datatype = (funsym->datatype)->basicdt;
	}
	
	if(strcmp(funsym->namestring, "new") != 0)
	{
		tok->tokentype = OPERATOR;
		tok->whichval = FUNCALLOP;
		tok->datatype = fn->datatype;
		tok->operands= fn;
		fn->link = args;
	}
	else
	{
		tok->tokentype = OPERATOR;
		tok->whichval = FUNCALLOP;
		tok->datatype = fn->datatype;
		tok->operands = fn;
		
		TOKEN sizetok = (TOKEN)talloc();
		sizetok->tokentype = NUMBERTOK;
		sizetok->intval = searchst((((searchst(args->stringval)->datatype)->datatype)->datatype)->namestring)->size;
		fn->link = sizetok;
		
		TOKEN assignop = (TOKEN)talloc();
		assignop->tokentype = OPERATOR;
		assignop->whichval = ASSIGNOP;
		args->datatype = POINTER;
		tok = binop(assignop, args, tok);
	}
	
	if(strcmp(funsym->namestring, "writeln") == 0)
	{
		if(args->tokentype == NUMBERTOK)
		{
			switch(args->datatype)
			{
				case INTEGER:
					strcpy(fn->stringval, "writelni");
				break;
				case REAL:
					strcpy(fn->stringval, "writelnf");
				break;
			}
		}
		else if(args->tokentype == IDENTIFIERTOK)
		{
			//switch(searchst(args->stringval)->basicdt)
			switch(args->symentry->basicdt)
			{
				case INTEGER:
					strcpy(fn->stringval, "writelni");
				break;
				case REAL:
					strcpy(fn->stringval, "writelnf");
				break;
			}
		}
	}
	
	else if(strcmp(funsym->namestring, "write") == 0)
	{
		if(args->tokentype == NUMBERTOK)
		{
			switch(args->datatype)
			{
				case INTEGER:
					strcpy(fn->stringval, "writei");
				break;
				case REAL:
					strcpy(fn->stringval, "writef");
				break;
			}
		}
		else if(args->tokentype == IDENTIFIERTOK)
		{
			switch(searchst(args->stringval)->basicdt)
			{
				case INTEGER:
					strcpy(fn->stringval, "writei");
				break;
				case REAL:
					strcpy(fn->stringval, "writef");
				break;
			}
		}
	}

	if (DEBUG & DB_MAKEFUNCALL)
	{ 
		printf("makefuncall\n");
		dbugprinttok(tok);
		dbugprinttok(fn);
		dbugprinttok(args);
	};
	return tok;
}

/* install variables in symbol table */
void instconst(TOKEN idtok, TOKEN consttok)
{  
	SYMBOL sym;
	
	if (DEBUG & DB_INSTALLCONST)
	{ 
		printf("instconst\n");
		dbugprinttok(idtok);
		dbugprinttok(consttok);
	};
	sym = insertsym(idtok->stringval);
	sym->kind = CONSTSYM;
	
	//sym->size = typesym->size;
	sym->basicdt = consttok->datatype;
	
	switch(consttok->datatype)
	{
		case REAL:
			sym->constval.realnum = consttok->realval;
		break;
		case INTEGER:
			sym->constval.intnum = consttok->intval;
		break;
		case STRINGTYPE:
			//int i;
			//for(i = 0; i < 16; i++)
				//sym->constval.stringconst[i] = consttok->stringval[i];
			strcpy(sym->constval.stringconst, consttok->stringval);
		break;
	}
		
	if (DEBUG & DB_INSTALLCONST) 
		printst();
}   

void  instlabel (TOKEN num)
{
	if(labelnumber < 5)
		labels[labelnumber++] = num->intval;
}

void  insttype(TOKEN typename, TOKEN eqtok, TOKEN typetok)
{
	SYMBOL typesym;
	typesym = searchins(typename->stringval);
	
	typesym->kind = TYPESYM;
	typesym->datatype = typetok->symentry;
	typesym->size = (typetok->symentry)->size;
	
}

TOKEN instenum(TOKEN rparen, TOKEN idlist, TOKEN lparen)
{
	//Smash r paren into a const token
	rparen->tokentype = NUMBERTOK;
	rparen->datatype = INTEGER;
	rparen->intval = 0;
	
	while(idlist != NULL)
	{
		instconst(idlist, rparen);
		(rparen->intval)++;
		idlist = idlist->link;
	}

	return makesubrange(lparen, 0, (rparen->intval) - 1);
}

TOKEN makesubrange(TOKEN tok, int low, int high)
{
	SYMBOL subrange = (SYMBOL)symalloc();

	subrange->kind = SUBRANGE;
	subrange->basicdt = INTEGER;
	subrange->lowbound = low;
	subrange->highbound = high;
	subrange->size = basicsizes[INTEGER];
	
	tok->symentry = subrange;
	
	return tok;
}

TOKEN instfields(TOKEN idlist, TOKEN typetok)
{
	SYMBOL typesym = searchins(typetok->stringval);
	SYMBOL sym;
	TOKEN tempTok = idlist;
	int align = alignsize(typesym);
	
	if(typesym->size == 0)
		typesym->size = 8;
		
	while(tempTok != NULL)
	{
		sym = (SYMBOL)symalloc();
		strcpy(sym->namestring, tempTok->stringval);
		sym->size = typesym->size;
		sym->datatype = typesym;
		sym->basicdt = typesym->basicdt;
		tempTok->symentry = sym;
		
		tempTok = tempTok->link;
	}
	
	return idlist;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok)
{
	SYMBOL recsym = (SYMBOL)symalloc();
	TOKEN tempTok = argstok;
	int size = 0;
	
	//Link argstok symentries together
	while(tempTok->link != NULL)
	{
		(tempTok->symentry)->link = (tempTok->link)->symentry;
		while( size % (tempTok->symentry)->size != 0)
			size += 4;
		size += (tempTok->symentry)->size;
		tempTok = tempTok->link;
	}
	//The last token doesn't get added in the above loop
	while( size % (tempTok->symentry)->size != 0)
			size += 4;
	size += (tempTok->symentry)->size;
	
	recsym->kind = RECORDSYM;
	recsym->datatype = argstok->symentry;
	recsym->size = size;
	
	rectok->symentry = recsym;

	return rectok;
}

TOKEN instpoint(TOKEN tok, TOKEN typename)
{
	SYMBOL pointsym = (SYMBOL)symalloc();
	SYMBOL typenamesym = (SYMBOL)symalloc();
	
	strcpy(typenamesym->namestring, typename->stringval);
	
	pointsym->kind = POINTERSYM;
	pointsym->datatype = typenamesym;
	pointsym->basicdt = POINTER;
	pointsym->size = basicsizes[POINTER];

	tok->symentry = pointsym;
	
	return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok)
{
	SYMBOL dotsym = (SYMBOL)symalloc();
	
	dotsym->kind = SUBRANGE;
	dotsym->basicdt = INTEGER;
	dotsym->lowbound = lowtok->intval;
	dotsym->highbound = hightok->intval;
	dotsym->size = basicsizes[INTEGER];
	
	dottok->symentry = dotsym;
	
	return dottok;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok)
{
	SYMBOL arrsym = (SYMBOL)symalloc();
	SYMBOL typesym = searchst(typetok->stringval);
	if(bounds->link != NULL)
	{
		TOKEN bound1 = bounds;
		TOKEN bound2 = bounds->link;
		bounds->link = NULL;
		TOKEN newType = instarray(bound2, typetok);
		typesym = newType->symtype;
	}
	arrsym->kind = ARRAYSYM;
	arrsym->datatype = typesym;
	if(bounds->tokentype != IDENTIFIERTOK)
	{
		arrsym->lowbound = (bounds->symentry)->lowbound;
		arrsym->highbound = (bounds->symentry)->highbound;
	}
	else //Hopefully a temporary fix
	{
		arrsym->lowbound = 0;
		arrsym->highbound = 2;
	}
	
	arrsym->size = (arrsym->highbound - arrsym->lowbound + 1) * typesym->size;
	
	typetok->symtype = arrsym;

	return typetok;
}

TOKEN dopoint(TOKEN var, TOKEN tok)
{
	
	tok->tokentype = OPERATOR;
	tok->whichval = POINTEROP;
	tok->symentry = searchst(var->stringval);
	
	//coming from a nested point - var is an aref
	if(tok->symentry == NULL)
	{
		tok->symtype = searchst(var->symtype->datatype->namestring)->datatype;
	}
	else
	{
		// Locate the record sym field lst out of the depths of hell
		//                  John variable->john's type->pointersym->namesym->nameofrec->record->firstfieldentry
		tok->symtype = searchst((tok->symentry)->datatype->datatype->datatype->namestring)->datatype;//->datatype;
	}
	tok = unaryop(tok, var);
	
	
	return tok;
}

TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok)
{
	tok->tokentype = OPERATOR;
	tok->whichval = AREFOP;
	
	return binop(tok, var, off);
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb)
{
	TOKEN ofs = tokb;
	ofs->tokentype = NUMBERTOK;
	ofs->datatype = INTEGER;
	SYMBOL sym = arr->symtype;
	
	if(arr->whichval == AREFOP)
	{
			//go to the first field entry
			sym = sym->datatype;
			
			//locate the proper location in the record
			while( strcmp(sym->namestring, subs->stringval) != 0)
			{
				while( ofs->intval % sym->size != 0)
					ofs->intval += 4;
				ofs->intval +=sym->size;
				
				sym = sym->link;
			}
			while( ofs->intval % sym->size != 0)
				ofs->intval += 4;
			
			
			arr->operands->link->intval+= ofs->intval;
			
			arr->symtype = sym->datatype->datatype;
			return arr;
	}
	else
	{
		if(sym->kind == RECORDSYM)
		{
			//go to the first field entry
			sym = sym->datatype;
			
			//locate the proper location in the record
			while( strcmp(sym->namestring, subs->stringval) != 0)
			{
				while( ofs->intval % sym->size != 0)
					ofs->intval += 4;
				ofs->intval +=sym->size;
				
				sym = sym->link;
			}
			while( ofs->intval % sym->size != 0)
				ofs->intval += 4;
			
			
			
			tok = makearef(arr, ofs, tok);
			
			//set the aref type to the type structure of the field entry
			tok->symtype = sym->datatype->datatype;
			
			return tok;
		}
		else if(sym->kind == ARRAYSYM)
		{
			//(index - low)* size
			if(subs->tokentype == NUMBERTOK)
			{
				ofs->intval = (subs->intval - sym->lowbound) * (sym->datatype->size);
				tok = makearef(arr, ofs, tok);
			}
			else
			{
				TOKEN plustok = (TOKEN)talloc();
				plustok->tokentype = OPERATOR;
				plustok->whichval = PLUSOP;
				
				TOKEN timestok = (TOKEN)talloc();
				timestok->tokentype = OPERATOR;
				timestok->whichval = TIMESOP;
				
				TOKEN term1 = (TOKEN)talloc();
				term1->tokentype = NUMBERTOK;
				term1->intval = -(sym->lowbound) * (sym->datatype->size);
				
				TOKEN elesize = (TOKEN)talloc();
				elesize->tokentype = NUMBERTOK;
				elesize->intval = (sym->datatype->size);
				
				ofs = binop(plustok, term1, binop(timestok, elesize, subs));
				ofs->tokentype = OPERATOR;
				tok = makearef(arr, ofs, tok);
			}
			
			//set the aref type to the type structure of the array entries
			tok->symtype = sym->datatype->datatype;
			
			return tok;
		}

		return tok;
	}
	
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement)
{
	TOKEN label = makelabel();
	labelnumber--;
	int i;
	for(i = 0; i < 50; i++)
		if(labels[i] == labeltok->intval)
			break;
	
	label->operands->intval = i;
	
	cons(label, statement);
	
	return makeprogn(tok, label);
}

TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement)
{
	TOKEN labeltok = makelabel();
	TOKEN whiletok = NULL;
	TOKEN iftok = makeif(tok, expr, makeprogn(tokb, cons(statement, makegoto(labelnumber - 1))), NULL);
	whiletok = cons(iftok, whiletok);
	whiletok = cons(labeltok, whiletok);

	return makeprogn((TOKEN)talloc(), whiletok);
	
}
   
TOKEN findtype(TOKEN tok)
{
	tok->symtype = searchst(tok->stringval);
	return tok;
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok)
{
	int i = 0;
	
	for(i = 0; i < 50; i++)
		if(labels[i] = labeltok->intval)
			break;
	
	return makegoto(i);
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(s)
  char * s;
  { 
  fputs(s,stderr); putc('\n',stderr);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
	gencode(parseresult, blockoffs[blocknumber], labelnumber);
  }

