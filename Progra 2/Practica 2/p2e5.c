
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void inicializar(int* v[MAX], int* );
void mostrarYLiberar(int* [], int);

int main(){
    int* v[MAX];
    int n = 0;
    inicializar(v,&n);
    mostrarYLiberar(v,n);
    return 0;
}

void inicializar(int* v[MAX],int *n){
    FILE* arch = NULL;
    int i=0;
    arch = fopen("p2e5.txt","r");

    while(!feof(arch)){
      v[i]  = (int *)malloc(sizeof(int));
      fscanf(arch,"%d ",v[i]);
      i++;
      (*n)++;
    }
    fclose(arch);
}

void mostrarYLiberar(int* v[MAX], int n){
    for(int i=0;i<n;i++){
        if( *v[i] > 0 ){
            printf("[ %d ] ",*v[i]);
        }

        free(v[i]);
    }
}
