#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<queue>
using namespace std;


#ifndef __LECTURADEARCHIVO_H__
#define __LECTURADEARCHIVO_H__

//Lee el archivo y retorna una cola que contiene una linea por cada posicion
queue<string> leerArchivo(string nombreArchivo);

#endif