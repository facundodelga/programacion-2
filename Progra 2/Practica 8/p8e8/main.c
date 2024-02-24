#include <stdio.h>
#include <stdlib.h>
#define N 4
typedef struct{
    int v;
    int g;
}TR;

int ej8b(int m[][N],int i,int j,int maxG,int maxV,int grado);
int ej8c(int m[][N],int i,int j,int x);

int main()
{
    int m[N][N] = {{0,1,1,1},{0,0,0,1},{1,1,0,0},{1,1,1,0}}, validos = 0;
    TR g3[N];
    printf("vertice con mayor grado de entrada: %d",ej8b(m,0,0,-1,0,0));
    return 0;
}

void ej8a(int m[][N],int v[N],int i, int j){
    if(i < N){
        if(m[i][j] == 1)
            (v[i])++;
        if(j < N-1)
            ej8a(m,v,i,j+1);
        else
            ej8a(m,v,i+1,0);
    }
}

int ej8b(int m[][N],int i,int j,int maxG,int maxV,int grado){
    if(j < N){
        if(i == (N-1)){
            if(maxG < grado)
                return ej8b(m,0,j+1,grado,j,0);
            else
                return ej8b(m,0,j+1,maxG,maxV,0);
        }else{
            if(m[i][j] == 1)
                return ej8b(m,i+1,j,maxG,maxV,grado + 1);
            else
                return ej8b(m,i+1,j,maxG,maxV,grado);
        }
    }
    return maxV + 1;
}
// 8) c- determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
//      (triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
int ej8c(int m[][N],int i,int j,int x){
    int aux = 0,j_aux;
    if(i < N){
        while(j > i && aux == 0){
            if(m[i][j] > x)
                aux = 1;
            j--;
        }
        if(i == j && aux == 0){
            j_aux = j-1;
            while(j_aux > -1 && aux == 0){
                if(m[j][j_aux] > x)
                    aux = 1;
                j_aux--;
            }
        }
        if(aux == 0)
            return 0;
        else
            return ej8c(m,i+1,N,x);
    }
    return 1;
}

void ej8d(int m[][N],TR v[N],int *validos,int i,int j,int grado){
    if(i < N){
        if(j < N){
            if(m[i][j] != 0)
                ej8d(m,v,validos,i,j+1,grado + 1);
            else
                ej8d(m,v,validos,i,j+1,grado);
        }else{
            if(grado > 3){
                v[*validos].v = i;
                v[*validos].g = grado;
                (*validos)++;
            }
            ej8d(m,v,validos,i+1,0,0);
        }
    }
}

















