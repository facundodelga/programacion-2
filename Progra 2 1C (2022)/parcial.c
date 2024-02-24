#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Progra 2\mis libs\colaE.h"
#define maxNac 4

typedef struct{
    char codigo[8];
    char nacionalidad[4];
    char disciplina[3];
}TCompe;

typedef struct nodito{
    int puntuacion;
    struct nodito *sig;
}nodito;

typedef nodito * TSLista;

typedef struct nodo{
    TCompe participante;
    struct nodo *sig;
    TSLista subL;
}nodo;

typedef nodo * TLista;

typedef struct nodod{
    char codigo[8];
    float puntajeFinal;
    int intentos;
    TCola puntajeIntento;
    struct nodod *ant,*sig;
}nodod;

typedef struct nodod * pnodod;

typedef struct{
    pnodod pri,ult;
}TListaD;

void puntoA(TLista *,char []);
void puntob(TLista ,TListaD *);

int main(){
    TLista l=NULL;
    TListaD LD;
    char nacionalidad[maxNac];
    LD.pri=NULL;
    LD.ult=NULL;

    scanf("nacionalidad ==> %s \n",nacionalidad);

    puntoA(&l,nacionalidad);

    puntob(l,&LD);

    return 0;
}


void puntoA(TLista *l,char nac[]){
    TCompe participante;
    TLista aux=*l;
    TSLista auxSl,ant,nuevoSl,antMenor,menorSl,antMayor,mayorSl,elim;
    int menor,mayor;
    FILE *arch;

    arch=fopen("DEPURAN.txt","w");

    while (aux!=NULL && strcmp(aux->participante.nacionalidad,nac)!=0 ){
        aux=aux->sig;
    }

    while (aux!=NULL && strcmp(aux->participante.nacionalidad,nac)==0 ){
            auxSl=aux->subL;
            //nuevoSl=aux->subL;
            antMenor=NULL;
            antMayor=NULL;
            menor=11;
            mayor=-1;
            ant=NULL;
            while(auxSl!=NULL){

                if(auxSl->puntuacion<menor){
                    menorSl=auxSl;
                    menor=auxSl->puntuacion;
                    if (ant!=NULL)
                        antMenor=ant;

                }else{

                    if(auxSl->puntuacion>mayor){
                        mayorSl=auxSl;
                        mayor=auxSl->puntuacion;
                        if (ant!=NULL)
                            antMayor=ant;
                    }

                }
                ant=auxSl;
                auxSl=auxSl->sig;

            }

            fprintf(arch,"%s  %d  %d\n",aux->participante.codigo,menor,mayor);

            if(antMenor==NULL){
                aux->subL=aux->subL->sig;
                if(menorSl==antMayor)
                    antMayor=NULL;
                free(menorSl);
            }else{
                antMenor->sig=menorSl->sig;
                if(menorSl==antMayor)
                    antMayor=antMenor;
                free(menorSl);
            }

            if(antMayor==NULL){
                aux->subL=aux->subL->sig;
                free(mayorSl);
            }else{
                antMayor->sig=mayorSl->sig;
                free(mayorSl);
            }

        aux=aux->sig;
    }
    fclose(arch);

}



void puntob(TLista l,TListaD *LD){
    TLista aux=l;
    pnodod nuevo,act,auxLD;
    TSLista auxSl;
    int jurados,sumaPuntos,insertar;
    TCompe partAnt;
    LD->pri=NULL;
    LD->ult=NULL;

    while(aux!=NULL){
        nuevo=(pnodod)malloc(sizeof(nodod));

        strcpy(nuevo->codigo,aux->participante.codigo);


        auxSl=aux->subL;

        while(auxSl!=NULL){
            sumaPuntos += auxSl->puntuacion;
            jurados++;

        }

        auxLD=LD->pri;
        if(strcmp(nuevo->codigo,LD->pri->codigo)==0){
            (LD->pri->intentos)++;
            poneC(&LD->pri->puntajeIntento,sumaPuntos/jurados);

            if(LD->pri->puntajeFinal<sumaPuntos/jurados)
                LD->pri->puntajeFinal=sumaPuntos/jurados;
            free(nuevo);
        }else{
            if (strcmp(nuevo->codigo,LD->ult->codigo)==0){
                (LD->ult->intentos)++;
                poneC(&LD->ult->puntajeIntento,sumaPuntos/jurados);

                if(LD->ult->puntajeFinal<sumaPuntos/jurados)
                    LD->ult->puntajeFinal=sumaPuntos/jurados;
                free(nuevo);
            }else{

                while(auxLD!=NULL && insertar==1){   //busco si existe el nodo
                    if(strcmp(nuevo->codigo,auxLD->codigo)==0)
                        insertar=0;
                    else
                        auxLD=auxLD->sig;


                }

                if(insertar == 0){          //si ya existe el nodo
                    (auxLD->intentos)++;
                    poneC(&auxLD->puntajeIntento,sumaPuntos/jurados);

                    if(auxLD->puntajeFinal<sumaPuntos/jurados)
                        auxLD->puntajeFinal=sumaPuntos/jurados;

                    free(nuevo);

                }else{ //si no existe inserto

                    poneC(&nuevo->puntajeIntento,sumaPuntos/jurados);
                    nuevo->puntajeFinal = sumaPuntos/jurados;
                    nuevo->intentos = 1;

                    if (LD->pri == NULL || strcmp(nuevo->codigo,LD->pri->codigo)<0){		//entro al principio
                        nuevo->ant = NULL;
                        nuevo->sig = LD->pri;
                        if (LD->pri == NULL){		//si la lista está vacía
                            LD->ult = nuevo;				//el ultimo es el nuevo
                        }else							//si no está vacíá
                            LD->pri->ant = nuevo;			//cambio anterior del segundo
                        LD->pri = nuevo;				//cambio cabeza
                    }
                    else{

                        if ( strcmp(nuevo->codigo,LD->ult->codigo)>0 ){		//entro si entra al final
                            nuevo->sig = NULL;				//el siguiente es nulo
                            nuevo->ant = LD->ult;			//el anterior es el ultimo
                            LD->ult->sig = nuevo;			//es el siguiente del penultimo
                            LD->ult = nuevo;				//el nuevo es el ultimo
                        }else{
                            act = LD->pri;						//entro en el medio
                            while (strcmp(nuevo->codigo,act->codigo)>0)			//avanzo hasta la posicion donde se encuentre
                                act=act->sig;
                            nuevo->ant = act->ant;			//asigno anterior
                            nuevo->sig = act;				//asigno siguiente
                            act->ant->sig = nuevo;			//cambio siguiente
                            act->ant = nuevo;				//cambio anterior
                        }
                    }
                   }

                }

        }

        aux=aux->sig;
    }

}
