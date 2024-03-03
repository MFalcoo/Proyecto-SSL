/* Desarrollado para Bison versión 2.4.1 */

/*
UTN - FRBA
Sintaxis y Semántica de los Lenguajes - 2022
Trabajo Práctico Integrador
Analizador léxico, sintáctico y semántico de C

Implementar en C un programa que realice el análisis léxico, sintáctico y semántico de un archivo fuente del lenguaje C generando su respectivo reporte sobre el análisis realizado.
El mismo será un modelo simplificado (tomar una GIC reducida) que solamente realizará determinadas validaciones semánticas.

Las validaciones semánticas serán:
- Al menos un control de tipos de datos en alguna operación binaria (a elección de cada grupo) -> Utilizar TS si operamos con variables
- Control de doble declaración de variables (se consideran que todas las variables están en el mismo ámbito para simplificar la validación) -> Utilizar TS
- Control de cantidad y tipos de parámetros en la invocación a funciones -> Utilizar TS

Las validaciones sintácticas (TP 4):
- Sentencias (todos los tipos: compuesta, If, While, Salto, For, Expresión, etc)
- Declaraciones de variables (puede agregar variables tipo puntero y tipo arreglo) de forma correcta almacenando en TS.
- Declaraciones de funciones de forma correcta almacenando en TS.
- Expresiones (que están incluidas dentro de las sentencias).

El programa deberá reportar un informe en pantalla con
- Lista de variables declaradas indicando el tipo de cada una. (Utilizar TS)
- Lista de funciones declaradas indicando el tipo de parámetro que devuelve y cantidad y tipos de parámetros que recibe. (Utilizar TS)
- Error léxicos encontrados (si los hay) - (Implementar en Flex, archivo.L)
- Errores sintácticos encontrados (si los hay) (Implementar en Bison, utilizar token error)
- Errores semánticos encontrados (si los hay) (Implementar Rutinas Semánticas con TS).

El criterio para el manejo de errores es el siguiente:
- Ante un error léxico, capturar la secuencia de caracteres no reconocida (pueden utilizar una última regla con comodín), en este caso, no le llegará ningún token al analizador sintáctico.
	Pero puede suceder que un error léxico, desencadene un error sintáctico en caso de que el Parser no reciba los tokens adecuados para la GIC implementada.
- Ante un error sintáctico, utilizar el token “error” para capturar el error y almacenar la información que consideren importante para registrar el mismo.
	Luego seguir procesando a partir de donde encuentran un punto y coma ‘;’ , o bien un salto de línea ‘\n’.
- Ante un error semántico, no es necesario salvar el error dado que la gramática independiente de contexto seguirá operando sin problemas.
	Pero deben implementar dentro de las rutinas semánticas la impresión de algún mensaje en pantalla, o bien, almacenar los errores encontrados en una lista para imprimirlo al final del análisis en el reporte.

La entrega de este trabajo práctico es obligatoria y será en conjunto con defensa del mismo los días lunes 31 de octubre (K2001) y martes 1 de noviembre (K2052).
Deben estar presentes con micrófono y cámara todos los integrantes del grupo. La defensa tendrá una duración aproximada de 15 minutos en los cuales todos los integrantes deberán responder preguntas referidas al trabajo práctico integrador.
*/

/* Inicio de la sección de prólogo (declaraciones y definiciones de C y directivas del preprocesador) */
%{
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
%}
/* Fin de la sección de prólogo (declaraciones y definiciones de C y directivas del preprocesador) */

/* Inicio de la sección de declaraciones de bison */

	/* Para requerir una versión mínima de Bison para procesar la gramática */
%require "2.4.1"

	/* Para activar el seguimiento de las ubicaciones de los tokens (número de línea, número de columna) */
%locations

	/* Para especificar la colección completa de posibles tipos de datos para los valores semánticos */
%union {
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
}

	/* Para declarar la precedencia de los operadores para especificarle a Bison cuándo desplazar y cuándo reducir. A más arriba la declaración, menor precedencia "por estar más cerca del axioma" (tiene menor prioridad para ser reducido), y a más abajo la declaración, mayor precedencia "por estar más lejos del axioma" (tiene mayor prioridad para ser reducido). Si varios operadores aparecen en una misma declaración, tienen la misma precedencia. */
	/* Así como para declarar la asociatividad de los operadores para especificarle a Bison cuándo desplazar y cuándo reducir. Si es asociativa por izquierda, se prioriza la reducción por sobre el desplazamiento para un mismo operador, y si es asociativa por derecha, se prioriza el desplazamiento por sobre la reducción para un mismo operador. Si varios operadores aparecen en una misma declaración, tienen la misma precedencia. */
		/* Estas declaraciones resuelven los conflictos desplazamiento/reducción causados por las ambigüedades en la gramática */
%nonassoc THEN
%nonassoc "else"

	/* Para requirle a Bison que describa más detalladamente los mensajes de error al invocar a yyerror */
%error-verbose
	/* Nota: esta directiva escrita de esta manera quedó obsoleta a partir de versiones de Bison posteriores por: %define parse.error verbose */

	/* */
		/* Constantes */
			/* Constantes enteras */
%token <int_type> CONSTANTE_ENTERA_INT_TYPE
%token <unsigned_int_type> CONSTANTE_ENTERA_UNSIGNED_INT_TYPE
%token <long_type> CONSTANTE_ENTERA_LONG_TYPE
%token <unsigned_long_type> CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE
			/* Constantes reales */
%token <float_type> CONSTANTE_REAL_FLOAT_TYPE
%token <long_double_type> CONSTANTE_REAL_LONG_DOUBLE_TYPE
%token <double_type> CONSTANTE_REAL_DOUBLE_TYPE
		/* Literales cadena */
%token <char_pointer_type> LITERAL_CADENA
		/* Palabras reservadas */
%token TYPEDEF_TOKEN "typedef" EXTERN_TOKEN "extern" STATIC_TOKEN "static" AUTO_TOKEN "auto" REGISTER_TOKEN "register"
%token VOID_TOKEN "void" CHAR_TOKEN "char" SHORT_TOKEN "short" INT_TOKEN "int" LONG_TOKEN "long" FLOAT_TOKEN "float" DOUBLE_TOKEN "double" SIGNED_TOKEN "signed" UNSIGNED_TOKEN "unsigned"
%token CONST_TOKEN "const" VOLATILE_TOKEN "volatile"
%token STRUCT_TOKEN "struct" UNION_TOKEN "union"
%token ENUM_TOKEN "enum"
%token IF_TOKEN "if" ELSE_TOKEN "else" SWITCH_TOKEN "switch"
%token WHILE_TOKEN "while" DO_TOKEN "do" FOR_TOKEN "for"
%token CASE_TOKEN "case" DEFAULT_TOKEN "default"
%token GOTO_TOKEN "goto" CONTINUE_TOKEN "continue" BREAK_TOKEN "break" RETURN_TOKEN "return"
%token SIZEOF_TOKEN "sizeof"
		/* Identificadores */
%token <char_pointer_type> IDENTIFICADOR NOMBRE_DE_TYPEDEF
		/* Caracteres de puntuación/operadores de C */
%token ELIPSIS_TOKEN "..."
%token MAS_IGUAL_TOKEN "+=" MENOS_IGUAL_TOKEN "-=" POR_IGUAL_TOKEN "*=" DIVIDIDO_IGUAL_TOKEN "/=" MOD_IGUAL_TOKEN "%=" AND_IGUAL_TOKEN "&=" OR_IGUAL_TOKEN "|=" XOR_IGUAL_TOKEN "^=" ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA_TOKEN "<<=" ASIGNACION_CON_DESPLAZAMIENTO_DERECHA_TOKEN ">>="
%token OR_TOKEN "||"
%token AND_TOKEN "&&"
%token IGUALDAD_TOKEN "==" DIFERENCIA_TOKEN "!="
%token MAYOR_O_IGUAL_TOKEN ">=" MENOR_O_IGUAL_TOKEN "<="
%token DESPLAZAMIENTO_IZQUIERDA_TOKEN "<<" DESPLAZAMIENTO_DERECHA_TOKEN ">>"
%token MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION_TOKEN "->"
%token INCREMENTO_TOKEN "++" DECREMENTO_TOKEN "--"

	/* */
