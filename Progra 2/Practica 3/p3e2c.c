#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void cargaMatriz(int [][MAX],int *);
void muestraM(int [][MAX],int );
int minimoM(int m[][MAX],int i,int j,int n,int minimo);

int main(){
    int m[MAX][MAX],grado = 0;
    cargaMatriz(m,&grado);
    muestraM(m,grado);
    printf("minimo: %d \n",minimoM(m,0,0,grado,m[0][0]));
    return 0;
}

void cargaMatriz(int m[][MAX],int *n){
    int grado = 0;
    printf("Grado de la matriz\n");
    scanf("%d",&grado);
    for(int i=0;i<grado;i++)
        for(int j=0;j<grado;j++)
            m[i][j] = rand()%30;
    *n=grado;
}

void muestraM(int m[][MAX],int n){
    for(int i=0;i<n;i++){
       printf("\n");
       for(int j=0;j<n;j++)
            printf("[%d] ",m[i][j]);
    }
    printf("\n");
}

int minimoM(int m[][MAX],int i,int j,int n,int minimo){
    if(i == n)
        return minimo;
    else
        if(j < n - 1)
            if(m[i][j] < minimo)
                return minimoM(m,i,j+1,n,m[i][j]);
            else
                return minimoM(m,i,j+1,n,minimo);
        else
            if(m[i][j] < minimo)
                return minimoM(m,i+1,0,n,m[i][j]);
            else
                return minimoM(m,i+1,0,n,minimo);

}








