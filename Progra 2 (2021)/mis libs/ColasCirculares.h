typedef int TElementoC;
typedef struct{
    TElementoC dato[50];
    int pri,ult;
}TCola;

void IniciaC(TCola *c);
int VaciaC(TCola c);
TElementoC ConsultaC(TCola c);
void SacaC(TCola *c, TElementoC *x);
void PoneC(TCola *c, TElementoC x);
