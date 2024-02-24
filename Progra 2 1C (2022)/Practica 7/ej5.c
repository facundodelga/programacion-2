#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxCad 10

typedef struct nodob{
    char cad[maxCad];
    struct nodob *izq,*der;
}nodob;

typedef nodob * TArbolB;


int main(){

    return 0;
}

// a) calcular la profundidad de un árbol binario.


void puntoA(TArbolB B,int i,int *prof){
    if(B){
        puntoA(B->izq,i+1,prof);
        puntoA(B->der,i+1,prof);
        if(i>*prof)
            *prof = i;
    }

}


// b) retornar la longitud de la cadena más larga de un árbol binario de cadenas




void puntoB(TArbolB B, int *longitud){

    if(B){
        if(*longitud < strlen(B->cad))
            *longitud = strlen(B->cad);

        puntoB(B->izq,longitud);
        puntoB(B->der,longitud);
    }

}

// c) devolver la cantidad de hijos derechos que contiene un árbol binario


void puntoC(TArbolB B, int *hijosDer){
    if(B){

        puntoC(B->izq,hijosDer);
        if(B->der)
            (*hijosDer)++;
        puntoC(B->der,hijosDer);

    }
}
