#include <stdio.h>
#include <stdlib.h>
/*6. Dada una matriz de NxM enteros, determinar si la suma de los elementos de cada fila es mayor
a la suma de los elementos de la fila anterior. Para la primera fila se debe cumplir que la suma
de sus elementos sea par.*/

int **asignaMemoriaMatriz();
void mostrarMatriz();
void cargarMatriz();
//int **inicializarMatriz(int N, int M);
void ejercicio6();

int main()
{
   int **matriz,filas,columnas;
   filas=4;
   columnas=4;
   matriz=asignaMemoriaMatriz(matriz,filas-1, columnas-1,0);
   cargarMatriz(matriz,filas-1,columnas-1,0,0);
   mostrarMatriz(matriz,filas-1,columnas-1,0,0);
   ejercicio6(matriz,filas-1,columnas-1,0,0,0,0);
   return 1;
}
int **asignaMemoriaMatriz(int **m,int f,int c,int i){
    if ((i>f)){
        return m;
    }else{
        if ((i==0)){
            m = calloc(f,sizeof(int *));
            m[i]=calloc(c,sizeof(int));
            return asignaMemoriaMatriz(m,f,c,i+1);
        }else{
            m[i]=calloc(c,sizeof(int));
            return asignaMemoriaMatriz(m,f,c,i+1);
        }
    }

}
void cargarMatriz(int **matriz,int f,int c,int i,int j){
    if ((i>f) && (j==0)){

    }else{
        //printf("fila: %i columna: %i\n",i+1,j+1);
        matriz[i][j]=rand()%101;
        //printf("%i\n",matriz[i][j]);
        if (j==c){
            cargarMatriz(matriz,f,c,i+1,0);
        }else{
            cargarMatriz(matriz,f,c,i,j+1);
        }

    }
}
void mostrarMatriz(int **matriz,int f,int c,int i,int j){
    if ((i>f) && (j==0)){

    }else{
        //printf("fila: %i columna: %i\n",i+1,j+1);
        printf("%i    ",matriz[i][j]);
        if (j==c){
            printf("\n");
            mostrarMatriz(matriz,f,c,i+1,0);
        }else{
            mostrarMatriz(matriz,f,c,i,j+1);
        }

    }
}

void ejercicio6 (int **m,int f,int c,int suma,int sumaAux,int i,int j){
    if ((i>f) && (j==0)){
        printf("Las sumas de las filas son mayores a medida que se aumenta de fila");
    }else{
        if ((i==1) && (sumaAux%2!=0)){
            printf("La suma de la primera fila no era par");
        }else{
            suma=suma+m[i][j];
            if (j==c){
                if (sumaAux<suma){
                    sumaAux=suma;
                    ejercicio6(m,f,c,0,sumaAux,i+1,0);
                }else{
                    printf("la suma de la fila anterior (%i) era mayor",i);
                }

            }else{
                ejercicio6(m,f,c,suma,sumaAux,i,j+1);
            }
        }

        }


    }



