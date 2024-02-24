#include <stdio.h>
#include <stdlib.h>
#include "ListasTp6Ej2.h"

//creo nodo y le agrego el dato
NodoL* crearNodo(datoL x){
    NodoL *aux=NULL;

    aux=(NodoL*)malloc(sizeof(NodoL));

    if (aux!=NULL){
        aux->dato=x;
        aux->sig=NULL;
    }
    return aux;
}

//Inserto dato al final de la lista
int insertarFinal(NodoL **cabeza, datoL dato)
{
    NodoL* nuevo = NULL, *nAux = *cabeza;

    nuevo = crearNodo(dato);
    if( nuevo != NULL)
    {
        while(nAux->sig != NULL)
        {
            nAux = nAux->sig;
        }
        nAux->sig = nuevo;
        return 1;
    }
    return 0;
}

//Inserto un elemento al principio de la lista
int insertarInicio(NodoL **cabeza,datoL x){
    NodoL *aux=NULL;

    aux=crearNodo(x);

    if (aux != NULL){
        aux->sig=*cabeza;  //le asigno como siguiente la cabeza para hacer push en la lista original
        *cabeza=aux;    //asigno el auxiliar para devolver la lista con el dato a la cabeza
        return 1;
    }
    return 0;
}

//Muestro la lista completa
void mostrarLista(NodoL *cabeza){
    NodoL *aux=cabeza;
    while (aux!=NULL){
        printf(". %c\n",aux->dato);
        aux=aux->sig;
    }
}
