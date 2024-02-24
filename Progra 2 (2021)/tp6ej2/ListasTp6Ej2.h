
typedef char datoL;

typedef struct nodo{
    int dato;
    struct nodo *sig;
}NodoL;

NodoL* crearNodo(datoL x);
int insertarFinal(NodoL **,datoL x);
int insertarInicio(NodoL **,datoL x);
void mostrarLista(NodoL *);
