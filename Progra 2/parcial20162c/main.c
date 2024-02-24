#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct nodo{
    char facultad[21];
    TPila p;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct nodod{
    char facultad[21];
    int DNI;
    float promedio;
    int orden;
    struct nodod *ant, *sig;
}nodod;

typedef nodod *PnodoD;

typedef struct{
    PnodoD pri,ult;
}TListaD;

void cargalista(TLista *);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void cargalista(TLista *l){
    FILE *arch;
    TLista aux,nuevo,ant;
    TElementoP titulo;
    char facultad[21];
    arch = fopen("TITULOS.txt","r");

    while(fscanf(arch,"%s %d %f\n",facultad,&titulo.DNI,&titulo.promedio) == 3){
        nuevo = (TLista)malloc(sizeof(nodo));
        IniciaP(&nuevo->p);
        strcpy(nuevo->facultad,facultad);

        if(*l == NULL || strcmp(facultad,(*l)->facultad) < 0){
            poneP(&nuevo->p,titulo);
            nuevo->sig = *l;
            *l = nuevo;
        }else{
            aux = *l;
            ant = NULL;
            while(aux != NULL && strcmp(facultad,aux->facultad) > 0){
                ant = aux;
                aux = aux->sig;
            }

            if(strcmp(facultad,aux->facultad) == 0)
                poneP(&aux->p,titulo);
            else{ //aux es mayor o NULL
                poneP(&nuevo->p,titulo);
                ant->sig = nuevo;
                nuevo->sig = aux;
            }
        }
    }

    fclose(arch);
}

void puntob(TLista *l,TListaD *LD){
    char facultad[21];
    int dni;
    TElementoP TP;
    PnodoD nuevo;
    TLista aux,ant;
    TPila auxP;
    IniciaP(&auxP);
    printf("facultad (0 para salir):\n");
    scanf("%s",facultad);
    while(strcmp(facultad,"0") != 0){
        aux = *l;
        ant = NULL;
        while(aux != NULL && strcmp(facultad,aux->facultad) < 0){ //busco facultad
            ant=aux;
            aux = aux->sig;
        }
        if(strcmp(facultad,aux->facultad) == 0){ //encuentre facultad y busco DNI
            printf("Dni):\n");
            scanf("%d",&dni);

            do{
                sacaP(&aux->p,&TP);
                poneP(&auxP,TP);
            }while(!VaciaP(aux->p) && TP.DNI != dni);

            if(TP.DNI == dni){ //si encuentro DNI procedo a insertar en la lista doble
                nuevo = (PnodoD)malloc(sizeof(nodod));
                strcpy(nuevo->facultad,facultad);
                nuevo->DNI = TP.DNI;
                nuevo->promedio = TP.promedio;

                if(LD->pri == NULL){ //si la lista esta vacia
                    nuevo->orden = 1;
                    nuevo->ant = NULL;
                    LD->ult = nuevo;
                    LD->pri = nuevo;
                }else{ //inserto al final
                    nuevo->orden = LD->ult->orden +1;
                    nuevo->sig = NULL;
                    nuevo->ant = LD->ult;
                    LD->ult->sig = nuevo;
                    LD->ult = nuevo;

                }

                if(VaciaP(auxP) && VaciaP(aux->p)){ //si la pila auxiliar esta vacia y la pila de la lista tambien elimino el nodo de la lista
                    if(aux == *l)
                        *l = (*l)->sig;
                    else
                        ant->sig = aux->sig;

                    free(aux);
                }else{ //restituyo los titulos no eliminados
                    while(!VaciaP(auxP)){
                        sacaP(&auxP,&TP);
                        poneP(&(aux->p),TP);
                    }
                }

            }else
                printf("DNI NO ENCONTRADO\n");


        }else
            printf("FACULTAD NO ENCONTRADA\n");
    }
}

void listarTitulos(TListaD LD, char x[]){
    PnodoD aux = LD.pri,mejorProm = NULL;
    float promMax = -1;
    while(aux){
        printf("[%d] %s %d %2.2f\n",aux->orden,aux->facultad,aux->DNI,aux->promedio);
        if(strcmp(aux->facultad,x) == 0 && promMax < aux->promedio){
            mejorProm = aux;
            promMax = aux->promedio;
        }
        aux = aux->sig;
    }

    if(mejorProm){
        printf("Alumno con mejor promedio\n");
        printf("%s %d %2.2f\n",aux->facultad,aux->DNI,aux->promedio);
    }
}


void eliminaTitulo(TListaD *LD, int DNI){
	PnodoD act;
	if (LD->pri != NULL){
		if (LD->pri == LD->ult && LD->pri->DNI == DNI){ //es Unico Elemento
			act = LD->pri;
			LD->pri = NULL;
			LD->ult = NULL;
			free(act);
		}else{
			act = LD->pri;
			while (act != NULL && act->DNI != DNI) //busco el nodo a eliminar
				act = act->sig;
            if(act){
                if (act == LD->pri){ //Elimino el primero
                    LD->pri = LD->pri->sig;
                    LD->pri->ant = NULL;
                }else{
                    if (act == LD->ult){ //Elimino el ultimo
                        LD->ult = LD->ult->ant;
                        LD->ult->sig = NULL;
                    }else{
                        act->ant->sig = act->sig;
                        act->sig->ant = act->ant;

                    }
                }
                free(act);
            }
		}
	}
}

















