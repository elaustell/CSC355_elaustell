/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_INT = 258,
     T_DOUBLE = 259,
     T_STRING = 260,
     T_TRIANGLE = 261,
     T_PIXMAP = 262,
     T_CIRCLE = 263,
     T_RECTANGLE = 264,
     T_TEXTBOX = 265,
     T_FORWARD = 266,
     T_INITIALIZATION = 267,
     T_TERMINATION = 268,
     T_TRUE = 269,
     T_FALSE = 270,
     T_ON = 271,
     T_SPACE = 272,
     T_LEFTARROW = 273,
     T_RIGHTARROW = 274,
     T_UPARROW = 275,
     T_DOWNARROW = 276,
     T_LEFTMOUSE_DOWN = 277,
     T_MIDDLEMOUSE_DOWN = 278,
     T_RIGHTMOUSE_DOWN = 279,
     T_LEFTMOUSE_UP = 280,
     T_MIDDLEMOUSE_UP = 281,
     T_RIGHTMOUSE_UP = 282,
     T_MOUSE_MOVE = 283,
     T_MOUSE_DRAG = 284,
     T_F1 = 285,
     T_AKEY = 286,
     T_SKEY = 287,
     T_DKEY = 288,
     T_FKEY = 289,
     T_HKEY = 290,
     T_JKEY = 291,
     T_KKEY = 292,
     T_LKEY = 293,
     T_WKEY = 294,
     T_ZKEY = 295,
     T_TOUCHES = 296,
     T_NEAR = 297,
     T_ANIMATION = 298,
     T_IF = 299,
     T_FOR = 300,
     T_ELSE = 301,
     T_PRINT = 302,
     T_EXIT = 303,
     T_LPAREN = 304,
     T_RPAREN = 305,
     T_LBRACE = 306,
     T_RBRACE = 307,
     T_LBRACKET = 308,
     T_RBRACKET = 309,
     T_SEMIC = 310,
     T_COMMA = 311,
     T_PERIOD = 312,
     T_ASSIGN = 313,
     T_PLUS_ASSIGN = 314,
     T_MINUS_ASSIGN = 315,
     T_PLUS_PLUS = 316,
     T_MINUS_MINUS = 317,
     T_MULTIPLY = 318,
     T_DIVIDE = 319,
     T_MOD = 320,
     T_PLUS = 321,
     T_MINUS = 322,
     T_SIN = 323,
     T_COS = 324,
     T_TAN = 325,
     T_ASIN = 326,
     T_ACOS = 327,
     T_ATAN = 328,
     T_SQRT = 329,
     T_FLOOR = 330,
     T_ABS = 331,
     T_RANDOM = 332,
     T_LESS = 333,
     T_GREATER = 334,
     T_LESS_EQUAL = 335,
     T_GREATER_EQUAL = 336,
     T_EQUAL = 337,
     T_NOT_EQUAL = 338,
     T_AND = 339,
     T_OR = 340,
     T_NOT = 341,
     T_ID = 342,
     T_INT_CONSTANT = 343,
     T_DOUBLE_CONSTANT = 344,
     T_STRING_CONSTANT = 345,
     T_ERROR = 346,
     IF_NO_ELSE = 347,
     UNARY_OPS = 348
   };
#endif
/* Tokens.  */
#define T_INT 258
#define T_DOUBLE 259
#define T_STRING 260
#define T_TRIANGLE 261
#define T_PIXMAP 262
#define T_CIRCLE 263
#define T_RECTANGLE 264
#define T_TEXTBOX 265
#define T_FORWARD 266
#define T_INITIALIZATION 267
#define T_TERMINATION 268
#define T_TRUE 269
#define T_FALSE 270
#define T_ON 271
#define T_SPACE 272
#define T_LEFTARROW 273
#define T_RIGHTARROW 274
#define T_UPARROW 275
#define T_DOWNARROW 276
#define T_LEFTMOUSE_DOWN 277
#define T_MIDDLEMOUSE_DOWN 278
#define T_RIGHTMOUSE_DOWN 279
#define T_LEFTMOUSE_UP 280
#define T_MIDDLEMOUSE_UP 281
#define T_RIGHTMOUSE_UP 282
#define T_MOUSE_MOVE 283
#define T_MOUSE_DRAG 284
#define T_F1 285
#define T_AKEY 286
#define T_SKEY 287
#define T_DKEY 288
#define T_FKEY 289
#define T_HKEY 290
#define T_JKEY 291
#define T_KKEY 292
#define T_LKEY 293
#define T_WKEY 294
#define T_ZKEY 295
#define T_TOUCHES 296
#define T_NEAR 297
#define T_ANIMATION 298
#define T_IF 299
#define T_FOR 300
#define T_ELSE 301
#define T_PRINT 302
#define T_EXIT 303
#define T_LPAREN 304
#define T_RPAREN 305
#define T_LBRACE 306
#define T_RBRACE 307
#define T_LBRACKET 308
#define T_RBRACKET 309
#define T_SEMIC 310
#define T_COMMA 311
#define T_PERIOD 312
#define T_ASSIGN 313
#define T_PLUS_ASSIGN 314
#define T_MINUS_ASSIGN 315
#define T_PLUS_PLUS 316
#define T_MINUS_MINUS 317
#define T_MULTIPLY 318
#define T_DIVIDE 319
#define T_MOD 320
#define T_PLUS 321
#define T_MINUS 322
#define T_SIN 323
#define T_COS 324
#define T_TAN 325
#define T_ASIN 326
#define T_ACOS 327
#define T_ATAN 328
#define T_SQRT 329
#define T_FLOOR 330
#define T_ABS 331
#define T_RANDOM 332
#define T_LESS 333
#define T_GREATER 334
#define T_LESS_EQUAL 335
#define T_GREATER_EQUAL 336
#define T_EQUAL 337
#define T_NOT_EQUAL 338
#define T_AND 339
#define T_OR 340
#define T_NOT 341
#define T_ID 342
#define T_INT_CONSTANT 343
#define T_DOUBLE_CONSTANT 344
#define T_STRING_CONSTANT 345
#define T_ERROR 346
#define IF_NO_ELSE 347
#define UNARY_OPS 348




/* Copy the first part of user declarations.  */
#line 1 "gpl.y"


// there is a compatibility problem with my current cygwin environment
// this appears to fix the problem
#undef __GNUC_MINOR__

#include "error.h"
#include "gpl_assert.h"
#include "symbol_table.h"
#include "symbol.h"
#include "expression.h"
#include "variable.h"
#include <iostream>
#include <sstream>
#include <cmath> // for floor()
#include <stack>
#include "event_manager.h"
#include "statement_block.h"
#include "animation_block.h"
#include "game_object.h"
#include "triangle.h"
#include "pixmap.h"
#include "circle.h"
#include "rectangle.h"
#include "textbox.h"
#include "window.h"
#include "if_statement.h"
#include "for_statement.h"
#include "print_statement.h"
#include "exit_statement.h"
#include "assign_statement.h"
using namespace std;

extern int yylex();
extern int yyerror(const char *);
extern int line_count;  // from gpl.l, used for statement blocks

