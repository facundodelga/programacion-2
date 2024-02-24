#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilas.h"



typedef struct Nodo{
    char facultad[21];
    TPila pila;
    struct Nodo* sig;
}Nodo;

Nodo* crearNodo(char st[],TElementoP);
void asignarOrdenado(Nodo** ,char st[],TElementoP );
void armarLista(Nodo**);

int main()
{

    return 0;
}

Nodo* crearNodo(char st[],TElementoP x){
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    strcpy(aux->facultad,st);
    iniciaP(&aux->pila);
    poneP(&aux->pila,x);
    aux->sig=NULL;
    return aux;

}

void asignarOrdenado(Nodo**L,char st[],TElementoP alumno){
    Nodo* nuevo,*ant,*act;

    if(*L==NULL || strcmp(act->facultad,st)>0){  //si la lista esta vacia o si la cabeza es mayor que st
        nuevo=crearNodo(st,alumno); //creo nuevo nodo
        nuevo->sig=*L;
        *L=nuevo;
    }else{
        ant=NULL;
        act=*L;
        while(strcmp(act->facultad,st)>0&&act!=NULL){ //recorro hasta encontrar un nodo igual o menor que st
            ant=act;
            act=act->sig;
        }
        if (strcmp(act->facultad,st)==0){ //si cabeza==st encontre nodo igual, entonces cargo la pila actual
            poneP(&act->pila,alumno);
            ant->sig=act;
        }else{   //si estoy en el medio de la lista o al final
            nuevo=crearNodo(st,alumno);
            nuevo->sig=act;
            ant->sig=nuevo;
        }

    }
}

//void armarLista(Nodo**){
//    //FILE *
//}

