#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <string>
#include "Figura.h"
using namespace std;

#ifndef __IndustriaPlastica_H__
#define __IndustriaPlastica_H__

//Funcion que switchea el calculo dependiendo de la figura que recibe como parametro
float calcularArea(Figura figura);

void insertarFigura(queue<string> contenidoArchivo);

#endif