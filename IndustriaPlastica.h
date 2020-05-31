#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include "Figura.h"
using namespace std;

#ifndef __IndustriaPlastica_H__
#define __IndustriaPlastica_H__

//Pausa la consola
void pausarConsola();

//Limpia la consola
void limpiarConsola();

// Obtener la lista figura
ListaFigura getListaFigura();

//Inserta las figuras en la lista (procedimiento general que contiene a los de abajo)
void insertarFiguras(queue<string> contenidoArchivo);

//Inserta los datos de la cola en un array
void insertarDatosEnArray(queue<string> contenidoArchivo);

//Reemplaza las comas y punto y comas por puntos y los inserta en un array
void reemplazoPorPuntos();

//Inserta los datos del array en variables
void insertarDatosEnVariables();

//Funcion que switchea el calculo dependiendo de la figura que recibe como parametro
float calcularArea(Figura figura);

#endif