#include <stdio.h>
#include <stdlib.h>
#include "TDAej2.h"

void poneP(TPila *p, TElementoP x){
    TPila n;
    n = (TPila)malloc(sizeof(nodop));
    n->dato=x;
    n->sig=*p;
    *p=n;
}

void sacaP(TPila *p){
    TPila n;
    if (*p){
        n=*p;
        //printf("(*p)->dato: %c\n",(*p)->dato);
        //*x=(*p)->dato;
        *p=(*p)->sig;
        free(n);
    }
}

TElementoP consultaP(TPila p){
    if(p){
        return p->dato;
    }
    return 0;
}

void mostrarP(TPila *p){
    TPila aux;
    while (*p){
        //printf("%c ",consultaP(*p));
        poneP(&aux,consultaP(*p));
        printf("%c ",aux->dato);
        sacaP(p);

    }
    printf("devolucion de datos a la pila (no quedan en orden original)\n");
    while (aux){
        poneP(p,consultaP(aux));
        printf("%c ",(*p)->dato);
        sacaP(&aux);
    }
    //aux=vaciaP(aux);
    printf("fin\n");
}

int vaciaP(TPila p){
    return p==NULL;
}

void iniciaP(TPila *p){
    *p=NULL;
}
