//librerias estandar
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int main()
{
	int registro;
	puts("Numero de registros: " );
	scanf("%d",&registro);
	int oHora[registro],oMinuto[registro],aHora[registro], aMinuto[registro];

	for(int i=0;i<registro;i++)
	{
		//los que tengan o son hora oficial de FIN clase
		//las a son HORA ACTUAL
		scanf("%d%d%d%d",&oHora[i], &oMinuto[i],&aHora[i], &aMinuto[i]); //lee las variables correspondientes para la hora, minuto, almacenadas en un arreglo 
		if(oMinuto[i]>60 || aMinuto[i]<0 || (oHora[i]<8 && oHora[i]>20) || (aHora[i]<oHora[i] && aHora[i]>oHora[i]+1)){ //hace la comparacion
			printf("No esta dentro del rango\n");
		}
	}
	int minutos=0;
	for (int i = 0; i < registro; i++)
	{

		if(oHora[i]==aHora[i]){
			minutos=minutos+(aMinuto[i]-oMinuto[i]);
		}else if(oHora[i]==(aHora[i]-1)){
			minutos=minutos+(60-oMinuto[i]);
		}
		printf("minutos:%d\n", minutos);

	}
	printf("%d",minutos/registro);
		
}