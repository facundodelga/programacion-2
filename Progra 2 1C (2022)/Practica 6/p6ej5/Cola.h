#define MAX 50
typedef int TElementoC;
typedef struct {
TElementoC datos[MAX];
 int pri, ult; } TCola;


void IniciaC (TCola * C);
int VaciaC (TCola C);
TElementoC ConsultaC (TCola C);
void SacaC (TCola *C, TElementoC* x);
void PoneC (TCola *C, TElementoC x);
