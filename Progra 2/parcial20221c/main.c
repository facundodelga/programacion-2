#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define N 30
#define M 12

typedef struct{
    int dia;
    int tempMax;
    int tempMin;
}TTemp;

typedef char cp[8];

typedef struct nodo{
    char cp[8];
    char ciudad[21];
    TPila p;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct nodoD{
    char ciudad[21];
    int tempMax;
    int dia;
    int tempMin;
    int AT;
    struct nodoD *ant,*sig;
}nodoD;

typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri,ult;
}TListaD;

typedef struct{
    char ciudad[21];
    int temp;
}TCiudad;

int main(){
    printf("Hello world!\n");
    return 0;
}


void cargaDoble(TLista l,TListaD *ld){
    TCiudad TC[100];
    TPila auxp;
    TElementoP temp;
    int contTempMax = 0,acumTempMax = 0,cantCiudades = 0,tempMinC = 99,tempMin = 99;
    PnodoD nuevo,act;
    TLista auxl = l;

    IniciaP(&auxp);
    while(auxl){
        tempMin = 99;
        while(!VaciaP(auxl->p)){
            sacaP(&auxl->p,&temp);
            if(temp.tempMax - temp.tempMin > temp.tempMin){
                nuevo = (PnodoD)malloc(sizeof(nodoD));
                nuevo->tempMax = temp.tempMax;
                nuevo->dia = temp.dia;
                nuevo->tempMin = temp.tempMin;
                nuevo->AT = temp.tempMax - temp.tempMin;
                strcpy(nuevo->ciudad,auxl->ciudad);

                if(ld->pri == NULL || ld->pri->AT < nuevo->AT){ //inserto en la cabeza
                    nuevo->ant = NULL;
                    nuevo->sig = ld->pri;

                    if(ld->pri == NULL)
                        ld->ult = nuevo;
                    else
                        ld->pri->ant = nuevo;

                    ld->pri = nuevo;

                }else{
                    act = ld->pri;
                    while(act != NULL && nuevo->AT < act->AT)
                        act = act->sig;

                    if(!act){ //inserto al final de la lista
                        nuevo->sig = NULL;
                        nuevo->ant = ld->ult;
                        ld->ult->sig = nuevo;
                        ld->ult = nuevo;
                    }else{ //inserto entre nodos
                        nuevo->ant = act->ant;
                        nuevo->sig = act;
                        act->ant->sig = nuevo;
                        act->ant = nuevo;
                    }
                }

            }else
                poneP(&auxp,temp);
            if(tempMin > temp.tempMin)
                tempMin = temp.tempMin;

            contTempMax++;
            acumTempMax += temp.tempMax;
        }

        while(!VaciaP(auxp)){
            sacaP(&auxp,&temp);
            poneP(&auxl->p,temp);
        }

        if(tempMinC >= tempMin){ //siempre inserto la temperatura minima registrada por ciudad siempre y cuando sea menor a la ultima registrada
            tempMinC = tempMin;
            strcpy(TC[cantCiudades].ciudad,auxl->ciudad);
            TC[cantCiudades].temp = tempMin;
            cantCiudades++;
        }
        auxl = auxl->sig;
    }

    int i = cantCiudades-1;

    tempMin = TC[i].temp;
    printf("Ciudades con la temperatura minima:\n");

    while(0 <= i && TC[i].temp == tempMin)
        printf("   %s\n",TC[i--].ciudad);

    printf("promedio de temperatura maxima: %d\n",acumTempMax/contTempMax);

}


int punto1b(cp mt[][M],cp CP,int i,int j){ //punto1b(mt,"7600",21,5);
    int boo1ean;
    if(i==20 && j==8){ // termina el invierno
        return 0;
    }else{ //if(i!=21 || j!=8)
        boo1ean = (strcmp(mt[i][j],CP) == 0) ? 1:0;
        if(i<30){
            return boo1ean + punto1b(mt,CP,i+1,j);
        }else
            return boo1ean + punto1b(mt,CP,0,j+1);

    }
}

void eliminaCiudad(TLista *l,char cp[8]){
    FILE *arch;
    TLista aux = *l,ant;
    TPila p;
    TElementoP temp;
    int tempMinMax;
    char ciudad[21];
    IniciaP(&p);
    ant = NULL;

    while(aux && strcmp(aux->cp,cp) != 0){
        ant = aux;
        aux=aux->sig;
    }

    if(aux != NULL){
        printf("temperatura minima para guardar\n");
        scanf("%d",&tempMinMax);
        strcpy(ciudad,aux->cp);
        strcat(ciudad,".txt");
        arch = fopen(ciudad,"wt");

        while(!VaciaP(aux->p)){
            sacaP(&(aux->p),&temp);
            if(tempMinMax <= temp.tempMax)
                fprintf(arch,"%d %d %d\n",temp.dia,temp.tempMin,temp.tempMax);
        }

        if(ant == NULL){
            aux = *l;
            *l = (*l)->sig;
        }else
            ant->sig = aux->sig;

        free(aux);
        fclose(arch);
    }
}
