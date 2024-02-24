#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

int ABB(arbol a){
    if(a == NULL)
        return 1;
    else
        if(((a->izq == NULL) || a->izq->dato < a->dato) && ((a->der == NULL) && a->der->dato > a->dato))
            return ABB(a->izq) && ABB(a->der);
        return 0;
}
