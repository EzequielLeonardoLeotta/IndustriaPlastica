#ifndef __COLOR_H__
#define __COLOR_H__
#include "ListaFigura.h"

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

typedef struct Color {
	string descripcion;
	ListaFigura lstfigura;
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
    PRE: La instancia del TDA (Color) no debe haberse creado (constructor) ni destruido (destructor) con anterioridad.
    POST: Deja la instancia del TDA (Color) listo para ser usado.
    ATRIBUTOS: Color (instancia sobre la cual se aplica la primitiva), descripcion, lstfigura.
    RETORNO: No aplica.
*/

void constructor(Color& color, Figura figura);

/*
    PRE: La instancia del TDA (Color) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Se inserta el color en la descripcion.
    ATRIBUTOS: Color (instancia sobre la cual se aplica la primitiva), descripcion.
    RETORNO: No aplica.
*/

void setDescripcion(Color& color, string descripcion);

/*
    PRE: La instancia del TDA (Color) debe haberse creado (constructor) pero no debe estar destruida (destructor). La instancia de la lista figura debe ser creada con el TDA ListaFigura.
    POST: Se agrega la listaFigura del atributo lista. 
    ATRIBUTOS: Color (instancia sobre la cual se aplica la primitiva), lista.
    RETORNO: No aplica.
*/

void setListaFigura(Color& color, ListaFigura lista);

/*
    PRE: La instancia del TDA (Color) debe haberse creado (constructor) pero no debe estar destruida (destructor). 
    POST: Devuelve la descripcion del color.
    ATRIBUTOS: Color (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve la descripcion del color.
*/

string getDescripcion(Color& color);

/*
    PRE: La instancia del TDA (Color) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve la ListFigura del color.
    ATRIBUTOS: Color (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve la ListFigura del color.
*/

ListaFigura getListaFigura(Color& color);

#endif