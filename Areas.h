#ifndef __AREAS_H__
#define __AREAS_H__

//Lib para numero pi
#define _USE_MATH_DEFINES
#include <math.h>

//Calculos segun la figura

float areaCirculo(float radio);
float areaCilindro(float radio, float altura);
float areaCubo(float lado);
float areaTriangulo(float catetoMayor, float catetoMenor); //solo son triangulos rectangulos
float areaRectangulo(float base, float altura);

#endif