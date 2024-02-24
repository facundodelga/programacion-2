#include <stdio.h>

void cargarDat (short int *infracc,short int *registros){
	FILE *archtxt, *archdat;
	char patente[6],fecha[11],hora[6],auxC;
	float vel, maxVel,auxVel;
	archtxt=fopen("tp1ej25.txt","r");
	archdat=fopen("tp1ej25.dat","wb");
    rewind(archtxt);
	while (!feof(archtxt)){

        fscanf(archtxt,"%s %f %f %s %s\n",patente,&vel,&maxVel,fecha,hora);

//        printf("%s ",patente);
//        printf(" %5.2f ",vel);
//        printf(" %5.2f ",maxVel);
//        printf(" %s %s\n",fecha,hora);

		if ((maxVel+(maxVel*0.2))<vel){
			fprintf(archdat,"%s %5.2f %5.2f %s %s\n",patente,&vel,&maxVel,fecha,hora);
			*infracc++;
		}
        registros++;
	}

	fclose(archtxt);
	fclose(archdat);
}
void mostrar(short int infracciones,short int registros){
    FILE *arch;
    char patente[6],fecha[11],hora[6];
	float vel, maxVel;
	arch=fopen("tp1ej25.dat","rb");

    while (!feof(arch)){
        fscanf(arch,"%s %f %f %s %s\n",patente,&vel,&maxVel,fecha,hora);
        printf("%s ",patente);
        printf(" %5.2f ",vel);
        printf(" %5.2f ",maxVel);
        printf(" %s %s\n",fecha,hora);
    }

    printf("Se han registrado %i",infracciones);
    printf(" infracciones de velocidad y %i",registros);
}

void main(){

	short int validos=0,totales=0;

	cargarDat(&validos,&totales);
    mostrar(validos,totales);

}
