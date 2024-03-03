#include "bibliotecas.h"
#include "reporte.h"

//SimboloDeclarado* variablesDeclaradas = NULL;
//SimboloDeclarado* funcionesDeclaradas = NULL;
Descripcion* variablesDeclaradas = NULL;
Descripcion* funcionesDeclaradas = NULL;
Descripcion* erroresLexicos = NULL;
Descripcion* erroresSintacticos = NULL;
Descripcion* erroresSemanticos = NULL;

void insertar_al_final_de_lista_de_descripciones(Descripcion** inicio, char* descripcion)
{
    while((*inicio) != NULL) inicio = &((*inicio) -> siguiente);
    
    *inicio = (Descripcion*) malloc(sizeof(Descripcion));
    verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(*inicio);
    (*inicio) -> descripcion = descripcion;
    (*inicio) -> siguiente = NULL;
}

void reportarListaDeDescripciones(Descripcion* inicio)
{
    while(inicio != NULL)
    {
        printf("%s", inicio -> descripcion);
        inicio = inicio -> siguiente;
    }
}