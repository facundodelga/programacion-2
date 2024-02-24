#include <stdlib.h>
#include <stdio.h>
#include "fraccion.h"

fraccion crear(int numerador, int denominador){
    fraccion f;
    if(denominador != 0){
        fraccion f;
        f.denominador = denominador;
        f.numerador = numerador;
        return f;
    }
}

int numerador(fraccion f){
    return f.numerador;
}

int denominador(fraccion f){
    return f.denominador;
}
fraccion sumar(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = f1.denominador * f2.denominador;
    f.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
    return f;
}

fraccion restar(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = f1.denominador * f2.denominador;
    f.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
    return f;
}

fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = f1.denominador * f2.denominador;
    f.numerador = f1.numerador * f2.numerador;
    return f;

}

fraccion dividir(fraccion f1, fraccion f2){
    fraccion f;
    f.denominador = f1.denominador * f2.numerador;
    f.numerador = f1.numerador * f2.denominador;
    return f;

}

fraccion simplificar(fraccion f){
    int i,hay_multiplo=0,multiplo,menor;

    if (f.denominador == f.numerador){
        f.denominador=1;
        f.numerador=1;
        return f;
    }else{

        if (f.numerador < f.denominador ){
            menor = f.numerador;
        }else{
            menor = f.denominador;
        }
    }

	do {
        hay_multiplo = 0;
        i = 2;
        while (i <= menor && hay_multiplo == 0){
          if (f.numerador % i == 0 && f.denominador % i == 0){
            multiplo = i;
            hay_multiplo = 1;
            if (hay_multiplo == 1){
                f.numerador=f.numerador/multiplo;
                f.denominador=f.denominador/multiplo;
            }
          }
          i++;
        }
	}while (hay_multiplo == 1);

	return f;

}

int iguales(fraccion f1, fraccion f2){
    return f1.denominador == f2.denominador && f1.numerador == f2.numerador;

}
void mostrarFraccion(fraccion f){
    printf("%d / %d\n",f.numerador,f.denominador);
}
