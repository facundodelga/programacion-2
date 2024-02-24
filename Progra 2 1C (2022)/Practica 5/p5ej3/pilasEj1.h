

typedef char* TElementoP;

typedef struct nodop{
    TElementoP dato;
    struct nodop *sig;
}nodop;

typedef nodop *TPila;

void poneP (TPila *, TElementoP );
void sacaP (TPila *, TElementoP *);
TElementoP consultaP(TPila);
int vaciaP (TPila );
void iniciaP (TPila *);
