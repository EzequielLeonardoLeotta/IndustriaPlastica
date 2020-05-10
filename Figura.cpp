#include "Figura.h"
#include<string>
using namespace std;

void constructor(Figura& figura, string color, float area, float parametro1, float parametro2)
{
	figura.color = color;
	figura.area = area;
	figura.parametro1 = parametro1;
	figura.parametro2 = parametro2 ? parametro2 : NULL;
};

TipoFigura getTipoFigura(Figura& figura) 
{ 
	return figura.tipoFigura; 
};

void setTipoFigura(Figura& figura, TipoFigura tipoFigura)
{
	figura.tipoFigura = tipoFigura;
};

string getColor(Figura& figura)
{
	return figura.color;
};

void setColor(Figura& figura, string color)
{
	figura.color = color;
};

float getArea(Figura& figura) 
{
	return figura.area;
};

void setArea(Figura& figura, float area)
{
	figura.area = area;
};

float getParametro1(Figura& figura)
{
	return figura.parametro1;
};

void setParametro1(Figura& figura, float parametro1)
{
	figura.parametro1 = parametro1;
};

float getParametro2(Figura& figura)
{
	return figura.parametro2;
};

void setParametro2(Figura& figura, float parametro2)
{
	figura.parametro2 = parametro2;
};