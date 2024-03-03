#include "ast.h"

#define variable_declarada_printf(formato, ...) \
    do { \
        int cantidadDeCaracteres = printf(formato, __VA_ARGS__); \
        char* descripcion = (char*) malloc((cantidadDeCaracteres + 1 + 1) * sizeof(char)); \
        sprintf(descripcion, "\t" formato, __VA_ARGS__); \
        insertar_al_final_de_lista_de_descripciones(&variablesDeclaradas, descripcion); \
    } while (0)

#define funcion_declarada_printf(formato, ...) \
    do { \
        int cantidadDeCaracteres = printf(formato, __VA_ARGS__); \
        char* descripcion = (char*) malloc((cantidadDeCaracteres + 1 + 1) * sizeof(char)); \
        sprintf(descripcion, "\t" formato, __VA_ARGS__); \
        insertar_al_final_de_lista_de_descripciones(&funcionesDeclaradas, descripcion); \
    } while (0)

#define error_lexico_fprintf(stream, formato, ...) \
    do { \
        int cantidadDeCaracteres = fprintf(stream, formato, __VA_ARGS__); \
        char* descripcion = (char*) malloc((cantidadDeCaracteres + 1 + 1) * sizeof(char)); \
        sprintf(descripcion, "\t" formato, __VA_ARGS__); \
        insertar_al_final_de_lista_de_descripciones(&erroresLexicos, descripcion); \
    } while (0)

#define error_sintactico_fprintf(stream, formato, ...) \
    do { \
        int cantidadDeCaracteres = fprintf(stream, formato, __VA_ARGS__); \
        char* descripcion = (char*) malloc((cantidadDeCaracteres + 1 + 1) * sizeof(char)); \
        sprintf(descripcion, "\t" formato, __VA_ARGS__); \
        insertar_al_final_de_lista_de_descripciones(&erroresSintacticos, descripcion); \
    } while (0)

#define error_semantico_fprintf(stream, formato, ...) \
    do { \
        int cantidadDeCaracteres = fprintf(stream, formato, __VA_ARGS__); \
        char* descripcion = (char*) malloc((cantidadDeCaracteres + 1 + 1) * sizeof(char)); \
        sprintf(descripcion, "\t" formato, __VA_ARGS__); \
        insertar_al_final_de_lista_de_descripciones(&erroresSemanticos, descripcion); \
    } while (0)

typedef struct SimboloDeclarado
{
    Simbolo* unSimbolo;
    Simbolo* simboloSiguiente;
} SimboloDeclarado;

typedef struct Descripcion
{
    char* descripcion;
    struct Descripcion* siguiente;
} Descripcion;

void insertar_al_final_de_lista_de_descripciones(Descripcion**, char*);
void reportarListaDeDescripciones(Descripcion*);