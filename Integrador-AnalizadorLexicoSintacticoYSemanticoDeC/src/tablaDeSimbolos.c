#include "bibliotecas.h"
#include "ast.h"

int alcanceActual = 0;
enum Booleano banderaDeclaracion = FALSE;

void inicializar_tabla_de_simbolos(void)
{
	tablaDeSimbolos = (Simbolo**) malloc(TAMANIO_TABLA_HASH * sizeof(Simbolo*));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(tablaDeSimbolos);
	for(int i = 0 ; i < TAMANIO_TABLA_HASH ; ++i) tablaDeSimbolos[i] = NULL;
}

unsigned int hash(char* literalCadena)
{
	unsigned int valorHash = 0;
	for(; *literalCadena != '\0' ; ++literalCadena) valorHash += (unsigned int) *literalCadena;
	valorHash += literalCadena[0] % 11 + (literalCadena[0] << 3) - literalCadena[0];
	return valorHash % TAMANIO_TABLA_HASH;
}

void insertar_En_La_Tabla_De_Simbolos(char* literalCadena, Simbolo* simbolo)
{
	unsigned int valorHash = hash(literalCadena);
    simbolo -> siguienteSimbolo = tablaDeSimbolos[valorHash];
    tablaDeSimbolos[valorHash] = simbolo;
}

void agregar_parametro_a_funcion(Funcion* nueva_Funcion, Parametro* nuevo_Parametro)
{   
    Parametro* aux;
    if((nueva_Funcion -> listaDeParametros) != NULL)
    {
        aux = nueva_Funcion -> listaDeParametros;
        while((aux -> siguienteParametro) != NULL) aux = aux -> siguienteParametro;
        aux -> siguienteParametro = nuevo_Parametro;
    }
    else
    {
        nueva_Funcion -> listaDeParametros = nuevo_Parametro;
    }
    (nueva_Funcion -> cantidadDeParametros)++;
}

Simbolo* buscarSimbolo(char* literalCadena, enum TipoBusqueda tipoBusqueda)
{
	unsigned int valorHash = hash(literalCadena);
	Simbolo* listaEnlazada = tablaDeSimbolos[valorHash];
	while (listaEnlazada != NULL)
    {
        switch(tipoBusqueda)
        {
            case BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR:
                switch(listaEnlazada -> tipoSimbolo)
                {
                    case OBJETO: case FUNCION: case TYPEDEF: case ENUMERADOR:
                        if (strcmp(literalCadena, (listaEnlazada -> nombreSimbolo)) == 0) return listaEnlazada;
                    break;
                    default:
                    break;
                }
            break;
            case BUSQUEDA_ENUMERACION_Y_ESTRUCTURA:
                switch(listaEnlazada -> tipoSimbolo)
                {
                    case ENUMERACION: case ESTRUCTURA:
                        if (strcmp(literalCadena, (listaEnlazada -> nombreSimbolo)) == 0) return listaEnlazada;
                    break;
                    default:
                    break;
                }
            break;
            default:
                errorCritico("Error de programa: buscarSimbolo: tipoBusqueda pasado como parametro incorrecto");
            break;
        }
        listaEnlazada = listaEnlazada -> siguienteSimbolo;
    }
    return NULL;
}

char* struct_o_union(enum Struct_o_Union struct_o_union)
{
    switch(struct_o_union)
    {
        case STRUCT: return "struct"; break;
        case UNION: return "union"; break;
        default: return NULL; break;
    }
}

void agregar_tag_a_estructura(char* identificador, Simbolo* simboloEstructura)
{
    if(simboloEstructura != NULL)
    {
        if(simboloEstructura -> tipoSimbolo == ESTRUCTURA)
        {
            simboloEstructura -> nombreSimbolo = identificador;
        }
        else
        {
            errorCritico("Error de programa: agregar_tag_a_estructura: simboloEstructura pasado como parametro incorrecto");
        }
    }
}

void agregar_struct_or_union_a_estructura(enum Struct_o_Union struct_o_union, Simbolo* simboloEstructura)
{
    if(simboloEstructura != NULL)
    {
        if(simboloEstructura -> tipoSimbolo == ESTRUCTURA)
        {
            ((Estructura*) (simboloEstructura -> simbolo)) -> struct_o_union = struct_o_union;
        }
        else
        {
            errorCritico("Error de programa: agregar_struct_or_union_a_estructura: simboloEstructura pasado como parametro incorrecto");
        }
    }
}

