typedef int TElementoP;

typedef struct nodop {
	TElementoP dato;
	struct nodop *sig;
} nodop;

typedef nodop *TPila;

void PoneP(TPila *P, TElementoP x);
void SacaP(TPila *P, TElementoP * x);
TElementoP consultaP(TPila P);
int VaciaP(TPila P);
void IniciaP(TPila *P);
