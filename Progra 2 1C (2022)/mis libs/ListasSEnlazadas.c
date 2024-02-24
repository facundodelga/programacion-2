#include <stdio.h>
#include <stdlib.h>
#include "ListasSEnlazadas.h"



NodoL* crearNodo(datoL x){  //creo nodo y le agrego el dato
    NodoL *aux=NULL;

    aux=(NodoL*)malloc(sizeof(NodoL));

    if (aux!=NULL){
        aux->dato=x;
        aux->sig=NULL;
    }
    return aux;
}

void insertarFinal(NodoL **cabeza,datoL x){
    NodoL *aux=NULL, *nAux=*cabeza;

    aux=crearNodo(x);

    if (aux!=NULL){
        while (nAux->sig != NULL){
            nAux=nAux->sig;
        }
        nAux->sig=aux;
    }
}

int insertarInicio(NodoL **cabeza,datoL x){
    NodoL *aux=NULL;

    aux=crearNodo(x);

    if (aux != NULL){
        aux->sig=*cabeza;
        *cabeza=aux;
        return 1;
    }
    return 0;
}

void mostrarLista(NodoL *cabeza){
    NodoL *aux=cabeza;
    while (aux!=NULL){
        printf(". %d\n",aux->dato);
        aux=aux->sig;
    }
}
