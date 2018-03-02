#include <stdio.h>

int tiempo(int,int);
int main(int argc, char const *argv[])
{
	int pesoMax,kilometros,numVehiculos;
	float tiempototal=0;
	printf("Ingrese pesoMax kilometros numVehiculos\n");
	scanf("%d%d%d",&pesoMax,&kilometros,&numVehiculos);
	int pesoVeh[numVehiculos];
	int velCar[numVehiculos];
	for (int i = 0; i < numVehiculos; ++i)
	{
		printf("peso-velocidad: ");
		scanf("%d%*[-]%d",&pesoVeh[i],&velCar[i]);
		printf("\n");
	}
	for (int i = 0; i < numVehiculos; ++i)
	{
		printf("peso-velocidad: ");
		printf("%d %d",pesoVeh[i],velCar[i]);
		printf("\n");
	}
	int contPeso=0;
	int sumPesoCar=0;
	int i=0;
	int j = 0;
	int menor;
	while(i<numVehiculos)
	{
		sumPesoCar=sumPesoCar+pesoVeh[i];
		if (sumPesoCar+pesoVeh[i+1]>pesoMax)
		{
			menor=velCar[i];
			while(j<=i){

				if (velCar[j]<menor)
				{
					menor=velCar[j];
				}
				j++;
			}
			printf("El menor de %d-%d es %d\n",j,i,menor);
			printf("%d-%d\n",kilometros,menor );

			tiempototal=+tiempototal+tiempo(kilometros,menor);
			sumPesoCar=0;
		}
		i++;
	}
	printf("Resultado: %.2f\n",tiempototal );
	return 0;
}

int tiempo(int kilometros,int s)
{
	float segundos;
	segundos=((float)kilometros/(float)s)*60;
	return segundos;
}