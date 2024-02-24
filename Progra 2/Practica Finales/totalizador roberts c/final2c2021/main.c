#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodito{
    char nombre[26];
    int cantInvitados;
    char mail[30];
    char mesdia[5];
    struct nodito *sig;
}nodito;

typedef nodito *TSubL;

typedef struct nodo{
    char codSalon[4];
    int capacidad;
    TSubL reservas;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

int main(){

    return 0;
}

void ej2a(TLista l,int invitados,char mesdia[]){
    TLista aux = l;
    TSubL auxs = NULL;

    while(aux != NULL){
        if(invitados <= (int) aux->capacidad * 0.5){
            auxs = aux->reservas;
            while(auxs != NULL && strcmp(auxs->mesdia,mesdia) > 0)
                auxs = auxs->sig;

            if(auxs != NULL && strcmp(auxs->mesdia,mesdia) != 0)
                printf("la reserva en el salon [ %s ] en el dia [ %s ] esta disponible",aux->codSalon,mesdia);

        }

        aux = aux->sig;
    }

}

void ej2b(TLista l,int d,int m){
    TSubL aux,ant;
    char diames[5];
    sprintf(diames,"%d%d",m,d);
    FILE * arch;

    arch = fopen("BAJAS.txt","w");

    while(l != NULL){
        aux = l->reservas;

        while (aux != NULL && strcmp(aux->mesdia,diames) > 0){
            ant = aux;
            aux = aux->sig;
        }

        if(aux != NULL && strcmp(aux->mesdia,diames) == 0 ){
            if(aux == l->reservas)
                l->reservas = l->reservas->sig;
            else
                ant->sig = aux->sig;

            fprintf(arch,"%s %s\n",aux->nombre,aux->mail);

            free(aux);

        }

        l = l->sig;
    }

    fclose(arch);
}

int ej3(Arbol A,posicion p, char x[]){
    posicion c;
    int i;
    if(!nulo(p)){
        c = hijoMasIzq(c,A);
        if(Info(p,A) == x[0] && !nulo(c)){
            i = 1;
            while(!nulo(c,A) && Info(p,A) == x[i]){
                c = herDer(c,A);
                i++;
            }

            if(strlen(x) == i)
                return 1;
        }

        return ej3(A,c,x) || ej3(A,herDer(c,A),x);
    }else
        return 0;
}
