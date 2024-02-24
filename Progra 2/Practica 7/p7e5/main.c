#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char dato[20];
    struct nodo *izq,*der;
}nodo;

typedef nodo * arbol;

void insertaABB(arbol *, char *);
int profundidad(arbol);

int main(){
    arbol a = NULL;

    return 0;
}

void insertaABB(arbol *A, char x[]){
    if (*A == NULL) {
         *A = (arbol) malloc (sizeof (struct nodo));
         strcpy((*A)->dato,x);
         (*A)->der = NULL;
         (*A)->izq = NULL;
    }else
        if(strcmp((*A)->dato,x) < 0)
            insertaABB(&((*A)->der), x);
        else
            insertaABB(&((*A)->izq), x);
}

int profundidad(arbol a){
    int izq = 0, der = 0;
    if(a){
        izq = profundidad(a->izq) + 1;
        der = profundidad(a->der) + 1;
        if(der < izq)
            return izq;
        else
            return der;
    }else
        return 0;
}

void cadenaMasLarga(arbol a, int *longitud){
    if(a){
        cadenaMasLarga(a->izq,longitud);
        if(strlen(a->dato) > *longitud)
            *longitud = strlen(a->dato);
        cadenaMasLarga(a->der,longitud);
    }
}

int hijosDerechos(arbol a){
    if(a){
        if(a->der != NULL)
            return 1 + hijosDerechos(a->izq) + hijosDerechos(a->der);
        return hijosDerechos(a->izq);
    }else
        return 0;
}