%type <nodo_ast> translation_unit
%type <nodo_ast> external_declaration
%type <nodo_ast> function_definition
%type <nodo_ast> declaration
%type <nodo_ast> declaration_list
%type <nodo_ast> declaration_specifiers
%type <nodo_ast> init_declarator_list
%type <nodo_ast> init_declarator
%type <nodo_ast> storage_class_specifier
%type <nodo_ast> type_specifier
%type <nodo_ast> type_qualifier
%type <nodo_ast> struct_or_union_specifier
%type <nodo_ast> factorizacion_struct_or_union_specifier
%type <struct_o_union> struct_or_union
%type <nodo_ast> struct_declaration_list
%type <nodo_ast> struct_declaration
%type <nodo_ast> specifier_qualifier_list
%type <nodo_ast> struct_declarator_list
%type <nodo_ast> struct_declarator
%type <nodo_ast> enum_specifier
%type <nodo_ast> factorizacion_enum_specifier
%type <nodo_ast> enumerator_list
%type <nodo_ast> enumerator
%type <nodo_ast> declarator
%type <nodo_ast> direct_declarator
%type <nodo_ast> factorizacion_direct_declarator
%type <nodo_ast> pointer
%type <nodo_ast> factorizacion_pointer
%type <nodo_ast> type_qualifier_list
%type <nodo_ast> parameter_type_list
%type <nodo_ast> parameter_list
%type <nodo_ast> parameter_declaration
%type <nodo_ast> identifier_list
%type <nodo_ast> initializer
%type <nodo_ast> initializer_list
%type <nodo_ast> type_name
%type <nodo_ast> abstract_declarator
%type <nodo_ast> direct_abstract_declarator
%type <nodo_ast> statement
%type <nodo_ast> labeled_statement
%type <nodo_ast> expression_statement
%type <nodo_ast> compound_statement
%type <nodo_ast> factorizacion_compound_statement
%type <nodo_ast> statement_list
%type <nodo_ast> selection_statement
%type <nodo_ast> factorizacion_selection_statement
%type <nodo_ast> iteration_statement
%type <nodo_ast> factorizacion_iteration_statement
%type <nodo_ast> jump_statement
%type <nodo_ast> factorizacion_jump_statement
%type <nodo_ast> expression
%type <nodo_ast> assignment_expression
%type <tipoAssignment_Expression> assignment_operator
%type <nodo_ast> constant_expression
%type <nodo_ast> conditional_expression
%type <nodo_ast> logical_or_expression
%type <nodo_ast> logical_and_expression
%type <nodo_ast> inclusive_or_expression
%type <nodo_ast> exclusive_or_expression
%type <nodo_ast> and_expression
%type <nodo_ast> equality_expression
%type <nodo_ast> relational_expression
%type <nodo_ast> shift_expression
%type <nodo_ast> additive_expression
%type <nodo_ast> multiplicative_expression
%type <nodo_ast> cast_expression
%type <nodo_ast> unary_expression
%type <nodo_ast> factorizacion_unary_expression
%type <tipoUnary_Expression> unary_operator
%type <nodo_ast> postfix_expression
%type <nodo_ast> argument_expression_list
%type <nodo_ast> primary_expression
%type <nodo_ast> constante_entera
%type <nodo_ast> constante_real

	/* 3.7.7 Freeing Discarded Symbols: Specify how the parser should reclaim the memory associated to discarded symbols */
/*
%destructor { printf("Bison: %s:%d:%d: Liberando valor semantico asociado: %s\n", archivo_yyin, @$.first_line, @$.first_column, $$); free($$); } CONSTANTE_ENTERA CONSTANTE_REAL LITERAL_CADENA IDENTIFICADOR NOMBRE_DE_TYPEDEF
*/

	/* Para especificar el no-terminal de inicio la gramática (el axioma). Si esto se omitiera, se asumiría que es el no-terminal de la primera regla */
%start translation_unit

/*
%initial-action
%merge
$<TYPEALT>$
$<typealt>n
YYABORT;
YYACCEPT;
YYBACKUP (token, value);
YYEMPTY
YYEOF
YYERROR;
YYRECOVERING
yychar
yyclearin;
*/

/* Fin de la sección de declaraciones de bison */

/* Inicio de la sección de reglas gramaticales */
%%

	/* Definiciones externas */

translation_unit /* Un programa de C consiste de uno o más unidades de traducción guardados en archivos. Cuando el preprocesamiento es completado, el programa es reducido a una secuencia de tokens. */
	: external_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: translation_unit -> external_declaration \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(TRANSLATION_UNIT, $1, @1);
			}
	| translation_unit external_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: translation_unit -> translation_unit external_declaration \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $2, @2); $$ = $1;
			}
	;

external_declaration
	: function_definition
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: external_declaration -> function_definition \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_external_declaration(TIPO_FUNCTION_DEFINITION, @1, $1, NULL);
			}
	| declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: external_declaration -> declaration \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_external_declaration(TIPO_DECLARATION, @1, $1, NULL);
			}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declaration_specifiers declarator declaration_list compound_statement \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast_function_definition($1, $2, $3, $4, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| declaration_specifiers declarator compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declaration_specifiers declarator compound_statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast_function_definition($1, $2, NULL, $3, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| declarator declaration_list compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declarator declaration_list compound_statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast_function_definition(NULL, $1, $2, $3, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| declarator compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: function_definition -> declarator compound_statement \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast_function_definition(NULL, $1, NULL, $2, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}));
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	;



	/* Declaraciones */

declaration /* Las declaraciones especifican la interpretación dada a cada identificador; no necesariamente reservan almacenamiento asociado con el identificador. Las declaraciones que reservan almacenamiento son llamadas definiciones. */
	: declaration_specifiers ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration -> declaration_specifiers ';' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast(DECLARATION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| declaration_specifiers init_declarator_list ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration -> declaration_specifiers init_declarator_list ';' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast(DECLARATION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $2);
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	;

declaration_list
	: declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_list -> declaration \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(DECLARATION_LIST, $1, @1);
			}
	| declaration_list declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_list -> declaration_list declaration \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $2, @2); $$ = $1;
			}
	;

declaration_specifiers /* Los especificadores de declaración consisten de una secuencia de tipos y de especificadores de clase de almacenamiento*/
	: storage_class_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> storage_class_specifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, $1, @1);
			}
	| storage_class_specifier declaration_specifiers
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> storage_class_specifier declaration_specifiers \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_inicio_de_lista_de_nodos_ast($2, $1, @1); $$ = $2;
			}
	| type_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_specifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, $1, @1);
			}
	| type_specifier declaration_specifiers
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_specifier declaration_specifiers \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_inicio_de_lista_de_nodos_ast($2, $1, @1); $$ = $2;
			}
	| type_qualifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_qualifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(DECLARATION_SPECIFIERS, $1, @1);
			}
	| type_qualifier declaration_specifiers
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declaration_specifiers -> type_qualifier declaration_specifiers \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_inicio_de_lista_de_nodos_ast($2, $1, @1); $$ = $2;
			}
	;

init_declarator_list
	: init_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(INIT_DECLARATOR_LIST, $1, @1);
			}
	| init_declarator_list ',' init_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator_list ',' init_declarator \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	| init_declarator_list ',' error
		{
			debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator_list -> init_declarator_list ',' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: init_declarator_list \n", archivo_yyin, @3.first_line, @3.first_column); 
			yyerrok;
			agregar_al_final_de_lista_de_nodos_ast($1, crear_nodo_ast_enumeracion_error(INIT_DECLARATOR_LIST, @3, NULL, NULL), @3); $$ = $1;
		}
	;

