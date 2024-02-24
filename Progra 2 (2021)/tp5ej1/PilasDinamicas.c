#include <stdio.h>
#include <stdlib.h>
#include "PilasDinamicas.h"

void poneP(TPila *p, TElementoP x){
    TPila n;
    *p = (TPila)malloc(sizeof(nodop));
    n->dato=x;
    n->sig=*p;
    *p=n;
}

void sacaP(TPila *p, TElementoP * x){
    TPila n;
    if (*p){
        n=*p;
        *x=(*p)->dato;
        *p=(*p)->sig;
        free(n);
    }
}

TElementoP consultaP(TPila p){
    if(p){
        return p->dato;
    }
}

int VaciaP(TPila p){
    return p==NULL;
}

void IniciaP(TPila *p){
    *p=NULL;
}
