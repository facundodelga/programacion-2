#include <stdio.h>
#include <stdlib.h>
#include "ColaE.h"

void iniciaC (TCola * C)
{
    C->pri = C->ult = -1;		//-1 es valor de referencia
}

int vaciaC (TCola C)
{
    return C.pri == -1;			//si la cola esta en los valores iniciales, esta vacía
}

TElementoC consultaC (TCola C)
{
    if (!vaciaC(C))					//si la pila no esta vacia
        return C.datos[C.pri];		//devuelve el dato que esta al principio
}

void sacaC (TCola *C, TElementoC* x)
{
    if ( !vaciaC(*C) ){					
        *x = C->datos[(C->pri)];		//le otorga a x el dato que está primero
        if (C->pri == C->ult)			//si es el unico dato en la cola
            iniciaC(C);					//la inicializo
        else							//si hay mas datos
            C->pri++;					//el primero pasa a ser el siguiente
    }
}
2 CASOS: UNICO ELEMENTO - VARIOS ELEMENTOS

void poneC (TCola *C, TElementoC x)
{
    if (C->ult < N-1){					//si la cola no está llena
        if (vaciaC(*C))				//si la cola está vacía
            C->pri = 0;					//le doy al nuevo el primero
		(C->ult)++;						
		(C)->datos[(C->ult)] = x;		//SIEMPRE el nuevo es el último y va en la posicion que le sigue al anterior ult 
    }
}
CASO PARTICULAR SI LA COLA ESTA VACIA
