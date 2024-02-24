#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char fechaHora[11];
    char patente[8];
}TElementoP;

typedef struct{
    TElementoP datos[MAX];
    int tope;
}TPila;

typedef struct nodo{
    int zona;
    char cod[5];
    TPila p;
    struct nodo *ant,*sig;
}nodo;

typedef nodo *PnodoD;

typedef struct{
    PnodoD pri,ult;
}TListaD;

typedef struct nodoC{
    int zona;
    int cantIR;
    int cantIC;
    struct nodoC *sig;
}nodoC;

typedef nodoC *TListaC;

void poneP(TPila *p,TElementoP x);
void sacaP(TPila *p,TElementoP *x);
int vaciaP(TPila p);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void pilarec(TPila *p,char fecha[],int *existe){
    TElementoP x;
    if(!vaciaP(*p)){
        sacaP(p,&x);
        if(strncmp(fecha,x.fechaHora,4)){
            *existe = 1;
        }
        pilarec(p,fecha, existe);
        poneP(p,x);
    }else
        *existe = 0;
}

void ej2a(TListaD LD,int *cantInfracciones,char *fecha){
    PnodoD aux = LD.pri;
    int existe;

    while(aux != NULL){
        if(aux->cod[0] == 'R' && aux->zona % 2 == 0 && !vaciaP(aux->p)){
            pilarec(&(aux->p),fecha,&existe);
            if(existe)
                *cantInfracciones += 1;
        }
        aux = aux->sig;
    }
}

void ej2b(TListaD LD,TListaC *LC){
    PnodoD aux = LD.pri,aux2;
    TListaC nuevo = NULL,ant,act;
    while(aux != NULL){

        if(!vaciaP(aux->p)){
            aux2 = aux;
            nuevo = (TListaC) malloc(sizeof(nodoC));
            nuevo->zona = aux->zona;
            nuevo->cantIC = 0;
            nuevo->cantIR = 0;
            while(aux2 != NULL){
                if(aux2->zona == nuevo->zona){
                    if(aux2->cod[0] == 'R'){
                        while(!vaciaP(aux2->p))
                            nuevo->cantIR += 1;

                    }else if(aux2->cod[0] == 'C'){
                        while(!vaciaP(aux2->p))
                            nuevo->cantIR += 1;
                    }
                }
                aux2 = aux2->sig;
            }
            if(nuevo->cantIC != 0 && nuevo->cantIR != 0){
                if(*LC == NULL){
                    *LC = nuevo;
                    nuevo->sig = nuevo;
                }else{
                    if(nuevo->zona > (*LC)->zona){
                        nuevo->sig = (*LC)->sig;
                        (*LC)->sig = nuevo;
                        *LC = nuevo;
                    }else{
                        ant = *LC;
                        act = (*LC)->sig;

                        while(nuevo->zona > act->zona){
                            ant = act;
                            act = act->sig;
                        }

                        ant->sig = nuevo;
                        nuevo->sig = act;
                    }
                }
            }else
                free(nuevo);
        }

        aux = aux->sig;
    }

}

void sacaP(TPila *p,TElementoP *x){
    if(!vaciaP(*p))
        *x = p->datos[(p->tope)--];
}

void poneP(TPila *p,TElementoP x){
    if(p->tope != MAX-1)
        p->datos[++(p->tope)] = x;
}

int vaciaP(TPila p){
    return p.tope == -1;
}

int esVocal(char x){
    return toupper(x) == 'A' || toupper(x) == 'E' || toupper(x) == 'I' || toupper(x) == 'O' || toupper(x) == 'U';
}

int ej3(Arbol A,posicion p,int nivel){

    if(!nulo(p)){

        if(nivel % 2 != 0){
            char aux[MAX];

            strcpy(aux,Info(p,A));

            if(strlen(aux) % 2 != 0 && esVocal( aux[0] ) && esVocal( aux[strlen(aux) - 1] ))
                return 1 + ej3(A,hijoMasIzq(p,A),nivel + 1) + ej3(A,herDer(p,A),nivel);
        }

        return ej3(A,hijoMasIzq(p,A),nivel + 1) + ej3(A,herDer(p,A),nivel);
    }else
        return 0;
}

int ej4(arbol abb,int ady[][MAX], int i,int j, int n,int grado,int cant){
    if(j < n && i < n){
        if(ady[j][j] != 0)

            if(ady[j][i] != 0)
                return ej4(abb,ady,i+1,j,n,grado + 1,cant);
            else
                return ej4(abb,ady,i+1,j,n,grado,cant);

        else
            return ej4(abb,ady,0,j + 1,n,0,cant);


    }else{
        if(j < n){
            if(ady[j][j] != 0 && buscaabb(a,grado))
                return ej4(abb,ady,0,j + 1,n,0,cant + 1);
            return ej4(abb,ady,0,j + 1,n,0,cant);
        }else{
            if(cant != 0)
                return 1;
            return 0;
        }

    }



}

int buscaabb(arbol a, int x){
    if(arbol){
        if(x < a->dato)
            return buscaabb(a->izq,x);
        else if(x > a->dato)
                return buscaabb(a->der,x);

        return 1;

    }else
        return 0;
}












