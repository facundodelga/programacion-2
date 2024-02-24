#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct nodo{
    char dato[MAX];
    int ocurrencias;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void cargaL(TLista *);
void muestraL(TLista);

int main(){
    TLista l = NULL;
    cargaL(&l);
    muestraL(l);
    return 0;
}

void cargaL(TLista *l){
    TLista aux=NULL,act,ant;
    FILE *arch;
    char st[MAX];
    arch = fopen("p6e3.txt","r");
    fscanf(arch,"%s\n",st);
    aux = (TLista)malloc(sizeof(nodo));
    strcpy(aux->dato,st);
    aux->ocurrencias = 1;
    aux->sig = *l;
    *l = aux;
    while(fscanf(arch,"%s\n",st) == 1){
        aux = (TLista)malloc(sizeof(nodo));

        if(strcmp(st,(*l)->dato) < 0){
            strcpy(aux->dato,st);
            aux->ocurrencias = 1;
            aux->sig = *l;
            *l = aux;
        }else{
            act = *l;

            while(act != NULL && strcmp(st,act->dato) > 0){
                ant = act;
                act = act->sig;
            }

            if(act == NULL || strcmp(st,act->dato) != 0){
                strcpy(aux->dato,st);
                aux->ocurrencias = 1;
                ant->sig = aux;
                aux->sig = act;
            }else
                act->ocurrencias += 1;

        }

    }

}


void muestraL(TLista l){
    TLista aux = l;
    while(aux != NULL){
        printf("%s ocurrencias: %d\n",aux->dato,aux->ocurrencias);
        aux = aux->sig;
    }


}
