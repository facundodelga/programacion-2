#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodito{
    int nro_mesa,nro_comensales;
    struct nodito *sig;
}Nodito;

typedef struct Nodo{
    char mozo[6];
    struct Nodo *sig;
    Nodito *sub;
}Nodo;

Nodito* crearNodito(int,int);
Nodo* crearNodo(char st[],Nodito*);
void insertarNodito(Nodito**,int,int);
void insertarNodo(Nodo**,Nodito*,char st[]);
void cargarLista(Nodo**);
void mostrarLista(Nodo*);
Nodito* cerrarMesa(Nodito*L,int);
Nodo* eliminarMozo(Nodo *L);
void procedimiento(Nodo**L);


int main(){
    Nodo *lista=NULL;
    cargarLista(&lista);
    mostrarLista(lista);
    procedimiento(&lista);
    mostrarLista2(lista);
    return 0;
}

Nodito* cerrarMesa(Nodito*L,int mesa){
    Nodito *mesa_act,*mesa_ant;

    if(L!=NULL){
        if(L->nro_mesa==mesa){
            printf("==> nro de mesa %d\n",L->nro_mesa);
            Nodito *aux=L;
            L=L->sig;
            free(aux);
        }else{
        mesa_act=L;

        while(mesa_act!=NULL && mesa!=mesa_act->nro_mesa){
            printf("==> nro de mesa %d\n",mesa_act->nro_mesa);
            mesa_ant=mesa_act;
            mesa_act=mesa_act->sig;
        }
        if(mesa_act!=NULL && mesa==mesa_act->nro_mesa){
            mesa_ant->sig=mesa_act->sig;
            free(mesa_act);
        }else{
            printf("no se encuentra la mesa [ %d ]\n",mesa);
            }

        }
        return L;
    }
}
Nodo* eliminarMozo(Nodo *L){
    Nodo* aux;
    aux=L;
    L=L->sig;
    free(aux);
    return aux;
}

void procedimiento(Nodo**L){
    Nodo* ant=NULL,*act;
    char op='s',op_mesa='s',mozo[6];
    int mesa;
    ant=NULL;
    act=*L;
    while(op=='s'){
        printf("Mozo ==> ");
        scanf(" %s",mozo);
        printf("\n");

        while(strcmp(mozo,act->mozo)!=0 && act->sig!=NULL){ //busco el mozo
            ant=act;
            act=act->sig;
        }
        if(act==NULL){
            printf("No existe mozo!\n");
            ant->sig=act;
        }else{
            op_mesa='s';
            while(op_mesa=='s' && (*L)->sub!=NULL){
                printf("Mesa ==> ");
                scanf(" %d",&mesa);
                printf("\n");
                act->sub=cerrarMesa(act->sub,mesa);

                if(act->sub==NULL){
                    act=eliminarMozo(act);
                    ant->sig=act->sig;
                    op_mesa='n';
                }else{
                    printf("Continuar eliminando mesas? [s] ==> ");
                    scanf(" %c",&op_mesa);
                    printf("\n");
                }
            }
        }
        printf("Continuar ? [s] ==> ");
        scanf(" %c",&op);
        printf("\n");
        ant=act;
        act=act->sig;
    }
}

Nodito* crearNodito(int mesa,int comensales){
    Nodito* aux=NULL;
    aux=(Nodito*)malloc(sizeof(Nodito));
    if(aux!=NULL){
        aux->nro_comensales=comensales;
        aux->nro_mesa=mesa;
        aux->sig=NULL;
        return aux;
    }
    return NULL;
}
Nodo* crearNodo(char st[],Nodito* subL){
    Nodo* aux=NULL;
    aux=(Nodo*)malloc(sizeof(Nodo));
    if(aux!=NULL){
        strcpy(aux->mozo,st);
        aux->sub=subL;
        aux->sig=NULL;
        return aux;
    }
    return NULL;
}

void insertarNodito(Nodito** sL,int mesa,int comensales){
    Nodito *nuevo=NULL,*aux=*sL;
    nuevo=crearNodito(mesa,comensales);
    if(nuevo){
        if (*sL==NULL){
            nuevo->sig=*sL;
            *sL=nuevo;
        }else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }
    }
}
void insertarNodo(Nodo** lista,Nodito* sL,char st[]){
    Nodo *nuevo=NULL,*aux=*lista;
    nuevo=crearNodo(st,sL);
    if(nuevo){
        if (*lista==NULL){
            nuevo->sig=*lista;
            *lista=nuevo;
        }else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            aux->sig=nuevo;
        }
    }
}
void cargarLista(Nodo**mozos){
    FILE *arch;
    Nodito *mesas;
    char mozo[6];
    int nMesas,k,mesa,comensales;
    arch=fopen("mozos.txt","r");
    while(!feof(arch)){
        k=0;
        mesas=NULL;
        fscanf(arch,"%s %d ",mozo,&nMesas);
        //printf("%s %d ",mozo,nMesas);
        while(k!=nMesas){
            fscanf(arch,"%d %d ",&mesa,&comensales);
            //printf("%d %d ",mesa,comensales);
            insertarNodito(&mesas,mesa,comensales);
            k++;
        }
        //printf("\n");
        insertarNodo(mozos,mesas,mozo);
    }

    fclose(arch);
}

void mostrarLista(Nodo* L){
    Nodo* aux=L;
    Nodito* auxSub;
    while(aux!=NULL){
        printf("Mozo: %s \n",aux->mozo);
        auxSub=aux->sub;
        while(auxSub!=NULL){
            printf("==>Mesa: %d Comen: %d \n",auxSub->nro_mesa,auxSub->nro_comensales);
            auxSub=auxSub->sig;
        }
        printf("\n");
        aux=aux->sig;
    }
}

void mostrarLista2(Nodo* L){
    Nodo* aux=L;
    Nodito* auxSub;
    int mesasSinCerrar=0,MesasConUnComensal=0;
    while(aux!=NULL){
        //printf("Mozo: %s ",aux->mozo);
        auxSub=aux->sub;
        while(auxSub!=NULL){
            //printf("==>Mesa: %d Comen: %d \n",auxSub->nro_mesa,auxSub->nro_comensales);
            mesasSinCerrar++;
            if(auxSub->nro_comensales==1){
                MesasConUnComensal++;
            }
            auxSub=auxSub->sig;
        }
        printf("Mozo: %s   Mesas sin cerrar: %d   Mesas con un solo comensal: %d",aux->mozo,mesasSinCerrar,MesasConUnComensal);
        printf("\n");
        mesasSinCerrar=0;
        MesasConUnComensal=0;
        aux=aux->sig;
    }
}
