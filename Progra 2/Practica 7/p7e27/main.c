#include <stdio.h>
#include <stdlib.h>

int main(){

    return 0;
}

int cantNodos(arbol A,posicion p){
    posicion c;
    int cant = 1;
    if(!nulo(p)){
        c = hijoMasIzq(A,p);
        while(!nulo(c)){
            cant += cantNodos(A,c);
            c = herDer(A,c);
        }

        return cant;
    }else
        return 0;
}

int sumaClavesPares(arbol A,posicion p){
    posicion c;
    int suma = 0, aux;
    if(!nulo(p)){
        c = hijoMasIzq(A,p);
        while(!nulo(c)){
            aux = sumaClavesPares(A,p);
            if(Info(A,c) % 2 == 0)
                suma = suma + aux + Info(A,c);
            c = herDer(A,c);
        }
        return suma;
    }else
        return 0;
}


int gradoNArio(arbol a,posicion p){
    posicion c;
    int aux, auxMax = -1, grado = 0;

    if(!nulo(p)){
        c = hijoMasIzq(a,p);
        while(!nulo(c)){
            aux = gradoNArio(a,c);
            if(aux > auxMax)
                auxMax = aux;
            grado++;
            c = herDer(a,c);
        }

        if(auxMax < grado)
            return grado;
        return auxMax;
    }else
        return 0;
}


