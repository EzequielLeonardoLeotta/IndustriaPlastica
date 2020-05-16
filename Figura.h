#ifndef __FIGURA_H__
#define __FIGURA_H__

#include<string>
using namespace std;

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

enum class TipoFigura { Circulo, Cilindro, Cubo, Triangulo, Rectangulo };

typedef struct Figura {
    TipoFigura tipoFigura;
    string color;
    float area;
    float parametro1;
    float parametro2;
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
    PRE: La instancia del TDA (Figura) no debe haberse creado (constructor) ni destruido (destructor) con anterioridad.
    POST: Deja la instancia del TDA (Figura) listo para ser usado.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva), color, area, parametro1, parametro2.
    RETORNO: No aplica.
*/
void constructor(Figura& figura, TipoFigura tipoFigura, string color, float area, float parametro1, float parametro2);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Destruye la instancia del TDA y ya no podra ser utilizada.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: No aplica.
*/
//void destructor(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve el Tipo de Figura de la Figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve el TipoFigura.
*/
TipoFigura getTipoFigura(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: La figura queda con el nuevo Tipo de Figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva) y tipoFigura (valor de TipoFigura a asignar a la Figura).
    RETORNO: No aplica.
*/
void setTipoFigura(Figura& figura, TipoFigura tipoFigura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve el color de la figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve el color de la figura.
*/
string getColor(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: La figura queda con el nuevo color.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva) y color (valor del color a asignar a la Figura).
    RETORNO: No aplica.
*/
void setColor(Figura& figura, string color);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve el area de la figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve el area de la figura.
*/
float getArea(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: La figura queda con la nueva area.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva) y area (valor del area a asignar a la Figura).
    RETORNO: No aplica.
*/
void setArea(Figura& figura, float area);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve el parametro1 de la figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve el parametro1 de la figura.
*/
float getParametro1(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: La figura queda con el nuevo parametro1.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva) y parametro1 (valor del parametro1 a asignar a la Figura).
    RETORNO: No aplica.
*/
void setParametro1(Figura& figura, float parametro1);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: Devuelve el parametro2 de la figura.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva).
    RETORNO: Devuelve el parametro2 de la figura.
*/
float getParametro2(Figura& figura);

/*
    PRE: La instancia del TDA (Figura) debe haberse creado (constructor) pero no debe estar destruida (destructor).
    POST: La figura queda con el nuevo parametro2.
    ATRIBUTOS: Figura (instancia sobre la cual se aplica la primitiva) y parametro2 (valor del parametro2 a asignar a la Figura).
    RETORNO: No aplica.
*/
void setParametro2(Figura& figura, float parametro2);

#endif 