// Global variable to make the construction of object much less complex
// Only one object can ever be under construction at one time
Game_object *cur_object_under_construction = 0;
string cur_object_under_construction_name;
int undeclared = 0;
Symbol_table *table = Symbol_table::instance();
std::stack<Statement_block*> statement_block_stack;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 48 "gpl.y"
{
  int              union_int;
  double           union_double;
  std::string      *union_string;  // MUST be a pointer to a string ARG!
  Gpl_type         union_type;
  Expression       *union_expression;
  Variable         *union_variable;
  Operator_type    union_op;
  Game_object      *union_object;
  Window::Keystroke union_keystroke;
  Statement_block *union_stmtblock;
}
/* Line 193 of yacc.c.  */
#line 342 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 355 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   470

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    14,    17,    20,    24,
      30,    32,    34,    36,    39,    41,    42,    49,    55,    57,
      59,    61,    63,    65,    67,    69,    73,    75,    79,    87,
      90,    92,    94,    96,    98,   100,   103,   106,   116,   119,
     123,   125,   127,   129,   131,   133,   135,   137,   139,   141,
     143,   145,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   165,   167,   169,   171,   175,   177,   183,   184,   185,
     188,   190,   191,   194,   196,   199,   202,   204,   210,   218,
     232,   237,   242,   244,   246,   250,   254,   258,   261,   264,
     266,   271,   275,   282,   284,   288,   292,   296,   300,   304,
     308,   312,   316,   320,   324,   328,   332,   336,   339,   342,
     347,   351,   355,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,   385,   387,   389,   391
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      95,     0,    -1,    96,   108,    -1,    96,    97,    -1,   132,
      -1,    98,    55,    -1,   101,    55,    -1,   107,    55,    -1,
      99,    87,   100,    -1,    99,    87,    53,   129,    54,    -1,
       3,    -1,     4,    -1,     5,    -1,    58,   129,    -1,   132,
      -1,    -1,   103,    87,   102,    49,   104,    50,    -1,   103,
      87,    53,   129,    54,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,   105,    -1,   132,    -1,   105,
      56,   106,    -1,   106,    -1,    87,    58,   129,    -1,    11,
      43,    87,    49,   103,    87,    50,    -1,   108,   109,    -1,
     132,    -1,   110,    -1,   111,    -1,   112,    -1,   114,    -1,
      12,   117,    -1,    13,   117,    -1,    43,    87,    49,   113,
      50,    51,   120,    52,   119,    -1,   103,    87,    -1,    16,
     115,   117,    -1,    17,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,    35,
      -1,    36,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,   118,   121,   119,    -1,   117,    -1,    51,   118,   120,
      52,   119,    -1,    -1,    -1,   120,   121,    -1,   132,    -1,
      -1,   127,    55,    -1,   122,    -1,   124,    55,    -1,   125,
      55,    -1,   123,    -1,    44,    49,   129,    50,   116,    -1,
      44,    49,   129,    50,   116,    46,   116,    -1,    45,    49,
     118,   126,   119,    55,   129,    55,   118,   126,   119,    50,
     117,    -1,    47,    49,   129,    50,    -1,    48,    49,   129,
      50,    -1,   127,    -1,   132,    -1,   128,    58,   129,    -1,
     128,    59,   129,    -1,   128,    60,   129,    -1,   128,    61,
      -1,   128,    62,    -1,    87,    -1,    87,    53,   129,    54,
      -1,    87,    57,    87,    -1,    87,    53,   129,    54,    57,
      87,    -1,   130,    -1,   129,    85,   129,    -1,   129,    84,
     129,    -1,   129,    80,   129,    -1,   129,    81,   129,    -1,
     129,    78,   129,    -1,   129,    79,   129,    -1,   129,    82,
     129,    -1,   129,    83,   129,    -1,   129,    66,   129,    -1,
     129,    67,   129,    -1,   129,    63,   129,    -1,   129,    64,
     129,    -1,   129,    65,   129,    -1,    67,   129,    -1,    86,
     129,    -1,   131,    49,   129,    50,    -1,   129,    42,   129,
      -1,   129,    41,   129,    -1,    49,   129,    50,    -1,   128,
      -1,    88,    -1,    14,    -1,    15,    -1,    89,    -1,    90,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    76,    -1,    75,    -1,    77,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   194,   194,   199,   200,   205,   206,   207,   212,   277,
     314,   315,   316,   321,   322,   327,   327,   347,   398,   399,
     400,   401,   402,   407,   408,   413,   414,   419,   474,   498,
     499,   504,   505,   506,   507,   512,   517,   524,   533,   538,
     546,   550,   554,   558,   562,   566,   570,   574,   578,   582,
     586,   590,   594,   598,   602,   606,   610,   614,   618,   622,
     626,   630,   634,   638,   645,   649,   656,   663,   671,   678,
     679,   682,   683,   684,   685,   686,   687,   691,   701,   709,
     721,   738,   745,   746,   750,   825,   857,   887,   902,   921,
     935,   968,  1021,  1098,  1102,  1114,  1128,  1139,  1150,  1161,
    1172,  1183,  1184,  1195,  1206,  1217,  1228,  1239,  1247,  1255,
    1264,  1265,  1270,  1271,  1277,  1278,  1279,  1280,  1281,  1286,
    1287,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1299
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"int\"", "\"double\"", "\"string\"",
  "\"triangle\"", "\"pixmap\"", "\"circle\"", "\"rectangle\"",
  "\"textbox\"", "\"forward\"", "\"initialization\"", "\"termination\"",
  "\"true\"", "\"false\"", "\"on\"", "\"space\"", "\"leftarrow\"",
  "\"rightarrow\"", "\"uparrow\"", "\"downarrow\"", "\"leftmouse_down\"",
  "\"middlemouse_down\"", "\"rightmouse_down\"", "\"leftmouse_up\"",
  "\"middlemouse_up\"", "\"rightmouse_up\"", "\"mouse_move\"",
  "\"mouse_drag\"", "\"f1\"", "\"akey\"", "\"skey\"", "\"dkey\"",
  "\"fkey\"", "\"hkey\"", "\"jkey\"", "\"kkey\"", "\"lkey\"", "\"wkey\"",
  "\"zkey\"", "\"touches\"", "\"near\"", "\"animation\"", "\"if\"",
  "\"for\"", "\"else\"", "\"print\"", "\"exit\"", "\"(\"", "\")\"",
  "\"{\"", "\"}\"", "\"[\"", "\"]\"", "\";\"", "\",\"", "\".\"", "\"=\"",
  "\"+=\"", "\"-=\"", "\"++\"", "\"--\"", "\"*\"", "\"/\"", "\"%\"",
  "\"+\"", "\"-\"", "\"sin\"", "\"cos\"", "\"tan\"", "\"asin\"",
  "\"acos\"", "\"atan\"", "\"sqrt\"", "\"floor\"", "\"abs\"", "\"random\"",
  "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\"&&\"",
  "\"||\"", "\"!\"", "\"identifier\"", "\"int constant\"",
  "\"double constant\"", "\"string constant\"", "\"error\"", "IF_NO_ELSE",
  "UNARY_OPS", "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "simple_type", "optional_initializer",
  "object_declaration", "@1", "object_type", "parameter_list_or_empty",
  "parameter_list", "parameter", "forward_declaration", "block_list",
  "block", "initialization_block", "termination_block", "animation_block",
  "check_animation_parameter", "on_block", "keystroke", "if_block",
  "statement_block", "statement_block_creator", "end_of_statement_block",
  "statement_list", "statement", "if_statement", "for_statement",
  "print_statement", "exit_statement", "assign_statement_or_empty",
  "assign_statement", "variable", "expression", "primary_expression",
  "math_operator", "empty", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    97,    97,    97,    98,    98,
      99,    99,    99,   100,   100,   102,   101,   101,   103,   103,
     103,   103,   103,   104,   104,   105,   105,   106,   107,   108,
     108,   109,   109,   109,   109,   110,   111,   112,   113,   114,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   118,   119,   120,
     120,   121,   121,   121,   121,   121,   121,   122,   122,   123,
     124,   125,   126,   126,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   132
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     3,     5,
       1,     1,     1,     2,     1,     0,     6,     5,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     7,     2,
       1,     1,     1,     1,     1,     2,     2,     9,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     5,     0,     0,     2,
       1,     0,     2,     1,     2,     2,     1,     5,     7,    13,
       4,     4,     1,     1,     3,     3,     3,     2,     2,     1,
       4,     3,     6,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     4,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     129,     0,   129,     4,     1,    10,    11,    12,    18,    19,
      20,    21,    22,     0,     3,     0,     0,     0,     0,     0,
       2,    30,     0,     5,   129,     6,    15,     7,     0,     0,
       0,     0,    29,    31,    32,    33,    34,     0,     0,     0,
       8,    14,     0,     0,    67,    35,    36,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,   115,   116,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   127,   126,   128,     0,    89,
     114,   117,   118,   113,     0,    93,     0,    13,     0,   129,
     129,    39,     0,     0,     0,   107,   108,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,    23,
      26,    24,     0,    70,     0,     0,     0,   112,     0,    91,
     111,   110,   104,   105,   106,   102,   103,    98,    99,    96,
      97,   100,   101,    95,    94,     0,     0,    16,     0,     0,
       0,     0,     0,    68,    69,    73,    76,     0,     0,     0,
       0,    38,     0,    28,    90,   109,    27,    25,     0,    67,
       0,     0,    66,    74,    75,    72,     0,     0,     0,    87,
      88,   129,     0,     0,   129,     0,     0,    84,    85,    86,
       0,    92,    67,    68,    82,    83,    80,    81,    68,    77,
      65,    71,     0,    37,    67,    68,     0,    78,    64,     0,
      67,   129,    68,     0,     0,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    40,    17,    43,    18,
     128,   129,   130,    19,    20,    32,    33,    34,    35,   135,
      36,    71,   209,   210,   211,   182,   132,   164,   165,   166,
     167,   168,   203,   169,    93,    94,    95,    96,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -189
