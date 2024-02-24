#include <stdio.h>

void hora_formato (int );


int main(){
    hora_formato(8000);
    return 0;
}


void hora_formato (int x){

    int hora = 0,minuto = 0,segundo = 0;

    hora = x / 3600;
    minuto = (x - hora * 3600) /60;
    segundo = x - (hora * 3600 + minuto * 60);

    printf("%d : %d : %d\n",hora,minuto,segundo);
}
