#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool factor(int);
int main(){
    int e;
    printf("Ingrese el numero de veces a ejecutar el programa\n");  
    scanf("%d", &e);  
	int inicio[e], cantidad[e];
	//Guardo en arreglos el numero en donde inicia y la cantidad de numeros que se evaluan
    for(int i=0;i<e;i++) {
    	printf("Ingresa a i(numemro de inicio) y n(cantidad de numeros a evaluar): \n");
		scanf("%d%d", &inicio[i], &cantidad[i]); 	
	}
	//El ciclo exterior itera en los arreglos anteriores y el de adentro es el que
	//itera sobre los numeros que se evaluan, y es donde cada vez que entra mando a llamar a la funcion factor
	//para saber si es perfecto o no.
	for(int i=0;i<e;i++){
		printf("--------------------\n" );
	for(int j=inicio[i]; j<=(inicio[i]+cantidad[i]); j++){
				if (factor(j)==true){
					printf("%d es perfecto\n",j);
				}else{
				printf("%d no es perfecto\n",j);}		
			
		} 
	}
	}

bool factor(int i){
	int suma=0, factor=0;
for(int x=1; x<i; x++) {
		factor=i%x;
		if(factor==0) {
			suma+=x;
		}
	}
	if(suma==i)
		return true;
	else
		return false;
}