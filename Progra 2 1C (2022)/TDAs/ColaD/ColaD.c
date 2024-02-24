#include <stdio.h>
#include <stdlib.h>
#include "ColaD.h"

void iniciaC (TCola * C)
{
    C->pri = C->ult = NULL;		//valor de referencia NULL
}

int vaciaC (TCola C)
{
    return C.pri == NULL;		//analizo valor de referencia
}

TElementoC consultaC (TCola C)
{
    if ( !vaciaC(C) )			//si la cola no esta vaciaC
        return C.pri->dato;		//devuelvo el dato que apunta el pri
}

void sacaC (TCola *C, TElementoC* x)
{
    nodo *elim;
    if ( !vaciaC(*C) ){			//si no esta vacia
        elim = C->pri;			//guardo la pos a eliminar
        *x = elim->dato;		//guardo el dato a eliminar
        C->pri = C->pri->sig;	//el 1ro es el siguiente
		if ( C->pri == NULL)	//si saqué el único
			C->ult = NULL;		//el ultimo apunta NULL
        free(elim);				//libero memoria
    }
}
CASO PARTICULAR ELIMINO UNICO


void poneC (TCola *C, TElementoC X)
{
	nodo * nuevo;
	nuevo = (nodo *) malloc (sizeof(nodo));
	nuevo->dato = X;
	nuevo->sig = NULL;
	if ( vaciaC(*C) )			//si la cola esta vacia
		C->pri = nuevo;			//el primero es el nuevo
	else						//si la cola no esta vacia
		C->ult->sig = nuevo;	//el sig del ult es el nuevo
	C->ult = nuevo; 			//siempre el q llega a la cola va al final
}
2 CASOS: COLA VACIA Y COLA CON ELEMENTOS

/*void poneC (TCola *C, TElementoC x)
{
    if (vaciaC(*C)){
        C->pri = C->ult=(Nodoc*)malloc(sizeof(Nodoc));
        C->pri->sig = NULL;
    }
    else{
        C->ult->sig = (Nodoc*)malloc(sizeof(Nodoc));
        C->ult = C->ult->sig;
        C->ult->sig = NULL;
    }
    C->ult->dato = x;
}*/