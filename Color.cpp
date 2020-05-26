#include "Color.h"

void constructor(Color& color, string descripcion)
{
	color.descripcion = descripcion;
	crearListaFigura(color.lstfigura);
}

void setDescripcion(Color& colo, string descripcion)
{
	colo.descripcion = descripcion;
}

void setListaFigura(Color& colo, ListaFigura lista)
{
	colo.lstfigura = lista;
}

string getNombre(Color& colo)
{
	return colo.descripcion;
}

ListaFigura getLista(Color& colo)
{
	return colo.lstfigura;
}