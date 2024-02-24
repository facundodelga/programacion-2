/*Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_P 7
#define MAX_F 9
#define MAX_H 6

typedef struct{
    char pat[MAX_P];
    int velR;
    int velM;
    char fecha[MAX_F];
    char hora[MAX_H];
}TReg;

void ej25Lee();
void ej25Muestra();

int main(){
    ej25Lee();
    return 0;
}

void ej25Lee(){
    FILE *archbin=NULL, *arch=NULL;
    TReg reg;
    int contReg = 0, contProc = 0; // cuenta registrados y cuenta procesados
    arch = fopen("p1e25.txt","r");
    if (arch == NULL)
        printf("error al abrir archivo \n");
    else{
        archbin = fopen("p1e25.dat","wb");

        while(!feof(arch)){
            fscanf(arch,"%s %d %d %s %s\n",&reg.pat,&reg.velR,&reg.velM,&reg.fecha,&reg.hora);
            printf("%d\n",reg.velR);
            if(reg.velR >= reg.velM * 1.20){
                fwrite(&reg,sizeof(TReg),1,archbin);
                contReg++;
            }

            contProc++;
        }


    }
    printf("procesados: %d \n registrados: %d \n",contProc,contReg);
    fclose(arch);
    fclose(archbin);
}
