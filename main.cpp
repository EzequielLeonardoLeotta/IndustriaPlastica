#include "LecturaDeArchivo.h"
#include "Areas.h"
#include "Listas.h"
#include "Figura.h"
#include "ListaFigura.h"
#include <iostream>
#include<string>
#include <iomanip>
#include "IndustriaPlastica.h"
#include "ListaColor.h"
using namespace std;

string nombreArchivo = "";

queue<string> mostrarInicio()
{
	queue<string> contenidoArchivo;
	do
	{
		cin.clear();

		cout <<
			"*************   Industria Plastica   ************" << "\n\n" <<
			"Ingrese nombre de archivo: ";

		cin >> nombreArchivo;
		limpiarConsola();
		contenidoArchivo = leerArchivo(nombreArchivo);
		if (contenidoArchivo.empty())
			cout << "\n" << "No se encuentra el archivo o el mismo esta vacio" << "\n" << endl;
	} while (contenidoArchivo.empty());
		return contenidoArchivo;
}

int main()
{
	int opcion = 0;
	
	queue<string> contenidoArchivo = mostrarInicio();
	ListaFigura listaFigura = insertarFigurasEnListaDeFiguras(contenidoArchivo);
	ListaColor listaColor = insertarFigurasEnListaDeColor(contenidoArchivo);
	

	//menu principal
	do
	{
		cout <<
			"*************   Industria Plastica   ************" << "\n\n" <<
			"1:Mostrar Figuras" << "\n" <<
			"2:Cantidad de Plastico Utilizado" << "\n" <<
			"3:Cantidad de Plastico Utilizado por Figura" << "\n" <<
			"4:Mostrar Total por Figura - Color" << "\n" <<
			"5:Orden de Produccion de Figuras por Color" << "\n" <<
			"6:Orden de Figuras Segun sus Areas" << "\n" <<
			"0:Salir" << "\n\n" <<
			"Ingrese una opcion: ";

		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "\n" << "Listado de Figuras" << "\n" << endl;
			imprimirLista(listaFigura);
			pausarConsola();
			limpiarConsola();
			break;
		case 2:
			cout << "\n" << "Plastico Utilizado" << "\n" << endl;
			cout << "\n" << "El total de plastico utilizado en el lote es de " << obtenerPlasticoUtilizado(listaFigura) << " cm." << "\n" << endl;
			pausarConsola();
			limpiarConsola();
			break;
		case 3:
			cout << "\n" << "Plastico Utilizado por Figura" << "\n" << endl;
			obtenerPlasticoUtilizadoPorFigura(listaFigura);
			pausarConsola();
			limpiarConsola();
			break;
		case 4:
			cout << "\n" << "Plastico Utilizado por Figura - Color" << "\n" << endl;
			obtenerPlasticoUtilizadoPorFiguraColor(listaColor);
			pausarConsola();
			limpiarConsola();
			break;
		case 5:
			cout << "\n" << "Orden de Produccion de Figuras por Color" << "\n" << endl;
			imprimirListaColor(listaColor);
			pausarConsola();
			limpiarConsola();
		case 6:
			pausarConsola();
			limpiarConsola();
		case 0: exit(EXIT_FAILURE);
		default:
			cout << "Opcion no valida.\n";
			break;
		}
	} while (opcion != 0);
	return 0;
}