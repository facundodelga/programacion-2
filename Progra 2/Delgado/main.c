#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilaD.h"

typedef struct{
    char cod_materia[6];
    int cuatrimestre;
    unsigned int creditos;
}TElementoP;

typedef struct nodoS{
    char correlativas[6];
    struct nodoS *sig;
}nodoS;

typedef nodoS *TsubL;

typedef struct nodo{
    char cod_materia[6];
    char nombre[26];
    int anio;
    int cuatrimestre;
    char tipo;
    unsigned int creditos;
    TsubL subL;
    struct nodo * sig;
}nodo;

typedef nodo *TLista;

typedef struct nodoD{
    int anio;
    TPila p;
    struct nodoD *ant,*sig;
}nodoD;

typedef nodoD *PnodoD;

typedef struct{
    PnodoD pri,ult;
}TListaD;

void cargaLista(TLista *);

void puntoiA(TLista ,TLista ,char []);
void puntoiB(TLista ,TListaD *);
void puntoiC(TLista *,TListaD ,TPila *,char [],int);


int main(){
    TLista l=NULL,busca;
    TListaD ld;
    TPila p=NULL;
    char cod_mat[6];

    ld.pri = NULL;
    ld.ult = NULL;

    cargaLista(&l);
    printf("codigo de materia\n");
    scanf("%s",cod_mat);
    busca = l;
    while(busca != NULL && strcmp(busca->cod_materia,cod_mat) == 0)
        busca = busca->sig;

    if(busca){
        puntoiA(l,busca,cod_mat);
    }
    puntoiB(l,&ld);

    printf("codigo de materia para eliminar\n");
    scanf("%s",cod_mat);

    puntoiC(&l,ld,&p,cod_mat,0);

    return 0;
}

void cargaLista(TLista *l){
    //desarrollo
}

void puntoiA(TLista l,TLista materia,char cod_materia[]){
    FILE *arch;
    char archivo[10];
    TLista aux;
    TsubL auxS = materia->subL;
    float acumCreditos = 0.0;
    int contCorrelativas = 0;

    strcpy(archivo,cod_materia);
    strcat(archivo,".txt");

    arch = fopen(archivo,"w");
    fprintf(arch,"%s %d %d\n",materia->nombre,materia->anio,materia->cuatrimestre);
    if(auxS){

        while(auxS!=NULL){
            aux = l; //vuelvo a la cabecera para poder buscar ya que no estan ordenados
            while(aux!=NULL && strcmp(aux->cod_materia,auxS->correlativas) != 0)
                aux=aux->sig;

            if(aux != NULL && strcmp(aux->cod_materia,auxS->correlativas) != 0){
                fprintf(arch,"%s\n",aux->nombre);
                acumCreditos += aux->creditos;
                contCorrelativas++;
            }

            auxS = auxS->sig;
        }
        fprintf(arch,"%2.2f\n",acumCreditos/contCorrelativas);
    }else{
        fprintf(arch,"NO TIENE CORRELATIVAS ANTERIORES\n");
    }

    fclose(arch);
}


