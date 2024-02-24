#define CANTMAXNARIO 100

typedef int TElementoAN;

typedef int TPos;

typedef struct {
    TPos HijoIzq, HermanoDer;
    TElementoAN dato;
} TNodo;

typedef struct {
    TNodo Elementos[CANTMAXNARIO];
    int Max;
} TArbolN;

int Vacio(TArbolN A);

int Nulo(TPos p, TArbolN A);

TPos HijoMasIzq(TPos p, TArbolN A);

TPos HnoDer(TPos p, TArbolN A);

TElementoAN Info(TPos p, TArbolN A);

TPos Raiz(TArbolN A);

TPos Padre(TPos p, TArbolN A);

