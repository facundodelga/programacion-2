#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int ej20(arbol a, int nivel){
    if(a){
        if(nivel % 2 != 0)
            return 1 + ej20(a->izq,nivel + 1) + ej20(a->der,nivel);
        return ej20(a->izq,nivel + 1) + ej20(a->der,nivel);
    }else
        return 0;
}
