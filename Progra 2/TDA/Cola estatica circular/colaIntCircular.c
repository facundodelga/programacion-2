#include "colaIntCircular.h"
#include <stdlib.h>

void iniciaC(TCola *c)
{
    c->pri = c->ult = -1;
}

void poneC(TCola *c, TElementoC x)
{
    if (vaciaC(*c))
    {
        c->pri = c->ult = 0;
        c->datos[c->ult] = x;
    }
    else
        if (c->ult < N-1)
        {
            if (c->ult != (c->pri - 1))
                c->datos[++(c->ult)] = x;
        }
        else
            if (c->pri != 0)
            {
                c->ult = 0;
                c->datos[c->ult] = x;
            }
}

void sacaC(TCola *c, TElementoC *x)
{
    if (!vaciaC(*c))
    {
        *x = c->datos[c->pri];
        if (c->pri != c->ult)
            if (c->pri < N-1)
                (c->pri)++;
            else
                c->pri = 0;
        else
            iniciaC(c);
    }
}

TElementoC consultaC(TCola c)
{
    if (!vaciaC(c))
        return c.datos[c.pri];
}

int vaciaC(TCola c)
{
    return c.pri == -1;
}
