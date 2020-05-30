#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include "LecturaDeArchivo.h"
#include <fstream> 
using namespace std;

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