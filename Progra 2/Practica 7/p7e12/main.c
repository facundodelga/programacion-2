#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}

void ej12(arbol A, int a, int b, int *cont){
    if(A){
        ej12(A->izq,a,b,cont);
        if(A->dato >= a && A->dato <= b)
            (*cont)++;


    }
}
