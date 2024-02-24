#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include "C:\Progra 2\mis libs\PilasDinamicas.h"

typedef struct nodo{
    TCola dato;
    int validos;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void cargaLista(TLista *);
TLista creaNodo(TCola ,int);
void inserta(TLista *,TCola ,int);
void cargaPila(TLista ,TPila *);
void mostrarEnOrden(TPila *);

int main()
{
    TLista l=NULL;
    TPila p;
    IniciaP(&p);

    cargaLista(&l);
    cargaPila(l,&p);
    mostrarEnOrden(&p);

    return 0;
}

TLista creaNodo(TCola c,int cant){
    TLista aux=NULL;
    aux=(TLista)malloc(sizeof(nodo));

    IniciaC(&aux->dato);
    //printf("%d\n",ConsultaC(c));
    aux->dato = c;
    aux->validos = cant;
    aux->sig = NULL;

    return aux;
}

void inserta(TLista *l,TCola c,int cant){
    TLista aux=*l,nuevo=NULL;

    nuevo=creaNodo(c,cant);
    if(aux!=NULL){
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;

    }else{
        *l=nuevo;
    }

}

void cargaLista(TLista *l){
    FILE *arch;
    TCola c;
    TLista aux=NULL;
    int i,num,cant;

    IniciaC(&c);

    arch=fopen("p6ej5.txt","r");

    while(!feof(arch)){
        fscanf(arch,"%i",&cant);
        //printf("%i  ",cant);
        for(i=0;i<cant;i++){

            fscanf(arch,"%i",&num);
            //printf("[%i ]",num);
            PoneC(&c,num);

        }
        //printf("\n");
        inserta(&aux,c,cant);
        IniciaC(&c);
    }
    fclose(arch);

    *l=aux;

}


void cargaPila(TLista l,TPila *p){
    TLista aux=l;
    int i,max,act;
    while(aux!=NULL){
        SacaC(&aux->dato,&max);
        for (i=0;i<aux->validos-1;i++){

            SacaC(&aux->dato,&act);

            if(act>max){
                max=act;
            }
            //printf("%d\n",max);
        }
        poneP(p,max);
        aux=aux->sig;
    }

}


void mostrarEnOrden(TPila *p){
    TElementoP aux;
    while(!VaciaP(*p)){
        sacaP(p,&aux);
        printf("%d\n",aux);

    }
}





