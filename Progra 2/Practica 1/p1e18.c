#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void multip_vectorFor(int v[],int);
void cargaV(int v[],int *);
void muestraV(int v[],int );

int main(){
    int validos = 0, v[MAX];

    cargaV(v,&validos);
    muestraV(v,validos);
    multip_vectorFor (v,validos);

    return 0;
}

void cargaV(int v[MAX],int *val){
    int cant=0;
    do{
        printf("cantidad de elementos > 0\n");
        scanf("%d",&cant);
    }while (cant<=0);

    for(int i=0;i<cant;i++){
        v[i]=rand()%30;
    }
    *val = cant;
    printf("fin\n");
}

void multip_vectorFor (int v[MAX],int validos){
    for(int i=0;i<validos;i+=2){
        v[i] *= 2;
    }
    muestraV(v,validos);
}

void muestraV(int v[],int validos){
    for (int i=0;i<validos;i++)
        printf("v[ %d ] = %d\n",i,v[i]);
}
