#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargaP(TPila *);
void ej7(TPila *);
void muestraP(TPila *);


int main(){
    TPila p;
    IniciaP(&p);
    cargaP(&p);
    ej7(&p);
    muestraP(&p);

    return 0;
}

void cargaP(TPila *p){
    int x;
    FILE *arch;
    arch = fopen("p5e7.txt","r");

    while(fscanf(arch,"%d\n",&x) == 1){
        poneP(p,x);
    }


    fclose(arch);
}

void ej7(TPila *p){
    TElementoP x;
    if(!VaciaP(*p)){
        sacaP(p,&x);
        ej7(p);
        poneP(p,x * (-1));
    }
}

void muestraP(TPila *p){
    TElementoP x;
    TPila p2;
    IniciaP(&p2);
    while(!VaciaP(*p)){
        sacaP(p,&x);
        printf("%d\n",x);
        poneP(&p2,x);
    }

    while(!VaciaP(p2)){
        sacaP(&p2,&x);
        poneP(p,x);
    }
}


