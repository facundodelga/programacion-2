#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>
typedef struct nodito{
    int nroMesa,cantCome;
    struct nodito *sig;
}nodito;

typedef nodito *TsubL;

typedef struct nodo{
    char mozo[6];
    TsubL subL;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void GeneraPila(TPila *,int );
void eliminaPila(TPila *,TElementoP , int *);
void MuestraPila(TPila *);
void GeneraLista(TLista *);
void cierraMesa(TLista *,char *,int);
void ListaFinal(TLista );
void muestraLista(TLista );

int main(){
    TPila p;
    //TElementoP x;
    TLista l = NULL;
    int contEliminados;
    GeneraPila(&p,20);
    MuestraPila(&p);
    printf("\n");
    eliminaPila(&p,1,&contEliminados);
    MuestraPila(&p);
    printf("cantidad de elementos eliminados: %d\n",contEliminados);

    GeneraLista(&l);
    muestraLista(l);
    cierraMesa(&l,"Alejo",77);
    muestraLista(l);
    ListaFinal(l);

    return 0;
}

void GeneraPila(TPila* p,int n){
    int i;
    IniciaP(p);
    for (i=0; i<n; i++)
        poneP(p, (TElementoP)rand()%10);
}

void eliminaPila(TPila *p,TElementoP x, int *contador){
    TElementoP tp;
    if(VaciaP(*p)){
        *contador = 0;
    }else{
        sacaP(p,&tp);
        eliminaPila(p,x,contador);

        if(tp != x)
            poneP(p,tp);
        else
            *contador += 1;
    }
}

void MuestraPila(TPila* p){
    TElementoP aux;
    if (!VaciaP(*p)){
        sacaP(p, &aux);
        MuestraPila(p);
        printf("[ %d ]\n",aux);
        poneP(p, aux);
    }
}


void GeneraLista(TLista* lista){
    FILE *Arch;
    TLista auxL;
    TsubL act, auxS;
    int cantMesas, i;
    *lista = NULL;
    Arch = fopen("Mozos.txt","rt");
    if (Arch == NULL)
        printf("No se encontró el archivo Mozos.txt\n");
    else{
        while (!feof(Arch)){
            act = NULL;
            auxL = (TLista) malloc(sizeof(nodo));
            auxL->subL = NULL;
            fscanf(Arch," %s %d",auxL->mozo,&cantMesas);
            for (i=0;i<cantMesas;i++){
                auxS = (TsubL) malloc(sizeof(nodito));
                auxS->sig = NULL;
                fscanf(Arch,"%d %d", &(auxS->nroMesa), &(auxS->cantCome));
                if (auxL->subL == NULL)
                    act = auxL->subL = auxS;
                else{
                    act->sig = auxS;
                    act = auxS;
                }
            }
            auxL->sig = *lista;
            *lista = auxL;
        }
    }
    fclose(Arch);
}

void muestraLista(TLista l){
    TLista aux = l;
    TsubL auxs;

    while(aux){
        printf("\nMOZO %s: \n",aux->mozo);
        auxs = aux->subL;
        printf("Numero de Mesa: \t\tCantidad de comensales: \t\t\n");
        while(auxs){
            printf("\t\t%d \t\t\t\t%d\n",auxs->nroMesa,auxs->cantCome);

            auxs = auxs->sig;
        }

        aux = aux->sig;
    }

}

void cierraMesa(TLista *l,char mozo[6],int mesa){
    TLista aux = *l,ant = NULL;
    TsubL auxS,antS;

    while(aux != NULL && strcmp(aux->mozo,mozo) != 0){
        ant=aux;
        aux = aux->sig;
    }

    if(aux){
        auxS = aux->subL;
        antS = NULL;
        while(auxS !=NULL && auxS->nroMesa > mesa){
            antS = auxS;
            auxS = auxS->sig;
        }

        if(auxS){
            if(!antS)
                aux->subL = aux->subL->sig;
            else
                antS->sig = auxS->sig;
            free(auxS);
        }

        if(aux->subL == NULL){
            if(!ant)
                *l = (*l)->sig;
            else
                ant->sig = aux->sig;
            free(aux);
        }
    }
}

void ListaFinal(TLista l){
    TLista aux = l;
    TsubL auxs;
    int contMesas,MUnComensal;
    printf("\tListado de Mozos\nId Mozo\t\tMesas sin cerrar\tMesas con un solo comensal\n");
    while(aux){
        auxs = aux->subL;
        contMesas = 0;
        MUnComensal = 0;
        while(auxs){
            contMesas++;
            if(auxs->cantCome == 1)
                MUnComensal++;
            auxs = auxs->sig;
        }
        printf("%s\t\t\t%d\t\t\t%d\n",aux->mozo,contMesas,MUnComensal);
        aux = aux->sig;
    }
}
