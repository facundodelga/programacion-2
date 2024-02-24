#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

void promRec(TPila *p, int *rta){
    TElementoP x1, x2;
    if(!vaciaP(*p))
        sacaP(p,&x1);
        if(!vaciaP(*p))
            sacaP(p,&x2);
            if(consultaP(*p) == (x1 + x2) / 2)
                (*rta)++;
            poneP(p,&x2)
            promRec(p,rta);

}
