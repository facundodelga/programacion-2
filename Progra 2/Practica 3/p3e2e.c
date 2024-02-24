
#include <stdlib.h>
#include <stdio.h>
#define MAX 30

void cargaV(int [],int*);
void muestraV(int [],int );
void ejercicio(int v[],int b[],int i,int j,int n,int m,int c[],int *t);

int main(){
    int v[MAX],b[MAX],c[MAX],n=0,m=0,val=0;
    cargaV(v,&n);
    cargaV(b,&m);
    muestraV(v,n);
    muestraV(b,m);
    ejercicio(v,b,0,0,n,m,c,&val);
    muestraV(c,val);


    return 0;
}

void cargaV(int v[MAX],int *validos){
    int grado = 0;
    printf("dimension del vector\n");
    scanf("%d",&grado);
    for(int i=0;i<grado;i++)
        v[i] = rand()%30;
    *validos=grado;

}

void muestraV(int v[],int n){
    for(int i=0;i<n;i++)
        printf("[%d] ",v[i]);

    printf("\n");
}

void ejercicio(int v[],int b[],int i,int j,int n,int m,int c[],int *t){
    if(i == n && j == m){
        printf("fin de recursividad\n");
    }else{
        if(i < n && j < m){
            if(v[i] < b[j]){
                c[*t] = v[i];
                c[(*t)+1] = b[j];
            }else{
                if(v[i] > b[j]){
                    c[(*t)] = b[j];
                    c[(*t)+1] = v[i];
                }else{
                    c[*t] = b[j];
                }
            }
            ejercicio(v,b,i+1,j+1,n,m,c,t+2);
        }else{
            if(i < n && j == m){
                c[*t] = v[i];
                ejercicio(v,b,i+1,j,n,m,c,t+1);
            }else{
                c[*t] = b[j];
                ejercicio(v,b,i,j+1,n,m,c,t+1);
            }

        }

    }

}

