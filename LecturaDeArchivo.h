#ifndef __LECTURADEARCHIVO_H__
#define __LECTURADEARCHIVO_H__
#include<string>
#include<queue>
#include <fstream> 
using namespace std;

//Lee el archivo y retorna una cola que contiene una linea por cada posicion
queue<string> leerArchivo(string nombreArchivo);

#endif