#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdapilaestatica.h"

#define MAX 21
#define CANT 15

//tipo de la lista simplemente enlazada
typedef struct nodo{
    char facu[MAX];
    tpila p;
    struct nodo *sig;
}nodo;

typedef nodo *tlista;

//tipo de la lista circular
typedef struct nodoC{
    char facu[MAX];
    char DNI[CANT];
    float promFinal;
    int orden;
    struct nodoC *sig;
}nodoC;

typedef nodoC *tlistaC;

void cargaL(tlista *L);
void muestraL(tlista L);
void retirarTitulo(tlista *L,tlistaC *LC,char facultad[],char DNI[]);
void muestraConDoWhile(tlistaC LC);
void titulosEntregados(tlistaC LC,char facu[]);
void devuelveTitulo(tlistaC *LC,tlista *L,char DNI[]);

int main(){

    tlista L=NULL;
    tlistaC LC=NULL;
    char facultad[MAX],DNI[CANT];
    int opcion;

    cargaL(&L);
    printf("holi\n");
    muestraL(L);

    do{
        printf("1-Retirar Titulo 0-Salir\n");
        scanf("%d",&opcion);
        switch (opcion){
            case 1: printf("Ingrese Facultad y DNI para el retiro del titulo.\n");
                    scanf("%s %s",facultad,DNI);
                    retirarTitulo(&L,&LC,facultad,DNI);
                    muestraConDoWhile(LC);
                    muestraL(L);
            break;
            case 0: printf("Salio del menu exitosamente.\n");
            break;
            default: printf("Opcion mal ingresada, ingrese la opcion nuevamente.\n");
            break;
        }
    }while (opcion!=0);

    if (LC!=NULL){
        printf("Ingrese facultad para saber el mejor promedio: \n");
        scanf("%s",facultad);
        titulosEntregados(LC,facultad);
        printf("Ingrese DNI para devolucion del titulo: \n");
        scanf("%s",DNI);
        devuelveTitulo(&LC,&L,DNI);
        printf("\nTitulos Entregados:\n");
        muestraConDoWhile(LC);
    }
    return 0;
}

//inciso a
void cargaL(tlista *L){

    FILE *archT;
    char facu[MAX];
    telementop x;
    tlista nuevo,antL,actL;

    archT=fopen("TITULOS.txt","r");
    if (archT==NULL)
        printf("Error al abrir el archivo.");
    else{
        while(fscanf(archT,"%s %s %f",facu,x.DNI,&x.promFinal)==3){
            nuevo=(tlista)malloc(sizeof(nodo));
            strcpy(nuevo->facu,facu);
            if (*L==NULL){
                nuevo->sig=NULL;
                *L=nuevo;
                iniciap(&((*L)->p));
                ponep(&((*L)->p),x);
            }else{
                antL=NULL;
                actL=*L;
                while (actL!=NULL && strcmp(nuevo->facu,actL->facu)>0){
                    antL=actL;
                    actL=actL->sig;
                }
                //printf("Facu: %s DNI:%s Prom: %5.2f ",nuevo->facu,x.DNI,x.promFinal);
                //printf("Actual: %s\n",actL->facu);
                if (actL==*L){
                    if (strcmp(nuevo->facu,actL->facu)==0){ //ya existía la facultad
                        ponep(&((*L)->p),x);
                        //free(nuevo);
                    }else{
                        nuevo->sig=*L;
                        *L=nuevo;
                        iniciap(&((*L)->p));
                        ponep(&((*L)->p),x);
                    }
                }else{
                    if (actL!=NULL && strcmp(nuevo->facu,actL->facu)==0){
                        ponep(&(actL->p),x);
                        //free(nuevo);
                    }else{  //no existia la facultad. Inserto en medio o en el final
                        iniciap(&(nuevo->p));
                        ponep(&(nuevo->p),x);
                        nuevo->sig=actL;
                        antL->sig=nuevo;
                    }
                }
            }
        }
        fclose(archT);
    }
}

void muestraL(tlista L){

    tpila auxP;
    telementop x;

    while (L!=NULL){
        printf("Facultad: %s \n",L->facu);
        iniciap(&auxP);
        while (!vaciap(L->p)){
            sacap(&(L->p),&x);
            printf("DNI: %s Promedio Final: %5.2f\n",x.DNI,x.promFinal);
            ponep(&auxP,x);
        }
        while (!vaciap(auxP)){
            sacap(&auxP,&x);
            ponep(&(L->p),x);
        }
        L=L->sig;
    }
}

