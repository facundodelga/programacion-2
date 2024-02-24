typedef struct {
    char DNI[9];
    float promedio;
}TElementoP;

typedef struct {
     TElementoP datos[50];
       int      tope;
} TPila;

void IniciaP(TPila *);
int VaciaP(TPila );
TElementoP ConsultaP(Tpila );
void SacaP(TPila *,TElementoP *);
void PoneP(TPila *,TElementoP );
