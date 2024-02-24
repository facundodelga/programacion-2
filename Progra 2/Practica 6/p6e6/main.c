#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Se tiene una lista con equipos de fútbol (nombre y puntaje en el torneo), la cual está ordenada
descendentemente por puntaje (los equipos con el mismo puntaje están ordenados
alfabéticamente). Cada equipo cuenta con una sublista de jugadores (nombre y edad, estado
([A]ctivo, [S]uspendido)).
a) Listar para todos los clubes los jugadores cuyo nombre comienza con la letra K (dato). Al
finalizar mostrar cantidad de jugadores listados y el club que tiene más jugadores que
cumplan el criterio solicitado.
b) Listar los clubes que tienen un mínimo de X (dato) puntos junto con todos sus jugadores,
mostrando edad promedio de cada equipo.
c) Verificar si el equipo E (dato) tiene P (dato) puntos.
d) Eliminar los jugadores que se encuentren en estado inactivo en todos los equipos. */

typedef struct nodito{
    char nombre[20];
    int edad;
    char estado;
    struct nodito *sig;
}nodito;

typedef nodito *subLista;

typedef struct nodo{
    char club[20];
    int puntaje;
    subLista subL;
    struct nodo *sig;
}nodo;

typedef nodo *TLista;

void cargaLista(TLista *);
void muestraLista(TLista );
void puntoa(TLista ,char );
void puntob(TLista ,int );
int puntoc(TLista ,char *,int );
void puntod(TLista );

int main(){
    TLista l = NULL;

    cargaLista(&l);
    //muestraLista(l);
//    puntoa(l,'M');
//    puntob(l,18);
//    printf("\n[ %d ]\n",puntoc(l,"Boca",21));
//    printf("\n[ %d ]\n",puntoc(l,"Bover",21));
    puntod(l);
    muestraLista(l);
    return 0;
}


void cargaLista(TLista *l){
    FILE *arch;
    TLista nuevo,act,ant;
    subLista snuevo,sact,sant;
    char club[20],nombre[20],estado;
    int puntaje,edad;

    arch = fopen("p6e6.txt","r");

    while(fscanf(arch,"%s %d\n",club,&puntaje) == 2){
        nuevo = (TLista)malloc(sizeof(nodo));
        strcpy(nuevo->club,club);
        nuevo->puntaje = puntaje;
        nuevo->subL = NULL;

        while(fscanf(arch,"%s %d %c\n",nombre,&edad,&estado) == 3){
            snuevo = (subLista)malloc(sizeof(nodito));
            strcpy(snuevo->nombre,nombre);
            snuevo->edad = edad;
            snuevo->estado = estado;

            if(nuevo->subL == NULL){
                snuevo->sig = nuevo->subL;
                nuevo->subL = snuevo;
            }else{
                sact = nuevo->subL;

                while(sact != NULL){
                    sant = sact;
                    sact = sact->sig;
                }

                sant->sig = snuevo;
                snuevo->sig = sact;
            }
        }

        if(*l == NULL || (*l)->puntaje < puntaje || ((*l)->puntaje == puntaje && strcmp((*l)->club,club) > 0)){
            nuevo->sig = *l;
            *l = nuevo;
        }else{
            act = *l;
            while(act != NULL && puntaje < act->puntaje){
                ant = act;
                act = act->sig;
            }

            if(act != NULL && act->puntaje == puntaje){
                while(act != NULL && strcmp(act->club,club) > 0){
                    ant = act;
                    act = act->sig;
                }
            }

            ant->sig = nuevo;
            nuevo->sig = act;
        }

    }

    fclose(arch);

}

void muestraLista(TLista l){
    TLista aux = l;
    subLista saux;

    while(aux != NULL){
        printf("%s %d\n",aux->club,aux->puntaje);
        saux = aux->subL;
        while(saux != NULL){
           printf("%s %d %c\n",saux->nombre,saux->edad,saux->estado);
           saux=saux->sig;
        }
        aux = aux->sig;
        printf("\n");
    }
}

void puntoa(TLista l,char k){
    TLista aux = l;
    subLista saux;
    int contJugadores,cont = 0,maxJugadores = -1;
    char club[20];
    while(aux != NULL){
        printf("%s\n",aux->club);
        saux = aux->subL;
        contJugadores = 0;
        while(saux != NULL){
            if(saux->nombre[0] == k){
                printf("%s %d %c\n",saux->nombre,saux->edad,saux->estado);
                contJugadores++;
                cont++;
            }
            saux=saux->sig;
        }
        if(contJugadores > maxJugadores){
            maxJugadores = contJugadores;
            strcpy(club,aux->club);
        }
        aux = aux->sig;
        printf("\n");
    }

    printf("cantidad de jugadores listados: %d \nclub con mas jugadores con la letra %c : %s\n",cont,k,club);
    printf("\n");

}

void puntob(TLista l,int puntos){
    TLista aux = l;
    subLista saux;
    int suma,cont;
    while(aux != NULL){

        if(aux->puntaje >= puntos){
            printf("%s %d\n",aux->club,aux->puntaje);
            saux = aux->subL;
            suma = 0;
            cont = 0;

            while(saux != NULL){
               printf("%s %d\n",saux->nombre,saux->edad);
               suma += saux->edad;
               cont++;
               saux=saux->sig;
            }
            printf("promedio edad: %d\n",suma/cont);

        }

        aux = aux->sig;
        printf("\n");
    }
}

int puntoc(TLista l,char club[20],int puntos){
    TLista aux = l;
    while(aux != NULL && strcmp(aux->club,club) != 0 && aux->puntaje != puntos)
        aux = aux->sig;
    return aux != NULL && strcmp(aux->club,club) == 0 && aux->puntaje == puntos;
}

void puntod(TLista l){
    TLista aux = l;
    subLista saux,ant,elim;

    while(aux != NULL){
        saux = aux->subL;
        ant = NULL;
        while(saux != NULL){

            if(ant == NULL && saux->estado == 'S'){
                elim = aux->subL;
                aux->subL = aux->subL->sig;
                saux = saux->sig;
                free(elim);
            }else{
                if(saux->estado == 'S'){
                    ant->sig = saux->sig;
                    elim = saux;
                    saux = saux->sig;
                    free(elim);
                }else{
                    ant = saux;
                    saux = saux->sig;
                }

            }

        }

        aux = aux->sig;
    }
}



