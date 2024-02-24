
#include <stdio.h>
#include <stdlib.h>
#include "pilaE.h"


void IniciaP (TPila * P){
    P->tope=-1;
}

void poneP (TPila * P, TElementoP x){
	if ((*P).tope!=(N-1))
		P->datos[++(P->tope)]=x;
}

void sacaP (TPila * P, TElementoP * x){
    if (!VaciaP(*P))
        *x=P->datos[(P->tope)--];
}

TElementoP consultaP(TPila P){
    if (!VaciaP(P))
        return P.datos[P.tope];
}

int VaciaP (TPila P){
    return (P.tope==-1);
}
