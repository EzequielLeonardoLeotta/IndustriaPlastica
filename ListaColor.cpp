#include "ListaColor.h"

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

PtrNodoListaColor adicionarPrincipio(ListaColor& lista, Color color)
{
	PtrNodoListaColor ptrNuevoNodo = crearNodoListaColor(color);

	/* lo incorpora al principio de la lista */
	ptrNuevoNodo->sgte = lista.primero;
	lista.primero = ptrNuevoNodo;

	return ptrNuevoNodo;
}

PtrNodoListaColor adicionarDespues(ListaColor& lista, Color colo, PtrNodoListaColor ptrNodo)
{
	PtrNodoListaColor ptrNuevoNodo = finColor();

	/* si la lista esta vacia se adiciona la principio */
	if (listaVacia(lista)) {
		ptrNuevoNodo = adicionarPrincipio(lista, colo);
	}
	else {
		if (ptrNodo != finColor()) {

			/* crea el nodo y lo intercala en la lista */
			ptrNuevoNodo = crearNodoListaColor(colo);

			ptrNuevoNodo->sgte = ptrNodo->sgte;
			ptrNodo->sgte = ptrNuevoNodo;
		}
	}

	return ptrNuevoNodo;
}