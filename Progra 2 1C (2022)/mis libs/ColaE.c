#include <stdio.h>
#include <stdlib.h>
#include "ColaE.h"

void IniciaC (TCola * C)
{
    C->pri=C->ult=-1;
}
int VaciaC (TCola C)
{
    return ((C.pri)==-1);
}
TElementoC consultaC (TCola C)
{
    if (!VaciaC(C))
        return (C.datos[C.pri]);
}
void sacaC (TCola *C, TElementoC* x)
{
    if (!VaciaC(*C)){
        *x=C->datos[(C->pri)];
        if ((*C).pri==(*C).ult)
            IniciaC(C);
        else
            C->pri+=1;
    }
}
void poneC (TCola *C, TElementoC x)
{
    if (C->ult!=(N-1))
    {
        if (C->pri==-1)
            C->pri=0;
    (C)->datos[++(C->ult)]=x;
    }
}
