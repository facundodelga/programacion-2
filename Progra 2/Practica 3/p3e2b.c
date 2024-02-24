#include <stdlib.h>
#include <stdio.h>
#define MAX 20

int posicionX(float [],int ,float );
int posicionXBin(float [],int ,int ,float );

int main(){
    float v[MAX]={1.3,3.4,6.3,8.1,8.5,10.5,14.3};
    printf("posicion de 6.3: %d\n",posicionX(v,6,8.5));
    printf("posicion de 6.3[BIN]: %d\n",posicionXBin(v,0,6,6.3));
    return 0;
}

int posicionX(float f[MAX],int v,float x){
    if(v < 0 || f[v] == x)
        return v;
    else
        return posicionX(f,v-1,x);

}

int posicionXBin(float f[MAX],int v,int i,float x){ //  v = 0 --- i = validos - 1
    if(v > i && f[v] != x){
        return -1;
    }else{
        if(f[v] == x)
            return v;
        else
            if(f[i] == x)
                return i;
            else
                return posicionXBin(f,v+1,i-1,x);
    }
}
