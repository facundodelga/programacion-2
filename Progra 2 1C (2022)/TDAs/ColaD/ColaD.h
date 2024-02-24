#include <stdio.h>
#include <stdlib.h>

typedef int TElementoC;

typedef struct nodo {
    TElementoC dato;
    struct nodo *sig;
}nodo;

typedef struct{
    nodo *pri,*ult;
}TCola;

void iniciaC (TCola *C);

int vaciaC (TCola C);

TElementoC consultaC (TCola C);

void sacaC (TCola *C, TElementoC *x);

void poneC (TCola *C, TElementoC x);

