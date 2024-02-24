#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

int ej7(arbol a, int nivel, int x){
    if(a && nivel <= x){
        if((a->izq == NULL && a->der != NULL || a->izq != NULL && a->der == NULL) && nivel == x)
            return a->dato + ej7(a->izq,nivel+1,x) + ej7(a->der,nive+1,x);
        return ej7(a->izq,nivel+1,x) + ej7(a->der,nive+1,x);
    }else
        return 0;


}
