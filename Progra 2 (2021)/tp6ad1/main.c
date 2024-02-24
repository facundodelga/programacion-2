#include <stdio.h>
#include <stdlib.h>

int validos1=-1,validos2=-1;

typedef struct nodo {
    int num;
    struct nodo *sig;
}nodo;

nodo* crearNodo(int x);
void insertarOrdLista(nodo**,int);
void cargarLista(nodo**,int);
void mostrarLista(nodo*);
int sonIguales(nodo*,nodo*);

int main(){
    nodo* L1=NULL,*L2=NULL;
    cargarLista(&L1,1);
    cargarLista(&L2,2);
    mostrarLista(L1);
    mostrarLista(L2);
    sonIguales(L1,L2);
    return 0;
}

nodo* crearNodo(int x){
    nodo* aux=NULL;
    aux=(nodo*)malloc(sizeof(nodo));
    if (aux){
        aux->num=x;
        aux->sig=NULL;
        return aux;
    }
    return NULL;
}

void insertarOrdLista(nodo** lista,int dato){
    nodo* nuevo=NULL,*act=*lista,*ant=NULL; //aux,act,ant
    nuevo=crearNodo(dato);
    if(act==NULL || dato < act->num){
            nuevo->sig=*lista;
            *lista=nuevo;
    }else{
            while(act!=NULL && dato >= act->num){
                ant=act;
                act=act->sig;
            }
            nuevo->sig=act;
            ant->sig=nuevo;
    }
}

void cargarLista(nodo** l,int nLista){
    char op='s';
    int num,validos=0;
    while(op=='s'){
        num=rand()%11;
        //printf("==> %d\n",num);
        scanf(" %d",&num);
        insertarOrdLista(l,num);
        printf("seguir cargando la lista %d ? (%d) [s] ===> ",nLista,validos+1);
        scanf(" %c",&op);
        validos++;
    }
    switch(nLista){
    case 1:
        validos1=validos;
        break;
    case 2:
        validos2=validos;
        break;
    default:
        printf("No valido. solo se toma 1/2\n");
        break;
    }

}

void mostrarLista(nodo* lista){
    nodo* aux=lista;
    while(aux!=NULL){
        printf(" [ %d ]",aux->num);
        aux=aux->sig;
    }
    printf("\n");
}

int sonIguales(nodo* L1,nodo* L2){
    nodo* aux1=L1,*aux2=L2;
    if(aux1!=NULL && aux2!=NULL){
        if(validos1==validos2){
            printf("{ 1 } [ 2 ]\n");
            printf("===========\n");
            while(aux1!=NULL && aux2!=NULL){
                printf("{ %d } [ %d ]\n",aux1->num,aux2->num);
                if(aux1->num!=aux2->num){
                    printf("NO son iguales\n");
                    return 0;
                }
                aux1=aux1->sig;
                aux2=aux2->sig;
            }
                if (aux1==NULL && aux2==NULL){
                    printf("son iguales!!\n");
                    return 1;
                }
        }else{
            printf("las listas tienen distintas longitudes\n");
            return 0;
        }
    }
    return 0;
}

