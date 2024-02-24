
#include <stdlib.h>
#include <stdio.h>
#define MAX 20

void promedioV(int v[],int i,int n,float suma,float *prom);


int main(){

    return 0;
}

void promedioV(int v[],int i,int n,float suma,float *prom){
    if(i < n){
        suma += v[i];
        promedioV(v,i+1,n,suma,prom);

    }else{
        *prom = suma / n;
    }

}


