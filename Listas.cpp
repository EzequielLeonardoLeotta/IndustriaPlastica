/* TDA Lista
 * Implementación Simplemente Enlazada
 * Archivo : Lista.cpp
 * Versión : 1.1
 */
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

#include "Listas.h"

 /******************************************************************************/
 /* Definición de Tipos de Datos para manejo interno */
 /*--------------------------------------------------*/


 /******************************************************************************/
 /* Funciones Adicionales */
 /*-----------------------*/

 /*
   pre : ninguna.
   post: compara ambos dato1 y dato2, devuelve
           mayor si dato1 es mayor que dato2,
           igual si dato1 es igual a dato2,
           menor si dato1 es menor que dato2.

   dato1 : dato a comparar.
   dato2 : dato a comparar.
   return resultado de comparar dato1 respecto de dato2.
 */

ResultadoComparacion compararDato(Dato dato1, Dato dato2) {
    /*if (dato1 > dato2) {
        return MAYOR;
    }
    else if (dato1 < dato2) {
        return MENOR;
    }
    else {
        return IGUAL;
    }*/
    //esta comentado porque viene una estructura como parametro en vez de un int
    return IGUAL; //borrar
}


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

void crearLista(Lista& lista) {
    lista.primero = fin();                // asigno el pintero al fin de la lista
}                                       // tambien se puede poner lista.primero = NULL

/*----------------------------------------------------------------------------*/
bool listaVacia(Lista& lista) {

    return (primero(lista) == fin());     // si primero(lista)==null devuelve true
}

/*----------------------------------------------------------------------------*/
PtrNodoLista fin() {
    return NULL;                          //devuelve un puntero a null
}

