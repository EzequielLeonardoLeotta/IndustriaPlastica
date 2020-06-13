#ifndef __LISTACOLOR_H__
#define __LISTACOLOR_H__
#include <iostream>
#include "Color.h"

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

struct NodoListaColor {
    Color color;
    NodoListaColor* sgte; // puntero al siguiente
};

typedef NodoListaColor* PtrNodoListaColor;

struct ListaColor {
    PtrNodoListaColor primero;      // puntero al primer nodo de la lista
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
    PRE: La lista no debe haber sido creada.
    POST: ListaColor queda creada y preparada para ser usada.
    ATRIBUTOS: ListaColor.
    RETORNO: No aplica.
*/
void crearListaColor(ListaColor& lista);

/*
    PRE: Lista Creada con crearListaColor().
    POST: Devuelve true si lista esta vacia, sino devuelve false.
    ATRIBUTOS: ListaColor.
    RETORNO: true o false.
*/
bool listaVacia(ListaColor& lista);

/*
    PRE: Lista Creada con crearListaColor().
    POST: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
    o sea el valor Null, que en esta implementacion representa el final de la ListaColor.
    ATRIBUTOS: No aplica.
    RETORNO: PtrNodoListaColor. 
*/
PtrNodoListaColor finColor();

/*
    PRE: Lista Creada con crearListaColor().
    POST: Devuelve el puntero al primer elemento de la lista, o devuelve finColor() si esta vacia.
    ATRIBUTOS: ListaColor.
    RETORNO: Puntero al primer nodo.
*/
PtrNodoListaColor primero(ListaColor& lista);

/*
    PRE: Lista Creada con crearListaColor().
    POST: Devuelve el puntero al nodo proximo del apuntado, o devuelve finColor()
    si ptrNodo apuntaba a finColor() o si lista esta vacia.
    ATRIBUTOS: ListaColor, ptrNodoListaColor.
    RETORNO: Puntero al nodo siguiente.
*/
PtrNodoListaColor siguiente(ListaColor& lista, PtrNodoListaColor ptrNodo);

/*
    PRE: Lista Creada con crearListaColor().
    POST: Devuelve el puntero al ultimo nodo de la lista, o devuelve finColor() si lista esta vacia.
    ATRIBUTOS: ListaColor.
    RETORNO: Puntero al ultimo nodo.
*/
PtrNodoListaColor ultimo(ListaColor& lista);

/*
    PRE: Lista creada con crearListaColor().
    POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero al nodo insertado.
    ATRIBUTOS: ListaColor, Color.
    RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaColor adicionarFinal(ListaColor& lista, Color color);

/*
    PRE: Lista creada con crearListaColor(), no vacia. ptrNodo es distinto de finColor().
    POST: Devuelve el dato del nodo apuntado por ptrNodo.
    ATRIBUTOS: ListaColor, Color, PtrNodoListaColor.
    RETORNO: Puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDatoLcolor(ListaColor& lista, Color& color, PtrNodoListaColor ptrNodo);

/*
    PRE: Lista creada con crearListaColor().ptrNodo es un puntero a un nodo de lista.
    POST: Devuelve el puntero al nodo anterior del apuntado, o devuelve finColor() si
    ptrNodo apuntaba al primero o si lista esta vacia.
    ATRIBUTOS: ListaColor, PtrNodoListaColor.
    RETORNO: Puntero al nodo anterior.
*/
PtrNodoListaColor anterior(ListaColor& lista, PtrNodoListaColor ptrNodo);

/*
    PRE: El color debe ser creado con el TDA Color.
    POST: Retorna ptrNodoListaColor.
    ATRIBUTOS: Color.
    RETORNO: PtrNodoListaColor.
*/
PtrNodoListaColor crearNodoListaColor(Color color);

/*
    PRE: Lista creada con crearListaColor().
    POST: Al principio de la lista se adiciona el color.
    ATRIBUTOS: ListaColor, Color.
    RETORNO: PtrNodoListaColor.
*/
PtrNodoListaColor adicionarPrimero(ListaColor& lista, Color color);

/*
    PRE: Lista creada con crearListaColor().
    POST: Agrega un nodo despues del apuntado por ptrNodo con el dato
    proporcionado y devuelve un puntero apuntado al elemento insertado.
    Si la lista esta vacía agrega un nodo al principio de esta y devuelve
    un puntero al nodo insertado. Si ptrNodo apunta a finColor() no inserta
    nada y devuelve finColor().
    ATRIBUTOS: ListaColor,Color, PtrNodoListaColor.
    RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaColor adicionarDespues(ListaColor& lista, Color color, PtrNodoListaColor ptrNodo);

/*
    PRE: Lista creada con crearListaColor().
    POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero al nodo insertado.
    ATRIBUTOS: ListaColor, Color.
    RETORNO: Puntero al nodo adicionado.
*/
PtrNodoListaColor adicionarFinal(ListaColor& lista, Color color);

/*
    PRE: Lista fue creada con crearListaColor().
    POST: Imprime la lista de Color.
    ATRIBUTOS: ListaColor.
    RETORNO: No aplica.
*/
void imprimirListaColor(ListaColor lst);

/*
    PRE: Lista fue creada con crearListaColor().
    POST: Inserta el color en la lista de Color general.
    ATRIBUTOS: ListaColor,Figura.
    RETORNO: No aplica.
*/
void insertarFiguraEnListaDeColor(ListaColor& listaColor, Figura figura);

/*
    PRE: Lista fue creada con crearListaColor().
    POST: Se obtiene la cantidad de plastico utilizado por figura y Color.
    ATRIBUTOS: ListaColor.
    RETORNO: No aplica.
*/
void obtenerPlasticoUtilizadoPorFiguraColor(ListaColor listaColor);

/*
    PRE: Lista fue creada con crearListaColor().
    POST: Elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
    esta vacia o si ptrNodo apunta a finLista().
    ATRIBUTOS: ListaColor, PtrNodoListaColor.
    RETORNO: No aplica.
*/
void eliminarNodoListaColor(ListaColor& lista, PtrNodoListaColor ptrNodo);

/*
    PRE: Lista fue creada con crearListaColor().
    POST: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
    ATRIBUTOS: ListaColor.
    RETORNO: No aplica.
*/
void eliminarLista(ListaColor& lista);

#endif