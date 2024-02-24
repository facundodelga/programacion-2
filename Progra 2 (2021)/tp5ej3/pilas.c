#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void ponerP(TPila *p,DNI dni){

    TPila n;
    n=(TPila)malloc(sizeof(nodop));

    n->dato= dni;

    n->sig = *p;
    *p=n;

}
void sacarP(TPila *p,DNI *x){
    TPila n;
    if (*p){
        n=*p;
        *x=(*p)->dato;
        *p=(*p)->sig;
        free(n);
    }
}
DNI consultaP(TPila p){
    if (p){
        return p->dato;
    }
    return 0;
}
int vaciaP(TPila p){
    return (p==NULL);
}

void iniciaP(TPila *p){
    *p=NULL;
}
