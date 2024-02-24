#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\facundo\Documents\Progra 2\mis libs\ColasCirculares.h"
#include "C:\Users\facundo\Documents\Progra 2\mis libs\PilasDinamicas.h"

typedef struct nodo{
    TCola cola;
    struct nodo *sig;
}NodoL;

NodoL* crearNodo(TCola c);
void cargarLista();
void pilaMaximos();


int main()
{
    int cantidad,i,dato,basura;
    TPila p;
    TCola c;
    NodoL* l=NULL;

    IniciaC(&c);
    IniciaP(&p);
    printf("cuantas colas desea cargar?\n");
    scanf("%d",&cantidad);
    for(i=0;i<cantidad;i++){
            do{
                printf("ingresar valor para la cola ==> %d\n",i+1);
                printf("Para salir escriba 0\n");
                scanf("%d",&dato);
                PoneC(&c,dato);
            }while(dato!=0);

            cargarLista(&l,c);

            while(!VaciaC(c)){
                SacaC(&c,&basura);
            }
    }

    return 0;
}

NodoL* crearNodo(TCola c){
    NodoL *aux ;
    aux = (NodoL*)malloc(sizeof(nodo));
    if (aux!=NULL){
        aux->cola=c;
        aux->sig=NULL;
    }
    return aux;
}

void cargarLista(NodoL **lista,TCola c){
    NodoL *aux=NULL;
    aux=crearNodo(c);
    if(aux!=NULL){
        aux->sig=*lista;
        *lista=aux;
    }
}

void pilaMaximos(NodoL* lista,TPila *p){
    NodoL* aux=lista;
    int max,x;
    while(aux!=NULL){
        max=-1;
        while(!VaciaC(aux->cola)){
            SacaC(&aux->cola,&x);
            if(x>max){
                max=x;
            }
        }
        poneP(p,x);
        aux=aux->sig;
    }
}


