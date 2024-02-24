#include <stdio.h>
#include <stdlib.h>
#include "fraccion.h"

int main()
{
    fraccion F1,F2,suma;
    F1 = simplificar(crear(65,15));
    F2 = simplificar(crear(64,28));
    suma = simplificar(sumar(F1,F2));

    return 0;
}
