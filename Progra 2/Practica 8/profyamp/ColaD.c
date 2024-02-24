#include <stdio.h>
#include <stdlib.h>
#include "ColaD.h"

void IniciaC (TCola * C)
{
    C->pri=C->ult=NULL;
}
int VaciaC (TCola C)
{
    return ((C.pri)==NULL);
}
TElementoC consultaC (TCola C)
{
    return C.pri->dato;
}
void sacaC (TCola *C, TElementoC* x)
{
    Nodoc *aux;
    if (!VaciaC(*C)){
        aux=C->pri;
        *x=aux->dato;
        C->pri=C->pri->sig;
        free(aux);
    }
}
void poneC (TCola *C, TElementoC x)
{
    if (VaciaC(*C))
    {
        C->pri=C->ult=(Nodoc*)malloc(sizeof(Nodoc));
        C->pri->sig=NULL;
    }
    else
    {
        C->ult->sig=(Nodoc*)malloc(sizeof(Nodoc));
        C->ult=C->ult->sig;
        C->ult->sig=NULL;
    }
    C->ult->dato=x;
}
