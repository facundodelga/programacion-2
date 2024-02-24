#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char dato[15];
    struct nodo * sig;} nodo;
typedef struct nodo * TLista;

//Busqueda

int esta (TLista L, char *x){
    TLista aux;
    aux = L;
    while (aux != NULL && strcmp(x,aux->dato) !=0)
        aux = aux -> sig;
    return aux != NULL;
}

int estaOrd (TLista L, char *x){
    TLista aux = L;
    while (aux != NULL && strcmp(x, aux->dato) > 0)
        aux = aux -> sig;
    return aux != NULL && strcmp(x, aux->dato) == 0;
}

//insercion ordenada

void insertaOrd (TLista * L, int x){
    TLista aux=NULL, ant, act;
    aux = (TLista) malloc (sizeof(nodo));
    aux->dato = x;
    
    if (*L == NULL || x < (*L)->dato) {
        aux->sig = *L;
        *L = aux;
    }
    else{
        ant=NULL;
        act=*L;
        while (act != NULL && x > act->dato){
            ant=act;
            act=act->sig;
        }
        aux->sig=act;
        ant->sig=aux;
    }
}

void eliminaE(TLista *L, int x){
    TLista ant,act;
    if (*L !=NULL)
        if ((*L)->dato==x){
            act=*L;
            *L=(*L)->sig;
            free(act);
        }else {
            act = *L;
            while (act != NULL && x>act->dato){
                ant=act;
                act = act -> sig;
            }
            if (act != NULL && x==act->dato) {
                ant->sig=act->sig;
                free(act);
            }
    }
}


void muestraL(TLista l){
    TLista aux = l;

    while(aux != NULL){
        printf("[ %d ] ",aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

//estructura lista con sublista
typedef struct nodito{
    char nombre[20];
    int edad;
    char estado;
    struct nodito *sig;
}nodito;

typedef nodito *subLista;

typedef struct nodo{
    char club[20];
    int puntaje;
    subLista subL;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

