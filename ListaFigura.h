#include "Figura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TDA ListaFigura
 * Implementación Simplemente Enlazada
 * Archivo : ListaFigura.h
 * Versión : 1.1
 */

#ifndef LISTAFIGURA_H_
#define LISTAFIGURA_H_

/* tipo enumerado para realizar comparaciones */

enum CompararAreaFigura {
    MAYORAREA,
    IGUALAREA,
    MENORAREA
};

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaFigura {
    Figura figura; // dato almacenado
    NodoListaFigura* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus Datos. */
typedef NodoListaFigura* PtrNodoListaFigura;


/* Tipo de Estructura de la Lista */
struct ListaFigura {
    PtrNodoListaFigura primero;      // puntero al primer nodo de la lista
};


/******************************************************************************/
/* Definicion de Primitivas */

/*----------------------------------------------------------------------------*/

/*
    PRE: La lista no debe haber sido creada.
    POST: ListaFigura queda creada y preparada para ser usada.
    ATRIBUTOS: ListaFigura.
    RETORNO: No aplica.
*/

void crearListaFigura(ListaFigura& lista);

/*
    PRE: Lista Creada con crearListaFigura().
    POST: Devuelve true si lista esta vacia, sino devuelve false.
    ATRIBUTOS: ListaFigura.
    RETORNO: true o false.
*/

bool listaVacia(ListaFigura& lista);

/*
    PRE: Lista Creada con crearListaFigura().
    POST: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
    o sea el valor Null, que en esta implementacion representa el final de la ListaFigura.
    ATRIBUTOS: No aplica.
    RETORNO: PtrNodoListaFigura.
*/

PtrNodoListaFigura finLista();

/*
    PRE: Lista Creada con crearListaFigura().
    POST: Devuelve el puntero al primer elemento de la lista, o devuelve finLista() si esta vacia.
    ATRIBUTOS: ListaFigura.
    RETORNO: Puntero al primer nodo.
*/

PtrNodoListaFigura primero(ListaFigura& lista);

/*
    PRE: Lista Creada con crearListaFigura().
    POST: Devuelve el puntero al nodo proximo del apuntado, o devuelve finLista()
    si ptrNodo apuntaba a finLista() o si lista esta vacia.
    ATRIBUTOS: ListaFigura, ptrNodoListaFigura.
    RETORNO: Puntero al nodo siguiente.
*/

PtrNodoListaFigura siguiente(ListaFigura& lista, PtrNodoListaFigura ptrSig);

/*
    PRE: La figura debe ser creada con el TDA Figura.
    POST: Retorna ptrNodoListaFigura.
    ATRIBUTOS: Figura.
    RETORNO: PtrNodoListaFigura.
*/

PtrNodoListaFigura crearNodo(Figura figura);

/*
    PRE: Lista creada con crearListaFigura().
    POST: Agrega un nodo despues del apuntado por ptrNodo con el dato
    proporcionado y devuelve un puntero apuntado al elemento insertado.
    Si la lista esta vacía agrega un nodo al principio de esta y devuelve
    un puntero al nodo insertado. Si ptrNodo apunta a finLista() no inserta
    nada y devuelve finLista().
    ATRIBUTOS: ListaFigura,Figura, PtrNodoListaFigura.
    RETORNO: Puntero al nodo adicionado.
*/

PtrNodoListaFigura adicionarDespues(ListaFigura& lista, Figura figura, PtrNodoListaFigura ptr);

/*
    PRE: Lista creada con crearListaFigura().
    POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero al nodo insertado.
    ATRIBUTOS: ListaFigura, Figura.
    RETORNO: Puntero al nodo adicionado.
*/

PtrNodoListaFigura adicionarFinal(ListaFigura lista, Figura figura);

/*
    PRE: Lista creada con crearListaFigura().
    POST: Al principio de la lista se adiciona la figura. 
    ATRIBUTOS: ListaFigura, Figura.
    RETORNO: PtrNodoListaFigura.
*/

PtrNodoListaFigura adicionarPrimero(ListaFigura& lista, Figura figura);

/*
    PRE: Lista creada con crearListaFigura().ptrNodo es un puntero a un nodo de lista.
    POST: Devuelve el puntero al nodo anterior del apuntado, o devuelve finLista() si
    ptrNodo apuntaba al primero o si lista esta vacia.
    ATRIBUTOS: ListaFigura, PtrNodoListaFigura.
    RETORNO: Puntero al nodo anterior.
*/

PtrNodoListaFigura anterior(ListaFigura& lista, PtrNodoListaFigura ptroNodo);

/*
    PRE: Lista creada con crearListaFigura().
    POST: Devuelve el puntero al ultimo nodo de la lista, o devuelve finLista() si lista esta vacia.
    ATRIBUTOS: ListaFigura.
    RETORNO: Puntero al ultimo nodo. 
*/

PtrNodoListaFigura ultimo(ListaFigura& lista);

/*
    PRE: Lista creada con crearListaFigura(), no vacia. ptrNodo es distinto de finLista().
    POST: Devuelve el dato del nodo apuntado por ptrNodo.
    ATRIBUTOS: ListaFigura, Figura, PtrNodoListaFigura.
    RETORNO: Puntero al nodo del cual se quiere obtener el dato.
*/

void obtenerDato(ListaFigura& lista, Figura& figura, PtrNodoListaFigura ptrNodo);

/*
    PRE: Lista fue creada con crearListaFigura().
    POST: Elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
    esta vacia o si ptrNodo apunta a finLista().
    ATRIBUTOS: ListaFigura, PtrNodoListaFigura.
    RETORNO: No aplica.
*/

void eliminarNodoListaFigura(ListaFigura& lista, PtrNodoListaFigura ptrNodo);

/*
    PRE: Lista fue creada con crearListaFigura().
    POST: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
    ATRIBUTOS: ListaFigura.
    RETORNO: No aplica.  
*/

void eliminarLista(ListaFigura& lista);

/*
    PRE: Lista fue creada con crearListaFigura().
    POST: Imprime la lista de Figura.
    ATRIBUTOS: ListaFigura, mostrarAreaTotal true o false.
    RETORNO: No aplica.
*/

void imprimirLista(ListaFigura& lista, bool mostrarAreaTotal);

/*
    PRE: Lista fue creada con crearListaFigura().
    POST: Se obtiene la cantidad de plastico utilizado por figura.
    ATRIBUTOS: ListaFigura.
    RETORNO: No aplica.
*/

void obtenerPlasticoUtilizadoPorFigura(ListaFigura& listaFigura);

/*
    PRE: La figura debe ser creada con el TDA Figura. 
    POST: Imprime el detalle de figura. 
    ATRIBUTOS: Figura. 
    RETORNO: No aplica.
*/

void imprimirDetalleFigura(Figura figura);

/*
    PRE: Lista fue creada con crearListaFigura().La figura debe ser creada con el TDA Figura. 
    POST: Inserta la figura en la lista de figuras general. 
    ATRIBUTOS: ListaFigura,Figura. 
    RETORNO: No aplica.
*/

void insertarFiguraEnListaDeFiguras(ListaFigura& listaFigura, Figura figura);

/*
    PRE: Lista fue creada con crearListaFigura().La figura debe ser creada con el TDA Figura.
    POST: Si la lista no esta vacia y el ptrNodo no es finLista() se asigna el puntero a la figura. 
    ATRIBUTOS: ListaFigura,Figura, PtrNodoListaFigura.
    RETORNO: No aplica.
*/

void colocarFigura(ListaFigura& lista, Figura& figu, PtrNodoListaFigura ptrNodo);

/*
    PRE: Lista fue creada con crearListaFigura().
    POST: Se obtiene la lista ordenada de figura. 
    ATRIBUTOS: ListaFigura.
    RETORNO: No aplica.
*/

void obtenerListaOrdenada(ListaFigura& lista);

#endif