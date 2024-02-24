#include <stdio.h>
#include <stdlib.h>
#include "pilasEj7.h"

void poneP (TPila *p,TElementoP x){
    TPila aux;

    aux=(TPila)malloc(sizeof(nodoP));

    aux->dato=x;
    aux->sig=*p;

    *p=aux;
}


void sacaP (TPila *p,TElementoP *x){
    TPila aux;
    if(*p){
        aux=*p;
        *x=(*p)->dato;
        *p=(*p)->sig;
        free(aux);
    }
}

TElementoP consultaP (TPila p){
    if(p){
        return p->dato;
    }else{
        return -999;
    }
}

int vaciaP (TPila p){
    return p==NULL;
}

void iniciaP (TPila *p){
    *p=NULL;
}
