#include <stdio.h>
#define max 10
typedef struct registro TVehiculos;
struct registro {
    char patente[6];
    float vel;
    float maxVel;
    char fecha[11];
    char hora[6];
};

void cargarDat(int *i,int *k);
void mostrarDat(int i,int k);

void main(){
    int validos=0,leidos=0;

    cargarDat(&validos,&leidos);
    //printf("%d\n",validos);
    mostrarDat(validos,leidos);
}

void cargarDat(int *i,int *k){
    FILE *archtxt,*archdat;
    TVehiculos vehiculo[max];

    int j=0;

    archtxt=fopen("tp1ej25.txt","r");
    archdat=fopen("tp1ej25.dat","wb");

    while(!feof(archtxt)){

        fscanf(archtxt,"%s %f %f %s %s\n",vehiculo[j].patente,&vehiculo[j].vel,&vehiculo[j].maxVel,vehiculo[j].fecha,vehiculo[j].hora);
//        printf("%s %f %f %s %s\n",vehiculo[j].patente,vehiculo[j].vel,vehiculo[j].maxVel,vehiculo[j].fecha,vehiculo[j].hora);
        //printf("%s\n",vehiculo[j].patente);
        if ((vehiculo[j].maxVel+(vehiculo[j].maxVel*0.2)<vehiculo[j].vel)){
            fwrite(&vehiculo[j],sizeof(TVehiculos),1,archdat);
            *i += 1;
        }

        j++;
    }
    fclose(archtxt);
    fclose(archdat);
    *k=j;
}

void mostrarDat(int i,int k){
    FILE *arch;
    TVehiculos vehiculo[max];
    int j=0;
    arch=fopen("tp1ej25.dat","rb");
//    while(!feof(arch)&&j<i){
//        fread(&vehiculo[j],sizeof(TVehiculos),1,arch);
//        printf("%s %f %f %s %s\n",vehiculo[j].patente,vehiculo[j].vel,vehiculo[j].maxVel,vehiculo[j].fecha,vehiculo[j].hora);
//        j++;
//    }
    for (j=0;j<i;j++){
        fread(&vehiculo[j],sizeof(TVehiculos),1,arch);
        printf("%s %f %f %s %s\n",vehiculo[j].patente,vehiculo[j].vel,vehiculo[j].maxVel,vehiculo[j].fecha,vehiculo[j].hora);
    }
    fclose(arch);
    printf("Se han leido %i registros y se han encontrado %i infracciones",k,i);
    //printf("%i",j);
}

