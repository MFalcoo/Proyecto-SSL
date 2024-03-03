/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 43 "src/TPI.y"

#include "bibliotecas.h"
#include "semantica.h"

	/* Declaración de la función yylex del analizador léxico, necesaria para que la función yyparse del analizador sintáctico pueda invocarla cada vez que solicite un nuevo token */
extern int yylex(void);
	/* Declaración de la función yyerror para reportar errores, necesaria para que la función yyparse del analizador sintáctico pueda invocarla para reportar un error */
void yyerror(const char*);

extern FILE* yyin;
extern int alcanceActual;
enum Booleano bandera_podria_usarse_un_nombre_de_typedef = TRUE;
extern Descripcion* variablesDeclaradas;
extern Descripcion* funcionesDeclaradas;
extern Descripcion* erroresLexicos;
extern Descripcion* erroresSintacticos;
extern Descripcion* erroresSemanticos;
extern int cantidadErroresLexicos;
int cantidadErroresSemanticos = 0;


/* Line 189 of yacc.c  */
#line 94 "obj/TPI.tab.c"

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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 216 "obj/TPI.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "obj/TPI.tab.c"

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  276
/* YYNRULES -- Number of states.  */
#define YYNSTATES  419

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,     2,     2,     2,    88,    82,     2,
      74,    75,    78,    85,    69,    86,    91,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    73,    68,
      83,    70,    84,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    80,    72,    89,     2,     2,     2,
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
      65,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    17,    21,    25,
      28,    31,    35,    37,    40,    42,    45,    47,    50,    52,
      55,    57,    61,    65,    67,    71,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   106,   108,   110,   112,   113,   117,   118,   123,
     124,   130,   132,   134,   136,   138,   141,   145,   147,   150,
     152,   155,   157,   161,   163,   166,   170,   171,   175,   179,
     184,   186,   188,   192,   194,   198,   201,   203,   205,   209,
     214,   218,   219,   224,   227,   230,   232,   233,   237,   238,
     240,   242,   245,   247,   250,   252,   256,   258,   262,   265,
     268,   270,   272,   276,   278,   282,   287,   289,   293,   295,
     298,   300,   302,   305,   309,   312,   316,   320,   325,   328,
     332,   336,   341,   343,   345,   347,   349,   351,   353,   354,
     359,   360,   365,   366,   372,   375,   376,   381,   383,   386,
     387,   391,   393,   396,   399,   403,   405,   408,   409,   413,
     414,   421,   426,   433,   436,   437,   444,   445,   454,   455,
     459,   465,   472,   473,   478,   479,   483,   484,   488,   489,
     493,   495,   498,   500,   504,   508,   510,   514,   516,   518,
     520,   522,   524,   526,   528,   530,   532,   534,   536,   538,
     540,   546,   552,   558,   560,   564,   568,   570,   574,   578,
     580,   584,   586,   590,   592,   596,   600,   602,   606,   610,
     614,   618,   620,   624,   628,   632,   636,   640,   644,   648,
     652,   654,   658,   662,   664,   668,   672,   676,   680,   682,
     686,   690,   694,   698,   702,   706,   708,   709,   715,   717,
     718,   722,   723,   727,   730,   731,   735,   737,   741,   743,
     745,   747,   749,   751,   753,   755,   760,   764,   769,   773,
     777,   780,   783,   785,   789,   791,   793,   795,   797,   798,
     803,   805,   807,   809,   811,   813,   815
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    94,    -1,    93,    94,    -1,    95,    -1,
      96,    -1,    98,   120,    97,   144,    -1,    98,   120,   144,
      -1,   120,    97,   144,    -1,   120,   144,    -1,    98,    68,
      -1,    98,    99,    68,    -1,    96,    -1,    97,    96,    -1,
     101,    -1,   101,    98,    -1,   102,    -1,   102,    98,    -1,
     103,    -1,   103,    98,    -1,   100,    -1,    99,    69,   100,
      -1,    99,    69,     1,    -1,   120,    -1,   120,    70,   132,
      -1,   120,     1,    -1,    15,    -1,    16,    -1,    14,    -1,
      13,    -1,    12,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,   104,    -1,   115,    -1,    45,    -1,    26,    -1,
      27,    -1,    -1,   109,   105,   106,    -1,    -1,    71,   107,
     110,    72,    -1,    -1,    44,    71,   108,   110,    72,    -1,
      44,    -1,    28,    -1,    29,    -1,   111,    -1,   110,   111,
      -1,   112,   113,    68,    -1,   102,    -1,   102,   112,    -1,
     103,    -1,   103,   112,    -1,   114,    -1,   113,    69,   114,
      -1,   120,    -1,    73,   166,    -1,   120,    73,   166,    -1,
      -1,    30,   116,   117,    -1,    71,   118,    72,    -1,    44,
      71,   118,    72,    -1,    44,    -1,   119,    -1,   118,    69,
     119,    -1,    44,    -1,    44,    70,   166,    -1,   124,   121,
      -1,   121,    -1,    44,    -1,    74,   120,    75,    -1,   121,
      76,   166,    77,    -1,   121,    76,    77,    -1,    -1,   121,
      74,   122,   123,    -1,   128,    75,    -1,   131,    75,    -1,
      75,    -1,    -1,    78,   125,   126,    -1,    -1,   127,    -1,
     124,    -1,   127,   124,    -1,   103,    -1,   127,   103,    -1,
     129,    -1,   129,    69,    46,    -1,   130,    -1,   129,    69,
     130,    -1,    98,   120,    -1,    98,   135,    -1,    98,    -1,
      44,    -1,   131,    69,    44,    -1,   164,    -1,    71,   133,
      72,    -1,    71,   133,    69,    72,    -1,   132,    -1,   133,
      69,   132,    -1,   112,    -1,   112,   135,    -1,   124,    -1,
     136,    -1,   124,   136,    -1,    74,   135,    75,    -1,    76,
      77,    -1,    76,   166,    77,    -1,   136,    76,    77,    -1,
     136,    76,   166,    77,    -1,    74,    75,    -1,    74,   128,
      75,    -1,   136,    74,    75,    -1,   136,    74,   128,    75,
      -1,   138,    -1,   143,    -1,   144,    -1,   148,    -1,   152,
      -1,   157,    -1,    -1,    44,   139,    73,   137,    -1,    -1,
      45,   140,    73,   137,    -1,    -1,    37,   141,   166,    73,
     137,    -1,    37,     1,    -1,    -1,    38,   142,    73,   137,
      -1,    68,    -1,   163,    68,    -1,    -1,    71,   145,   146,
      -1,    72,    -1,   147,    72,    -1,    97,    72,    -1,    97,
     147,    72,    -1,   137,    -1,   147,   137,    -1,    -1,    31,
     149,   151,    -1,    -1,    33,   150,    74,   163,    75,   137,
      -1,    74,   163,    75,   137,    -1,    74,   163,    75,   137,
      32,   137,    -1,    74,     1,    -1,    -1,    34,   153,    74,
     163,    75,   137,    -1,    -1,    35,   154,   137,    34,    74,
     163,    75,    68,    -1,    -1,    36,   155,   156,    -1,    74,
     143,   143,    75,   137,    -1,    74,   143,   143,   163,    75,
     137,    -1,    -1,    39,   158,    44,    68,    -1,    -1,    40,
     159,    68,    -1,    -1,    41,   160,    68,    -1,    -1,    42,
     161,   162,    -1,    68,    -1,   163,    68,    -1,   164,    -1,
     163,    69,   164,    -1,   163,    69,     1,    -1,   167,    -1,
     180,   165,   164,    -1,    70,    -1,    49,    -1,    50,    -1,
      51,    -1,    47,    -1,    48,    -1,    55,    -1,    56,    -1,
      52,    -1,    54,    -1,    53,    -1,   167,    -1,   168,    -1,
     168,    79,   163,    73,   167,    -1,   168,    79,     1,    73,
     167,    -1,   168,    79,   163,    73,     1,    -1,   169,    -1,
     168,    57,   169,    -1,   168,    57,     1,    -1,   170,    -1,
     169,    58,   170,    -1,   169,    58,     1,    -1,   171,    -1,
     170,    80,   171,    -1,   172,    -1,   171,    81,   172,    -1,
     173,    -1,   172,    82,   173,    -1,   172,    82,     1,    -1,
     174,    -1,   173,    59,   174,    -1,   173,    59,     1,    -1,
     173,    60,   174,    -1,   173,    60,     1,    -1,   175,    -1,
     174,    83,   175,    -1,   174,    83,     1,    -1,   174,    84,
     175,    -1,   174,    84,     1,    -1,   174,    62,   175,    -1,
     174,    62,     1,    -1,   174,    61,   175,    -1,   174,    61,
       1,    -1,   176,    -1,   175,    63,   176,    -1,   175,    64,
     176,    -1,   177,    -1,   176,    85,   177,    -1,   176,    85,
       1,    -1,   176,    86,   177,    -1,   176,    86,     1,    -1,
     178,    -1,   177,    78,   178,    -1,   177,    78,     1,    -1,
     177,    87,   178,    -1,   177,    87,     1,    -1,   177,    88,
     178,    -1,   177,    88,     1,    -1,   180,    -1,    -1,    74,
     179,   134,    75,   178,    -1,   186,    -1,    -1,    66,   181,
     180,    -1,    -1,    67,   182,   180,    -1,   185,   178,    -1,
      -1,    43,   183,   184,    -1,   180,    -1,    74,   134,    75,
      -1,    82,    -1,    78,    -1,    85,    -1,    86,    -1,    89,
      -1,    90,    -1,   188,    -1,   186,    76,   163,    77,    -1,
     186,    74,    75,    -1,   186,    74,   187,    75,    -1,   186,
      91,    44,    -1,   186,    65,    44,    -1,   186,    66,    -1,
     186,    67,    -1,   164,    -1,   187,    69,   164,    -1,    44,
      -1,   190,    -1,   191,    -1,    11,    -1,    -1,    74,   189,
     163,    75,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,     8,    -1,    10,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   246,   246,   251,   259,   264,   272,   280,   288,   296,
     311,   319,   330,   335,   343,   348,   353,   358,   363,   368,
     376,   381,   386,   396,   401,   406,   417,   422,   427,   432,
     437,   445,   451,   457,   463,   469,   475,   481,   487,   493,
     499,   505,   511,   520,   525,   533,   533,   571,   571,   577,
     577,   583,   599,   604,   612,   617,   625,   634,   639,   644,
     649,   657,   662,   670,   675,   680,   688,   688,   698,   704,
     710,   726,   731,   739,   744,   752,   757,   765,   771,   776,
     781,   786,   786,   797,   803,   809,   818,   818,   836,   840,
     845,   850,   858,   863,   871,   876,   884,   890,   899,   904,
     909,   917,   923,   931,   936,   941,   949,   954,   962,   967,
     975,   980,   985,   993,   998,  1003,  1008,  1013,  1018,  1023,
    1028,  1033,  1052,  1057,  1062,  1067,  1072,  1077,  1085,  1085,
    1091,  1091,  1097,  1097,  1103,  1110,  1110,  1119,  1126,  1136,
    1135,  1151,  1158,  1165,  1172,  1182,  1187,  1195,  1195,  1203,
    1203,  1221,  1226,  1231,  1241,  1241,  1256,  1256,  1271,  1271,
    1282,  1287,  1295,  1295,  1301,  1301,  1307,  1307,  1313,  1313,
    1324,  1329,  1345,  1350,  1355,  1365,  1370,  1378,  1383,  1388,
    1393,  1398,  1403,  1408,  1413,  1418,  1424,  1429,  1437,  1445,
    1450,  1455,  1462,  1473,  1478,  1483,  1493,  1498,  1503,  1513,
    1518,  1534,  1539,  1555,  1560,  1565,  1575,  1580,  1585,  1592,
    1597,  1607,  1612,  1617,  1624,  1629,  1636,  1641,  1648,  1653,
    1663,  1668,  1673,  1681,  1686,  1691,  1698,  1703,  1713,  1718,
    1725,  1732,  1737,  1744,  1749,  1759,  1764,  1764,  1772,  1789,
    1789,  1794,  1794,  1799,  1804,  1804,  1814,  1819,  1827,  1833,
    1839,  1845,  1851,  1857,  1866,  1871,  1900,  1907,  1914,  1943,
    1972,  2002,  2035,  2040,  2064,  2070,  2076,  2082,  2088,  2088,
    2106,  2112,  2118,  2124,  2133,  2140,  2146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "THEN", "CONSTANTE_ENTERA_INT_TYPE",
  "CONSTANTE_ENTERA_UNSIGNED_INT_TYPE", "CONSTANTE_ENTERA_LONG_TYPE",
  "CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE", "CONSTANTE_REAL_FLOAT_TYPE",
  "CONSTANTE_REAL_LONG_DOUBLE_TYPE", "CONSTANTE_REAL_DOUBLE_TYPE",
  "LITERAL_CADENA", "\"typedef\"", "\"extern\"", "\"static\"", "\"auto\"",
  "\"register\"", "\"void\"", "\"char\"", "\"short\"", "\"int\"",
  "\"long\"", "\"float\"", "\"double\"", "\"signed\"", "\"unsigned\"",
  "\"const\"", "\"volatile\"", "\"struct\"", "\"union\"", "\"enum\"",
  "\"if\"", "\"else\"", "\"switch\"", "\"while\"", "\"do\"", "\"for\"",
  "\"case\"", "\"default\"", "\"goto\"", "\"continue\"", "\"break\"",
  "\"return\"", "\"sizeof\"", "IDENTIFICADOR", "NOMBRE_DE_TYPEDEF",
  "\"...\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"",
  "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"", "\"||\"", "\"&&\"", "\"==\"",
  "\"!=\"", "\">=\"", "\"<=\"", "\"<<\"", "\">>\"", "\"->\"", "\"++\"",
  "\"--\"", "';'", "','", "'='", "'{'", "'}'", "':'", "'('", "')'", "'['",
  "']'", "'*'", "'?'", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'",
  "'/'", "'%'", "'~'", "'!'", "'.'", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "declaration_list", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "type_qualifier", "struct_or_union_specifier", "$@1",
  "factorizacion_struct_or_union_specifier", "$@2", "$@3",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "$@4",
  "factorizacion_enum_specifier", "enumerator_list", "enumerator",
  "declarator", "direct_declarator", "$@5",
  "factorizacion_direct_declarator", "pointer", "$@6",
  "factorizacion_pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "statement", "labeled_statement", "$@7",
  "$@8", "$@9", "$@10", "expression_statement", "compound_statement",
  "$@11", "factorizacion_compound_statement", "statement_list",
  "selection_statement", "$@12", "$@13",
  "factorizacion_selection_statement", "iteration_statement", "$@14",
  "$@15", "$@16", "factorizacion_iteration_statement", "jump_statement",
  "$@17", "$@18", "$@19", "$@20", "factorizacion_jump_statement",
  "expression", "assignment_expression", "assignment_operator",
  "constant_expression", "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "$@21",
  "unary_expression", "$@22", "$@23", "$@24",
  "factorizacion_unary_expression", "unary_operator", "postfix_expression",
  "argument_expression_list", "primary_expression", "$@25",
  "constante_entera", "constante_real", 0
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
     315,   316,   317,   318,   319,   320,   321,   322,    59,    44,
      61,   123,   125,    58,    40,    41,    91,    93,    42,    63,
     124,    94,    38,    60,    62,    43,    45,    47,    37,   126,
      33,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   103,   103,   105,   104,   107,   106,   108,
     106,   106,   109,   109,   110,   110,   111,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   116,   115,   117,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   121,
     121,   122,   121,   123,   123,   123,   125,   124,   126,   126,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   132,   133,   133,   134,   134,
     135,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   137,   137,   137,   137,   139,   138,
     140,   138,   141,   138,   138,   142,   138,   143,   143,   145,
     144,   146,   146,   146,   146,   147,   147,   149,   148,   150,
     148,   151,   151,   151,   153,   152,   154,   152,   155,   152,
     156,   156,   158,   157,   159,   157,   160,   157,   161,   157,
     162,   162,   163,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   166,   167,
     167,   167,   167,   168,   168,   168,   169,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   173,   173,   173,   173,
     173,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     175,   175,   175,   176,   176,   176,   176,   176,   177,   177,
     177,   177,   177,   177,   177,   178,   179,   178,   180,   181,
     180,   182,   180,   180,   183,   180,   184,   184,   185,   185,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   186,   187,   187,   188,   188,   188,   188,   189,   188,
     190,   190,   190,   190,   191,   191,   191
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     4,     3,     3,     2,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     3,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     0,     4,     0,
       5,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       2,     1,     3,     1,     2,     3,     0,     3,     3,     4,
       1,     1,     3,     1,     3,     2,     1,     1,     3,     4,
       3,     0,     4,     2,     2,     1,     0,     3,     0,     1,
       1,     2,     1,     2,     1,     3,     1,     3,     2,     2,
       1,     1,     3,     1,     3,     4,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     0,     5,     2,     0,     4,     1,     2,     0,
       3,     1,     2,     2,     3,     1,     2,     0,     3,     0,
       6,     4,     6,     2,     0,     6,     0,     8,     0,     3,
       5,     6,     0,     4,     0,     3,     0,     3,     0,     3,
       1,     2,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     0,     5,     1,     0,
       3,     0,     3,     2,     0,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     1,     1,     1,     0,     4,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    30,    29,    28,    26,    27,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    43,    44,    52,    53,    66,
      77,    42,     0,    86,     0,     2,     4,     5,     0,    14,
      16,    18,    40,    45,    41,     0,    76,     0,     0,     0,
      88,     1,     3,    10,     0,    20,     0,    15,    17,    19,
       0,   139,    12,     0,     0,     9,    81,     0,    75,    70,
       0,    67,    78,    92,    90,    87,    89,    11,     0,    25,
       0,     0,     7,    51,    47,    46,     0,    13,     8,     0,
       0,   270,   271,   272,   273,   274,   276,   275,   267,   244,
     264,   239,   241,   268,    80,   249,   248,   250,   251,   252,
     253,     0,   188,   189,   193,   196,   199,   201,   203,   206,
     211,   220,   223,   228,   235,     0,   238,   254,   265,   266,
       0,    73,     0,    71,    93,    91,    22,    21,     0,    24,
     103,   175,   235,     6,    49,     0,   147,   149,   154,   156,
     158,     0,   135,   162,   164,   166,   168,   264,    42,   137,
     141,     0,   145,   122,   123,   124,   140,     0,   125,   126,
     127,     0,   172,   101,    85,   100,    82,     0,    94,    96,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,     0,   260,   261,
       0,     0,     0,     0,     0,     0,    68,   106,     0,   181,
     182,   178,   179,   180,   185,   187,   186,   183,   184,   177,
       0,     0,    57,    59,     0,    54,     0,     0,     0,     0,
       0,     0,   134,     0,     0,     0,     0,     0,     0,     0,
       0,   143,     0,   130,   142,   146,   138,     0,     0,     0,
      98,   110,    99,   111,    83,     0,     0,    84,   268,   246,
     245,   268,   240,   242,   108,     0,     0,   195,   194,     0,
       0,   198,   197,   200,   202,   205,   204,   208,   207,   210,
     209,   219,   218,   217,   216,   213,   212,   215,   214,   221,
     222,   225,   224,   227,   226,   230,   229,   232,   231,   234,
     233,   259,   256,   262,     0,     0,   258,    69,    74,    72,
       0,   104,   176,     0,    58,    60,    48,    55,     0,     0,
      61,    63,     0,   148,     0,     0,     0,     0,   159,     0,
       0,     0,   165,   167,   170,   169,     0,     0,     0,   144,
     174,   173,   118,     0,     0,   114,     0,   112,     0,     0,
      95,    97,   102,     0,     0,   110,   109,     0,   269,     0,
       0,     0,   257,   255,   105,   107,    50,    64,    56,     0,
       0,   153,     0,     0,     0,     0,     0,     0,   136,   163,
     171,   129,   131,   119,   113,   115,   120,     0,   116,     0,
     247,   237,   191,   192,   190,   263,    62,    65,     0,     0,
       0,     0,     0,   133,   121,   117,   151,   150,   155,     0,
       0,     0,     0,     0,   160,     0,   152,   157,   161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,    25,    26,    52,    53,    54,    44,    45,    29,
      30,    31,    32,    50,    75,   135,   221,    33,   224,   225,
     226,   319,   320,    34,    38,    61,   122,   123,    35,    36,
      80,   166,    37,    40,    65,    66,   343,   168,   169,   170,
     129,   208,   265,   344,   253,   152,   153,   239,   240,   233,
     234,   154,   155,    76,   156,   157,   158,   227,   228,   323,
     159,   229,   230,   231,   328,   160,   235,   236,   237,   238,
     335,   161,   162,   220,   101,   131,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   174,   132,   172,
     173,   171,   260,   115,   116,   304,   117,   175,   118,   119
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -305
static const yytype_int16 yypact[] =
{
    1484,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,    10,  -305,  1960,  -305,  -305,  -305,     7,  1222,
    1222,  1222,  -305,  -305,  -305,  2129,   -15,    -4,     5,   -23,
      -7,  -305,  -305,  -305,   136,  -305,  2027,  -305,  -305,  -305,
      47,  -305,  -305,  2129,     7,  -305,  -305,  1589,   -15,    25,
       3,  -305,  -305,  -305,  -305,  -305,    -7,  -305,    21,  -305,
    1633,  2129,  -305,    35,  -305,  -305,  1188,  -305,  -305,    40,
    2061,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  2216,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,     1,  -305,   -22,    59,    44,    68,   118,   109,    39,
     159,   158,   -32,  -305,  -305,  1872,    96,  -305,  -305,  -305,
       3,    95,   -36,  -305,  -305,  -305,  -305,  -305,  1633,  -305,
    -305,  -305,   165,  -305,  -305,  2245,  -305,  -305,  -305,  -305,
    -305,   273,  -305,  -305,  -305,  -305,  -305,   137,   153,  -305,
    -305,  1275,  -305,  -305,  -305,  -305,  -305,  1362,  -305,  -305,
    -305,   181,  -305,  -305,  -305,   100,  -305,   162,   189,  -305,
      28,  1881,  1925,  1925,  2245,  1872,  -305,   321,   365,   413,
    1872,  1872,   457,   505,   549,   597,   641,   689,   733,  1872,
    1872,   781,   825,   873,   917,   965,  -305,   216,  -305,  -305,
    1642,  1872,   221,    78,  1872,     3,  -305,  -305,    88,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    1872,  2245,  2245,  2245,  2158,  -305,     9,   193,   195,   196,
    1536,   212,  -305,  1872,   214,   244,   222,   223,  1686,   219,
     220,  -305,  1449,  -305,  -305,  -305,  -305,  1009,  1310,  1730,
    -305,   -16,  -305,   115,  -305,  1136,   245,  -305,  2245,  -305,
    -305,  -305,  -305,  -305,   160,   225,    29,  -305,    59,   228,
     106,  -305,    44,    68,   118,  -305,   109,  -305,    39,  -305,
      39,  -305,   159,  -305,   159,  -305,   159,  -305,   159,   158,
     158,  -305,   -32,  -305,   -32,  -305,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,    89,   -27,  -305,  -305,  -305,  -305,
    1545,  -305,  -305,  2187,  -305,  -305,  -305,  -305,  1872,   183,
    -305,   229,  1057,  -305,  1872,  1872,   260,  1774,  -305,   230,
    1536,   227,  -305,  -305,  -305,  -305,   185,  1536,  1536,  -305,
    -305,  -305,  -305,   231,   236,  -305,   237,   115,  2095,  1784,
    -305,  -305,  -305,   238,  1396,   155,  -305,  1872,  -305,  1872,
    1101,  1872,  -305,  -305,  -305,  -305,  -305,  -305,  -305,     9,
    1872,  -305,    98,   111,   113,   224,  1774,  1536,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,   246,  -305,   242,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  1536,  1536,
    1536,  1872,  1828,  -305,  -305,  -305,   264,  -305,  -305,   132,
    1536,   133,  1536,   255,  -305,  1536,  -305,  -305,  -305
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -305,  -305,   280,  -305,    15,    -3,     0,  -305,   256,  -305,
    -110,   -28,  -305,  -305,  -305,  -305,  -305,  -305,   112,  -208,
    -156,  -305,   -35,  -305,  -305,  -305,   215,   131,   -20,   -24,
    -305,  -305,   -39,  -305,  -305,  -305,   -77,  -305,    82,  -305,
    -118,  -305,    85,  -148,  -240,  -153,  -305,  -305,  -305,  -305,
    -305,  -304,    -9,  -305,  -305,   187,  -305,  -305,  -305,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,
    -305,  -169,   -49,  -305,  -159,   -50,  -305,   164,   163,   166,
     169,   170,    80,    54,    83,    84,  -101,  -305,   -52,  -305,
    -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305,  -305
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -237
static const yytype_int16 yytable[] =
{
      28,    64,    39,   167,   245,   114,   266,   102,    46,   270,
     207,   347,    63,    58,   196,    27,   317,   252,   264,    15,
      16,   130,   126,   376,    28,   222,    55,   125,    20,    47,
      48,    49,   305,   205,    79,   177,   206,    72,   124,    27,
      20,    69,   247,    71,    78,   308,   193,   121,    79,    59,
     363,    20,    62,    20,    20,   194,   195,   178,   248,    56,
     249,    57,   133,   114,   222,    20,   314,   315,    77,   336,
      22,    23,   402,   151,   329,    43,    60,   326,   176,   130,
     165,    22,   318,    22,    22,    23,    77,    23,    23,   245,
     346,    73,   296,   298,   300,    22,   120,   256,   247,    23,
     185,   186,   264,   257,   358,   317,   134,   223,   -23,   -23,
      70,   222,   222,   222,   222,   347,   356,   179,    74,   259,
     262,   263,   187,   188,   180,   114,   251,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,    20,   250,   223,   205,   222,   181,
     307,   303,   114,   372,   102,   373,   374,   310,   361,   367,
     311,   197,   198,   199,   362,   204,    77,   247,   183,   184,
     200,   312,   201,   398,   248,   247,   249,   378,    23,   360,
     247,   114,   247,   102,   381,   382,   399,   202,   400,   348,
     389,   349,   365,   223,   223,   223,   223,   114,   341,   102,
     182,   247,   247,   222,    67,    68,   321,   413,   415,   251,
    -128,   397,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   189,   190,   403,   355,  -130,    58,    39,   354,
     223,   249,   409,   411,   354,   219,   249,   254,    23,   282,
     284,   286,   288,   191,   192,   406,   407,   408,   165,   246,
     247,   368,   369,   380,   247,   165,   391,   414,   255,   416,
     301,   130,   418,   278,   280,   306,   114,   322,   102,   324,
     325,   387,   289,   290,   232,   292,   294,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,   223,   327,   330,   331,   352,
     332,   333,   337,   338,   375,   379,   412,   114,   401,   102,
     357,   359,   370,   377,    42,   114,   383,   114,   114,   392,
     394,   384,   395,   390,   385,   355,  -132,  -132,   114,   405,
     102,   404,   267,   417,   127,    81,    82,    83,    84,    85,
      86,    87,    88,   313,   396,   203,   309,   351,   242,  -132,
    -132,   268,   272,   353,     0,     0,   273,  -132,   165,   321,
     274,  -132,   276,     0,   165,  -132,     0,     0,  -132,  -132,
       0,     0,  -132,  -132,    89,    90,   269,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    95,
       0,     0,     0,    96,     0,     0,    97,    98,    89,    90,
      99,   100,     0,     0,   271,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    95,     0,     0,     0,    96,     0,     0,
      97,    98,     0,     0,    99,   100,    89,    90,   275,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    95,     0,     0,     0,    96,     0,     0,    97,    98,
      89,    90,    99,   100,     0,     0,   277,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    95,     0,     0,     0,    96,
       0,     0,    97,    98,     0,     0,    99,   100,    89,    90,
     279,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    95,     0,     0,     0,    96,     0,     0,
      97,    98,    89,    90,    99,   100,     0,     0,   281,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    95,     0,     0,
       0,    96,     0,     0,    97,    98,     0,     0,    99,   100,
      89,    90,   283,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    95,     0,     0,     0,    96,
       0,     0,    97,    98,    89,    90,    99,   100,     0,     0,
     285,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    95,
       0,     0,     0,    96,     0,     0,    97,    98,     0,     0,
      99,   100,    89,    90,   287,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    95,     0,     0,
       0,    96,     0,     0,    97,    98,    89,    90,    99,   100,
       0,     0,   291,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    95,     0,     0,     0,    96,     0,     0,    97,    98,
       0,     0,    99,   100,    89,    90,   293,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    95,
       0,     0,     0,    96,     0,     0,    97,    98,    89,    90,
      99,   100,     0,     0,   295,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    95,     0,     0,     0,    96,     0,     0,
      97,    98,     0,     0,    99,   100,    89,    90,   297,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,    95,     0,     0,     0,    96,     0,     0,    97,    98,
      89,    90,    99,   100,     0,     0,   299,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    95,     0,     0,     0,    96,
       0,     0,    97,    98,     0,     0,    99,   100,    89,    90,
     340,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,    95,     0,     0,     0,    96,     0,     0,
      97,    98,    89,    90,    99,   100,     0,     0,   371,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,    95,     0,     0,
       0,    96,     0,     0,    97,    98,     0,     0,    99,   100,
      89,    90,   393,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,    95,     0,     0,     0,    96,
       0,     0,    97,    98,    89,    90,    99,   100,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    91,    92,     0,
       0,     0,     0,     0,     0,    93,     0,     0,     0,    95,
       0,    21,   350,    96,     0,     0,    97,    98,     0,     0,
      99,   100,    81,    82,    83,    84,    85,    86,    87,    88,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,    89,   147,   148,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    91,    92,   149,     0,     0,    51,
     150,     0,    93,     0,     0,     0,    95,    21,     0,     0,
      96,     0,     0,    97,    98,     0,     0,    99,   100,    81,
      82,    83,    84,    85,    86,    87,    88,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   136,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,    89,   147,
     148,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    91,    92,   149,     0,     0,    51,   241,     0,    93,
       0,     0,     0,    95,    20,    21,     0,    96,     0,     0,
      97,    98,     0,     0,    99,   100,    81,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   342,   249,     0,    23,     0,
       0,     0,     0,   136,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,    89,   147,   243,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    91,    92,
     149,     0,     0,    51,   244,     0,    93,     0,     0,     0,
      95,    21,     0,     0,    96,     0,     0,    97,    98,     0,
       0,    99,   100,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     354,   342,   249,     0,    23,     0,     0,     0,     0,     0,
     136,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    89,   147,   243,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    91,    92,   149,     0,     0,
      51,   339,     0,    93,     0,     0,     0,    95,    20,    21,
       0,    96,     0,     0,    97,    98,     0,     0,    99,   100,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    22,     0,
       0,     0,    23,     0,     0,     0,     0,   136,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,    89,
     147,   243,     0,     0,     0,     0,     0,     0,    89,    90,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,     0,    91,    92,   149,     0,     0,    51,     0,     0,
      93,    91,    92,     0,    95,     0,   128,   364,    96,    93,
       0,    97,    98,    95,     0,    99,   100,    96,     0,     0,
      97,    98,    89,    90,    99,   100,     0,    81,    82,    83,
      84,    85,    86,    87,    88,     0,    81,    82,    83,    84,
      85,    86,    87,    88,     0,    91,    92,     0,     0,     0,
       0,     0,     0,    93,     0,     0,    94,    95,     0,     0,
       0,    96,     0,     0,    97,    98,    89,    90,    99,   100,
       0,     0,     0,     0,     0,    89,    90,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,     0,    91,
      92,     0,     0,     0,   128,     0,     0,    93,    91,    92,
       0,    95,     0,     0,     0,    96,    93,   302,    97,    98,
      95,     0,    99,   100,    96,     0,     0,    97,    98,    89,
      90,    99,   100,     0,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,   334,     0,     0,     0,     0,     0,
      93,     0,     0,     0,    95,     0,     0,     0,    96,     0,
       0,    97,    98,    89,    90,    99,   100,     0,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    91,    92,     0,     0,
       0,     0,     0,     0,    93,     0,     0,   345,    95,     0,
       0,     0,    96,     0,     0,    97,    98,    89,    90,    99,
     100,     0,     0,     0,     0,     0,     0,    89,    90,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      91,    92,   149,     0,     0,     0,     0,     0,    93,     0,
      91,    92,    95,     0,     0,     0,    96,     0,    93,    97,
      98,   388,    95,    99,   100,     0,    96,     0,     0,    97,
      98,    89,    90,    99,   100,     0,    81,    82,    83,    84,
      85,    86,    87,    88,     0,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    91,    92,     0,     0,     0,     0,
       0,     0,    93,   410,     0,     0,    95,     0,     0,     0,
      96,     0,     0,    97,    98,    89,    90,    99,   100,     0,
       0,     0,     0,     0,    89,    90,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    91,    92,
       0,     0,     0,     0,     0,     0,    93,    91,    92,     0,
      95,     0,     0,     0,    96,   258,     0,    97,    98,    95,
      41,    99,   100,    96,     0,     0,    97,    98,    89,    90,
      99,   100,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    91,    92,     0,     0,     0,     0,     0,     0,   261,
       0,     0,     0,    95,    20,    21,     0,    96,     0,     0,
      97,    98,     0,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    22,     0,     0,     0,    23,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,   -23,   -23,    70,    51,     0,
       0,     0,     0,     0,     0,   163,    21,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   164,     0,     0,     0,
      21,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,    21,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,    21,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     0,    21,  -236,  -236,  -236,  -236,  -236,  -236,  -236,
    -236,  -236,  -236,  -236,  -236,  -236,  -236,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   366,
       0,  -236,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21
};

static const yytype_int16 yycheck[] =
{
       0,    40,    22,    80,   157,    57,   175,    57,    28,   178,
     128,   251,    40,    37,   115,     0,   224,   165,   174,    26,
      27,    70,     1,   327,    24,   135,    35,    66,    44,    29,
      30,    31,   201,    69,    54,    57,    72,    46,    66,    24,
      44,     1,    69,    46,    53,   204,    78,    44,    68,    44,
      77,    44,    75,    44,    44,    87,    88,    79,    74,    74,
      76,    76,    71,   115,   174,    44,   222,   223,    53,   238,
      74,    78,   376,    76,   233,    68,    71,   230,    77,   128,
      80,    74,    73,    74,    74,    78,    71,    78,    78,   242,
     249,    44,   193,   194,   195,    74,    71,    69,    69,    78,
      61,    62,   258,    75,    75,   313,    71,   135,    68,    69,
      70,   221,   222,   223,   224,   355,   264,    58,    71,   171,
     172,   173,    83,    84,    80,   177,   165,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    44,   165,   174,    69,   258,    81,
      72,   200,   204,   322,   204,   324,   325,    69,    69,   318,
      72,    65,    66,    67,    75,    70,   151,    69,    59,    60,
      74,   220,    76,    75,    74,    69,    76,   330,    78,    73,
      69,   233,    69,   233,   337,   338,    75,    91,    75,    74,
     349,    76,   310,   221,   222,   223,   224,   249,   247,   249,
      82,    69,    69,   313,    68,    69,   226,    75,    75,   248,
      73,   370,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    63,    64,   377,   264,    73,   251,   248,    74,
     258,    76,   401,   402,    74,    70,    76,    75,    78,   185,
     186,   187,   188,    85,    86,   398,   399,   400,   248,    68,
      69,    68,    69,    68,    69,   255,   357,   410,    69,   412,
      44,   310,   415,   183,   184,    44,   318,    74,   318,    74,
      74,   348,   189,   190,     1,   191,   192,     4,     5,     6,
       7,     8,     9,    10,    11,   313,    74,    73,    44,    44,
      68,    68,    73,    73,    34,    68,    32,   349,    74,   349,
      75,    73,    73,    73,    24,   357,    75,   359,   360,   359,
     360,    75,   361,    75,    77,   354,    43,    44,   370,    77,
     370,    75,     1,    68,    68,     4,     5,     6,     7,     8,
       9,    10,    11,   221,   369,   120,   205,   255,   151,    66,
      67,   177,   179,   258,    -1,    -1,   180,    74,   348,   369,
     181,    78,   182,    -1,   354,    82,    -1,    -1,    85,    86,
      -1,    -1,    89,    90,    43,    44,     1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    86,    43,    44,
      89,    90,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,    86,    -1,    -1,    89,    90,    43,    44,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,    86,
      43,    44,    89,    90,    -1,    -1,     1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,
      -1,    -1,    85,    86,    -1,    -1,    89,    90,    43,    44,
       1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,    86,    43,    44,    89,    90,    -1,    -1,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    -1,    85,    86,    -1,    -1,    89,    90,
      43,    44,     1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,
      -1,    -1,    85,    86,    43,    44,    89,    90,    -1,    -1,
       1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    86,    -1,    -1,
      89,    90,    43,    44,     1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    -1,    85,    86,    43,    44,    89,    90,
      -1,    -1,     1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,    86,
      -1,    -1,    89,    90,    43,    44,     1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    82,    -1,    -1,    85,    86,    43,    44,
      89,    90,    -1,    -1,     1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,    86,    -1,    -1,    89,    90,    43,    44,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    82,    -1,    -1,    85,    86,
      43,    44,    89,    90,    -1,    -1,     1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,
      -1,    -1,    85,    86,    -1,    -1,    89,    90,    43,    44,
       1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,    -1,
      85,    86,    43,    44,    89,    90,    -1,    -1,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    -1,
      -1,    82,    -1,    -1,    85,    86,    -1,    -1,    89,    90,
      43,    44,     1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,
      -1,    -1,    85,    86,    43,    44,    89,    90,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,
      -1,    45,    46,    82,    -1,    -1,    85,    86,    -1,    -1,
      89,    90,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    66,    67,    68,    -1,    -1,    71,
      72,    -1,    74,    -1,    -1,    -1,    78,    45,    -1,    -1,
      82,    -1,    -1,    85,    86,    -1,    -1,    89,    90,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    66,    67,    68,    -1,    -1,    71,    72,    -1,    74,
      -1,    -1,    -1,    78,    44,    45,    -1,    82,    -1,    -1,
      85,    86,    -1,    -1,    89,    90,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    -1,    78,    -1,
      -1,    -1,    -1,    31,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    66,    67,
      68,    -1,    -1,    71,    72,    -1,    74,    -1,    -1,    -1,
      78,    45,    -1,    -1,    82,    -1,    -1,    85,    86,    -1,
      -1,    89,    90,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    66,    67,    68,    -1,    -1,
      71,    72,    -1,    74,    -1,    -1,    -1,    78,    44,    45,
      -1,    82,    -1,    -1,    85,    86,    -1,    -1,    89,    90,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    74,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    66,    67,    68,    -1,    -1,    71,    -1,    -1,
      74,    66,    67,    -1,    78,    -1,    71,    72,    82,    74,
      -1,    85,    86,    78,    -1,    89,    90,    82,    -1,    -1,
      85,    86,    43,    44,    89,    90,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,    -1,
      -1,    82,    -1,    -1,    85,    86,    43,    44,    89,    90,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    74,    66,    67,
      -1,    78,    -1,    -1,    -1,    82,    74,    75,    85,    86,
      78,    -1,    89,    90,    82,    -1,    -1,    85,    86,    43,
      44,    89,    90,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    82,    -1,
      -1,    85,    86,    43,    44,    89,    90,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    66,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,    -1,
      -1,    -1,    82,    -1,    -1,    85,    86,    43,    44,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      66,    67,    78,    -1,    -1,    -1,    82,    -1,    74,    85,
      86,    77,    78,    89,    90,    -1,    82,    -1,    -1,    85,
      86,    43,    44,    89,    90,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    -1,
      82,    -1,    -1,    85,    86,    43,    44,    89,    90,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    66,    67,    -1,
      78,    -1,    -1,    -1,    82,    74,    -1,    85,    86,    78,
       0,    89,    90,    82,    -1,    -1,    85,    86,    43,    44,
      89,    90,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    78,    44,    45,    -1,    82,    -1,    -1,
      85,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      45,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    45,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    45,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    45,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    45,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      44,    45,    74,    78,    93,    94,    95,    96,    98,   101,
     102,   103,   104,   109,   115,   120,   121,   124,   116,   120,
     125,     0,    94,    68,    99,   100,   120,    98,    98,    98,
     105,    71,    96,    97,    98,   144,    74,    76,   121,    44,
      71,   117,    75,   103,   124,   126,   127,    68,    69,     1,
      70,    97,   144,    44,    71,   106,   145,    96,   144,   120,
     122,     4,     5,     6,     7,     8,     9,    10,    11,    43,
      44,    66,    67,    74,    77,    78,    82,    85,    86,    89,
      90,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   180,   185,   186,   188,   190,   191,
      71,    44,   118,   119,   103,   124,     1,   100,    71,   132,
     164,   167,   180,   144,    71,   107,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    44,    45,    68,
      72,    97,   137,   138,   143,   144,   146,   147,   148,   152,
     157,   163,   164,    44,    75,    98,   123,   128,   129,   130,
     131,   183,   181,   182,   179,   189,    77,    57,    79,    58,
      80,    81,    82,    59,    60,    61,    62,    83,    84,    63,
      64,    85,    86,    78,    87,    88,   178,    65,    66,    67,
      74,    76,    91,   118,    70,    69,    72,   132,   133,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    70,
     165,   108,   102,   103,   110,   111,   112,   149,   150,   153,
     154,   155,     1,   141,   142,   158,   159,   160,   161,   139,
     140,    72,   147,    45,    72,   137,    68,    69,    74,    76,
     120,   124,   135,   136,    75,    69,    69,    75,    74,   180,
     184,    74,   180,   180,   112,   134,   163,     1,   169,     1,
     163,     1,   170,   171,   172,     1,   173,     1,   174,     1,
     174,     1,   175,     1,   175,     1,   175,     1,   175,   176,
     176,     1,   177,     1,   177,     1,   178,     1,   178,     1,
     178,    44,    75,   164,   187,   163,    44,    72,   166,   119,
      69,    72,   164,   110,   112,   112,    72,   111,    73,   113,
     114,   120,    74,   151,    74,    74,   137,    74,   156,   166,
      73,    44,    68,    68,    68,   162,   163,    73,    73,    72,
       1,   164,    75,   128,   135,    77,   166,   136,    74,    76,
      46,   130,    44,   134,    74,   124,   135,    75,    75,    73,
      73,    69,    75,    77,    72,   132,    72,   166,    68,    69,
      73,     1,   163,   163,   163,    34,   143,    73,   137,    68,
      68,   137,   137,    75,    75,    77,    75,   128,    77,   166,
      75,   178,   167,     1,   167,   164,   114,   166,    75,    75,
      75,    74,   143,   137,    75,    77,   137,   137,   137,   163,
      75,   163,    32,    75,   137,    75,   137,    68,   137
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
     `$$ = $1'.

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

/* Line 1464 of yacc.c  */
#line 247 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: translation_unit -> external_declaration \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(TRANSLATION_UNIT, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 252 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: translation_unit -> translation_unit external_declaration \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast), (yylsp[(2) - (2)])); (yyval.nodo_ast) = (yyvsp[(1) - (2)].nodo_ast);
			;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 260 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: external_declaration -> function_definition \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_external_declaration(TIPO_FUNCTION_DEFINITION, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 265 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: external_declaration -> declaration \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_external_declaration(TIPO_DECLARATION, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 273 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declaration_specifiers declarator declaration_list compound_statement \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast_function_definition((yyvsp[(1) - (4)].nodo_ast), (yyvsp[(2) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast), (yyvsp[(4) - (4)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 281 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declaration_specifiers declarator compound_statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast_function_definition((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(2) - (3)].nodo_ast), NULL, (yyvsp[(3) - (3)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 289 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declarator declaration_list compound_statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast_function_definition(NULL, (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(2) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 297 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declarator compound_statement \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast_function_definition(NULL, (yyvsp[(1) - (2)].nodo_ast), NULL, (yyvsp[(2) - (2)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 312 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration -> declaration_specifiers ';' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast(DECLARATION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 320 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration -> declaration_specifiers init_declarator_list ';' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast(DECLARATION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(2) - (3)].nodo_ast));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 331 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_list -> declaration \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(DECLARATION_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 336 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_list -> declaration_list declaration \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast), (yylsp[(2) - (2)])); (yyval.nodo_ast) = (yyvsp[(1) - (2)].nodo_ast);
			;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 344 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> storage_class_specifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 349 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> storage_class_specifier declaration_specifiers \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_inicio_de_lista_de_nodos_ast((yyvsp[(2) - (2)].nodo_ast), (yyvsp[(1) - (2)].nodo_ast), (yylsp[(1) - (2)])); (yyval.nodo_ast) = (yyvsp[(2) - (2)].nodo_ast);
			;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 354 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_specifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 359 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_specifier declaration_specifiers \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_inicio_de_lista_de_nodos_ast((yyvsp[(2) - (2)].nodo_ast), (yyvsp[(1) - (2)].nodo_ast), (yylsp[(1) - (2)])); (yyval.nodo_ast) = (yyvsp[(2) - (2)].nodo_ast);
			;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 364 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_qualifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 369 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_qualifier declaration_specifiers \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_inicio_de_lista_de_nodos_ast((yyvsp[(2) - (2)].nodo_ast), (yyvsp[(1) - (2)].nodo_ast), (yylsp[(1) - (2)])); (yyval.nodo_ast) = (yyvsp[(2) - (2)].nodo_ast);
			;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 377 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(INIT_DECLARATOR_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 382 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator_list ',' init_declarator \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 387 "src/TPI.y"
    {
			debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator_list ',' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: init_declarator_list \n", archivo_yyin, (yylsp[(3) - (3)]).first_line, (yylsp[(3) - (3)]).first_column); 
			yyerrok;
			agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), crear_nodo_ast_enumeracion_error(INIT_DECLARATOR_LIST, (yylsp[(3) - (3)]), NULL, NULL), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
		;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 397 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(INIT_DECLARATOR, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 402 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator '=' initializer \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(INIT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 407 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator error \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: init_declarator \n", archivo_yyin, (yylsp[(2) - (2)]).first_line, (yylsp[(2) - (2)]).first_column); 
				yyerrok;
				yyclearin;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(INIT_DECLARATOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, NULL);
			;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 418 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"auto\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_AUTO, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 423 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"register\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_REGISTER, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 428 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"static\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_STATIC, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 433 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"extern\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_EXTERN, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 438 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"typedef\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_TYPEDEF, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 446 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"void\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_VOID, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 452 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"char\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_CHAR, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 458 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"short\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_SHORT, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 464 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"int\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_INT, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 470 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"long\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_LONG, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 476 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"float\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_FLOAT, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 482 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"double\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_DOUBLE, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 488 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"signed\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_SIGNED, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 494 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"unsigned\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_UNSIGNED, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 500 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> struct_or_union_specifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_STRUCT_OR_UNION_SPECIFIER, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 506 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> enum_specifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_ENUM_SPECIFIER, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 512 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> NOMBRE_DE_TYPEDEF \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_specifier(TIPO_NOMBRE_DE_TYPEDEF, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 521 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier -> \"const\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_qualifier(TIPO_CONST, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 526 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier -> \"volatile\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_type_qualifier(TIPO_VOLATILE, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 533 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 534 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union_specifier -> struct_or_union {} factorizacion_struct_or_union_specifier \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);

				/*
				switch(*((int*) ($3 -> contenido)))
				{
					case DECLARACION_CON_TAG:
						//agregar_struct_or_union_a_estructura($1, (Simbolo*) ($3 -> hijoIzquierdo));

						Simbolo* resultadoBusqueda = buscarSimbolo(((Simbolo*) ($3 -> hijoIzquierdo)) -> nombreSimbolo, SEGUN_ETIQUETA);
						if((resultadoBusqueda != NULL) && ((resultadoBusqueda -> alcanceSimbolo) == alcanceActual))
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: redefinicion de '%s %s' \n", archivo_yyin, @1.first_line, @1.first_column, struct_o_union(((Estructura*) (((Simbolo*) ($3 -> hijoIzquierdo) ) -> simbolo)) -> struct_o_union), (((Simbolo*) $3 -> hijoIzquierdo) -> nombreSimbolo));
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: originalmente definida alli \n", archivo_yyin, resultadoBusqueda->ubicacionSimbolo.first_line, resultadoBusqueda->ubicacionSimbolo.first_column, $1);
							cantidadErroresSemanticos++;
						}
					break;
					case DECLARACION_SIN_TAG:
						//agregar_struct_or_union_a_estructura($1, (Simbolo*) ($3 -> hijoIzquierdo));
					break;
					case USO_POR_TAG:
						if((((Estructura*) ((Simbolo*) ($3 -> hijoIzquierdo)) -> simbolo) -> struct_o_union) != $1)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' definido como tipo incorrecto de tag \n", archivo_yyin, @1.first_line, @1.first_column, ((Simbolo*) ($3 -> hijoIzquierdo)) -> nombreSimbolo);
							cantidadErroresSemanticos++;
						}
					break;
				}
				*/

				((Nodo_Struct_or_Union_Specifier*) ((yyvsp[(3) - (3)].nodo_ast) -> contenido)) -> struct_o_union = (yyvsp[(1) - (3)].struct_o_union);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 571 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = TRUE; ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 572 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> '{' {} struct_declaration_list '}' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column);
				//agregar_tag_a_estructura(NULL, (Simbolo*) ($3 -> contenido));
				(yyval.nodo_ast) = crear_nodo_ast_struct_or_union_specifier(NULL, (yyvsp[(3) - (4)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}));
			;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 577 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = TRUE; ;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 578 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> IDENTIFICADOR '{' {} struct_declaration_list '}' \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
				//agregar_tag_a_estructura($1, (Simbolo*) ($4 -> contenido));
				(yyval.nodo_ast) = crear_nodo_ast_struct_or_union_specifier((Nodo_AST*) (yyvsp[(1) - (5)].char_pointer_type), (yyvsp[(4) - (5)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}));
			;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 584 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				/*
				Simbolo* resultadoBusqueda = buscarSimbolo($1, SEGUN_ETIQUETA);
				if(resultadoBusqueda == NULL)
				{
					error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, $1);
					cantidadErroresSemanticos++;
				}
				*/
				(yyval.nodo_ast) = crear_nodo_ast_struct_or_union_specifier((Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL, (yylsp[(1) - (1)]));
			;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 600 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union -> \"struct\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.struct_o_union) = STRUCT;
			;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 605 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union -> \"union\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.struct_o_union) = UNION;
			;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 613 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration_list -> struct_declaration \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(STRUCT_DECLARATION_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 618 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration_list -> struct_declaration_list struct_declaration \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast), (yylsp[(2) - (2)])); (yyval.nodo_ast) = (yyvsp[(1) - (2)].nodo_ast);
			;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 626 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration -> specifier_qualifier_list struct_declarator_list ';' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast(STRUCT_DECLARATION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(2) - (3)].nodo_ast));
			;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 635 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_specifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(SPECIFIER_QUALIFIER_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 640 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_specifier specifier_qualifier_list \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_inicio_de_lista_de_nodos_ast((yyvsp[(2) - (2)].nodo_ast), (yyvsp[(1) - (2)].nodo_ast), (yylsp[(1) - (2)])); (yyval.nodo_ast) = (yyvsp[(2) - (2)].nodo_ast);
			;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 645 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_qualifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(SPECIFIER_QUALIFIER_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 650 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_qualifier specifier_qualifier_list \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_inicio_de_lista_de_nodos_ast((yyvsp[(2) - (2)].nodo_ast), (yyvsp[(1) - (2)].nodo_ast), (yylsp[(1) - (2)])); (yyval.nodo_ast) = (yyvsp[(2) - (2)].nodo_ast);
			;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 658 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator_list -> struct_declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(STRUCT_DECLARATOR_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 663 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator_list -> struct_declarator_list ',' struct_declarator \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 671 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(STRUCT_DECLARATOR, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 676 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> ':' constant_expression \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(STRUCT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 681 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> declarator ':' constant_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(STRUCT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 688 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 689 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enum_specifier -> \"enum\" {} factorizacion_enum_specifier \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 699 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> '{' enumerator_list '}' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				//agregar_tag_a_enumeracion(NULL, (Simbolo*) ($2 -> contenido));
				(yyval.nodo_ast) = crear_nodo_ast(ENUM_SPECIFIER, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, (yyvsp[(2) - (3)].nodo_ast));
			;}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 705 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> IDENTIFICADOR '{' enumerator_list '}' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				//agregar_tag_a_enumeracion($1, (Simbolo*) ($3 -> contenido));
				(yyval.nodo_ast) = crear_nodo_ast(ENUM_SPECIFIER, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (Nodo_AST*) (yyvsp[(1) - (4)].char_pointer_type), (yyvsp[(3) - (4)].nodo_ast));
			;}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 711 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				/*
				Simbolo* resultadoBusqueda = buscarSimbolo($1, SEGUN_ETIQUETA);
				if(resultadoBusqueda == NULL)
				{
					error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, $1);
					cantidadErroresSemanticos++;
				}
				*/
				(yyval.nodo_ast) = crear_nodo_ast(ENUM_SPECIFIER, NULL, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 727 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator_list -> enumerator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(ENUMERATOR_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 732 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator_list -> enumerator_list ',' enumerator \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 740 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(ENUMERATOR, NULL, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 745 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator -> IDENTIFICADOR '=' constant_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(ENUMERATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (Nodo_AST*) (yyvsp[(1) - (3)].char_pointer_type), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 753 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declarator -> pointer direct_declarator \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(DECLARATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 758 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declarator -> direct_declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(DECLARATOR, NULL, (yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].nodo_ast));
			;}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 766 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_IDENTIFICADOR, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 772 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> '(' declarator ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_DECLARATOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(2) - (3)].nodo_ast), NULL);
			;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 777 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '[' constant_expression ']' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(1) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast));
			;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 782 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '[' ']' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), NULL);
			;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 786 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = TRUE; ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 787 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '(' {} factorizacion_direct_declarator \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyvsp[(4) - (4)].nodo_ast) -> hijoIzquierdo = (yyvsp[(1) - (4)].nodo_ast);
				((yyvsp[(4) - (4)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (4)]).first_line;
				((yyvsp[(4) - (4)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (4)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(4) - (4)].nodo_ast);
			;}
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 798 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> parameter_type_list ')' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, (yyvsp[(1) - (2)].nodo_ast));
			;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 804 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> identifier_list ')' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, (yyvsp[(1) - (2)].nodo_ast));
			;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 810 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> ')' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 818 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 819 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: pointer -> '*' {} factorizacion_pointer \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				if((((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line == -1) && (((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column == -1) && (((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).last_line == -1) && (((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).last_column == -1))
				{
					(yyvsp[(3) - (3)].nodo_ast) -> ubicacion = (yylsp[(1) - (3)]);
				}
				else
				{
					((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
					((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				}
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 836 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bis%cn: Reduciendo por la regla: factorizacion_pointer -> (Epsilon) \n", 'o');
				(yyval.nodo_ast) = crear_nodo_ast(POINTER, NULL, ((struct Ubicacion) {.first_line = -1, .first_column = -1, .last_line = -1, .last_column = -1}), NULL, NULL);
			;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 841 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> type_qualifier_list \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(POINTER, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 846 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> pointer \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(POINTER, NULL, (yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].nodo_ast));
			;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 851 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> type_qualifier_list pointer \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(POINTER, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 859 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier_list -> type_qualifier \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(TYPE_QUALIFIER_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 864 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier_list -> type_qualifier_list type_qualifier \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast), (yylsp[(2) - (2)])); (yyval.nodo_ast) = (yyvsp[(1) - (2)].nodo_ast);
			;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 872 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_type_list -> parameter_list \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_parameter_type_list(SIN_ELIPSIS, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 877 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_type_list -> parameter_list ',' \"...\" \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_parameter_type_list(CON_ELIPSIS, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), NULL);
			;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 885 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_list -> parameter_declaration \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(PARAMETER_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 891 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_list -> parameter_list ',' parameter_declaration \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 900 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers declarator \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_DECLARATOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 905 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers abstract_declarator \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 910 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_EPSILON, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 918 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: identifier_list -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(IDENTIFIER_LIST, (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), (yylsp[(1) - (1)]));
			;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 924 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: identifier_list -> identifier_list ',' IDENTIFICADOR \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (Nodo_AST*) (yyvsp[(3) - (3)].char_pointer_type), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 932 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> assignment_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_ASSIGNMENT_EXPRESSION, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 937 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> '{' initializer_list '}' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_INITIALIZER_LIST, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(2) - (3)].nodo_ast), NULL);
			;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 942 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> '{' initializer_list ',' '}' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_INITIALIZER_LIST, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(2) - (4)].nodo_ast), NULL);
			;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 950 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer_list -> initializer \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(INITIALIZER_LIST, (Nodo_AST*) (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 955 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer_list -> initializer_list ',' initializer \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 963 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_name -> specifier_qualifier_list \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(TYPE_NAME, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 968 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_name -> specifier_qualifier_list abstract_declarator \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(TYPE_NAME, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 976 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> pointer \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 981 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> direct_abstract_declarator \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, (yylsp[(1) - (1)]), NULL, (yyvsp[(1) - (1)].nodo_ast));
			;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 986 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> pointer direct_abstract_declarator \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast));
			;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 994 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' abstract_declarator ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ABSTRACT_DECLARATOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(2) - (3)].nodo_ast), NULL);
			;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 999 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '[' ']' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, NULL);
			;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 1004 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '[' constant_expression ']' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, (yyvsp[(2) - (3)].nodo_ast));
			;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 1009 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '[' ']' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), NULL);
			;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 1014 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '[' constant_expression ']' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(1) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast));
			;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 1019 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' ')' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, NULL);
			;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 1024 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' parameter_type_list ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, (yyvsp[(2) - (3)].nodo_ast));
			;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 1029 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '(' ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), NULL);
			;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 1034 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '(' parameter_type_list ')' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(1) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast));
			;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 1053 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> labeled_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_LABELED_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 1058 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> expression_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_EXPRESSION_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 1063 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> compound_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_COMPOUND_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 1068 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> selection_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_SELECTION_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 126:

/* Line 1464 of yacc.c  */
#line 1073 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> iteration_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_ITERATION_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 1078 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> jump_statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_statement(TIPO_JUMP_STATEMENT, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 1085 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 1086 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> IDENTIFICADOR {} ':' statement \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_labeled_statement(LABEL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (Nodo_AST*) (yyvsp[(1) - (4)].char_pointer_type), (yyvsp[(4) - (4)].nodo_ast));
			;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 1091 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 1092 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> NOMBRE_DE_TYPEDEF {} ':' statement \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_labeled_statement(LABEL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (Nodo_AST*) (yyvsp[(1) - (4)].char_pointer_type), (yyvsp[(4) - (4)].nodo_ast));
			;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 1097 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 133:

/* Line 1464 of yacc.c  */
#line 1098 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"case\" {} constant_expression ':' statement \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_labeled_statement(CASE, ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}), (yyvsp[(3) - (5)].nodo_ast), (yyvsp[(5) - (5)].nodo_ast));
			;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 1104 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"case\" error \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: labeled_statement \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(LABELED_STATEMENT, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, NULL);
		;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 1110 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 1111 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"default\" {} ':' statement \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_labeled_statement(DEFAULT, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(4) - (4)].nodo_ast), NULL);
			;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 1120 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression_statement -> ';' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de expresion \n", archivo_yyin, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast(EXPRESSION_STATEMENT, NULL, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 1127 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression_statement -> expression ';' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de expresion \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast(EXPRESSION_STATEMENT, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
			;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 1136 "src/TPI.y"
    {
			incrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual incrementado en 1: %d \n", alcanceActual);
			bandera_podria_usarse_un_nombre_de_typedef = TRUE;
		;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 1141 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: compound_statement -> '{' {} factorizacion_compound_statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia compuesta \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1152 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> '}' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast(COMPOUND_STATEMENT, NULL, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1159 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> statement_list '}' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, (yyvsp[(1) - (2)].nodo_ast));
			;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 1166 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> declaration_list '}' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
			;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 1173 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> declaration_list statement_list '}' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(2) - (3)].nodo_ast));
			;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 1183 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement_list -> statement \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(STATEMENT_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 146:

/* Line 1464 of yacc.c  */
#line 1188 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement_list -> statement_list statement \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (2)].nodo_ast), (yyvsp[(2) - (2)].nodo_ast), (yylsp[(2) - (2)])); (yyval.nodo_ast) = (yyvsp[(1) - (2)].nodo_ast);
			;}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1195 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 148:

/* Line 1464 of yacc.c  */
#line 1196 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_statement -> \"if\" {} factorizacion_selection_statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de seleccion \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 149:

/* Line 1464 of yacc.c  */
#line 1203 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 150:

/* Line 1464 of yacc.c  */
#line 1204 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_statement -> \"switch\" {} '(' expression ')' statement \n", (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yylsp[(6) - (6)]).last_line, (yylsp[(6) - (6)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de seleccion \n", archivo_yyin, (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_selection_statement(SWITCH, ((struct Ubicacion) {.first_line = (yylsp[(1) - (6)]).first_line, .first_column = (yylsp[(1) - (6)]).first_column, .last_line = (yylsp[(6) - (6)]).last_line, .last_column = (yylsp[(6) - (6)]).last_column}), (yyvsp[(4) - (6)].nodo_ast), (yyvsp[(6) - (6)].nodo_ast));
			;}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1222 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_selection_statement -> '(' expression ')' statement \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_if((yyvsp[(2) - (4)].nodo_ast), (yyvsp[(4) - (4)].nodo_ast), NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}));
			;}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1227 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_selection_statement -> '(' expression ')' statement \"else\" statement \n", (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yylsp[(6) - (6)]).last_line, (yylsp[(6) - (6)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_if((yyvsp[(2) - (6)].nodo_ast), (yyvsp[(4) - (6)].nodo_ast), (yyvsp[(6) - (6)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (6)]).first_line, .first_column = (yylsp[(1) - (6)]).first_column, .last_line = (yylsp[(6) - (6)]).last_line, .last_column = (yylsp[(6) - (6)]).last_column}));
			;}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1232 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_stateme -> '(' error \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: selection_statement \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(SELECTION_STATEMENT, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), NULL, NULL);
		;}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1241 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1242 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"while\" {} '(' expression ')' statement \n", (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yylsp[(6) - (6)]).last_line, (yylsp[(6) - (6)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_iteration_statement(WHILE, ((struct Ubicacion) {.first_line = (yylsp[(1) - (6)]).first_line, .first_column = (yylsp[(1) - (6)]).first_column, .last_line = (yylsp[(6) - (6)]).last_line, .last_column = (yylsp[(6) - (6)]).last_column}), (yyvsp[(4) - (6)].nodo_ast), (yyvsp[(6) - (6)].nodo_ast));
			;}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1256 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1257 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"do\" {} statement \"while\" '(' expression ')' ';' \n", (yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column, (yylsp[(8) - (8)]).last_line, (yylsp[(8) - (8)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, (yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_iteration_statement(DO_WHILE, ((struct Ubicacion) {.first_line = (yylsp[(1) - (8)]).first_line, .first_column = (yylsp[(1) - (8)]).first_column, .last_line = (yylsp[(6) - (8)]).last_line, .last_column = (yylsp[(6) - (8)]).last_column}), (yyvsp[(3) - (8)].nodo_ast), (yyvsp[(6) - (8)].nodo_ast));
			;}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1271 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1272 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"for\" {} '(' expression_statement expression_statement ')' statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1283 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_iteration_statement -> '(' expression_statement expression_statement ')' statement \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_for((yyvsp[(2) - (5)].nodo_ast), (yyvsp[(3) - (5)].nodo_ast), NULL, (yyvsp[(5) - (5)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}));
			;}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1288 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_iteration_statement -> '(' expression_statement expression_statement expression ')' statement \n", (yylsp[(1) - (6)]).first_line, (yylsp[(1) - (6)]).first_column, (yylsp[(6) - (6)]).last_line, (yylsp[(6) - (6)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_for((yyvsp[(2) - (6)].nodo_ast), (yyvsp[(3) - (6)].nodo_ast), (yyvsp[(4) - (6)].nodo_ast), (yyvsp[(6) - (6)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (6)]).first_line, .first_column = (yylsp[(1) - (6)]).first_column, .last_line = (yylsp[(6) - (6)]).last_line, .last_column = (yylsp[(6) - (6)]).last_column}));
			;}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1295 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1296 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"goto\" {} IDENTIFICADOR ';' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_jump_statement(GOTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (Nodo_AST*) (yyvsp[(3) - (4)].char_pointer_type), NULL);
			;}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1301 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1302 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"continue\" {} ';' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_jump_statement(CONTINUE, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
			;}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1307 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1308 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"break\" {} ';' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_jump_statement(BREAK, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
			;}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 1313 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 1314 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"return\" {} factorizacion_jump_statement \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 1325 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_jump_statement -> ';' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_jump_statement(RETURN, (yylsp[(1) - (1)]), NULL, NULL);
			;}
    break;

  case 171:

/* Line 1464 of yacc.c  */
#line 1330 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_jump_statement -> expression ';' \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_jump_statement(RETURN, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
			;}
    break;

  case 172:

/* Line 1464 of yacc.c  */
#line 1346 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression -> assignment_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(EXPRESSION, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 173:

/* Line 1464 of yacc.c  */
#line 1351 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression -> expression ',' assignment_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1356 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  expression ',' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 175:

/* Line 1464 of yacc.c  */
#line 1366 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_expression -> conditional_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 1371 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_expression -> unary_expression assignment_operator assignment_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_assignment_expression((yyvsp[(2) - (3)].tipoAssignment_Expression), ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 177:

/* Line 1464 of yacc.c  */
#line 1379 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> '=' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = IGUAL;
			;}
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1384 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"*=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = POR_IGUAL;
			;}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1389 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"/=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = DIVIDIDO_IGUAL;
			;}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 1394 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"%%=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = MOD_IGUAL;
			;}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 1399 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"+=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = MAS_IGUAL;
			;}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1404 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"-=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = MENOS_IGUAL;
			;}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 1409 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"<<=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA;
			;}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 1414 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \">>=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = ASIGNACION_CON_DESPLAZAMIENTO_DERECHA;
			;}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1419 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"&=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				
				(yyval.tipoAssignment_Expression) = AND_IGUAL;
			;}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1425 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"^=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = XOR_IGUAL;
			;}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1430 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"|=\" \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.tipoAssignment_Expression) = OR_IGUAL;
			;}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1438 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constant_expression -> conditional_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(CONSTANT_EXPRESSION, NULL, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1446 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: conditional_expression -> logical_or_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1451 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: conditional_expression -> logical_or_expression '?' expression ':' conditional_expression \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_conditional_expression((yyvsp[(1) - (5)].nodo_ast), (yyvsp[(3) - (5)].nodo_ast), (yyvsp[(5) - (5)].nodo_ast), ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}));
			;}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1456 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression '?' error ':' conditional_expression error \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(CONDITIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}), NULL, NULL);
		;}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1463 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression '?' expression ':'  error \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(CONDITIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}), NULL, NULL);
		;}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1474 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression -> logical_and_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1479 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression -> logical_or_expression \"||\" logical_and_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(LOGICAL_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1484 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  logical_or_expression \"||\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(LOGICAL_OR_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 196:

/* Line 1464 of yacc.c  */
#line 1494 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_and_expression -> inclusive_or_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 197:

/* Line 1464 of yacc.c  */
#line 1499 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_and_expression -> logical_and_expression \"&&\" inclusive_or_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(LOGICAL_AND_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 198:

/* Line 1464 of yacc.c  */
#line 1504 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression \"&&\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_and_expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(LOGICAL_AND_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 199:

/* Line 1464 of yacc.c  */
#line 1514 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: inclusive_or_expression -> exclusive_or_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 200:

/* Line 1464 of yacc.c  */
#line 1519 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(INCLUSIVE_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 201:

/* Line 1464 of yacc.c  */
#line 1535 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: exclusive_or_expression -> and_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 202:

/* Line 1464 of yacc.c  */
#line 1540 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: exclusive_or_expression -> exclusive_or_expression '^' and_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(EXCLUSIVE_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 203:

/* Line 1464 of yacc.c  */
#line 1556 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> equality_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 204:

/* Line 1464 of yacc.c  */
#line 1561 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> and_expression '&' equality_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(AND_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 205:

/* Line 1464 of yacc.c  */
#line 1566 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> and_expression '&' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: and_expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(AND_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 206:

/* Line 1464 of yacc.c  */
#line 1576 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> relational_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 207:

/* Line 1464 of yacc.c  */
#line 1581 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> equality_expression \"==\" relational_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_equality_expression(IGUALDAD, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 208:

/* Line 1464 of yacc.c  */
#line 1586 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: equallity_expression -> equality_expression \"==\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: equality_expression \"==\"  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(EQUALITY_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 209:

/* Line 1464 of yacc.c  */
#line 1593 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> equality_expression \"!=\" relational_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_equality_expression(DIFERENCIA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 210:

/* Line 1464 of yacc.c  */
#line 1598 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: equallity_expression -> equality_expression \"!=\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: equality_expression \"!=\"  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(EQUALITY_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 211:

/* Line 1464 of yacc.c  */
#line 1608 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> shift_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 212:

/* Line 1464 of yacc.c  */
#line 1613 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '<' shift_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_relational_expression(MENOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 213:

/* Line 1464 of yacc.c  */
#line 1618 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '<' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression '<'  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 214:

/* Line 1464 of yacc.c  */
#line 1625 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '>' shift_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_relational_expression(MAYOR, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1630 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '>' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression '>'  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1637 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression \"<=\" shift_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_relational_expression(MENOR_O_IGUAL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1642 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> error \"<=\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression \"<=\"  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1649 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression \">=\" shift_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_relational_expression(MAYOR_O_IGUAL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1654 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> error \">=\" error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression \"!=\"  \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1664 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> additive_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1669 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> shift_expression \"<<\" additive_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_shift_expression(DESPLAZAMIENTO_IZQUIERDA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1674 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> shift_expression \">>\" additive_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_shift_expression(DESPLAZAMIENTO_DERECHA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1682 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> multiplicative_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1687 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> additive_expression '+' multiplicative_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_additive_expression(SUMA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1692 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression '+' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(ADDITIVE_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1699 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> additive_expression '-' multiplicative_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_additive_expression(RESTA, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1704 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  additive_expression '-' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(ADDITIVE_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1714 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> cast_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1719 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '*' cast_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_multiplicative_expression(MULTIPLICACION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1726 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '*' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 231:

/* Line 1464 of yacc.c  */
#line 1733 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '/' cast_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_multiplicative_expression(DIVISION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 232:

/* Line 1464 of yacc.c  */
#line 1738 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '/' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 233:

/* Line 1464 of yacc.c  */
#line 1745 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '%%' cast_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_multiplicative_expression(RESTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast));
			;}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1750 "src/TPI.y"
    {
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '%%' error \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
			yyerrok;
			(yyval.nodo_ast) = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), NULL, NULL);
		;}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1760 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: cast_expression -> unary_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1764 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = TRUE; ;}
    break;

  case 237:

/* Line 1464 of yacc.c  */
#line 1765 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: cast_expression -> '(' {} type_name ')' cast_expression \n", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(5) - (5)]).last_line, (yylsp[(5) - (5)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast(CAST_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = (yylsp[(1) - (5)]).first_line, .first_column = (yylsp[(1) - (5)]).first_column, .last_line = (yylsp[(5) - (5)]).last_line, .last_column = (yylsp[(5) - (5)]).last_column}), (yyvsp[(3) - (5)].nodo_ast), (yyvsp[(5) - (5)].nodo_ast));
			;}
    break;

  case 238:

/* Line 1464 of yacc.c  */
#line 1773 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> postfix_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				if(((yyvsp[(1) - (1)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (1)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (1)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (char*) ((yyvsp[(1) - (1)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
					}
				}
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 239:

/* Line 1464 of yacc.c  */
#line 1789 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 240:

/* Line 1464 of yacc.c  */
#line 1790 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"++\" {} unary_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_unary_expression(PREINCREMENTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(3) - (3)].nodo_ast), NULL);
			;}
    break;

  case 241:

/* Line 1464 of yacc.c  */
#line 1794 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 242:

/* Line 1464 of yacc.c  */
#line 1795 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"--\" {} unary_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_unary_expression(PREDECREMENTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(3) - (3)].nodo_ast), NULL);
			;}
    break;

  case 243:

/* Line 1464 of yacc.c  */
#line 1800 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> unary_operator cast_expression \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_unary_expression((yyvsp[(1) - (2)].tipoUnary_Expression), ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(2) - (2)].nodo_ast), NULL);
			;}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1804 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = TRUE; ;}
    break;

  case 245:

/* Line 1464 of yacc.c  */
#line 1805 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"sizeof\" {} factorizacion_unary_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_line = (yylsp[(1) - (3)]).first_line;
				((yyvsp[(3) - (3)].nodo_ast) -> ubicacion).first_column = (yylsp[(1) - (3)]).first_column;
				(yyval.nodo_ast) = (yyvsp[(3) - (3)].nodo_ast);
			;}
    break;

  case 246:

/* Line 1464 of yacc.c  */
#line 1815 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_unary_expression -> unary_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_unary_expression(SIZEOF, (yylsp[(1) - (1)]), (yyvsp[(1) - (1)].nodo_ast), NULL);
			;}
    break;

  case 247:

/* Line 1464 of yacc.c  */
#line 1820 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_unary_expression -> '(' {} type_name ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_unary_expression(SIZEOF, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(2) - (3)].nodo_ast), NULL);
			;}
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1828 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '&' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = REFERENCIACION;
			;}
    break;

  case 249:

/* Line 1464 of yacc.c  */
#line 1834 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '*' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = DESREFERENCIACION;
			;}
    break;

  case 250:

/* Line 1464 of yacc.c  */
#line 1840 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '+' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = SIGNO_MAS;
			;}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1846 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '-' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = SIGNO_MENOS;
			;}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1852 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '~' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = COMPLEMENTO;
			;}
    break;

  case 253:

/* Line 1464 of yacc.c  */
#line 1858 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '!' \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.tipoUnary_Expression) = NEGACION_LOGICA;
			;}
    break;

  case 254:

/* Line 1464 of yacc.c  */
#line 1867 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> primary_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 255:

/* Line 1464 of yacc.c  */
#line 1872 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '[' expression ']' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				if(((yyvsp[(1) - (4)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (4)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (4)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (char*) ((yyvsp[(1) - (4)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								// FALTA EXPANDIR ACÁ
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: el valor suscrito no es ni un arreglo, ni un puntero ni un vector \n", archivo_yyin, (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
						cantidadErroresSemanticos++;
					}
				}
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(REFERENCIA_INDEXADA_ARREGLO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(1) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast));
			;}
    break;

  case 256:

/* Line 1464 of yacc.c  */
#line 1901 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '(' ')' \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(INVOCACION_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), NULL);
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 257:

/* Line 1464 of yacc.c  */
#line 1908 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '(' argument_expression_list ')' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(INVOCACION_FUNCION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (4)]).first_line, .first_column = (yylsp[(1) - (4)]).first_column, .last_line = (yylsp[(4) - (4)]).last_line, .last_column = (yylsp[(4) - (4)]).last_column}), (yyvsp[(1) - (4)].nodo_ast), (yyvsp[(3) - (4)].nodo_ast));
				//imprimir_ast_postorden($$);
				resolver_ast((yyval.nodo_ast));
			;}
    break;

  case 258:

/* Line 1464 of yacc.c  */
#line 1915 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '.' IDENTIFICADOR \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				if(((yyvsp[(1) - (3)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (3)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (3)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (char*) ((yyvsp[(1) - (3)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								// FALTA EXPANDIR ACÁ
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: tipo de argumento invalido de '.' \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
						cantidadErroresSemanticos++;
					}
				}
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (Nodo_AST*) (yyvsp[(3) - (3)].char_pointer_type));
			;}
    break;

  case 259:

/* Line 1464 of yacc.c  */
#line 1944 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"->\" IDENTIFICADOR \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				if(((yyvsp[(1) - (3)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (3)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (3)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (char*) ((yyvsp[(1) - (3)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								// FALTA EXPANDIR ACÁ
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: tipo de argumento invalido de '->' \n", archivo_yyin, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
						cantidadErroresSemanticos++;
					}
				}
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION, ((struct Ubicacion) {.first_line = (yylsp[(1) - (3)]).first_line, .first_column = (yylsp[(1) - (3)]).first_column, .last_line = (yylsp[(3) - (3)]).last_line, .last_column = (yylsp[(3) - (3)]).last_column}), (yyvsp[(1) - (3)].nodo_ast), (Nodo_AST*) (yyvsp[(3) - (3)].char_pointer_type));
			;}
    break;

  case 260:

/* Line 1464 of yacc.c  */
#line 1973 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"++\" \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				if(((yyvsp[(1) - (2)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (2)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
								cantidadErroresSemanticos++;
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
						cantidadErroresSemanticos++;
					}
				}
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(POSTINCREMENTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
			;}
    break;

  case 261:

/* Line 1464 of yacc.c  */
#line 2003 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"--\" \n", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column);
				if(((yyvsp[(1) - (2)].nodo_ast) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((yyvsp[(1) - (2)].nodo_ast) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
								cantidadErroresSemanticos++;
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (char*) ((yyvsp[(1) - (2)].nodo_ast) -> hijoIzquierdo));
						cantidadErroresSemanticos++;
					}
				}
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_postfix_expression(POSTDECREMENTO, ((struct Ubicacion) {.first_line = (yylsp[(1) - (2)]).first_line, .first_column = (yylsp[(1) - (2)]).first_column, .last_line = (yylsp[(2) - (2)]).last_line, .last_column = (yylsp[(2) - (2)]).last_column}), (yyvsp[(1) - (2)].nodo_ast), NULL);
			;}
    break;

  case 262:

/* Line 1464 of yacc.c  */
#line 2036 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> assignment_expression \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				(yyval.nodo_ast) = crear_lista_de_nodos_ast(ARGUMENT_EXPRESSION_LIST, (yyvsp[(1) - (1)].nodo_ast), (yylsp[(1) - (1)]));
			;}
    break;

  case 263:

/* Line 1464 of yacc.c  */
#line 2041 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> argument_expression_list ',' assignment_expression \n", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
				agregar_al_final_de_lista_de_nodos_ast((yyvsp[(1) - (3)].nodo_ast), (yyvsp[(3) - (3)].nodo_ast), (yylsp[(3) - (3)])); (yyval.nodo_ast) = (yyvsp[(1) - (3)].nodo_ast);
			;}
    break;

  case 264:

/* Line 1464 of yacc.c  */
#line 2065 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> IDENTIFICADOR \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_primary_expression(TIPO_IDENTIFICADOR, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 265:

/* Line 1464 of yacc.c  */
#line 2071 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> constante_entera \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 266:

/* Line 1464 of yacc.c  */
#line 2077 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> constante_real \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = (yyvsp[(1) - (1)].nodo_ast);
			;}
    break;

  case 267:

/* Line 1464 of yacc.c  */
#line 2083 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> LITERAL_CADENA \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				(yyval.nodo_ast) = crear_nodo_ast_enumeracion_primary_expression(TIPO_LITERAL_CADENA, (yylsp[(1) - (1)]), (Nodo_AST*) (yyvsp[(1) - (1)].char_pointer_type), NULL);
			;}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 2088 "src/TPI.y"
    { bandera_podria_usarse_un_nombre_de_typedef = FALSE; ;}
    break;

  case 269:

/* Line 1464 of yacc.c  */
#line 2089 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> '(' {} expression ')' \n", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(4) - (4)]).last_line, (yylsp[(4) - (4)]).last_column);
				(yyval.nodo_ast) = (yyvsp[(3) - (4)].nodo_ast);
			;}
    break;

  case 270:

/* Line 1464 of yacc.c  */
#line 2107 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_INT_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo int: %d \n", (yyvsp[(1) - (1)].int_type)); (yyval.int_type) = (yyvsp[(1) - (1)].int_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_INT, ((union Valor) {.int_value = (yyvsp[(1) - (1)].int_type)}), (yylsp[(1) - (1)]));
			;}
    break;

  case 271:

/* Line 1464 of yacc.c  */
#line 2113 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_UNSIGNED_INT_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo unsigned int: %u \n", (yyvsp[(1) - (1)].unsigned_int_type)); (yyval.unsigned_int_type) = (yyvsp[(1) - (1)].unsigned_int_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_UNSIGNED_INT, ((union Valor) {.unsigned_int_value = (yyvsp[(1) - (1)].unsigned_int_type)}), (yylsp[(1) - (1)]));
			;}
    break;

  case 272:

/* Line 1464 of yacc.c  */
#line 2119 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_LONG_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo long: %ld \n", (yyvsp[(1) - (1)].long_type)); (yyval.long_type) = (yyvsp[(1) - (1)].long_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_LONG, ((union Valor) {.long_value = (yyvsp[(1) - (1)].long_type)}), (yylsp[(1) - (1)]));
			;}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 2125 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo unsigned long: %lu \n", (yyvsp[(1) - (1)].unsigned_long_type)); (yyval.unsigned_long_type) = (yyvsp[(1) - (1)].unsigned_long_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_UNSIGNED_LONG, ((union Valor) {.unsigned_long_value = (yyvsp[(1) - (1)].unsigned_long_type)}), (yylsp[(1) - (1)]));
			;}
    break;

  case 274:

/* Line 1464 of yacc.c  */
#line 2134 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_FLOAT_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo float: %f \n", (yyvsp[(1) - (1)].float_type)); (yyval.float_type) = (yyvsp[(1) - (1)].float_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_FLOAT, ((union Valor) {.float_value = (yyvsp[(1) - (1)].float_type)}), (yylsp[(1) - (1)]));

			;}
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 2141 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_DOUBLE_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo double: %f \n", (yyvsp[(1) - (1)].double_type)); (yyval.double_type) = (yyvsp[(1) - (1)].double_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_DOUBLE, ((union Valor) {.double_value = (yyvsp[(1) - (1)].double_type)}), (yylsp[(1) - (1)]));
			;}
    break;

  case 276:

/* Line 1464 of yacc.c  */
#line 2147 "src/TPI.y"
    {
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_LONG_DOUBLE_TYPE \n", (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column, (yylsp[(1) - (1)]).last_line, (yylsp[(1) - (1)]).last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo long double: %Lf \n", (yyvsp[(1) - (1)].long_double_type)); (yyval.long_double_type) = (yyvsp[(1) - (1)].long_double_type);
				(yyval.nodo_ast) = crear_nodo_ast_constante(DATO_LONG_DOUBLE, ((union Valor) {.long_double_value = (yyvsp[(1) - (1)].long_double_type)}), (yylsp[(1) - (1)]));
			;}
    break;



/* Line 1464 of yacc.c  */
#line 5332 "obj/TPI.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 2154 "src/TPI.y"

/* Fin de la sección de reglas gramaticales */

/* Inicio de la sección de epílogo (código de usuario) */

int main(void) {

	inicializar_tabla_de_simbolos();

    printf("\n============================== [ Compilacion ] ==============================\n\n");
    errno = 0; yyin = fopen(archivo_yyin, "r");
    if (errno != 0)
    {
		fprintf(stderr, "Error de programa: Error al abrir el archivo \"%s\": %s \n", archivo_yyin, strerror(errno));
        pausa();
        exit(1);
    }

	inicializarUbicacion();

	#if YYDEBUG
      yydebug = 1;
    #endif

    switch(yyparse())
	{
		case 0:
			if(! cantidadErroresLexicos)
			{
				if(! yynerrs)
				{
					printf("\nEl texto del archivo \"%s\" SI es sintacticamente correcto respecto de la gramatica ANSI C de 1989 (C89) \n", archivo_yyin);
					if(! cantidadErroresSemanticos)
					{
						printf("\nEl texto del archivo \"%s\" SI es semanticamente correcto \n", archivo_yyin);
					}
					else
					{
						printf("\nEl texto del archivo \"%s\" NO es semanticamente correcto: se han detectado %d error/es semantico/s \n", archivo_yyin, cantidadErroresSemanticos);
					}
				}
				else
				{
					printf("\nEl texto del archivo \"%s\" NO es sintacticamente correcto respecto de la gramatica ANSI C de 1989 (C89) \n", archivo_yyin);
				}
			}
			else
			{
				printf("\nEl texto del archivo \"%s\" NO es lexicamente correcto: se han detectado %d error/es lexicos/s \n", archivo_yyin, cantidadErroresLexicos);
			}
		break;
		case 1:
			if(! cantidadErroresLexicos)
			{
				printf("\nEl texto del archivo \"%s\" NO es sintacticamente correcto respecto de la gramatica ANSI C de 1989 (C89) \n", archivo_yyin);
			}
			else
			{
				printf("\nEl texto del archivo \"%s\" NO es lexicamente correcto: se han detectado %d error/es lexicos/s \n", archivo_yyin, cantidadErroresLexicos);
			}
		break;
		case 2:
			printf("\nError de programa: Hubo un fallo en el analisis sintactico debido al agotamiento de la memoria dinamica \n");
		break;
	}

    fclose(yyin);
    printf("\n============================== [ Terminado ] ==============================\n\n");

    printf("\n============================== [ Reporte ] ==============================\n");
	printf("\n* Listado de variables declaradas:\n"); reportarListaDeDescripciones(variablesDeclaradas);
	printf("\n* Listado de funciones declaradas:\n"); reportarListaDeDescripciones(funcionesDeclaradas);
	printf("\n* Listado de errores lexicos encontrados:\n"); reportarListaDeDescripciones(erroresLexicos);
	printf("\n* Listado de errores sintacticos encontrados:\n"); reportarListaDeDescripciones(erroresSintacticos);
	printf("\n* Listado de errores semanticos encontrados:\n"); reportarListaDeDescripciones(erroresSemanticos);
    printf("\n============================== [ Terminado ] ==============================\n\n");

    pausa();
    return 0;
}

	/* Definición de la función yyerror para reportar errores, necesaria para que la función yyparse del analizador sintáctico pueda invocarla para reportar un error */
void yyerror(const char* literalCadena)
{
	error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: %s\n", archivo_yyin, yylloc.first_line, yylloc.first_column, literalCadena);
}

/* Fin de la sección de epílogo (código de usuario) */
