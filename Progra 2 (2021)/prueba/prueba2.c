#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo
{
    char nombre[20];
    int cont;
    struct Nodo *sig;
}Nodo;
//typedef struct Nodo *tlista;
typedef struct tlista
{
    struct Nodo* cabeza;
}tlista;

//Nodo* crearnodo(char *dato);
void leeryordenar();
int main()
{
    FILE *arch;
    tlista lista;
    lista.cabeza=NULL;
    char dato[20];
    arch=fopen ("tp6ej3.txt","rt");
    while (fscanf(arch,"%s",dato)==1)
    {
        Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
            strcpy(nodo->nombre,dato);
            nodo->sig;
        printf("%s\n",nodo->nombre);
        if (lista.cabeza==NULL)
            lista.cabeza=nodo;
        else
        {
          Nodo* puntero=lista.cabeza;
          while (puntero->sig)
            puntero=puntero->sig;
          puntero->sig=nodo;
        }
        leeryordenar(&lista);
    }
    fclose(arch);
    return 0;
}
/*Nodo* crearnodo(char dato)
{
    Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->nombre=dato;
    nodo->sig;
    return nodo;

}*/

void leeryordenar(tlista* lista)
{
    Nodo* ant;
    Nodo* puntero=lista->cabeza;
    while (puntero->sig!=NULL)
      {                                                 //valor=strcmp(strin1,strin2);
        ant=puntero;                                    //valor==-1;strin1<strin2
        puntero=puntero->sig;                           //valor==0; strin1==strin2
        if ((strcmp(ant->nombre,puntero->nombre)>=0) &&
            (puntero->sig!=NULL))                       //valor==1; strin1>strin2
        {
            lista->cabeza=puntero;
            puntero->sig=ant;
            ant->sig=puntero->sig;
        }
        else
        {
            puntero=puntero->sig;
        }
      }
}