static const yytype_int16 yypact[] =
{
    -189,    11,   152,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,   -23,  -189,   -41,   -59,   -26,   -50,   -10,
      28,  -189,   -48,  -189,   -31,  -189,   -32,  -189,     5,     5,
     408,   -30,  -189,  -189,  -189,  -189,  -189,     4,    99,    99,
    -189,  -189,    99,    12,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,     5,    21,    96,  -189,  -189,    99,    99,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,    99,     2,
    -189,  -189,  -189,  -189,   -16,  -189,    23,   339,   149,   -27,
    -189,  -189,    96,    10,   159,  -189,  -189,    99,    13,    99,
      99,  -189,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,  -189,    19,    57,    54,
    -189,  -189,   -35,  -189,    24,    62,    66,  -189,   194,  -189,
     329,   329,  -189,  -189,  -189,    30,    30,    65,    65,    65,
      65,   239,   239,    60,   386,   204,    99,  -189,   -27,    68,
      69,    71,    72,  -189,  -189,  -189,  -189,    78,    79,    80,
     146,  -189,    86,  -189,    88,  -189,   339,  -189,    99,  -189,
      99,    99,  -189,  -189,  -189,  -189,    99,    99,    99,  -189,
    -189,  -189,    63,   249,    64,   259,   304,   339,   339,   339,
     -29,  -189,     5,  -189,  -189,  -189,  -189,  -189,  -189,   103,
    -189,   -13,   109,  -189,     5,  -189,    99,  -189,  -189,   294,
    -189,    64,  -189,   115,     5,  -189
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,   -66,
    -189,  -189,    20,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,   -33,   -25,   -43,  -107,   -12,   -28,  -189,  -189,
    -189,  -189,   -37,  -188,  -102,   -34,  -189,  -189,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       3,   100,    21,    45,    46,    97,   204,   103,    98,   159,
     160,     4,   161,   162,    23,   159,   160,   163,   161,   162,
      22,    42,    38,   208,    41,   109,   110,    39,    24,    25,
     170,   159,   160,   204,   161,   162,   134,    26,   111,    37,
      28,    29,   104,   105,    30,    27,   101,   112,   113,   114,
     115,   116,    89,    73,   106,   107,    44,    72,    89,   108,
     127,    99,   117,   118,   119,   120,   121,   122,   123,   124,
     102,    31,   125,   138,    89,   140,   141,   156,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   170,   112,   113,   114,   212,   136,   170,   131,
     139,   213,     8,     9,    10,    11,    12,   157,   218,   170,
     158,   171,   172,    74,    75,   223,   173,   178,   179,   170,
     180,   181,   176,   112,   113,   114,   115,   116,   112,   113,
     114,   115,   116,   183,   184,   185,   194,   191,   117,   118,
     119,   120,   121,   122,   193,   192,   195,   196,    76,   214,
     201,    89,   197,   198,   199,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   216,   224,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,   221,   177,   200,
       0,   217,   219,   215,   222,    88,    89,    90,    91,    92,
     109,   110,     0,     0,   205,     0,     0,     0,     0,   225,
     109,   110,     0,   126,   186,   187,   188,   189,   190,   137,
       0,     0,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   205,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   109,   110,   117,   118,   119,
     120,   121,   122,   123,   124,   109,   110,     0,   174,     0,
       0,     0,     0,     0,   175,     0,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
     109,   110,     0,     0,     0,     0,     0,     0,     0,   202,
     109,   110,   112,   113,   114,   115,   116,     0,     0,   206,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   109,   110,   117,   118,   119,
     120,   121,   122,   123,   124,   109,   110,     0,     0,   220,
       0,     0,     0,     0,   207,     0,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     109,   110,   117,   118,   119,   120,   121,   122,   123,   124,
       0,     0,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123
};

