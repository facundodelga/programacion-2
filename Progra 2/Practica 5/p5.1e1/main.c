#include <stdio.h>
#include <stdlib.h>
#include "colaE.h"

void cargaC(TCola *c);
void muestraC(TCola *c);
void sacaImp(TCola *c);

int main(){
    TCola c;

    IniciaC(&c);
    cargaC(&c);
    muestraC(&c);
    sacaImp(&c);
    muestraC(&c);
    return 0;
}

void cargaC(TCola *c){
    FILE *arch;
    TElementoC x;
    arch = fopen("p5.1e1.txt","r");

    while(fscanf(arch,"%d\n",&x) == 1)
        poneC(c,x);

    fclose(arch);
}

void muestraC(TCola *c){
    TCola aux;
    TElementoC x;
    IniciaC(&aux);

    while(!VaciaC(*c)){
        sacaC(c,&x);
        printf("[ %d ] ",x);
        poneC(&aux,x);
    }
    printf("\n");

    while(!VaciaC(aux)){
        sacaC(&aux,&x);
        poneC(c,x);
    }
}

void sacaImp(TCola *c){
    TCola aux;
    TElementoC x;
    IniciaC(&aux);

    while(!VaciaC(*c)){
        sacaC(c,&x);
        if( x % 2 == 0)
            poneC(&aux,x);
    }

    while(!VaciaC(aux)){
        sacaC(&aux,&x);
        poneC(c,x);
    }

}
