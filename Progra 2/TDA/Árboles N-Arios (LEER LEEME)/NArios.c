#include "NArios.h"
#include <stdlib.h>

int Vacio(TArbolN A)
{
    return (A.Elementos[0].HijoIzq == -1);
}

int Nulo(TPos p, TArbolN A)
{
    return ((p > A.Max) || (p == -1));
}

TPos HijoMasIzq(TPos p, TArbolN A)
{
    return A.Elementos[p].HijoIzq;
}

TPos HnoDer(TPos p, TArbolN A)
{
    return A.Elementos[p].HermanoDer;
}

TElementoAN Info(TPos p, TArbolN A)
{
    return A.Elementos[p].dato;
}

TPos Raiz(TArbolN A)
{
    return A.Elementos[0].HijoIzq;
}

TPos Padre(TPos p, TArbolN A)
{
    int i = 1;
    while ((i <= A.Max) && (A.Elementos[i].HijoIzq != p) && (A.Elementos[i].HermanoDer != p))
        i++;
    if (i > A.Max)
        return -1;
    else
        if (A.Elementos[i].HijoIzq == p)
            return i;
        else
            return Padre(i, A);
}
