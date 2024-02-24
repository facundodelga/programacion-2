#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#define DIM 31
#define DIMM 12

typedef struct {
    int dia;
    float tempMin;
    float tempMax;
}TTemp;  //TElementoP

typedef struct {
    char cp[8];
    float tempMin;
}TTempB;

typedef struct {
	TTemp temp[DIM];
	int tope;
}TPila;

typedef struct nodo{
    char cp[8];
    char ciudad[21];
    TPila p;
    struct nodo *sig;
}nodo;

typedef nodo * TLista;

typedef struct nodoD{
    char ciudad[21];
    int dia;
    float tempMin;
    float tempMax;
    float amplitud;
    struct nodoD *ant, * sig;
}nodoD;

typedef struct nodoD * PnodoD;

typedef struct {
    PnodoD pri, ult;
}TListaD;

void cargaLista(TLista *);
void cargaMatriz(TTempB [][DIMM],TLista);
void puntoA(TLista ,TListaD *);
int puntoB(TTempB m[][DIMM],char cp[],int dia,int mes);
void puntoC(TLista *,char [],float );

int main()
{
    TLista l=NULL;
    TListaD LD;
    TTempB m[31][DIMM];
    char cp[8];
    float tempEliminacion;

    LD.pri=NULL;
    LD.ult=NULL;

    cargaLista(&l);
    cargaMatriz(m,l);

    puntoA(l,&LD);

    scanf("cp: %s\n",cp);

    scanf("tempEliminacion: %f",&tempEliminacion);

    printf("cantidad de veces que el cp %s es temperatura minima: %i\n",cp,puntoB(m,cp,22,6));

    puntoC(&l,cp,tempEliminacion);

    return 0;
}

void cargaLista(TLista *l){
    //desarrollo
}

void cargaMatriz(TTempB m[][DIMM],TLista l){
    //desarrollo

}

void puntoA(TLista l,TListaD *LD){
    TLista aux=l;
    TPila auxP;
    PnodoD nuevo,act;
    TTemp t;
    int contadorCiudades=0;
    float menorTemp=99,acumulaMax=0;
    char ciudadMenorTemp[21];

    iniciaP(&auxP);

    while(aux!=NULL){

        while(!vaciaP(aux->p)){
            sacaP(&(aux->p),&t);

            if(t.tempMin<menorTemp){
                menorTemp=t.tempMin;
                strcpy(ciudadMenorTemp,aux->ciudad);
            }

            if(t.tempMax-t.tempMin > t.tempMin){ //insercion

                nuevo=(PnodoD)malloc(sizeof(nodoD));

                strcpy(nuevo->ciudad,aux->ciudad);
                nuevo->dia=t.dia;
                nuevo->tempMin=t.tempMin;
                nuevo->tempMax=t.tempMax;
                nuevo->amplitud=t.tempMax-t.tempMin;

                if (LD->pri == NULL || t.tempMax-t.tempMin > LD->pri->amplitud){
                    nuevo->ant = NULL;
                    nuevo->sig = LD->pri;
                    if (LD->pri == NULL){
                        LD->ult = nuevo;
                    }else
                        LD->pri->ant = nuevo;
                    LD->pri = nuevo;
                }else{
                    act = LD->pri;
                    if ( t.tempMax-t.tempMin < LD->ult->amplitud){
                        nuevo->sig = NULL;
                        nuevo->ant = LD->ult;
                        LD->ult->sig = nuevo;
                        LD->ult = nuevo;
                    }else{
                        while (t.tempMax-t.tempMin < act->amplitud)
                            act=act->sig;
                        nuevo->ant = act->ant;
                        nuevo->sig = act;
                        act->ant->sig = nuevo;
                        act->ant = nuevo;
                    }
                }


            }else{
                poneP(&auxP,t);
            }

            acumulaMax += t.tempMax;

        }

        while(!vaciaP(auxP)){
            sacaP(&auxP,&t);
            poneP(&aux->p,t);
        }

        contadorCiudades++;
        aux=aux->sig;
    }

    printf("promedio de temperatura maxima : %f\n",acumulaMax/contadorCiudades);

    printf("ciudad con menor temperatura registrada : %s\n",ciudadMenorTemp);
}


int puntoB(TTempB m[][DIMM],char cp[],int dia,int mes){

    if(dia>20 && mes==9){

        return 0;

    }else{

        if(strcmp(cp,m[dia][mes].cp)==0){
            if(dia==30)
                return 1 + puntoB(m,cp,1,mes+1);
            else
                return 1 + puntoB(m,cp,dia+1,mes);
        }else{

            if(dia==30)
                return 0 + puntoB(m,cp,1,mes+1);
            else
                return 0 + puntoB(m,cp,dia+1,mes);

        }


    }

}

void puntoC(TLista *l,char cp[],float x){
    TLista ant,act,elim;
    TTemp t;
    FILE *arch;

    if (*l != NULL){
        if (strcmp((*l)->cp,cp)==0){
            arch=fopen("CIUDAD.txt","w"); //no se como poner el nombre del .txt como lo pide el ejercicio

            while(!vaciaP((*l)->p)){
                sacaP(&(*l)->p,&t);
                if(t.tempMax > x)
                    fprintf(arch,"%i %2.2f %2.2f\n",t.dia,t.tempMin,t.tempMax);

            }

            elim = *l;
            *l=(*l)->sig;
            free(elim);
        }
		else{
			act = *l;

			while (act != NULL &&  strcmp(act->cp,cp)!=0){
				ant = act;
				act = act -> sig;
			}
			if (act != NULL && strcmp(act->cp,cp)==0){

				arch=fopen("CIUDAD.txt","w");

				while(!vaciaP(act->p)){
                    sacaP(&act->p,&t);
                    if(t.tempMax > x)
                        fprintf(arch,"%i %2.2f %2.2f\n",t.dia,t.tempMin,t.tempMax);

                }

				ant->sig = act->sig;
				free(act);

			}else{
                printf("No se encontro el codigo postal\n");
			}
		}
	}

    if(arch!=NULL){
        fclose(arch);
    }

}
