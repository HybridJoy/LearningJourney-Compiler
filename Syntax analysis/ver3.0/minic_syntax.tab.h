/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    STRUCT = 259,
    ID = 260,
    INTEGER = 261,
    FLOATING = 262,
    STRING = 263,
    CHAR = 264,
    IF = 265,
    ELSE = 266,
    DO = 267,
    WHILE = 268,
    FOR = 269,
    BREAK = 270,
    CONTINUE = 271,
    RETURN = 272,
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
    QUALIFIER = 298,
    LOWER_THAN_ELSE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "minic_syntax.y" /* yacc.c:1909  */

	struct treeNode* node;

#line 103 "minic_syntax.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_SYNTAX_TAB_H_INCLUDED  */
