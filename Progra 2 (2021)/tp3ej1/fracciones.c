#include "fracciones.h"
#include <stdio.h>
#include <stdlib.h>

fraccion crear (int numerador,int denominador){

    fraccion f;
    f.denominador=denominador;
    f.numerador=numerador;
  if ((numerador%denominador==0)||(denominador%numerador==0)){
        f=simplificar(f);
  }
    mostrarFraccion(f);
    return f;
}

int numerador(fraccion f){
    return f.numerador;
}

int denominador(fraccion f){
    return f.denominador;
}

fraccion sumar(fraccion f1, fraccion f2){
    fraccion suma;
    if (f1.denominador==f2.denominador){
        suma.denominador=f1.denominador;
        suma.numerador=f1.numerador+f2.numerador;
    }else{
       suma.denominador=f1.denominador*f2.denominador;
       suma.numerador=(f1.numerador*f2.denominador)+(f2.numerador*f1.denominador);
    }
  if ((suma.numerador%suma.denominador==0)||(suma.denominador%suma.numerador==0)){
      suma=simplificar(suma);
  }
    return suma;
}
fraccion restar(fraccion f1, fraccion f2){
    fraccion resta;
    if (f1.denominador==f2.denominador){
        resta.denominador=f1.denominador;
        resta.numerador=f1.numerador-f2.numerador;
    }else{
       resta.denominador=f1.denominador*f2.denominador;
       resta.numerador=(f1.numerador*f2.denominador)-(f2.numerador*f1.denominador);
    }

  if ((resta.numerador%resta.denominador==0)||(resta.denominador%resta.numerador==0)){
      resta=simplificar(resta);
  }

    return resta;
}
fraccion multiplicar(fraccion f1, fraccion f2){
    fraccion multi;

    multi.denominador=f1.denominador*f2.denominador;
    multi.numerador=f1.numerador*f2.numerador;

  if ((multi.numerador%multi.denominador==0)||(multi.denominador%multi.numerador==0)){
      multi=simplificar(multi);
  }

    return multi;
}
fraccion dividir(fraccion f1, fraccion f2){
    fraccion divis;

    divis.denominador=f1.denominador*f2.numerador;
    divis.numerador=f1.numerador*f2.denominador;

  if ((divis.numerador%divis.denominador==0)||(divis.denominador%divis.numerador==0)){
      divis=simplificar(divis);
  }

    return divis;
}
fraccion simplificar(fraccion f){ //retorna fraccion simplificada.
	int i,hay_multiplo=0,multiplo,*menor;

	menor=(int*)malloc(sizeof(int));

    if (f.denominador==f.numerador){
        f.denominador=1;
        f.numerador=1;
        return f;
    }else{

        if (f.numerador < f.denominador ){
            *menor = f.numerador;
        }else{
            *menor = f.denominador;
        }
    }

	do {
	hay_multiplo=0;
    i=2;
	while (i <= *menor && hay_multiplo == 0){
	  if (f.numerador % i == 0 && f.denominador % i == 0){
        multiplo = i;
        hay_multiplo = 1;
        if (hay_multiplo == 1){
            f.numerador=f.numerador/multiplo;
            f.denominador=f.denominador/multiplo;
            printf(" = %d/%d\n", f.numerador, f.denominador);
        }
	  }
	  i++;
	}
	}while (hay_multiplo==1);

	return f;
}

int iguales (fraccion f1, fraccion f2){ //retorna verdadero o falso.
    if ((f1.denominador==f2.denominador)&&(f1.numerador==f2.numerador)){
        return 1;
    }else{
        return 0;
    }
}

void mostrarFraccion(fraccion f){
    printf("%d/%d\n",f.numerador,f.denominador);
}






