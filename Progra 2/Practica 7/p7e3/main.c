#include <stdio.h>
#include <stdlib.h>

typedef int TElementoA;

typedef struct nodo{
    TElementoA dato;
    struct nodo *izq,*der;
}nodo;

typedef nodo * arbol;

void insertaABB(arbol *a, TElementoA x);
int multiplos3(arbol a);
int cuentaHojas(arbol a);
int estaX(arbol a, TElementoA x);
int profundidad(arbol);

int main(){
    arbol a = NULL;

    insertaABB(&a,12);
    insertaABB(&a,3);
    insertaABB(&a,9);
    insertaABB(&a,2);
    insertaABB(&a,4);
    insertaABB(&a,10);
    insertaABB(&a,1);
    insertaABB(&a,26);
    insertaABB(&a,18);
    insertaABB(&a,21);
    insertaABB(&a,22);
    insertaABB(&a,15);

    printf("cant de multiplos de 3: %d\n",multiplos3(a));

    printf("cant de hojas: %d\n",cuentaHojas(a));

    if(estaX(a,15))
        printf("esta el numero 15 \n");
    else
        printf("NO esta el numero 15 \n");
    printf("cant de hojas: %d\n",profundidad(a));
    return 0;
}


void insertaABB(arbol *a, TElementoA x){
    if(*a == NULL){
        *a = (arbol)malloc(sizeof(struct nodo));
        (*a)->dato = x;
        (*a)->der = NULL;
        (*a)->izq = NULL;
    }else
        if(x < (*a)->dato)
            insertaABB(&(*a)->izq,x);
        else
            insertaABB(&(*a)->der,x);
}

int multiplos3(arbol a){
    if(a){
        if(a->dato % 3 == 0)
            return 1 + multiplos3(a->der) + multiplos3(a->izq);
        return multiplos3(a->der) + multiplos3(a->izq);
    }else
        return 0;
}

int cuentaHojas(arbol a){
    if(a){
        if(a->izq == NULL && a->der == NULL)
            return 1;
        return multiplos3(a->der) + multiplos3(a->izq);
    }else
        return 0;
}

int estaX(arbol a, TElementoA x){
    if(a != NULL && a->dato != x)
        return estaX(a->der,x) || estaX(a->izq,x);
    else{
        if(a)
            return 1;
        return 0;
    }
}


int profundidad(arbol a){
    int izq = 0, der = 0;
    if(a){
        izq = profundidad(a->izq) + 1;
        der = profundidad(a->der) + 1;
        if(der < izq)
            return izq;
        else
            return der;
    }else
        return 0;
}



