typedef char TElementoP;   //son pilas dinamicas
typedef struct nodop{
    TElementoP dato;
    struct nodop *sig;
}nodop;
typedef nodop *TPila;

void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P);
TElementoP consultaP(TPila P);
int vaciaP(TPila P);
void iniciaP(TPila *P);
void mostrarP(TPila *p);

