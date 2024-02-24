#include <stdio.h>
#include <stdlib.h>
#include "PilasDinamicas.h"

void cargarP();
void transformarPilaNegativa();

int main()
{
    TPila stack;
    IniciaP(&stack);
    cargarP(&stack,6,0);
    printf("------------\n");
    transformarPilaNegativa(&stack);
    printf("------------\n");
    return 0;
}

void cargarP(TPila *p, int n, int i){
    TElementoP x;
    if ((i<=n)){
        x=rand()%21;
        printf("|    %i    |\n",x);
        poneP(p,x);
        cargarP(p,n,i+1);
    }

}

void transformarPilaNegativa(TPila *p){
    TElementoP x;
    if (!VaciaP(*p)){
        sacaP(p,&x);
        transformarPilaNegativa(p);
        poneP(p,x-2*x);
        printf("|  %d  |\n",consultaP(*p));
    }

}
