#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo{
    char dato;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void muestraL(TLista );
void cargaL(TLista *);
int cantVocales(TLista );
int listaOrdenada(TLista );
void eliminaPos(TLista *, int );

int main(){
    TLista l = NULL;
    cargaL(&l);
    muestraL(l);
    printf("cantidad de vocales: %d\n",cantVocales(l));
    if(listaOrdenada(l))
        printf("la lista esta ordenada\n");
    else
        printf("la lista no esta ordenada\n");
    eliminaPos(&l,5);
    muestraL(l);
    return 0;
}

void muestraL(TLista l){
    TLista aux = l;

    while(aux != NULL){
        printf("[ %c ] ",aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void cargaL(TLista *l){
    TLista aux = NULL;
    char op;

    printf("Insertar caracter {'0' para salir}\n");
    scanf("%c",&op);

    while(op != '0'){
        aux = (TLista) malloc(sizeof(nodo));
        aux->dato = op;
        aux->sig = *l;
        *l = aux;

        printf("Insertar caracter {'0' para salir}\n");
        scanf(" %c",&op);
    }
}

int cantVocales(TLista l){
    TLista aux = l;
    int cont = 0;
    if(l != NULL){

        while(aux!=NULL){
            if(toupper(aux->dato) == 'A' && toupper(aux->dato) == 'E' && toupper(aux->dato) == 'I' && toupper(aux->dato) == 'O' && toupper(aux->dato) == 'U')
                cont++;
            aux = aux->sig;
        }
        return cont;

    }else
        return -1;
}

int listaOrdenada(TLista l){
    TLista aux = l;

    while(aux != NULL && aux->dato <= aux->sig->dato)
        aux = aux->sig;

    if(aux == NULL)
        return 1;
    else
        return 0;

}

void eliminaPos(TLista *l, int pos){
    TLista elim, act, ant;
    int i = 1;
    if (pos==1){
        elim = *l;
        *l = (*l)->sig;
        free(elim);
    }else{
        act = *l;
        while(act != NULL && i!=pos){
            ant = act;
            act = act->sig;
            i++;
        }
        if(act == NULL)
            free(ant);
        else{
            ant->sig = act->sig;
            free(act);
        }

    }


}
