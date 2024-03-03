#include "bibliotecas.h"
#include "semantica.h"

static char* string_enum_Almacenamiento[] =
{
	"",
	"auto",
    "register",
    "static",
    "extern"
};

static char* string_enum_Dato[] =
{
	"",
    "void",
    "char",
	"signed char",
	"unsigned char",
    "short",
	"unsigned short",
    "int",
	"unsigned int",
    "long",
	"unsigned long",
    "float",
    "double",
	"long double"
};

static char* string_const[] =
{
	"",
	"const"
};

static char* string_volatile[] =
{
	"",
	"volatile"
};

extern int alcanceActual;
extern Descripcion* variablesDeclaradas;
extern Descripcion* funcionesDeclaradas;
extern Descripcion* erroresSemanticos;
extern int cantidadErroresSemanticos;

// declaration_specifiers
    // function_definition
    // declaration
    // parameter_declaration

// declarator
    // function_definition
    // init_declarator
    // struct_declarator
    // parameter_declaration

    /*
    main.c:5:15: error: ‘void’ must be the only parameter
    5 | int main(int, void){
    |               ^~~~
main.c: In function ‘main’:
main.c:5:10: error: parameter name omitted
    */

Semantica_Declaration_Specifiers resolver_nodo_ast_declaration_specifiers(Nodo_AST* raiz)
{
    struct Semantica_Declaration_Specifiers aRetornar;

    if((raiz -> tipoNodoAST) == DECLARATION_SPECIFIERS)
    {
        Lista_AST* lista_de_declaration_specifiers = (Lista_AST*) (raiz -> contenido);

        aRetornar.bandera_correcto = TRUE;
        aRetornar.storage_class_specifier = NULL;
        aRetornar.primer_type_specifier = NULL;
        aRetornar.segundo_type_specifier = NULL;
        aRetornar.tercer_type_specifier = NULL;
        aRetornar.type_qualifier_const = FALSE;
        aRetornar.type_qualifier_volatile = FALSE;

        Miembro_AST* aux = lista_de_declaration_specifiers -> primero;
        while(aux != NULL)
        {
            switch((aux -> nodo) -> tipoNodoAST)
            {
                case STORAGE_CLASS_SPECIFIER:
                    if(aRetornar.storage_class_specifier == NULL)
                    {
                        aRetornar.storage_class_specifier = (enum Tipo_Storage_Class_Specifier*) ((aux -> nodo) -> contenido);
                    }
                    else
                    {
                        aRetornar.bandera_correcto = FALSE;

                        enum Tipo_Storage_Class_Specifier* storage_class_specifier_de_lista = (enum Tipo_Storage_Class_Specifier*) ((aux -> nodo) -> contenido);
                        if((*(aRetornar.storage_class_specifier)) == (*storage_class_specifier_de_lista))
                        {
                            switch(*storage_class_specifier_de_lista)
                            {
                                case TIPO_AUTO:
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'auto' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                break;
                                case TIPO_REGISTER:
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'register' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                break;
                                case TIPO_STATIC:
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'static' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                break;
                                case TIPO_EXTERN:
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'extern' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                break;
                                case TIPO_TYPEDEF:
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'typedef' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                break;
                            }
                        }
                        else
                        {
                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: multiples clases de almacenamiento en especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                        }

                        cantidadErroresSemanticos++;
                    }
                break;
                case TYPE_SPECIFIER:
                    if((aRetornar.primer_type_specifier) == NULL)
                    {
                        aRetornar.primer_type_specifier = (enum Tipo_Type_Specifier*) ((aux -> nodo) -> contenido);

                    }
                    else
                    {
                        enum Tipo_Type_Specifier* nuevo_type_specifier = (enum Tipo_Type_Specifier*) ((aux -> nodo) -> contenido);

                        switch(*(aRetornar.primer_type_specifier))
                        {
                            case TIPO_VOID: case TIPO_FLOAT: case TIPO_STRUCT_OR_UNION_SPECIFIER: case TIPO_ENUM_SPECIFIER: case TIPO_NOMBRE_DE_TYPEDEF:
                                aRetornar.bandera_correcto = FALSE;
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                cantidadErroresSemanticos++;
                            break;
                            case TIPO_CHAR:
                                switch(*nuevo_type_specifier)
                                {
                                    case TIPO_SIGNED: case TIPO_UNSIGNED:
                                        aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                        aRetornar.primer_type_specifier = nuevo_type_specifier;
                                    break;
                                    default:
                                        aRetornar.bandera_correcto = FALSE;
                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                        cantidadErroresSemanticos++;
                                    break;
                                }
                            break;
                            case TIPO_SHORT:
                                if((aRetornar.segundo_type_specifier) == NULL)
                                {
                                    switch(*nuevo_type_specifier)
                                    {
                                        case TIPO_SIGNED: case TIPO_UNSIGNED:
                                            aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                            aRetornar.primer_type_specifier = nuevo_type_specifier;
                                        break;
                                        case TIPO_INT:
                                            aRetornar.segundo_type_specifier = nuevo_type_specifier;
                                        break;
                                        default:
                                            aRetornar.bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                            cantidadErroresSemanticos++;
                                        break;
                                    }
                                }
                                else
                                {
                                    switch(*nuevo_type_specifier)
                                    {
                                        case TIPO_SIGNED: case TIPO_UNSIGNED:
                                            aRetornar.tercer_type_specifier = aRetornar.segundo_type_specifier;
                                            aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                            aRetornar.primer_type_specifier = nuevo_type_specifier;
                                        break;
                                        default:
                                            aRetornar.bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                            cantidadErroresSemanticos++;
                                        break;
                                    }
                                }
                            break;
                            case TIPO_INT:
                                switch(*nuevo_type_specifier)
                                {
                                    case TIPO_SHORT: case TIPO_LONG: case TIPO_SIGNED: case TIPO_UNSIGNED:
                                        aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                        aRetornar.primer_type_specifier = nuevo_type_specifier;
                                    break;
                                    default:
                                        aRetornar.bandera_correcto = FALSE;
                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                        cantidadErroresSemanticos++;
                                    break;
                                }
                            break;
                            case TIPO_LONG:
                                if((aRetornar.segundo_type_specifier) == NULL)
                                {
                                    switch(*nuevo_type_specifier)
                                    {
                                        case TIPO_SIGNED: case TIPO_UNSIGNED:
                                            aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                            aRetornar.primer_type_specifier = nuevo_type_specifier;
                                        break;
                                        case TIPO_INT: case TIPO_DOUBLE:
                                            aRetornar.segundo_type_specifier = nuevo_type_specifier;
                                        break;
                                        default:
                                            aRetornar.bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                            cantidadErroresSemanticos++;
                                        break;
                                    }
                                }
                                else
                                {
                                    switch(*(aRetornar.segundo_type_specifier))
                                    {
                                        case TIPO_INT:
                                            switch(*nuevo_type_specifier)
                                            {
                                                case TIPO_SIGNED: case TIPO_UNSIGNED:
                                                    aRetornar.tercer_type_specifier = aRetornar.segundo_type_specifier;
                                                    aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                                    aRetornar.primer_type_specifier = nuevo_type_specifier;
                                                break;
                                                default:
                                                    aRetornar.bandera_correcto = FALSE;
                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                                    cantidadErroresSemanticos++;
                                                break;
                                            }
                                        break;
                                        case TIPO_DOUBLE:
                                            aRetornar.bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                            cantidadErroresSemanticos++;
                                        break;
                                        default:
                                            errorCritico("Error de programa: resolver_nodo_ast_declaration_specifiers: contante de enumeracion de segundo_type_specifier incorrecta");
                                        break;
                                    }
                                }
                            break;
                            case TIPO_DOUBLE:
                                switch(*nuevo_type_specifier)
                                {
                                    case TIPO_LONG:
                                        aRetornar.segundo_type_specifier = aRetornar.primer_type_specifier;
                                        aRetornar.primer_type_specifier = nuevo_type_specifier;
                                    break;
                                    default:
                                        aRetornar.bandera_correcto = FALSE;
                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                        cantidadErroresSemanticos++;
                                    break;
                                }
                            break;
                            case TIPO_SIGNED: case TIPO_UNSIGNED:
                                if((aRetornar.segundo_type_specifier) == NULL)
                                {
                                    switch(*nuevo_type_specifier)
                                    {
                                        case TIPO_CHAR: case TIPO_SHORT: case TIPO_INT: case TIPO_LONG:
                                            aRetornar.segundo_type_specifier = nuevo_type_specifier;
                                        break;
                                        default:
                                            aRetornar.bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                            cantidadErroresSemanticos++;
                                        break;
                                    }
                                }
                                else
                                {
                                    if((aRetornar.tercer_type_specifier) == NULL)
                                    {
                                        switch(*(aRetornar.segundo_type_specifier))
                                        {
                                            case TIPO_SHORT: case TIPO_LONG:
                                                switch(*nuevo_type_specifier)
                                                {
                                                    case TIPO_INT:
                                                        aRetornar.tercer_type_specifier = nuevo_type_specifier;
                                                    break;
                                                    default:
                                                        aRetornar.bandera_correcto = FALSE;
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                                        cantidadErroresSemanticos++;
                                                    break;
                                                }
                                            break;
                                            default:
                                                aRetornar.bandera_correcto = FALSE;
                                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                                cantidadErroresSemanticos++;
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        aRetornar.bandera_correcto = FALSE;
                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: dos o mas tipos de dato en los especificadores de declaracion \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                        cantidadErroresSemanticos++;
                                    }
                                }
                            break;
                        }
                    }
                break;
                case TYPE_QUALIFIER:
                    ;
                    enum Tipo_Type_Qualifier* type_qualifier_de_lista = (enum Tipo_Type_Qualifier*) ((aux -> nodo) -> contenido);
                    switch(*type_qualifier_de_lista)
                    {
                        case TIPO_CONST:
                            if(! (aRetornar.type_qualifier_const))
                            {
                                aRetornar.type_qualifier_const = TRUE;
                            }
                            else
                            {
                                aRetornar.bandera_correcto = FALSE;
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de declaracion 'const' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                cantidadErroresSemanticos++;
                            }
                        break;
                        case TIPO_VOLATILE:
                            if(! (aRetornar.type_qualifier_volatile))
                            {
                                aRetornar.type_qualifier_volatile = TRUE;
                            }
                            else
                            {
                                aRetornar.bandera_correcto = FALSE;
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de declaracion 'volatile' duplicado \n", archivo_yyin, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_line, ((lista_de_declaration_specifiers -> primero) -> ubicacion).first_column);
                                cantidadErroresSemanticos++;
                            }
                        break;
                    }
                break;
                default:
                    errorCritico("Error de programa: resolver_nodo_ast_declaration_specifiers: tipoNodoAST de lista_de_declaration_specifiers incorrecto");
                break;
            }

            aux = aux -> siguiente;
        }
    }
    else
    {
        errorCritico("Error de programa: resolver_nodo_ast_declaration_specifiers: tipoNodoAST pasado como parametro incorrecto");
    }

    return aRetornar;
}

Semantica_Type_Qualifier_List resolver_nodo_ast_type_qualifier_list(Nodo_AST* raiz)
{
    struct Semantica_Type_Qualifier_List aRetornar;

    if((raiz -> tipoNodoAST) == TYPE_QUALIFIER_LIST)
    {
        Lista_AST* lista_de_type_qualifier_list = (Lista_AST*) (raiz -> contenido);

        aRetornar.bandera_correcto = TRUE;
        aRetornar.type_qualifier_const = FALSE;
        aRetornar.type_qualifier_volatile = FALSE;

        Miembro_AST* aux = lista_de_type_qualifier_list -> primero;
        while(aux != NULL)
        {
			enum Tipo_Type_Qualifier* type_qualifier_de_lista = (enum Tipo_Type_Qualifier*) ((aux -> nodo) -> contenido);
			switch(*type_qualifier_de_lista)
			{
				case TIPO_CONST:
					if(! (aRetornar.type_qualifier_const))
					{
						aRetornar.type_qualifier_const = TRUE;
					}
					else
					{
						aRetornar.bandera_correcto = FALSE;
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de declaracion 'const' duplicado \n", archivo_yyin, ((lista_de_type_qualifier_list -> primero) -> ubicacion).first_line, ((lista_de_type_qualifier_list -> primero) -> ubicacion).first_column);
						cantidadErroresSemanticos++;
					}
				break;
				case TIPO_VOLATILE:
					if(! (aRetornar.type_qualifier_volatile))
					{
						aRetornar.type_qualifier_volatile = TRUE;
					}
					else
					{
						aRetornar.bandera_correcto = FALSE;
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de declaracion 'volatile' duplicado \n", archivo_yyin, ((lista_de_type_qualifier_list -> primero) -> ubicacion).first_line, ((lista_de_type_qualifier_list -> primero) -> ubicacion).first_column);
						cantidadErroresSemanticos++;
					}
				break;
			}

            aux = aux -> siguiente;
        }
    }
    else
    {
        errorCritico("Error de programa: resolver_nodo_ast_declaration_specifiers: tipoNodoAST pasado como parametro incorrecto");
    }
    return aRetornar;
}

void resolver_nodo_ast_function_definition(Nodo_AST* raiz)
{

}

void resolver_nodo_ast_declaration(Nodo_AST* raiz)
{
    if((raiz -> tipoNodoAST) == DECLARATION)
    {
        Simbolo* nuevo_Simbolo;

        struct Semantica_Declaration_Specifiers retorno_declaration_specifiers = resolver_nodo_ast_declaration_specifiers(raiz -> hijoIzquierdo);
        enum Booleano bandera_correcto;

        if((raiz -> hijoDerecho) == NULL)
        {
            if(retorno_declaration_specifiers.storage_class_specifier != NULL)
            {
                bandera_correcto = FALSE;
                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de clase de almacenamiento inservible en declaracion vacia \n", archivo_yyin, (raiz -> ubicacion).first_line, (raiz -> ubicacion).first_column);
                cantidadErroresSemanticos++;
            }
            if((retorno_declaration_specifiers.primer_type_specifier) != NULL)
            {
                switch(*(retorno_declaration_specifiers.primer_type_specifier))
                {
                    case TIPO_STRUCT_OR_UNION_SPECIFIER:
                        // FALTA EXPANDIR ACÁ
                    break;
                    case TIPO_ENUM_SPECIFIER:
                        // FALTA EXPANDIR ACÁ
                    break;
                    default:
                        bandera_correcto = FALSE;
                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: especificador de tipo inservible en declaracion vacia \n", archivo_yyin, (raiz -> ubicacion).first_line, (raiz -> ubicacion).first_column);
                        cantidadErroresSemanticos++;
                    break;
                }
            }
            if((retorno_declaration_specifiers.type_qualifier_const) || (retorno_declaration_specifiers.type_qualifier_volatile))
            {
                bandera_correcto = FALSE;
                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: calificador de tipo inservible en declaracion vacia \n", archivo_yyin, (raiz -> ubicacion).first_line, (raiz -> ubicacion).first_column);
                cantidadErroresSemanticos++;
            }
        }
        else
        {
            enum Tipo_Type_Specifier* primer_type_specifier;
            Lista_AST* lista_de_init_declarator_list = (Lista_AST*) ((raiz -> hijoDerecho) -> contenido);
            Miembro_AST* init_declarator = lista_de_init_declarator_list -> primero;
            ListaSemantica* pila_de_nodos_ast_declarator;
            Nodo_AST* declarator;

            while(init_declarator != NULL)
            {
                if(((init_declarator -> nodo) -> tipoNodoAST) != ERROR)
                {
                    bandera_correcto = retorno_declaration_specifiers.bandera_correcto;
                    primer_type_specifier = retorno_declaration_specifiers.primer_type_specifier;
                    pila_de_nodos_ast_declarator = NULL;
                    recorrer_ast_declarator(&pila_de_nodos_ast_declarator, (init_declarator -> nodo) -> hijoIzquierdo);
                    declarator = pop_pila_semantica(&pila_de_nodos_ast_declarator);

                    nuevo_Simbolo = (Simbolo*) malloc(sizeof(Simbolo));
                    nuevo_Simbolo -> alcanceSimbolo = alcanceActual;
                    nuevo_Simbolo -> nombreSimbolo = (char*) (declarator -> hijoIzquierdo);
                    nuevo_Simbolo -> ubicacionSimbolo = declarator -> ubicacion;

                    Simbolo* resultadoBusqueda = buscarSimbolo(nuevo_Simbolo -> nombreSimbolo, BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
                    if((resultadoBusqueda != NULL) && ((resultadoBusqueda -> alcanceSimbolo) == alcanceActual))
                    {
                        bandera_correcto = FALSE;
                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: redeclaracion de '%s' sin enlazado \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: la declaracion previa de '%s' estaba aqui \n", archivo_yyin, (resultadoBusqueda -> ubicacionSimbolo).first_line, (resultadoBusqueda -> ubicacionSimbolo).first_column, resultadoBusqueda -> nombreSimbolo);
                        cantidadErroresSemanticos++;
                    }

                    if((declarator = pop_pila_semantica(&pila_de_nodos_ast_declarator)) == NULL)
                    {
                        if(((retorno_declaration_specifiers.storage_class_specifier) == NULL) || ((*(retorno_declaration_specifiers.storage_class_specifier)) != TIPO_TYPEDEF))
                        {
                            if((retorno_declaration_specifiers.storage_class_specifier) == NULL)
                            {
                                nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_INDEFINIDO;
                            }
                            else
                            {
                                switch(*(retorno_declaration_specifiers.storage_class_specifier))
                                {
                                    case TIPO_AUTO:
                                        nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_AUTO;
                                        if(alcanceActual == 0)
                                        {
                                            bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: La declaracion con alcance de archivo de '%s' especifica 'auto' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                            cantidadErroresSemanticos++;
                                        }
                                    break;
                                    case TIPO_REGISTER:
                                        nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_REGISTER;
                                        if(alcanceActual == 0)
                                        {
                                            bandera_correcto = FALSE;
                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: La declaracion con alcance de archivo de '%s' especifica 'register' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                            cantidadErroresSemanticos++;
                                        }
                                    break;
                                    case TIPO_STATIC:
                                        nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_STATIC;
                                    break;
                                    case TIPO_EXTERN:
                                        nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_EXTERN;
                                    break;
                                    default:
                                    break;
                                }
                            }

                            struct Objeto* nuevo_Objeto = (struct Objeto*) malloc(sizeof(struct Objeto));
                            nuevo_Simbolo -> tipoSimbolo = OBJETO;
                            nuevo_Simbolo -> simbolo = (Simbolo*) nuevo_Objeto;

                            (nuevo_Objeto -> tipoDeDato).calificadorDeTipoConst = retorno_declaration_specifiers.type_qualifier_const;
                            (nuevo_Objeto -> tipoDeDato).calificadorDeTipoVolatile = retorno_declaration_specifiers.type_qualifier_volatile;

                            if((retorno_declaration_specifiers.primer_type_specifier) == NULL)
                            {
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Warning: el especificador de tipo se predetermina en 'int' en la declaracion de '%s' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                primer_type_specifier = (enum Tipo_Type_Specifier*) malloc(sizeof(enum Tipo_Type_Specifier));
                                *primer_type_specifier = TIPO_INT;
                            }

                            switch(*(primer_type_specifier))
                            {
                                case TIPO_VOID:
                                    bandera_correcto = FALSE;
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: el tamanio de almacenamiento de '%s' es desconocido \n", archivo_yyin, (raiz -> ubicacion).first_line, (raiz -> ubicacion).first_column, nuevo_Simbolo -> nombreSimbolo);
                                    cantidadErroresSemanticos++;
                                break;
                                case TIPO_CHAR: case TIPO_SHORT: case TIPO_INT: case TIPO_LONG: case TIPO_FLOAT: case TIPO_DOUBLE: case TIPO_SIGNED: case TIPO_UNSIGNED:
                                    ;
                                    struct Basico* nuevo_Basico = (struct Basico*) malloc(sizeof(struct Basico));
                                    (nuevo_Objeto -> tipoDeDato).tipoDeConstruccion = CONSTRUCCION_BASICA;
                                    (nuevo_Objeto -> tipoDeDato).construccion = (struct TipoDeDato*) nuevo_Basico;
                                    nuevo_Basico -> tipoDeDato = dato_asociado(primer_type_specifier, retorno_declaration_specifiers.segundo_type_specifier, retorno_declaration_specifiers.tercer_type_specifier);
                                    if(bandera_correcto)
                                    {
                                        insertar_En_La_Tabla_De_Simbolos(nuevo_Simbolo -> nombreSimbolo, nuevo_Simbolo);
                                        variable_declarada_printf("Semantica: %s:%d:%d: Variable declarada: %s %s %s %s %s \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, string_enum_Almacenamiento[nuevo_Simbolo -> claseAlmacenamiento], string_const[(nuevo_Objeto -> tipoDeDato).calificadorDeTipoConst], string_volatile[(nuevo_Objeto -> tipoDeDato).calificadorDeTipoVolatile], string_enum_Dato[nuevo_Basico -> tipoDeDato], nuevo_Simbolo -> nombreSimbolo);
                                    }
                                break;
                                case TIPO_STRUCT_OR_UNION_SPECIFIER:
                                    // FALTA EXPANDIR ACÁ
                                break;
                                case TIPO_ENUM_SPECIFIER:
                                    // FALTA EXPANDIR ACÁ
                                break;
                                case TIPO_NOMBRE_DE_TYPEDEF:
                                    // FALTA EXPANDIR ACÁ
                                break;
                            }
                        }
                        else
                        {
                            nuevo_Simbolo -> tipoSimbolo = TYPEDEF;
                            // FALTA EXPANDIR ACÁ
                        }
                    }
                    else
                    {
                        switch(declarator -> tipoNodoAST)
                        {
                            case POINTER:
                                // FALTA EXPANDIR ACÁ
                            break;
                            case DIRECT_DECLARATOR:
                                switch(*((enum Tipo_Direct_Declarator*) (declarator -> contenido)))
                                {
                                    case TIPO_NO_ABSTRACTO_ARREGLO:
                                    break;
                                    case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA:
                                        if(pila_de_nodos_ast_declarator == NULL)
                                        {
                                            if(((retorno_declaration_specifiers.storage_class_specifier) == NULL) || ((*(retorno_declaration_specifiers.storage_class_specifier)) != TIPO_TYPEDEF))
                                            {
                                                if((retorno_declaration_specifiers.storage_class_specifier) == NULL)
                                                {
                                                    nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_INDEFINIDO;
                                                }
                                                else
                                                {
                                                    if((alcanceActual > 0) && ((*(retorno_declaration_specifiers.storage_class_specifier)) != TIPO_EXTERN))
                                                    {
                                                        bandera_correcto = FALSE;
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: clase de almacenamiento no valida para la funcion '%s' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                                        cantidadErroresSemanticos++;
                                                    }
                                                    else
                                                    {
                                                        switch(*(retorno_declaration_specifiers.storage_class_specifier))
                                                        {
                                                            case TIPO_AUTO:
                                                                nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_AUTO;
                                                                if(alcanceActual == 0)
                                                                {
                                                                    bandera_correcto = FALSE;
                                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: La declaracion con alcance de archivo de '%s' especifica 'auto' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                                                    cantidadErroresSemanticos++;
                                                                }
                                                            break;
                                                            case TIPO_REGISTER:
                                                                nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_REGISTER;
                                                                if(alcanceActual == 0)
                                                                {
                                                                    bandera_correcto = FALSE;
                                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: La declaracion con alcance de archivo de '%s' especifica 'register' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                                                    cantidadErroresSemanticos++;
                                                                }
                                                            break;
                                                            case TIPO_STATIC:
                                                                nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_STATIC;
                                                            break;
                                                            case TIPO_EXTERN:
                                                                nuevo_Simbolo -> claseAlmacenamiento = ALMACENAMIENTO_EXTERN;
                                                            break;
                                                            default:
                                                            break;
                                                        }
                                                    }
                                                }
                                                
                                                struct Funcion* nueva_Funcion = (struct Funcion*) malloc(sizeof(struct Funcion));
                                                nuevo_Simbolo -> tipoSimbolo = FUNCION;
                                                nuevo_Simbolo -> simbolo = (Simbolo*) nueva_Funcion;

                                                nueva_Funcion -> cantidadDeParametros = 0;
                                                nueva_Funcion -> listaDeParametros = NULL;

                                                if((retorno_declaration_specifiers.primer_type_specifier) == NULL)
                                                {
                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Warning: el especificador de tipo se predetermina en 'int' en la declaracion de '%s' \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nuevo_Simbolo -> nombreSimbolo);
                                                    primer_type_specifier = (enum Tipo_Type_Specifier*) malloc(sizeof(enum Tipo_Type_Specifier));
                                                    *primer_type_specifier = TIPO_INT;
                                                }
                                                
                                                struct Basico* nuevo_Basico = (struct Basico*) malloc(sizeof(struct Basico));
                                                (nueva_Funcion -> tipoRetorno).tipoDeConstruccion = CONSTRUCCION_BASICA;
                                                (nueva_Funcion -> tipoRetorno).construccion = (struct TipoDeDato*) nuevo_Basico;
                                                nuevo_Basico -> tipoDeDato = dato_asociado(primer_type_specifier, retorno_declaration_specifiers.segundo_type_specifier, retorno_declaration_specifiers.tercer_type_specifier);

                                                (nueva_Funcion -> tipoRetorno).calificadorDeTipoConst = retorno_declaration_specifiers.type_qualifier_const;
                                                (nueva_Funcion -> tipoRetorno).calificadorDeTipoVolatile = retorno_declaration_specifiers.type_qualifier_volatile;

                                                nueva_Funcion -> banderaDefinicion = FALSE;
                                                switch(*((enum Tipo_Parameter_Type_List*) ((declarator -> hijoDerecho) -> contenido)))
                                                {
                                                    case SIN_ELIPSIS:
                                                        nueva_Funcion -> banderaElipsis = FALSE;
                                                    break;
                                                    case CON_ELIPSIS:
                                                        nueva_Funcion -> banderaElipsis = TRUE;
                                                    break;
                                                }

                                                Lista_AST* lista_de_parameter_list = (Lista_AST*) (((declarator -> hijoDerecho) -> hijoIzquierdo) -> contenido);
                                                Miembro_AST* parameter_declaration = lista_de_parameter_list -> primero;
                                                struct Semantica_Declaration_Specifiers retorno_declaration_specifiers_parametro = resolver_nodo_ast_declaration_specifiers((parameter_declaration -> nodo) -> hijoIzquierdo);                       

                                                if(((lista_de_parameter_list -> cantidadDeNodos) == 1) && ((*((enum Tipo_Parameter_Declaration*) ((parameter_declaration -> nodo) -> contenido))) == TIPO_PARAMETER_DECLARATION_EPSILON) && ((retorno_declaration_specifiers_parametro.primer_type_specifier) != NULL) && (*(retorno_declaration_specifiers_parametro.primer_type_specifier)) == TIPO_VOID)
                                                {
                                                    bandera_correcto = bandera_correcto * (retorno_declaration_specifiers_parametro.bandera_correcto);
                                                    if(((retorno_declaration_specifiers_parametro.storage_class_specifier) != NULL) || (retorno_declaration_specifiers_parametro.type_qualifier_const) || (retorno_declaration_specifiers_parametro.type_qualifier_volatile))
                                                    {
                                                        bandera_correcto = FALSE;
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'void' como unico parametro no puede ser calificado \n", archivo_yyin, (parameter_declaration -> ubicacion).first_line, (parameter_declaration -> ubicacion).first_column);
                                                        cantidadErroresSemanticos++;
                                                    }
                                                    if(nueva_Funcion -> banderaElipsis)
                                                    {
                                                        bandera_correcto = FALSE;
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'void' debe ser el unico parametro \n", archivo_yyin, (parameter_declaration -> ubicacion).first_line, (parameter_declaration -> ubicacion).first_column);
                                                        cantidadErroresSemanticos++;
                                                    }
                                                    if(bandera_correcto)
                                                    {
                                                        insertar_En_La_Tabla_De_Simbolos(nuevo_Simbolo -> nombreSimbolo, nuevo_Simbolo);
                                                        funcion_declarada_printf("Semantica: %s:%d:%d: Funcion de %d parametro/s declarada: %s %s %s %s %s \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nueva_Funcion -> cantidadDeParametros, string_enum_Almacenamiento[nuevo_Simbolo -> claseAlmacenamiento], string_const[(nueva_Funcion -> tipoRetorno).calificadorDeTipoConst], string_volatile[(nueva_Funcion -> tipoRetorno).calificadorDeTipoVolatile], string_enum_Dato[nuevo_Basico -> tipoDeDato], nuevo_Simbolo -> nombreSimbolo);
                                                    }
                                                }
                                                else
                                                {
                                                    struct Parametro* nuevo_Parametro;
                                                    enum Tipo_Type_Specifier* primer_type_specifier_parametro = retorno_declaration_specifiers_parametro.primer_type_specifier;
                                                    ListaSemantica* pila_de_nodos_ast_declarator_parametro;
                                                    Nodo_AST* declarator_parametro;

                                                    do
                                                    {
                                                        nuevo_Parametro = (struct Parametro*) malloc(sizeof(struct Parametro));
                                                        nuevo_Parametro -> nombreParametro = NULL;
                                                        nuevo_Parametro -> siguienteParametro = NULL;

                                                        (nuevo_Parametro -> tipoParametro).calificadorDeTipoConst = retorno_declaration_specifiers_parametro.type_qualifier_const;
                                                        (nuevo_Parametro -> tipoParametro).calificadorDeTipoVolatile = retorno_declaration_specifiers_parametro.type_qualifier_volatile;

                                                        switch(*((enum Tipo_Parameter_Declaration*) ((parameter_declaration -> nodo) -> contenido)))
                                                        {
                                                            case TIPO_PARAMETER_DECLARATION_DECLARATOR:
                                                                pila_de_nodos_ast_declarator_parametro = NULL;
                                                                recorrer_ast_declarator(&pila_de_nodos_ast_declarator_parametro, (parameter_declaration -> nodo) -> hijoDerecho);
                                                                declarator_parametro = pop_pila_semantica(&pila_de_nodos_ast_declarator_parametro);

                                                                if(pila_de_nodos_ast_declarator_parametro == NULL)
                                                                {
                                                                    nuevo_Parametro -> ubicacionParametro = declarator_parametro -> ubicacion;

                                                                    if(((retorno_declaration_specifiers_parametro.storage_class_specifier) != NULL) && ((*(retorno_declaration_specifiers_parametro.storage_class_specifier)) != TIPO_REGISTER))
                                                                    {
                                                                        bandera_correcto = FALSE;
                                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: clase de almacenamiento especificada para el parametro '%s' \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column, (char*) (declarator_parametro -> hijoIzquierdo));
                                                                        cantidadErroresSemanticos++;
                                                                    }
                                                                    else
                                                                    {
                                                                        if((retorno_declaration_specifiers_parametro.storage_class_specifier) == NULL)
                                                                        {
                                                                            nuevo_Parametro -> almacenamientoParametro = ALMACENAMIENTO_INDEFINIDO;
                                                                        }
                                                                        else
                                                                        {
                                                                            nuevo_Parametro -> almacenamientoParametro = ALMACENAMIENTO_REGISTER;
                                                                        }
                                                                    }

                                                                    if((primer_type_specifier_parametro) == NULL)
                                                                    {
                                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Warning: el especificador de tipo se predetermina en 'int' en la declaracion de '%s' \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column, (char*) (declarator_parametro -> hijoIzquierdo));
                                                                        primer_type_specifier_parametro = (enum Tipo_Type_Specifier*) malloc(sizeof(enum Tipo_Type_Specifier));
                                                                        *primer_type_specifier_parametro = TIPO_INT;
                                                                    }

                                                                    switch(*(primer_type_specifier_parametro))
                                                                    {
                                                                        case TIPO_VOID:
                                                                            bandera_correcto = FALSE;
                                                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: El parametro %d ('%s') tiene tipo 'void' \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column, (nueva_Funcion -> cantidadDeParametros) + 1, (char*) (declarator_parametro -> hijoIzquierdo));
                                                                            cantidadErroresSemanticos++;
                                                                        break;
                                                                        case TIPO_CHAR: case TIPO_SHORT: case TIPO_INT: case TIPO_LONG: case TIPO_FLOAT: case TIPO_DOUBLE: case TIPO_SIGNED: case TIPO_UNSIGNED:
                                                                            ;
                                                                            struct Basico* nuevo_Basico = (struct Basico*) malloc(sizeof(struct Basico));
                                                                            (nuevo_Parametro -> tipoParametro).tipoDeConstruccion = CONSTRUCCION_BASICA;
                                                                            (nuevo_Parametro -> tipoParametro).construccion = (struct TipoDeDato*) nuevo_Basico;
                                                                            nuevo_Basico -> tipoDeDato = dato_asociado(primer_type_specifier_parametro, retorno_declaration_specifiers.segundo_type_specifier, retorno_declaration_specifiers.tercer_type_specifier);
                                                                            if(bandera_correcto)
                                                                            {
                                                                                agregar_parametro_a_funcion(nueva_Funcion, nuevo_Parametro);
                                                                            }
                                                                        break;
                                                                        case TIPO_STRUCT_OR_UNION_SPECIFIER:
                                                                            // FALTA EXPANDIR ACÁ
                                                                        break;
                                                                        case TIPO_ENUM_SPECIFIER:
                                                                            // FALTA EXPANDIR ACÁ
                                                                        break;
                                                                        case TIPO_NOMBRE_DE_TYPEDEF:
                                                                            // FALTA EXPANDIR ACÁ
                                                                        break;
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    // FALTA EXPANDIR ACÁ
                                                                    //bandera_correcto = FALSE; // En realidad es correcto pero lo hacemos porque falta expandir
                                                                }
                                                            break;
                                                            case TIPO_PARAMETER_DECLARATION_ABSTRACT_DECLARATOR:
                                                                // FALTA EXPANDIR ACÁ
                                                                //bandera_correcto = FALSE; // En realidad es correcto pero lo hacemos porque falta expandir
                                                            break;
                                                            case TIPO_PARAMETER_DECLARATION_EPSILON:
                                                                nuevo_Parametro -> ubicacionParametro = (parameter_declaration -> nodo) -> ubicacion;

                                                                if(((retorno_declaration_specifiers_parametro.storage_class_specifier) != NULL) && ((*(retorno_declaration_specifiers_parametro.storage_class_specifier)) != TIPO_REGISTER))
                                                                {
                                                                    bandera_correcto = FALSE;
                                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: clase de almacenamiento especificada para el parametro sin nombre \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column);
                                                                    cantidadErroresSemanticos++;
                                                                }
                                                                else
                                                                {
                                                                    if((retorno_declaration_specifiers_parametro.storage_class_specifier) == NULL)
                                                                    {
                                                                        nuevo_Parametro -> almacenamientoParametro = ALMACENAMIENTO_INDEFINIDO;
                                                                    }
                                                                    else
                                                                    {
                                                                        nuevo_Parametro -> almacenamientoParametro = ALMACENAMIENTO_REGISTER;
                                                                    }
                                                                }

                                                                if((primer_type_specifier_parametro) == NULL)
                                                                {
                                                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Warning: el especificador de tipo se predetermina en 'int' en el nombre de tipo \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column);
                                                                    primer_type_specifier_parametro = (enum Tipo_Type_Specifier*) malloc(sizeof(enum Tipo_Type_Specifier));
                                                                    *primer_type_specifier_parametro = TIPO_INT;
                                                                }

                                                                switch(*(primer_type_specifier_parametro))
                                                                {
                                                                    case TIPO_VOID:
                                                                        bandera_correcto = FALSE;
                                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: 'void' debe ser el unico parametro \n", archivo_yyin, (nuevo_Parametro -> ubicacionParametro).first_line, (nuevo_Parametro -> ubicacionParametro).first_column);
                                                                        cantidadErroresSemanticos++;
                                                                    break;
                                                                    case TIPO_CHAR: case TIPO_SHORT: case TIPO_INT: case TIPO_LONG: case TIPO_FLOAT: case TIPO_DOUBLE: case TIPO_SIGNED: case TIPO_UNSIGNED:
                                                                        ;
                                                                        struct Basico* nuevo_Basico = (struct Basico*) malloc(sizeof(struct Basico));
                                                                        (nuevo_Parametro -> tipoParametro).tipoDeConstruccion = CONSTRUCCION_BASICA;
                                                                        (nuevo_Parametro -> tipoParametro).construccion = (struct TipoDeDato*) nuevo_Basico;
                                                                        nuevo_Basico -> tipoDeDato = dato_asociado(primer_type_specifier_parametro, retorno_declaration_specifiers.segundo_type_specifier, retorno_declaration_specifiers.tercer_type_specifier);
                                                                        if(bandera_correcto)
                                                                        {
                                                                            agregar_parametro_a_funcion(nueva_Funcion, nuevo_Parametro);
                                                                        }
                                                                    break;
                                                                    case TIPO_STRUCT_OR_UNION_SPECIFIER:
                                                                        // FALTA EXPANDIR ACÁ
                                                                    break;
                                                                    case TIPO_ENUM_SPECIFIER:
                                                                        // FALTA EXPANDIR ACÁ
                                                                    break;
                                                                    case TIPO_NOMBRE_DE_TYPEDEF:
                                                                        // FALTA EXPANDIR ACÁ
                                                                    break;
                                                                }
                                                            break;
                                                        }
                                                                                                
                                                        parameter_declaration = parameter_declaration -> siguiente;
                                                        if(parameter_declaration != NULL)
                                                        {
                                                            retorno_declaration_specifiers_parametro = resolver_nodo_ast_declaration_specifiers((parameter_declaration -> nodo) -> hijoIzquierdo);
                                                            primer_type_specifier_parametro = retorno_declaration_specifiers_parametro.primer_type_specifier;
                                                            bandera_correcto = bandera_correcto * (retorno_declaration_specifiers_parametro.bandera_correcto);
                                                        }
                                                        
                                                    }
                                                    while((bandera_correcto) && (parameter_declaration != NULL));

                                                    if(bandera_correcto)
                                                    {
                                                        insertar_En_La_Tabla_De_Simbolos(nuevo_Simbolo -> nombreSimbolo, nuevo_Simbolo);
                                                        funcion_declarada_printf("Semantica: %s:%d:%d: Funcion de %d parametro/s declarada: %s %s %s %s %s \n", archivo_yyin, (nuevo_Simbolo -> ubicacionSimbolo).first_line, (nuevo_Simbolo -> ubicacionSimbolo).first_column, nueva_Funcion -> cantidadDeParametros, string_enum_Almacenamiento[nuevo_Simbolo -> claseAlmacenamiento], string_const[(nueva_Funcion -> tipoRetorno).calificadorDeTipoConst], string_volatile[(nueva_Funcion -> tipoRetorno).calificadorDeTipoVolatile], string_enum_Dato[nuevo_Basico -> tipoDeDato], nuevo_Simbolo -> nombreSimbolo);
                                                        Parametro* unParametro = nueva_Funcion -> listaDeParametros;
                                                        int numero_de_parametro = 1;
                                                        while(unParametro != NULL)
                                                        {
                                                            funcion_declarada_printf("\t Semantica: %s:%d:%d: Parametro %d: %s %s %s %s \n", archivo_yyin, (unParametro -> ubicacionParametro).first_line, (unParametro -> ubicacionParametro).first_column, numero_de_parametro, string_enum_Almacenamiento[unParametro -> almacenamientoParametro], string_const[(unParametro -> tipoParametro).calificadorDeTipoConst], string_volatile[(unParametro -> tipoParametro).calificadorDeTipoVolatile], string_enum_Dato[((Basico*) ((unParametro -> tipoParametro).construccion)) -> tipoDeDato], unParametro -> nombreParametro);
                                                            unParametro = unParametro -> siguienteParametro;
                                                            numero_de_parametro++;
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                nuevo_Simbolo -> tipoSimbolo = TYPEDEF;
                                                // FALTA EXPANDIR ACÁ
                                            }
                                        }
                                        else
                                        {
                                            // FALTA EXPANDIR ACÁ
                                        }
                                    break;
                                    case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA:
                                        // FALTA EXPANDIR ACÁ
                                    break;
                                    default:
                                        errorCritico("Error de programa: resolver_nodo_ast_declaration: Tipo_Direct_Declarator incorrecto");
                                    break;
                                }
                            break;
                            default:
                                errorCritico("Error de programa: resolver_nodo_ast_declaration: tipoNodoAST de declarator incorrecto");
                            break;
                        }
                    }
                }
                
                init_declarator = init_declarator -> siguiente;
            }
        }
    }
    else
    {
        errorCritico("Error de programa: resolver_nodo_ast_declaration: tipoNodoAST pasado como parametro incorrecto");
    }
}

void resolver_nodo_ast_multiplicative_expression(Nodo_AST* raiz)
{
    if((raiz -> tipoNodoAST) == MULTIPLICATIVE_EXPRESSION)
    {
        enum Booleano bandera_continuar = TRUE;
        ListaSemantica* pila_de_nodos_ast_multiplicative_expression = NULL;
        recorrer_ast_multiplicative_expression(&pila_de_nodos_ast_multiplicative_expression, raiz);
        Nodo_AST* operandoActual = pop_pila_semantica(&pila_de_nodos_ast_multiplicative_expression);
        Nodo_AST* operandoSiguiente = pop_pila_semantica(&pila_de_nodos_ast_multiplicative_expression);
        enum Dato tipoDeDato_actual = DATO_INDEFINIDO;

        while(bandera_continuar)
        {
            if((operandoActual -> tipoNodoAST) == PRIMARY_EXPRESSION)
            {
                switch(*((enum Tipo_Primary_Expression*) (operandoActual -> contenido)))
                {
                    case TIPO_CONSTANTE:
                        if(tipoDeDato_actual != DATO_INDEFINIDO)
                        {
                            tipoDeDato_actual = conversion_aritmetica_usual(tipoDeDato_actual, ((Contenido_Constante_AST*) (operandoActual -> hijoIzquierdo)) -> tipoConstante);
                        }
                        else
                        {
                            tipoDeDato_actual = ((Contenido_Constante_AST*) (operandoActual -> hijoIzquierdo)) -> tipoConstante;
                        }
                    break;
                    case TIPO_LITERAL_CADENA:
                        if(operandoSiguiente == NULL)
                        {
                            if(tipoDeDato_actual == DATO_INDEFINIDO)
                            {
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: segundo operando no valido del operador binario * (tiene 'char*') \n", archivo_yyin, (operandoActual -> ubicacion).first_line, (operandoActual -> ubicacion).first_column);
                            }
                            else
                            {
                                error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: operandos no validos del operador binario * (tienen '%s' y 'char*') \n", archivo_yyin, (operandoActual -> ubicacion).first_line, (operandoActual -> ubicacion).first_column, string_enum_Dato[tipoDeDato_actual]);
                            }
                            cantidadErroresSemanticos++;
                        }
                        else
                        {
                            bandera_continuar = FALSE;
                        }
                    break;
                    case TIPO_IDENTIFICADOR:
                        ;
                        Simbolo* resultadoBusqueda = buscarSimbolo((char*) (operandoActual -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
                        if(resultadoBusqueda != NULL)
                        {
                            switch(resultadoBusqueda -> tipoSimbolo)
                            {
                                case OBJETO:
                                    switch((((Objeto*) (resultadoBusqueda -> simbolo)) -> tipoDeDato).tipoDeConstruccion)
                                    {
                                        case CONSTRUCCION_INDEFINIDA:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_BASICA:
                                            if(tipoDeDato_actual != DATO_INDEFINIDO)
                                            {
                                                tipoDeDato_actual = conversion_aritmetica_usual(tipoDeDato_actual, ((Contenido_Constante_AST*) (operandoActual -> hijoIzquierdo)) -> tipoConstante);
                                            }
                                            else
                                            {
                                                tipoDeDato_actual = ((Basico*) ((((Objeto*) (resultadoBusqueda -> simbolo)) -> tipoDeDato).construccion)) -> tipoDeDato;
                                            }
                                        break;
                                        case CONSTRUCCION_PUNTERO:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_ARREGLO:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_CAMPO_DE_BITS:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_ESTRUCTURA:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_ENUMERACION:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                        case CONSTRUCCION_FUNCION:
                                            // FALTA EXPANDIR ACÁ
                                        break;
                                    }
                                break;
                                case ENUMERADOR:
                                break;
                                case FUNCION:
                                    if(operandoSiguiente == NULL)
                                    {
                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: Un Valor-L es requerido como operando \n", archivo_yyin, (operandoActual -> ubicacion).first_line, (operandoActual -> ubicacion).first_column);
                                        cantidadErroresSemanticos++;
                                    }
                                    else
                                    {
                                        bandera_continuar = FALSE;
                                    }
                                break;
                                default:
                                break;
                            }
                        }
                        else
                        {
                            bandera_continuar = FALSE;
                        }
                    break;
                }
            }
            else
            {
                bandera_continuar = FALSE;
            }

            if(operandoSiguiente != NULL)
            {
                operandoActual = operandoSiguiente;
                operandoSiguiente = pop_pila_semantica(&pila_de_nodos_ast_multiplicative_expression);
            }
            else
            {
                bandera_continuar = FALSE;
            }
        }
    }
    else
    {
        errorCritico("Error de programa: resolver_nodo_ast_multiplicative_expression: tipoNodoAST pasado como parametro incorrecto");
    }
}

void resolver_nodo_ast_postfix_expression(Nodo_AST* raiz)
{
    if((raiz -> tipoNodoAST) == POSTFIX_EXPRESSION)
    {
        switch(*((enum Tipo_Postfix_Expression*) (raiz -> contenido)))
        {
            case INVOCACION_FUNCION:
				if(((raiz -> hijoIzquierdo) -> tipoNodoAST) == PRIMARY_EXPRESSION)
				{
					if((*((enum Tipo_Primary_Expression*) ((raiz -> hijoIzquierdo) -> contenido))) == TIPO_IDENTIFICADOR)
					{
						Simbolo* resultadoBusqueda = buscarSimbolo((char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
						if(resultadoBusqueda == NULL)
						{
							error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Warning: declaracion implicita de la funcion '%s' \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                            Simbolo* nuevo_Simbolo = (Simbolo*) malloc(sizeof(Simbolo));
                            nuevo_Simbolo -> alcanceSimbolo = alcanceActual;
                            nuevo_Simbolo -> nombreSimbolo = (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo);
                            nuevo_Simbolo -> ubicacionSimbolo = (raiz -> hijoIzquierdo) -> ubicacion;
                            struct Funcion* nueva_Funcion = (struct Funcion*) malloc(sizeof(struct Funcion));
                            nuevo_Simbolo -> tipoSimbolo = FUNCION;
                            nuevo_Simbolo -> simbolo = (Simbolo*) nueva_Funcion;
                            nueva_Funcion -> banderaDefinicion = FALSE;
                            nueva_Funcion -> banderaElipsis = FALSE;
                            Basico* nuevo_Basico = (Basico*) malloc(sizeof(Basico));
                            (nueva_Funcion -> tipoRetorno).tipoDeConstruccion = CONSTRUCCION_BASICA;
                            (nueva_Funcion -> tipoRetorno).construccion = (TipoDeDato*) nuevo_Basico;
                            nuevo_Basico -> tipoDeDato = DATO_INT;
                            nueva_Funcion -> cantidadDeParametros = 0;
                            nueva_Funcion -> listaDeParametros = NULL;
                            insertar_En_La_Tabla_De_Simbolos((char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo), nuevo_Simbolo);
                            resultadoBusqueda = nuevo_Simbolo;
						}

                        if((resultadoBusqueda -> tipoSimbolo) != FUNCION)
                        {
                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: el objeto invocado no es una funcion o un puntero a una funcion \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column);
                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: declarado aqui \n", archivo_yyin, (resultadoBusqueda -> ubicacionSimbolo).first_line, (resultadoBusqueda -> ubicacionSimbolo).first_column);
                            cantidadErroresSemanticos++;
                        }
                        else
                        {
                            if((raiz -> hijoDerecho) == NULL)
                            {
                                if((((Funcion*) (resultadoBusqueda -> simbolo)) -> cantidadDeParametros) > 0)
                                {
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: insuficientes argumentos para la funcion '%s' \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: declarado aqui \n", archivo_yyin, (resultadoBusqueda -> ubicacionSimbolo).first_line, (resultadoBusqueda -> ubicacionSimbolo).first_column);
                                    cantidadErroresSemanticos++;
                                }
                            }
                            else
                            {
                                Lista_AST* lista_de_argument_expression_list = (Lista_AST*) ((raiz -> hijoDerecho) -> contenido);
                                enum Booleano bandera_correcto = TRUE;
                                Parametro* parametro_funcion = (((Funcion*) (resultadoBusqueda -> simbolo)) -> listaDeParametros);
                                Miembro_AST* miembro_de_argument_expression_list = lista_de_argument_expression_list -> primero;

                                int numero_de_argumento = 1;
                                enum Dato tipoDeDato_argumento;
                                enum Dato tipoDeDato_parametro;

                                Simbolo* resultadoBusqueda_Identificador;

                                if(parametro_funcion != NULL)
                                {
                                    do
                                    {
                                        if(((parametro_funcion -> tipoParametro).tipoDeConstruccion) == CONSTRUCCION_BASICA)
                                        {
                                            tipoDeDato_parametro = ((Basico*) ((parametro_funcion -> tipoParametro).construccion)) -> tipoDeDato;

                                            if(((miembro_de_argument_expression_list -> nodo) -> tipoNodoAST) == PRIMARY_EXPRESSION)
                                            {
                                                switch(*((Tipo_Primary_Expression*) ((miembro_de_argument_expression_list -> nodo) -> contenido)))
                                                {
                                                    case TIPO_CONSTANTE:
                                                        tipoDeDato_argumento = (((Contenido_Constante_AST*) ((miembro_de_argument_expression_list -> nodo) -> hijoIzquierdo)) -> tipoConstante);
                                                        if(tipoDeDato_parametro != tipoDeDato_argumento)
                                                        {
                                                            bandera_correcto = FALSE;
                                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: pasando desde el argumento %d de '%s' un tipo de dato incompatible \n", archivo_yyin, (miembro_de_argument_expression_list -> ubicacion).first_line, (miembro_de_argument_expression_list -> ubicacion).first_column, numero_de_argumento, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: se esperaba '%s' pero el argumento es de tipo '%s' \n", archivo_yyin, (parametro_funcion -> ubicacionParametro).first_line, (parametro_funcion -> ubicacionParametro).first_column, string_enum_Dato[tipoDeDato_parametro], string_enum_Dato[tipoDeDato_argumento]);
                                                            cantidadErroresSemanticos++;
                                                        }
                                                    break;
                                                    case TIPO_LITERAL_CADENA:
                                                        bandera_correcto = FALSE;
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: pasando desde el argumento %d de '%s' un tipo de dato incompatible \n", archivo_yyin, (miembro_de_argument_expression_list -> ubicacion).first_line, (miembro_de_argument_expression_list -> ubicacion).first_column, numero_de_argumento, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                                        error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: se esperaba '%s' pero el argumento es de tipo 'char*' \n", archivo_yyin, (parametro_funcion -> ubicacionParametro).first_line, (parametro_funcion -> ubicacionParametro).first_column, string_enum_Dato[tipoDeDato_parametro]);
                                                        cantidadErroresSemanticos++;
                                                    break;
                                                    case TIPO_IDENTIFICADOR:
                                                        resultadoBusqueda_Identificador = buscarSimbolo((char*) ((miembro_de_argument_expression_list -> nodo) -> hijoIzquierdo), BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
                                                        if(resultadoBusqueda_Identificador == NULL)
                                                        {
                                                            bandera_correcto = FALSE;
                                                        }
                                                        else
                                                        {
                                                            switch(resultadoBusqueda_Identificador -> tipoSimbolo)
                                                            {
                                                                case OBJETO:
                                                                    if(((((Objeto*) (resultadoBusqueda_Identificador -> simbolo)) -> tipoDeDato).tipoDeConstruccion) == CONSTRUCCION_BASICA)
                                                                    {
                                                                        tipoDeDato_argumento = (((Basico*) ((((Objeto*) (resultadoBusqueda_Identificador -> simbolo)) -> tipoDeDato).construccion)) -> tipoDeDato);
                                                                        if(tipoDeDato_parametro != tipoDeDato_argumento)
                                                                        {
                                                                            bandera_correcto = FALSE;
                                                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: pasando desde el argumento %d de '%s' un tipo de dato incompatible \n", archivo_yyin, (miembro_de_argument_expression_list -> ubicacion).first_line, (miembro_de_argument_expression_list -> ubicacion).first_column, numero_de_argumento, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                                                            error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: se esperaba '%s' pero el argumento es de tipo '%s' \n", archivo_yyin, (parametro_funcion -> ubicacionParametro).first_line, (parametro_funcion -> ubicacionParametro).first_column, string_enum_Dato[tipoDeDato_parametro], string_enum_Dato[tipoDeDato_argumento]);
                                                                            cantidadErroresSemanticos++;
                                                                        }
                                                                    }
                                                                break;
                                                                case ENUMERADOR:
                                                                break;
                                                                case FUNCION:
                                                                break;
                                                                default:
                                                                break;
                                                            }
                                                        }
                                                    break;
                                                }
                                            }
                                        }

                                        numero_de_argumento++;
                                        parametro_funcion = parametro_funcion -> siguienteParametro;
                                        miembro_de_argument_expression_list = miembro_de_argument_expression_list -> siguiente;
                                    }
                                    while((bandera_correcto) && (parametro_funcion != NULL) && (miembro_de_argument_expression_list != NULL));
                                }

                                if((((Funcion*) (resultadoBusqueda -> simbolo)) -> cantidadDeParametros) > (lista_de_argument_expression_list -> cantidadDeNodos))
                                {
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: insuficientes argumentos para la funcion '%s' \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: declarado aqui \n", archivo_yyin, (resultadoBusqueda -> ubicacionSimbolo).first_line, (resultadoBusqueda -> ubicacionSimbolo).first_column);
                                    cantidadErroresSemanticos++;
                                }
                                else if(((((Funcion*) (resultadoBusqueda -> simbolo)) -> cantidadDeParametros) < (lista_de_argument_expression_list -> cantidadDeNodos)) && (!((((Funcion*) (resultadoBusqueda -> simbolo)) -> banderaElipsis))))
                                {
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: demasiados argumentos para la funcion '%s' \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column, (char*) ((raiz -> hijoIzquierdo) -> hijoIzquierdo));
                                    error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Nota: declarado aqui \n", archivo_yyin, (resultadoBusqueda -> ubicacionSimbolo).first_line, (resultadoBusqueda -> ubicacionSimbolo).first_column);
                                    cantidadErroresSemanticos++;
                                }
                            }
                        }
					}
					else
					{
						error_semantico_fprintf(stderr, "Semantica: %s:%d:%d: Error semantico: el objeto invocado no es una funcion o un puntero a una funcion \n", archivo_yyin, ((raiz -> hijoIzquierdo) -> ubicacion).first_line, ((raiz -> hijoIzquierdo) -> ubicacion).first_column);
						cantidadErroresSemanticos++;
					}
				}
            break;
            default:
            break;
        }
    }
    else
    {
        errorCritico("Error de programa: resolver_nodo_ast_multiplicative_expression: tipoNodoAST pasado como parametro incorrecto");
    }
}

void resolver_ast(Nodo_AST* raiz)
{
    switch(raiz -> tipoNodoAST)
    {
        case FUNCTION_DEFINITION:
            resolver_nodo_ast_function_definition(raiz);
        break;
        case DECLARATION:
            resolver_nodo_ast_declaration(raiz);
        break;
        case MULTIPLICATIVE_EXPRESSION:
            resolver_nodo_ast_multiplicative_expression(raiz);
        break;
        case POSTFIX_EXPRESSION:
            resolver_nodo_ast_postfix_expression(raiz);
        break;
        default:
        break;
    }
}

void recorrer_ast_declarator(struct ListaSemantica** pila, struct Nodo_AST* raiz)
{
    if(raiz != NULL)
	{
		switch(raiz -> tipoNodoAST)
		{
            case DECLARATOR:
                recorrer_ast_pointer(pila, raiz -> hijoIzquierdo);
                recorrer_ast_declarator(pila, raiz -> hijoDerecho);
            break;
            case DIRECT_DECLARATOR:
                switch(*((enum Tipo_Direct_Declarator*) (raiz -> contenido)))
                {
                    case TIPO_NO_ABSTRACTO_IDENTIFICADOR:
                        push_pila_semantica(pila, raiz);
                    break;
                    case TIPO_NO_ABSTRACTO_DECLARATOR:
                        recorrer_ast_declarator(pila, raiz -> hijoIzquierdo);
                    break;
                    case TIPO_NO_ABSTRACTO_ARREGLO:
                        push_pila_semantica(pila, raiz);
                        recorrer_ast_declarator(pila, raiz -> hijoIzquierdo);
                    break;
                    case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_NUEVA:
                        push_pila_semantica(pila, raiz);
                        recorrer_ast_declarator(pila, raiz -> hijoIzquierdo);
                    break;
                    case TIPO_NO_ABSTRACTO_FUNCION_NOTACION_ANTIGUA:
                        push_pila_semantica(pila, raiz);
                        recorrer_ast_declarator(pila, raiz -> hijoIzquierdo);
                    break;
                }
            break;
            default:
                errorCritico("Error de programa: recorrer_ast_declarator: tipoNodoAST pasado como parametro incorrecto");
            break;
        }
    }
}

void recorrer_ast_pointer(struct ListaSemantica** pila, struct Nodo_AST* raiz)
{
    if(raiz != NULL)
	{
		switch(raiz -> tipoNodoAST)
		{
            case POINTER:
                push_pila_semantica(pila, raiz);
                recorrer_ast_pointer(pila, raiz -> hijoDerecho);
            break;
            default:
                errorCritico("Error de programa: recorrer_ast_pointer: tipoNodoAST pasado como parametro incorrecto");
            break;
        }
    }
}

void recorrer_ast_multiplicative_expression(struct ListaSemantica** pila, struct Nodo_AST* raiz)
{
    if(raiz != NULL)
	{
		switch(raiz -> tipoNodoAST)
		{
            case PRIMARY_EXPRESSION:
                push_pila_semantica(pila, raiz);
            break;
            case MULTIPLICATIVE_EXPRESSION:
                switch(*((enum Tipo_Multiplicative_Expression*) (raiz -> contenido)))
                {
                    case MULTIPLICACION:
                        recorrer_ast_multiplicative_expression(pila, raiz -> hijoDerecho);
                        recorrer_ast_multiplicative_expression(pila, raiz -> hijoIzquierdo);
                    break;
                    default:
                    break;
                }
            break;
            default:
            break;
        }
    }
}

void push_pila_semantica(struct ListaSemantica** pila, struct Nodo_AST* nodoAAgregar)
{
	ListaSemantica* nuevo = (ListaSemantica*) malloc(sizeof (ListaSemantica));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(nuevo);
    nuevo -> elemento = nodoAAgregar;
    nuevo -> siguiente = *pila;

    *pila = nuevo;
}

Nodo_AST* pop_pila_semantica(struct ListaSemantica** pila)
{
	if((*pila) != NULL)
    {
        Nodo_AST* aRetornar;
        ListaSemantica* aux;

        aux = *pila;
        aRetornar = aux -> elemento;
        *pila = aux -> siguiente;
        free(aux);
        return aRetornar;
    }
    return NULL;
}

enum Dato dato_asociado(enum Tipo_Type_Specifier* primer_type_specifier, enum Tipo_Type_Specifier* segundo_type_specifier, enum Tipo_Type_Specifier* tercer_type_specifier)
{
    enum Dato aRetornar = DATO_INDEFINIDO;
    if(primer_type_specifier != NULL)
    {
        switch(*primer_type_specifier)
        {
            case TIPO_VOID:
                return DATO_VOID;
            break;
            case TIPO_CHAR:
                return DATO_CHAR;
            break;
            case TIPO_SHORT:
                return DATO_SHORT;
            break;
            case TIPO_INT:
                return DATO_INT;
            break;
            case TIPO_LONG:
                if(segundo_type_specifier == NULL)
                {
                    return DATO_LONG;
                }
                else
                {
                    switch(*segundo_type_specifier)
                    {
                        case TIPO_INT:
                            return DATO_LONG;
                        break;
                        case TIPO_DOUBLE:
                            return DATO_LONG_DOUBLE;
                        break;
                        default:
                            errorCritico("Error de programa: dato_asociado: segundo_type_specifier pasado como parametro incorrecto");
                        break;
                    }
                }
            break;
            case TIPO_FLOAT:
                return DATO_FLOAT;
            break;
            case TIPO_DOUBLE:
                return DATO_DOUBLE;
            break;
            case TIPO_SIGNED:
                if(segundo_type_specifier == NULL)
                {
                    return DATO_INT;
                }
                else
                {
                    switch(*segundo_type_specifier)
                    {
                        case TIPO_CHAR:
                            return DATO_SIGNED_CHAR;
                        break;
                        case TIPO_SHORT:
                            return DATO_SHORT;
                        break;
                        case TIPO_INT:
                            return DATO_INT;
                        break;
                        case TIPO_LONG:
                            return DATO_LONG;
                        break;
                        default:
                            errorCritico("Error de programa: dato_asociado: segundo_type_specifier pasado como parametro incorrecto");
                        break;
                    }
                }
            break;
            case TIPO_UNSIGNED:
                if(segundo_type_specifier == NULL)
                {
                    return DATO_UNSIGNED_INT;
                }
                else
                {
                    switch(*segundo_type_specifier)
                    {
                        case TIPO_CHAR:
                            return DATO_UNSIGNED_CHAR;
                        break;
                        case TIPO_SHORT:
                            return DATO_UNSIGNED_SHORT;
                        break;
                        case TIPO_INT:
                            return DATO_UNSIGNED_INT;
                        break;
                        case TIPO_LONG:
                            return DATO_UNSIGNED_LONG;
                        break;
                        default:
                            errorCritico("Error de programa: dato_asociado: segundo_type_specifier pasado como parametro incorrecto");
                        break;
                    }
                }
            break;
            case TIPO_STRUCT_OR_UNION_SPECIFIER: case TIPO_ENUM_SPECIFIER: case TIPO_NOMBRE_DE_TYPEDEF:
                errorCritico("Error de programa: dato_asociado: primer_type_specifier pasado como parametro incorrecto");
            break;
        }
    }
    else
    {
        errorCritico("Error de programa: dato_asociado: primer_type_specifier pasado como parametro incorrecto");
    }
    return aRetornar;
}

enum Dato conversion_aritmetica_usual(enum Dato primerOperando, enum Dato segundoOperando)
{
    if((primerOperando == DATO_LONG_DOUBLE) || (segundoOperando == DATO_LONG_DOUBLE)) return DATO_LONG_DOUBLE;
    else if((primerOperando == DATO_DOUBLE) || (segundoOperando == DATO_DOUBLE)) return DATO_DOUBLE;
    else if((primerOperando == DATO_FLOAT) || (segundoOperando == DATO_FLOAT)) return DATO_FLOAT;
    else
    {
        primerOperando = promocion_entera(primerOperando);
        segundoOperando = promocion_entera(segundoOperando);
        if((primerOperando == DATO_UNSIGNED_LONG) || (segundoOperando == DATO_UNSIGNED_LONG)) return DATO_UNSIGNED_LONG;
        else if(((primerOperando == DATO_LONG) && (segundoOperando == DATO_UNSIGNED_INT)) && ((primerOperando == DATO_UNSIGNED_INT) && (segundoOperando == DATO_LONG)))
        {
            if((LONG_MIN <= 0) && (LONG_MAX >= UINT_MAX)) return DATO_LONG;
            else return DATO_UNSIGNED_LONG;
        }
        else if((primerOperando == DATO_LONG) || (segundoOperando == DATO_LONG)) return DATO_LONG;
        else if((primerOperando == DATO_UNSIGNED_INT) || (segundoOperando == DATO_UNSIGNED_INT)) return DATO_UNSIGNED_INT;
    }
    return DATO_INT;
}

enum Dato promocion_entera(enum Dato operando)
{
    switch(operando)
    {
        case DATO_CHAR:
            if((INT_MIN <= CHAR_MIN) && (INT_MAX >= CHAR_MAX)) return DATO_INT;
            else return DATO_UNSIGNED_INT;
        break;
        case DATO_SIGNED_CHAR:
            if((INT_MIN <= SCHAR_MIN) && (INT_MAX >= SCHAR_MAX)) return DATO_INT;
            else return DATO_UNSIGNED_INT;
        break;
        case DATO_UNSIGNED_CHAR:
            if((INT_MIN <= 0) && (INT_MAX >= UCHAR_MAX)) return DATO_INT;
            else return DATO_UNSIGNED_INT;
        break;
        case DATO_SHORT:
            if((INT_MIN <= SHRT_MIN) && (INT_MAX >= SHRT_MAX)) return DATO_INT;
            else return DATO_UNSIGNED_INT;
        break;
        case DATO_UNSIGNED_SHORT:
            if((INT_MIN <= 0) && (INT_MAX >= USHRT_MAX)) return DATO_INT;
            else return DATO_UNSIGNED_INT;
        break;
        default:
        break;
    }
    return operando;
}