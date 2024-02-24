#include "pilasEj1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void poneP (TPila *p, TElementoP x){
    TPila aux;

    aux = (TPila) malloc(sizeof(nodop));
    aux->dato=(TElementoP)malloc(11*sizeof(char));
    strcpy(aux->dato,x);
    aux->sig = *p;

    *p=aux;

}

void sacaP (TPila *p, TElementoP *x){
    if (*p){
        TPila aux;
        aux=*p;
        strcpy(*x,(*p)->dato);
        *p = (*p)->sig;
        free(aux);

    }

}
TElementoP consultaP(TPila p){
    if(p){
        return p->dato;
    }
}

int vaciaP (TPila p){
    return (p==NULL);
}
void iniciaP (TPila *p){
    *p=NULL;

}