init_declarator
	: declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(INIT_DECLARATOR, NULL, @1, $1, NULL);
			}
	| declarator '=' initializer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator '=' initializer \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(INIT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| declarator error 
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: init_declarator -> declarator error \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: init_declarator \n", archivo_yyin, @2.first_line, @2.first_column); 
				yyerrok;
				yyclearin;
				$$ = crear_nodo_ast_enumeracion_error(INIT_DECLARATOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
			}
	;

storage_class_specifier /* La clase de almacenamiento determina la duración del almacenamiento asociado con objeto identificado. Como mucho un sólo especificador de clase de almacenamiento puede ser dado en una declaración. Si ninguno es dado, estas reglas son usadas: los objetos declarados por dentro de una función son tomados por ser "auto"; las funciones  declaradas por dentro de una función son tomadas por ser "extern"; los objetos y funciones declarados por fuera de una función son tomados por ser "static", con enlace externo. */
	: "auto" /* Los especificadores "auto" y "register" le dan a los objetos declarados clase de almacenamiento automático, y sólo pueden ser utilizados dentro de funciones. Tales declaraciones también sirven como definiciones y causan que se reserve almacenamiento. Los objetos automáticos son locales a un bloque, y son descartados al salir del bloque. Las declaraciones en un bloque crean objetos automáticos si ninguna especificación de clase de almacenamiento es mencionada, o si el especificador "auto" es usado.  */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"auto\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_AUTO, @1, NULL, NULL);
			}
	| "register" /* Los especificadores "auto" y "register" le dan a los objetos declarados clase de almacenamiento automático, y sólo pueden ser utilizados dentro de funciones. Tales declaraciones también sirven como definiciones y causan que se reserve almacenamiento. Los objetos declarados "register" son automáticos, y son (si es posible) almacenados en registros rápidos de la máquina. Una declaración "register" es equivalente a una declaración "auto", pero indica que los objetos declarados serán accedidos frecuentemente. Sólo unos cuantos objetos son puestos dentro de registros en realidad, y sólo ciertos tipos son elegibles; las restricciones son dependientes de la implementación. Sin embargo, si un objeto es declarado "register", el operador unario de referenciación (&) no puede ser aplicado al mismo, explícitamente o implícitamente. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"register\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_REGISTER, @1, NULL, NULL);
			}
	| "static" /* El especificador "static" le da a los objetos declarados clase de almacenamiento estática, y pueden  ser utilizado ya sea por dentro o por fuera de las funciones. Por dentro de una función, este especificador causa asignación de almacenamiento, y sirve como una definición. Los objetos estáticos pueden ser locales a un bloque o externos a todos los bloques, pero en cualquier caso mantienen su valor entre las salidas y reentradas a funciones y bloques. Dentro de un bloque, incluyendo un bloque que provee el código para una función, los objetos estáticos son declarados con la palabra reservada "static". Los objetos declarados afuera de todos los bloques, al mismo nivel que las definiciones de funciones, son siempre estáticos. Pueden hacerse locales a una unidad de traducción en particular con el uso de la palabra reservada "static"; esto les da enlace interno. Se hacen globales a un programa entero omitiendo una clase de almacenamiento explícita, o usando la palabra reservada "extern"; esto les da enlace externo. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"static\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_STATIC, @1, NULL, NULL);
			}
	| "extern" /* Una declaración con "extern", utilizado por dentro de una función, especifica que el almacenamiento para los objetos declarados está definido en algún otra parte. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"extern\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_EXTERN, @1, NULL, NULL);
			}
	| "typedef" /* El especificador "typedef" no reserva almacenamiento y es llamado un especificador de clase de almacenamiento sólo por conveniencia sintáctica. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: storage_class_specifier -> \"typedef\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_storage_class_specifier(TIPO_TYPEDEF, @1, NULL, NULL);
			}
	;

type_specifier /* Como mucho una de las palabras "long" o "short" pueden ser especificadas en conjunto con "int"; el significadoes el mismo si "int" no es mencionado. La palabra "long" puede ser especificada en conjunto con "double". Como mucho uno de "signed" o "unsigned" puede ser especificado en conjunto con "int" o con cualquiera de sus variaciones "short" o "long", o con "char". Cualquiera de los dos puede aparecer solo, en cuyo caso "int" es sobreentendido. El especificador "signed" es útil para forzar a los objetos "char" a llevar un signo; es permisible pero redundante con otros tipos enteros. De lo contrario, como mucho un especificador de tipo puede ser dado en una declaración. Si el especificador de tipo falta de una declaración, es tomado por ser "int". */
	: "void"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"void\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_VOID, @1, NULL, NULL);
			}
	| "char"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"char\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_CHAR, @1, NULL, NULL);
			}
	| "short"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"short\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_SHORT, @1, NULL, NULL);
			}
	| "int"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"int\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_INT, @1, NULL, NULL);
			}
	| "long"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"long\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_LONG, @1, NULL, NULL);
			}
	| "float"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"float\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_FLOAT, @1, NULL, NULL);
			}
	| "double"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"double\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_DOUBLE, @1, NULL, NULL);
			}
	| "signed"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"signed\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_SIGNED, @1, NULL, NULL);
			}
	| "unsigned"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> \"unsigned\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_UNSIGNED, @1, NULL, NULL);
			}
	| struct_or_union_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> struct_or_union_specifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_STRUCT_OR_UNION_SPECIFIER, @1, $1, NULL);
			}
	| enum_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> enum_specifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_ENUM_SPECIFIER, @1, $1, NULL);
			}
	| NOMBRE_DE_TYPEDEF /* Un NOMBRE_DE_TYPEDEF termina siendo un IDENTIFICADOR al fin y al cabo, pero si lo ponemos como tal en la gramática se generan conflictos reducción/reducción. Es por eso que es trabajo del analizador léxico (scanner), utilizando la tabla de símbolos y las variables globales que sean necesarias, distinguir y retornar los tokens IDENTIFICADOR y NOMBRE_DE_TYPEDEF según corresponda. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_specifier -> NOMBRE_DE_TYPEDEF \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_type_specifier(TIPO_NOMBRE_DE_TYPEDEF, @1, (Nodo_AST*) $1, NULL);
			}
	;

type_qualifier /* Los tipos también pueden ser calificados, para indicar propiedades especiales de los objetos siendo declarados. El tipo de un objeto puede tener calificadores adicionales. Ningún calificador afecta el rango de valores o propiedades aritméticas del objeto */
	: "const" /* Declarar un objeto "const"  anuncia que su valor no será cambiado. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier -> \"const\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_type_qualifier(TIPO_CONST, @1, NULL, NULL);
			}
	| "volatile" /* Declarar un objeto "volatile" anuncia que tiene propiedades especiales relevantes para la optimización. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier -> \"volatile\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_type_qualifier(TIPO_VOLATILE, @1, NULL, NULL);
			}
	;

struct_or_union_specifier
	: struct_or_union { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_struct_or_union_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union_specifier -> struct_or_union {} factorizacion_struct_or_union_specifier \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);

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

				((Nodo_Struct_or_Union_Specifier*) ($3 -> contenido)) -> struct_o_union = $1;
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;
factorizacion_struct_or_union_specifier
	: '{' { bandera_podria_usarse_un_nombre_de_typedef = TRUE; } struct_declaration_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> '{' {} struct_declaration_list '}' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				//agregar_tag_a_estructura(NULL, (Simbolo*) ($3 -> contenido));
				$$ = crear_nodo_ast_struct_or_union_specifier(NULL, $3, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}));
			}
	| IDENTIFICADOR '{' { bandera_podria_usarse_un_nombre_de_typedef = TRUE; } struct_declaration_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> IDENTIFICADOR '{' {} struct_declaration_list '}' \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
				//agregar_tag_a_estructura($1, (Simbolo*) ($4 -> contenido));
				$$ = crear_nodo_ast_struct_or_union_specifier((Nodo_AST*) $1, $4, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}));
			}
	| IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_struct_or_union_specifier -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				/*
				Simbolo* resultadoBusqueda = buscarSimbolo($1, SEGUN_ETIQUETA);
				if(resultadoBusqueda == NULL)
				{
					error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, $1);
					cantidadErroresSemanticos++;
				}
				*/
				$$ = crear_nodo_ast_struct_or_union_specifier((Nodo_AST*) $1, NULL, @1);
			}
	;

struct_or_union
	: "struct"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union -> \"struct\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = STRUCT;
			}
	| "union"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_or_union -> \"union\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = UNION;
			}
	;

struct_declaration_list
	: struct_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration_list -> struct_declaration \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(STRUCT_DECLARATION_LIST, $1, @1);
			}
	| struct_declaration_list struct_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration_list -> struct_declaration_list struct_declaration \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $2, @2); $$ = $1;
			}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declaration -> specifier_qualifier_list struct_declarator_list ';' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast(STRUCT_DECLARATION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $2);
			}
	;

specifier_qualifier_list
	: type_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_specifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(SPECIFIER_QUALIFIER_LIST, $1, @1);
			}
	| type_specifier specifier_qualifier_list
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_specifier specifier_qualifier_list \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_inicio_de_lista_de_nodos_ast($2, $1, @1); $$ = $2;
			}
	| type_qualifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_qualifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(SPECIFIER_QUALIFIER_LIST, $1, @1);
			}
	| type_qualifier specifier_qualifier_list
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: specifier_qualifier_list -> type_qualifier specifier_qualifier_list \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_inicio_de_lista_de_nodos_ast($2, $1, @1); $$ = $2;
			}
	;

struct_declarator_list
	: struct_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator_list -> struct_declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(STRUCT_DECLARATOR_LIST, $1, @1);
			}
	| struct_declarator_list ',' struct_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator_list -> struct_declarator_list ',' struct_declarator \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	;

struct_declarator
	: declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(STRUCT_DECLARATOR, NULL, @1, $1, NULL);
			}
	| ':' constant_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> ':' constant_expression \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast(STRUCT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, $2);
			}
	| declarator ':' constant_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: struct_declarator -> declarator ':' constant_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(STRUCT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	;
 
enum_specifier
	: "enum" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_enum_specifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enum_specifier -> \"enum\" {} factorizacion_enum_specifier \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;

factorizacion_enum_specifier
	: '{' enumerator_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> '{' enumerator_list '}' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				//agregar_tag_a_enumeracion(NULL, (Simbolo*) ($2 -> contenido));
				$$ = crear_nodo_ast(ENUM_SPECIFIER, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, $2);
			}
	| IDENTIFICADOR '{' enumerator_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> IDENTIFICADOR '{' enumerator_list '}' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				//agregar_tag_a_enumeracion($1, (Simbolo*) ($3 -> contenido));
				$$ = crear_nodo_ast(ENUM_SPECIFIER, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), (Nodo_AST*) $1, $3);
			}
	| IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_enum_specifier -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				/*
				Simbolo* resultadoBusqueda = buscarSimbolo($1, SEGUN_ETIQUETA);
				if(resultadoBusqueda == NULL)
				{
					error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, $1);
					cantidadErroresSemanticos++;
				}
				*/
				$$ = crear_nodo_ast(ENUM_SPECIFIER, NULL, @1, (Nodo_AST*) $1, NULL);
			}
	;

enumerator_list
	: enumerator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator_list -> enumerator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(ENUMERATOR_LIST, $1, @1);
			}
	| enumerator_list ',' enumerator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator_list -> enumerator_list ',' enumerator \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	;

enumerator
	: IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(ENUMERATOR, NULL, @1, (Nodo_AST*) $1, NULL);
			}
	| IDENTIFICADOR '=' constant_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: enumerator -> IDENTIFICADOR '=' constant_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(ENUMERATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), (Nodo_AST*) $1, $3);
			}
	;

declarator /* Los declaradores contienen los identificadores/nombres siendo declarados */
	: pointer direct_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declarator -> pointer direct_declarator \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast(DECLARATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	| direct_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: declarator -> direct_declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(DECLARATOR, NULL, @1, NULL, $1);
			}
	;

