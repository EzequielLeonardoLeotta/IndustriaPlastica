#include <cstring>
#ifndef __COLOR_H__
#define __COLOR_H__
#include "ListaFigura.h"

typedef struct Color {
	string descripcion;
	ListaFigura lstfigura;
};

void constructor(Color& color, Figura figura);
void setDescripcion(Color& color, string descripcion);
void setListaFigura(Color& color, ListaFigura lista);
string getDescripcion(Color& color);
ListaFigura getListaFigura(Color& color);

#endif