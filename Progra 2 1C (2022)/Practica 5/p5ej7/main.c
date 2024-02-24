#include <stdio.h>
#include <stdlib.h>
#include "pilasEj7.h"

void cargarPila(TPila *);
void cambiaSigno(TPila *);

int main()
{
    TPila p;
    iniciaP(&p);
    cargarPila(&p);

    cambiaSigno(&p);
    return 0;
}
void cargarPila(TPila *pila){
    TElementoP x=0;
    FILE *arch;

    arch=fopen("p5ej7.txt","r");

    while(!feof(arch)){

        fscanf(arch," %d \n",&x);
        poneP(pila,x);

    }

    fclose(arch);

}

void cambiaSigno(TPila *p){
    TElementoP x;
    if(!vaciaP(*p)){
        sacaP(p,&x);
        cambiaSigno(p);
        printf("%d\n",x*-1);
        poneP(p,x*(-1));
    }
}
