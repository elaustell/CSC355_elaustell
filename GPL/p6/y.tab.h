/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 42 "gpl.y"
{
  int              union_int;
  double           union_double;
  std::string      *union_string;  // MUST be a pointer to a string ARG!
  Gpl_type         union_type;
  Expression       *union_expression;
  Variable         *union_variable;
  Operator_type    union_op;
  Game_object      *union_object;
}
/* Line 1529 of yacc.c.  */
#line 246 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