direct_declarator
	: IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_IDENTIFICADOR, @1, (Nodo_AST*) $1, NULL);
			}
	| '(' declarator ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> '(' declarator ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_DECLARATOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $2, NULL);
			}
	| direct_declarator '[' constant_expression ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '[' constant_expression ']' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $1, $3);
			}
	| direct_declarator '[' ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '[' ']' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, NULL);
			}
	| direct_declarator '(' { bandera_podria_usarse_un_nombre_de_typedef = TRUE; } factorizacion_direct_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_declarator -> direct_declarator '(' {} factorizacion_direct_declarator \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$4 -> hijoIzquierdo = $1;
				($4 -> ubicacion).first_line = @1.first_line;
				($4 -> ubicacion).first_column = @1.first_column;
				$$ = $4;
			}
	;

factorizacion_direct_declarator
	: parameter_type_list ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> parameter_type_list ')' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, $1);
			}
	| identifier_list ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> identifier_list ')' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, $1);
			}
	| ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_direct_declarator -> ')' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_direct_declarator(TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA, @1, NULL, NULL);
			}
	;

pointer
	: '*' { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_pointer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: pointer -> '*' {} factorizacion_pointer \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				if((($3 -> ubicacion).first_line == -1) && (($3 -> ubicacion).first_column == -1) && (($3 -> ubicacion).last_line == -1) && (($3 -> ubicacion).last_column == -1))
				{
					$3 -> ubicacion = @1;
				}
				else
				{
					($3 -> ubicacion).first_line = @1.first_line;
					($3 -> ubicacion).first_column = @1.first_column;
				}
				$$ = $3;
			}
	;

factorizacion_pointer
	: /* Regla vacía */
			{
				debug_reducciones_bison_printf("Bis%cn: Reduciendo por la regla: factorizacion_pointer -> (Epsilon) \n", 'o');
				$$ = crear_nodo_ast(POINTER, NULL, ((struct Ubicacion) {.first_line = -1, .first_column = -1, .last_line = -1, .last_column = -1}), NULL, NULL);
			}
	| type_qualifier_list
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> type_qualifier_list \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(POINTER, NULL, @1, $1, NULL);
			}
	| pointer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> pointer \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(POINTER, NULL, @1, NULL, $1);
			}
	| type_qualifier_list pointer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_pointer -> type_qualifier_list pointer \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast(POINTER, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	;

type_qualifier_list
	: type_qualifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier_list -> type_qualifier \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(TYPE_QUALIFIER_LIST, $1, @1);
			}
	| type_qualifier_list type_qualifier
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_qualifier_list -> type_qualifier_list type_qualifier \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $2, @2); $$ = $1;
			}
	;

parameter_type_list
	: parameter_list
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_type_list -> parameter_list \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_parameter_type_list(SIN_ELIPSIS, @1, $1, NULL);
			}
	| parameter_list ',' "..."
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_type_list -> parameter_list ',' \"...\" \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_parameter_type_list(CON_ELIPSIS, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, NULL);
			}
	;

parameter_list
	: parameter_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_list -> parameter_declaration \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				$$ = crear_lista_de_nodos_ast(PARAMETER_LIST, $1, @1);
			}
	| parameter_list ',' parameter_declaration
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_list -> parameter_list ',' parameter_declaration \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = TRUE;
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	;

parameter_declaration
	: declaration_specifiers declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers declarator \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_DECLARATOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	| declaration_specifiers abstract_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers abstract_declarator \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	| declaration_specifiers
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: parameter_declaration -> declaration_specifiers \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_parameter_declaration(TIPO_PARAMETER_DECLARATION_EPSILON, @1, $1, NULL);
			}
	;

identifier_list
	: IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: identifier_list -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_lista_de_nodos_ast(IDENTIFIER_LIST, (Nodo_AST*) $1, @1);
			}
	| identifier_list ',' IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: identifier_list -> identifier_list ',' IDENTIFICADOR \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, (Nodo_AST*) $3, @3); $$ = $1;
			}
	;

initializer
	: assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> assignment_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_ASSIGNMENT_EXPRESSION, @1, $1, NULL);
			}
	| '{' initializer_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> '{' initializer_list '}' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_INITIALIZER_LIST, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $2, NULL);
			}
	| '{' initializer_list ',' '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer -> '{' initializer_list ',' '}' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$$ = crear_nodo_ast_enumeracion_initializer(TIPO_INITIALIZER_INITIALIZER_LIST, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $2, NULL);
			}
	;

initializer_list
	: initializer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer_list -> initializer \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(INITIALIZER_LIST, (Nodo_AST*) $1, @1);
			}
	| initializer_list ',' initializer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: initializer_list -> initializer_list ',' initializer \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	;

type_name
	: specifier_qualifier_list
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_name -> specifier_qualifier_list \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(TYPE_NAME, NULL, @1, $1, NULL);
			}
	| specifier_qualifier_list abstract_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: type_name -> specifier_qualifier_list abstract_declarator \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast(TYPE_NAME, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	;

abstract_declarator
	: pointer
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> pointer \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, @1, $1, NULL);
			}
	| direct_abstract_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> direct_abstract_declarator \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, @1, NULL, $1);
			}
	| pointer direct_abstract_declarator
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: abstract_declarator -> pointer direct_abstract_declarator \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast(ABSTRACT_DECLARATOR, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, $2);
			}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' abstract_declarator ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ABSTRACT_DECLARATOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $2, NULL);
			}
	| '[' ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '[' ']' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
			}
	| '[' constant_expression ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '[' constant_expression ']' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, $2);
			}
	| direct_abstract_declarator '[' ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '[' ']' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, NULL);
			}
	| direct_abstract_declarator '[' constant_expression ']'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '[' constant_expression ']' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $1, $3);
			}
	| '(' ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' ')' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
			}
	| '(' parameter_type_list ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> '(' parameter_type_list ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, $2);
			}
	| direct_abstract_declarator '(' ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '(' ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, NULL);
			}
	| direct_abstract_declarator '(' parameter_type_list ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: direct_abstract_declarator -> direct_abstract_declarator '(' parameter_type_list ')' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				crear_nodo_ast_enumeracion_direct_abstract_declarator(TIPO_ABSTRACTO_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $1, $3);
			}
	;










	/* Sentencias */

statement
	: labeled_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> labeled_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_LABELED_STATEMENT, @1, $1, NULL);
			}
	| expression_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> expression_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_EXPRESSION_STATEMENT, @1, $1, NULL);
			}
	| compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> compound_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_COMPOUND_STATEMENT, @1, $1, NULL);
			}
	| selection_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> selection_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_SELECTION_STATEMENT, @1, $1, NULL);
			}
	| iteration_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> iteration_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_ITERATION_STATEMENT, @1, $1, NULL);
			}
	| jump_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement -> jump_statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_statement(TIPO_JUMP_STATEMENT, @1, $1, NULL);
			}
	;

labeled_statement
	: IDENTIFICADOR { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } ':' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> IDENTIFICADOR {} ':' statement \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_labeled_statement(LABEL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), (Nodo_AST*) $1, $4);
			}
	| NOMBRE_DE_TYPEDEF { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } ':' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> NOMBRE_DE_TYPEDEF {} ':' statement \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_labeled_statement(LABEL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), (Nodo_AST*) $1, $4);
			}
	| "case" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } constant_expression ':' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"case\" {} constant_expression ':' statement \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_labeled_statement(CASE, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}), $3, $5);
			}
	| "case" error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"case\" error \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: labeled_statement \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(LABELED_STATEMENT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
		}
	| "default" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } ':' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: labeled_statement -> \"default\" {} ':' statement \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia etiquetada \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_labeled_statement(DEFAULT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $4, NULL);
			}
	;

expression_statement
	: ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression_statement -> ';' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de expresion \n", archivo_yyin, @1.first_line, @1.first_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast(EXPRESSION_STATEMENT, NULL, @1, NULL, NULL);
			}
	| expression ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression_statement -> expression ';' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de expresion \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast(EXPRESSION_STATEMENT, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
			}
	;

compound_statement
	: 	'{'
		{
			incrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual incrementado en 1: %d \n", alcanceActual);
			bandera_podria_usarse_un_nombre_de_typedef = TRUE;
		}
		factorizacion_compound_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: compound_statement -> '{' {} factorizacion_compound_statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia compuesta \n", archivo_yyin, @1.first_line, @1.first_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;

factorizacion_compound_statement
	: '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> '}' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast(COMPOUND_STATEMENT, NULL, @1, NULL, NULL);
			}
	| statement_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> statement_list '}' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, $1);
			}
	| declaration_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> declaration_list '}' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
			}
	| declaration_list statement_list '}'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_compound_statement -> declaration_list statement_list '}' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				decrementarAlcanceActual(); debug_banderas_bison_printf("Bison: Alcance actual decrementado en 1: %d \n", alcanceActual);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast(COMPOUND_STATEMENT, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $2);
			}
	;

statement_list
	: statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement_list -> statement \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(STATEMENT_LIST, $1, @1);
			}
	| statement_list statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: statement_list -> statement_list statement \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $2, @2); $$ = $1;
			}
	;

