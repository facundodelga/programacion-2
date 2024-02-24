#include <stdio.h>
int fSuma(){

	FILE *txt;
	int aux,total=0;
	txt=fopen("tp1ej12.txt","r");
	while (!feof(txt)){
		fscanf(txt,"%i",&aux);
		total+=aux;
	}
	fclose(txt);
	return total;
}
void main(){

	printf("el resultado es: %i",fSuma());

}

