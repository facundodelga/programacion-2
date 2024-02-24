#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

TLista creaNodo(int x);
void insertaNodo (TLista *L, int x);
void mostrarLista(TLista L);
void insertaAdelante(TLista *L, int x);
void insertaOrdenado(TLista *L, int x);

int main()
{
    TLista a=NULL;
//    insertaNodo(&a,5);
//    insertaNodo(&a,2);
//    insertaNodo(&a,6);
//    mostrarLista(a);
//    printf(" /// /// /// /// ///\n");
//    insertaAdelante(&a,5);
//    insertaAdelante(&a,2);
//    insertaAdelante(&a,6);
//    mostrarLista(a);
//    printf(" /// /// /// /// ///\n");
    insertaOrdenado(&a,5);
    insertaOrdenado(&a,2);
    insertaOrdenado(&a,6);
    insertaOrdenado(&a,5);
    insertaOrdenado(&a,2);
    insertaOrdenado(&a,6);
    insertaOrdenado(&a,5);
    insertaOrdenado(&a,2);
    insertaOrdenado(&a,6);
    insertaOrdenado(&a,5);
    insertaOrdenado(&a,2);
    insertaOrdenado(&a,6);
    mostrarLista(a);

    return 0;
}


TLista creaNodo(int x){
    TLista aux;

    aux=(TLista)malloc(sizeof(nodo));

    aux->dato = x;
    aux->sig = NULL;

    return aux;
}

void insertaNodo (TLista *L, int x){
    TLista aux=*L,nuevo=NULL;

    nuevo=creaNodo(x);

    if (aux!=NULL){

        while (aux->sig!=NULL){
            aux=aux->sig;
        }

        aux->sig=nuevo;

    }else{
        *L=nuevo;
    }

}
void insertaAdelante(TLista *L, int x){
    TLista nuevo=NULL;

    nuevo=creaNodo(x);

    nuevo->sig = *L;
    *L = nuevo;

}

void insertaOrdenado(TLista *L, int x){
    TLista act=*L,ant=NULL,nuevo=NULL;

    nuevo=creaNodo(x);

    if(*L == NULL || x < (*L)->dato){
        nuevo->sig = *L;
        *L=nuevo;

    }else{

        while (act!=NULL && act->dato <= x){
            ant=act;
            act=act->sig;
        }
        nuevo->sig = act;
        ant->sig = nuevo;
    }

}

void mostrarLista(TLista L){
    TLista aux=L;
    while (aux!=NULL){
        printf(". %d\n",aux->dato);
        aux=aux->sig;
    }
}
