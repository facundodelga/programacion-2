#include <stdio.h>
#include <stdlib.h>
#include "colasTp5Ej4.1.h"


void iniciaC(TCola *c){
    (*c).pri=NULL;
    (*c).ult=NULL;
}
int vaciaC(TCola c){
    return c.pri==NULL;
}
void poneC(TCola *c,TElementoC x){
    nodo *aux;
    aux=(nodo*)malloc(sizeof(nodo));
    aux->dato=x;
    aux->sig=NULL;
    if ((*c).pri==NULL)
        (*c).pri=aux;
    else
        (*c).ult->sig=aux;
    (*c).ult=aux;
}
void sacaC(TCola *c,TElementoC *x){
    nodo *aux;
    if ((*c).pri!=NULL){
        aux=(*c).pri;
        *x=aux->dato;
        (*c).pri=(*c).pri->sig;
        if ((*c).pri==NULL)
            (*c).ult=NULL;
        free(aux);
    }
}
TElementoC consultaC (TCola c){
    return c.pri->dato;
}