/*----------------------------------------------------------------------------*/
PtrNodoLista primero(Lista& lista) {
    return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista siguiente(Lista& lista, PtrNodoLista ptrNodo) {

    /* verifica si la lista está vacia o si ptrNodo es el último */

    if ((!listaVacia(lista)) && (ptrNodo != fin()))      //si la lista no está vacía y el nodo no es el último
        return ptrNodo->sgte;                               // devolver puntero a siguiente
    else
        return fin();
}

/*----------------------------------------------------------------------------*/
PtrNodoLista anterior(Lista& lista, PtrNodoLista ptrNodo) {

    PtrNodoLista ptrPrevio = fin();
    PtrNodoLista ptrCursor = primero(lista);

    while ((ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
        ptrPrevio = ptrCursor;
        ptrCursor = siguiente(lista, ptrCursor);
    }
    return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista ultimo(Lista& lista) {

    /* el último nodo de la lista es el anterior al fin() */
    return anterior(lista, fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoLista crearNodoLista(Dato dato) {

    /* reserva memoria para el nodo y luego completa sus datos */
    PtrNodoLista ptrAux = new NodoLista;      // reserva memorioa para un nodo

    ptrAux->dato = dato;                      // guarda el dato en el nodo
    ptrAux->sgte = fin();                     // el nuevo nodo apunta a null

    return ptrAux;                            // devuelve un puntero al nuevo nodo
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarPrincipio(Lista& lista, Dato dato) {

    /* crea el nodo */
    PtrNodoLista ptrNuevoNodo = crearNodoLista(dato);     //recibo el puntero al nuevo nodo

    /* lo incorpora al principio de la lista */
    ptrNuevoNodo->sgte = lista.primero;              //apunto el nuevo nodo al primero de la lista
    lista.primero = ptrNuevoNodo;                    // INdico que el primero es ahora el nuevo nodo

    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarDespues(Lista& lista, Dato dato, PtrNodoLista ptrNodo) {

    PtrNodoLista ptrNuevoNodo = fin();

    /* si la lista está vacia se adiciona la principio */
    if (listaVacia(lista))
        ptrNuevoNodo = adicionarPrincipio(lista, dato);

    else {
        if (ptrNodo != fin()) {

            /* crea el nodo y lo intercala en la lista */
            ptrNuevoNodo = crearNodoLista(dato);

            ptrNuevoNodo->sgte = ptrNodo->sgte;
            ptrNodo->sgte = ptrNuevoNodo;
        }
    }
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarFinal(Lista& lista, Dato dato) {

    /* adiciona el dato después del último nodo de la lista */
    return adicionarDespues(lista, dato, ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista adicionarAntes(Lista& lista, Dato dato, PtrNodoLista ptrNodo) {

    PtrNodoLista ptrNuevoNodo = fin();

    if (!listaVacia(lista)) {
        if (ptrNodo != primero(lista))
            ptrNuevoNodo = adicionarDespues(lista, dato, anterior(lista, ptrNodo));
        else
            ptrNuevoNodo = adicionarPrincipio(lista, dato);
    }
    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
void colocarDato(Lista& lista, Dato& dato, PtrNodoLista ptrNodo) {

    if ((!listaVacia(lista)) && (ptrNodo != fin()))
        ptrNodo->dato = dato;
}

/*----------------------------------------------------------------------------*/
void obtenerDato(Lista& lista, Dato& dato, PtrNodoLista ptrNodo) {

    if ((!listaVacia(lista)) && (ptrNodo != fin()))
        dato = ptrNodo->dato;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(Lista& lista, PtrNodoLista ptrNodo) {

    PtrNodoLista ptrPrevio;                           //defino un nodo auxiliar

    /* verifica que la lista no esté vacia y que nodo no sea fin*/
    if ((!listaVacia(lista)) && (ptrNodo != fin())) {    // si la lista no está vacía y el nodo no es el último

        if (ptrNodo == primero(lista))
            lista.primero = siguiente(lista, primero(lista));  // si el nodo que voy a elminar es el primero de la lista
                                                              //asigno lista.primero al segundo nodo de la lista    
        else {
            ptrPrevio = anterior(lista, ptrNodo);          // El auxiliar guarda el puntero del anterior al que quiero borrar
            ptrPrevio->sgte = ptrNodo->sgte;                  // Al nodo anterior le asigno lo que está apuntando el que quiero borrar
        }
        // Si el dato es un TDA, acá habría que llamar al destructor.

        delete ptrNodo;
    }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(Lista& lista) {

    if (!listaVacia(lista))              // si la lista no esta vacía
        eliminarNodo(lista, primero(lista)); //elimino el primer nodo
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(Lista& lista) {

    if (!listaVacia(lista))
        eliminarNodo(lista, ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(Lista& lista) {

    /* retira uno a uno los nodos de la lista */
    while (!listaVacia(lista))
        eliminarNodo(lista, primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoLista localizarDato(Lista& lista, Dato dato) {

    bool encontrado = false;
    Dato datoCursor;
    PtrNodoLista ptrCursor = primero(lista);

    /* recorre los nodos hasta llegar al último o hasta
       encontrar el nodo buscado */
    while ((ptrCursor != fin()) && (!encontrado)) {

        /* obtiene el dato del nodo y lo compara */
        obtenerDato(lista, datoCursor, ptrCursor);
        if (compararDato(datoCursor, dato) == IGUAL)
            encontrado = true;
        else
            ptrCursor = siguiente(lista, ptrCursor);
    }

    /* si no lo encontró devuelve fin */
    if (!encontrado)
        ptrCursor = fin();

    return ptrCursor;
}

/*----------------------------------------------------------------------------*/
void eliminarDato(Lista& lista, Dato dato) {

    /* localiza el dato y luego lo elimina */
    PtrNodoLista ptrNodo = localizarDato(lista, dato);
    if (ptrNodo != fin())
        eliminarNodo(lista, ptrNodo);
}

/*----------------------------------------------------------------------------*/
PtrNodoLista insertarDato(Lista& lista, Dato dato) {

    PtrNodoLista ptrPrevio = primero(lista);
    PtrNodoLista ptrCursor = primero(lista);
    PtrNodoLista ptrNuevoNodo;
    Dato datoCursor;
    bool ubicado = false;

    /* recorre la lista buscando el lugar de la inserción */
    while ((ptrCursor != fin()) && (!ubicado)) {

        obtenerDato(lista, datoCursor, ptrCursor);
        if (compararDato(datoCursor, dato) == MAYOR)
            ubicado = true;

        else {
            ptrPrevio = ptrCursor;
            ptrCursor = siguiente(lista, ptrCursor);
        }
    }

    if (ptrCursor == primero(lista))
        ptrNuevoNodo = adicionarPrincipio(lista, dato);
    else
        ptrNuevoNodo = adicionarDespues(lista, dato, ptrPrevio);

    return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(Lista& lista) {

    Lista temp = lista;
    PtrNodoLista ptrCursor = primero(temp);
    crearLista(lista);
    while (ptrCursor != fin()) {
        Dato dato;
        obtenerDato(temp, dato, ptrCursor);
        insertarDato(lista, dato);
        eliminarNodo(temp, ptrCursor);
        ptrCursor = primero(temp);
    }
    eliminarLista(temp);
}


/*----------------------------------------------------------------------------*/

int longitud(Lista& lista) {
    PtrNodoLista ptrCursor = primero(lista);
    int longitud = 0;
    while (ptrCursor != fin()) {
        longitud++;
        ptrCursor = siguiente(lista, ptrCursor);
    }
    return longitud;
}

/*----------------------------------------------------------------------------*/
/*void mostrar (Lista &lista){
Dato datoCursor;
   PtrNodoLista ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
     /*while ((ptrCursor != fin()) ) {

       /* obtiene el dato del nodo y lo compara */
       /*std::cout<< obtenerDato(lista,datoCursor,ptrCursor)<<endl;
   }
}*/