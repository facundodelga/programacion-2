#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

typedef struct nodito{
    int mesa;
    int comensales;
    struct nodito * sig;
}nodito;

typedef struct nodo{
    char Id[MAX];
    struct nodo* sig;
    nodito *subL;
}nodo;

typedef nodo *TLista;
typedef nodito *TSLista;

TLista creaNodo(char [],TSLista);
TSLista creaNodito(int,int);
void insertaSubL(TSLista *,int,int);
void insertaOrdL(TLista *,char [],TSLista);
void cargaLista(TLista *);
void BuscaMozoParaEliminarMesa(TLista *l,char Id[],int mesa);
void EliminaMesa(TSLista *l,int mesa);

int main()
{
    printf("Hello world!\n");
    return 0;
}


TLista creaNodo(char Id[],TSLista sL){
    TLista aux=NULL;

    aux = (TLista)malloc(sizeof(nodo));

    strcpy(aux->Id,Id);
    aux->subL=sL;
    aux->sig=NULL;

    return aux;

}

TSLista creaNodito(int mesa,int comensales){

    TSLista aux;

    aux = (TSLista)malloc(sizeof(nodito));

    aux->mesa=mesa;
    aux->comensales=comensales;
    aux->sig=NULL;

    return aux;

}

//void insertaSubL(TSLista *,int,int){




//}
void insertaOrdL(TLista *,char [],TSLista);
void cargaLista(TLista *);

void BuscaMozoParaEliminarMesa(TLista *l,char Id[],int mesa){
    TLista aux=*l,ant=NULL;

    if(strcmp(Id,(*l)->Id)==0){
        EliminaMesa(&(*l)->subL,mesa);
        if((*l)->subL==NULL){
            aux=*l;
            *l=(*l)->sig;
            free(aux);
        }
    }else{
        while(aux!=NULL && strcmp(aux->Id,Id)!=0){
           ant=aux;
           aux=aux->sig;
        }
        if(aux!=NULL){
            EliminaMesa(&aux->subL,mesa);
            if(aux->subL==NULL){
                ant->sig=aux->sig;
                free(aux);
            }
        }

    }
}

void EliminaMesa(TSLista *l,int mesa){

    TSLista auxSl=*l,ant=NULL;

    if(!(*l)){
        if((*l)->mesa==mesa){
            auxSl=*l;
            *l=(*l)->sig;
            free(auxSl);

        }else{
            while(auxSl!=NULL && auxSl->mesa!=mesa){
                ant=auxSl;
                auxSl=auxSl->sig;
            }
            if(auxSl!=NULL){
                ant->sig=auxSl->sig;
                free(auxSl);
            }
        }

    }

}
