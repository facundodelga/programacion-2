#include <stdio.h>
#include <stdlib.h>

int *mallocVariable();

int main(){
    int *a,*b,*c;
    b=mallocVariable();
    a=mallocVariable();
    c=mallocVariable();

    printf("suma : %d            multiplicacion : %d",*a + *b + *c,(*a) * (*b) * (*c));

    free(a);
    free(b);
    free(c);
}
int *mallocVariable(){
    int *aux,x;
    aux=(int *)malloc(sizeof(int));
    scanf("%d",&x);
    *aux=x;
    return aux;
}
