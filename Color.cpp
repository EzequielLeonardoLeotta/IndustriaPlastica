#include "Color.h"

void constructor(Color& color, Figura figura)
{
	color.descripcion = getColor(figura);
	crearListaFigura(color.lstfigura);
	adicionarPrimero(color.lstfigura, figura);
}

void setDescripcion(Color& color, string descripcion)
{
	color.descripcion = descripcion;
}

void setListaFigura(Color& color, ListaFigura lista)
{
	color.lstfigura = lista;
}

string getDescripcion(Color& color)
{
	return color.descripcion;
}

ListaFigura getListaFigura(Color& color)
{
	return color.lstfigura;
}