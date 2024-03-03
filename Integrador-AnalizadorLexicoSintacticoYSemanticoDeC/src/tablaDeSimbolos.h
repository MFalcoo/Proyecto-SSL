#include "general.h"
#define YYLTYPE Ubicacion
#define TAMANIO_TABLA_HASH 211

typedef struct Ubicacion
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} Ubicacion;

typedef enum TipoBusqueda
{
	BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR,
	BUSQUEDA_ENUMERACION_Y_ESTRUCTURA,
	BUSQUEDA_SENTENCIA_ETIQUETADA
} TipoBusqueda;

typedef enum TipoSimbolo
{
	OBJETO,
	FUNCION,
    TYPEDEF,
	ENUMERADOR,

	ENUMERACION,
	ESTRUCTURA,

	SENTENCIA_ETIQUETADA
} TipoSimbolo;

typedef enum Construccion
{
    CONSTRUCCION_INDEFINIDA,
	CONSTRUCCION_BASICA,
	CONSTRUCCION_PUNTERO,
	CONSTRUCCION_ARREGLO,
	CONSTRUCCION_CAMPO_DE_BITS,
	CONSTRUCCION_ESTRUCTURA,
	CONSTRUCCION_ENUMERACION,
	CONSTRUCCION_FUNCION
} Construccion;

typedef enum Dato
{
	DATO_INDEFINIDO,
    DATO_VOID,
    DATO_CHAR,
	DATO_SIGNED_CHAR,
	DATO_UNSIGNED_CHAR,
    DATO_SHORT,
	DATO_UNSIGNED_SHORT,
    DATO_INT,
	DATO_UNSIGNED_INT,
    DATO_LONG,
	DATO_UNSIGNED_LONG,
    DATO_FLOAT,
    DATO_DOUBLE,
	DATO_LONG_DOUBLE
} Dato;

typedef enum Almacenamiento
{
	ALMACENAMIENTO_INDEFINIDO,
	ALMACENAMIENTO_AUTO,
	ALMACENAMIENTO_REGISTER,
	ALMACENAMIENTO_STATIC,
	ALMACENAMIENTO_EXTERN
} Almacenamiento;

typedef enum Struct_o_Union
{
    STRUCT,
	UNION
} Struct_o_Union;

typedef union Valor
{
	char char_value;
	signed char signed_char_value;
	unsigned char unsigned_char_value;
	short short_value;
	unsigned short unsigned_short_value;
	int int_value;
	unsigned int unsigned_int_value;
	long long_value;
	unsigned long unsigned_long_value;
	float float_value;
	double double_value;
	long double long_double_value;

	void* void_pointer_value;
} Valor;

typedef struct Simbolo
{
	struct Ubicacion ubicacionSimbolo;
	char* nombreSimbolo;
	int alcanceSimbolo;

	enum Almacenamiento claseAlmacenamiento;

	enum TipoSimbolo tipoSimbolo;
    struct Simbolo* simbolo;
	
	struct Simbolo* siguienteSimbolo;
} Simbolo;

typedef struct TipoDeDato
{
	enum Booleano calificadorDeTipoConst;
	enum Booleano calificadorDeTipoVolatile;

	enum Construccion tipoDeConstruccion;
	struct TipoDeDato* construccion;
} TipoDeDato;

typedef struct Objeto
{
    struct TipoDeDato tipoDeDato;
} Objeto;

typedef struct Parametro
{
    char* nombreParametro;
    struct Ubicacion ubicacionParametro;

	enum Almacenamiento almacenamientoParametro;
    struct TipoDeDato tipoParametro;

	struct Parametro* siguienteParametro;
} Parametro;

typedef struct Funcion
{
	enum Booleano banderaDefinicion; // Para saber si ya fue definida o si sólo fue prototipada
	enum Booleano banderaElipsis;
    struct TipoDeDato tipoRetorno;
    int cantidadDeParametros;
	struct Parametro* listaDeParametros;
} Funcion;

typedef struct Typedef
{
	struct TipoDeDato tipoTypedef;
} Typedef;

typedef struct Enumerador
{
	struct TipoDeDato tipoDeDato;

	struct Enumerador* siguienteEnumerador;
} Enumerador;

typedef struct Enumeracion
{
	struct Enumerador* listaDeEnumeradores;
} Enumeracion;

typedef struct Miembro
{
	char* nombreMiembro;
	struct TipoDeDato tipoDeDato;
	struct Miembro* siguienteMiembro;
} Miembro;

typedef struct Estructura
{
	enum Struct_o_Union struct_o_union;
	struct Miembro* listaDeMiembros;
} Estructura;

typedef struct Basico
{
	enum Dato tipoDeDato;
	union Valor valor;
} Basico;

typedef struct Puntero
{
	union Valor direccionDeMemoria;
	struct TipoDeDato haciaDondeApunta;
} Puntero;

typedef struct Elemento
{
	union Valor valor;
	struct Elemento* siguienteElemento;
} Elemento;

typedef struct Dimension
{
	int cantidadDeElementos;
	struct Elemento* listaElementos;

	struct Dimension* siguienteDimension;
} Dimension;

typedef struct Arreglo
{
	struct TipoDeDato tipoDeDato;
	int cantidadDeDimensiones;
	struct Dimension* listaDeDimensiones;
} Arreglo;

typedef struct Campo_de_Bits
{
	int cantidadDeBits;
	struct TipoDeDato* tipoDeDato;
} Campo_de_Bits;

Simbolo** tablaDeSimbolos;

void inicializar_tabla_de_simbolos(void);
unsigned int hash(char*);
void insertar_En_La_Tabla_De_Simbolos(char*, Simbolo*);
void agregar_parametro_a_funcion(Funcion*, Parametro*);
Simbolo* buscarSimbolo(char*, enum TipoBusqueda);
void agregar_tag_a_estructura(char*, Simbolo*);
void agregar_struct_or_union_a_estructura(enum Struct_o_Union, Simbolo*);
void incrementarAlcanceActual(void);
void decrementarAlcanceActual(void);
/*
void liberar_Simbolo(Simbolo*);
void liberarListaDeParametros(Parametro*);
*/