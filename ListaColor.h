#ifndef __LISTACOLOR_H__
#define __LISTACOLOR_H__
#include "ListaFigura.h"
#include "Color.h"
#include <cstring>
#include <string>

struct NodoListaColor {
    Color color;
    NodoListaColor* sgte; // puntero al siguiente
};

typedef NodoListaColor* PtrNodoListaColor;

struct ListaColor {
    PtrNodoListaColor primero;      // puntero al primer nodo de la lista
};

void crearListaColor(ListaColor& lista);
bool listaVacia(ListaColor& lista);
PtrNodoListaColor finColor();
PtrNodoListaColor primero(ListaColor& lista);
PtrNodoListaColor siguiente(ListaColor& lista, PtrNodoListaColor ptrNodo);
PtrNodoListaColor ultimo(ListaColor& lista);
PtrNodoListaColor adicionarFinal(ListaColor& lista, Color color);
void obtenerDatoLcolor(ListaColor& lista, Color& color, PtrNodoListaColor ptrNodo);
PtrNodoListaColor anterior(ListaColor& lista, PtrNodoListaColor ptrNodo);
PtrNodoListaColor crearNodoListaColor(Color color);
PtrNodoListaColor adicionarPrimero(ListaColor& lista, Color color);
PtrNodoListaColor adicionarDespues(ListaColor& lista, Color color, PtrNodoListaColor ptrNodo);
PtrNodoListaColor adicionarFinal(ListaColor& lista, Color color);
void imprimirListaColor(ListaColor lst);
void insertarFiguraEnListaDeColor(ListaColor& listaColor, Figura figura);
void obtenerPlasticoUtilizadoPorFiguraColor(ListaColor listaColor);

#endif