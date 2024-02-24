#include <stdio.h>
#include <stdlib.h>
#include "PilaD.h"

void IniciaP (TPila * P)
{
    *P=NULL;
}
void poneP (TPila *P, TElementoP x)
{
    TPila N;
    N=(TPila)malloc(sizeof(nodop));
    N->dato=x;
    N->sig=*P;
    *P=N;
}
void sacaP (TPila * P, TElementoP * x)
{
    TPila N;
    if (!VaciaP(*P))
        N=*P;
        *x=(*P)->dato;
        *P=(*P)->sig;
        free(N);
}
TElementoP consultaP(TPila P)
{
    if (!VaciaP(P))
        return P->dato;
}
int VaciaP (TPila P)
{
    return (P==NULL);
}
