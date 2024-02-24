#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void cargaMatriz(float [][MAX],int *, int *);
void muestraM(float [][MAX],int ,int );
int encuentraX(float [][MAX],int ,int ,int ,int ,float );
int main(){
    float mt[MAX][MAX],x;
    int n = 0,m = 0;
    cargaMatriz(mt,&n,&m);
    muestraM(mt,n,m);
    x = (rand()%2000)/100.0;
    printf("cuantas veces sale el numero %2.2f : %d\n",x,encuentraX(mt,0,0,n,m,x));
    return 0;
}

void cargaMatriz(float mt[][MAX],int *n,int *m){
    int gradoN = 0,gradoM = 0;
    printf("Grado de N y M\n");
    scanf("%d",&gradoN);
    scanf("%d",&gradoM);

    for(int i=0;i<gradoN;i++)
        for(int j=0;j<gradoM;j++)
            mt[i][j] = (rand()%2000)/100.0;
    *n=gradoN;
    *m=gradoM;
}

void muestraM(float mt[][MAX],int n, int m){
    for(int i=0;i<n;i++){
       printf("\n");
       for(int j=0;j<m;j++)
            printf("[%2.2f] ",mt[i][j]);
    }
    printf("\n");
}

int encuentraX(float mt[][MAX],int i,int j,int n,int m,float x){
    if(i == n){
        return 0;
    }else{
        if(j+1 < m)
            if(mt[i][j] == x)
                return 1 + encuentraX(mt,i,j+1,n,m,x);
            else
                return encuentraX(mt,i,j+1,n,m,x);
        else
            if(mt[i][j] == x)
                return 1 + encuentraX(mt,i+1,0,n,m,x);
            else
                return encuentraX(mt,i,i+1,0,m,x);
    }

}
