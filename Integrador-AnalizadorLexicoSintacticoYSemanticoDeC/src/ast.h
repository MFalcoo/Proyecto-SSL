#include "tablaDeSimbolos.h"

typedef enum Tipo_Nodo_AST
{
    ERROR,

    PRIMARY_EXPRESSION,
    ARGUMENT_EXPRESSION_LIST,
    POSTFIX_EXPRESSION,
    UNARY_EXPRESSION,
    CAST_EXPRESSION,
    MULTIPLICATIVE_EXPRESSION,
    ADDITIVE_EXPRESSION,
    SHIFT_EXPRESSION,
    RELATIONAL_EXPRESSION,
    EQUALITY_EXPRESSION,
    AND_EXPRESSION,
    EXCLUSIVE_OR_EXPRESSION,
    INCLUSIVE_OR_EXPRESSION,
    LOGICAL_AND_EXPRESSION,
    LOGICAL_OR_EXPRESSION,
    CONDITIONAL_EXPRESSION,
    CONSTANT_EXPRESSION,
    ASSIGNMENT_EXPRESSION,
    EXPRESSION,
    JUMP_STATEMENT,
    ITERATION_STATEMENT,
    SELECTION_STATEMENT,
    STATEMENT_LIST,
    COMPOUND_STATEMENT,
    EXPRESSION_STATEMENT,
    LABELED_STATEMENT,
    STATEMENT,
    DIRECT_ABSTRACT_DECLARATOR,
    ABSTRACT_DECLARATOR,
    TYPE_NAME,
    INITIALIZER_LIST,
    INITIALIZER, /* ¿ Sacar el contenido enumerado ? */
    IDENTIFIER_LIST,
    PARAMETER_DECLARATION, /* ¿ Sacar el contenido enumerado ? */
    PARAMETER_LIST,
    PARAMETER_TYPE_LIST,
    TYPE_QUALIFIER_LIST,
    POINTER,
    DIRECT_DECLARATOR,
    DECLARATOR,
    ENUMERATOR,
    ENUMERATOR_LIST,
    ENUM_SPECIFIER,
    STRUCT_DECLARATOR,
    STRUCT_DECLARATOR_LIST,
    SPECIFIER_QUALIFIER_LIST,
    STRUCT_DECLARATION,
    STRUCT_DECLARATION_LIST,
    STRUCT_OR_UNION_SPECIFIER,
    TYPE_QUALIFIER,
    TYPE_SPECIFIER,
    STORAGE_CLASS_SPECIFIER,
    INIT_DECLARATOR,
    INIT_DECLARATOR_LIST,
    DECLARATION_SPECIFIERS,
    DECLARATION_LIST,
    DECLARATION,
    FUNCTION_DEFINITION,
    EXTERNAL_DECLARATION,
    TRANSLATION_UNIT
} Tipo_Nodo_AST;

typedef enum Tipo_Primary_Expression
{
    TIPO_CONSTANTE,
    TIPO_LITERAL_CADENA,
    TIPO_IDENTIFICADOR
} Tipo_Primary_Expression;

typedef enum Tipo_Postfix_Expression
{
    REFERENCIA_INDEXADA_ARREGLO,
    INVOCACION_FUNCION,
    MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION,
    MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION,
    POSTINCREMENTO,
    POSTDECREMENTO
} Tipo_Postfix_Expression;

typedef enum Tipo_Unary_Expression
{
    PREINCREMENTO,
    PREDECREMENTO,
    REFERENCIACION,
    DESREFERENCIACION,
    SIGNO_MAS,
    SIGNO_MENOS,
    COMPLEMENTO,
    NEGACION_LOGICA,
    SIZEOF
} Tipo_Unary_Expression;

typedef enum Tipo_Multiplicative_Expression
{
    MULTIPLICACION,
    DIVISION,
    RESTO
} Tipo_Multiplicative_Expression;

typedef enum Tipo_Additive_Expression
{
    SUMA,
    RESTA
} Tipo_Additive_Expression;

typedef enum Tipo_Shift_Expression
{
    DESPLAZAMIENTO_IZQUIERDA,
    DESPLAZAMIENTO_DERECHA
} Tipo_Shift_Expression;

