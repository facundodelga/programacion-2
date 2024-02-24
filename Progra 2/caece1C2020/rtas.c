#include <stdio.h>
#include <stdlib.h>
#define DIM 30
typedef struct nodoA{
    int dato;
    struct nodoA *izq, *der;
} NodoA;

typedef NodoA* TArbol;

void addNodo(TArbol* A, int x);
void Descendente(TArbol A, int V[DIM], int nivelActual, int N, int *i);
int Ej3(int M[][3],int i, int j,int J,int gradoEntrada);

int main()
{
    int i=0,x;
    TArbol A;
    int V[DIM];
    //int Mat[][3]={{2,10,20},{0,0,10},{0,15,0}};

    addNodo(&A, 30);
    addNodo(&(A->izq), 10);
    addNodo(&(A->izq->der), 15);
    addNodo(&(A->der), 40);
    addNodo(&(A->der->der), 43);
    addNodo(&(A->der->izq), 35);
    addNodo(&(A->der->izq->der), 37);
    addNodo(&(A->der->der->izq), 41);
    addNodo(&(A->izq->izq),5);
    printf("\n*****\n");
    Descendente( A, V, 1, 3, &i);
    for(x=0;x<6;x++){
        printf("\n %d \n", V[x]);
    }

    //printf("\n %d \n",Ej3(Mat,2,2,2,0));
    return 0;
}

void addNodo(TArbol* A, int x){
    *A = (TArbol) malloc(sizeof(NodoA));
    (*A)->dato = x;
    (*A)->der = (*A)->izq = NULL;
}
//1) Dado un ABB generar un vector con las claves ubicadas en niveles mayores o iguales a N (N dato) ordenadas descendentemente
void Descendente(TArbol A, int V[DIM], int nivelActual, int N, int *i){
    if (A != NULL){
        Descendente(A->der,V,nivelActual+1,N,i);
        if (nivelActual >= N ){
            V[*i] = A->dato;
            *i = *i + 1;
        }
        Descendente(A->izq,V,nivelActual+1,N,i);
    }
}