static const yytype_int16 yycheck[] =
{
       0,    44,     2,    28,    29,    39,   194,    73,    42,    44,
      45,     0,    47,    48,    55,    44,    45,    52,    47,    48,
      43,    53,    53,    52,    24,    41,    42,    58,    87,    55,
     132,    44,    45,   221,    47,    48,   102,    87,    54,    87,
      12,    13,    76,    77,    16,    55,    71,    63,    64,    65,
      66,    67,    87,    49,    88,    53,    51,    87,    87,    57,
      87,    49,    78,    79,    80,    81,    82,    83,    84,    85,
      49,    43,    49,   107,    87,   109,   110,    58,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   194,    63,    64,    65,   203,    87,   200,    99,
      87,   208,     6,     7,     8,     9,    10,    50,   215,   211,
      56,    87,    50,    14,    15,   222,    50,    49,    49,   221,
      49,    49,   156,    63,    64,    65,    66,    67,    63,    64,
      65,    66,    67,    55,    55,    55,   179,    51,    78,    79,
      80,    81,    82,    83,   178,    57,   180,   181,    49,    46,
      87,    87,   186,   187,   188,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    55,    50,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,   220,   158,   191,
      -1,   214,   216,   211,   221,    86,    87,    88,    89,    90,
      41,    42,    -1,    -1,   194,    -1,    -1,    -1,    -1,   224,
      41,    42,    -1,    54,    58,    59,    60,    61,    62,    50,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,   221,    63,    64,    65,    66,    67,    78,    79,    80,
      81,    82,    83,    84,    85,    41,    42,    78,    79,    80,
      81,    82,    83,    84,    85,    41,    42,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      41,    42,    63,    64,    65,    66,    67,    -1,    -1,    50,
      -1,    -1,    63,    64,    65,    66,    67,    78,    79,    80,
      81,    -1,    63,    64,    65,    66,    67,    78,    79,    80,
      81,    82,    83,    84,    85,    41,    42,    78,    79,    80,
      81,    82,    83,    84,    85,    41,    42,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    78,    79,    80,    81,    82,    83,    84,    85,
      41,    42,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    78,    79,    80,
      81,    82,    83,    84,    85,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,    96,   132,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    97,    98,    99,   101,   103,   107,
     108,   132,    43,    55,    87,    55,    87,    55,    12,    13,
      16,    43,   109,   110,   111,   112,   114,    87,    53,    58,
     100,   132,    53,   102,    51,   117,   117,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,   115,    87,    49,    14,    15,    49,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    86,    87,
      88,    89,    90,   128,   129,   130,   131,   129,   129,    49,
     118,   117,    49,   103,   129,   129,   129,    53,    57,    41,
      42,    54,    63,    64,    65,    66,    67,    78,    79,    80,
      81,    82,    83,    84,    85,    49,    54,    87,   104,   105,
     106,   132,   120,   132,   103,   113,    87,    50,   129,    87,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,    58,    50,    56,    44,
      45,    47,    48,    52,   121,   122,   123,   124,   125,   127,
     128,    87,    50,    50,    54,    50,   129,   106,    49,    49,
      49,    49,   119,    55,    55,    55,    58,    59,    60,    61,
      62,    51,    57,   129,   118,   129,   129,   129,   129,   129,
     120,    87,    50,   126,   127,   132,    50,    50,    52,   116,
     117,   118,   119,   119,    46,   121,    55,   116,   119,   129,
      55,   118,   126,   119,    50,   117
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 8:
#line 212 "gpl.y"
    {
        string *name = (yyvsp[(2) - (3)].union_string);
        if ((yyvsp[(1) - (3)].union_type) == INT){
            int initial_value = 0;
            if ((yyvsp[(3) - (3)].union_expression) != NULL)
            {
                if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != INT_ARRAY) {
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,gpl_type_to_string((yyvsp[(3) - (3)].union_expression)->get_type()),*name,"int");
                }
                else {
                    if ((yyvsp[(3) - (3)].union_expression)->get_type() == INT) {
                        initial_value = (yyvsp[(3) - (3)].union_expression)->eval_int();
                    }
                }
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        } else if ((yyvsp[(1) - (3)].union_type) == DOUBLE){
            double initial_value = 0.0;
            if ((yyvsp[(3) - (3)].union_expression) != NULL)
            {
                if (((yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE) && ((yyvsp[(3) - (3)].union_expression)->get_type() != INT)) {
                    if ((yyvsp[(3) - (3)].union_expression)->get_type() == INT_ARRAY || (yyvsp[(3) - (3)].union_expression)->get_type() == DOUBLE_ARRAY){
                    } else{
                        Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE, "string", *name, "double");
                    }
                }
                else initial_value = (yyvsp[(3) - (3)].union_expression)->eval_double();
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        } else {
            string initial_value = "";
            if ((yyvsp[(3) - (3)].union_expression) != NULL)
            {
                if ((yyvsp[(3) - (3)].union_expression)->get_type() == INT || (yyvsp[(3) - (3)].union_expression)->get_type() == DOUBLE || (yyvsp[(3) - (3)].union_expression)->get_type() == STRING) {
                    initial_value = (yyvsp[(3) - (3)].union_expression)->eval_string();
                } else if ((yyvsp[(3) - (3)].union_expression)->get_type() == INT_ARRAY) {
                    Variable *v = (yyvsp[(3) - (3)].union_expression)->eval_variable();
                    int val = v->get_int_value();
                    initial_value = to_string(val);
                } else if ((yyvsp[(3) - (3)].union_expression)->get_type() == DOUBLE_ARRAY) {
                    Variable *v = (yyvsp[(3) - (3)].union_expression)->eval_variable();
                    double val = v->get_double_value();
                    initial_value = to_string(val);
                } else if ((yyvsp[(3) - (3)].union_expression)->get_type() == STRING_ARRAY) {
                    Variable *v = (yyvsp[(3) - (3)].union_expression)->eval_variable();
                    initial_value = v->get_string_value();
                } else {
                    Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,gpl_type_to_string((yyvsp[(3) - (3)].union_expression)->get_type()), *name, "string");
                }
            }
            Symbol *s = new Symbol(*name, initial_value);
            bool valid = table->insert(s);
            if (!valid) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
            }
        }
    }
    break;

  case 9:
#line 277 "gpl.y"
    {
        string *name = (yyvsp[(2) - (5)].union_string);
        if ((yyvsp[(4) - (5)].union_expression) == NULL) {

        } else if ((yyvsp[(4) - (5)].union_expression)->get_type() != INT) {
            Error::error(Error::ARRAY_SIZE_MUST_BE_AN_INTEGER,gpl_type_to_string((yyvsp[(4) - (5)].union_expression)->get_type()),*name);
        } else {
            int size = (yyvsp[(4) - (5)].union_expression)->eval_int();
            if (size <= 0){
                Error::error(Error::INVALID_ARRAY_SIZE, *name, to_string(size));
            } else {
                if ((yyvsp[(1) - (5)].union_type) == INT){
                    Symbol *s = new Symbol(*name, INT_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ((yyvsp[(1) - (5)].union_type) == DOUBLE){
                    Symbol *s = new Symbol(*name, DOUBLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else {
                    Symbol *s = new Symbol(*name, STRING_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                }
            }
        }
    }
    break;

  case 10:
#line 314 "gpl.y"
    {(yyval.union_type) = INT;}
    break;

  case 11:
#line 315 "gpl.y"
    {(yyval.union_type) = DOUBLE;}
    break;

  case 12:
#line 316 "gpl.y"
    {(yyval.union_type) = STRING;}
    break;

  case 13:
#line 321 "gpl.y"
    {(yyval.union_expression) = (yyvsp[(2) - (2)].union_expression);}
    break;

  case 14:
#line 322 "gpl.y"
    {(yyval.union_expression) = NULL;}
    break;

  case 15:
#line 327 "gpl.y"
    {
        // create a new object and it's symbol
        // (Symbol() creates the new object);
        Symbol *symbol = new Symbol(*(yyvsp[(2) - (2)].union_string), (yyvsp[(1) - (2)].union_type));

        if (!table->insert(symbol))
        {
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *(yyvsp[(2) - (2)].union_string));
        }
        // assign to global variable so the parameters can be inserted into
        // this object when each parameter is parsed
        cur_object_under_construction = symbol->get_game_object_value();
        cur_object_under_construction_name = symbol->get_name();
  
    }
    break;

  case 16:
#line 343 "gpl.y"
    {
        cur_object_under_construction = NULL;
        delete (yyvsp[(2) - (6)].union_string); // Scanner allocates memory for each T_ID string
    }
    break;

  case 17:
#line 347 "gpl.y"
    {
        string *name = (yyvsp[(2) - (5)].union_string);
        if ((yyvsp[(4) - (5)].union_expression) == NULL) {

        } else if ((yyvsp[(4) - (5)].union_expression)->get_type() != INT) {
            Error::error(Error::ARRAY_SIZE_MUST_BE_AN_INTEGER,gpl_type_to_string((yyvsp[(4) - (5)].union_expression)->get_type()),*name);
        } else {
            int size = (yyvsp[(4) - (5)].union_expression)->eval_int();
            if (size <= 0){
                Error::error(Error::INVALID_ARRAY_SIZE, *name, to_string(size));
            } else {
                if ((yyvsp[(1) - (5)].union_type) == TRIANGLE){
                    Symbol *s = new Symbol(*name, TRIANGLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ((yyvsp[(1) - (5)].union_type) == CIRCLE){
                    Symbol *s = new Symbol(*name, CIRCLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ((yyvsp[(1) - (5)].union_type) == RECTANGLE){
                    Symbol *s = new Symbol(*name, RECTANGLE_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ((yyvsp[(1) - (5)].union_type) == TEXTBOX){
                    Symbol *s = new Symbol(*name, TEXTBOX_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else if ((yyvsp[(1) - (5)].union_type) == PIXMAP){
                    Symbol *s = new Symbol(*name, PIXMAP_ARRAY, size);
                    bool valid = table->insert(s);
                    if (!valid) {
                        Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *name);
                    }
                } else {
                    //invalid type error?
                }
            }
        }
    }
    break;

  case 18:
#line 398 "gpl.y"
    {(yyval.union_type) = TRIANGLE;}
    break;

  case 19:
#line 399 "gpl.y"
    {(yyval.union_type) = PIXMAP;}
    break;

  case 20:
#line 400 "gpl.y"
    {(yyval.union_type) = CIRCLE;}
    break;

  case 21:
#line 401 "gpl.y"
    {(yyval.union_type) = RECTANGLE;}
    break;

  case 22:
#line 402 "gpl.y"
    {(yyval.union_type) = TEXTBOX;}
    break;

  case 27:
#line 419 "gpl.y"
    {
        string *name = (yyvsp[(1) - (3)].union_string);
        if (!cur_object_under_construction->has_member_variable(*name)) {
            Error::error(Error::UNKNOWN_CONSTRUCTOR_PARAMETER,gpl_type_to_string(cur_object_under_construction->get_type()),*name);
        } else {
            Gpl_type *param_type = new Gpl_type(NO_TYPE);
            cur_object_under_construction->get_member_variable_type(*name,*param_type);

            Gpl_type exp_type = (yyvsp[(3) - (3)].union_expression)->get_type();

            if (*param_type == INT) {
                if (exp_type != INT) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE,cur_object_under_construction_name, *(yyvsp[(1) - (3)].union_string));
                } else {
                    int val = (yyvsp[(3) - (3)].union_expression)->eval_int();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (*param_type == DOUBLE) {
                if (exp_type != INT && exp_type != DOUBLE) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *(yyvsp[(1) - (3)].union_string));
                } else {
                    double val = (yyvsp[(3) - (3)].union_expression)->eval_double();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (*param_type == STRING) {
                if (exp_type != INT && exp_type != DOUBLE && exp_type != STRING) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *(yyvsp[(1) - (3)].union_string));
                } else {
                    string val = (yyvsp[(3) - (3)].union_expression)->eval_string();
                    Status status = cur_object_under_construction->set_member_variable(*name,val);
                }
            } else if (exp_type == ANIMATION_BLOCK) {
                if (*param_type != exp_type) {
                    Error::error(Error::INCORRECT_CONSTRUCTOR_PARAMETER_TYPE, cur_object_under_construction_name, *(yyvsp[(1) - (3)].union_string));
                } else {
                    string var_name = (yyvsp[(3) - (3)].union_expression)->eval_variable()->get_name();
                    Symbol *var_sym = table->lookup(var_name);
                    Animation_block *ablock = var_sym->get_animation_block_value();
                    Symbol *param_symbol = ablock->get_parameter_symbol();
                    if (param_symbol == NULL) {} 
                    else if (param_symbol->get_type() != cur_object_under_construction->get_type()) {
                        Error::error(Error::TYPE_MISMATCH_BETWEEN_ANIMATION_BLOCK_AND_OBJECT,cur_object_under_construction_name,ablock->name());
                    } else {
                        Symbol *curr = table->lookup(cur_object_under_construction_name);
                        ablock->initialize(curr,var_name);
                        Status status = cur_object_under_construction->set_member_variable(*name,ablock);
                    }
                }
            } else {}
        } 
    }
    break;

  case 28:
#line 475 "gpl.y"
    {
        if (table->lookup(*(yyvsp[(6) - (7)].union_string)) != NULL) {
            Error::error(Error::ANIMATION_PARAMETER_NAME_NOT_UNIQUE,*(yyvsp[(6) - (7)].union_string));
        }

            // put animation block and game object into symbol table
            Symbol *s_object = new Symbol(*(yyvsp[(6) - (7)].union_string), (yyvsp[(5) - (7)].union_type));
            Symbol *s_ablock = new Symbol(*(yyvsp[(3) - (7)].union_string),ANIMATION_BLOCK);

            Animation_block *a = s_ablock->get_animation_block_value();
            a->initialize(s_object, *(yyvsp[(3) - (7)].union_string));

            table->insert(s_object);
            bool flag = table->insert(s_ablock);
            if (!flag) {
                Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE, *(yyvsp[(3) - (7)].union_string));
            }
        
    }
    break;

  case 36:
#line 518 "gpl.y"
    {
      // COMPLETE ME
  }
    break;

  case 39:
#line 539 "gpl.y"
    {
      Window::Keystroke k = (yyvsp[(2) - (3)].union_keystroke);
      
  }
    break;

  case 40:
#line 547 "gpl.y"
    {
      (yyval.union_keystroke) = Window::SPACE;
    }
    break;

  case 41:
#line 551 "gpl.y"
    {
      (yyval.union_keystroke) = Window::LEFTARROW;
    }
    break;

  case 42:
#line 555 "gpl.y"
    {
      (yyval.union_keystroke) = Window::RIGHTARROW;
    }
    break;

  case 43:
#line 559 "gpl.y"
    {
      (yyval.union_keystroke) = Window::UPARROW;
    }
    break;

  case 44:
#line 563 "gpl.y"
    {
      (yyval.union_keystroke) = Window::DOWNARROW;
    }
    break;

  case 45:
#line 567 "gpl.y"
    {
      (yyval.union_keystroke) = Window::LEFTMOUSE_DOWN;
    }
    break;

  case 46:
#line 571 "gpl.y"
    {
      (yyval.union_keystroke) = Window::MIDDLEMOUSE_DOWN;
    }
    break;

  case 47:
#line 575 "gpl.y"
    {
      (yyval.union_keystroke) = Window::RIGHTMOUSE_DOWN;
    }
    break;

  case 48:
#line 579 "gpl.y"
    {
      (yyval.union_keystroke) = Window::LEFTMOUSE_UP;
    }
    break;

  case 49:
#line 583 "gpl.y"
    {
      (yyval.union_keystroke) = Window::MIDDLEMOUSE_UP;
    }
    break;

  case 50:
#line 587 "gpl.y"
    {
      (yyval.union_keystroke) = Window::RIGHTMOUSE_UP;
    }
    break;

  case 51:
#line 591 "gpl.y"
    {
      (yyval.union_keystroke) = Window::MOUSE_MOVE;
    }
    break;

  case 52:
#line 595 "gpl.y"
    {
      (yyval.union_keystroke) = Window::MOUSE_DRAG;
    }
    break;

  case 53:
#line 599 "gpl.y"
    {
      (yyval.union_keystroke) = Window::F1;
    }
    break;

  case 54:
#line 603 "gpl.y"
    {
      (yyval.union_keystroke) = Window::AKEY;
    }
    break;

  case 55:
#line 607 "gpl.y"
    {
      (yyval.union_keystroke) = Window::SKEY;
    }
    break;

  case 56:
#line 611 "gpl.y"
    {
      (yyval.union_keystroke) = Window::DKEY;
    }
    break;

  case 57:
#line 615 "gpl.y"
    {
      (yyval.union_keystroke) = Window::FKEY;
    }
    break;

  case 58:
#line 619 "gpl.y"
    {
      (yyval.union_keystroke) = Window::HKEY;
    }
    break;

  case 59:
#line 623 "gpl.y"
    {
      (yyval.union_keystroke) = Window::JKEY;
    }
    break;

  case 60:
#line 627 "gpl.y"
    {
      (yyval.union_keystroke) = Window::KKEY;
    }
    break;

  case 61:
#line 631 "gpl.y"
    {
      (yyval.union_keystroke) = Window::LKEY;
    }
    break;

  case 62:
#line 635 "gpl.y"
    {
      (yyval.union_keystroke) = Window::WKEY;
    }
    break;

  case 63:
#line 639 "gpl.y"
    {
      (yyval.union_keystroke) = Window::ZKEY;
    }
    break;

  case 64:
#line 646 "gpl.y"
    {
      (yyval.union_stmtblock) = (yyvsp[(1) - (3)].union_stmtblock);
  }
    break;

  case 65:
#line 650 "gpl.y"
    {
      (yyval.union_stmtblock) = (yyvsp[(1) - (1)].union_stmtblock);
  }
    break;

  case 66:
#line 657 "gpl.y"
    {
      (yyval.union_stmtblock) = (yyvsp[(2) - (5)].union_stmtblock);
  }
    break;

  case 67:
#line 663 "gpl.y"
    {
      Statement_block *new_block = new Statement_block();
      statement_block_stack.push(new_block);
      (yyval.union_stmtblock) = new_block;
  }
    break;

  case 68:
#line 671 "gpl.y"
    {
      assert(!statement_block_stack.empty());
      statement_block_stack.pop();
  }
    break;

  case 77:
#line 692 "gpl.y"
    {
      Expression *expr = (yyvsp[(3) - (5)].union_expression);
      if (expr->get_type() != INT)
      {
        Error::error(Error::INVALID_TYPE_FOR_IF_STMT_EXPRESSION);
        expr = new Expression(0);
      }
      statement_block_stack.top()->insert(new If_statement(expr,(yyvsp[(5) - (5)].union_stmtblock)));
  }
    break;

  case 78:
#line 702 "gpl.y"
    {
      // COMPLETE ME
  }
    break;

  case 79:
#line 714 "gpl.y"
    {
      // COMPLETE ME
  }
    break;

  case 80:
#line 722 "gpl.y"
    {
      Expression *expr = (yyvsp[(3) - (4)].union_expression);
      if (expr->get_type() != INT
        && expr->get_type() != DOUBLE
        && expr->get_type() != STRING
       )
      {
        Error::error(Error::INVALID_TYPE_FOR_PRINT_STMT_EXPRESSION);
        // for error handling
        expr = new Expression(0);
      }
      statement_block_stack.top()->insert(new Print_statement(expr, (yyvsp[(1) - (4)].union_int))); // $1 has line_number
  }
    break;

  case 81:
#line 739 "gpl.y"
    {
      // COMPLETE ME
  }
    break;

  case 84:
#line 751 "gpl.y"
    {
      Variable *lhs = (yyvsp[(1) - (3)].union_variable);
      Expression *rhs = (yyvsp[(3) - (3)].union_expression);
      Gpl_type lhs_type = lhs->get_type();
      Gpl_type rhs_type = rhs->get_type();

      // game_object is illegal on lhs of assignment
      if (lhs_type & GAME_OBJECT)
      {
        Error::error(Error::INVALID_LHS_OF_ASSIGNMENT,
              lhs->get_name(),
              gpl_type_to_string(lhs_type)
              );
      }

      // if variable is an INT, expression must be INT
      // if variable is a DOUBLE, expression must be INT or DOUBLE
      // if variable is a STRING, expression must be STRING,INT, or DOUBLE
      // if variable is a ANIMATION_BLOCK, expression ANIMATION_BLOCK
      else if ((lhs_type == INT && rhs_type != INT)
          ||(lhs_type==DOUBLE&&(rhs_type != INT && rhs_type!=DOUBLE))
          ||(lhs_type == STRING && rhs_type == ANIMATION_BLOCK)
          ||(lhs_type==ANIMATION_BLOCK&& rhs_type != ANIMATION_BLOCK)
          )
      {
        Error::error(Error::ASSIGNMENT_TYPE_ERROR,
                     gpl_type_to_string(lhs_type),
                     gpl_type_to_string(rhs_type)
                    );
      }
        else if (lhs_type==ANIMATION_BLOCK)
        {
          // since lhs is an ANIMATION_BLOCK, it SHOULD take one of these forms
          // circle.animation_block =
          // circles[index].animation_block =

          // this is ok
          //   my_rect.animation_block = bounce;
          // this is NOT ok
          //   bounce = move;
          // check to make sure it is not this illegal form
          if (lhs->is_non_member_animation_block())
          {
            Error::error(Error::CANNOT_ASSIGN_TO_NON_MEMBER_ANIMATION_BLOCK,
                         lhs->get_name()
                        );
          }
          else
          {
  
            // get the type of the Game_object on the LHS
            Gpl_type lhs_base_object_type = lhs->get_base_game_object_type();
  
            Gpl_type rhs_param_type = rhs->eval_animation_block()->get_parameter_symbol()->get_type();
  
            // Animation_block *block = rhs->eval_animation_block();
            // Symbol *sym = block->get_parameter_symbol();
  
            if (lhs_base_object_type != rhs_param_type)
            {
              Error::error(Error::ANIMATION_BLOCK_ASSIGNMENT_PARAMETER_TYPE_ERROR,
                           gpl_type_to_string(lhs_base_object_type),
                           gpl_type_to_string(rhs_param_type)
                          );
  
            }
            else statement_block_stack.top()->insert(new Assign_statement(ASSIGN, lhs, rhs));
            }
          }
      else // the types are ok
      {
        statement_block_stack.top()->insert(new Assign_statement(ASSIGN, lhs, rhs));
      }
  }
    break;

  case 85:
#line 826 "gpl.y"
    {
      Gpl_type lhs_type = (yyvsp[(1) - (3)].union_variable)->get_type();
      Gpl_type rhs_type = (yyvsp[(3) - (3)].union_expression)->get_type();

      // game_object & statement_block are illegal on lhs of +=
      if ((lhs_type & GAME_OBJECT) || (lhs_type == ANIMATION_BLOCK))
      {
        Error::error(Error::INVALID_LHS_OF_PLUS_ASSIGNMENT,
                  (yyvsp[(1) - (3)].union_variable)->get_name(),
                  gpl_type_to_string(lhs_type)
              );
      }

      // if variable is an INT, expression must be INT
      // if variable is a DOUBLE, expression must be INT or DOUBLE
      // if variable is a STRING, expression must be STRING,INT, or DOUBLE
      else if ((lhs_type == INT && rhs_type != INT)
          ||(lhs_type==DOUBLE&&(rhs_type != INT && rhs_type!=DOUBLE))
          ||(lhs_type == STRING && rhs_type == ANIMATION_BLOCK)
          )
      {
        Error::error(Error::PLUS_ASSIGNMENT_TYPE_ERROR,
              gpl_type_to_string(lhs_type),
              gpl_type_to_string(rhs_type)
              );
      }
      else // the types are ok
      {
        statement_block_stack.top()->insert(new Assign_statement(PLUS_ASSIGN, (yyvsp[(1) - (3)].union_variable), (yyvsp[(3) - (3)].union_expression)));
      }
  }
    break;

  case 86:
#line 858 "gpl.y"
    {
      Gpl_type lhs_type = (yyvsp[(1) - (3)].union_variable)->get_type();
      Gpl_type rhs_type = (yyvsp[(3) - (3)].union_expression)->get_type();

      // game_object & statement_block & string are illegal on lhs of +=
      if (lhs_type != INT && lhs_type != DOUBLE)
      {
        Error::error(Error::INVALID_LHS_OF_MINUS_ASSIGNMENT,
                  (yyvsp[(1) - (3)].union_variable)->get_name(),
                  gpl_type_to_string(lhs_type)
                 );
      }

      // if variable is an INT, expression must be INT
      // if variable is a DOUBLE, expression must be INT or DOUBLE
      else if ((lhs_type == INT && rhs_type != INT)
          ||(lhs_type==DOUBLE&&(rhs_type != INT && rhs_type!=DOUBLE))
          )
      {
        Error::error(Error::MINUS_ASSIGNMENT_TYPE_ERROR,
              gpl_type_to_string(lhs_type),
              gpl_type_to_string(rhs_type)
              );
      }
      else // the types are ok
      {
        statement_block_stack.top()->insert(new Assign_statement(MINUS_ASSIGN, (yyvsp[(1) - (3)].union_variable), (yyvsp[(3) - (3)].union_expression)));
      }
  }
    break;

  case 87:
#line 888 "gpl.y"
    {
      Gpl_type lhs_type = (yyvsp[(1) - (2)].union_variable)->get_type();
      if (lhs_type != INT)
      {
        Error::error(Error::INVALID_LHS_OF_PLUS_PLUS,
                  (yyvsp[(1) - (2)].union_variable)->get_name(),
                  gpl_type_to_string(lhs_type)
                 );
      }
      else // the types are ok
      {
        statement_block_stack.top()->insert(new Assign_statement(PLUS_PLUS, (yyvsp[(1) - (2)].union_variable)));
      }
  }
    break;

  case 88:
#line 903 "gpl.y"
    {
      Gpl_type lhs_type = (yyvsp[(1) - (2)].union_variable)->get_type();
      if (lhs_type != INT)
      {
        Error::error(Error::INVALID_LHS_OF_MINUS_MINUS,
                  (yyvsp[(1) - (2)].union_variable)->get_name(),
                  gpl_type_to_string(lhs_type)
                 );
      }
      else // the types are ok
      {
        statement_block_stack.top()->insert(new Assign_statement(MINUS_MINUS, (yyvsp[(1) - (2)].union_variable)));
      }
  }
    break;

  case 89:
#line 921 "gpl.y"
    {
        string *id = (yyvsp[(1) - (1)].union_string); 
        Symbol *s = table->lookup(*id);
        if (s == NULL) {
            Error::error(Error::UNDECLARED_VARIABLE,*id);
            (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
        }
        else if (s->is_array()) {
            Error::error(Error::VARIABLE_IS_AN_ARRAY,*id);
            (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
        } else {
            (yyval.union_variable) = new Variable(table->lookup(*id));
        }
    }
    break;

  case 90:
#line 935 "gpl.y"
    {
            string *id = (yyvsp[(1) - (4)].union_string); 
            Symbol *s = table->lookup(*id);
            Expression *e = (yyvsp[(3) - (4)].union_expression);
            if (s == NULL) {
                string name = *id + "[]";
                Error::error(Error::UNDECLARED_VARIABLE,name);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_array()){
                Error::error(Error::VARIABLE_NOT_AN_ARRAY,*id);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else if (e == NULL) {
                
            } else if (e->get_type() != INT) {
                string err = "";
                if (e->get_type() == DOUBLE) {
                    err = "A double expression";
                } else if (e->get_type() == STRING) {
                    err = "A string expression";
                } else {
                    err = "A animation_block expression";
                }
                Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*id, err);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else if (!s->index_within_range(e->eval_int())) {
                int num = e->eval_int();
                string n = std::to_string(num);
                Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*id,n);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            }
            else {(yyval.union_variable) = new Variable(s, (yyvsp[(3) - (4)].union_expression));}
        }
    break;

  case 91:
#line 969 "gpl.y"
    {
        Symbol *s = table->lookup(*(yyvsp[(1) - (3)].union_string));
        if (s == NULL) {
            Error::error(Error::UNDECLARED_VARIABLE, *(yyvsp[(1) - (3)].union_string));
            (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
        } else {
            if (!(s->get_type() & GAME_OBJECT)) {
                Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT,*(yyvsp[(1) - (3)].union_string));
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else {
                Game_object *g = s->get_game_object_value();
                if (g == NULL) {

                } else {
                    Gpl_type *type = new Gpl_type(NO_TYPE);
                    if (!g->has_member_variable(*(yyvsp[(3) - (3)].union_string))) {
                        Error::error(Error::UNDECLARED_MEMBER,*(yyvsp[(1) - (3)].union_string),*(yyvsp[(3) - (3)].union_string));
                        (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
                    } else {
                        g->get_member_variable_type(*(yyvsp[(3) - (3)].union_string),*type);
                        if (*type == INT) {
                            int *val = new int(0);
                            Status status = g->get_member_variable(*(yyvsp[(3) - (3)].union_string),*val);
                            string newName = *(yyvsp[(1) - (3)].union_string) + "." + *(yyvsp[(3) - (3)].union_string);
                            Symbol *newSymbol = new Symbol(newName,*val);
                            (yyval.union_variable) = new Variable(newSymbol);
                        } else if (*type == DOUBLE) {
                            double *val = new double(0.0);
                            Status status = g->get_member_variable(*(yyvsp[(3) - (3)].union_string),*val);
                            string newName = *(yyvsp[(1) - (3)].union_string) + "." + *(yyvsp[(3) - (3)].union_string);
                            Symbol *newSymbol = new Symbol(newName,*val);
                            (yyval.union_variable) = new Variable(newSymbol);
                        } else if (*type == STRING) {
                            string *val = new string("");
                            Status status = g->get_member_variable(*(yyvsp[(3) - (3)].union_string),*val);
                            string newName = *(yyvsp[(1) - (3)].union_string) + "." + *(yyvsp[(3) - (3)].union_string);
                            Symbol *newSymbol = new Symbol(newName,*val);
                            (yyval.union_variable) = new Variable(newSymbol);
                        } else if (*type == ANIMATION_BLOCK) {
                            // Animation_block **a;
                            // Status status = g->get_member_variable(*$3,*a);
                            // string newName = *$1 + "." + *$3;
                            // Symbol *newSymbol = new Symbol(newName,ANIMATION_BLOCK);
                            // $$ = new Variable(newSymbol);
                        } else {

                        }
                    }
                }
            }
        }
    }
    break;

  case 92:
#line 1021 "gpl.y"
    {
            string *id = (yyvsp[(1) - (6)].union_string); 
            Symbol *s = table->lookup(*id);
            Expression *e = (yyvsp[(3) - (6)].union_expression);
            if (s == NULL) {
                string name = *id + "[]";
                Error::error(Error::UNDECLARED_VARIABLE,name);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_array()){
                Error::error(Error::VARIABLE_NOT_AN_ARRAY,*id);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else if (e == NULL) {
                
            } else if (e->get_type() != INT) {
                string err = "";
                if (e->get_type() == DOUBLE) {
                    err = "A double expression";
                } else if (e->get_type() == STRING) {
                    err = "A string expression";
                } else {
                    err = "A animation_block expression";
                }
                Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*id, err);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else if (!s->index_within_range(e->eval_int())) {
                int num = e->eval_int();
                string n = std::to_string(num);
                Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*id,n);
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            }
            else if (!s->is_game_object()) {
                Error::error(Error::LHS_OF_PERIOD_MUST_BE_OBJECT,*(yyvsp[(1) - (6)].union_string));
                (yyval.union_variable) = new Variable(new Symbol("undeclared",0));
            } else {
                int index = e->eval_int();
                Game_object *g = s->get_game_object_value(index);
                Gpl_type *type = new Gpl_type(NO_TYPE);
                if (!g->has_member_variable(*(yyvsp[(6) - (6)].union_string))) {
                    
                } else {
                    g->get_member_variable_type(*(yyvsp[(6) - (6)].union_string),*type);
                    if (*type == INT) {
                        int *val = new int(0);
                        Status status = g->get_member_variable(*(yyvsp[(6) - (6)].union_string),*val);
                        string newName = *(yyvsp[(1) - (6)].union_string) + "." + *(yyvsp[(6) - (6)].union_string);
                        Symbol *newSymbol = new Symbol(newName,*val);
                        (yyval.union_variable) = new Variable(newSymbol);
                    } else if (*type == DOUBLE) {
                        double *val = new double(0.0);
                        Status status = g->get_member_variable(*(yyvsp[(6) - (6)].union_string),*val);
                        string newName = *(yyvsp[(1) - (6)].union_string) + "." + *(yyvsp[(6) - (6)].union_string);
                        Symbol *newSymbol = new Symbol(newName,*val);
                        (yyval.union_variable) = new Variable(newSymbol);
                    } else if (*type == STRING) {
                        string *val = new string("");
                        Status status = g->get_member_variable(*(yyvsp[(6) - (6)].union_string),*val);
                        string newName = *(yyvsp[(1) - (6)].union_string) + "." + *(yyvsp[(6) - (6)].union_string);
                        Symbol *newSymbol = new Symbol(newName,*val);
                        (yyval.union_variable) = new Variable(newSymbol);
                    } else if (*type == ANIMATION_BLOCK) {
                        // Animation_block **a;
                        // Status status = g->get_member_variable(*$6,*a);
                        // string newName = *$1 + "." + *$6;
                        // Symbol *newSymbol = new Symbol(newName,ANIMATION_BLOCK);
                        // $$ = new Variable(newSymbol);
                    } else {

                    }
                }
            }
    }
    break;

  case 93:
#line 1098 "gpl.y"
    {
        Expression *e = (yyvsp[(1) - (1)].union_expression);
        (yyval.union_expression) = (yyvsp[(1) - (1)].union_expression);
        }
    break;

  case 94:
#line 1102 "gpl.y"
    {
            (yyval.union_expression) = new Expression(0);
            if ((yyvsp[(1) - (3)].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "||");
            } 
            if ((yyvsp[(3) - (3)].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "||");
            } 
            if ((yyvsp[(1) - (3)].union_expression)->get_type() != STRING && (yyvsp[(3) - (3)].union_expression)->get_type() != STRING) {
                (yyval.union_expression) = new Expression(OR, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
            }
        }
    break;

  case 95:
#line 1114 "gpl.y"
    {
            (yyval.union_expression) = new Expression(0);
            if ((yyvsp[(1) - (3)].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "&&");
                (yyval.union_expression) = new Expression(0);
            } 
            if ((yyvsp[(3) - (3)].union_expression)->get_type() == STRING){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "&&");
                (yyval.union_expression) = new Expression(0);
            } 
            if ((yyvsp[(1) - (3)].union_expression)->get_type() != STRING && (yyvsp[(3) - (3)].union_expression)->get_type() != STRING) {
                (yyval.union_expression) = new Expression(AND, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
            }
        }
    break;

  case 96:
#line 1128 "gpl.y"
    {
        (yyval.union_expression) = new Expression(LESS_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "<=");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "<=");
            (yyval.union_expression) = NULL;
        }
        }
    break;

  case 97:
#line 1139 "gpl.y"
    {
        (yyval.union_expression) = new Expression(GREATER_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, ">=");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, ">=");
            (yyval.union_expression) = NULL;
        }
        }
    break;

  case 98:
#line 1150 "gpl.y"
    {
        (yyval.union_expression) = new Expression(LESS_THAN, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "<");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "<");
            (yyval.union_expression) = NULL;
        }
        }
    break;

  case 99:
#line 1161 "gpl.y"
    {
        (yyval.union_expression) = new Expression(GREATER_THAN, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, ">");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, ">");
            (yyval.union_expression) = NULL;
        }
        }
    break;

  case 100:
#line 1172 "gpl.y"
    {
        (yyval.union_expression) = new Expression(EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "==");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "==");
            (yyval.union_expression) = NULL;
        }
        }
    break;

  case 101:
#line 1183 "gpl.y"
    {(yyval.union_expression) = new Expression(NOT_EQUAL, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));}
    break;

  case 102:
#line 1184 "gpl.y"
    {
        (yyval.union_expression) = new Expression(PLUS, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(1) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "+");
            (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE && (yyvsp[(3) - (3)].union_expression)->get_type()!=STRING) {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "+");
            (yyval.union_expression) = NULL;
        }
    }
    break;

  case 103:
#line 1195 "gpl.y"
    {
        (yyval.union_expression) = new Expression(MINUS, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "-");
                (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
                (yyval.union_expression) = NULL;
        } 
        }
    break;

  case 104:
#line 1206 "gpl.y"
    {
        (yyval.union_expression) = new Expression(MULTIPLY, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
        if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE){
                Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "*");
                (yyval.union_expression) = NULL;
        }
        if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "*");
                (yyval.union_expression) = NULL;
        } 
        }
    break;

  case 105:
