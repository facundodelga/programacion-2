
typedef struct {
    int numerador;
    int denominador;
}fraccion;


fraccion crear(int numerador, int denominador);
int numerador(fraccion f);
int numerador(fraccion f);
int denominador(fraccion f);
fraccion sumar(fraccion f1, fraccion f2);
fraccion restar(fraccion f1, fraccion f2);
fraccion multiplicar(fraccion f1, fraccion f2);
fraccion dividir(fraccion f1, fraccion f2);
fraccion simplificar(fraccion f); //retorna fraccion simplificada.
int iguales(fraccion f1, fraccion f2); //retorna verdadero o falso.
void mostrarFraccion(fraccion f);
