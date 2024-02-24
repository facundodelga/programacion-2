#include <stdio.h>
#include <stdlib.h>
#include "ColaE.h"
#include "pila.h"

void cargaP(TPila *);
void cargaC(TCola *,TPila *);
void muestraC(TCola *);

int main(){
    TCola c;
    TPila p;
    cargaP(&p);
    cargaC(&c,&p);
    muestraC(&c);

    return 0;
}

void cargaP(TPila *p){
    TPila aux;
    FILE *arch;
    TElementoP x;
    IniciaP(p);
    arch = fopen("p5.1e2.txt","r");
    IniciaP(&aux);

    while(fscanf(arch,"%d\n",&x) == 1)
        poneP(&aux,x);
    fclose(arch);

    while(!VaciaP(aux)){
        sacaP(&aux,&x);
        poneP(p,x);
    }
}

void cargaC(TCola *c,TPila *p){
    TElementoP x;
    int ant = -1,flag = 0,y;
    TPila aux,aux2;
    IniciaP(&aux);
    IniciaP(&aux2);
    IniciaC(c);

    while(!VaciaP(*p)){
        sacaP(p,&x);
        if(ant <= x && x!=0 && flag == 0){
            ant = x;
            poneP(&aux2,x);
        }else{
            if(x == 0){
                if(flag == 0)
                    flag = 1;
                else
                    if (flag == 1){
                        flag = 0;
                        ant = -1;
                        while(!VaciaP(aux2)){
                            sacaP(&aux2,&y);
                            poneC(c,y);
                        }
                    }
            }
        }

        poneP(&aux,x);

    }

    while(!VaciaP(aux)){
        sacaP(&aux,&x);
        poneP(p,x);
    }


}

void muestraC(TCola *c){
    TElementoC x;
    TCola aux;
    IniciaC(&aux);

    while(!VaciaC(*c)){
        sacaC(c,&x);
        printf("[ %d ] ",x);
        poneC(&aux,x);
    }

    while(!VaciaC(aux)){
        sacaC(&aux,&x);
        poneC(c,x);
    }
}