#line 1217 "gpl.y"
    {
            (yyval.union_expression) = new Expression(DIVIDE, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
            if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT && (yyvsp[(1) - (3)].union_expression)->get_type() != DOUBLE){
                    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "/");
                    (yyval.union_expression) = NULL;
            }
            if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT && (yyvsp[(3) - (3)].union_expression)->get_type() != DOUBLE){
                    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "/");
                    (yyval.union_expression) = NULL;
            } 
        }
    break;

  case 106:
#line 1228 "gpl.y"
    {
            (yyval.union_expression) = new Expression(MOD, (yyvsp[(1) - (3)].union_expression), (yyvsp[(3) - (3)].union_expression));
            if ((yyvsp[(1) - (3)].union_expression)->get_type() != INT){
                    Error::error(Error::INVALID_LEFT_OPERAND_TYPE, "%");
                    (yyval.union_expression) = NULL;
            }
            if ((yyvsp[(3) - (3)].union_expression)->get_type() != INT){
                    Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "%");
                    (yyval.union_expression) = NULL;
            } 
        }
    break;

  case 107:
#line 1239 "gpl.y"
    {
            if ((yyvsp[(2) - (2)].union_expression)->get_type() != INT && (yyvsp[(2) - (2)].union_expression)->get_type() != DOUBLE){
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "-");
                (yyval.union_expression) = new Expression(0);
            } else {
                (yyval.union_expression) = new Expression(UNARY_MINUS, (yyvsp[(2) - (2)].union_expression));
            }
        }
    break;

  case 108:
