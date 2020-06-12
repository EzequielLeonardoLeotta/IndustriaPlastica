#include "ListaFigura.h"
#include "Figura.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

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
	if ((!listaVacia(lista)) && (ptrSig != finLista()))
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

	/* verifica que la lista no est� vacia y que nodo no sea finListaFigura*/
	if ((!listaVacia(lista)) && (ptrNodo != finLista())) {

		if (ptrNodo == primero(lista))
		{
			lista.primero = siguiente(lista, primero(lista));
		}
		else 
		{
			ptrPrevio = anterior(lista, ptrNodo);
			ptrPrevio->sgte = ptrNodo->sgte;
		}

		delete ptrNodo;
	}
}

void eliminarLista(ListaFigura& lista)
{
	/* retira uno a uno los nodos de la lista */
	while (!listaVacia(lista))
		eliminarNodoListaFigura(lista, primero(lista));
}

void imprimirLista(ListaFigura& lista, bool mostrarAreaTotal)
{
	PtrNodoListaFigura cursor;
	cursor = primero(lista);
	Figura auxFigura;
	float areaTotal = 0;

	while (cursor != finLista()) {
		obtenerDato(lista, auxFigura, cursor);
		areaTotal += getArea(auxFigura);
		imprimirDetalleFigura(auxFigura);

		cursor = siguiente(lista, cursor);
	}
	if (mostrarAreaTotal)
		cout << "\n" << "El total de plastico utilizado en el lote es de " << areaTotal << " cm." << "\n" << endl;
}

void imprimirDetalleFigura(Figura figura)
{
	switch (getTipoFigura(figura))
	{
	case TipoFigura::Circulo:
		cout << "Tipo: circulo" << endl;
		cout << "Radio: " << getParametro1(figura) << " cm." << endl;
		break;
	case TipoFigura::Cilindro:
		cout << "Tipo: cilindro" << endl;
		cout << "Radio: " << getParametro1(figura) << " cm." << endl;
		cout << "Altura: " << getParametro2(figura) << " cm." << endl;
		break;
	case TipoFigura::Cubo:
		cout << "Tipo: cubo" << endl;
		cout << "Lado: " << getParametro1(figura) << " cm." << endl;
		break;
	case TipoFigura::Triangulo:
		cout << "Tipo: triangulo " << endl;
		cout << "Cateto mayor: " << getParametro1(figura) << " cm." << endl;
		cout << "Cateto menor: " << getParametro2(figura) << " cm." << endl;
		break;
	case TipoFigura::Rectangulo:
		cout << "Tipo: rectangulo" << endl;
		cout << "Base: " << getParametro1(figura) << " cm." << endl;
		cout << "Altura: " << getParametro2(figura) << " cm." << endl;
		break;
	}

	cout << "Color: " << getColor(figura) << endl;
	cout << "Plastico utilizado: " << getArea(figura) << " cm." << "\n" << endl;
}

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

