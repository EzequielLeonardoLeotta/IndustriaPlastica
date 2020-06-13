#include "LecturaDeArchivo.h"
#include "IndustriaPlastica.h"

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
			imprimirLista(listaFigura, false);
			pausarConsola();
			limpiarConsola();
			break;
		case 2:
			cout << "\n" << "Plastico Utilizado" << "\n" << endl;
			imprimirLista(listaFigura, true);
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
			break;
		case 6:
			cout << "\n" << "Orden de Figuras por Area de Mayor a Menor" << "\n" << endl;
			obtenerListaOrdenada(listaFigura);
			pausarConsola();
			limpiarConsola();
			break;
		case 0: 
			eliminarLista(listaFigura);
			eliminarLista(listaColor);
			exit(EXIT_FAILURE);
			break;
		default:
			limpiarConsola();
			cout << "Opcion no valida.\n";
			break;
		}
	} while (opcion != 0);
	return 0;
}