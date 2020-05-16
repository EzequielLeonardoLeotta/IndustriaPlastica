#include "LecturaDeArchivo.h"
#include "Areas.h"
#include "Listas.h"
#include "Figura.h"
#include "ListaFigura.h"
#include <iostream>
#include<string>
#include <iomanip>
using namespace std;

void pausarConsola() { system("pause"); }
void limpiarConsola() { system("cls"); }

float calcularArea(Figura figura)
{
	return 1;
}

void insertarFigura(queue<string> contenidoArchivo)
{
	string linea = "";
	size_t posicion = 0;
	string delimitador = " ";
	string valor = "";
	string valores[4];
	int iterador = 0;

	ListaFigura listaFigura;
	Figura figura;
	TipoFigura tipoFigura;
	string color = "";
	float area = 0;
	float parametro1 = 0;
	float parametro2 = 0;
	size_t posicionComa = 0;
	size_t posicionPuntoYComa = 0;

	crearListaFigura(listaFigura); 

	while(!contenidoArchivo.empty()) //mientras la cola tenga datos la recorro
	{
		linea = contenidoArchivo.front() + " "; //tomo el valor que esta al frente
		
		while ((posicion = linea.find(delimitador)) != string::npos) { //recorro hasta que llego al valor del delimitador
			valor = linea.substr(0, posicion);
			linea.erase(0, posicion + delimitador.length());
			valores[iterador] = valor; //inserto cada valor en un array
			iterador++;
		}

		//reemplazo las , por .
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

		//paso los datos del array con sus nombres
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
		area = calcularArea(figura);

		//construyo la figura
		constructor(figura, tipoFigura, color, area, parametro1, parametro2);
		listaVacia(listaFigura) ? adicionarPrimero(listaFigura, figura) : adicionarFinal(listaFigura, figura);

		//vacio el array y pongo el iterador en 0
		iterador = 0;
		valores[0] = "";
		valores[1] = "";
		valores[2] = "";
		valores[3] = "";

		contenidoArchivo.pop(); // elimino el valor
	}
	//recorrerLista(listaFigura);
}

int main()
{   
	int opcion = 0;
	string nombreArchivo="";

	limpiarConsola();
	cin.clear();

	cout <<
		"*************   Industria Plastica   ************" << "\n\n" <<
		"Ingrese nombre de archivo: "
		<< endl;

	cin >> nombreArchivo;
	limpiarConsola();
	queue<string> contenidoArchivo = leerArchivo(nombreArchivo);
	insertarFigura(contenidoArchivo);

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
			"Ingrese una opcion: "
		<< endl;

		cin >> opcion;
		
		/*switch (opcion)
		{
		case 1:
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
			break;
		}*/
	} while (opcion != 0);
	return 0;
}