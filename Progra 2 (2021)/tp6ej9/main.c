#include <stdio.h>
#include <stdlib.h>
#define validos 15


typedef struct Nodo{
    int dato;
    struct Nodo * sig;
} Nodo;

typedef struct nodoD{
    int dato;
    struct nodoD* ant,*sig;
}nodoD;


typedef struct {
    nodoD *pri,*ult;
}TListaD; //LISTA DOBLE

Nodo* crearnodo(int dato);
Nodo* crearNodoCirc(int dato);
void llenarListaS(Nodo**);
void insertarListaNodo(Nodo**,int);
void mostrarLista(Nodo*);
void armaListaDobleOrd(TListaD *listaD, Nodo* listaS);
void armaListaDoble(TListaD *listaD, Nodo* listaS);
void armaListaCircular(Nodo**,Nodo*);
void MostrarCircular(Nodo *LC);

int main()
{
    Nodo* lista=NULL,*listaCirc=NULL;
    TListaD listaD;
    llenarListaS(&lista);
    mostrarLista(lista);
    armaListaDoble(&listaD,lista);
    mostrarListaDoble(listaD);
    armaListaCircular(&listaCirc,lista);
    MostrarCircular(listaCirc);
    return 0;
}

Nodo* crearNodo(int dato){
    Nodo* aux=NULL;

    aux=(Nodo*)malloc(sizeof(Nodo));

    if (aux!=NULL){
        aux->dato=dato;
        aux->sig=NULL;
        return aux;
    }
    return NULL;
}

void armaListaDoble(TListaD *listaD, Nodo* listaS){
    nodoD *nuevo,*auxD;
    Nodo *auxS=listaS;
    listaD->pri=NULL;
    listaD->ult=NULL;
    while(auxS!=NULL){
        nuevo=(nodoD*)malloc(sizeof(nodoD));
        nuevo->dato=auxS->dato;
        nuevo->sig=NULL;
        if(listaD->pri==NULL){
            nuevo->ant=NULL;
            listaD->pri=nuevo;
        }else{
            auxD->sig=nuevo;
            nuevo->ant=auxD;
        }
        auxD=nuevo;
        auxS=auxS->sig;
    }
    listaD->ult=nuevo;
}

void insertarListaNodo(Nodo**lista,int x){
    Nodo* aux=NULL,*aux2=*lista;
    aux=crearNodo(x);
    if (aux!=NULL){
        if(*lista==NULL){
            aux->dato=*lista;
            *lista=aux;
        }else{
            while(aux2->sig!=NULL){
                aux2=aux2->sig;
            }
            aux2->sig=aux;
        }
    }
}
void llenarListaS(Nodo**lista){  //Llenar una lista con numeros random
    int numero,i;
    for (i=0;i<validos;i++){
        numero=rand()%validos;
        insertarListaNodo(lista,numero);
    }
}

void mostrarLista(Nodo* lista){
    Nodo* aux=lista;
    while(aux!=NULL){
        printf(" [ %d ]",aux->dato);
        aux=aux->sig;
    }
    printf("\n");
}

void armaListaDobleOrd(TListaD *listaD, Nodo* listaS){
    Nodo* aux=listaS;
    nodoD* nuevo,*act;

    listaD->pri=NULL;
    listaD->ult=NULL;
    while(aux!=NULL){
        nuevo=(nodoD*)malloc(sizeof(nodoD));
        nuevo->dato=aux->dato;
        if(listaD->pri == NULL || nuevo->dato < listaD->pri->dato){
            nuevo->sig=listaD->pri;
            nuevo->ant=NULL;
            if (listaD->pri==NULL)
                listaD->ult=nuevo;
            else
                listaD->pri->ant=nuevo;
            listaD->pri=nuevo;
        }else{
            if (nuevo->dato > listaD->ult->dato){
                nuevo->ant=listaD->ult;
                nuevo->sig=NULL;
                listaD->ult->sig=nuevo;
                listaD->ult=nuevo;
            }else{
                act = listaD->pri;
                while (nuevo->dato > act->dato){
                    act=act->sig;
                }
                nuevo->sig=act;
                nuevo->ant=act->ant;
                act->ant->sig=nuevo;
                act->ant=nuevo;
            }
        aux=aux->sig;

        }
    }
}

void mostrarListaDoble(TListaD LD){
    nodoD *auxD=LD.pri;
    printf("Lista doble\n");
    while(auxD!=NULL){
        printf(" [ %d ]", auxD->dato);
        auxD=auxD->sig;
    }
    printf("\n");
}

Nodo* crearNodoCirc(int dato){
    Nodo* aux=NULL;
    aux=(Nodo*)malloc(sizeof(Nodo));
    aux->dato=dato;
    aux->sig=aux;
    return aux;
}

void insertarListaNodoCirc(Nodo **LC, int x){
    Nodo* nuevo,*aux,*ant;
    nuevo=crearNodoCirc(x);
    if(*LC==NULL){
        *LC=nuevo;
    }else{
        if(x>(*LC)->dato){
            nuevo->sig=(*LC)->sig;
            (*LC)->sig=nuevo;
            *LC=nuevo;
        }else{
            ant=*LC;
            aux=(*LC)->sig;
            while(x>aux->dato){
                ant=aux;
                aux=aux->sig;
            }
            ant->sig=nuevo;
            nuevo->sig=aux;
        }
    }
}

void MostrarCircular(Nodo *LC){
    Nodo* aux=LC;
    printf("Lista Circular:\n");
    do{
        aux=aux->sig;
        printf(" [ %d ]",aux->dato);

    }while (aux!=LC);
}

void armaListaCircular(Nodo**LC,Nodo* L){
    Nodo* auxS=L;
    while(auxS!=NULL){
        insertarListaNodoCirc(LC,auxS->dato);
        auxS=auxS->sig;
    }
}
