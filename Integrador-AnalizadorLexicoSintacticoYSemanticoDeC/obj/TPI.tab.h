/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
     THEN = 258,
     CONSTANTE_ENTERA_INT_TYPE = 259,
     CONSTANTE_ENTERA_UNSIGNED_INT_TYPE = 260,
     CONSTANTE_ENTERA_LONG_TYPE = 261,
     CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE = 262,
     CONSTANTE_REAL_FLOAT_TYPE = 263,
     CONSTANTE_REAL_LONG_DOUBLE_TYPE = 264,
     CONSTANTE_REAL_DOUBLE_TYPE = 265,
     LITERAL_CADENA = 266,
     TYPEDEF_TOKEN = 267,
     EXTERN_TOKEN = 268,
     STATIC_TOKEN = 269,
     AUTO_TOKEN = 270,
     REGISTER_TOKEN = 271,
     VOID_TOKEN = 272,
     CHAR_TOKEN = 273,
     SHORT_TOKEN = 274,
     INT_TOKEN = 275,
     LONG_TOKEN = 276,
     FLOAT_TOKEN = 277,
     DOUBLE_TOKEN = 278,
     SIGNED_TOKEN = 279,
     UNSIGNED_TOKEN = 280,
     CONST_TOKEN = 281,
     VOLATILE_TOKEN = 282,
     STRUCT_TOKEN = 283,
     UNION_TOKEN = 284,
     ENUM_TOKEN = 285,
     IF_TOKEN = 286,
     ELSE_TOKEN = 287,
     SWITCH_TOKEN = 288,
     WHILE_TOKEN = 289,
     DO_TOKEN = 290,
     FOR_TOKEN = 291,
     CASE_TOKEN = 292,
     DEFAULT_TOKEN = 293,
     GOTO_TOKEN = 294,
     CONTINUE_TOKEN = 295,
     BREAK_TOKEN = 296,
     RETURN_TOKEN = 297,
     SIZEOF_TOKEN = 298,
     IDENTIFICADOR = 299,
     NOMBRE_DE_TYPEDEF = 300,
     ELIPSIS_TOKEN = 301,
     MAS_IGUAL_TOKEN = 302,
     MENOS_IGUAL_TOKEN = 303,
     POR_IGUAL_TOKEN = 304,
     DIVIDIDO_IGUAL_TOKEN = 305,
     MOD_IGUAL_TOKEN = 306,
     AND_IGUAL_TOKEN = 307,
     OR_IGUAL_TOKEN = 308,
     XOR_IGUAL_TOKEN = 309,
     ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA_TOKEN = 310,
     ASIGNACION_CON_DESPLAZAMIENTO_DERECHA_TOKEN = 311,
     OR_TOKEN = 312,
     AND_TOKEN = 313,
     IGUALDAD_TOKEN = 314,
     DIFERENCIA_TOKEN = 315,
     MAYOR_O_IGUAL_TOKEN = 316,
     MENOR_O_IGUAL_TOKEN = 317,
     DESPLAZAMIENTO_IZQUIERDA_TOKEN = 318,
     DESPLAZAMIENTO_DERECHA_TOKEN = 319,
     MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION_TOKEN = 320,
     INCREMENTO_TOKEN = 321,
     DECREMENTO_TOKEN = 322
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 74 "src/TPI.y"

	int int_type;
	unsigned int unsigned_int_type;
	long long_type;
	unsigned long unsigned_long_type;
	float float_type;
	double double_type;
	long double long_double_type;
	char* char_pointer_type;

	Nodo_AST* nodo_ast;

	enum Struct_o_Union struct_o_union;
	enum Tipo_Unary_Expression tipoUnary_Expression;
	enum Tipo_Assignment_Expression tipoAssignment_Expression;



/* Line 1685 of yacc.c  */
#line 137 "obj/TPI.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;

