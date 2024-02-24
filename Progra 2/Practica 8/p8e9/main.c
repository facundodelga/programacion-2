#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct nodo{
    int v;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

int main()
{

    return 0;
}

int ej9(TLista l[], int n){
    int i = 0,max = 0,entrada[N] = {0};
    while(i < n){
        while(l[i] != NULL){
            entrada[l[i]->v] += 1;
            l[i] = l[i]->sig;
        }
        i++;
    }
    i = 0;
    while(i < n){
        if(entrada[i] > max)
            max = entrada[i];
        i++;
    }

    return max;
}
