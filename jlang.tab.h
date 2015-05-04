/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 141 "jlang.y" /* yacc.c:1909  */

    struct treeNode* node;
	struct 
	{
		char* ptr;
		int lineNumber;
	} str;
	
	long num;

#line 112 "jlang.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_JLANG_TAB_H_INCLUDED  */