selection_statement
	: "if" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_selection_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_statement -> \"if\" {} factorizacion_selection_statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de seleccion \n", archivo_yyin, @1.first_line, @1.first_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	| "switch" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } '(' expression ')' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_statement -> \"switch\" {} '(' expression ')' statement \n", @1.first_line, @1.first_column, @6.last_line, @6.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de seleccion \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_selection_statement(SWITCH, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @6.last_line, .last_column = @6.last_column}), $4, $6);
			}
	/*
	| "switch" '(' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_statement -> \"switch\" '(' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: selection_statement \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(SELECTION_STATEMENT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
	*/	
	;

factorizacion_selection_statement
	: '(' expression ')' statement %prec THEN /* Precedencia dependiente del contexto */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_selection_statement -> '(' expression ')' statement \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$$ = crear_nodo_ast_if($2, $4, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}));
			}
	| '(' expression ')' statement "else" statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_selection_statement -> '(' expression ')' statement \"else\" statement \n", @1.first_line, @1.first_column, @6.last_line, @6.last_column);
				$$ = crear_nodo_ast_if($2, $4, $6, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @6.last_line, .last_column = @6.last_column}));
			}
	| '(' error 
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: selection_stateme -> '(' error \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: selection_statement \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(SELECTION_STATEMENT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
		}
	;

iteration_statement
	: "while" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } '(' expression ')' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"while\" {} '(' expression ')' statement \n", @1.first_line, @1.first_column, @6.last_line, @6.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_iteration_statement(WHILE, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @6.last_line, .last_column = @6.last_column}), $4, $6);
			}
/*
	| "while" '(' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"while\" '(' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: iteration_statement \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ITERATION_STATEMENT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
*/
	| "do" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } statement "while" '(' expression ')' ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"do\" {} statement \"while\" '(' expression ')' ';' \n", @1.first_line, @1.first_column, @8.last_line, @8.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_iteration_statement(DO_WHILE, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @6.last_line, .last_column = @6.last_column}), $3, $6);
			}
/*
	| "do" statement "while" '(' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"do\" statement \"while\" '(' error \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: iteration_statement \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ITERATION_STATEMENT, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}), NULL, NULL);
		}		
*/
	| "for" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_iteration_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: iteration_statement -> \"for\" {} '(' expression_statement expression_statement ')' statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de iteracion \n", archivo_yyin, @1.first_line, @1.first_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;

factorizacion_iteration_statement
	: '(' expression_statement expression_statement ')' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_iteration_statement -> '(' expression_statement expression_statement ')' statement \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
				$$ = crear_nodo_ast_for($2, $3, NULL, $5, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}));
			}
	| '(' expression_statement expression_statement expression ')' statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_iteration_statement -> '(' expression_statement expression_statement expression ')' statement \n", @1.first_line, @1.first_column, @6.last_line, @6.last_column);
				$$ = crear_nodo_ast_for($2, $3, $4, $6, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @6.last_line, .last_column = @6.last_column}));
			}
	;

jump_statement
	: "goto" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } IDENTIFICADOR ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"goto\" {} IDENTIFICADOR ';' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_jump_statement(GOTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), (Nodo_AST*) $3, NULL);
			}
	| "continue" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"continue\" {} ';' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_jump_statement(CONTINUE, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
			}
	| "break" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"break\" {} ';' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, @1.first_line, @1.first_column);
				$$ = crear_nodo_ast_enumeracion_jump_statement(BREAK, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
			}
	| "return" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } factorizacion_jump_statement
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: jump_statement -> \"return\" {} factorizacion_jump_statement \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				printf("Bison: %s:%d:%d: Tipo sentencia encontrada: Sentencia de salto \n", archivo_yyin, @1.first_line, @1.first_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;

factorizacion_jump_statement
	: ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_jump_statement -> ';' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_jump_statement(RETURN, @1, NULL, NULL);
			}
	| expression ';'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_jump_statement -> expression ';' \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast_enumeracion_jump_statement(RETURN, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
			}
	;







	/* Expresiones */

expression  /* Un par de expresiones separadas por una coma es evaluada de izquierda a derecha, y el valor de la expresión izquierda es descartada. El tipo y valor del resultado son el tipo y valor del operando derecho. Todos los efectos colaterales de la evaluación del operando izquierdo son completados antes de comenzar la evluación del operando derecho. En contextos donde a la coma se le da un significado especial, por ejemplo en listas de argumentos de funciones y listas de inicializadores, la unidad sintáctica requerida es una expresión de asignación, así que el operador coma solamente aparece en un agrupamiento entre paréntesis; por ejemplo, "f(a, (t = 3, t + 2), c)" tiene tres argumentos, el segundo del cual tiene el valor 5. */
	: assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression -> assignment_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(EXPRESSION, $1, @1);
			}
	| expression ',' assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: expression -> expression ',' assignment_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
	| expression ',' error           
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  expression ',' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

assignment_expression /* Hay varios operadores de asignación; todos son agrupados de derecha a izquierda. Todos requieren un Valor-L como operando izquierdo, y el Valor-L debe ser modificable: no debe ser un arreglo, y no debe tener un tipo incomplete, o ser una función. Además, su tipo no debe ser calificado con "const"; si es una estructura o unión, no debe tener ningún miembro o, recursivamente, submiembro calificado con const. El tipo de una expresión de asignación es la de su operando izquierdo, y el valor es el valor almacenado en el operando izquierdo luego de que la asignación se ha llevado a cabo. En la asignación simple con "=", el valor de la expresión reemplaza al del objeto referido por el Valor-L. Uno de lo siguiente debe ser verdadero: ambos operandos tienen tipo aritmético, en cuyo caso el operando derecho es convertido al tipo de la izquierda por la asignación; o ambos operandos son estructuras o uniones del mismo tipo; o un operando es un puntero y el other es un puntero a void (void*); o el operando izquierdo es un puntero y el operando derecho es una expresión constante con valor 0; o ambos operandos son punteros a funciones u objetos cuyos tipos son el mismo excepto por la posible ausencia de "const" o "volatile" en el operando derecho. Una expresion de la forma "E1 op= E2" es equivalente a "E1 = E1 op (E2)", excepto que E1 es evaluado solamente una vez. */
	: conditional_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_expression -> conditional_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| unary_expression assignment_operator assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_expression -> unary_expression assignment_operator assignment_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_assignment_expression($2, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	;

assignment_operator
	: '='
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> '=' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = IGUAL;
			}
	| "*="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"*=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = POR_IGUAL;
			}
	| "/="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"/=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = DIVIDIDO_IGUAL;
			}
	| "%="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"%%=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = MOD_IGUAL;
			}
	| "+="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"+=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = MAS_IGUAL;
			}
	| "-="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"-=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = MENOS_IGUAL;
			}
	| "<<="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"<<=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA;
			}
	| ">>="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \">>=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = ASIGNACION_CON_DESPLAZAMIENTO_DERECHA;
			}
	| "&="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"&=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				
				$$ = AND_IGUAL;
			}
	| "^="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"^=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = XOR_IGUAL;
			}
	| "|="
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: assignment_operator -> \"|=\" \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = OR_IGUAL;
			}
	;

constant_expression /* Sintácticamente, una expresión constante es una expresión restringida a un subconjunto de operadores. Las expresiones que se evalúan a una constante son requeridas en varios contextos: después de "case", como límites de un arreglo y longitudes de campos de bits, como el valor de una constante de enumeración, en inicializadores, y en ciertas expresiones del preprocesador. Las expresiones constantes no pueden contener asignaciones, operadores de incremento o decremento, invocación a funciones u operadores coma, excepto en un operando de "sizeof". Si la expresión constante se requiere que sea entera, sus operandos deben consistir de constantes enteras, de enumeració, caracter y reales; las conversiones deben especificar un tipo entero, y cualquier constante real debe ser convertida a un entero. Esto necesariamente excluye a las operaciones de arreglos, indirección (*), referenciación (&) y meimbros de estructuras (sin embargo, cualquier operando es permitido para "sizeof"). Mayor libertad es otorgada para las expresiones constantes de los inicializadores; los operandos pueden ser cualquier tipo de constante, y el operador unario de referenciación (&) puede ser aplicado a objetos "extern" o "static", y a arreglos "extern" o "static" indexados con una expresión constante. El operador de referenciación (&) también puede ser aplicado implícitamente por la aparición de arreglos no indexados y funciones. Los inicializadores deben ser evaluados ya sea a una constante o a la dirección de memoria de objeto "extern" o "static" previamente declarado más o menos una constante. Menor libertad es otorgada para las expresiones constantes enteras después de #if: no están permitidas expresiones "sizeof", constantes de enumeración, ni conversiones. */
	: conditional_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constant_expression -> conditional_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast(CONSTANT_EXPRESSION, NULL, @1, $1, NULL);
			}
	;

