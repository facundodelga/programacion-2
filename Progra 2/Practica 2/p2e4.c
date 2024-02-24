#include <stdio.h>
#include <stdlib.h>

void mostrar(int *,int );

int main(){
    int *v, n=0;
    printf("cantidad de posiciones del arreglo: ");
    scanf("%d",&n);
    v = (int* )malloc(n * sizeof(int));
    int j;
    for(int i=0;i<n;i++)
        *(v+i) = rand() % 20;
    printf("\n");
    mostrar(v,n);
    return 0;
}

void mostrar(int *v,int n){
    int i=0;
    while( i < n ){
        printf("[ %d ] ",*(v+i));
        i++;
    }

}

