#define N 100

typedef struct{
    int dia;
    int tempMax;
    int tempMin;
}TElementoP;

typedef struct{
    TElementoP datos[N];
    int tope;
}TPila;

void IniciaP (TPila * P);

void poneP (TPila * P, TElementoP x);

void sacaP (TPila * P, TElementoP * x);

TElementoP consultaP(TPila P);

int VaciaP (TPila P);
