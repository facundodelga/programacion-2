
#include <stdio.h>
#include <stdlib.h>

void memDinamica(int **);
int suma(int* ,int* ,int* );
int multiplicacion(int* ,int* ,int* );

int main(){
    int *a,*b,*c;

    memDinamica(&a);
    memDinamica(&b);
    memDinamica(&c);

    printf("suma : %d\nmultiplicacion : %d\n",suma(a,b,c),multiplicacion(a,b,c));

    free(a);
    free(b);
    free(c);

    return 0;
}

void memDinamica(int **a){
    *a = (int *) malloc(sizeof(int));
    scanf("%d",*a);
}


int suma(int* a, int* b,int* c){
    return *a + *b + *c;
}


int multiplicacion(int* a, int* b,int* c){
    return *a * *b * *c;
}
