#include <stdio.h>
#include <stdlib.h>
#define max 10

void main(){
    int *a,*b,*c,X[max],i=0,suma,multi;
    a=(int *)malloc(sizeof (int));
    b=(int *)malloc(sizeof (int));
    c=(int *)malloc(sizeof (int));

    while (i<3){
        scanf(" %i\n",&X[i]);
        i++;
    }

    a=&X[0];
    b=&X[1];
    c=&X[2];

    suma=*a+*b+*c;
    multi=(*a)*(*b)*(*c);
    printf("%i",i);
    printf("\nsuma: %d multiplicacion: %d",suma,multi);

}
