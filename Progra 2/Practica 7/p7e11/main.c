#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}

int minimoABB(arbol a){
    if(a->izq == NULL)
        return a->dato;
    else
        return minimoABB(a->izq);

}
