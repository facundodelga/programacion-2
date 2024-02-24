#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

typedef struct{
    char nombre[MAX];
    int edad;
    char estado;
}TJugador;

typedef struct{
    char nombreClub[MAX];
    int puntos;
}TClub;

typedef struct nodito{
    TJugador jugador;
    struct nodito * sig;
}nodito;

typedef struct nodo{
    TClub club;
    struct nodo* sig;
    nodito *subL;
}nodo;

typedef nodo *TLista;
typedef nodito *TSLista;

TLista creaNodo(TClub,TSLista);
TSLista creaNodito(TJugador);
void insertaSubL(TSLista *,TJugador);
void insertaOrdL(TLista *,TClub,TSLista);
void cargaLista(TLista *);
void listaJugadoresInicial(TLista,char ); //punto a
void listaJugadoresPuntos(TLista ,int );//punto b
void buscaPuntos(TLista ,int ,TClub *); //punto c
void eliminaE(TSLista *);
void puntoD(TLista );
void mostrarLista(TLista );

int main()
{
    TLista l=NULL;
    TClub c;
    cargaLista(&l);
    //listaJugadoresInicial(l,'K');
    //listaJugadoresPuntos(l,18);
    //buscaPuntos(l,21,&c);
    //printf("EQUIPO: %s  PUNTOS: %d\n",c.nombreClub,c.puntos);
    //printf("\n");
    puntoD(l);
    mostrarLista(l);
    return 0;
}

TLista creaNodo(TClub c,TSLista subL){
    TLista aux=NULL;

    aux=(TLista)malloc(sizeof(nodo));

    aux->club=c;
    aux->subL=subL;
    aux->sig=NULL;

    return aux;

}

TSLista creaNodito(TJugador j){
    TSLista auxSL=NULL;

    auxSL=(TSLista)malloc(sizeof(nodito));

    auxSL->jugador=j;
    auxSL->sig=NULL;

    return auxSL;
}

void insertaSubL(TSLista *sL,TJugador j){
    TSLista aux=*sL,nuevo=NULL;
    //printf("%s \n",j.nombre);
    nuevo=creaNodito(j);

    if (aux!=NULL){
        while (aux->sig!=NULL){
            aux=aux->sig;
        }

        aux->sig=nuevo;
    }else{

        *sL=nuevo;
    }

}


void insertaOrdL(TLista *l,TClub c,TSLista sL){
    TLista act=*l,nuevo,ant=NULL;

    nuevo=creaNodo(c,sL);

    if(*l==NULL || c.puntos < (*l)->club.puntos || (c.puntos == (*l)->club.puntos && strcmp(c.nombreClub,(*l)->club.nombreClub)<0)){
        nuevo->sig=*l;
        *l=nuevo;
    }else{
        while(act!=NULL && c.puntos > act->club.puntos){
            ant=act;
            act=act->sig;
        }

        if(c.puntos == (*l)->club.puntos){

            while(act!=NULL && strcmp(c.nombreClub,act->club.nombreClub)>0 && c.puntos == (*l)->club.puntos ){
                ant=act;
                act=act->sig;
            }

        }

        nuevo->sig=act;
        ant->sig=nuevo;

    }

}


void cargaLista(TLista *l){
    TSLista listaClub=NULL;
    TClub club;
    int op;
    TJugador jugador;
    FILE *arch;

    arch=fopen("p6ej6.txt","r");

    while(!feof(arch)){
        fscanf(arch,"%d %s %d\n",&op,club.nombreClub,&club.puntos);
        //printf("%s %d\n",club.nombreClub,club.puntos);

        while(op==1){
            fscanf(arch,"%d %s %d %c\n",&op,jugador.nombre,&jugador.edad,&jugador.estado);
            //printf("==> %s %d %c\n",jugador.nombre,jugador.edad,jugador.estado);
            insertaSubL(&listaClub,jugador);
        }

        insertaOrdL(l,club,listaClub);
        listaClub=NULL;

    }
    fclose(arch);

}

void listaJugadoresInicial(TLista l,char inicial){
    TLista aux=l;
    TSLista auxSl=NULL;
    int cantJugadores=0,maxJugadores=-1,i=0;
    TClub c;

    printf("LISTA DE JUGADORES CON LETRA [ %c ]\n",inicial);

    while(aux!=NULL){
        printf("%s %i\n",aux->club.nombreClub,aux->club.puntos);
        auxSl=aux->subL;
        while(auxSl!=NULL){
            //printf("%s\n",auxSl->jugador.nombre);
            if(auxSl->jugador.nombre[0] == inicial){
                printf("%s\n",auxSl->jugador.nombre);
                cantJugadores++;
                i++;
            }

            auxSl=auxSl->sig;
        }
        if(cantJugadores>maxJugadores){
            maxJugadores=cantJugadores;
            c=aux->club;
        }
        cantJugadores=0;
        aux=aux->sig;
    }
    printf("\n");
    printf("cant jugadores listados: %d\n",i);
    printf("\n");
    printf("el club que tiene mas jugadores con la inicial [ %c ]:  %s\n",inicial,c.nombreClub);
    printf("\n");
}

void listaJugadoresPuntos(TLista l,int puntos){
    TLista aux=l;
    TSLista auxSl=NULL;
    int cantJugadores,contEdades;

    printf("EQUIPOS CON PUNTAJE MINIMO DE [ %d ]\n",puntos);
    printf("\n");
    while(aux!=NULL){

        if ( puntos <= aux->club.puntos ){
            printf("%s %i\n",aux->club.nombreClub,aux->club.puntos);
            auxSl=l->subL;
            while(auxSl!=NULL){
                printf("%s\n",auxSl->jugador.nombre);
                cantJugadores++;
                contEdades += auxSl->jugador.edad;
                auxSl=auxSl->sig;
            }
            printf("\n");
            printf("Promedio de edad: %2.2f\n",(float)contEdades/cantJugadores);
            printf("\n");
            contEdades=0;
            cantJugadores=0;

        }

        aux=aux->sig;

    }

}

void buscaPuntos(TLista l,int puntos,TClub *c){
    TLista aux=l;
    *c=aux->club;

    while(aux!=NULL && puntos!=aux->club.puntos){
        aux=aux->sig;
    }

    if(puntos==aux->club.puntos){
        *c=aux->club;
    }
}
void puntoD(TLista L){
    TLista aux=L;
    while(aux!=NULL){
        eliminaE(&aux->subL);
        aux=aux->sig;
    }
}
void eliminaE(TSLista *sl){
    TSLista act=*sl,aux;

    while(act!=NULL){
        if ((*sl)->jugador.estado=='S'){
            aux=(*sl)->sig;
            *sl=(*sl)->sig;
            act=act->sig;
            free(aux);
        }else{
            if(act->sig!=NULL && act->sig->jugador.estado=='S'){
                aux=act->sig;
                act->sig=act->sig->sig;
                free(aux);
            }else{
                act=act->sig;
            }
        }
    }
}

void mostrarLista(TLista lista){
    TLista aux=lista;
    TSLista aux2=NULL;
    if(aux!=NULL){
        while (aux!=NULL){
            printf("Club: %s   Puntos: %d\n",aux->club.nombreClub,aux->club.puntos);
            aux2=aux->subL;
            while(aux2!=NULL){
                printf("==> Jugador: %s   Edad: %d  Condicion: %c\n",aux2->jugador.nombre,aux2->jugador.edad,aux2->jugador.estado);
                aux2=aux2->sig;

            }
            aux=aux->sig;
        }
    }
}








