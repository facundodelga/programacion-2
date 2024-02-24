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
    addnodo(&a->der,'k');
    addnodo(&a->der->izq,'q');
    addnodo(&a->der->izq->izq,'r');
    addnodo(&a->der->izq->izq->der,'s');
    addnodo(&a->der->izq->izq->der->izq,'t');
    addnodo(&a->der,'k');
    addnodo(&a->der->izq,'k');
    addnodo(&a->izq,'b');
    addnodo(&a->izq->der,'i');
    addnodo(&a->izq->der->izq,'j');
    addnodo(&a->izq->der->der,'c');
    addnodo(&a->izq->der->der->izq,'f');
    addnodo(&a->izq->der->der->izq->der,'g');
    addnodo(&a->izq->der->der->der,'n');
    addnodo(&a->izq->izq,'d');
    addnodo(&a->izq->izq->der,'e');
    printf("cant arboles con altura 2: %d",ej24(a,2,1));
    return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}
int ej24(arbol a, int k,int nivel){

    if(a){
        if(nivel == 0){
            return ej24(a->izq,k,nivel + 1) + ej24(a->der,k,1);
        }else{
            if(nivel < k)
                return ej24(a->izq,k,nivel + 1) + ej24(a->der,k,nivel);
            else
                return 1;
        }
    }else
        return 0;

}
