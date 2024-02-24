#include <stdio.h>
#include <stdlib.h>
#include "ListasTp6Ej2.h"

void cantVocales();

int main()
{
    datoL dato;
    char op;
    NodoL *Lista=NULL;
    printf("ingresar letra\n");
    scanf(" %c",&dato);
    insertarInicio(&Lista,dato);
    while (op!='n'){
        printf("ingresar letra\n");
        scanf(" %c",&dato);
        insertarFinal(&Lista,dato);
        printf("seguir?\n");
        scanf(" %c",&op);
    }
    mostrarLista(Lista);
    cantVocales(Lista);
    printf("\n");
    return 0;
}

void cantVocales(NodoL* cabeza){
    int vocales;
    NodoL* aux=cabeza;
    while (aux!=NULL){
        switch(aux->dato){
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
            default:
                printf("no habia vocal\n");
        }
        aux=aux->sig;
    }

    printf("vocales en la lista: %d",vocales);
}
