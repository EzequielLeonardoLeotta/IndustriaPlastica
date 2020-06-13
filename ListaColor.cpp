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


void eliminarNodoListaColor(ListaColor& lista, PtrNodoListaColor ptrNodo)
{
	PtrNodoListaColor ptrPrevio;

	/* verifica que la lista no esté vacia y que nodo no sea finListaColor*/
	if ((!listaVacia(lista)) && (ptrNodo != finColor())) {

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

void eliminarLista(ListaColor& lista)
{
	/* retira uno a uno los nodos de la lista */
	while (!listaVacia(lista))
		eliminarNodoListaColor(lista, primero(lista));
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

int LongitudListaColor(ListaColor& lista)
{
	PtrNodoListaColor ptrCursor = primero(lista);
	int longitud = 0;
	while (ptrCursor != finColor()) {
		longitud++;
		ptrCursor = siguiente(lista, ptrCursor);
	}
	return longitud;
}

void insertarFiguraEnListaDeColor(ListaColor& listaColor, Figura figura)
{
	bool existe = false;
	PtrNodoListaColor cursor;
	cursor = primero(listaColor);
	Color color;
	int longitudLista = LongitudListaColor(listaColor);

	// cout << longitudLista << endl;

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

	if (!existe && longitudLista < 10)
	{
		constructor(color, figura);
		listaVacia(listaColor) ? adicionarPrimero(listaColor, color) : adicionarFinal(listaColor, color);
	}
	else if (longitudLista == 10) {

		cout << "La figura ";

		switch (getTipoFigura(figura))
		{
		case Circulo:
			cout << "de tipo circulo ";
			cout << "con radio " << getParametro1(figura) << " cm. ";
			break;
		case Cilindro:
			cout << "de tipo cilindro ";
			cout << "con radio " << getParametro1(figura) << " cm. ";
			cout << "altura " << getParametro2(figura) << " cm. ";
			break;
		case Cubo:
			cout << "de tipo cubo ";
			cout << "lado " << getParametro1(figura) << " cm. ";
			break;
		case Triangulo:
			cout << "de tipo triangulo ";
			cout << "cateto mayor " << getParametro1(figura) << " cm. ";
			cout << "cateto menor " << getParametro2(figura) << " cm. ";
			break;
		case Rectangulo:
			cout << "de tipo rectangulo ";
			cout << "base " << getParametro1(figura) << " cm. ";
			cout << "altura " << getParametro2(figura) << " cm. ";
			break;
		}

		cout << "y color " << getColor(figura) << " no sera procesada, se llego al limite de 10 colores en el lote.\n" << endl;
	}
};

void imprimirListaColor(ListaColor listaColor)
{
	PtrNodoListaColor cursor;
	cursor = primero(listaColor);
	Color color;
	ListaFigura listaFigura;
	crearListaFigura(listaFigura);
	cout << "---------------------------------------------" << endl;

	while (cursor != finColor()) {
		obtenerDatoLcolor(listaColor, color, cursor);
		cout << "\n" << "Figuras de Color : " << getDescripcion(color) << "\n" << endl;
		listaFigura = getListaFigura(color);
		imprimirLista(listaFigura, false);
		cout << "---------------------------------------------" << endl;
		cursor = siguiente(listaColor, cursor);
	}
}

void obtenerPlasticoUtilizadoPorFiguraColor(ListaColor listaColor)
{
	PtrNodoListaColor cursorColor;
	cursorColor = primero(listaColor);
	Color color;
	ListaFigura listaFigura;
	crearListaFigura(listaFigura);
	PtrNodoListaFigura cursorFigura;
	Figura auxFigura;
	TipoFigura tipoFigura;
	float areaTotalCirculo = 0;
	float areaTotalCilindro = 0;
	float areaTotalCubo = 0;
	float areaTotalTriangulo = 0;
	float areaTotalRectangulo = 0;

	while (cursorColor != finColor()) {
		obtenerDatoLcolor(listaColor, color, cursorColor);
		cout << "\n" << "Figuras de Color : " << getDescripcion(color) << "\n" << endl;
		listaFigura = getListaFigura(color);
		cursorFigura = primero(listaFigura);
		
		while (cursorFigura != finLista()) {
			obtenerDato(listaFigura, auxFigura, cursorFigura);
			tipoFigura = getTipoFigura(auxFigura);

			switch (getTipoFigura(auxFigura))
			{
			case Circulo:
				areaTotalCirculo += getArea(auxFigura);
				break;
			case Cilindro:
				areaTotalCilindro += getArea(auxFigura);
				break;
			case Cubo:
				areaTotalCubo += getArea(auxFigura);
				break;
			case Triangulo:
				areaTotalTriangulo += getArea(auxFigura);
				break;
			case Rectangulo:
				areaTotalRectangulo += getArea(auxFigura);
				break;
			}

			imprimirDetalleFigura(auxFigura);

			cursorFigura = siguiente(listaFigura, cursorFigura);
		}

		if(areaTotalCirculo!=0)
		cout << "\n" << "Plastico Utilizado para Circulo: " << areaTotalCirculo << " cm." << "\n" << endl;
		if (areaTotalCilindro != 0)
		cout << "Plastico Utilizado para Cilindro: " << areaTotalCilindro << " cm." << "\n" << endl;
		if (areaTotalCubo != 0)
		cout << "Plastico Utilizado para Cubo: " << areaTotalCubo << " cm." << "\n" << endl;
		if(areaTotalTriangulo!=0)
		cout << "Plastico Utilizado para Triangulo: " << areaTotalTriangulo << " cm." << "\n" << endl;
		if(areaTotalRectangulo!=0)
		cout << "Plastico Utilizado para Rectangulo: " << areaTotalRectangulo << " cm." << "\n" << endl;
		cout << "---------------------------------------------" << endl;

		areaTotalCirculo = 0;
		areaTotalCilindro = 0;
		areaTotalCubo = 0;
		areaTotalTriangulo = 0;
		areaTotalRectangulo = 0;

		cursorColor = siguiente(listaColor, cursorColor);
	}
};