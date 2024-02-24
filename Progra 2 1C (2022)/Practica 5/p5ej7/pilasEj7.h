
typedef int TElementoP;

typedef struct nodoP{
    TElementoP dato;
    struct nodoP *sig;
} nodoP;

typedef nodoP *TPila;

void poneP (TPila *,TElementoP);
void sacaP (TPila *,TElementoP *);
TElementoP consultaP (TPila);
int vaciaP (TPila);
void iniciaP (TPila *);
