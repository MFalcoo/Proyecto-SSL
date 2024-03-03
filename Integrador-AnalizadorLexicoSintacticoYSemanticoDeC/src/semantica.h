#include "reporte.h"

typedef struct ListaSemantica
{
    struct Nodo_AST* elemento;
    struct ListaSemantica* siguiente;
} ListaSemantica;

typedef struct Semantica_Declaration_Specifiers
{
    enum Booleano bandera_correcto;
    enum Tipo_Storage_Class_Specifier* storage_class_specifier;
    enum Tipo_Type_Specifier* primer_type_specifier;
    enum Tipo_Type_Specifier* segundo_type_specifier;
    enum Tipo_Type_Specifier* tercer_type_specifier;
    enum Booleano type_qualifier_const;
    enum Booleano type_qualifier_volatile;
} Semantica_Declaration_Specifiers;

typedef struct Semantica_Type_Qualifier_List
{
    enum Booleano bandera_correcto;
    enum Booleano type_qualifier_const;
    enum Booleano type_qualifier_volatile;
} Semantica_Type_Qualifier_List;

Semantica_Declaration_Specifiers resolver_nodo_ast_declaration_specifiers(Nodo_AST*);
Semantica_Type_Qualifier_List resolver_nodo_ast_type_qualifier_list(Nodo_AST* raiz);
void resolver_nodo_ast_function_definition(Nodo_AST*);
void resolver_nodo_ast_declaration(Nodo_AST*);
void resolver_nodo_ast_multiplicative_expression(Nodo_AST*);
void resolver_nodo_ast_postfix_expression(Nodo_AST*);
void resolver_ast(Nodo_AST*);

enum Dato dato_asociado(enum Tipo_Type_Specifier*, enum Tipo_Type_Specifier*, enum Tipo_Type_Specifier*);

void recorrer_ast_declarator(struct ListaSemantica**, struct Nodo_AST*);
void recorrer_ast_pointer(struct ListaSemantica**, struct Nodo_AST*);
void recorrer_ast_multiplicative_expression(struct ListaSemantica**, struct Nodo_AST*);
void push_pila_semantica(struct ListaSemantica**, struct Nodo_AST*);
Nodo_AST* pop_pila_semantica(struct ListaSemantica**);
enum Dato conversion_aritmetica_usual(enum Dato, enum Dato);
enum Dato promocion_entera(enum Dato);