void puntoiB(TLista l,TListaD *ld){
    TLista aux = l;
    PnodoD nuevo,auxd;
    TElementoP obligatoria;
    while(aux){
        //insercion del año en lista doble
        if(ld->pri == NULL || aux->anio < ld->pri->anio){
            nuevo = (PnodoD)malloc(sizeof(nodoD));
            nuevo->anio = aux->anio;
            IniciaP(&nuevo->p);

            if(aux->tipo == 'O'){ // si es obligatoria inserto en la pila
                strcpy(obligatoria.cod_materia,aux->cod_materia);
                obligatoria.creditos = aux->creditos;
                obligatoria.cuatrimestre = aux->cuatrimestre;
                poneP(&nuevo->p,obligatoria);
            }

            nuevo->ant = NULL;
            nuevo->sig = ld->pri;
            if (ld->pri == NULL)
                ld->ult = nuevo;
            else
                ld->pri->ant = nuevo;

            ld->pri = nuevo;
        }else{
            if(ld->ult->anio < aux->anio){
                nuevo = (PnodoD)malloc(sizeof(nodoD));
                nuevo->anio = aux->anio;
                IniciaP(&nuevo->p);

                if(aux->tipo == 'O'){
                    strcpy(obligatoria.cod_materia,aux->cod_materia);
                    obligatoria.creditos = aux->creditos;
                    obligatoria.cuatrimestre = aux->cuatrimestre;
                    poneP(&nuevo->p,obligatoria);
                }

                nuevo->sig = NULL;
                nuevo->ant = ld->ult;
                ld->ult->sig = nuevo;
                ld->ult = nuevo;
            }else{
                auxd = ld->pri;
                while(auxd != NULL && aux->anio > auxd->anio)
                    auxd = auxd->sig;

                if(auxd != NULL && auxd->anio == aux->anio && aux->tipo == 'O'){

                    strcpy(obligatoria.cod_materia,aux->cod_materia);
                    obligatoria.creditos = aux->creditos;
                    obligatoria.cuatrimestre = aux->cuatrimestre;
                    poneP(&auxd->p,obligatoria);

                }else{

                    if(auxd != NULL && aux->anio < auxd->anio){
                        nuevo = (PnodoD)malloc(sizeof(nodoD));
                        nuevo->anio = aux->anio;
                        IniciaP(&nuevo->p);

                        if(aux->tipo == 'O'){
                            strcpy(obligatoria.cod_materia,aux->cod_materia);
                            obligatoria.creditos = aux->creditos;
                            obligatoria.cuatrimestre = aux->cuatrimestre;
                            poneP(&nuevo->p,obligatoria);
                        }

                        nuevo->ant = auxd->ant;
                        nuevo->sig = auxd;
                        auxd->ant->sig = nuevo;
                        auxd->ant = nuevo;
                    }

                }
            }
        }

        aux = aux->sig;
    }

}

void puntoiC(TLista *l,TListaD ld,TPila *p,char cod_mat[],int recursivo){
    TLista ant = NULL,aux = *l;
    int anio;
    TElementoP x;
    TsubL auxs,ants,elimsl;
    PnodoD auxd;
    if(recursivo == 0){
        while(aux != NULL && strcmp(aux->cod_materia,cod_mat) != 0){
            ant = aux;
            aux = aux->sig;
        }

        if(aux != NULL){
            anio = aux->anio;
            while(aux->subL != NULL){ //libero todo lo que hay dentro de la sublista de la materia
                elimsl = aux->subL;
                aux->subL = aux->subL->sig;
                free(elimsl);
            }
            if(ant) //elimino de la lista principal
                ant->sig = aux->sig;
            else
                *l = (*l)->sig;
            free(aux);


            aux = *l;
            //comienzo a buscar en las sublistas
            while(aux){
                auxs = aux->subL;
                ants = NULL;
                while(auxs != NULL && strcmp(auxs->correlativas,cod_mat) != 0){
                    ants = auxs;
                    auxs = auxs->sig;
                }

                if(auxs){
                    if(ants)
                        ants->sig = auxs->sig;
                    else
                        aux->subL = aux->subL->sig;

                    free(auxs);
                }

                aux = aux->sig;
            }

            if(ld.pri){ //elimino de la lista doble
                auxd = ld.pri;
                while(auxd != NULL && auxd->anio != anio)
                    auxd = auxd->sig;

                if(auxd != NULL && !VaciaP(auxd->p))
                    puntoiC(l,ld,&auxd->p,cod_mat,1); //llamado recursivo
            }

        }else{
            printf("NO EXISTE LA MATERIA\n");

        }

    }else{
        if(!VaciaP(*p)){ //eliminacion en la pila
            sacaP(p,&x);
            puntoiC(l,ld,p,cod_mat,1);
            if(strcmp(x.cod_materia,cod_mat) != 0)
                poneP(p,x);
        }
    }
}

