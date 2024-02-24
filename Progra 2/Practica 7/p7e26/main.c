#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

void recorrido(arbol a, int k){
    int bandera = 1;
    while(a != NULL && bandera != 0){
        bandera = 0;
        verificoGrado(a,k,&bandera);
        a = a->der;
    }

    if(bandera = 0)
        printf("no todos los arboles tienen un nodo con grado %d",k);
    else
        printf("todos los arboles tienen un nodo con grado %d",k);
}

void verificoGrado(arbol a, int k, int *bandera){
    int grado;
    if(a != NULL && *bandera != 1){
        a = a->izq;
        grado = 0;
        while(a != NULL && grado <=k){
            verificoGrado(a->der,k,bandera);
            grado++;
            a = a->der;
        }
        if(grado == k)
            *bandera = 1;
    }
}