conditional_expression /* La primera expresión es evaluada, incluyendo todos los efectos colaterales; si se compara como diferente a 0, el resultado es el valor de la segunda expresión, en caso contrario el de la tercera expresión. Sólo uno de los operandos segundo y tercero es evaluado. Si los operandos segundo y tercero son aritméticos, las conversiones aritméticas usuales son realizadas para llevarlas a un tipo en común, y ese es el tipo del resultado. Si ambos son "void", o estructuras o uniones del mismo tipo, o punteros a objetos del mismo tipo, el resultado tiene el tipo en común. Si uno es un puntero y el otro la constante 0, el 0 es convertido al tipo puntero, y el resultado tiene ese tipo. Si uno es un puntero a "void" y el otro es otro puntero, el otro puntero es convertido a un puntero a "void", y ese es el tipo del resultado. En la comparación de tipos para punteros, cualquier calificador de tipos en el tipo al cual el puntero apunta es insignificante, pero el tipo del resultado hereda los calificadores de ambos brazos del condicional. */
	: logical_or_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: conditional_expression -> logical_or_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| logical_or_expression '?' expression ':' conditional_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: conditional_expression -> logical_or_expression '?' expression ':' conditional_expression \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
				$$ = crear_nodo_ast_conditional_expression($1, $3, $5, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}));
			}
	| logical_or_expression '?' error ':' conditional_expression
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression '?' error ':' conditional_expression error \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(CONDITIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}), NULL, NULL);
		}
	| logical_or_expression '?' expression ':' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression '?' expression ':'  error \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(CONDITIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}), NULL, NULL);
		}

	;

logical_or_expression /* El operador "||" se agrupa de izquierda a derecha. Retorna 1 si alguno de sus operandos se compara como distinto a cero, y 0 en caso contrario. A diferencia de "|", "||" garantiza evaluación de izquierda a derecha: el primer operando es evaluado, incluyendo todos los efectos colaterales; si es distinto a 0, el valor de la expresión es 1. De lo contrario, el operando derecho es evaluado, y si este es distinto a 0, el valor de la expresión es 1, de lo contrario 0. Los operandos no necesitan tener el mismo tipo, pero cada uno debe tener un tipo aritmético o ser un puntero. El resultado es "int". */
	: logical_and_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression -> logical_and_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| logical_or_expression "||" logical_and_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_or_expression -> logical_or_expression \"||\" logical_and_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(LOGICAL_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| logical_or_expression "||" error            
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  logical_or_expression \"||\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_or_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(LOGICAL_OR_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