#line 1247 "gpl.y"
    {
            if ((yyvsp[(2) - (2)].union_expression)->get_type() != INT && (yyvsp[(2) - (2)].union_expression)->get_type() != DOUBLE) {
                Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, "!");
                (yyval.union_expression) = new Expression(0);
            } else {
                (yyval.union_expression) = new Expression(NOT, (yyvsp[(2) - (2)].union_expression));
            }
        }
    break;

  case 109:
#line 1255 "gpl.y"
    {
        if ((yyvsp[(3) - (4)].union_expression)->get_type() == INT || (yyvsp[(3) - (4)].union_expression)->get_type() == DOUBLE){
            (yyval.union_expression) = new Expression((yyvsp[(1) - (4)].union_op), (yyvsp[(3) - (4)].union_expression));
        } else {

            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE, operator_to_string((yyvsp[(1) - (4)].union_op)));
            (yyval.union_expression) = new Expression(0);
        }
        }
    break;

  case 112:
#line 1270 "gpl.y"
    {(yyval.union_expression) = (yyvsp[(2) - (3)].union_expression);}
    break;

  case 113:
#line 1271 "gpl.y"
    {
            if ((yyvsp[(1) - (1)].union_variable) == NULL) {
            } else {
                (yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_variable));
            }
        }
    break;

  case 114:
