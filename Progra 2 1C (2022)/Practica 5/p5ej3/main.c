#include <stdio.h>
#include <stdlib.h>
#include "pilasEj1.h"
#include <string.h>
// Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
//los últimos N (es dato) votantes

TPila cargaPila();
void mostrarEnOrdenInverso();
void mostrarEnOrden();

int main()
{
    TPila p;
    int cantAMostrar=0;
    iniciaP(&p);

    p=cargaPila();

    scanf("%i",&cantAMostrar);

    mostrarEnOrdenInverso(&p,cantAMostrar);
    mostrarEnOrden(&p,cantAMostrar);
    p=NULL;
    return 0;
}

void mostrarEnOrdenInverso(TPila *p,int i){
    TElementoP aux;

    if (i>0 && !vaciaP(*p)){
        aux=(char *)malloc(11*sizeof(char));
        sacaP(p,&aux);
        printf("%s\n",aux);
        mostrarEnOrdenInverso(p,i-1);
        poneP(p,aux);
    }

}

void mostrarEnOrden(TPila *p,int i){
    TElementoP aux;
    if (i>0 && !vaciaP(*p)){
        aux=(char *)malloc(11*sizeof(char));
        sacaP(p,&aux);
        mostrarEnOrden(p,i-1);
        printf("%s\n",aux);
        poneP(p,aux);
    }
}

TPila cargaPila(){
    TPila pila;
    TElementoP dni;
    FILE *arch;


    dni=(char *)malloc(11*sizeof(char));

    arch=fopen("p5ej1.txt","r");

    while(!feof(arch)){
        fscanf(arch,"%s\n",dni);
        poneP(&pila,dni);
    }

    fclose(arch);

    return pila;
}
