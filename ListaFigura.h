#include "Figura.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LISTAFIGURA_H_
#define LISTAFIGURA_H_
/* tipo enumerado para realizar comparaciones */
enum CompararAreaFigura {
    MAYORAREA,
    IGUALAREA,
    MENORAREA,

};
/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaFigura {
    Figura figu; // dato almacenado
    NodoListaFigura* sgte; // puntero al siguiente
};

/* Tipo de Puntero a los Nodos de la Lista, el cual se usa para recorrer
   la Lista y acceder a sus Datos. */
typedef NodoListaFigura* PtrNodoListaFigura;


/* Tipo de Estructura de la Lista */
struct ListaFigura {
    PtrNodoListaFigura primero;      // puntero al primer nodo de la lista
};

CompararAreaFigura resultadoComparacion(Figura figu1, Figura figu2);

void crearListaFigura(ListaFigura& lista);

bool listaVacia(ListaFigura& lista);

PtrNodoListaFigura finLista();

PtrNodoListaFigura primero(ListaFigura& lista);

PtrNodoListaFigura siguiente(ListaFigura& lista, PtrNodoListaFigura ptrSig);

PtrNodoListaFigura crearNodo(Figura figura);

PtrNodoListaFigura adicionarDespues(ListaFigura& lista, Figura figu, PtrNodoListaFigura ptr);

PtrNodoListaFigura AdicionarFinal(ListaFigura lista, Figura figu);

PtrNodoListaFigura adicionarPrimero(ListaFigura& lista, Figura figu);

PtrNodoListaFigura anterior(ListaFigura& lista, PtrNodoListaFigura ptroNodo);

PtrNodoListaFigura ultimo(ListaFigura& lista);

void obtenerDato(ListaFigura& lista, Figura& Figu, PtrNodoListaFigura ptrNodo);

PtrNodoListaFigura localizarDato(ListaFigura& lista, Figura figu);

#endif#