#line 1277 "gpl.y"
    {(yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_int));}
    break;

  case 115:
#line 1278 "gpl.y"
    {(yyval.union_expression) = new Expression(1);}
    break;

  case 116:
#line 1279 "gpl.y"
    {(yyval.union_expression) = new Expression(0);}
    break;

  case 117:
#line 1280 "gpl.y"
    {(yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_double));}
    break;

  case 118:
#line 1281 "gpl.y"
    {(yyval.union_expression) = new Expression((yyvsp[(1) - (1)].union_string));}
    break;

  case 119:
#line 1286 "gpl.y"
    {(yyval.union_op) = SIN;}
    break;

  case 120:
#line 1287 "gpl.y"
    {(yyval.union_op) = COS;}
    break;

  case 121:
#line 1288 "gpl.y"
    {(yyval.union_op) = TAN;}
    break;

  case 122:
#line 1289 "gpl.y"
    {(yyval.union_op) = ASIN;}
    break;

  case 123:
#line 1290 "gpl.y"
    {(yyval.union_op) = ACOS;}
    break;

  case 124:
#line 1291 "gpl.y"
    {(yyval.union_op) = ATAN;}
    break;

  case 125:
#line 1292 "gpl.y"
    {(yyval.union_op) = SQRT;}
    break;

  case 126:
#line 1293 "gpl.y"
    {(yyval.union_op) = ABS;}
    break;

  case 127:
#line 1294 "gpl.y"
    {(yyval.union_op) = FLOOR;}
    break;

  case 128:
#line 1295 "gpl.y"
    {(yyval.union_op) = RANDOM;}
    break;


/* Line 1267 of yacc.c.  */
#line 3109 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



