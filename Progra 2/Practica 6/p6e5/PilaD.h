typedef int TElementoP;

typedef struct nodo{
    TElementoP dato;
    struct nodo *sig;
}nodop;

typedef nodop *TPila;

void IniciaP (TPila * P);

void poneP (TPila * P, TElementoP x);

void sacaP (TPila * P, TElementoP * x);

TElementoP consultaP(TPila P);

int VaciaP (TPila P);

