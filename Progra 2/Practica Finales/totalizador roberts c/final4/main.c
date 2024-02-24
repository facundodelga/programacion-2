#include <stdio.h>
#include <stdlib.h>
#define MAXP 30
#define MAXV 10

typedef struct{
    int v;
    int peso;
}TElementoP;

typedef struct{
    TElementoP datos[MAXP];
    int tope;
}TPila;

typedef struct nodito{
    int div;
    struct nodito * sig;
}nodito;

typedef nodito *TSubL;

typedef struct nodo{
    int vert;
    int peso;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct nodod{
    int num;
    TSubL divisores;
    struct nodod *ant,*sig;
}nodod;

typedef nodod *PnodoD;

typedef struct {
    PnodoD pri,ant;
}TListaD;

int main()
{
    printf("Hello world!\n");
    return 0;
}

void ej1a(TListaD LD, int k){
    PnodoD aux = LD.pri;

    while(aux != NULL && aux->num < k)
        aux = aux->sig;

    if(aux != NULL && aux->num == k){
        TSubL auxS = aux->divisores,ant = NULL,elim = NULL;
        while(auxS != NULL){

            if(k % auxS->div != 0){

                if(ant == NULL){
                    elim = auxS;
                    auxS = auxS->sig;
                    aux->divisores = aux->divisores->sig;
                }else{
                    elim = auxS;
                    auxS = auxS->sig;
                    ant->sig = auxS;
                }

                printf("%d no es divisor de %d\n",elim->div,k);

                free(elim);

            }else{
                ant = auxS;
                auxS = auxS->sig;
            }
        }
    }
}

void ej2b(TListaD *LD, int x){
    FILE *arch;
    PnodoD aux = LD->pri;
    TSubL auxs = NULL;
    int contador;
    arch = fopen("DIVI.txt","w");
    while(aux != NULL){
        auxs = aux->divisores;
        contador = 0;
        while(aux->num % 2 == 0 && auxs != NULL){
            if(aux->num % auxs->div == 0)
                contador++;
        }

        if(contador == x){
            fprintf(arch,"%d\n",aux->num);
        }
    }
    fclose(arch);
}

void ej3(Arbol a,posicion p,int nivel, int k, int *nivelK){
    pisicion c;
    if(!nulo(p,A)){
        ej3(a,hmi(p,a),nivel + 1,k,nivelK);
        if(Info(p,a) == k)
            *nivelK = nivel;
        else{
            c = hmi(p,a);
            while(!nulo(c)){
                c = herder(c,a);
                ej3(a,c,nivel + 1,k,nivelK);
            }
        }
    }
}

void depuraPila(TPila *p,int costosV[]){
    TElementoP x;
    if(!vaciaP(*p)){
        sacaP(p,&x);
        depuraPila(p,costosV);
        if(!(x.peso < costosV[x.v]))
            poneP(p,x);
    }
}


void ej4(TLista ady[], TPila *p){
    TLista aux;

    int pesoAcum[MAXV] = {0};
    if(!vacia(*p)){
        for(int i = 0;i < MAXV;i++){
            aux = ady[i];
            while(aux != NULL){
                if(aux->vert != i)
                    pesoAcum[aux->vert] += aux->peso;
                aux = aux->sig;
            }
        }

        depuraPila(p,pesoAcum);
    }
}
