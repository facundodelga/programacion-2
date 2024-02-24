#include <stdio.h>
#include <stdlib.h>
#define dim 50

typedef int TElementoP;

typedef struct {
	TElementoP datos[dim];
	int tope;
}TPila;

void iniciaP(TPila *P);

int vaciaP(TPila P);

TElementoP consultaP(TPila P);

void sacaP(TPila *P,TElementoP *x);

void poneP(TPila *P,TElementoP x);



