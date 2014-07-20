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
/* Tokens.  */
#define T_WITH 258
#define T_STRUCT 259
#define T_RETURN 260
#define T_NUM 261
#define T_COND 262
#define T_END 263
#define T_ID 264
#define T_LET 265
#define T_IN 266
#define T_FUNC 267
#define T_OR 268
#define T_NOT 269
#define T_DO 270
#define T_THEN 271
#define T_BRACKET_LEFT 272
#define T_BRACKET_RIGHT 273
#define T_DOUBLE_POINT 274
#define T_SEMICOLON 275
#define T_EQUAL 276
#define T_POINT 277
#define T_MINUS 278
#define T_PLUS 279
#define T_MUL 280
#define T_GREATER 281
#define T_NOT_EQUAL 282
#define T_COLON 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

