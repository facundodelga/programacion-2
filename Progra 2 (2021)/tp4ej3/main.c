#include <stdio.h>
#include <stdlib.h>
#define DIM 10
int validos=0;

void inciarVector();
void promedioVector();
void mostrarVector();

int main() ////Dado un vector A de N elementos, obtener el promedio de sus elementos.
{
    int v[DIM];
    float sumaP=0;
    inciarVector(v,0);
    mostrarVector(v,0);
    promedioVector(v,sumaP,0);
    return 1;
}

void inciarVector(int v[],int i){
    if (i>=DIM){
        printf("validos= %d\n",validos);
    }else{
        v[i]=rand()%31;                             //incio el vector con numeros aleatorios del [0-30]
        validos++;
        inciarVector(v,i+1);                //invoco otra vez con la posicion aumentada en 1
    }
}

void mostrarVector(int v[],int i){

    if (i<validos){
        printf("posicion: %i elemento: %i\n",i,v[i]);
        mostrarVector(v,i+1);
    }

}

void promedioVector(int v[],double suma,int i){
    if (i<validos){
       suma=suma+v[i];
       promedioVector(v,suma,i+1);
    }else{
        printf("promedio = %2.2f\n",(suma/i));
    }

}
