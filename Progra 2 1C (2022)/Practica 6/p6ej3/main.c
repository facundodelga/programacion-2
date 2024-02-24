#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 18

typedef struct nodo{
    char dato[MAX];
    int frecuencia;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

void cargaLista(TLista *);
TLista creaNodo(char s[]);
void muestraLista(TLista l);
void insertaOrd(TLista *l,char s[]);

int main()
{
    TLista lista=NULL;
    cargaLista(&lista);
    muestraLista(lista);
    free(lista);
    return 0;
}

TLista creaNodo(char s[]){
    TLista aux;
    aux=(TLista)malloc(sizeof(nodo));

    strcpy(aux->dato,s);
    aux->sig = NULL;

    return aux;
}

void insertaOrd(TLista *l,char s[]){
    TLista act=*l,nuevo=NULL,ant=NULL;

    if (*l==NULL || strcmp(s,(*l)->dato)<0){        // s < l->dato

        nuevo=creaNodo(s);
        nuevo->frecuencia=1;
        nuevo->sig=*l;
        *l=nuevo;

    }else{

        while(act!=NULL && strcmp(s,act->dato) > 0){  // s >= l->dato
            ant=act;
            act=act->sig;
        }

        if (act==NULL || strcmp(s,act->dato) < 0){

                nuevo=creaNodo(s);
                nuevo->frecuencia=1;
                nuevo->sig=act;
                ant->sig=nuevo;

        }else{          // s == act->dato

            act->frecuencia +=1;

        }

    }
}

void cargaLista(TLista *l){
    FILE *arch;
    char cad[MAX];
    TLista aux=NULL;

    arch=fopen("p6ej3.txt","r");
    while (!feof(arch)){
        fscanf(arch,"%s\n",cad);
        insertaOrd(&aux,cad);
    }
    *l=aux;
    fclose(arch);
}


void muestraLista(TLista l){
    TLista aux=l;

    while (aux!=NULL){
        printf("%s      frecuencia: %i\n",aux->dato,aux->frecuencia);
        aux=aux->sig;
    }
}

