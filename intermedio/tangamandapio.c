#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numero_real(char);
int main(){
	char numero_tangamandapiense[100];
//do{
	puts("Ingresa un numero tangamandapiense");
	scanf("%[^\n]%*c", &numero_tangamandapiense);
	int tamano = 0;
	while (numero_tangamandapiense[tamano] != '\0')
		tamano += 1; 
	int numero_r[tamano];
	for(int i = 0; i < tamano; i++)
		numero_r[i] = numero_real(numero_tangamandapiense[i]);
	int potencias[tamano];
	int potencia = 0;
	for(int i = 0; i < tamano; i++){
		potencias[i] = pow(6,i);
	}
	
    int suma = 0; 
	int j = tamano - 1;
	for(int i = 0; i < tamano; i++){
		suma += potencias[i] * numero_r[j];
		j--;
	}
	printf("suma: %d\n", suma);
//}while(numero_tangamandapiense != "#");
	return EXIT_SUCCESS;
}

int numero_real(char num){
	switch(num){
		case 37: 
			return 0;
		break;

		case 41:
			return 1;
		break;

		case 126:  
			return 2;
		break; 

		case 64: 
			return 3;
		break;

		case 63: 
			return 4; 
		break; 

		case 92:
			return 5; 
		break; 

		case 36:
			return -1;
		break;
	}
}