typedef enum Tipo_Relational_Expression
{
    MENOR,
    MAYOR,
    MENOR_O_IGUAL,
    MAYOR_O_IGUAL
} Tipo_Relational_Expression;

typedef enum Tipo_Equality_Expression
{
    IGUALDAD,
    DIFERENCIA
} Tipo_Equality_Expression;

typedef enum Tipo_Assignment_Expression
{
    IGUAL,
    POR_IGUAL,
    DIVIDIDO_IGUAL,
    MOD_IGUAL,
    MAS_IGUAL,
    MENOS_IGUAL,
    ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA,
    ASIGNACION_CON_DESPLAZAMIENTO_DERECHA,
    AND_IGUAL,
    XOR_IGUAL,
    OR_IGUAL
} Tipo_Assignment_Expression;

typedef enum Tipo_Jump_Statement
{
    GOTO,
    CONTINUE,
    BREAK,
    RETURN
} Tipo_Jump_Statement;

typedef enum Tipo_Iteration_Statement
{
    WHILE,
    DO_WHILE,
    FOR
} Tipo_Iteration_Statement;

typedef enum Tipo_Selection_Statement
{
    IF,
    SWITCH
} Tipo_Selection_Statement;

typedef enum Tipo_Labeled_Statement
{
    LABEL,
    CASE,
    DEFAULT
} Tipo_Labeled_Statement;

typedef enum Tipo_Statement
{
    TIPO_LABELED_STATEMENT,
    TIPO_EXPRESSION_STATEMENT,
    TIPO_COMPOUND_STATEMENT,
    TIPO_SELECTION_STATEMENT,
    TIPO_ITERATION_STATEMENT,
    TIPO_JUMP_STATEMENT
} Tipo_Statement;

typedef enum Tipo_Direct_Abstract_Declarator
{
    TIPO_ABSTRACTO_ABSTRACT_DECLARATOR,
    TIPO_ABSTRACTO_ARREGLO,
    TIPO_ABSTRACTO_FUNCION
} Tipo_Direct_Abstract_Declarator;

typedef enum Tipo_Initializer
{
    TIPO_INITIALIZER_ASSIGNMENT_EXPRESSION,
    TIPO_INITIALIZER_INITIALIZER_LIST
} Tipo_Initializer;

typedef enum Tipo_Parameter_Declaration
{
    TIPO_PARAMETER_DECLARATION_DECLARATOR,
    TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR,
    TIPO_PARAMETER_DECLARATION_EPSILON
} Tipo_Parameter_Declaration;

typedef enum Tipo_Parameter_Type_List
{
    SIN_ELIPSIS,
    CON_ELIPSIS
} Tipo_Parameter_Type_List;

typedef enum Tipo_Direct_Declarator
{
    TIPO_NO_ABSTRACTO_IDENTIFICADOR,
    TIPO_NO_ABSTRACTO_DECLARATOR,
    TIPO_NO_ABSTRACTO_ARREGLO,
    TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA,
    TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA
} Tipo_Direct_Declarator;

typedef enum Tipo_Type_Qualifier
{
    TIPO_CONST,
    TIPO_VOLATILE
} Tipo_Type_Qualifier;

typedef enum Tipo_Type_Specifier
{
    TIPO_VOID,
    TIPO_CHAR,
    TIPO_SHORT,
    TIPO_INT,
    TIPO_LONG,
    TIPO_FLOAT,
    TIPO_DOUBLE,
    TIPO_SIGNED,
    TIPO_UNSIGNED,
    TIPO_STRUCT_OR_UNION_SPECIFIER,
    TIPO_ENUM_SPECIFIER,
    TIPO_NOMBRE_DE_TYPEDEF
} Tipo_Type_Specifier;

typedef enum Tipo_Storage_Class_Specifier
{
    TIPO_AUTO,
    TIPO_REGISTER,
    TIPO_STATIC,
    TIPO_EXTERN,
    TIPO_TYPEDEF
} Tipo_Storage_Class_Specifier;

typedef enum Tipo_External_Declaration
{
    TIPO_FUNCTION_DEFINITION,
    TIPO_DECLARATION
} Tipo_External_Declaration;

