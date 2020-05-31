#include "ListaFigura.h"
#include "Figura.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


CompararAreaFigura resultadoComparacion(Figura figura1, Figura figura2)
{
	CompararAreaFigura aux;

	if (getArea(figura1) > getArea(figura2)) {
		aux=MAYORAREA;
	}
	else if (getArea(figura1) < getArea(figura2)) {
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
	aux->figura = figura;
	aux->sgte = finLista();
	return aux;
}

PtrNodoListaFigura adicionarDespues(ListaFigura& lista, Figura figura, PtrNodoListaFigura ptr)
{
	PtrNodoListaFigura nvoNodo = finLista();
	if (listaVacia(lista))
		nvoNodo = adicionarPrimero(lista, figura);
	else
	{
		nvoNodo = crearNodo(figura);
		nvoNodo->sgte = ptr->sgte;
		ptr->sgte = nvoNodo;
	}
	return nvoNodo;
}

PtrNodoListaFigura adicionarFinal(ListaFigura lista, Figura figura)
{
	return adicionarDespues(lista, figura, ultimo(lista));
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
		figura = ptrNodo->figura;
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

void imprimirLista(ListaFigura& lista)
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
				cout << "Tipo: " << tipoFigura << endl;
				cout << "Radio: " << getParametro1(auxFigura) << " cm." << endl;
				break;
			case 1:
				tipoFigura = "cilindro";
				cout << "Tipo: " << tipoFigura << endl;
				cout << "Radio: " << getParametro1(auxFigura) << " cm." << endl;
				cout << "Altura: " << getParametro2(auxFigura) << " cm." << endl;
				break;
			case 2:
				tipoFigura = "cubo";
				cout << "Tipo: " << tipoFigura << endl;
				cout << "Lado: " << getParametro1(auxFigura) << " cm." << endl;
				break;
			case 3:
				tipoFigura = "triangulo";
				cout << "Tipo: " << tipoFigura << endl;
				cout << "Cateto mayor: " << getParametro1(auxFigura) << " cm." << endl;
				cout << "Cateto menor: " << getParametro2(auxFigura) << " cm." << endl;
				break;
			case 4:
				tipoFigura = "rectangulo";
				cout << "Tipo: " << tipoFigura << endl;
				cout << "Base: " << getParametro1(auxFigura) << " cm." << endl;
				cout << "Altura: " << getParametro2(auxFigura) << " cm." << endl;
				break;
		}

		cout << "Color: " << getColor(auxFigura) << endl;
		cout << "Plastico utilizado: " << getArea(auxFigura) << " cm." << endl;
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

int obtenerPlasticoUtilizado(ListaFigura& lista) {
	PtrNodoListaFigura cursor;
	cursor = primero(lista);
	Figura auxFigura;
	int areaTotal = 0;

	while (cursor != finLista()) {
		obtenerDato(lista, auxFigura, cursor);
		areaTotal += getArea(auxFigura);
		cursor = siguiente(lista, cursor);
	}
	return areaTotal;
};

