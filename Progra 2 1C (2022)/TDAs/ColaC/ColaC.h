#define N 50

typedef int TElementoC;

typedef struct{
	TElementoC datos[N];
	int pri, ult;
} TCola;

void iniciaC(TCola *c);

int vaciaC(TCola c);

TElementoC consultaC(TCola c);

void sacaC(TCola *c, TElementoC *x);

void poneC(TCola *c, TElementoC x);