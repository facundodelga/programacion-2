
#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int sumasSucesivas(int ,int );
void restasSucesivas(int ,int ,int );
void encuentraMax(int [],int ,int ,int );
int maximoV(int [],int ,int );

int main(){
    int v[MAX] = {1,10,-4,8,2,7,3,4};
    int validos = 7;
    printf("%d\n",sumasSucesivas(4,4));

    restasSucesivas(4,2,0);
    encuentraMax(v,validos,0,v[0]);
    printf("Maximo del vector (int): %d\n",maximoV(v,validos-1,v[0]));
    return 0;
}

int sumasSucesivas(int a,int b){

    if(b==0)
        return 0;
    else
        return a + sumasSucesivas(a,b-1);
}

void restasSucesivas(int num,int divisor,int q){
    if (num < divisor)
        printf("Resto: %d\nCociente: %d\n",num,q);
    else
        restasSucesivas(num-divisor,divisor,q+1);
}

void encuentraMax(int v[MAX],int validos,int i,int maximus){
    if(i==validos)
        printf("Maximo del vector (void): %d\n",maximus);
    else
        if(v[i] > maximus)
            encuentraMax(v,validos,i+1,v[i]);
        else
            encuentraMax(v,validos,i+1,maximus);
}

int maximoV(int v[MAX],int i,int maximo){
    if (i < 0)
        return maximo;
    else
        if(v[i] > maximo)
            return maximoV(v,i-1,v[i]);
        else
            return maximoV(v,i-1,maximo);
}
