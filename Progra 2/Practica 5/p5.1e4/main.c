#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}


void ascendente(TPila *p,int *rta){
    TElementoP x;
    if(!vaciaP(*p)){
        sacaP(p,&x);
        if(!vaciaP(*p))
            if(x <= consultaP(*p))
                ascendente(p,rta);
            else
                *rta = 0;
        poneP(p,x);
    }
}
