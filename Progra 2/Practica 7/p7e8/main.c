#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Hello world!\n");
    return 0;
}

void ej8a(arbol a){ //el nombre del ganador.
    if(a)
        printf("%s\n",a->dato);
}

void ej8a(arbol a){ //los nombres de los 2 finalistas.
    if(a)
        printf("%s vs. %s\n",a->izq->dato,a->der->dato);
}
