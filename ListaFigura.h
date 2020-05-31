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

CompararAreaFigura resultadoComparacion(Figura figura1, Figura figura2);

void crearListaFigura(ListaFigura& lista);

bool listaVacia(ListaFigura& lista);

PtrNodoListaFigura finLista();

PtrNodoListaFigura primero(ListaFigura& lista);

PtrNodoListaFigura siguiente(ListaFigura& lista, PtrNodoListaFigura ptrSig);

PtrNodoListaFigura crearNodo(Figura figura);

PtrNodoListaFigura adicionarDespues(ListaFigura& lista, Figura figura, PtrNodoListaFigura ptr);

PtrNodoListaFigura adicionarFinal(ListaFigura lista, Figura figura);

PtrNodoListaFigura adicionarPrimero(ListaFigura& lista, Figura figura);

PtrNodoListaFigura anterior(ListaFigura& lista, PtrNodoListaFigura ptroNodo);

PtrNodoListaFigura ultimo(ListaFigura& lista);

void obtenerDato(ListaFigura& lista, Figura& figura, PtrNodoListaFigura ptrNodo);

PtrNodoListaFigura localizarDato(ListaFigura& lista, Figura figura);

void eliminarNodoListaFigura(ListaFigura& lista, PtrNodoListaFigura ptrNodo);

void eliminarLista(ListaFigura& lista);

void imprimirLista(ListaFigura& lista);

float obtenerPlasticoUtilizado(ListaFigura& lista);

void obtenerPlasticoUtilizadoPorFigura(ListaFigura& listaFigura);

//Inserta la figura en la lista de figuras general
void insertarFiguraEnListaDeFiguras(ListaFigura& listaFigura, Figura figura);

#endif