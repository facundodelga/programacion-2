#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendalib.h"

int main()
{
    int validos=0;
    agenda agnda[max_sch];
    char nombre[]="facundo ";
    crear(&validos,agnda,0);
    mostrarAgenda(validos,agnda);
    //agregarContacto(&validos,agnda,validos);
    //mostrarAgenda(validos,agnda);

    if(!buscarContacto(validos,agnda,nombre))
        printf("el contacto no existe");
    else
        printf("el contacto existe");

    return 1;
}
