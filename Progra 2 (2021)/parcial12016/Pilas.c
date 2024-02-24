#include <stdio.h>
#include <stdlib.h>
#include "Pilas.h"

void IniciaP(TPila *P)
{
    (*P).tope=-1;
}

int VaciaP(TPila P)
{
    return (P.tope==-1);
}

TElementoP ConsultaP(TPila P)
{
   if ( (P.tope)!=1)
     return P.datos[P.tope];
}

void SacaP(TPila *P,TElementoP *x)
{
    if ( ((*P).tope)!=-1 )
    {
      *x=(*P).datos[(*P).tope];
     (*P).tope--;
    }
}

void PoneP(TPila *P,TElementoP x)
{
    if ( ((*P).tope)!=49 )
    {
      (*P).tope++;
      (*P).datos[(*P).tope]=x;
    }
}
