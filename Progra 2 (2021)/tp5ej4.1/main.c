#include <stdio.h>
#include <stdlib.h>
#include "colasTp5Ej4.1.h"

void cargarCola();
void mostrarCola();

int main()
{
    TCola c;
    iniciaC(&c);
    cargarCola(&c);
    mostrarCola(&c);
    return 0;
}

void cargarCola(TCola *c){
    FILE *arch;
    int *num=(int *)malloc(sizeof(int));
    arch=fopen("archivo.txt","r");

    while (!feof(arch)){
        fscanf(arch,"%d\n",num);
        poneC(c,*num);
        //printf("%d\n",*num);
    }

    fclose(arch);
}

void mostrarCola(TCola *c){
    int *x=(int *)malloc(sizeof(int));
    TCola aux;
    iniciaC(&aux);
    while (!vaciaC(*c)){
        sacaC(c,x);
        printf("%d <==",*x);
        poneC(&aux,*x);
    }
    printf("\n");
    printf("regresando datos\n");
    while (!vaciaC(aux)){
        sacaC(&aux,x);
        poneC(c,*x);
    }
}
