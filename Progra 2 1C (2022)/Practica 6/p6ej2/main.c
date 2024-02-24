#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    char dato;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

TLista creaNodo(char x);
void insertaNodo(TLista *l, int x);
void ejercicio(TLista *l, int pos);

int main()
{
    TLista l=NULL;
    insertaNodo(&l,'n');
    insertaNodo(&l,'i');
    insertaNodo(&l,'c');
    insertaNodo(&l,'o');
    insertaNodo(&l,'t');
    insertaNodo(&l,'r');
    insertaNodo(&l,'o');
    insertaNodo(&l,'l');
    insertaNodo(&l,'o');

    ejercicio(&l,0);

    return 0;
}



TLista creaNodo(char x){
    TLista aux=NULL;

    aux = (TLista) malloc(sizeof(nodo));

    aux->dato = x;
    aux->sig = NULL;

    return aux;
}

void insertaNodo(TLista *l, int x){
    TLista nuevo,aux=*l;

    nuevo = creaNodo(x);

    if (aux!=NULL){

        while(aux->sig!= NULL){
            aux = aux->sig;
        }

        aux->sig = nuevo;

    }else{
        *l=nuevo;
    }

}

void ejercicio(TLista *l,int pos){
    TLista act=*l,ant=NULL,nodoEliminar=NULL;
    char cAnt;
    int vocales=0,ordenado=1,i=0;

    cAnt = act->dato;
    ant=*l;

    while (act!=NULL){
        //ant=act;
        printf(". %c \n",ant->dato);

        switch(act->dato){ //contador de vocales
        case 'a':
            vocales++;
            break;
        case 'e':
            vocales++;
            break;
        case 'i':
            vocales++;
            break;
        case 'o':
            vocales++;
            break;
        case 'u':
            vocales++;
            break;
        }

        if(cAnt > act->dato && ordenado==1){ //esta ordenado?

            ordenado=0;


        }else{

            cAnt = act->dato;

        }
                                                        //eliminacion
        if(pos == i){

            if (act == *l){
                *l=(*l)->sig;
                 ant=*l;
            }else{
                ant -> sig = act ->sig;
            }
            free(act);
            act=ant;

        }



        i++;
        ant=act;
        act=act->sig;

    }
    if (ordenado == 0){
        printf("la lista no esta ordenada\n");
    }

    printf("cantidad de vocales : %d\n",vocales);

}
