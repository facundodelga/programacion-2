#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MCAD 11
#define MDNI 9
#define MRES 3
#define MAXC 50


typedef struct{
    char DNI[MDNI];
    char resultado[MRES];
}TElementoC;

typedef struct{
    TElementoC datos[MAXC];
    int ult,pri;
}TCola;

typedef struct nodo{
    char IdCentro[MCAD];
    int capMax;
    TCola PCR;
    TCola Antigenos;
    struct nodo *sig;
}nodo;

typedef nodo *TListaC;

typedef struct nodoD{
    char IdCentro[MCAD];
    int totalTests;
    float porcentajeP;
    struct nodoD *ant,*sig;
}nodoD;

typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri,ult;
}TListaD;

void IniciaC(TCola *c);
int vaciaC(TCola c);
void sacaC(TCola *c,TElementoC *x);
void poneC(TCola *c,TElementoC x);

int main()
{
    printf("Hello world!\n");
    return 0;
}

int ej2a(TListaC LC){
    TListaC aux = LC->sig;
    TCola auxCola;
    TElementoC x;
    IniciaC(&auxCola);
    int cont = 0, contTest, contP, contN;
    if(LC){

        do{
            if(strncmp("AN",aux->IdCentro,2) == 0){
                contTest = 0;
                contP = 0;
                contN = 0;

                while(!vaciaC(aux->Antigenos)){
                    sacaC(&(aux->Antigenos),&x);
                    contTest++;
                    if(x.resultado[0] == 'D')
                        contP++;
                    else if(strcmp(x.resultado,"ND") == 0)
                        contN++;
                    poneC(&auxCola,x);
                }

                while(!vaciaC(auxCola)){
                    sacaC(&auxCola,&x);
                    poneC(&(aux->Antigenos),x);
                }

                if(aux->capMax / 0.5 <= contTest && contP >= contN)
                    cont++;
            }

            aux = aux->sig;
        }while(aux != LC->sig);

        return cont;
    }

    return -1;
}

void IniciaC(TCola *c){
}
int vaciaC(TCola c){
    return 0;
}
void sacaC(TCola *c,TElementoC *x){
    if (!vaciaC(*c)){
        *x = c->datos[c->pri];
        if (c->pri != c->ult)
            if (c->pri < MAXC-1)
                (c->pri)++;
            else
                c->pri = 0;
        else
            IniciaC(c);
    }
}
void poneC(TCola *c,TElementoC x){
}

void insertaLD(TListaD *LD,char id[],int totalTest,float porcentaje){
    PnodoD nuevo;

    nuevo = (PnodoD)malloc(sizeof(nodoD));

    strcpy(nuevo->IdCentro,id);
    nuevo->totalTests = totalTest;
    nuevo->porcentajeP = porcentaje;

    if(LD->pri == NULL || LD->pri->totalTests < totalTest){

        nuevo->ant = NULL;
        nuevo->sig = LD->pri;

        if(LD->pri == NULL){
            LD->ult = nuevo;
        }else
            LD->pri->ant = nuevo;

        LD->pri = nuevo;
    }else{
        if(LD->ult->totalTests >= totalTest){
            nuevo->ant = LD->ult;
            nuevo->sig = NULL;
            LD->ult->sig = nuevo;
            LD->ult = nuevo;
        }else{
            PnodoD aux = LD->pri;
            while(aux->totalTests > totalTest){
                aux = aux->sig;
            }

            nuevo->ant = aux->ant;
            nuevo->sig = aux;
            aux->ant->sig = nuevo;
            aux->ant = nuevo;

        }

    }

}


void ej2b(TListaC LC, TListaD *LD){
    TElementoC x;
    TListaC aux = LC->sig;
    int contTest,contTestP;
    float porcentaje;
    if(LC){
        do{
            contTest = 0;
            contTestP = 0;
            while(!vaciaC(aux->PCR)){
                sacaC(&(aux->PCR),&x);
                if(x.resultado[0] == 'D')
                    contTestP++;
                contTest++;
            }

            while(!vaciaC(aux->Antigenos)){
                sacaC(&(aux->Antigenos),&x);
                if(x.resultado[0] == 'D')
                    contTestP++;
                contTest++;
            }

            if(contTest != 0){
                porcentaje = contTestP * (100/contTest);
                insertaLD(LD,aux->IdCentro,contTest,porcentaje);
            }else
                insertaLD(LD,aux->IdCentro,0,0.0);

            aux = aux->sig;
        }while(aux != LC->sig);
    }
}

int ej3(Arbol a,posicion p){
    posicion c;
    int aux,suma = 0,grado = 0;

    if(!nulo(p)){
        c = hmi(a,p);
        while(!nulo(c)){
            suma += info(a,c);
            grado++;
            c = herder(a,c);
        }

        if(suma < info(a,p) && grado % 2 != 0)
            return 0;
        else
            return ej3(a,hmi(a,p)) && ej3(a,herder(a,p));
    }else{
        return 1;
    }
}

int encontrado(arbol AB, int nivel, int grado){
    if(AB){
        if(nivel % 2 == 0 && grado % 2 == 0 && nivel == grado || nivel % 2 != 0 && grado % 2 != 0 && nivel == grado)
            return 1;
        return encontrado(AB->izq,nivel + 1,grado) || encontrado(AB->der,nivel + 1,grado);
    }else
        return 0;

}

int ej4(int m[][MAXC],int i,int j,int grado,arbol AB){
    if(i < MAXC){
        if(j < MAXC)
            if(m[i][j] != 0 && i != j)
                return ej4(m,i,j+1,grado + 1,AB);
            else
                return ej4(m,i,j+1,grado,AB);
        else{
            if(encontrado(AB,0,grado))
                return ej4(m,i+1,0,0,AB);
            return 0;
        }
    }else
        return 1;
}