/*
Simbolo* crear_simbolo_funcion(struct Ubicacion ubicacion_simbolo, char* nombreFuncion_simbolo, char banderaDefinicion_simbolo, struct TipoDeDato tipoRetorno_simbolo, int cantidadDeParametros_simbolo, struct Parametro* listaDeParametros_simbolo)
{
    Funcion* simbolo_funcion = (Funcion*) malloc(sizeof(Funcion));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(simbolo_funcion);
    simbolo_funcion -> ubicacion = ubicacion_simbolo;
    simbolo_funcion -> nombreFuncion = nombreFuncion_simbolo;
	simbolo_funcion -> banderaDefinicion = banderaDefinicion_simbolo;
    simbolo_funcion -> tipoRetorno = tipoRetorno_simbolo;
    simbolo_funcion -> cantidadDeParametros = cantidadDeParametros_simbolo;
    simbolo_funcion -> listaDeParametros = listaDeParametros_simbolo;
    return (Simbolo*) simbolo_funcion;
}

Simbolo* crear_simbolo_variable(struct Ubicacion ubicacion_simbolo, char* nombreVariable_simbolo, int alcanceVariable_simbolo, struct TipoDeDato tipoDeDato_simbolo)
{
    Variable* simbolo_variable = (Variable*) malloc(sizeof(Variable));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(simbolo_variable);
    simbolo_variable -> ubicacion = ubicacion_simbolo;
    simbolo_variable -> nombreVariable = nombreVariable_simbolo;
	simbolo_variable -> alcanceVariable = alcanceVariable_simbolo;
    simbolo_variable -> tipoDeDato = tipoDeDato_simbolo;
    return (Simbolo*) simbolo_variable;
}
*/

void incrementarAlcanceActual(void)
{
    alcanceActual++;
}

void decrementarAlcanceActual(void)
{
	Simbolo* listaEnlazada,* aux;
	for (int i = 0 ; i < TAMANIO_TABLA_HASH ; i++)
    {
		if(tablaDeSimbolos[i] != NULL)
        {
			listaEnlazada = tablaDeSimbolos[i];
			while((listaEnlazada != NULL) && ((listaEnlazada -> alcanceSimbolo) == alcanceActual))
            {
                aux = listaEnlazada -> siguienteSimbolo;
                /*liberar_Simbolo(listaEnlazada);*/
				listaEnlazada = aux;
			}
			tablaDeSimbolos[i] = listaEnlazada;
		}
	}
    alcanceActual--;
}

/*
void liberar_Simbolo(Simbolo* simbolo)
{
    switch(simbolo -> tipoSimbolo)
    {
        Funcion* simboloFuncion;
        Variable* simboloVariable;
        Typedef* simboloTypedef;

        case FUNCION:
            simboloFuncion = (Funcion*) simbolo;
            if((simboloFuncion -> nombreFuncion) != NULL) free(simboloFuncion -> nombreFuncion);
            liberarListaDeParametros(simboloFuncion -> listaDeParametros);
            free(simboloFuncion);
        break;
        case VARIABLE:
            simboloVariable = (Variable*) simbolo;
            if((simboloVariable -> nombreVariable) != NULL) free(simboloVariable -> nombreVariable);
            free(simboloVariable);
        break;
        case TYPEDEF:
            simboloTypedef = (Typedef*) simbolo;
            if((simboloTypedef -> nombreTypedef) != NULL) free(simboloTypedef -> nombreTypedef);
            free(simboloTypedef);
        break;
        default:
            errorCritico("Error de programa: liberar_Simbolo");
        break;
    }
}

void liberarListaDeParametros(Parametro* listaDeParametros)
{
    Parametro* aux;

    while(listaDeParametros != NULL)
    {
        aux = listaDeParametros -> siguienteParametro;
        if((listaDeParametros -> nombreParametro) != NULL) free(listaDeParametros -> nombreParametro);
        free(listaDeParametros);
        listaDeParametros = aux;
    }
}
*/