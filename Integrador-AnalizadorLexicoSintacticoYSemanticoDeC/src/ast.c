#include "bibliotecas.h"
#include "ast.h"

Nodo_AST* crear_nodo_ast(enum Tipo_Nodo_AST tipoNodoAST, struct Nodo_AST* contenido, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	Nodo_AST* nuevo = (Nodo_AST*) malloc(sizeof (Nodo_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> tipoNodoAST = tipoNodoAST;
	nuevo -> contenido = contenido;
	nuevo -> ubicacion = ubicacion;
	nuevo -> hijoIzquierdo = hijoIzquierdo;
	nuevo -> hijoDerecho = hijoDerecho;
	return nuevo;
}

Nodo_AST* crear_lista_de_nodos_ast(enum Tipo_Nodo_AST tipoListaDeNodosAST, struct Nodo_AST* primerElemento, struct Ubicacion ubicacionPrimerElemento)
{
	Lista_AST* nuevo = (Lista_AST*) malloc(sizeof (Lista_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> cantidadDeNodos = 0;
	nuevo -> primero = NULL;
	Nodo_AST* nodoQueContieneUnaListaAST = crear_nodo_ast(tipoListaDeNodosAST, (Nodo_AST*) nuevo, ubicacionPrimerElemento, NULL, NULL);
	return agregar_al_inicio_de_lista_de_nodos_ast(nodoQueContieneUnaListaAST, primerElemento, ubicacionPrimerElemento);
}

Nodo_AST* agregar_al_final_de_lista_de_nodos_ast(struct Nodo_AST* nodoQueContieneUnaListaAST, struct Nodo_AST* nodoAAgregar, struct Ubicacion ubicacionNodoAAgregar)
{
	Lista_AST* listaDeNodosAST = (Lista_AST*) (nodoQueContieneUnaListaAST -> contenido);
	Miembro_AST* nuevo = (Miembro_AST*) malloc(sizeof (Miembro_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> nodo = nodoAAgregar;
	nuevo -> ubicacion = ubicacionNodoAAgregar;
	nuevo -> siguiente = NULL;
	
	(listaDeNodosAST -> cantidadDeNodos)++;
	struct Miembro_AST* aux = listaDeNodosAST -> primero;
	if(aux != NULL)
	{
		while((aux -> siguiente) != NULL) aux = aux -> siguiente;
		aux -> siguiente = nuevo;
	}
	else listaDeNodosAST -> primero = nuevo;

	(nodoQueContieneUnaListaAST -> ubicacion).last_line = ubicacionNodoAAgregar.last_line;
	(nodoQueContieneUnaListaAST -> ubicacion).last_column = ubicacionNodoAAgregar.last_column;
	return nodoQueContieneUnaListaAST;
}

Nodo_AST* agregar_al_inicio_de_lista_de_nodos_ast(struct Nodo_AST* nodoQueContieneUnaListaAST, struct Nodo_AST* nodoAAgregar, struct Ubicacion ubicacionNodoAAgregar)
{
	Lista_AST* listaDeNodosAST = (Lista_AST*) (nodoQueContieneUnaListaAST -> contenido);
	Miembro_AST* nuevo = (Miembro_AST*) malloc(sizeof (Miembro_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> nodo = nodoAAgregar;
	nuevo -> ubicacion = ubicacionNodoAAgregar;
	nuevo -> siguiente = listaDeNodosAST -> primero;

	(listaDeNodosAST -> cantidadDeNodos)++;
	listaDeNodosAST -> primero = nuevo;

	(nodoQueContieneUnaListaAST -> ubicacion).first_line = ubicacionNodoAAgregar.first_line;
	(nodoQueContieneUnaListaAST -> ubicacion).first_column = ubicacionNodoAAgregar.first_column;
	return nodoQueContieneUnaListaAST;
}

Nodo_AST* crear_nodo_ast_enumeracion_error(enum Tipo_Nodo_AST enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Nodo_AST* nuevo = (enum Tipo_Nodo_AST*) malloc(sizeof (enum Tipo_Nodo_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(ERROR, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_primary_expression(enum Tipo_Primary_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Primary_Expression* nuevo = (enum Tipo_Primary_Expression*) malloc(sizeof (enum Tipo_Primary_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(PRIMARY_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_postfix_expression(enum Tipo_Postfix_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Postfix_Expression* nuevo = (enum Tipo_Postfix_Expression*) malloc(sizeof (enum Tipo_Postfix_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(POSTFIX_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_unary_expression(enum Tipo_Unary_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Unary_Expression* nuevo = (enum Tipo_Unary_Expression*) malloc(sizeof (enum Tipo_Unary_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(UNARY_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_multiplicative_expression(enum Tipo_Multiplicative_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Multiplicative_Expression* nuevo = (enum Tipo_Multiplicative_Expression*) malloc(sizeof (enum Tipo_Multiplicative_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(MULTIPLICATIVE_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_additive_expression(enum Tipo_Additive_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Additive_Expression* nuevo = (enum Tipo_Additive_Expression*) malloc(sizeof (enum Tipo_Additive_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(ADDITIVE_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_shift_expression(enum Tipo_Shift_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Shift_Expression* nuevo = (enum Tipo_Shift_Expression*) malloc(sizeof (enum Tipo_Shift_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(SHIFT_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_relational_expression(enum Tipo_Relational_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Relational_Expression* nuevo = (enum Tipo_Relational_Expression*) malloc(sizeof (enum Tipo_Relational_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(RELATIONAL_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_equality_expression(enum Tipo_Equality_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Equality_Expression* nuevo = (enum Tipo_Equality_Expression*) malloc(sizeof (enum Tipo_Equality_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(EQUALITY_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_assignment_expression(enum Tipo_Assignment_Expression enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Assignment_Expression* nuevo = (enum Tipo_Assignment_Expression*) malloc(sizeof (enum Tipo_Assignment_Expression));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(ASSIGNMENT_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_jump_statement(enum Tipo_Jump_Statement enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Jump_Statement* nuevo = (enum Tipo_Jump_Statement*) malloc(sizeof (enum Tipo_Jump_Statement));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(JUMP_STATEMENT, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_iteration_statement(enum Tipo_Iteration_Statement enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Iteration_Statement* nuevo = (enum Tipo_Iteration_Statement*) malloc(sizeof (enum Tipo_Iteration_Statement));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(ITERATION_STATEMENT, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_selection_statement(enum Tipo_Selection_Statement enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Selection_Statement* nuevo = (enum Tipo_Selection_Statement*) malloc(sizeof (enum Tipo_Selection_Statement));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(SELECTION_STATEMENT, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_labeled_statement(enum Tipo_Labeled_Statement enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Labeled_Statement* nuevo = (enum Tipo_Labeled_Statement*) malloc(sizeof (enum Tipo_Labeled_Statement));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(LABELED_STATEMENT, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_statement(enum Tipo_Statement enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Statement* nuevo = (enum Tipo_Statement*) malloc(sizeof (enum Tipo_Statement));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(STATEMENT, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_direct_abstract_declarator(enum Tipo_Direct_Abstract_Declarator enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Direct_Abstract_Declarator* nuevo = (enum Tipo_Direct_Abstract_Declarator*) malloc(sizeof (enum Tipo_Direct_Abstract_Declarator));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(DIRECT_ABSTRACT_DECLARATOR, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_initializer(enum Tipo_Initializer enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Initializer* nuevo = (enum Tipo_Initializer*) malloc(sizeof (enum Tipo_Initializer));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(INITIALIZER, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_parameter_declaration(enum Tipo_Parameter_Declaration enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Parameter_Declaration* nuevo = (enum Tipo_Parameter_Declaration*) malloc(sizeof (enum Tipo_Parameter_Declaration));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(PARAMETER_DECLARATION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_parameter_type_list(enum Tipo_Parameter_Type_List enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Parameter_Type_List* nuevo = (enum Tipo_Parameter_Type_List*) malloc(sizeof (enum Tipo_Parameter_Type_List));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(PARAMETER_TYPE_LIST, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_direct_declarator(enum Tipo_Direct_Declarator enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Direct_Declarator* nuevo = (enum Tipo_Direct_Declarator*) malloc(sizeof (enum Tipo_Direct_Declarator));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(DIRECT_DECLARATOR, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_type_qualifier(enum Tipo_Type_Qualifier enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Type_Qualifier* nuevo = (enum Tipo_Type_Qualifier*) malloc(sizeof (enum Tipo_Type_Qualifier));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(TYPE_QUALIFIER, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_type_specifier(enum Tipo_Type_Specifier enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Type_Specifier* nuevo = (enum Tipo_Type_Specifier*) malloc(sizeof (enum Tipo_Type_Specifier));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(TYPE_SPECIFIER, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_storage_class_specifier(enum Tipo_Storage_Class_Specifier enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_Storage_Class_Specifier* nuevo = (enum Tipo_Storage_Class_Specifier*) malloc(sizeof (enum Tipo_Storage_Class_Specifier));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(STORAGE_CLASS_SPECIFIER, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_enumeracion_external_declaration(enum Tipo_External_Declaration enumerador, struct Ubicacion ubicacion, struct Nodo_AST* hijoIzquierdo, struct Nodo_AST* hijoDerecho)
{
	enum Tipo_External_Declaration* nuevo = (enum Tipo_External_Declaration*) malloc(sizeof (enum Tipo_External_Declaration));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	*nuevo = enumerador;
	return crear_nodo_ast(EXTERNAL_DECLARATION, (Nodo_AST*) nuevo, ubicacion, hijoIzquierdo, hijoDerecho);
}

Nodo_AST* crear_nodo_ast_constante(enum Dato tipoConstante, union Valor valorConstante, struct Ubicacion ubicacion)
{
	Contenido_Constante_AST* nuevo = (Contenido_Constante_AST*) malloc(sizeof (Contenido_Constante_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> tipoConstante = tipoConstante;
	nuevo -> valorConstante = valorConstante;
	return crear_nodo_ast_enumeracion_primary_expression(TIPO_CONSTANTE, ubicacion, (Nodo_AST*) nuevo, NULL);
}

Nodo_AST* crear_nodo_ast_conditional_expression(struct Nodo_AST* condicion, struct Nodo_AST* then_action, struct Nodo_AST* else_action, struct Ubicacion ubicacion)
{
	Nodo_Condicional_AST* nuevo = (Nodo_Condicional_AST*) malloc(sizeof (Nodo_Condicional_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> condicion = condicion;
	nuevo -> then_action = then_action;
	nuevo -> else_action = else_action;
	return crear_nodo_ast(CONDITIONAL_EXPRESSION, (Nodo_AST*) nuevo, ubicacion, NULL, NULL);
}

Nodo_AST* crear_nodo_ast_for(struct Nodo_AST* inicializacion, struct Nodo_AST* condicion, struct Nodo_AST* actualizacion, struct Nodo_AST* sentencia, struct Ubicacion ubicacion)
{
	Nodo_For_AST* nuevo = (Nodo_For_AST*) malloc(sizeof (Nodo_For_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> inicializacion = inicializacion;
	nuevo -> condicion = condicion;
	nuevo -> actualizacion = actualizacion;
	nuevo -> sentencia = sentencia;
	return crear_nodo_ast_enumeracion_iteration_statement(FOR, ubicacion, (Nodo_AST*) nuevo, NULL);
}

Nodo_AST* crear_nodo_ast_if(struct Nodo_AST* condicion, struct Nodo_AST* then_action, struct Nodo_AST* else_action, struct Ubicacion ubicacion)
{
	Nodo_Condicional_AST* nuevo = (Nodo_Condicional_AST*) malloc(sizeof (Nodo_Condicional_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> condicion = condicion;
	nuevo -> then_action = then_action;
	nuevo -> else_action = else_action;
	return crear_nodo_ast_enumeracion_selection_statement(IF, ubicacion, (Nodo_AST*) nuevo, NULL);
}

Nodo_AST* crear_nodo_ast_struct_or_union_specifier(struct Nodo_AST* tag, struct Nodo_AST* struct_declaration_list, struct Ubicacion ubicacion)
{
	Nodo_Struct_or_Union_Specifier* nuevo = (Nodo_Struct_or_Union_Specifier*) malloc(sizeof (Nodo_Struct_or_Union_Specifier));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> tag = tag;
	nuevo -> struct_declaration_list = struct_declaration_list;
	return crear_nodo_ast(STRUCT_OR_UNION_SPECIFIER, (Nodo_AST*) nuevo, ubicacion, NULL, NULL);
}

Nodo_AST* crear_nodo_ast_function_definition(struct Nodo_AST* declaration_specifiers, struct Nodo_AST* declarator, struct Nodo_AST* declaration_list, struct Nodo_AST* compound_statement, struct Ubicacion ubicacion)
{
	Nodo_Function_Definition_AST* nuevo = (Nodo_Function_Definition_AST*) malloc(sizeof (Nodo_Function_Definition_AST));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
	nuevo -> declaration_specifiers = declaration_specifiers;
	nuevo -> declarator = declarator;
	nuevo -> declaration_list = declaration_list;
	nuevo -> compound_statement = compound_statement;
	return crear_nodo_ast(FUNCTION_DEFINITION, (Nodo_AST*) nuevo, ubicacion, NULL, NULL);
}

void imprimir_ast_postorden(struct Nodo_AST* raiz)
{
	if(raiz != NULL)
	{
		Miembro_AST* aux;

		switch(raiz -> tipoNodoAST)
		{
			case ERROR:
				switch(*((enum Tipo_Nodo_AST*) (raiz -> contenido)))
				{
					case ERROR:
						errorCritico("Error de programa: imprimir_ast_postorden: tipoNodoAST ERROR de tipo ERROR");
					break;
					case PRIMARY_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: PRIMARY_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ARGUMENT_EXPRESSION_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: ARGUMENT_EXPRESSION_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case POSTFIX_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: POSTFIX_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case UNARY_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: UNARY_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case CAST_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: CAST_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MULTIPLICATIVE_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: MULTIPLICATIVE_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ADDITIVE_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: ADDITIVE_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SHIFT_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: SHIFT_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case RELATIONAL_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: RELATIONAL_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case EQUALITY_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: EQUALITY_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case AND_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: AND_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case EXCLUSIVE_OR_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: EXCLUSIVE_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INCLUSIVE_OR_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: INCLUSIVE_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case LOGICAL_AND_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: LOGICAL_AND_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case LOGICAL_OR_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: LOGICAL_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case CONDITIONAL_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: CONDITIONAL_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case CONSTANT_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: CONSTANT_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ASSIGNMENT_EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: ASSIGNMENT_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case EXPRESSION:
						printf("AST: %d:%d-%d:%d: ERROR: EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case JUMP_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: JUMP_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ITERATION_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: ITERATION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SELECTION_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: SELECTION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STATEMENT_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: STATEMENT_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case COMPOUND_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: COMPOUND_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case EXPRESSION_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: EXPRESSION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case LABELED_STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: LABELED_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STATEMENT:
						printf("AST: %d:%d-%d:%d: ERROR: STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DIRECT_ABSTRACT_DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: DIRECT_ABSTRACT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ABSTRACT_DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: ABSTRACT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TYPE_NAME:
						printf("AST: %d:%d-%d:%d: ERROR: TYPE_NAME \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INITIALIZER_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: INITIALIZER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INITIALIZER:
						printf("AST: %d:%d-%d:%d: ERROR: INITIALIZER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case IDENTIFIER_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: IDENTIFIER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case PARAMETER_DECLARATION:
						printf("AST: %d:%d-%d:%d: ERROR: PARAMETER_DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case PARAMETER_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: PARAMETER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case PARAMETER_TYPE_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: PARAMETER_TYPE_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TYPE_QUALIFIER_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: TYPE_QUALIFIER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case POINTER:
						printf("AST: %d:%d-%d:%d: ERROR: POINTER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DIRECT_DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: DIRECT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ENUMERATOR:
						printf("AST: %d:%d-%d:%d: ERROR: ENUMERATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ENUMERATOR_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: ENUMERATOR_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ENUM_SPECIFIER:
						printf("AST: %d:%d-%d:%d: ERROR: ENUM_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STRUCT_DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: STRUCT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STRUCT_DECLARATOR_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: STRUCT_DECLARATOR_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SPECIFIER_QUALIFIER_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: SPECIFIER_QUALIFIER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STRUCT_DECLARATION:
						printf("AST: %d:%d-%d:%d: ERROR: STRUCT_DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STRUCT_DECLARATION_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: STRUCT_DECLARATION_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STRUCT_OR_UNION_SPECIFIER:
						printf("AST: %d:%d-%d:%d: ERROR: STRUCT_OR_UNION_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TYPE_QUALIFIER:
						printf("AST: %d:%d-%d:%d: ERROR: TYPE_QUALIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TYPE_SPECIFIER:
						printf("AST: %d:%d-%d:%d: ERROR: TYPE_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case STORAGE_CLASS_SPECIFIER:
						printf("AST: %d:%d-%d:%d: ERROR: STORAGE_CLASS_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INIT_DECLARATOR:
						printf("AST: %d:%d-%d:%d: ERROR: INIT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INIT_DECLARATOR_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: INIT_DECLARATOR_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DECLARATION_SPECIFIERS:
						printf("AST: %d:%d-%d:%d: ERROR: DECLARATION_SPECIFIERS \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DECLARATION_LIST:
						printf("AST: %d:%d-%d:%d: ERROR: DECLARATION_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DECLARATION:
						printf("AST: %d:%d-%d:%d: ERROR: DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case FUNCTION_DEFINITION:
						printf("AST: %d:%d-%d:%d: ERROR: FUNCTION_DEFINITION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case EXTERNAL_DECLARATION:
						printf("AST: %d:%d-%d:%d: ERROR: EXTERNAL_DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TRANSLATION_UNIT:
						printf("AST: %d:%d-%d:%d: ERROR: TRANSLATION_UNIT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case PRIMARY_EXPRESSION:
				switch(*((enum Tipo_Primary_Expression*) (raiz -> contenido)))
				{
					case TIPO_CONSTANTE:
						switch(((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> tipoConstante)
						{
							case DATO_INT:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante entera de tipo int: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).int_value);
							break;
							case DATO_UNSIGNED_INT:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante entera de tipo unsigned int: %u \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).unsigned_int_value);
							break;
							case DATO_LONG:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante entera de tipo long: %ld \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).long_value);
							break;
							case DATO_UNSIGNED_LONG:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante entera de tipo unsigned long: %lu \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).unsigned_long_value);
							break;
							case DATO_FLOAT:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante real de tipo float: %f \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).float_value);
							break;
							case DATO_DOUBLE:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante real de tipo double: %f \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).double_value);
							break;
							case DATO_LONG_DOUBLE:
								printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Constante real de tipo long double: %Lf \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (((Contenido_Constante_AST*) (raiz -> hijoIzquierdo)) -> valorConstante).long_double_value);
							break;
							default:
								errorCritico("Error de programa: AST: PRIMARY_EXPRESSION: Constante de tipo incorrecto");
							break;
						}
					break;
					case TIPO_LITERAL_CADENA:
						printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Literal cadena: %s \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoIzquierdo));
					break;
					case TIPO_IDENTIFICADOR:
						printf("AST: %d:%d-%d:%d: PRIMARY_EXPRESSION: Identificador: %s \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoIzquierdo));
					break;
				}
			break;
			case ARGUMENT_EXPRESSION_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: ARGUMENT_EXPRESSION_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case POSTFIX_EXPRESSION:
				switch(*((enum Tipo_Postfix_Expression*) (raiz -> contenido)))
				{
					case REFERENCIA_INDEXADA_ARREGLO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: REFERENCIA_INDEXADA_ARREGLO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case INVOCACION_FUNCION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: INVOCACION_FUNCION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION: %s", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoDerecho));
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: MIEMBRO_DE_ESTRUCTURA_SIN_DESREFERENCIACION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION: %s", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoDerecho));
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case POSTINCREMENTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: POSTINCREMENTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case POSTDECREMENTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: POSTFIX_EXPRESSION: POSTDECREMENTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case UNARY_EXPRESSION:
				switch(*((enum Tipo_Unary_Expression*) (raiz -> contenido)))
				{
					case PREINCREMENTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: PREINCREMENTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case PREDECREMENTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: PREDECREMENTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case REFERENCIACION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: REFERENCIACION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DESREFERENCIACION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: DESREFERENCIACION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SIGNO_MAS:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: SIGNO_MAS \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SIGNO_MENOS:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: SIGNO_MENOS \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case COMPLEMENTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: COMPLEMENTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case NEGACION_LOGICA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: NEGACION_LOGICA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SIZEOF:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: UNARY_EXPRESSION: SIZEOF \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case CAST_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: CAST_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case MULTIPLICATIVE_EXPRESSION:
				switch(*((enum Tipo_Multiplicative_Expression*) (raiz -> contenido)))
				{
					case MULTIPLICACION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: MULTIPLICATIVE_EXPRESSION: MULTIPLICACION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DIVISION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: MULTIPLICATIVE_EXPRESSION: DIVISION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case RESTO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: MULTIPLICATIVE_EXPRESSION: RESTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case ADDITIVE_EXPRESSION:
				switch(*((enum Tipo_Additive_Expression*) (raiz -> contenido)))
				{
					case SUMA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ADDITIVE_EXPRESSION: SUMA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case RESTA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ADDITIVE_EXPRESSION: RESTA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case SHIFT_EXPRESSION:
				switch(*((enum Tipo_Shift_Expression*) (raiz -> contenido)))
				{
					case DESPLAZAMIENTO_IZQUIERDA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: SHIFT_EXPRESSION: DESPLAZAMIENTO_IZQUIERDA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DESPLAZAMIENTO_DERECHA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: SHIFT_EXPRESSION: DESPLAZAMIENTO_DERECHA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case RELATIONAL_EXPRESSION:
				switch(*((enum Tipo_Relational_Expression*) (raiz -> contenido)))
				{
					case MENOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: RELATIONAL_EXPRESSION: MENOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MAYOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: RELATIONAL_EXPRESSION: MAYOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MENOR_O_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: RELATIONAL_EXPRESSION: MENOR_O_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MAYOR_O_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: RELATIONAL_EXPRESSION: MAYOR_O_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case EQUALITY_EXPRESSION:
				switch(*((enum Tipo_Equality_Expression*) (raiz -> contenido)))
				{
					case IGUALDAD:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: EQUALITY_EXPRESSION: IGUALDAD \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DIFERENCIA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: EQUALITY_EXPRESSION: DIFERENCIA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case AND_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: AND_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case EXCLUSIVE_OR_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: EXCLUSIVE_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case INCLUSIVE_OR_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: INCLUSIVE_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case LOGICAL_AND_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: LOGICAL_AND_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case LOGICAL_OR_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: LOGICAL_OR_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case CONDITIONAL_EXPRESSION:
				imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> contenido)) -> condicion);
				imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> contenido)) -> then_action);
				imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> contenido)) -> else_action);
				printf("AST: %d:%d-%d:%d: CONDITIONAL_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case CONSTANT_EXPRESSION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				printf("AST: %d:%d-%d:%d: CONSTANT_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case ASSIGNMENT_EXPRESSION:
				switch(*((enum Tipo_Assignment_Expression*) (raiz -> contenido)))
				{
					case IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case POR_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: POR_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DIVIDIDO_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: DIVIDIDO_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MOD_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: MOD_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MAS_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: MAS_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case MENOS_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: MENOS_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case ASIGNACION_CON_DESPLAZAMIENTO_DERECHA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: ASIGNACION_CON_DESPLAZAMIENTO_DERECHA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case AND_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: AND_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case XOR_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: XOR_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case OR_IGUAL:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ASSIGNMENT_EXPRESSION: OR_IGUAL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case EXPRESSION:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: EXPRESSION: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case JUMP_STATEMENT:
				switch(*((enum Tipo_Jump_Statement*) (raiz -> contenido)))
				{
					case GOTO:
						printf("AST: %d:%d-%d:%d: JUMP_STATEMENT: GOTO (IDENTIFICADOR: %s) \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoIzquierdo));
					break;
					case CONTINUE:
						printf("AST: %d:%d-%d:%d: JUMP_STATEMENT: CONTINUE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case BREAK:
						printf("AST: %d:%d-%d:%d: JUMP_STATEMENT: BREAK \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case RETURN:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: JUMP_STATEMENT: RETURN \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case ITERATION_STATEMENT:
				switch(*((enum Tipo_Iteration_Statement*) (raiz -> contenido)))
				{
					case WHILE:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ITERATION_STATEMENT: WHILE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DO_WHILE:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: ITERATION_STATEMENT: DO_WHILE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case FOR:
						imprimir_ast_postorden(((Nodo_For_AST*) (raiz -> hijoIzquierdo)) -> inicializacion);
						imprimir_ast_postorden(((Nodo_For_AST*) (raiz -> hijoIzquierdo)) -> condicion);
						imprimir_ast_postorden(((Nodo_For_AST*) (raiz -> hijoIzquierdo)) -> actualizacion);
						imprimir_ast_postorden(((Nodo_For_AST*) (raiz -> hijoIzquierdo)) -> sentencia);
						printf("AST: %d:%d-%d:%d: ITERATION_STATEMENT: FOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case SELECTION_STATEMENT:
				switch(*((enum Tipo_Selection_Statement*) (raiz -> contenido)))
				{
					case IF:
						imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> hijoIzquierdo)) -> condicion);
						imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> hijoIzquierdo)) -> then_action);
						imprimir_ast_postorden(((Nodo_Condicional_AST*) (raiz -> hijoIzquierdo)) -> else_action);
						printf("AST: %d:%d-%d:%d: SELECTION_STATEMENT: IF \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case SWITCH:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: SELECTION_STATEMENT: SWITCH \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case STATEMENT_LIST:
				aux = ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: STATEMENT_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case COMPOUND_STATEMENT:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: COMPOUND_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case EXPRESSION_STATEMENT:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				printf("AST: %d:%d-%d:%d: EXPRESSION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case LABELED_STATEMENT:
				switch(*((enum Tipo_Labeled_Statement*) (raiz -> contenido)))
				{
					case LABEL:
						/* FALTA UBICACIÓN */ printf("AST: LABEL IDENTIFICADOR: %s \n", (char*) (raiz -> hijoIzquierdo));
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: LABELED_STATEMENT: LABEL \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case CASE:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: LABELED_STATEMENT: CASE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case DEFAULT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: LABELED_STATEMENT: DEFAULT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case STATEMENT:
				switch(*((enum Tipo_Statement*) (raiz -> contenido)))
				{
					case TIPO_LABELED_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: LABELED_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_EXPRESSION_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: EXPRESSION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_COMPOUND_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: COMPOUND_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_SELECTION_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: SELECTION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_ITERATION_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: ITERATION_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_JUMP_STATEMENT:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: STATEMENT: JUMP_STATEMENT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case DIRECT_ABSTRACT_DECLARATOR:
				switch(*((enum Tipo_Direct_Abstract_Declarator*) (raiz -> contenido)))
				{
					case TIPO_ABSTRACTO_ABSTRACT_DECLARATOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: DIRECT_ABSTRACT_DECLARATOR: TIPO_ABSTRACTO_ABSTRACT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_ABSTRACTO_ARREGLO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: DIRECT_ABSTRACT_DECLARATOR: TIPO_ABSTRACTO_ARREGLO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_ABSTRACTO_FUNCION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: DIRECT_ABSTRACT_DECLARATOR: TIPO_ABSTRACTO_FUNCION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case ABSTRACT_DECLARATOR:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: ABSTRACT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case TYPE_NAME:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: TYPE_NAME \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case INITIALIZER_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: INITIALIZER_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case INITIALIZER:
				switch(*((enum Tipo_Initializer*) (raiz -> contenido)))
				{
					case TIPO_INITIALIZER_ASSIGNMENT_EXPRESSION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: INITIALIZER: TIPO_INITIALIZER_ASSIGNMENT_EXPRESSION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_INITIALIZER_INITIALIZER_LIST:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: INITIALIZER: TIPO_INITIALIZER_INITIALIZER_LIST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case IDENTIFIER_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: IDENTIFIER_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case PARAMETER_DECLARATION:
				switch(*((enum Tipo_Parameter_Declaration*) (raiz -> contenido)))
				{
					case TIPO_PARAMETER_DECLARATION_DECLARATOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: PARAMETER_DECLARATION: TIPO_PARAMETER_DECLARATION_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: PARAMETER_DECLARATION: TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_PARAMETER_DECLARATION_EPSILON:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: PARAMETER_DECLARATION: TIPO_PARAMETER_DECLARATION_EPSILON \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case PARAMETER_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: PARAMETER_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case PARAMETER_TYPE_LIST:
				switch(*((enum Tipo_Parameter_Type_List*) (raiz -> contenido)))
				{
					case SIN_ELIPSIS:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: PARAMETER_TYPE_LIST: SIN_ELIPSIS \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case CON_ELIPSIS:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: PARAMETER_TYPE_LIST: CON_ELIPSIS \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case TYPE_QUALIFIER_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: TYPE_QUALIFIER_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case POINTER:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: POINTER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case DIRECT_DECLARATOR:
				switch(*((enum Tipo_Direct_Declarator*) (raiz -> contenido)))
				{
					case TIPO_NO_ABSTRACTO_IDENTIFICADOR:
						printf("AST: %d:%d-%d:%d: DIRECT_DECLARATOR: TIPO_NO_ABSTRACTO_IDENTIFICADOR: %s \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, (char*) (raiz -> hijoIzquierdo));
					break;
					case TIPO_NO_ABSTRACTO_DECLARATOR:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: DIRECT_DECLARATOR: TIPO_NO_ABSTRACTO_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_NO_ABSTRACTO_ARREGLO:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: DIRECT_DECLARATOR: TIPO_NO_ABSTRACTO_ARREGLO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: DIRECT_DECLARATOR: TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						imprimir_ast_postorden(raiz -> hijoDerecho);
						printf("AST: %d:%d-%d:%d: DIRECT_DECLARATOR: TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case DECLARATOR:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case ENUMERATOR:
				/* FALTA UBICACIÓN */ printf("AST: IDENTIFICADOR de DECLARATOR: %s \n", (char*) (raiz -> hijoIzquierdo));
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case ENUMERATOR_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: ENUMERATOR_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case ENUM_SPECIFIER:
				/* FALTA UBICACIÓN */ printf("AST: IDENTIFICADOR de ENUM_SPECIFIER: %s \n", (char*) (raiz -> hijoIzquierdo));
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: ENUM_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case STRUCT_DECLARATOR:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: STRUCT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case STRUCT_DECLARATOR_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: STRUCT_DECLARATOR_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case SPECIFIER_QUALIFIER_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: SPECIFIER_QUALIFIER_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case STRUCT_DECLARATION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: STRUCT_DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case STRUCT_DECLARATION_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: STRUCT_DECLARATION_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case STRUCT_OR_UNION_SPECIFIER:
				switch(((Nodo_Struct_or_Union_Specifier*) (raiz -> contenido)) -> struct_o_union)
				{
					case STRUCT:
						/* FALTA UBICACIÓN */ printf("AST: STRUCT");
					break;
					case UNION:
						/* FALTA UBICACIÓN */ printf("AST: UNION");
					break;
				}
				/* FALTA UBICACIÓN */ printf("AST: Tag de STRUCT_OR_UNION_SPECIFIER: %s ", (char*) (((Nodo_Struct_or_Union_Specifier*) (raiz -> contenido)) -> tag));
				imprimir_ast_postorden(((Nodo_Struct_or_Union_Specifier*) (raiz -> contenido)) -> struct_declaration_list);
				printf("AST: %d:%d-%d:%d: STRUCT_OR_UNION_SPECIFIER", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case TYPE_QUALIFIER:
				switch(*((enum Tipo_Type_Qualifier*) (raiz -> contenido)))
				{
					case TIPO_CONST:
						printf("AST: %d:%d-%d:%d: TYPE_QUALIFIER: TIPO_CONST \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_VOLATILE:
						printf("AST: %d:%d-%d:%d: TYPE_QUALIFIER: TIPO_VOLATILE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case TYPE_SPECIFIER:
				switch(*((enum Tipo_Type_Specifier*) (raiz -> contenido)))
				{
					case TIPO_VOID:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_VOID \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_CHAR:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_CHAR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_SHORT:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_SHORT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_INT:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_INT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_LONG:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_LONG \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_FLOAT:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_FLOAT \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_DOUBLE:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_DOUBLE \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_SIGNED:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_SIGNED \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_UNSIGNED:
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_UNSIGNED \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_STRUCT_OR_UNION_SPECIFIER:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_STRUCT_OR_UNION_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_ENUM_SPECIFIER:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_ENUM_SPECIFIER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_NOMBRE_DE_TYPEDEF:
						/* FALTA UBICACIÓN */ printf("AST: NOMBRE_DE_TYPEDEF de TYPE_SPECIFIER: %s \n", (char*) (raiz -> hijoIzquierdo));
						printf("AST: %d:%d-%d:%d: TYPE_SPECIFIER: TIPO_NOMBRE_DE_TYPEDEF \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case STORAGE_CLASS_SPECIFIER:
				switch(*((enum Tipo_Storage_Class_Specifier*) (raiz -> contenido)))
				{
					case TIPO_AUTO:
						printf("AST: %d:%d-%d:%d: STORAGE_CLASS_SPECIFIER: TIPO_AUTO \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_REGISTER:
						printf("AST: %d:%d-%d:%d: STORAGE_CLASS_SPECIFIER: TIPO_REGISTER \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_STATIC:
						printf("AST: %d:%d-%d:%d: STORAGE_CLASS_SPECIFIER: TIPO_STATIC \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_EXTERN:
						printf("AST: %d:%d-%d:%d: STORAGE_CLASS_SPECIFIER: TIPO_EXTERN \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_TYPEDEF:
						printf("AST: %d:%d-%d:%d: STORAGE_CLASS_SPECIFIER: TIPO_TYPEDEF \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case INIT_DECLARATOR:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: INIT_DECLARATOR \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case INIT_DECLARATOR_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: INIT_DECLARATOR_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case DECLARATION_SPECIFIERS:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: DECLARATION_SPECIFIERS: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case DECLARATION_LIST:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: DECLARATION_LIST: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
			case DECLARATION:
				imprimir_ast_postorden(raiz -> hijoIzquierdo);
				imprimir_ast_postorden(raiz -> hijoDerecho);
				printf("AST: %d:%d-%d:%d: DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case FUNCTION_DEFINITION:
				imprimir_ast_postorden(((Nodo_Function_Definition_AST*) (raiz -> contenido)) -> declaration_specifiers);
				imprimir_ast_postorden(((Nodo_Function_Definition_AST*) (raiz -> contenido)) -> declarator);
				imprimir_ast_postorden(((Nodo_Function_Definition_AST*) (raiz -> contenido)) -> declaration_list);
				imprimir_ast_postorden(((Nodo_Function_Definition_AST*) (raiz -> contenido)) -> compound_statement);
				printf("AST: %d:%d-%d:%d: FUNCTION_DEFINITION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
			break;
			case EXTERNAL_DECLARATION:
				switch(*((enum Tipo_External_Declaration*) (raiz -> contenido)))
				{
					case TIPO_FUNCTION_DEFINITION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: EXTERNAL_DECLARATION: TIPO_FUNCTION_DEFINITION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
					case TIPO_DECLARATION:
						imprimir_ast_postorden(raiz -> hijoIzquierdo);
						printf("AST: %d:%d-%d:%d: EXTERNAL_DECLARATION: TIPO_DECLARATION \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column);
					break;
				}
			break;
			case TRANSLATION_UNIT:
				aux =  ((Lista_AST*) (raiz -> contenido)) -> primero;
				while(aux != NULL)
				{
					imprimir_ast_postorden(aux -> nodo);
					aux = aux -> siguiente;
				}
				printf("AST: %d:%d-%d:%d: TRANSLATION_UNIT: Cantidad de nodos: %d \n", (raiz ->ubicacion).first_line, (raiz ->ubicacion).first_column, (raiz ->ubicacion).last_line, (raiz ->ubicacion).last_column, ((Lista_AST*) (raiz -> contenido)) -> cantidadDeNodos);
			break;
		}
	}
}