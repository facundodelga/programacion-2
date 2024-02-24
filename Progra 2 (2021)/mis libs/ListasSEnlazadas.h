typedef int datoL;
typedef struct nodo{
    datoL dato;
    struct nodo *sig;
}NodoL;

NodoL* crearNodo(datoL x);
void insertarFinal(NodoL **,datoL x);
int insertarInicio(NodoL **,datoL x);
void mostrarLista(NodoL *);
