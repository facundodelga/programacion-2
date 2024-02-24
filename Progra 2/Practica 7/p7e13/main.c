#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}

void ej13(arbol a, int v[],int *validos){
    if(a){
        ej13(a->izq,v,validos);
        v[*validos] = a->dato;
        (*validos)++;
        ej13(a->der,v,validos);
    }
}
