#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;
}NodoL;

NodoL* crearNodo(int x);
void insertarFinal(NodoL **,int x);
int insertarInicio(NodoL **,int x);
void mostrarLista(NodoL *);

int main(){
    NodoL *L=NULL;
//    printf("%d",L->dato);
    //insertarInicio(&L,5);
    insertarInicio(&L,4);
    insertarFinal(&L,6);
    insertarFinal(&L,7);
//    insertarFinal(&L,8);
    mostrarLista(L);
    return 0;
}

NodoL* crearNodo(int x){  //creo nodo y le agrego el dato
    NodoL *aux=NULL;

    aux=(NodoL*)malloc(sizeof(NodoL));

    if (aux!=NULL){
        aux->dato=x;
        aux->sig=NULL;
    }
    return aux;
}

void insertarFinal(NodoL **cabeza,int x){
    NodoL *aux=NULL, *nAux=*cabeza;

    aux=crearNodo(x);

    if (aux!=NULL){
        while (nAux->sig != NULL){
            nAux=nAux->sig;
        }
        nAux->sig=aux;
    }
}

int insertarInicio(NodoL **cabeza,int x){
    NodoL *aux=NULL;

    aux=crearNodo(x);

    if (aux != NULL){
        aux->sig=*cabeza;
        *cabeza=aux;
        return 1;
    }
    return 0;
}

void mostrarLista(NodoL *cabeza){
    NodoL *aux=cabeza;
    while (aux!=NULL){
        printf(". %d\n",aux->dato);
        aux=aux->sig;
    }
    //printf("\n");
}
