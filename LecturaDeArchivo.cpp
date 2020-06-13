#include "LecturaDeArchivo.h"

queue<string> leerArchivo(string nombreArchivo) 
{
	queue<string> contenidoArchivo; //resultado

	ifstream archivo (nombreArchivo); //apertura de archivo
	string linea; //linea a leer
	while (getline(archivo, linea))
	{
		contenidoArchivo.push(linea); //insercion de la linea en la cola
	}

	return contenidoArchivo;
}