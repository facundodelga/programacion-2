#include <stdlib.h>
#include "ColaC.h"

void iniciaC(TCola *c)
{
    c->pri = c->ult = -1;		//-1 es valor de referencia
}

int vaciaC(TCola c)
{
    return c.pri == -1;			//analizo valor de referencia
}

TElementoC consultaC(TCola c)
{
    if (!vaciaC(c))					//si la pila no esta vacia
        return c.datos[c.pri];		//devuelve el dato que esta al principio
}

void sacaC(TCola *c, TElementoC *x)
{
    if (!vaciaC(*c)){
        *x = c->datos[c->pri];	//SIEMPRE saco el dato que esta en pri
        if (c->pri == c->ult)	//si  es el unico elemento
			iniciaC(c);			//inicializo la cola porque queda vacia
		else					//si hay mas de uno 
            if (c->pri < N-1)	//si no me caigo de arreglo (el primero no se encuentra en la ultima posicion)
                (c->pri)++;		//el primero pasa a ser el siguiente
            else				//el dato que estoy sacando esta en la ultima posicion
                c->pri = 0;		//el primero pasa a ser el que esta en la primer posicion
    }
}
3 CASOS: UNICO ELEMENTO - SACO DEL MEDIO - SACO DEL FINAL

void poneC (TCola *c, TElementoC x) {
	if ( !( c->ult == N-1 && c->pri == 0 || c->ult+1 == c->pri ) ) {		//esta llena si el ultimo es 49 y el pri es cero O si el pri y el ult estan separados por 1
		if (vaciaC(*c)){			//la cola esta vacia
			c->pri = 0;					//el primero y el ultimo son 0 xq solo hay un elemento
			c->ult = 0;
		}
		else						//si la cola no esta vacia
			if (c->ult == N-1)			//si el lugar esta al principio
				c->ult = 0;					//el nuevo se ubica en la primer posicion 
			else						//el lugar esta en cualquier espacio
				c->ult++;					//el nuevo se ubica siguiente al anterior ultimo
		(c)->datos[c->ult] = x;		//SIEMPRE el nuevo es el ultimo
	}
}
3 CASOS: ESTA VACIA - PONGO EN EL MEDIO - PONGO AL PRINCIPIO
//le digo yo en que posicion esta el primero y en cual el ultimo
//
/*COLA CIRCULAR: CUANDO UN INDICE LLEGA A OCUPAR LA ULTIMA POSICION
Y HAY LUGARES LIBRES AL COMIENZO LOS HAGO CIRCULAR
PERO QUE CIRCULO?
EL ULTIMO CUANDO PONGO
EL PRIMERO CUANDO SACO
*/
/*void poneC(TCola *c, TElementoC x)
{
    if (vaciaC(*c)){
        c->pri = c->ult = 0;
        c->datos[c->ult] = x;
    }
    else
        if (c->ult < N-1){
            if (c->ult != (c->pri - 1))
                c->datos[++(c->ult)] = x;
        }
        else
            if (c->pri != 0){
                c->ult = 0;
                c->datos[c->ult] = x;
            }
}*/