void retirarTitulo(tlista *L,tlistaC *LC,char facultad[],char DNI[]){

    tlista antL,actL;
    tpila auxP;
    telementop x;
    tlistaC nuevoC;

    if (*L!=NULL){
        actL=*L;
        while (actL!=NULL && strcmp(facultad,actL->facu)>0){
            antL=actL;
            actL=actL->sig;
        }
        if (actL!=NULL)
            if (strcmp(facultad,actL->facu)<0)
                printf("No existe la facultad ingresada.\n");
            else{
                iniciap(&auxP);
                while (!vaciap(actL->p)){
                    sacap(&(actL->p),&x);
                    if (strcmp(DNI,x.DNI)==0){  //si encontre la facultad y el DNI
                        nuevoC=(tlistaC)malloc(sizeof(nodoC));
                        strcpy(nuevoC->facu,facultad);
                        strcpy(nuevoC->DNI,DNI);
                        nuevoC->promFinal=x.promFinal;
                        if (*LC==NULL){
                            *LC=nuevoC;
                            (*LC)->sig=nuevoC;
                            (*LC)->orden=1;
                        }
                        else{
                            nuevoC->orden=(*LC)->orden+1;
                            nuevoC->sig=(*LC)->sig;
                            (*LC)->sig=nuevoC;
                            *LC=nuevoC;
                        }
                    }else
                        ponep(&auxP,x);
                }
                if (*LC==NULL)
                    printf("El DNI ingresado no existe.\n");
                while (!vaciap(auxP)){  //devuelvo los datos a la pila original
                    sacap(&auxP,&x);
                    ponep(&(actL->p),x);
                }
                if (vaciap(actL->p)){       //facultad sin titulos pendientes, la elimino de la lista
                    if (actL==*L){
                        *L=actL->sig;
                    }else
                        antL->sig=actL->sig;
                    free(actL);
                }
            }
        else
             printf("No existe la facultad ingresada.\n");
    }
}

void muestraConDoWhile(tlistaC LC){

    tlistaC auxC;

    if (LC!=NULL){
        auxC=LC->sig;
        do{
            printf("Facultad: %s DNI: %s promedio: %5.2f orden: %d\n",auxC->facu,auxC->DNI,auxC->promFinal,auxC->orden);
            auxC=auxC->sig;
        }while (auxC!=LC->sig);
    }
}

void titulosEntregados(tlistaC LC,char facu[]){

    tlistaC auxC;
    float maxProm=0;
    int ordenMax;
    char DNIMax[CANT];

    if (LC!=NULL){
        auxC=LC->sig;
        do{
            printf("Facultad: %s DNI: %s Promedio Final: %5.2f\n",auxC->facu,auxC->DNI,auxC->promFinal);
            if (strcmp(facu,auxC->facu)==0 && auxC->promFinal>maxProm){
                maxProm=auxC->promFinal;
                strcpy(DNIMax,auxC->DNI);
                ordenMax=auxC->orden;
            }
            auxC=auxC->sig;
        }while (auxC!=LC->sig);
        printf("El graduado con mayor promedio es: DNI: %s con Promedio Final: %5.2f de la Facultad: %s -- Orden: %d\n",DNIMax,maxProm,facu,ordenMax);
    }
}

void devuelveTitulo(tlistaC *LC,tlista *L,char DNI[]){

    tlistaC antC,actC,elim;
    //tlista auxL;
    int eliminado=0;

    if (*LC!=NULL){
        antC=(*LC);
        actC=(*LC)->sig;
        do{
            if (strcmp(DNI,actC->DNI)==0){
                elim=actC;
                if (actC==*LC)
                    if (actC==antC) //si era el unico elemento
                        *LC=NULL;
                    else{
                        antC->sig=(*LC)->sig;
                        actC=(*LC)->sig;
                        (*LC)=antC;
                    }
                else{
                    antC->sig=actC->sig;
                    actC=actC->sig;
                }
                eliminado=1;
                printf("Graduado eliminado. Orden: %d",elim->orden);
                free(elim);
            }else{
                antC=actC;
                actC=actC->sig;
            }
        }while (actC!=(*LC)->sig && eliminado==0);
    }
}
