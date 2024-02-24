#include <stdio.h>
#include <stdlib.h>
#define N 5

int main(){

    return 0;
}

int gradoVertice(int m[][N], int v){
    int grado = 0,i = 0,j = v-1;

    while(i < v){
        if(m[i][j] == 1)
            grado++;
        i++;
    }

    while(j < N){
        if(m[i][j] == 1)
            grado++;
        j++;
    }

    return grado;
}
