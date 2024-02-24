#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct nodo{
    int v;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

int main()
{
    TLista l[N] = {NULL};

    return 0;
}

int gSalida(TLista l[N], int v){
    int i = 0,grado = 0;

    while(l[i] != NULL){
        grado++;
        l[i] = l[i]->sig;
    }
    return grado;
}

int gEntrada(TLista l[],int v){
    int i = 0,grado = 0;

    while(i < N){
        while(l[i] != NULL){
            if(l[i]->v == v)
                grado++;
            l[i] = l[i]->sig;
        }
        i++;
    }
    return grado;
}

int gVertice(TLista l[], int v){
    return gSalida(l,v) + gEntrada(l,v);
}