logical_and_expression /* El operador "&&" se agrupa de izquierda a derecha. Retorna 1 si ambos operandos se comparan como distintos de cero, 0 de lo contrario. A diferencia de "&", "&&" garantiza evaluación de izquierda a derecha: el primer operando es evaluado, incluyendo todos los efectos colaterales; si es igual a 0, el valor de la expresión es 0. De lo contrario, el operando derecho es evaluado, y si este es igual a 0, el valor de la expresión es 0, de lo contrario 1. Los operandos no necesitan tener el mismo tipo, pero cada uno debe tener un tipo aritmético o ser un puntero. El resultado es "int". */
	: inclusive_or_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_and_expression -> inclusive_or_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| logical_and_expression "&&" inclusive_or_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: logical_and_expression -> logical_and_expression \"&&\" inclusive_or_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(LOGICAL_AND_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| logical_and_expression "&&" error           
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression \"&&\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: logical_and_expression \n", archivo_yyin, @1.first_line, @1.first_column);
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(LOGICAL_AND_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

inclusive_or_expression /* Las conversiones aritméticas usuales son realizadas; el resultado es la función OR bit a bit de los operandos. El operador sólo se aplica a operandos enteros. */
	: exclusive_or_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: inclusive_or_expression -> exclusive_or_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| inclusive_or_expression '|' exclusive_or_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(INCLUSIVE_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
/*	| logical_and_expression '|' error            
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  inclusive_or_expression '|' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: inclusive_or_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(INCLUSIVE_OR_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
*/		
	;

exclusive_or_expression /* Las conversiones aritméticas usuales son realizadas; el resultado es la función XOR bit a bit de los operandos. El operador sólo se aplica a operandos enteros. */
	: and_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: exclusive_or_expression -> and_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| exclusive_or_expression '^' and_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: exclusive_or_expression -> exclusive_or_expression '^' and_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(EXCLUSIVE_OR_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
/*	| exclusive_or_expression '^' error            
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  exclusive_or_expression '^' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: exclusive_or_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(EXCLUSIVE_OR_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}	*/			
	;


and_expression /* Las conversiones aritméticas usuales son realizadas; el resultado es la función AND bit a bit de los operandos. El operador sólo se aplica a operandos enteros. */
	: equality_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> equality_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| and_expression '&' equality_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> and_expression '&' equality_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast(AND_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| and_expression '&' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: and_expression -> and_expression '&' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: and_expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(AND_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
	;

equality_expression /* Los operadores "==" (igual a) y "!=" (distinto a) son análogos a los operadores relacionales excepto por su menor precedencia (así "a < b == c < d" es 1 cuando sea que "a < b" y "c < d" tienen el mismo valor de verdad). Los operadores de igualdad siguen las mismas reglas que los operadores relacionales, pero permiten posibilidades adicionales: un puntero puede ser comparado con una expresión entera constante con valor 0, o con un puntero a void (void*). */
	: relational_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> relational_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| equality_expression "==" relational_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> equality_expression \"==\" relational_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_equality_expression(IGUALDAD, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| equality_expression "==" error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: equallity_expression -> equality_expression \"==\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: equality_expression \"==\"  \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(EQUALITY_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| equality_expression "!=" relational_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: equality_expression -> equality_expression \"!=\" relational_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_equality_expression(DIFERENCIA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| equality_expression "!=" error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: equallity_expression -> equality_expression \"!=\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: equality_expression \"!=\"  \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(EQUALITY_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
	;

relational_expression /* Los operadores relacionales se agrupan de izquierda a derecha, pero este hecho no es útil; "a < b < c" es analizado sintácticamente como "(a < b) < c", y "a < b" es evaluado como 0 ó 1. Los operadores < (menor), > (mayor), <= (menor o igual) y >=  (mayor o igual), todos producen 0 si la relación especificada es falsa y 1 si es verdadera. El tipo del resultado es "int". Las conversiones aritméticas usuales son realizadas sobre los operandos aritméticos. Punteros a objetos del mismo tipo (ignorando cualquier califificador de tipo) puede ser comparado; el resultado dependede las ubicaciones relativas en el espacio de direcciones de memoria de los objetos apuntados. La comparación de punteros sólo está definida para partes del mismo objeto: si dos punteros apuntan al mismo objeto simple, se comparan como iguales; si los punteros son hacia miembros de la misma estructura, los punteros hacia objetos declarados más adelante en la estructura se comparan como mayores; si los punteros son hacia miembros de la misma unión, se comparan como iguales; si los punteros hacen referencia a miembros de un arreglo, la comparación es equivalente a la comparación de los correspondientes subíndices. Si P apunta al último miembro de un arreglo, entonces "P + 1" se compara como mayor que P, a pesar de que "P + 1" apunta afuera del arreglo. En caso contrario, la comparación de punteros es indefinida. */
	: shift_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> shift_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| relational_expression '<' shift_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '<' shift_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_relational_expression(MENOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| relational_expression '<' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '<' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression '<'  \n", archivo_yyin, @1.first_line, @1.first_column);
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| relational_expression '>' shift_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '>' shift_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_relational_expression(MAYOR, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| relational_expression '>' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression '>' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression '>'  \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| relational_expression "<=" shift_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression \"<=\" shift_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_relational_expression(MENOR_O_IGUAL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| relational_expression "<=" error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> error \"<=\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression \"<=\"  \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| relational_expression ">=" shift_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> relational_expression \">=\" shift_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_relational_expression(MAYOR_O_IGUAL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			} 
	| relational_expression ">=" error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: relational_expression -> error \">=\" error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: relational_expression \"!=\"  \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(RELATIONAL_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

shift_expression /* Los operadores de corrimiento "<<" y ">>" son agrupados de izquierda a derecha. Para ambos operadores, cada operando debe ser entero, y está sujeto a las promociones enteras. El tipo del resultado es el del operando izquierdo promovido. El resultado es indefinido si el operando derecho es negativo, o mayor o igual que el número de bits en el tipo de la expresión izquierda. El valor de "E1 << E2" es "E1" (interpretado como un patrón de bits) corrido hacia la izquierda E2 bits; en la ausencia de desbordamiento, esto es equivalente a la multiplicación por 2 elevado a la E2. El valor de "E1 >> E2" es E1 corrido hacia la derecha E2 posiciones de bit. El corrimiento derecho es equivalente a la división por 2 elevado a la E2 si E1 es "unsigned" o si tiene un valor no negativo; de lo contrario el resultado es definido según la implementación. */
	: additive_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> additive_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| shift_expression "<<" additive_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> shift_expression \"<<\" additive_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_shift_expression(DESPLAZAMIENTO_IZQUIERDA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| shift_expression ">>" additive_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: shift_expression -> shift_expression \">>\" additive_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_shift_expression(DESPLAZAMIENTO_DERECHA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	;

additive_expression /* Los operadores aditivos + y - se agrupan de izquierda a derecha. Si los operandos tienen tipos aritméticos, la conversiones aritméticas uisuales son realizadas. Hay algunas posibilidades de tipo adicionales para cada operador. */
	: multiplicative_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> multiplicative_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| additive_expression '+' multiplicative_expression /* El resultado del operador + es la suma de los operandos. Un puntero a un objeto en un arreglo y un valor de cualquier tipo entero pueden ser sumados. Este último es convertido a un offset (desplazamiento) de direcciones de memoria multiplicándolo por el tamaño del objeto al cual el puntero apunta. La suma es un puntero del mismo tipo que el del puntero original, y apunta a otro objeto en el mismo arreglo, desplazado apropiadamente del objeto original. Por lo tanto si P es un puntero a un objeto en un arreglo, la expresión "P + 1" es un puntero al  siguiente objeto en el arreglo. Si el puntero de la suma apunta hacia afuera de los límites del arreglo, con excepción de la primera ubicación más allá del extremo superior, el resultado es indefinido. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> additive_expression '+' multiplicative_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_additive_expression(SUMA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| additive_expression '+' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression '+' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ADDITIVE_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| additive_expression '-' multiplicative_expression /* El resultado del operador - es la diferenciua de los operandos. Un valor de cualquier tipo entero puede ser restado de un puntero, y luego las mismas conversiones y condiciones como para la suma aplican. Si dos punteros a objetos del mismo tipo son restados, el resultado es un valor entero "signed" representando el desplazamiento entre los objetos apuntados; punteros a objetos sucesivos difieren en 1. El tipo del resultado depende de la implementación, pero es definido como ptrdiff_t in el header estándar <stddef.h>. El valor es indefinido a menos de que los punteros apunten a objetos dentro del mismo arreglo; sin embargo si P apunta hacia el último miembro de un arreglo, entonces "(P + 1) - P" tiene valor 1. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: additive_expression -> additive_expression '-' multiplicative_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_additive_expression(RESTA, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| additive_expression '-' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  additive_expression '-' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ADDITIVE_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

multiplicative_expression /* Los operadores multiplicativos *, / y % se agrupan de izquierda a derecha */
	: cast_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> cast_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| multiplicative_expression '*' cast_expression /* El operador binario * denota multiplicación. Los operandos deben tener tipo aritmético. Las conversiones aritméticas usuales son realizadas sobre los operandos, y predicen el tipo del resultado. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '*' cast_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_multiplicative_expression(MULTIPLICACION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| multiplicative_expression '*' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '*' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| multiplicative_expression '/' cast_expression /* El operador binario / produce el cociente de la división del primer operando por el segundo; si el segundo operando es 0, el resultado es indefinido. De lo contrario, siempre es cierto que "(a / b) * b + a % b" es igual a "a". Los operandos deben tener tipo aritmético. Las conversiones aritméticas usuales son realizadas sobre los operandos, y predicen el tipo del resultado. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '/' cast_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_multiplicative_expression(DIVISION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| multiplicative_expression '/' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '/' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	| multiplicative_expression '%' cast_expression /* El operador binario % produce el resto (rem) de la división del primer operando por el segundo; si el segundo operando es 0, el resultado es indefinido. De lo contrario, siempre es cierto que "(a / b) * b + a % b" es igual a "a". Si ambos operandos no son negativos, entonces el resto es no negativo y menor que el divisor; si no, sólo es garantizado que el valor absoluto del resto es más pequeño que el valor absoluto del divisor. Los operandos deben tener tipo entero. Las conversiones aritméticas usuales son realizadas sobre los operandos, y predicen el tipo del resultado. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: multiplicative_expression -> multiplicative_expression '%%' cast_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_multiplicative_expression(RESTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, $3);
			}
	| multiplicative_expression '%' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla:  multiplicative_expression '%%' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: expression \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(MULTIPLICATIVE_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}		
	;

cast_expression
	: unary_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: cast_expression -> unary_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| '(' { bandera_podria_usarse_un_nombre_de_typedef = TRUE; } type_name ')' cast_expression /* Una expresión unaria precedida por un nombre de tipo entre paréntesis causa la conversión del valor de la expresión al tipo nombrado. Una expresión con una conversión no es un Valor-L. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: cast_expression -> '(' {} type_name ')' cast_expression \n", @1.first_line, @1.first_column, @5.last_line, @5.last_column);
				$$ = crear_nodo_ast(CAST_EXPRESSION, NULL, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @5.last_line, .last_column = @5.last_column}), $3, $5);
			}
	;

unary_expression /* Las expresiones con operadores unarios se agrupan de derecha a izquierda. */
	: postfix_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> postfix_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
					}
				}
				$$ = $1;
			}
	| "++" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } unary_expression /* Una expresión unaria precedida por un operador "++" ó "--" es una expresión unaria. El operando es incrementado (++) o decrementado (--) por 1. El valor de la expresión es el valor luego de la incrementacion/decrementación. El operando debe ser un Valor-L. El resultado no es un Valor-L. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"++\" {} unary_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_unary_expression(PREINCREMENTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $3, NULL);
			}
	| "--" { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } unary_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"--\" {} unary_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_unary_expression(PREDECREMENTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $3, NULL);
			}
	| unary_operator cast_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> unary_operator cast_expression \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				$$ = crear_nodo_ast_enumeracion_unary_expression($1, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $2, NULL);
			}
	| "sizeof" { bandera_podria_usarse_un_nombre_de_typedef = TRUE; } factorizacion_unary_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_expression -> \"sizeof\" {} factorizacion_unary_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				($3 -> ubicacion).first_line = @1.first_line;
				($3 -> ubicacion).first_column = @1.first_column;
				$$ = $3;
			}
	;

factorizacion_unary_expression
	: unary_expression /* El operador "sizeof" produce el número de bytes requeridos para almacenar un objeto del tipo de su operando. El operando es ya sea una expresión, la cual no es evaluada, o un nombre de tipo entre paréntesis. Cuando "sizeof" es aplicado a un char,  el resultado es 1; cuando es aplicado a un arreglo, el resultado es el número total de bytes en el array. Cuando es aplicado a una estructura o a una unión, el resultadoes el número de bytes en el objeto, incluyendo cualquier relleno requerido para hacer que el objeto complete un arreglo: el tamaño de un arreglo de n elementos es n veces el tamaño de un elemento. El operador no puede ser aplicado a un operando de tipo función, o de tipo incompleto, o a un campo de bits. El resultado es una constante entera "unsigned"; el tipo particular es definido por la implementación. El header estándar <stddef.h> define este tipo como size_t */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_unary_expression -> unary_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_nodo_ast_enumeracion_unary_expression(SIZEOF, @1, $1, NULL);
			}
	| '(' type_name ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: factorizacion_unary_expression -> '(' {} type_name ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_unary_expression(SIZEOF, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $2, NULL);
			}
	;

unary_operator
	: '&' /* El operador unario de referenciación toma la dirección de memoria de su operando. El operando debe ser un Valor-L que no se refiera a un campo de bits ni a un objeto declarado como "register", o debe ser de un tipo función. El resultado es un puntero al objeto o función referido por el Valor-L. Si el tipo del operando es T, el tipo del resultado es "puntero a T". */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '&' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = REFERENCIACION;
			}
	| '*' /* El operador unario de desreferenciación denota indirección, y returna el objeto o función al cual su operando apunta. Es un Valor-L si el operando es un puntero a un objeto de tipo aritmético, estructura, unión o puntero. Si el tipo de la expresión es "puntero a T", el tipo del resultado es T. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '*' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = DESREFERENCIACION;
			}
	| '+' /* El operando del operador unario de signo + debe tener un tipo aritmético, y el resultado es el valor del operando. Un operando entero recibe promoción entera. El tipo del resultado es el tipo de operando promovido. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '+' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = SIGNO_MAS;
			}
	| '-' /* El operando del operador unario de signo - debe tener un tipo aritmético, y el resultado es el negativo de su operando. Un operando entero recibe promoción entera. El negativo de una cantidad "unsigned" es computado sustrayendo el valor promovido del mayor valor del tipo promovido y sumando 1; pero el negativo de cero es cero. El tipo del resultado es el tipo de operando promovido. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '-' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = SIGNO_MENOS;
			}
	| '~' /* El operando del operador complemento a uno debe tener un tipo entero, y el resultado es es el complemento a uno de su operando. Las promociones enteras son realizadas. Si el operando es "unsigned",el resultado es computado sustrayendo el valor del mayor valor del tipo promovido. Si el operando es "signed", el resultado es computado conviertiendo el operando promovidoal correspondiente tipo "unsigned", aplicando ~, y conviertiendo de vuelta al tipo "signed". El tipo del resultado es el tipo del operando promovido. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '~' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = COMPLEMENTO;
			}
	| '!' /* El operando del operador de negación lógica debe tener un tipo aritmético o ser un puntero, y el resultado es 1 si el valor de su operando se compara igual a 0, y 0 de lo contrario. El tipo del resultado es int. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: unary_operator -> '!' \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = NEGACION_LOGICA;
			}
	;

postfix_expression
	: primary_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> primary_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = $1;
			}
	| postfix_expression '[' expression ']' /* Una expresión posfija seguida de una expresión entre corchetes es una expresión posfija denotando una referencia indexada a un arreglo. La primera expresión debe ser del tipo "puntero a T", donde T es algún tipo, y la segunda expresión debe ser de tipo entero; el tipo de la expresión posfija es T. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '[' expression ']' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
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
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: el valor suscrito no es ni un arreglo, ni un puntero ni un vector \n", archivo_yyin, @1.first_line, @1.first_column);
						cantidadErroresSemanticos++;
					}
				}
				$$ = crear_nodo_ast_enumeracion_postfix_expression(REFERENCIA_INDEXADA_ARREGLO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $1, $3);
			}
	| postfix_expression '(' ')' /* Una invocación a una función es una expresión posfija, llamada el designador de función, seguida de paréntesis conteniendo una lista de expresiones de asignación separadas por coma posiblemente vacía. Si la expresión posfija consiste de un identificador para el cual no existe declaración en el alcance actual, el identificador es declarado implícitamente como si la declaración "extern int identificador();" hubiera sido dado en el bloque más interno conteniendo a la invocación de la función. La expresión posfija (resultante) (luego de una posible declaración implícita y una generación de puntero) debe ser del tipo "puntero a una función que retorna T", para algún tipo T, y el valor de la invocación de la función tiene tipo T. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '(' ')' \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				$$ = crear_nodo_ast_enumeracion_postfix_expression(INVOCACION_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, NULL);
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| postfix_expression '(' argument_expression_list ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '(' argument_expression_list ')' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$$ = crear_nodo_ast_enumeracion_postfix_expression(INVOCACION_FUNCION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @4.last_line, .last_column = @4.last_column}), $1, $3);
				//imprimir_ast_postorden($$);
				resolver_ast($$);
			}
	| postfix_expression '.' IDENTIFICADOR /* Una expresión posfija seguida de un punto seguida de un identificador es una expresión posfija. La primera expresión operando debe ser una estructura o una unión, y el identificador debe nombrar un miembro de la estructura o unión. El valor es el miembro nombrado de la estructura o unión, y su tipo es el tipo del miembro. La expresión es un Valor-L si la primera expresión es un Valor-L, y si el tipo de la segunda expresión no es de un tipo arreglo. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression '.' IDENTIFICADOR \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
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
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: tipo de argumento invalido de '.' \n", archivo_yyin, @1.first_line, @1.first_column);
						cantidadErroresSemanticos++;
					}
				}
				$$ = crear_nodo_ast_enumeracion_postfix_expression(MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, (Nodo_AST*) $3);
			}
	| postfix_expression "->" IDENTIFICADOR /* Una expresión posfija seguida de una flecha seguida de un identificador es una expresión posfija. La primera expresión operando debe ser una estructura o una unión, y el identificador debe nombrar un miembro de la estructura o unión. El resultado se refiere al miembro nombrado de la estructura o unión al cual la expresión puntero apunta, y el tipo es el tipo del miembro; el resultado es un Valor-L si el tipo no es un tipo arreglo. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"->\" IDENTIFICADOR \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
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
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: tipo de argumento invalido de '->' \n", archivo_yyin, @1.first_line, @1.first_column);
						cantidadErroresSemanticos++;
					}
				}
				$$ = crear_nodo_ast_enumeracion_postfix_expression(MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), $1, (Nodo_AST*) $3);
			}
	| postfix_expression "++" /* Una expresión posfija seguida de un operador "++" ó "--" es una expresión posfija. El valor de la expresión es el valor del operando. Luego de que el valor es anotado, el operando es incrementado (++) o decrementado (--) por 1. El operando debe ser un Valor-L. El resultado no es un Valor-L. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"++\" \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
								cantidadErroresSemanticos++;
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
						cantidadErroresSemanticos++;
					}
				}
				$$ = crear_nodo_ast_enumeracion_postfix_expression(POSTINCREMENTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
			}
	| postfix_expression "--"
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: postfix_expression -> postfix_expression \"--\" \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				if(($1 -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ($1 -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ($1 -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: '%s' no declarado (primer uso en esta funcion) \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
							cantidadErroresSemanticos++;
						}
						else
						{
							if((resultadoBusqueda -> tipoSimbolo) == FUNCION)
							{
								error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
								cantidadErroresSemanticos++;
							}
						}
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando de incremento \n", archivo_yyin, @1.first_line, @1.first_column, (char*) ($1 -> hijoIzquierdo));
						cantidadErroresSemanticos++;
					}
				}
				$$ = crear_nodo_ast_enumeracion_postfix_expression(POSTDECREMENTO, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), $1, NULL);
			}
	;

argument_expression_list /* El término argumento es utilizado para una expresión pasada por una invocación a una función; el término parámetro es utilizado para un objeto de entrada (o su identificador) recibidopor la definición de una función, o descrito en una declaración de una función. En la preparación para la invocación a una función, una copia es hecha de cada argumento; todo pasaje de argumento es estrictamente por valor. */
	: assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> assignment_expression \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				$$ = crear_lista_de_nodos_ast(ARGUMENT_EXPRESSION_LIST, $1, @1);
			}
	| argument_expression_list ',' assignment_expression
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> argument_expression_list ',' assignment_expression \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
				agregar_al_final_de_lista_de_nodos_ast($1, $3, @3); $$ = $1;
			}
