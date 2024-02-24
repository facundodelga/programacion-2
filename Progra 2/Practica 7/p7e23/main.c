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
int ej23(arbol);
void ej23void(arbol,int *);

int main(){
    arbol a;
    addnodo(&a,'a');
    addnodo(&a->izq,'b');
    addnodo(&a->izq->der,'i');
    addnodo(&a->izq->der->izq,'j');
    addnodo(&a->izq->der->der,'c');
    addnodo(&a->izq->der->der->izq,'f');
    addnodo(&a->izq->der->der->izq->der,'g');
    addnodo(&a->izq->der->der->izq->der->der,'h');
    addnodo(&a->izq->der->der->izq->der->der->der,'s');
    addnodo(&a->izq->der->der->izq->der->der->der->der,'v');
    addnodo(&a->izq->der->der->izq->der->der->der->der->der,'w');
    addnodo(&a->izq->der->der->der,'n');
    addnodo(&a->izq->izq,'d');
    addnodo(&a->izq->izq->der,'e');
    addnodo(&a->izq->izq->der->der,'t');
    addnodo(&a->izq->izq->der->der->der,'p');
    printf("grado: %d",ej23(a));
//    int grado = 0;
//    ej23void(a,&grado);
//    printf("grado: %d",grado);

    return 0;

}

void addnodo(arbol* a, TElememtoA e) {
    *a = (arbol)malloc(sizeof(NODO));
    (*a)->dato = e;
    (*a)->izq = NULL;
    (*a)->der = NULL;
}

int ej23(arbol a){
    int aux,auxMax = -1,grado = 0;
    arbol b;
    if(a){
        b = a->izq;
        while(b){
            aux = ej23(b);
            if(aux > auxMax)
                auxMax = aux;
            grado++;
            b = b->der;
        }

        if(grado > auxMax)
            return grado;
        else
            return auxMax;
    }else
        return 0;
}

void ej23void(arbol a, int *maxGR){
    int grado;
    arbol aux;

    if(a){
        aux = a->izq;
        grado = 0;
        while(aux){
            ej23void(aux,maxGR);
            grado++;
            aux = aux->der;
        }

        if(grado > *maxGR)
            *maxGR = grado;
    }
}
