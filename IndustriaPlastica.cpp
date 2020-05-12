#include "LecturaDeArchivo.h"
#include "Areas.h"
#include "Listas.h" //hacer una lista de figuras y n listas de figuras por color
#include <iostream>
#include<string>
#include "Figura.h"
using namespace std;

void pausarConsola() { system("pause"); }
void limpiarConsola() { system("cls"); }

int main()
{
	int opcion = 0;
	string nombreArchivo="";

	//menu principal
	do
	{
		limpiarConsola();
		cin.clear();

		cout <<
			"*************   Industria Plastica   ************" << "\n\n" <<
			"Ingrese nombre de archivo: "
		<< endl;
		
		cin >> nombreArchivo;
		limpiarConsola();
		queue<string> contenidoArchivo = leerArchivo(nombreArchivo);
		
		cout <<
			"*************   Industria Plastica   ************" << "\n\n" <<
			"1:Mostrar Figuras" << "\n" <<
			"2:Cantidad de Plastico Utilizado" << "\n" <<
			"3:Cantidad de Plastico Utilizado por Figura" << "\n" <<
			"4:Mostrar Total por Figura - Color" << "\n" <<
			"5:Orden de Produccion de Figuras" << "\n" <<
			"6:Orden de Figuras Segun sus Areas" << "\n" <<
			"0:Salir" << "\n\n" <<
			"Ingrese una opcion: "
		<< endl;

		cin >> opcion;
		
		switch (opcion)
		{
		/*case 1:
			cout << "Perimetro = " << perimetro(radio) << endl;
			pauseConsole();
			break;
		case 2:
			cout << "Diametro = " << diametro(radio) << endl;
			pauseConsole();
			break;
		case 3:
			cout << "Area = " << area(radio) << endl;
			pauseConsole();
			break;
		case 4:
			cleanConsoleMain();
			cout << "Ingrese angulo: " << endl;
			cin >> angulo;
			cout << "Longitud del arco = " << longitudDelArco(radio, angulo) << endl;
			pauseConsole();
			break;
		case 0: exit(EXIT_FAILURE);
		default:
			cleanConsoleMain();
			cout << "Opcion no valida.\n";
			break;*/
		}
	} while (opcion != 0);

	return 0;
}