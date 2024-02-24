#define DIM_DNI 9

typedef unsigned long int DNI;
typedef struct nodop {
    DNI dato;
    struct nodop *sig;
}nodop;
typedef nodop *TPila;

void ponerP(TPila *p,DNI dni);
void sacarP(TPila *p,DNI *x);
DNI consultaP(TPila p);
int vaciaP(TPila );
void iniciaP(TPila *p);

