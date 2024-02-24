#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    printf("Hello world!\n");
    return 0;
}

void profundidad(int m[][N]){ //profundidad para grafos conexos
    TPila p;
    int VV[N]={0},pos,cont = 0,pos,op = 1;
    IniciaP(&p);
    poneP(&p,0);
    VV[0] = 1;
    cont++;
    printf("%d\n",0);

    while(cont < N){
        pos = consultaP(p);
        op = 1;
        for(int j = 0;j<N;j++){
            if(m[pos][j] == 1 && VV[j] == 0){
                VV[j] = 1;
                cont++;
                printf("%d\n",j);
                op=0;
                poneP(&p,j);
            }
        }
        if(op == 1)
            sacaP(&p,&pos);
    }
}


void amplitud(int m[][N], int n){ //amplitud grafo conexo
    TCola c;
    int VV[N] = {0},pos,cont = 0;
    poneC(&c,0);
    VV[0] = 1;
    printf("%d\n",0);
    cont++;
    while(cont < n){
        sacaC(&c,pos);
        for(int j=0;j<n;j++){
            if(m[pos][j] == 1)
                if(VV[j] == 0){
                    printf("%d\n",j);
                    VV[j] = 1;
                    cont++;
                    poneC(&c,j);
                }
        }
    }
}
