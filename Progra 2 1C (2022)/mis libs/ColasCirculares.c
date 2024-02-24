#include "ColasCirculares.h"
#include <stdlib.h>
#include <stdio.h>


void IniciaC (TCola *c){
    c->pri = -1;
    c->ult = -1;
}
int VaciaC(TCola c){
    return (c.pri ==-1);
}
TElementoC ConsultaC(TCola c){
    if (c.pri !=-1)
        return c.dato[c.pri];
}
void SacaC(TCola *c, TElementoC *x){
    if ((*c)->pri != -1){
        *x = (*c)->dato[(*c)->pri];
        if ((*c)->pri == (*c)->ult)
            IniciaC(c);
        else{
            if ((*c)->pri == 49)
                (*c)->pri = 0;
            else
                (*c)->pri +=1;
        }
    }
}
void PoneC(TCola *c, TElementoC x){
    if (!((*c)->ult == 49 && (*c)->pri == 0 || (*c)->ult+1 == (*c)->pri)){

        if((*c)->pri == -1){
            (*c)->pri = 0;
            (*c)->ult = 0;
        }else{
            if ((*c)->ult == 49)
                (*c)->ult = 0;
            else
                (*c)->ult +=1;
            (*c)->dato[(*c)->ult] = x;
        }
    }
}

