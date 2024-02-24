#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10
#define MAX_ST 20

typedef struct{
    int v,g;
}TElementoC;

typedef struct{
    int pri,ult;
    TElementoC vertices[MAX];
}TCola;

typedef struct nodito{
    char palabra[20];
    int apariciones;
    struct nodito *sig;
}nodito;

typedef nodito *TSubL;
typedef nodito *TListaC;

typedef struct nodo{
    char letra;
    TSubL subL;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;


void ej1a(int m[][MAX],int i,int j,int n,int grado,TCola *c,int *costoAAM);
void poneC(TCola *c,TElementoC x);
int esVocal(char x);


int main()
{

    return 0;
}

/*(Utilizar TDA Cola) Se tiene una matriz T de NxN naturales que representa un AAM construido sobre
un grafo. Desarrollar una solución recursiva sobre la matriz que almacene en la cola los vértices y su grado
en el AAM, sólo para aquellos vértices que grado > 1 en el AAM, retornar además el costo del AAM.*/

void ej1a(int m[][MAX],int i,int j,int n,int grado,TCola *c,int *costoAAM){
    TElementoC vert;
    if (i < n && j < n){

        if(m[i][j] != 0){
            *costoAAM += m[i][j];

            if(j < i)
                ej1a(m,i,j+1,n,grado + 1,c,costoAAM);
            else
                ej1a(m,i+1,j,n,grado + 1,c,costoAAM);
        }else

            if(j < i)
                ej1a(m,i,j+1,n,0,c,costoAAM);
            else
                ej1a(m,i+1,j,n,0,c,costoAAM);

    }else{

        if(grado > 1){
            vert.g = grado;
            vert.v = j+1;
            poneC(c,vert);
        }

        if(j < n)
            ej1a(m,j+1,0,n,0,c,costoAAM);

    }
}

void poneC(TCola *c,TElementoC x){
    if(c->ult < MAX-1){
        if(c->pri == -1)
            c->pri = 0;
        c->vertices[++(c->ult)].g = x.g;
        c->vertices[c->ult].v = x.v;
    }
}

void ej2a(TLista *l,char *palabra){
    TLista aux = *l,ant = NULL;
    TSubL auxS = NULL,antS;

    while(aux != NULL && aux->letra < palabra[0]){
        ant = aux;
        aux = aux->sig;
    }


    if(aux != NULL && aux->letra == palabra[0]){
        antS = NULL;
        auxS = aux->subL;

        while(auxS != NULL && strcmp(auxS->palabra,palabra) < 0){
            antS = auxS;
            auxS = auxS->sig;
        }

        if(auxS != NULL && strcmp(auxS->palabra,palabra) == 0){
            if(auxS == aux->subL)
                aux->subL = aux->subL->sig;
            else
                antS->sig = auxS->sig;

            free(auxS);

            if(aux->subL == NULL){ // si la letra queda vacia la elimino
                if(aux == *l)
                    *l = (*l)->sig;
                else
                    ant->sig = aux->sig;

                free(aux);
            }
        }
    }
}

void ej2b(TLista l,TListaC *LC){
    TLista aux = l;
    TSubL auxS = NULL;
    TListaC nuevo = NULL;
    while(aux != NULL){

        if(esVocal(aux->letra)){
            auxS = aux->subL;

            while(auxS != NULL){

                if(auxS->apariciones > 5){
                    nuevo = (TListaC) malloc(sizeof(nodito));
                    strcpy(nuevo->palabra, auxS->palabra);
                    nuevo->apariciones = auxS->apariciones;

                    if(!(*LC)){
                        *LC = nuevo;
                        nuevo->sig = nuevo;
                    }else{
                        nuevo->sig = (*LC)->sig;
                        (*LC)->sig = nuevo;
                        *LC = nuevo;
                    }

                }

                auxS = auxS->sig;
            }
        }

        aux = aux->sig;
    }

}

int esVocal(char x){
    return toupper(x) == 'A' || toupper(x) == 'E' || toupper(x) == 'I' || toupper(x) == 'O' || toupper(x) == 'U';
}

int ej3(Arbol A, posicion p, int nivel, int k){
    int hojas = 0,aux = 0;
    posicion c;

    if(nulo(p) && nivel > k)
        return 0;
    else
        if(nivel == k)
            if(info(p,A) == 0 && nulo(hijoMasIzq(p,A)))
                return 1 + ej3(a,herDer(p,A),nivel,k);
            else
                return ej3(a,herDer(p,A),nivel,k);
        else
            return ej3(a,hijoMasIzq(p,A),nivel + 1,k) + ej3(a,herDer(p,A),nivel,k);


}
