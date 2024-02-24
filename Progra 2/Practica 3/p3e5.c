#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int esSimetrica(int [][MAX],int ,int ,int );

int main(){

    return 0;
}

int esSimetrica(int m[][MAX],int i,int j,int n){
    if (i > n )
        return 1;
    else
            if(i == j)
                return esSimetrica(m,i+1,j,n);
            else
                if(j+1 < n)
                    return m[i][j] == m[j][i] && esSimetrica(m,i,j+1,n);
                else
                    return m[i][j] == m[j][i] && esSimetrica(m,i+1,0,n);

}
