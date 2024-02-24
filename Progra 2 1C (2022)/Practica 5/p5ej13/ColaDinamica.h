typedef int TElementoC;

typedef struct nodoC{
    TElementoC dato;
    struct nodoC *sig;
}nodoC;

typedef struct {
    nodoC *pri,*ult;
}TCola;

void iniciaC (TCola *);
int vaciaC (TCola);
void poneC (TCola *, TElementoC);
void sacaC (TCola *, TElementoC *);
TElementoC consultaC (TCola);

