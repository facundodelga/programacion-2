#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cantEliminados(TPila *,int *,int );

int main(){
    TPila p=NULL;
    int eliminados=0;
    PoneP(&p,7);
    PoneP(&p,32);
    PoneP(&p,5);
    PoneP(&p,9);
    PoneP(&p,0);
    PoneP(&p,11);
    PoneP(&p,9);
    PoneP(&p,43);
    PoneP(&p,23);
    PoneP(&p,9);
    PoneP(&p,9);
    PoneP(&p,9);
    cantEliminados(&p,&eliminados,9);

    return 1;
}


void cantEliminados(TPila *p,int *eliminados,int x){
    int aux;

    if (!*p){

        printf("cantidad de elementos eliminados: %d\n",*eliminados);

    }else{
        SacaP(p,&aux);
        if (aux==x){
            (*eliminados)++;
            cantEliminados(p,eliminados,x);
        }else{
            cantEliminados(p,eliminados,x);
            PoneP(p,aux);
        }

    }
}
