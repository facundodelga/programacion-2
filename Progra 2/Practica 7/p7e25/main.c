#include <stdio.h>
#include <stdlib.h>
typedef int TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;
typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);
void buscaMax(arbol a,int *max);
int main(){
    arbol a;

    addnodo(&a, 5);
    addnodo(&a->izq, 8);
    addnodo(&a->izq->izq, 3);
    addnodo(&a->izq->der, 6);
    addnodo(&a->der, 4);
    addnodo(&a->der->izq, 1);
    addnodo(&a->der->izq->der, 2);

    return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

void ej25(arbol a,int v[],int *validos){
    *validos = 0;
    while(a){
        v[*validos] = a->dato;
        buscaMax(a,&v[*validos]);
        *validos += 1;
        a = a->der;
    }
}

void buscaMax(arbol a,int *max){
    if(a){
        if(*max < a->dato)
            *max = a->dato;
        buscaMax(a->izq,max);
        buscaMax(a->der,max);
    }
}
