#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void cargaListaInv(TLista *,int [],int );
void cargaLista(TLista *,int [],int );
void cargaListaOrd(TLista *,int [],int );
void muestraV(int [],int );
void muestraL(TLista);

int main()
{
    TLista l_a=NULL,l_b=NULL,l_c=NULL;
    int v[MAX] = {1,24,13,5,32,43,2,1,32,14,34,2,21,41,2,312,4,23,45}, n = 19;
    muestraV(v,n);
    cargaListaInv(&l_a,v,n);
    printf(" a) Vector Invertido ==>\n");
    muestraL(l_a);
    cargaLista(&l_b,v,n);
    printf(" b) Vector tal cual ==>\n");
    muestraL(l_b);
    cargaListaOrd(&l_c,v,n);
    printf(" c) Vector ordenado ==>\n");
    muestraL(l_c);
    return 0;
}

void cargaListaInv(TLista *l,int v[],int n){
    TLista aux = NULL;

    for(int i=0; i < n;i++){
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = v[i];
        aux->sig = *l;
        *l = aux;
    }
}

void cargaLista(TLista *l,int v[],int n){
    TLista aux = NULL,act;

    for(int i=0; i < n;i++){
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = v[i];
        aux->sig = NULL;
        if(*l == NULL){
            aux->sig = *l;
            *l = aux;
        }else{
            act = *l;
            while(act->sig != NULL)
                act = act->sig;
            act->sig = aux;
        }
    }

}

void cargaListaOrd(TLista *l,int v[],int n){
    TLista aux = NULL,act,ant;

    for(int i=0; i < n;i++){
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = v[i];
        aux->sig = NULL;
        if(*l == NULL || aux->dato < (*l)->dato){
            aux->sig = *l;
            *l = aux;
        }else{
            act = *l;
            ant = NULL;
            while(act != NULL && act->dato <= aux->dato){
                ant = act;
                act = act->sig;
            }
            aux->sig = act;
            ant->sig = aux;

        }
    }

}

void muestraV(int v[], int n){
    for(int i=0;i<n;i++)
        printf("[ %d ] ",v[i]);
    printf("\n");
}

void muestraL(TLista l){
    TLista aux = l;

    while(aux != NULL){
        printf("[ %d ] ",aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}





