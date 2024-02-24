#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct nodo{
    char dato[MAX];
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct nodoD {
    char dato[MAX];
    struct nodoD *ant, * sig;
}nodoD;

typedef nodoD * PnodoD;

typedef struct {
 PnodoD pri, ult;} TListaD;

void cargaL(TLista *);
void muestraL(TLista);
void cargaLD(TLista ,TListaD *);
void cargaLC(TLista ,TLista *);
void muestraLD(TListaD );
void muestraLC(TLista );

int main(){
    TLista l=NULL,lc=NULL;
    TListaD ld;

    cargaL(&l);
    cargaLD(l,&ld);
    //muestraLD(ld);
    cargaLC(l,&lc);
    muestraLC(lc);


    return 0;
}

void cargaL(TLista *l){
    TLista aux=NULL,act,ant;
    FILE *arch;
    char st[MAX];

    arch = fopen("p6e9.txt","r");

    fscanf(arch,"%s\n",st);

    aux = (TLista)malloc(sizeof(nodo));
    strcpy(aux->dato,st);
    aux->sig = *l;
    *l = aux;

    while(fscanf(arch,"%s\n",st) == 1){
        aux = (TLista)malloc(sizeof(nodo));
        strcpy(aux->dato,st);

        if(strcmp(st,(*l)->dato) < 0){
            aux->sig = *l;
            *l = aux;
        }else{
            act = *l;

            while(act != NULL && strcmp(st,act->dato) >= 0){
                ant = act;

                act = act->sig;
            }
            ant->sig = aux;
            aux->sig = act;
        }

    }

}

void cargaLD(TLista l,TListaD *LD){
    TLista aux = l;
    PnodoD nuevo,act;
    LD->pri = NULL;
    LD->ult = NULL;
    while(aux){
        nuevo = (PnodoD)malloc(sizeof(nodoD));
        strcpy(nuevo->dato,aux->dato);
        printf("%s\n",aux->dato);
        if(LD->pri == NULL || strcmp(nuevo->dato,LD->pri->dato) < 0){
            nuevo->sig = LD->pri;
            nuevo->ant = NULL;

            if(LD->pri == NULL)
                LD->ult = nuevo;
            else
                LD->pri->ant = nuevo;
            LD->pri = nuevo;
        }else
            if(strcmp(LD->ult->dato,aux->dato) <= 0){
                nuevo->ant = LD->ult;
                nuevo->sig = NULL;
                LD->ult->sig = nuevo;
                LD->ult = nuevo;
            }else{
                act = LD->pri;

                while(strcmp(act->dato,aux->dato) <= 0)
                    act = act->sig;

                nuevo->sig = act;
                nuevo->ant = act->ant;
                act->ant->sig = nuevo;
                act->ant = nuevo;
            }
        aux = aux->sig;

    }

}

void cargaLC(TLista l,TLista *LC){
    TLista aux = l,nuevo,ant,act;

    while(aux){
        nuevo = (TLista)malloc(sizeof(nodo));
        strcpy(nuevo->dato,aux->dato);

        if(*LC == NULL){
            *LC = nuevo;
            nuevo->sig = nuevo;

        }else{
            if(strcmp(aux->dato,(*LC)->dato) >= 0){
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = nuevo;
                *LC = nuevo;
            }else{
                ant = *LC;
                act = (*LC)->sig;

                while(strcmp(act->dato,(*LC)->dato) >= 0){
                    ant = act;
                    act = act->sig;
                }

                ant->sig = nuevo;
                nuevo->sig = aux;

            }

        }
        aux = aux->sig;
    }

}

void muestraLD(TListaD l){
    PnodoD aux = l.pri;

    while(aux){
        printf("[ %s ] ",aux->dato);
        aux = aux->sig;
    }
    printf("\n");

}

void muestraLC(TLista LC){
    TLista aux = LC->sig;

    if(aux){
        do{
            printf("[ %s ] ",aux->dato);
            aux = aux->sig;
        }while(aux != LC->sig);

        printf("\n");

    }

}


