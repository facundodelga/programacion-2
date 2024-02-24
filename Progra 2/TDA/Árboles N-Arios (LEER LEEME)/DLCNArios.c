#include "DLCNArios.h"

void GenerarArbol24a(TArbolN* A)
{
    (*A).Max = 9;
    //
    (*A).Elementos[0].HijoIzq = 1;
    (*A).Elementos[0].dato = 0;
    (*A).Elementos[0].HermanoDer = 0;
    //
    (*A).Elementos[1].HijoIzq = 2;
    (*A).Elementos[1].dato = 1;
    (*A).Elementos[1].HermanoDer = -1;
    //
    (*A).Elementos[2].HijoIzq = 3;
    (*A).Elementos[2].dato = 3;
    (*A).Elementos[2].HermanoDer = -1;
    //
    (*A).Elementos[3].HijoIzq = 4;
    (*A).Elementos[3].dato = 1;
    (*A).Elementos[3].HermanoDer = 5;
    //
    (*A).Elementos[4].HijoIzq = -1;
    (*A).Elementos[4].dato = -4;
    (*A).Elementos[4].HermanoDer = -1;
    //
    (*A).Elementos[5].HijoIzq = -1;
    (*A).Elementos[5].dato = 7;
    (*A).Elementos[5].HermanoDer = 6;
    //
    (*A).Elementos[6].HijoIzq = 7;
    (*A).Elementos[6].dato = 2;
    (*A).Elementos[6].HermanoDer = -1;
    //
    (*A).Elementos[7].HijoIzq = 8;
    (*A).Elementos[7].dato = 1;
    (*A).Elementos[7].HermanoDer = 9;
    //
    (*A).Elementos[8].HijoIzq = -1;
    (*A).Elementos[8].dato = 5;
    (*A).Elementos[8].HermanoDer = -1;
    //
    (*A).Elementos[9].HijoIzq = -1;
    (*A).Elementos[9].dato = 123;
    (*A).Elementos[9].HermanoDer = -1;
}

void GenerarArbol24b(TArbolN* A)
{
    (*A).Max = 9;
    //
    (*A).Elementos[0].HijoIzq = 1;
    (*A).Elementos[0].dato = 0;
    (*A).Elementos[0].HermanoDer = 0;
    //
    (*A).Elementos[1].HijoIzq = 2;
    (*A).Elementos[1].dato = 1;
    (*A).Elementos[1].HermanoDer = -1;
    //
    (*A).Elementos[2].HijoIzq = 3;
    (*A).Elementos[2].dato = 3;
    (*A).Elementos[2].HermanoDer = -1;
    //
    (*A).Elementos[3].HijoIzq = 4;
    (*A).Elementos[3].dato = 1;
    (*A).Elementos[3].HermanoDer = 5;
    //
    (*A).Elementos[4].HijoIzq = -1;
    (*A).Elementos[4].dato = -4;
    (*A).Elementos[4].HermanoDer = -1;
    //
    (*A).Elementos[5].HijoIzq = -1;
    (*A).Elementos[5].dato = 7;
    (*A).Elementos[5].HermanoDer = 6;
    //
    (*A).Elementos[6].HijoIzq = 7;
    (*A).Elementos[6].dato = 4;
    (*A).Elementos[6].HermanoDer = -1;
    //
    (*A).Elementos[7].HijoIzq = 8;
    (*A).Elementos[7].dato = 1;
    (*A).Elementos[7].HermanoDer = 9;
    //
    (*A).Elementos[8].HijoIzq = -1;
    (*A).Elementos[8].dato = 5;
    (*A).Elementos[8].HermanoDer = -1;
    //
    (*A).Elementos[9].HijoIzq = -1;
    (*A).Elementos[9].dato = 123;
    (*A).Elementos[9].HermanoDer = -1;
}
