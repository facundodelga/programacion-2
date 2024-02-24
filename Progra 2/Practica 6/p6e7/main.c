#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 27
typedef struct nodito{
    char titulo[30];
    char autor[20];
    int edicion;
    struct nodito *sig;
}nodito;

typedef nodito *subLista;

typedef struct nodoA{
    char autor;
    subLista subL;
    struct nodoA *sig;
}nodoA;

typedef nodoA *TListaA;

typedef struct{
    char
}

typedef struct nodoS{
    char socio[20];
    subLista subL;
    struct nodoS *sig;
}nodoS;

typedef nodoS *TListaS;

void cargaListaA(TListaA *);

int main(){


    return 0;
}

void cargaListaA(TListaA *l){
    FILE *arch;
    TListaA nuevo,aux;
    subLista nuevos;
    char titulo[30];
    char autor[20],contASCII = 'Z';
    int edicion;

    arch = fopen("Libros.txt","r");
    aux = *l;
    while(fscanf(arch,"%s %s %d\n",titulo,autor,&edicion)){
        while(aux != NULL && autor[0] != aux->autor)
            aux = aux->sig;
        if(aux->subL == NULL || strcmp(aux->subL->autor,autor) > 0){

        }

    }


    fclose(arch);





}







