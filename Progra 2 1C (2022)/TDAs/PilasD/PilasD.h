#include <stdio.h>
#include <stdlib.h>

typedef int TElementoP;

typedef struct nodo{
	TElementoP dato;
	struct nodo *sig;
} nodo;

typedef nodo *TPila;

void iniciaP (TPila *P ); //Devuelve en P una pila vac�a

int vaciaP (TPila P ); //Devuelve Verdadero si la pila P est� vac�a, y Falso en caso contrario

TElementoP consultaP (TPila P ); // Devuelve el valor del elemento que se encuentra en el tope de la pila P

void sacaP (TPila *P ,TElementoP *x ); //Devuelve en x el elemento que se encuentra en el tope de la pila removi�ndolo de P

void poneP(TPila *P ,TElementoP x ); //Inserta el elemento x en el tope de la pila.
