#include <stdio.h>
#include <stdlib.h>

void binario(int x);

int main(){

    binario(16);
    return 0;
}

void binario(int x){
    int aux;

    if (x / 2 != 0){

        aux = x % 2;        // [0 ; 1]
        binario(x/2);
        printf("%d ",aux);

    }else{
        printf(" %d ",x % 2);
    }

}
