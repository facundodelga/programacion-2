#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void iniciarMatriz();
void vecesQueSale(float m[][DIM],float X,int cont_veces,int max_f,int max_c,int i,int j);
int esSimetrica();


int main()
{
    int f=0,c=0;
    float m[DIM][DIM],num;
    num=2.0;
    printf("filas \n");
    scanf("%d",&f);
    printf("columnas \n");
    scanf("%d",&c);
    iniciarMatriz(m,f-1,c-1,0,0);
    vecesQueSale(m,num,0,f-1,c-1,0,0);
    if (f==c){

        if(!esSimetrica(m,f-1,0,0)){
            printf("No es simetrica");
        }else{
            printf("Es simetrica");
        }

    }
    return 1;
}

void iniciarMatriz(float matriz[][DIM],int max_i,int max_j,int i, int j){
    if ((i>max_i) && (j==0)){

    }else{
        printf("fila: %i columna: %i\n",i+1,j+1);
        scanf(" %f",&matriz[i][j]);
        if (j==max_j){
            iniciarMatriz(matriz,max_i,max_j,i+1,0);
        }else{
            iniciarMatriz(matriz,max_i,max_j,i,j+1);
        }

    }
}

void vecesQueSale(float m[][DIM],float X,int cont_veces,int max_f,int max_c,int i,int j){
    if ((i>max_f) && (j==0)){
        printf("Veces que se encontro %2.2f: %i\n",X,cont_veces);
    }else{
        //printf("fila: %i columna: %i\n",i+1,j+1);

        if (X==m[i][j]){
            cont_veces++;
        }

        if (j==max_c){
            vecesQueSale(m,X,cont_veces,max_f,max_c,i+1,0);
        }else{
            vecesQueSale(m,X,cont_veces,max_f,max_c,i,j+1);
        }

    }

}

int esSimetrica(float matriz[][DIM],int max_fc,int i,int j){
    if ((i>max_fc) && (j==0)){
        return 1;
    }else{
        printf("fila: %i columna: %i\n",i+1,j+1);
        if (matriz[i][j]==matriz[j][i] && i==j){
            return esSimetrica(matriz,max_fc,i+1,0);
        }else{
            if (matriz[i][j]==matriz[j][i] && i!=j){
                return esSimetrica(matriz,max_fc,i,j+1);
            }else{
                return 0;
            }

        }

    }

}

