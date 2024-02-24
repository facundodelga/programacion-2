#include <stdlib.h>
#include <stdio.h>
#define MAX 50

void cargaV(int [],int *);
int suma(int [],int );
void muestraV(int v[MAX],int validos,int i);
void muestraVInv(int v[MAX],int validos);

int main(){
    int v[MAX], validos = 0;

    cargaV(v,&validos);

    muestraV(v,validos,0);
    printf("\n");
    muestraVInv(v,validos-1);
    printf("\n");
    printf("Suma de elementos : %d\n",suma(v,validos-1));

    return 0;
}

void cargaV(int v[MAX],int *validos){
    FILE *arch;
    int i = 0;

    arch = fopen("p3e2a.txt","r");

    while(!feof(arch)){
        fscanf(arch,"%d ",&v[i]);
        //printf("%d\n",v[i]);
        i++;
    }

    fclose(arch);
    *validos = i;
}

int suma(int v[MAX],int validos){
    if (validos == 0)
        return v[validos];
    else
        return v[validos] + suma(v,validos-1);

}

void muestraVInv(int v[MAX],int validos){
    if(validos >= 0){
        printf("[ %d ] ",v[validos]);
        muestraVInv(v,validos-1);
    }
}


void muestraV(int v[MAX],int validos,int i){
    if(i < validos){
        printf("[ %d ] ",v[i]);
        muestraV(v,validos,i+1);
    }
}
