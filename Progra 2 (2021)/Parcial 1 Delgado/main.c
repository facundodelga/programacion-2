#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {   //TIPO GIMNASTA
    char codigo[9];
    char nacionalidad[5];
    char disciplina[4];
}TGimnasta;

typedef struct {
    TGimnasta gim;
    int puntos[2];
}TElementoCA; //tipo de elemento que va a utilizar la cola que uso en el punto A

typedef int TElementoCB;//tipo de elemento que va a utilizar la cola que uso en el punto B

typedef struct {
    TElementoCA datos[50];
    int     pri, ult;
} TColaA; //COLA QUE UTILIZO EN EL PUNTO A

typedef struct {
    TElementoCB datos[50];
    int     pri, ult;
} TColaB; //COLA QUE UTILIZO EN EL PUNTO B

typedef struct Nodito{ //NODO DE SUBLISTA
    int puntuaciones;
    struct Nodito* sig;
}Nodito;

typedef struct Nodo{ //LISTA
    TGimnasta gimnasta;
    Nodito* subL;
    struct Nodo* sig;
}Nodo;

typedef struct nodoD{ //Nodo de lista DOBLE
    char codigo[9];
    int puntaje_final;
    unsigned int intentos;
    TColaB c;
    struct nodoD* ant,*sig;
}nodoD;

typedef struct {
    nodoD ant,sig;
}TListaD; //Tipo lista DOBLE

Nodito* crearNodito(int puntuacion);
Nodo* crearNodo(TGimnasta gim,Nodito* subL);
void cargarListaGimnastas(Nodo**lista);
void puntoA(Nodo *lista,char nacionalidad[],char disciplina[]);
void puntoB(TListaD *listaDoble,Nodo* listaSimple);


int main(){
    Nodo *lista_gimnastas=NULL;
    TListaD listaDoble=NULL;
    char nacionalidad[5],disciplina[4];

    cargarListaGimnastas(&lista_gimnastas);

    printf("nacionalidad a buscar: \n");
    scanf("%s",nacionalidad);
    printf("disciplina a buscar: \n");
    scanf("%s",disciplina);

    puntoA(lista_gimnastas,nacionalidad,disciplina);
    void puntoB(&listaDoble,lista_gimnastas)

    return 0;
}


Nodito* crearNodito(int puntuacion){
    Nodito *aux;
    aux=(Nodito*)malloc(sizeof(Nodito)); //supongo que tengo memoria para asignar
    aux->puntuaciones=puntuacion;
    aux->sig=NULL;
    return aux;
}

Nodo* crearNodo(TGimnasta gim,Nodito* subL){
    Nodo *aux;
    aux=(Nodo*)malloc(sizeof(Nodo)); //supongo que tengo memoria para asignar
    aux->subL=subL; //asigno sublista de puntuaciones
    aux->gimnasta=gim;
    aux->sig=NULL;
    return aux;
}

void cargarListaGimnastas(Nodo**lista){
}


void puntoA(Nodo *lista,char nacionalidad[],char disciplina[]){
    int mejor=-1,peor=11;
    int cont=0;
    float suma=0,promedio;
    TElementoCA gimnasta;
    TColaA c_gimanstas;
    FILE *arch;
    Nodo *auxL=lista;
    Nodito *auxSubL;

    IniciaC(&c_gimanstas);

    arch=fopen("DEPURAND.txt","w");

    if (axuL!=NULL){
        while(auxL!=NULL && strcmp(auxL->gimnasta.nacionalidad,nacionalidad)!=0){ //estoy buscando cuando empieza la nacionalidad
            auxL=auxL->sig;
        }
        if (strcmp(auxL->gimnasta.nacionalidad,nacionalidad)==0){ //si encontre la nacionalidad

            while(auxL!=NULL && strcmp(auxL->gimnasta.nacionalidad,nacionalidad)==0){

                if(strcmp(auxL->gimnasta.disciplina,disciplina)==0){

                    gimnasta.gim=gimnasta;

                    auxSubL=auxL->subL; //asigno al auxiliar la sublista de puntuaciones

                    while(auxSubL!=NULL){ //me fijo las puntuaciones de la gimnasta

                        if (mejor<auxSubL->puntuaciones){ //Comparo puntuaciones
                            mejor=auxSubL->puntuaciones;
                        }else{
                            if (peor>auxSubL->puntuaciones)
                                peor=auxSubL->puntuaciones;
                        }

                        auxSubL=auxSubL->sig;

                    }

                    gimnasta.puntos[0]=peor;
                    gimnasta.puntos[1]=mejor;

                }

                PoneC(&c_gimanstas,gimnasta);

                auxL=auxL->sig;
            }
        }
    }

    while(!vaciaCA(c_gimanstas)){
        sacaCA(c_gimanstas,&gimnasta);
        fprintf(arch,"%s %d %d\n",gimnasta.gim.codigo,gimnasta.puntos[0],gimnasta.puntos[1]); //escribo todo lo guardado en el archivo
        suma=suma+gimnasta.puntos[0]+gimnasta.puntos[1]; //suma de puntos
        cont++;
    }
    promedio=suma/cont;
    printf("promedio de puntos encontrados: %d",promedio);
    fclose(arch); //cierro el archivo
}