typedef struct Nodo_AST
{
    enum Tipo_Nodo_AST tipoNodoAST;
    struct Nodo_AST* contenido;
    struct Ubicacion ubicacion;

	struct Nodo_AST* hijoIzquierdo;
    struct Nodo_AST* hijoDerecho;
} Nodo_AST;

typedef struct Miembro_AST
{
	struct Nodo_AST* nodo;
    struct Ubicacion ubicacion;
    struct Miembro_AST* siguiente;
} Miembro_AST;

typedef struct Lista_AST
{
    int cantidadDeNodos;
    struct Miembro_AST* primero;
} Lista_AST;

typedef struct Contenido_Constante_AST
{
    enum Dato tipoConstante;
    union Valor valorConstante;
} Contenido_Constante_AST;

typedef struct Nodo_Condicional_AST
{
    struct Nodo_AST* condicion;
    struct Nodo_AST* then_action;
    struct Nodo_AST* else_action;
} Nodo_Condicional_AST;

typedef struct Nodo_For_AST
{
    struct Nodo_AST* inicializacion;
    struct Nodo_AST* condicion;
    struct Nodo_AST* actualizacion;
    struct Nodo_AST* sentencia;
} Nodo_For_AST;

typedef struct Nodo_Struct_or_Union_Specifier
{
    enum Struct_o_Union struct_o_union;
    struct Nodo_AST* tag;
    struct Nodo_AST* struct_declaration_list;
} Nodo_Struct_or_Union_Specifier;

typedef struct Nodo_Function_Definition_AST
{
    struct Nodo_AST* declaration_specifiers;
    struct Nodo_AST* declarator;
    struct Nodo_AST* declaration_list;
    struct Nodo_AST* compound_statement;
} Nodo_Function_Definition_AST;

Nodo_AST* crear_nodo_ast(enum Tipo_Nodo_AST, struct Nodo_AST*, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_lista_de_nodos_ast(enum Tipo_Nodo_AST, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* agregar_al_final_de_lista_de_nodos_ast(struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* agregar_al_inicio_de_lista_de_nodos_ast(struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* crear_nodo_ast_constante(enum Dato, union Valor, struct Ubicacion);
Nodo_AST* crear_nodo_ast_enumeracion_error(enum Tipo_Nodo_AST, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_primary_expression(enum Tipo_Primary_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_postfix_expression(enum Tipo_Postfix_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_unary_expression(enum Tipo_Unary_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_multiplicative_expression(enum Tipo_Multiplicative_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_additive_expression(enum Tipo_Additive_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_shift_expression(enum Tipo_Shift_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_relational_expression(enum Tipo_Relational_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_equality_expression(enum Tipo_Equality_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_assignment_expression(enum Tipo_Assignment_Expression, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_jump_statement(enum Tipo_Jump_Statement, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_iteration_statement(enum Tipo_Iteration_Statement, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_selection_statement(enum Tipo_Selection_Statement, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_labeled_statement(enum Tipo_Labeled_Statement, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_statement(enum Tipo_Statement, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_direct_abstract_declarator(enum Tipo_Direct_Abstract_Declarator, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_initializer(enum Tipo_Initializer, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_parameter_declaration(enum Tipo_Parameter_Declaration, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_parameter_type_list(enum Tipo_Parameter_Type_List, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_direct_declarator(enum Tipo_Direct_Declarator, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_type_qualifier(enum Tipo_Type_Qualifier, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_type_specifier(enum Tipo_Type_Specifier, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_storage_class_specifier(enum Tipo_Storage_Class_Specifier, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_enumeracion_external_declaration(enum Tipo_External_Declaration, struct Ubicacion, struct Nodo_AST*, struct Nodo_AST*);
Nodo_AST* crear_nodo_ast_conditional_expression(struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* crear_nodo_ast_for(struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* crear_nodo_ast_if(struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* crear_nodo_ast_struct_or_union_specifier(struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
Nodo_AST* crear_nodo_ast_function_definition(struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Nodo_AST*, struct Ubicacion);
void imprimir_ast_postorden(struct Nodo_AST*);