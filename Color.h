#include <cstring>
#ifndef __COLOR_H__
#define __COLOR_H__
#include "ListaFigura.h"

typedef struct Color {
	string descripcion;
	ListaFigura lstfigura;
};

void constructor(Color& color, string descripcion);
void setDescripcion(Color& color, string descripcion);
void setListaFigura(Color& color, ListaFigura lista);
string getNombre(Color& color);
ListaFigura getLista(Color& color);

#endif