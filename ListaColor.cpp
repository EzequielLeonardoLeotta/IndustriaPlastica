﻿#include "ListaColor.h"
#include <iostream>

void crearListaColor(ListaColor& lista)
{
	lista.primero = finColor();
}

bool listaVacia(ListaColor& lista)
{
	return (primero(lista) == finColor());
}

PtrNodoListaColor finColor()
{
	return NULL;
}

PtrNodoListaColor primero(ListaColor& lista)
{
	return lista.primero;
}

PtrNodoListaColor siguiente(ListaColor& lista, PtrNodoListaColor ptrNodo)
{
	if ((!listaVacia(lista)) && (ptrNodo != finColor()))
		return ptrNodo->sgte;
	else
		return finColor();
}

PtrNodoListaColor ultimo(ListaColor& lista)
{
	return anterior(lista, finColor());
}

PtrNodoListaColor adicionarFinal(ListaColor& lista, Color color)
{
	return adicionarDespues(lista, color, ultimo(lista));
}

void obtenerDatoLcolor(ListaColor& lista, Color& color, PtrNodoListaColor ptrNodo)
{
	if ((!listaVacia(lista)) && (ptrNodo != finColor()))
		color = ptrNodo->color;
}

PtrNodoListaColor anterior(ListaColor& lista, PtrNodoListaColor ptrNodo)
{
	PtrNodoListaColor ptrPrevio = finColor();
	PtrNodoListaColor ptrCursor = primero(lista);

	while ((ptrCursor != finColor()) && (ptrCursor != ptrNodo)) {
		ptrPrevio = ptrCursor;
		ptrCursor = siguiente(lista, ptrCursor);
	}
	return ptrPrevio;
}

PtrNodoListaColor crearNodoListaColor(Color color)
{
	PtrNodoListaColor ptrAux = new NodoListaColor;

	ptrAux->color = color;
	ptrAux->sgte = finColor();

	return ptrAux;
}

PtrNodoListaColor adicionarPrimero(ListaColor& lista, Color color)
{
	PtrNodoListaColor ptrNuevoNodo = crearNodoListaColor(color);

	/* lo incorpora al principio de la lista */
	ptrNuevoNodo->sgte = lista.primero;
	lista.primero = ptrNuevoNodo;

	return ptrNuevoNodo;
}

PtrNodoListaColor adicionarDespues(ListaColor& lista, Color color, PtrNodoListaColor ptrNodo)
{
	PtrNodoListaColor ptrNuevoNodo = finColor();

	/* si la lista esta vacia se adiciona la principio */
	if (listaVacia(lista)) {
		ptrNuevoNodo = adicionarPrimero(lista, color);
	}
	else {
		if (ptrNodo != finColor()) {

			/* crea el nodo y lo intercala en la lista */
			ptrNuevoNodo = crearNodoListaColor(color);

			ptrNuevoNodo->sgte = ptrNodo->sgte;
			ptrNodo->sgte = ptrNuevoNodo;
		}
	}

	return ptrNuevoNodo;
}

void imprimirListaColor(ListaColor listaColor)
{
	PtrNodoListaColor cursor;
	cursor = primero(listaColor);
	Color color;
	ListaFigura listaFigura;
	crearListaFigura(listaFigura);

	while (cursor != finColor()) {
		obtenerDatoLcolor(listaColor, color, cursor);
		cout << "\n" << "Figuras de Color : " << getDescripcion(color) << "\n" <<endl;
		listaFigura = getListaFigura(color);
		imprimirLista(listaFigura);
		cursor = siguiente(listaColor, cursor);
	}
}

void insertarFiguraEnListaDeColor(ListaColor& listaColor, Figura figura)
{
	bool existe = false;
	PtrNodoListaColor cursor;
	cursor = primero(listaColor);
	Color color;

	while (cursor != finColor() && !existe) {
		obtenerDatoLcolor(listaColor, color, cursor);
		if (getColor(figura) == getDescripcion(color))
		{
			adicionarFinal(getListaFigura(color), figura);
			existe = true;
		}
		else
			cursor = siguiente(listaColor, cursor);
	}

	if(!existe)
	{
		constructor(color, figura);
		listaVacia(listaColor) ? adicionarPrimero(listaColor, color) : adicionarFinal(listaColor, color);
	}
}