#define N 5

typedef int TElementoC;

typedef struct{
int pri, ult;
TElementoC datos[N];
} TCola;

void iniciaC(TCola *c);

void poneC(TCola *c, TElementoC x);

void sacaC(TCola *c, TElementoC *x);

TElementoC consultaC(TCola c);

int vaciaC(TCola c);