void obtenerPlasticoUtilizadoPorFigura(ListaFigura& listaFigura)
{
	PtrNodoListaFigura cursor;
	cursor = primero(listaFigura);
	Figura auxFigura;
	float areaTotalCirculo = 0;
	float areaTotalCilindro = 0;
	float areaTotalCubo = 0;
	float areaTotalTriangulo = 0;
	float areaTotalRectangulo = 0;
	TipoFigura tipoFigura;
	ListaFigura listaCirculo;
	ListaFigura listaCilindro;
	ListaFigura listaCubo;
	ListaFigura listaTriangulo;
	ListaFigura listaRectangulo;
	crearListaFigura(listaCirculo);
	crearListaFigura(listaCilindro);
	crearListaFigura(listaCubo);
	crearListaFigura(listaTriangulo);
	crearListaFigura(listaRectangulo);

	while (cursor != finLista()) {
		obtenerDato(listaFigura, auxFigura, cursor);
		tipoFigura = getTipoFigura(auxFigura);

		switch (getTipoFigura(auxFigura))
		{
		case TipoFigura::Circulo:
			areaTotalCirculo += getArea(auxFigura);
			listaVacia(listaCirculo) ? adicionarPrimero(listaCirculo, auxFigura) : adicionarFinal(listaCirculo, auxFigura);
			break;
		case TipoFigura::Cilindro:
			areaTotalCilindro += getArea(auxFigura);
			listaVacia(listaCilindro) ? adicionarPrimero(listaCilindro, auxFigura) : adicionarFinal(listaCilindro, auxFigura);
			break;
		case TipoFigura::Cubo:
			areaTotalCubo += getArea(auxFigura);
			listaVacia(listaCubo) ? adicionarPrimero(listaCubo, auxFigura) : adicionarFinal(listaCubo, auxFigura);
			break;
		case TipoFigura::Triangulo:
			areaTotalTriangulo += getArea(auxFigura);
			listaVacia(listaTriangulo) ? adicionarPrimero(listaTriangulo, auxFigura) : adicionarFinal(listaTriangulo, auxFigura);
			break;
		case TipoFigura::Rectangulo:
			areaTotalRectangulo += getArea(auxFigura);
			listaVacia(listaRectangulo) ? adicionarPrimero(listaRectangulo, auxFigura) : adicionarFinal(listaRectangulo, auxFigura);
			break;
		}

		cursor = siguiente(listaFigura, cursor);
	}

	cout << "\n" << "Circulo: " << "\n" << endl;
	imprimirLista(listaCirculo, false);
	cout << "\n" << "Plastico Utilizado para Circulo: " << areaTotalCirculo << " cm." << "\n" << endl;
	eliminarLista(listaCirculo);

	cout << "\n" << "Cilindro: " << "\n" << endl;
	imprimirLista(listaCilindro, false);
	cout << "Plastico Utilizado para Cilindro: " << areaTotalCilindro << " cm." << "\n" << endl;
	eliminarLista(listaCirculo);

	cout << "\n" << "Cubo: " << "\n" << endl;
	imprimirLista(listaCubo, false);
	cout << "Plastico Utilizado para Cubo: " << areaTotalCubo << " cm." << "\n" << endl;
	eliminarLista(listaCubo);

	cout << "\n" << "Triangulo: " << "\n" << endl;
	imprimirLista(listaTriangulo, false);
	cout << "Plastico Utilizado para Triangulo: " << areaTotalTriangulo << " cm." << "\n" << endl;
	eliminarLista(listaTriangulo);

	cout << "\n" << "Rectangulo: " << "\n" << endl;
	imprimirLista(listaRectangulo, false);
	cout << "Plastico Utilizado para Rectangulo: " << areaTotalRectangulo << " cm." << "\n" << endl;
	eliminarLista(listaRectangulo);
};

void obtenerListaOrdenada(ListaFigura& lista)
{
	PtrNodoListaFigura cursor;
	PtrNodoListaFigura cursorsgte;
	Figura auxi1;
	Figura auxi2;
	bool ordenado = false;

	while (ordenado != true) {

		ordenado = true;
		cursor = primero(lista);
		cursorsgte = siguiente(lista, cursor);

		while (cursor != finLista())
		{
			obtenerDato(lista, auxi1, cursor);
			obtenerDato(lista, auxi2, cursorsgte);
			if (getArea(auxi1) < getArea(auxi2))
			{
				colocarFigura(lista, auxi1, cursorsgte);
				colocarFigura(lista, auxi2, cursor);
				ordenado = false;
				cursor = primero(lista);
				cursorsgte = siguiente(lista, cursor);
			}
			else
			{
				cursor = siguiente(lista, cursor);
				cursorsgte = siguiente(lista, cursor);
			}
		}
	}
	imprimirLista(lista, false);
}

void colocarFigura(ListaFigura& lista, Figura& figura, PtrNodoListaFigura ptrNodo)
{
	if ((!listaVacia(lista)) && (ptrNodo != finLista()))
		ptrNodo->figura = figura;
};