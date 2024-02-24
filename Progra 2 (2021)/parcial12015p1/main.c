#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\facundo\Documents\Progra 2\mis libs\PilasEstaticas.h"

int valido=12; //cantidad de valores en la pila

void eliminarIgualesRec(TPila *p,TElementoP x,int);
void cargarPila(TPila*);
void muestraRecursivo(TPila*,int);

int main()
{
    TPila p;

    iniciaP(&p);
    cargarPila(&p);
    muestraRecursivo(&p,valido);
    eliminarIgualesRec(&p,19,valido);
    muestraRecursivo(&p,valido);
    return 0;
}

void eliminarIgualesRec(TPila *p,TElementoP x,int n){
    TElementoP *basura,guarda_elemento;

    if (vaciaP(*p)||n<0){
        printf("La pila esta vacia\n");
    }else{
        if(consultaP(*p)==x){
            basura=(TElementoP*)malloc(sizeof(TElementoP));
            sacaP(p,basura);
            free(basura);
            eliminarIgualesRec(p,x,n-1);
        }else{                              //saco de la pila y cuando vuelva, lo regreso
            sacaP(p,&guarda_elemento);
            eliminarIgualesRec(p,x,n-1);
            poneP(p,guarda_elemento);
        }
    }
}

void cargarPila(TPila *pila){
    TElementoP dato;
    int i;

    for(i=0;i<valido;i++){
        dato=rand()%21;  //numeros random {0-20}
        poneP(pila,dato);
    }
}

void muestraRecursivo(TPila *p,int n){
    TElementoP x;
    if (!vaciaP(*p)&&n>0){
        sacaP(p,&x);
        printf("| %d |\n",x);
        muestraRecursivo(p,n-1);
        poneP(p,x);
    }
}
