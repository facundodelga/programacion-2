#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_nombre 25
#define max_telefono 11
#define max_sch 99

typedef struct{
    char nombre[max_nombre];
    char telefono[max_telefono];
}agenda;

void crear(int *validos,agenda sch[max_sch],int pos_inicial);
void agregarContacto(int *validos,agenda sch[max_sch],int pos);
void mostrar(int validos);
int buscarContacto(int validos,agenda sch[max_sch],char nombre[max_nombre]);


