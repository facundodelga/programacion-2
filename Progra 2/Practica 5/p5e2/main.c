#include <stdio.h>
#include <stdlib.h>
#include "pilaE.h"

void cargaP(TPila *p);
void mostrarP(TPila *p);

int main()
{
    TPila p;
    cargaP(&p);
    mostrarP(&p);
    return 0;
}

void cargaP(TPila *p){
    char c;
    FILE *arch;

    IniciaP(p);

    arch = fopen("p1e2.txt","r");
    while(fscanf(arch,"%c\n",&c) == 1)
        poneP(p,c);

    fclose(arch);
}

void mostrarP(TPila *p){
    TPila aux;
    char c;

    while(!VaciaP(*p)){
        sacaP(p,&c);
        printf("%c",c);
        poneP(&aux,c);
    }

    while(!VaciaP(aux)){
        sacaP(&aux,&c);
        poneP(p,c);
    }

}
