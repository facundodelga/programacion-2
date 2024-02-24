
#include <stdio.h>
#include <stdlib.h>

void leeArchivo();

int main(){
    leeArchivo();
    return 0;
}


void leeArchivo(){
    FILE *arch = NULL;
    int aux,suma = 0;
    arch = fopen("p1e23.txt","r");

    while( !feof(arch) ){
        fscanf(arch,"%d ",&aux);
        suma += aux;
    }
    fclose(arch);
    printf("suma de valores en el archivo: %d \n",suma);
}
