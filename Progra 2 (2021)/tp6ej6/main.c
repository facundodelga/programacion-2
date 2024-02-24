#include <stdio.h>
#include <stdlib.h>
typedef struct clubes{
    char club[15];
    unsigned short int puntaje;
}TClub;

typedef struct jugadores{
    char nombre[15],condicion;
    unsigned short int edad;
}TJugador;

typedef struct nodo{
    TClub dClub;
    struct nodo *sig;
}nodo;

typedef struct nodito{
    TJugador jugador;
    struct nodito *sig;
}nodito;

typedef struct nodoB{
    TClub dClub;
    struct nodoB *sig;
    nodito *subL;
}nodoB;

void cargarLista();
nodoB* cargarNodoB(TClub x,nodito* sub);
nodito* cargarNodito(TJugador x);
void insertarNodoB(nodoB **lista,nodito *subLista,TClub dato);
void insertarNodito(nodito **subLista, TJugador x);
void mostrarLista(nodoB *lista);
void mostrarListaIniciales(nodoB* ,char );
void minimoPuntajeYPromEdad(nodoB*,unsigned short int);

int main(){
    nodoB *listaPosiciones=NULL;
    char inicial_jugador='M';
    cargarLista(&listaPosiciones);
    mostrarLista(listaPosiciones);
    mostrarListaIniciales(listaPosiciones,inicial_jugador);
    minimoPuntajeYPromEdad(listaPosiciones,20);
//    free(listaPosiciones);
    return 0;
}

nodoB* cargarNodoB(TClub x,nodito* sub){
    nodoB *aux=(nodoB*)malloc(sizeof(nodoB));
    if (aux!=NULL){
        aux->dClub=x;
        aux->subL=sub;
        aux->sig=NULL;
    }
    return aux;
}
nodito* cargarNodito(TJugador x){
    nodito* aux=(nodito*)malloc(sizeof(nodito));
    if (aux!=NULL){
        aux->jugador=x;
        aux->sig=NULL;
    }
    return aux;
}

void insertarNodoB(nodoB **lista,nodito *subLista,TClub dato){
    nodoB* nuevo = NULL,*aux=*lista;

    nuevo = cargarNodoB(dato,subLista);

    if( nuevo != NULL ){
        if (*lista==NULL){
            nuevo->sig = *lista;
            *lista = nuevo;
        }else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }

    }
}
void insertarNodito(nodito **subLista, TJugador x){
    nodito* nuevo = NULL, *aux=*subLista;

    nuevo = cargarNodito(x);

    if( nuevo != NULL ){
        if (*subLista==NULL){
            nuevo->sig = *subLista;
            *subLista = nuevo;
        }else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;

        }

    }
}

void cargarLista(nodoB **listaPos){
    FILE *arch;
    int op;
    TClub c;
    TJugador j;
    nodito* subLista=NULL;
    arch=fopen("tp6ej6.txt","r");

    while(!feof(arch)){
        op=1;
        subLista=NULL;
        fscanf(arch,"%s %d\n",&c.club,&c.puntaje);
        //printf("%s %d\n",c.club,c.puntaje);
        while(op!=0){
            fscanf(arch,"%s %d %c %d\n",&j.nombre,&j.edad,&j.condicion,&op);
            //printf("%s %d %c %d\n",j.nombre,j.edad,j.condicion,op);
            insertarNodito(&subLista,j);
        }
        insertarNodoB(listaPos,subLista,c);
    }
    fclose(arch);
}

void mostrarLista(nodoB *lista){
    nodoB *aux=lista;
    nodito *aux2=NULL;
    if(aux!=NULL){
        while (aux!=NULL){
            printf("Club: %s   Puntos: %d\n",aux->dClub.club,aux->dClub.puntaje);
            aux2=aux->subL;
            while(aux2!=NULL){
                printf("==> Jugador: %s   Edad: %d  Condicion: %c\n",aux2->jugador.nombre,aux2->jugador.edad,aux2->jugador.condicion);
                aux2=aux2->sig;

            }
            aux=aux->sig;
        }
    }

}

void mostrarListaIniciales(nodoB *lista,char inicial){
    nodoB *aux=lista,*lista_iniciales=NULL;
    nodito *sub_iniciales=NULL,*aux2=NULL;
    TClub club_iniciales;
    TJugador jugador_iniciales;
    int contador_global=0,contador_priv=0,max=-1;

    if(aux!=NULL){
        while (aux!=NULL){
            aux2=aux->subL;
            while(aux2!=NULL){
                if (aux2->jugador.nombre[0]==inicial){
                    contador_global++;
                    contador_priv++;
                    jugador_iniciales=aux2->jugador;
                    insertarNodito(&sub_iniciales,jugador_iniciales);
                }

                aux2=aux2->sig;
            }
            if (contador_priv>max){
                max=contador_priv;
                contador_priv=0;
                lista_iniciales=NULL;
                club_iniciales=aux->dClub;
                insertarNodoB(&lista_iniciales,sub_iniciales,club_iniciales);
                sub_iniciales=NULL;
            }else{
                sub_iniciales=NULL;
                contador_priv=0;
            }
            aux=aux->sig;
        }
        mostrarLista(lista_iniciales);
        printf("se encontraron jugadores con esta inicial %c: %d\n",inicial,contador_global);
        printf("el club con mas iniciales tuvo: %d\n",max);

    }
}

void minimoPuntajeYPromEdad(nodoB* lista,unsigned short int puntaje){
    nodoB *aux=lista;
    nodito *aux2=NULL;
    int cantidad;
    float promedio,suma;
    while(aux!=NULL && aux->dClub.puntaje>=puntaje ){
        suma=0;
        cantidad=0;
        printf("Club: %s   Puntos: %d\n",aux->dClub.club,aux->dClub.puntaje);
        aux2=aux->subL;
        while(aux2!=NULL){
            printf("==> Jugador: %s   Edad: %d  Condicion: %c\n",aux2->jugador.nombre,aux2->jugador.edad,aux2->jugador.condicion);
            suma+=aux2->jugador.edad;
            cantidad++;
            aux2=aux2->sig;
        }
        promedio=suma/cantidad;
        printf("promedio de edad del plantel: %2.2f\n",promedio);
        aux=aux->sig;
    }
}

