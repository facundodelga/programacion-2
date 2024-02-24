#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

int cuantosArboles(arbol a){

    if(a)
        return 1 + cuantosArboles(a->der);

}

int cuantosArbolesNoRec(arbol a){
    int i = 0;
    while(a){
        a = a->der;
        i++;
    }
    return i;
}
