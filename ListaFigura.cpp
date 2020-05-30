#include "ListaFigura.h"
#include "Figura.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


CompararAreaFigura resultadoComparacion(Figura figu1, Figura figu2)
{
	CompararAreaFigura aux;

	if (getArea(figu1) > getArea(figu2)) {
		aux=MAYORAREA;
	}
	else if (getArea(figu1) < getArea(figu2)) {
		aux=MENORAREA;
	}
	else {
		aux=IGUALAREA;
	}
	return aux;
}


void crearListaFigura(ListaFigura& lista)
{
	lista.primero = finLista();
}

bool listaVacia(ListaFigura& lista)
{
	return primero(lista) == finLista();
}

PtrNodoListaFigura finLista()
{
	return NULL;

}

PtrNodoListaFigura primero(ListaFigura& lista)
{
	return lista.primero;

}

PtrNodoListaFigura siguiente(ListaFigura& lista, PtrNodoListaFigura ptrSig)
{
	PtrNodoListaFigura aux;
	if (!listaVacia(lista) && !finLista())
		aux = ptrSig->sgte;
	else
		aux = finLista();
	return aux;

}

PtrNodoListaFigura crearNodo(Figura figura)
{
	PtrNodoListaFigura aux = new NodoListaFigura;
	aux->figu = figura;
	aux->sgte = finLista();
	return aux;
}

PtrNodoListaFigura adicionarDespues(ListaFigura& lista, Figura figu, PtrNodoListaFigura ptr)
{

	PtrNodoListaFigura nvoNodo = finLista();
	if (listaVacia(lista))
		nvoNodo = adicionarPrimero(lista, figu);
	else
	{
		nvoNodo = crearNodo(figu);
		nvoNodo->sgte = ptr->sgte;
		ptr->sgte = nvoNodo;
	}
	return nvoNodo;

}

PtrNodoListaFigura adicionarFinal(ListaFigura lista, Figura figu)
{
	return adicionarDespues(lista, figu, ultimo(lista));
}

PtrNodoListaFigura adicionarPrimero(ListaFigura& lista, Figura figura)
{
	PtrNodoListaFigura aux = crearNodo(figura);
	aux->sgte = lista.primero;
	lista.primero = aux;
	return aux;
}

PtrNodoListaFigura anterior(ListaFigura& lista, PtrNodoListaFigura ptroNodo)
{
	PtrNodoListaFigura ptrPrevio = finLista();
	PtrNodoListaFigura Ptrocursor = primero(lista);
	while (Ptrocursor != finLista() && Ptrocursor != ptroNodo)
	{
		ptrPrevio = Ptrocursor;
		Ptrocursor = siguiente(lista, Ptrocursor);
	}
	return ptrPrevio;

}

PtrNodoListaFigura ultimo(ListaFigura& lista)
{
	return anterior(lista, finLista());

}

void obtenerDato(ListaFigura& lista, Figura& figura, PtrNodoListaFigura ptrNodo)
{
   if ((!listaVacia(lista)) && (ptrNodo != finLista()))
		figura = ptrNodo->figu;
}

void eliminarNodoListaFigura(ListaFigura& lista, PtrNodoListaFigura ptrNodo)
{
	PtrNodoListaFigura ptrPrevio;

	/* verifica que la lista no esté vacia y que nodo no sea finListaFigura*/
	if ((!listaVacia(lista)) && (ptrNodo != finLista())) {

		if (ptrNodo == primero(lista))
			lista.primero = siguiente(lista, primero(lista));

		else {
			ptrPrevio = anterior(lista, ptrNodo);
			ptrPrevio->sgte = ptrNodo->sgte;
		}
		// Si el dato es un TDA, acá habría que llamar al destructor.

		delete ptrNodo;
	}
}

void eliminarLista(ListaFigura& lista){
{
	/* retira uno a uno los nodos de la lista */
	while (!listaVacia(lista))
		eliminarNodoListaFigura(lista, primero(lista));
}

}

void recorrerLista(ListaFigura& lista)
{
	PtrNodoListaFigura cursor;
	cursor = primero(lista);
	Figura auxFigura;
	string tipoFigura = "";
	int tipo = 0;

	while (cursor != finLista()) {
		obtenerDato(lista, auxFigura, cursor);

		tipo = (int)auxFigura.tipoFigura;

		switch (tipo)
		{
			case 0: 
				tipoFigura = "circulo";
				break;
			case 1:
				tipoFigura = "cilindro";
				break;
			case 2:
				tipoFigura = "cubo";
				break;
			case 3:
				tipoFigura = "triangulo";
				break;
			case 4:
				tipoFigura = "rectangulo";
				break;
		}

		cout << tipoFigura << endl;
		cout << getColor(auxFigura) << endl;
		cout << getParametro1(auxFigura) << endl;
		cout << getParametro2(auxFigura) << endl;
		cout << "Area:" << endl;
		cout << getArea(auxFigura) << endl;
		cout << "\n" << endl;

		cursor = siguiente(lista, cursor);
	}
}

/* VER ACA COMO COMPARAMOS 2 FIGURAS, COMO SABEMOS QUE SON IGUALES LA MISMA FIGURA
O DISTINTAS?
PtrNodoListaFigura localizarDato(ListaFigura& lista, Figura figu)
{

}
*/

int Longitud(ListaFigura& lista)
{
	PtrNodoListaFigura ptrCursor = primero(lista);
	int longitud = 0;
	while (ptrCursor != finLista()) {
		longitud++;
		ptrCursor = siguiente(lista, ptrCursor);
	}
	return longitud;
}

void insertarFiguraEnListaDeFiguras(ListaFigura& listaFigura, Figura figura)
{
	listaVacia(listaFigura) ? adicionarPrimero(listaFigura, figura) : adicionarFinal(listaFigura, figura);
}
