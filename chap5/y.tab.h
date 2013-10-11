/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

#include "absyn.h"


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 160 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


