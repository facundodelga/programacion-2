#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendalib.h"

void crear(int *validos,agenda sch[max_sch],int pos){
    //int i=0;
    char op;
    //agenda sch[max_sch];

    while(op!='n'){

        printf("Nombre del contacto (25 caracteres)\n");
        scanf("%s",sch[pos].nombre);
        printf("Numero de telefono del contacto (11 caracteres)\n");
        scanf("%s",sch[pos].telefono);

        printf("Continuar cargando contactos? para salir escribir 'n' \n");
        scanf(" %c",&op);

        printf("\n");
        pos++;
    }

    printf("Contactos validos: %i\n",pos);

    *validos=pos;
}
void agregarContacto(int *validos,agenda sch[max_sch],int pos){
    char op;
    printf("Agregar contacto\n");

    while(op!='n'){

        printf("Nombre del contacto (25 caracteres)\n");
        scanf("%s",sch[pos].nombre);
        printf("Numero de telefono del contacto (11 caracteres)\n");
        scanf("%s",sch[pos].telefono);

        printf("Continuar cargando contactos? para salir escribir 'n' \n");
        scanf(" %c",&op);

        printf("\n");
        pos++;
    }

    printf("Contactos validos: %i\n",pos);

    *validos=pos;
}
void mostrarAgenda(int validos,agenda sch[max_sch]){
    int i;
    for (i=0;i<validos;i++){
        printf("nombre: %s  telefono: %s\n",sch[i].nombre,sch[i].telefono);
    }
}
int buscarContacto(int validos,agenda sch[max_sch],char nombre[max_nombre]){
    int i=0,j;
    j=(validos-1);
    while ((i<=validos/2) || (j>=validos/2)){
        if (strcmp(sch[i].nombre,nombre)||strcmp(sch[j].nombre,nombre)){
            return 1;
        }
        printf("i: %i j: %i",i,j);
        i++;
        j--;

    }
    return 0;
}

