#include <stdio.h>
#include <stdlib.h>

int *cargarVector(int);

int main(){
    int *vector,n,i=0;
    printf("cuantos numeros quiere cargar? =>  ");
    scanf(" %d",&n);
    vector=cargarVector(n);
    for(i=0;i<n;i++){
        if( *vector+i >= 0){
            printf("[ %d ] ",*vector+i);
        }
    }
    free(vector);
}

int *cargarVector(int n){
    int *v,i=0,aux;
    v =(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        printf("posicion %d / %d =>  ",i+1,n);
        scanf("%d",v+i);     // v => v[0]     v+1 = v[i]
    }
    return v;
}
