#include <stdio.h>
#include <stdlib.h>
#include "PilasD.h"

void iniciaP (TPila *P) //Devuelve en P una pila vacía
{
    *P = NULL;			//NULL valor de referencia
}

int vaciaP (TPila P) //Devuelve Verdadero si la pila P está vacía, y Falso en caso contrario
{
    return (P == NULL); //analizo valor de referencia
}

TElementoP consultaP (TPila P) // Devuelve el valor del elemento que se encuentra en el tope de la pila P
{
    if ( !vaciaP(P) ) 	//si la pila no esta vacia
        return P->dato;	//devuelvo P PUNTERO a dato
}

void sacaP (TPila *P ,TElementoP *x) //Devuelve en x el elemento que se encuentra en el tope de la pila removiéndolo de P
{
    TPila aux;
	if ( !vaciaP(*P) ){ 
		aux = *P; //aux tiene el contenido de P
		*x = (*P)->dato; //el contenido de P PUNTERO a dato
		*P = (*P)->sig; //el contenido de P = *P PUNTERO a sig
		free(aux); //libero la memoria que contenia el nodo antiguo
	}
}
//usar aux en vez de (*P)?

void poneP(TPila *P ,TElementoP x) //Inserta el elemento x en el tope de la pila.
{
    TPila nuevo;
    nuevo = (TPila)malloc(sizeof (nodo));	//creo memoria para almacenar nodo
    nuevo->dato = x; 						//le paso al nodo nuevo el dato
    nuevo->sig = *P;						//le paso al nodo nuevo el nodo anterior
    *P = nuevo; 							//el contenido de P es igual al nodo nuevo
}
