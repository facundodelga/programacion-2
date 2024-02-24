#include <stdio.h>
#include <stdlib.h>
#include "colaCircular.h"
#include "pilaD.h"

typedef struct nodoL{
    TCola cola;
    struct nodoL *sig;
}nodoL;

typedef nodoL *TLista;

void cargaL(TLista *);
void cargaP(TLista ,TPila *);
void muestraP(TPila *);
int main(){
    TPila p;
    TLista l=NULL;
    cargaL(&l);
    cargaP(l,&p);
    muestraP(&p);
    return 0;
}

void cargaL(TLista *l){
    TLista aux=NULL;
    FILE *arch;
    TElementoC num = 1;
    arch = fopen("p6e5.txt","r");

    while(!feof(arch)){
        aux = (TLista)malloc(sizeof(nodoL));
        iniciaC(&aux->cola);
        do{
            fscanf(arch,"%d ",&num);
            printf("%d\n",num);
            poneC(&aux->cola,num);

        }while(num != -1);

        aux->sig = *l;
        *l = aux;
    }
}

void cargaP(TLista l,TPila *p){
    TLista aux = l;
    TCola auxC;
    TElementoC c,max;
    iniciaC(&auxC);
    IniciaP(p);
    while(aux != NULL){
        sacaC(&aux->cola,&c);
        max = c;
        while(c != -1){
            sacaC(&aux->cola,&c);
            if(max < c)
                max = c;
        }
        poneP(p,max);

        aux = aux->sig;
    }

}

void muestraP(TPila *p){
    TElementoP x;
    if(!VaciaP(*p)){
        sacaP(p,&x);
        printf("[%d]\n",x);
        muestraP(p);
        poneP(p,x);
    }
}
