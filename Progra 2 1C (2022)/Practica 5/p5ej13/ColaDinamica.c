#include <stdio.h>
#include <stdlib.h>
#include "ColaDinamica.h"

void iniciaC (TCola *c){
    c->pri=NULL;
    c->ult=NULL;
}
int vaciaC (TCola c){
    return c.pri==NULL;
}

void poneC (TCola *c, TElementoC x){
    nodoC *aux;

    aux=(nodoC *) malloc(sizeof(nodoC));
    aux->dato = x;
    aux->sig = NULL;

    if (c->pri == NULL)
        c->pri = aux;
    else
        c->ult->sig = aux;
    c->ult=aux;
}

void sacaC (TCola *c, TElementoC *x){
    nodoC *aux;

    if(c->pri != NULL){
        aux = c->pri;
        *x = aux->dato;
        c->pri = c->pri->sig;
        if (c->pri == NULL){
            c->ult=NULL;
        }
        free(aux);
    }
}

TElementoC consultaC (TCola c){
    if (c!=NULL){
        return c->pri==NULL;
    }
}
