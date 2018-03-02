#include <stdio.h>
#include <stdlib.h>

void maxInterval(int[], int);

int main(){

	int ejecuciones, contador=0;
	char input;

	printf("Ingresa el numero de arreglos por analizar:\n");
	scanf("%d%*c", &ejecuciones);

	int array[ejecuciones][20];
	int index[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	printf("Ingresa arreglos\n");
	do{
		scanf("%d%c", &array[contador][index[contador]], &input);
		index[contador]++;
		if(input == '\n')
			contador++;
	}while(contador < ejecuciones);

	for(int i = 0; i < ejecuciones; i++)
		maxInterval(array[i], index[i]);
	

	return EXIT_SUCCESS;
}

void maxInterval(int array[], int index){
	int  max=0, aux=0, inicio, fin;

	for(int i=0; i<index; i++){
		for(int j=i; j<index; j++){
			aux += array[j];
			if(aux > max){
				max = aux;
				inicio = i;
				fin = j;
			}
		}
		aux=0;
	}

	printf("\n%d - %d: %d\n", inicio, fin, max);
}