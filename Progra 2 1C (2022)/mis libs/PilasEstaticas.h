#define DIM 50

typedef int TElementoP;

typedef struct {
    TElementoP datos[DIM];
    int tope;
}TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);
void iniciaP(TPila *P);
