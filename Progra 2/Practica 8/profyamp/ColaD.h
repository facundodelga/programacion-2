#include <stdio.h>
#include <stdlib.h>

typedef int TElementoC;

typedef struct nodoc {
    TElementoC dato;
    struct nodoc *sig;
}Nodoc;
typedef struct{
    Nodoc *pri,*ult;
}TCola;

void IniciaC (TCola * C);
int VaciaC (TCola C);
TElementoC consultaC (TCola C);
void sacaC (TCola *C, TElementoC* x);
void poneC (TCola *C, TElementoC x);
