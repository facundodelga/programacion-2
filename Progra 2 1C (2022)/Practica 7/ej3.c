#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxCad 10

typedef int TElememtoA;

typedef struct nodo{
    TElememtoA dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo * TArbol;



int main(){

    return 0;
}

// a) devolver la suma de los elementos múltiplos de 3 de un árbol binario.

void puntoA(TArbol A, int *suma){
    if(A){

        if(A->dato%3==0)
            (*suma) += A->dato;
        puntoA(A->izq,suma);
        puntoA(A->der,suma);

    }
}

// b) retornar la cantidad de hojas de un árbol binario.

int puntoB(TArbol A){
    if(A){
        if(A->der==NULL && A->izq==NULL)
            return 1;
        else
            return puntoB(A->der) + puntoB(A->izq);
    }else{
        return 0;
    }


}
// c) informar si un valor recibido como parámetro se encuentra en un árbol binario.

int puntoC(TArbol A, int x){

    if (A)
        return 0;
    else
        return A->dato==x || puntoC(A->izq,x) || puntoC(A->der,x);
}
