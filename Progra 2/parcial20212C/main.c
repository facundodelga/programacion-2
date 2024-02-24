#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaE.h"

typedef struct nodito{
    int punt;
    struct nodito *sig;
}nodito;

typedef nodito *TsubL;

typedef struct nodo{
    char cod_gim[9];
    char cod_nac[5];
    char cod_dis[4];
    TsubL subL;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

typedef struct nodod{
    char cod_gim[9];
    float puntFinal;
    int intentos;
    TCola c;
    struct nodod *ant,*sig;
}nodod;

typedef nodod *pnodod;

typedef struct{
    pnodod pri,ult;
}TListaD;

void punto1a(TLista *,char []);


int main(){

    return 0;
}


void punto1a(TLista *l,char nac[]){
    TLista aux = *l;
    TsubL auxs,ants,mejor,mejorAnt,peor,peorAnt;
    int mejor_p,peor_p;
    FILE *arch;

    while(aux!=NULL && strcmp(aux->cod_nac,nac) < 0){ //paro en la nacionalidad si la encuentro
        aux = aux->sig;
    }

    if(aux && strcmp(aux->cod_nac,nac) == 0){
        arch = fopen("DEPURAN.txt","rt");

        while(aux!=NULL && strcmp(aux->cod_nac,nac) == 0){
            auxs = aux->subL;
            ants = NULL;
            mejor_p = -1;
            peor_p = 11;
            mejorAnt = NULL;
            peorAnt = NULL;

            while(auxs != NULL){
                if(mejor_p < auxs->punt){
                    if(ants)
                        mejorAnt = ants;
                    mejor_p = auxs->punt;
                    mejor = auxs;
                }
                if(peor_p > auxs->punt){
                    if(ants!=NULL && ants!=mejor) //peorAnt sea distinto de mejor
                        peorAnt = ants;
                    peor_p = auxs->punt;
                    peor = auxs;
                }

                ants = auxs;
                auxs = auxs->sig;
            }

            fprintf(arch,"%s %d %d\n",aux->cod_gim,peor->punt,mejor->punt);

            if(mejorAnt == NULL){
                if(peor == aux->subL->sig)
                    aux->subL = peor->sig;
                else
                    aux->subL = aux->subL->sig;
            }else{
                if(peor == mejor->sig)
                    mejorAnt->sig = peor->sig;
                else
                    mejorAnt->sig = mejor->sig;
            }

            if(peorAnt == NULL){
                if(aux->subL == peor)
                    aux->subL = aux->subL->sig;
            }else
                if(peorAnt != mejorAnt)
                    peorAnt->sig = peor->sig;

            free(mejor);
            free(peor);

            aux = aux->sig;
        }

        fclose(arch);
    }else
        printf("No hay gimnastas de %s\n",nac);

}

//HACER PUNTO 1B
void punto1b(TLista l,TListaD *LD){
    TLista aux = l;
    TsubL auxs;
    pnodod auxd,nuevo;
    int contJurados = 0, cuentaGimnasta = 0;
    float acupuntajefinal = 0.0, cuentaIntentos = 0.0;
    TElementoC puntaje;
    while(aux){
        auxs = aux->subL;
        acupuntajefinal = 0.0;
        contJurados = 0;
        while(auxs){
            acupuntajefinal += auxs->punt;
            contJurados++;
            auxs = auxs->sig;
        }

        puntaje = acupuntajefinal / contJurados;
        if(LD->pri == NULL || strcmp(aux->cod_gim,LD->pri->cod_gim) == 0){
            //asignaciones e inicializaciones
            nuevo = (pnodod)malloc(sizeof(nodod));
            strcpy(nuevo->cod_gim,aux->cod_gim);
            nuevo->intentos = 1;
            IniciaC(&nuevo->c);
            poneC(&nuevo->c,puntaje);
            nuevo->puntFinal = acupuntajefinal / contJurados;
            nuevo->ant = NULL;
            nuevo->sig = LD->pri;
            cuentaGimnasta++;
            if(LD->pri)
                LD->pri->ant = nuevo;
            else
                LD->ult = nuevo;
            LD->pri = nuevo;

        }else{
            if(strcmp(aux->cod_gim,LD->ult->cod_gim) > 0){
                nuevo = (pnodod)malloc(sizeof(nodod));
                strcpy(nuevo->cod_gim,aux->cod_gim);
                nuevo->intentos = 1;
                IniciaC(&nuevo->c);
                poneC(&nuevo->c,puntaje);
                nuevo->puntFinal = acupuntajefinal / contJurados;
                nuevo->sig = NULL;
                nuevo->ant = LD->ult;
                LD->ult->sig = nuevo;
                LD->ult = nuevo;
                cuentaGimnasta++;
            }else{
                auxd = LD->pri;
                while(auxd != NULL && strcmp(aux->cod_gim,auxd->cod_gim) > 0)
                    auxd = auxd->sig;

                if(auxd != NULL && strcmp(aux->cod_gim,auxd->cod_gim) == 0){
                    poneC(&auxd->c,puntaje);
                    auxd->intentos += 1;
                    if(auxd->puntFinal < acupuntajefinal / contJurados)
                        auxd->puntFinal = acupuntajefinal / contJurados;
                }else{
                    nuevo = (pnodod)malloc(sizeof(nodod));
                    strcpy(nuevo->cod_gim,aux->cod_gim);
                    nuevo->intentos = 1;
                    IniciaC(&nuevo->c);
                    poneC(&nuevo->c,puntaje);
                    nuevo->puntFinal = acupuntajefinal / contJurados;

                    nuevo->sig = auxd;
                    nuevo->ant = auxd->ant;
                    auxd->ant->sig = nuevo;
                    auxd->ant = nuevo;
                }
            }
        }
        aux = aux->sig;
    }
    auxd = LD->pri;
    while(auxd){
        cuentaGimnasta++;
        cuentaIntentos += auxd->intentos;
    }

    printf("promedio de intentos por gimnasta: %2.2f\n",cuentaIntentos/cuentaGimnasta);

}
