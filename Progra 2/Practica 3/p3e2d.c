
#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void cargaMatriz(int [][MAX],int *, int *);
void muestraM(int [][MAX],int ,int );
void muestraV(int v[],int n);
void maximoV(int mt[][MAX],int i,int j,int n,int m,int max[],int aux);

int main(){
    int mt[MAX][MAX],n = 0,m = 0,v[MAX];
    cargaMatriz(mt,&n,&m);
    muestraM(mt,n,m);
    maximoV(mt,0,0,n,m,v,-1);

    muestraV(v,n);
    return 0;
}
void cargaMatriz(int mt[][MAX],int *n,int *m){
    int gradoN = 0,gradoM = 0;
    printf("Grado de N y M\n");
    scanf("%d",&gradoN);
    scanf("%d",&gradoM);

    for(int i=0;i<gradoN;i++)
        for(int j=0;j<gradoM;j++)
            mt[i][j] = rand()%30;
    *n=gradoN;
    *m=gradoM;
}

void muestraM(int mt[][MAX],int n, int m){
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<m;j++)
            printf("[%d] ",mt[i][j]);
    }
    printf("\n");
}

void maximoV(int mt[][MAX],int i,int j,int n,int m,int max[],int aux){
    if(i < n){
        if(j+1 < m)
            if(aux < mt[i][j]){
                max[i] = mt[i][j];
                maximoV(mt,i,j+1,n,m,max,mt[i][j]);
            }else{
                maximoV(mt,i,j+1,n,m,max,aux);
            }
        else{
            if(aux < mt[i][j])
                max[i] = mt[i][j];
            maximoV(mt,i+1,0,n,m,max,-99);

        }
    }

}


void muestraV(int v[],int n){
    for(int i=0;i<n;i++)
        printf("[%d] ",v[i]);

    printf("\n");
}
