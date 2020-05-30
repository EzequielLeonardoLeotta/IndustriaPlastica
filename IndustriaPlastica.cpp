#include "LecturaDeArchivo.h"
#include "Areas.h"
#include "Figura.h"
#include "ListaFigura.h"
#include <iostream>
#include<string>
#include <iomanip>
#include "IndustriaPlastica.h"
#include "ListaColor.h"
using namespace std;

string linea = "";
size_t posicion = 0;
string delimitador = " ";
string valor = "";
string valores[4];
int iterador = 0;


ListaFigura listaFigura;
ListaColor listaColor;
Color colorAux;
Figura figura;
TipoFigura tipoFigura;
string color = "";
float area = 0;
float parametro1 = 0;
float parametro2 = 0;
size_t posicionComa = 0;
size_t posicionPuntoYComa = 0;

void pausarConsola() { system("pause"); }
void limpiarConsola() { system("cls"); }

ListaFigura insertarFiguras(queue<string> contenidoArchivo)
{
	ListaFigura listaFigura;
	crearListaFigura(listaFigura); 
	crearListaColor(listaColor);

	while(!contenidoArchivo.empty()) //mientras la cola tenga datos la recorro
	{
		insertarDatosEnArray(contenidoArchivo);

		reemplazoPorPuntos();

		insertarDatosEnVariables();

		//construyo la figura, calculo su area y la inserto en la lista segun su color y al final en la lista general
		constructor(figura, tipoFigura, color, area, parametro1, parametro2);
		setArea(figura, calcularArea(figura));
		insertarFiguraEnListaDeColor(listaColor, figura);
		insertarFiguraEnListaDeFiguras(listaFigura, figura);
		
		//vacio el array y pongo el iterador en 0
		iterador = 0;
		valores[0] = "";
		valores[1] = "";
		valores[2] = "";
		valores[3] = "";
		contenidoArchivo.pop(); // elimino el valor
	}
	//Esto se usa solo para probar
	//recorrerLista(listaFigura); 
	return listaFigura;
}

void insertarDatosEnArray(queue<string> contenidoArchivo)
{
	linea = contenidoArchivo.front() + " "; //tomo el valor que esta al frente

	while ((posicion = linea.find(delimitador)) != string::npos) { //recorro hasta que llego al valor del delimitador
		valor = linea.substr(0, posicion);
		linea.erase(0, posicion + delimitador.length());
		valores[iterador] = valor; //inserto cada valor en un array
		iterador++;
	}
}

void reemplazoPorPuntos()
{
	posicionComa = valores[2].find(",");
	posicionPuntoYComa = valores[2].find(";");

	if (posicionComa < 10 && posicionPuntoYComa < 10) //si tiene coma y punto y coma
	{
		valores[2].replace(posicionComa, 1, ".");
		valores[2].replace(posicionPuntoYComa, 1, "");
	}
	else if (posicionComa < 10) //si tiene coma
		valores[2].replace(posicionComa, 1, ".");
	else if (posicionPuntoYComa < 10) //si tiene punto y coma
		valores[2].replace(posicionPuntoYComa, 1, "");

	posicionComa = valores[3].find(",");

	if (valores[3] != "" && posicionComa < 10)
		valores[3].replace(posicionComa, 1, ".");
}

void insertarDatosEnVariables()
{
	//primero obtengo el tipo de figura
	if (valores[0] == "circulo")
		tipoFigura = TipoFigura::Circulo;
	if (valores[0] == "cilindro")
		tipoFigura = TipoFigura::Cilindro;
	if (valores[0] == "cubo")
		tipoFigura = TipoFigura::Cubo;
	if (valores[0] == "triangulo")
		tipoFigura = TipoFigura::Triangulo;
	if (valores[0] == "rectangulo")
		tipoFigura = TipoFigura::Rectangulo;

	//convierto los atributos restantes a su tipo correspondiente
	color = valores[1];
	parametro1 = stof(valores[2]);
	parametro2 = !valores[3].empty() ? stof(valores[3]) : 0;
}

float calcularArea(Figura figura)
{
	float area = 0;

	if (figura.tipoFigura == TipoFigura::Circulo)
		area = areaCirculo(figura.parametro1);
	if (figura.tipoFigura == TipoFigura::Cilindro)
		area = areaCilindro(figura.parametro1, figura.parametro2);
	if (figura.tipoFigura == TipoFigura::Cubo)
		area = areaCubo(figura.parametro1);
	if (figura.tipoFigura == TipoFigura::Triangulo)
		area = areaTriangulo(figura.parametro1, figura.parametro2);
	if (figura.tipoFigura == TipoFigura::Rectangulo)
		area = areaRectangulo(figura.parametro1, figura.parametro2);

	return area;
}