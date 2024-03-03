#include "bibliotecas.h"
#include "tablaDeSimbolos.h"

extern YYLTYPE yylloc;

void pausa(void)
{
    printf("Presione ENTER para continuar...\n");
    getchar();
}

void verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(void* puntero)
{
    if(puntero == NULL) errorCritico("Error de programa: Hubo un fallo de asignacion de memoria dinamica");
}

void errorCritico(char* mensaje)
{
    fprintf(stderr, "%s \n", mensaje);
    pausa();
    exit(1);
}

void inicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line = INICIO_CONTEO_LINEA;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

void reinicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line;
    yylloc.first_column = yylloc.last_column;
}

void iniciarCadena(char** destino, char* fuente)
{
    *destino = (char*) malloc((strlen(fuente) + 1) * sizeof(char));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(*destino);
    strcpy(*destino, fuente);
}

void iniciarCadenaHasta(char** destino, char* fuente, size_t cantidad)
{
    if(cantidad > strlen(fuente)) cantidad = strlen(fuente);
    *destino = (char*) malloc((cantidad + 1) * sizeof(char));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(*destino);
    strncpy(*destino, fuente, cantidad);
    (*destino)[cantidad] = '\0';
}

void concatenarCadena(char** destino, char* fuente)
{
    *destino = (char*) realloc(*destino, (strlen(*destino) + strlen(fuente) + 1) * sizeof(char));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(*destino);
    strcat(*destino, fuente);
}

void concatenarCadenaHasta(char** destino, char* fuente, size_t cantidad)
{
    if(cantidad > strlen(fuente)) cantidad = strlen(fuente);
    *destino = (char*) realloc(*destino, (strlen(*destino) + cantidad + 1) * sizeof(char));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(*destino);
    strncat(*destino, fuente, cantidad);
    (*destino)[strlen(*destino) + cantidad] = '\0';
}