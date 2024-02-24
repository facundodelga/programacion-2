typedef struct{
    char cod_materia[6];
    int cuatrimestre;
    unsigned int creditos;
}TElementoP;

typedef struct nodop{
    TElementoP dato;
    struct nodop *sig;
}nodop;

typedef nodop *TPila;

void IniciaP (TPila * P);

void poneP (TPila * P, TElementoP x);

void sacaP (TPila * P, TElementoP * x);

TElementoP consultaP(TPila P);

int VaciaP (TPila P);

