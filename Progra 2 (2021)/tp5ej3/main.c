#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

void votacion(TPila *p,DNI dni,char op);
void mostrarPila();
void mostrarPilaInvertido();

int main()
{
    TPila p;
    iniciaP(&p);
    votacion(&p,"0",'s');
    mostrarPila(&p,2);
    mostrarPilaInvertido(&p,2);
    return 0;
}

void votacion(TPila *p,DNI dni,char op){

    if (op!='s'){

    }else{
        printf("DNI del votante?\n");
        scanf(" %d",&dni);
        ponerP(p,dni);
        printf("Desea seguir ingresando votos? [s/n]\n");
        scanf(" %c",&op);
        votacion(p,dni,op);
    }
}

void mostrarPila(TPila *p,int n){
    DNI x;

    if ((n>0)&&(!vaciaP(*p))){
        sacarP(p,&x);
        printf("%d\n",x);
        mostrarPila(p,n-1);
        ponerP(p,x);
    }
}

void mostrarPilaInvertido(TPila *p,int n){
    DNI x;

    if ((n>0)&&(!vaciaP(*p))){
        sacarP(p,&x);
        mostrarPila(p,n-1);
        printf("%d\n",x);
        ponerP(p,x);
    }
}

