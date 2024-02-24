#include <stdio.h>
#include <stdlib.h>

typedef int TElementoP;

typedef struct nodo{
	TElementoP dato;
	struct nodo *sig;
} nodo;

typedef nodo *TPila;

void iniciaP (TPila *P ); //Devuelve en P una pila vacía

int vaciaP (TPila P ); //Devuelve Verdadero si la pila P está vacía, y Falso en caso contrario

TElementoP consultaP (TPila P ); // Devuelve el valor del elemento que se encuentra en el tope de la pila P

void sacaP (TPila *P ,TElementoP *x ); //Devuelve en x el elemento que se encuentra en el tope de la pila removiéndolo de P

void poneP(TPila *P ,TElementoP x ); //Inserta el elemento x en el tope de la pila.
