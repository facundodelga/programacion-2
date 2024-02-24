#include <stdio.h>
#include <stdlib.h>
#include "TDAej2.h"

void leerArchivo();

int main()
{
    TPila caracteres;
    leerArchivo(&caracteres);
    printf("x\n");
    mostrarP(&caracteres);
    return 0;
}

void leerArchivo(TPila *p){
    FILE *arch;
    TElementoP auxChar;
    arch=fopen("archivo.txt","r");
    while (!feof(arch)){
        fscanf(arch,"%c\n",&auxChar);
        //printf("%c\n",auxChar);
        poneP(p,auxChar);
        //printf("x");
    }
    fclose(arch);
}
