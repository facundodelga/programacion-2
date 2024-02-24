#include <stdio.h>
#include <stdlib.h>
#define N 8
#include "PilaD.h"
#include "ColaD.h"

void Prof(int A[][N], int n);

void Amp(int A[][N], int n);

int main()
{                //A                   B                   C                   D                   E                   F                   G                   H
    int A[][N] = {{0,1,0,1,0,0,0,0},{1,0,1,0,1,0,0,0},{0,1,0,1,0,0,0,0},{1,0,1,0,0,0,0,1},{0,1,0,0,0,1,1,1},{0,0,0,0,1,0,1,1},{0,0,0,0,1,1,0,1},{0,0,0,1,1,0,1,0}}, n = 8;
    Prof(A,n);
    printf("\n*****\n");
    Amp(A,n);
    return 0;
}

void Prof(int A[][N], int n)
{
    int i = 0,j, visitados[N] = {0}, vertice = 0, todos = 0,volvi = 0;
    TPila pila;
    IniciaP(&pila);
    printf("Profundidad:\n");
    poneP(&pila, vertice);
    visitados[vertice] = 1;
    printf("%d\t", vertice + 1);
    todos++;
    while (todos < n)
    {



            vertice = consultaP(pila);
            j = 0;
            while ((j<n) && ((A[vertice][j] == 0) || (visitados[j] == 1)))
                j++;
            if (j<n)
            {
                poneP(&pila,j);
                visitados[j] = 1;
                todos++;
                printf("%d\t",j+1);
            }
            else{
                sacaP(&pila,&vertice);
                volvi = 1;
            }


//        while ((i<n) && (visitados[i] == 1))
//            i++;
//        if (i==n)
//            todos = 1;
//        else
//            vertice = i;
    }
    printf("volvi = %d\n",volvi);
}

void Amp(int A[][N], int n)
{
    int i = 0, j, vertice = 0, visitados[N] = {0}, todos = 0;
    TCola cola;
    IniciaC(&cola);
    printf("Amplitud:\n");
    while (!todos)
    {
        poneC(&cola,vertice);
        visitados[vertice] = 1;
        printf("%d\t",vertice);
        while (!VaciaC(cola))
        {
            sacaC(&cola,&vertice);
            for (j=0;j<n;j++)
                if ((A[vertice][j] != 0) && (visitados[j] == 0))
                {
                    poneC(&cola, j);
                    visitados[j] = 1;
                    printf("%d\t",j);
                }
        }
        while ((i<n) && (visitados[i] == 1))
            i++;
        if (i==n)
            todos = 1;
        else
            vertice = i;
    }
}
