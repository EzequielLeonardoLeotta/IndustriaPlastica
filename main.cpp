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

int main()
{
	int opcion = 0;
	string nombreArchivo = "";

	limpiarConsola();
	cin.clear();

	cout <<
		"*************   Industria Plastica   ************" << "\n\n" <<
		"Ingrese nombre de archivo: ";

	cin >> nombreArchivo;
	limpiarConsola();
	queue<string> contenidoArchivo = leerArchivo(nombreArchivo);
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
			"5:Orden de Produccion de Figuras" << "\n" <<
			"6:Orden de Figuras Segun sus Areas" << "\n" <<
			"0:Salir" << "\n\n" <<
			"Ingrese una opcion: ";

		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "Listado de Figuras" << "\n" << endl;
			imprimirLista(listaFigura);
			pausarConsola();
			break;
		case 2:
			cout << "Plastico Utilizado" << "\n" << endl;
			cout << "El total de plastico utilizado en el lote es de " << obtenerPlasticoUtilizado(listaFigura) << " cm." << "\n" << endl;
			pausarConsola();
			break;
		case 3:
			//cout << "Area = " << area(radio) << endl;
			//pausarConsola();
			break;
		case 4:
			//cleanConsoleMain();
			//cout << "Ingrese angulo: " << endl;
			//cin >> angulo;
			//cout << "Longitud del arco = " << longitudDelArco(radio, angulo) << endl;
			//pausarConsola();
			break;
		case 0: exit(EXIT_FAILURE);
		default:
			//cleanConsoleMain();
			cout << "Opcion no valida.\n";
			break;
		}
	} while (opcion != 0);
	return 0;
}