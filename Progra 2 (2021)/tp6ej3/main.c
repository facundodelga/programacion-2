#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_dim 11

typedef struct nodo{
    char *dato;
    int cont;
    struct nodo *sig;
}NodoL;
typedef NodoL* Tlista;

void insertarOrdenado(Tlista *,char st[]);
void cargarLista(Tlista *);
int yaExiste(Tlista,char st[]);
void mostrarLista(Tlista);

int main(){
    Tlista l=NULL;
    cargarLista(&l);
    mostrarLista(l);
    return 0;
}

void insertarOrdenado(Tlista *L,char *st){
    Tlista aux,ant,act;
    aux=(Tlista)malloc(sizeof(NodoL));
    strcpy(aux->dato,st);
    aux->sig=NULL;
    printf("-> %s\n",st);                           //valor=strcmp(strin1,strin2);
    if (*L==NULL || strcmp(st,(*L)->dato)==-1){      //valor==-1;strin1<strin2
        aux->sig=*L;                                //valor==0; strin1==strin2
        *L=aux;
        //printf("--> %s\n",(*L)->dato);                                   //valor==1; strin1>strin2
    }else{
        ant=NULL;
        act=*L;
        while (act!=NULL && strcmp(st,(*L)->dato)==1){
            ant=act;
            act=act->sig;
        }
        aux->sig=act;
        ant->sig=aux;
    }
}

void cargarLista(Tlista *L){
    FILE *arch;
    char *st; //string dinamico
    st=(char*)malloc(9*sizeof(char));
    arch=fopen("tp6ej3.txt","r");

    while(!feof(arch)){
        fscanf(arch,"%s\n",st);
        printf("%s\n",st);
        if (!yaExiste(*L,st)){
            insertarOrdenado(L,st);
        }else{

        }
        memset (st, '\0', 9);
    }


    fclose(arch);
    free(st);
}

int yaExiste(Tlista L,char *st){
    Tlista aux=L;
    while (aux!=NULL){
        if (strcmp(aux->dato,st)==0){
//            aux->cont=aux->cont +1;
//            L=aux;
            return 1;
        }
        aux=aux->sig;
    }
    return 0;
}

void mostrarLista(Tlista L){
    Tlista aux=L;
    while (aux!=NULL){
        printf("%s",aux->dato);
        aux=aux->sig;
    }
}
