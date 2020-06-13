#include "Areas.h"

float areaCirculo(float radio)
{
	return M_PI * pow(radio, 2);
}

float areaCilindro(float radio, float altura)
{
	return 2 * M_PI * radio * (radio + altura);
}

float areaCubo(float lado)
{
	return 6 * pow(lado, 2);
}

float areaTriangulo(float catetoMayor, float catetoMenor) //solo son triangulos rectangulos
{
	return (catetoMayor * catetoMenor) / 2;
}

float areaRectangulo(float base, float altura)
{
	return base * altura;
}