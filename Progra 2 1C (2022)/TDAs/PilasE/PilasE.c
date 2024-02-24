#include <stdio.h>
#include <stdlib.h>
#include "PilasE.h"

void iniciaP(TPila *P)
{
    P->tope = -1;			//-1 valor referencia
}

int vaciaP(TPila P)
{
    return (P.tope == -1);		//analizo referencia
}

TElementoP consultaP(TPila P)
{
    if ( !vaciaP(P) )			//si no esta vacia
        return P.datos[P.tope];	//reviso el vector en la pos del tope
}

void sacaP(TPila *P,TElementoP *x)
{
    if ( !vaciaP(*P) ){			//si no esta vacia
        *x = P->datos[P->tope];	//le doy el elemento del tope
        P->tope--;				//el tope pasa a la pos anterior
    }
}

void poneP(TPila *P, TElementoP x) {
	if ( (P->tope) < (dim-1)){	//si el vector no esta lleno
		P->tope++;				//aumento el valor del tope
		P->datos[P->tope] = x;	//le doy en la nueva pos el valor
	}
}

/*void poneP(TPila *P,TElementoP x)
{
    P->tope++;
    P->datos[P->tope]=x;
}*/






