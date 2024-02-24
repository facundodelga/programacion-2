
#include <stdlib.h>
#include <stdio.h>
#define M 10

int main(){
    int a[][M] = {{-1,-2,-3},{4,5,6},{7,8,9},{11,11,11}}, b[][M] = {{4,7,7},{8,1,1},{1,4,3},{1,7,8}}, n = 4, m = 3;
    return 0;
}

int ejercicio(int a[][M], int i, int j, int n, int m, int suma, int sumaAnt){
    if(i < n)
        if(j < m)
            return ejercicio(a,i,j+1,n,m,suma + a[i][j],sumaAnt);
        else
            if(i == 0 && suma % 2 != 0 || sumaAnt < suma)
                return ejercicio(a,i+1,0,n,m,0,suma);
            else
                return 0;
    else
        return 1;
}
