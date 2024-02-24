#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


    return 0;
}

void nivel(arbol a,int *nivel,int nivelAct,int longitud){

    if(a){
        if(strlen(a->dato) > l && a->dato[0] == 'A'){
            *nivel = nivelAct;
            longitud = strlen(a->dato);
        }
        nivel(a->izq,nivel,nivelAct + 1,longitud);
        nivel(a->der,nivel,nivelAct + 1,longitud);
    }

}
