#include <stdio.h>
#include <stdlib.h>
#define max_vector 20

int multiplicacionPorSuma();
int cocienteRestoRecursivo();
int encontrarMax();
void iniciarVector();
void mostrarVector();

int main()
{
    int a,b,multip,divisor,dividendo,cociente,v[max_vector],pos_validas=0,maximo;

    a=6;
    b=4;
    divisor=2;
    dividendo=2;
    cociente=0;

    multip=multiplicacionPorSuma(a,b);
    cociente=cocienteRestoRecursivo(dividendo,divisor);
    inciarVector(v,0);
    mostrarVector(v,0);
    maximo=encontrarMax(v,0,0);

    printf("maximo %i\n",maximo);
    printf("cociente: %i\n",cociente);
    printf("resto: %i\n",dividendo);

    return 1;
}

int multiplicacionPorSuma(int a,int b){
    if (a==0)
        return 0;
    else
        return b+multiplicacionPorSuma(a-1,b);    // axb va a ser igual a B sumado A veces
}

int cocienteRestoRecursivo(int a,int b){
    if (a>=b)
        return cocienteRestoRecursivo(a-b,b)+1;         // retorno cociente pero el resto no
    else
        return 0;
}

void inciarVector(int v[],int i){
    if (i>=max_vector){
        //printf("validos= %d\n",validos);
    }else{
        v[i]=rand()%11;                             //incio el vector con numeros aleatorios del [1-10]
        //printf("%i\n",v[i]);
        inciarVector(v,i+1);                //invoco otra vez con la posicion aumentada en 1
    }
}

void mostrarVector(int v[],int i){

    if (i<max_vector){
        printf("posicion: %i elemento: %i\n",i,v[i]);
        mostrarVector(v,i+1);
    }

}

int encontrarMax (int v[],int maximo,int i){

    if (i>=max_vector){
        return maximo;
    }else{
        if (maximo<v[i]){
            maximo=v[i];        //le asigno la posicion del vector al maximo valor encontrado
            //printf("maximo encontrado: %i\n",maximo);
            return encontrarMax(v,maximo,i+1);
        }else{
            return encontrarMax(v,maximo,i+1);
        }
    }

}