/*	| error ',' assignment_expression
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> argument_expression_list ',' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: argument_expression_list \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ARGUMENT_EXPRESSION_LIST, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}

	| argument_expression_list ',' error
		{
			debug_reducciones_bison_printf("\t Bison: %d:%d-%d:%d: Reduciendo por la regla: argument_expression_list -> argument_expression_list ',' error \n", @1.first_line, @1.first_column, @3.last_line, @3.last_column);
			error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: argument_expression_list \n", archivo_yyin, @1.first_line, @1.first_column); 
			yyerrok;
			$$ = crear_nodo_ast_enumeracion_error(ARGUMENT_EXPRESSION_LIST, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @3.last_line, .last_column = @3.last_column}), NULL, NULL);
		}
*/
	;

primary_expression
	: IDENTIFICADOR
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> IDENTIFICADOR \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_primary_expression(TIPO_IDENTIFICADOR, @1, (Nodo_AST*) $1, NULL);
			}
	| constante_entera
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> constante_entera \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = $1;
			}
	| constante_real
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> constante_real \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = $1;
			}
	| LITERAL_CADENA /* Un literal cadena tiene el tipo "arreglo de caracteres" y clase de almacenamiento "static", y es inicializado con los caracteres dados. El que si literales cadena idénticos son diferentes es definido por la implementación, y el comportamiento de un programa que intenta alterar un literal cadena es indefinido. */
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> LITERAL_CADENA \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				$$ = crear_nodo_ast_enumeracion_primary_expression(TIPO_LITERAL_CADENA, @1, (Nodo_AST*) $1, NULL);
			}
	| '(' { bandera_podria_usarse_un_nombre_de_typedef = FALSE; } expression ')'
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> '(' {} expression ')' \n", @1.first_line, @1.first_column, @4.last_line, @4.last_column);
				$$ = $3;
			}
/*
	| '(' error 
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: primary_expression -> '(' error \n", @1.first_line, @1.first_column, @2.last_line, @2.last_column);
				error_sintactico_fprintf(stderr, "Bison: %s:%d:%d: Error sintactico: primary_expression \n", archivo_yyin, @1.first_line, @1.first_column);
				bandera_podria_usarse_un_nombre_de_typedef = FALSE;
				yyerrok;
				$$ = crear_nodo_ast_enumeracion_error(PRIMARY_EXPRESSION, ((struct Ubicacion) {.first_line = @1.first_line, .first_column = @1.first_column, .last_line = @2.last_line, .last_column = @2.last_column}), NULL, NULL);
			}
*/
	;

constante_entera
	: CONSTANTE_ENTERA_INT_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_INT_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo int: %d \n", $1); $<int_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_INT, ((union Valor) {.int_value = $1}), @1);
			}
	| CONSTANTE_ENTERA_UNSIGNED_INT_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_UNSIGNED_INT_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo unsigned int: %u \n", $1); $<unsigned_int_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_UNSIGNED_INT, ((union Valor) {.unsigned_int_value = $1}), @1);
			}
	| CONSTANTE_ENTERA_LONG_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_LONG_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo long: %ld \n", $1); $<long_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_LONG, ((union Valor) {.long_value = $1}), @1);
			}
	| CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_entera -> CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante entera de tipo unsigned long: %lu \n", $1); $<unsigned_long_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_UNSIGNED_LONG, ((union Valor) {.unsigned_long_value = $1}), @1);
			}
	;

constante_real
	: CONSTANTE_REAL_FLOAT_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_FLOAT_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo float: %f \n", $1); $<float_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_FLOAT, ((union Valor) {.float_value = $1}), @1);

			}
	| CONSTANTE_REAL_DOUBLE_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_DOUBLE_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo double: %f \n", $1); $<double_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_DOUBLE, ((union Valor) {.double_value = $1}), @1);
			}
	| CONSTANTE_REAL_LONG_DOUBLE_TYPE
			{
				debug_reducciones_bison_printf("Bison: %d:%d-%d:%d: Reduciendo por la regla: constante_real -> CONSTANTE_REAL_LONG_DOUBLE_TYPE \n", @1.first_line, @1.first_column, @1.last_line, @1.last_column);
				debug_banderas_bison_printf("Bison: Valor semantico asociado de la constante real de tipo long double: %Lf \n", $1); $<long_double_type>$ = $1;
				$$ = crear_nodo_ast_constante(DATO_LONG_DOUBLE, ((union Valor) {.long_double_value = $1}), @1);
			}
	;

%%
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