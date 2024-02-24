#include <stdio.h>
#include <stdlib.h>
typedef char TElememtoA;
typedef struct nodo{
        TElememtoA dato;
        struct nodo *izq;
        struct nodo *der;
} NODO;

typedef NODO * arbol;

void addnodo(arbol* a, TElememtoA e);

int main(){
    arbol a;
    addnodo(&a,'a');
    addnodo(&a->izq,'b');
    addnodo(&a->izq->der,'i');
    addnodo(&a->izq->der->izq,'j');
    addnodo(&a->izq->der->der,'c');
    addnodo(&a->izq->der->der->izq,'f');
    addnodo(&a->izq->der->der->izq->der,'g');
    addnodo(&a->izq->der->der->der,'n');
    addnodo(&a->izq->izq,'d');
    addnodo(&a->izq->izq->der,'e');
    printf("altura: %d",ej22(a))
    return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int ej22(arbol a){
    int nivel = 0,aux;
    arbol b;
    if(a == NULL)
        return 0;
    else{
        b = a->izq;

        while(b){
            aux = ej22(b);
            if(aux > nivel)
                nivel = aux;
            b = b->der;
        }

        return aux + 1;
    }
}
