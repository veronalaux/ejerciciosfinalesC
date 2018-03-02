#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n_veces; 

	scanf("%d", &n_veces);

	int contador = 0; 

	while(contador < n_veces){

		int renglones, columnas;
		scanf("%d%d", &renglones,&columnas);

		int matriz_patron[renglones][columnas];

		for(int i = 0; i < renglones; i++)
			for(int j = 0; j < columnas; j++){
				scanf("%d",&matriz_patron[i][j]);
			}

		int renglones_gmat, columnas_gmat;
		scanf("%d%d",&renglones_gmat, &columnas_gmat);

		int matriz_gmat[renglones_gmat][columnas_gmat];

		for(int i = 0; i < renglones_gmat; i++)
			for(int j = 0; j < columnas_gmat; j++){
				scanf("%d",&matriz_gmat[i][j]);
			}


		for(int i = 0; i < renglones_gmat - renglones + 1; i++)
			for(int j = 0; j < columnas_gmat - columnas + 1; j++){
				if (matriz_gmat[i][j] == matriz_patron[0][0]){
					int bandera = 1;
					for(int x = 0; x < renglones && bandera==1; x++){
						for(int y = 0; y < columnas; y++){
							if(matriz_patron[x][y] != matriz_gmat[i + x][j + y]){
								bandera = 0;	
							}
					}
				}

				if( bandera == 1 ){
					for( int m = 0; m < renglones; m++ )
						for( int n = 0; n < columnas; n++ ){
							if( matriz_gmat[i + m][j + n] == 1 )
								matriz_gmat[ i + m][ j + n ] = 2;
							else
								matriz_gmat[i + m ][ j + n ] = 9;
						}			
				}
			}
		}

		puts("");

		for(int i = 0; i < renglones_gmat; i++){
			for(int j = 0; j < columnas_gmat; j++){
				if(matriz_gmat[i][j] == 9)
					printf("* ");
				else
					printf("%d ",matriz_gmat[i][j]);
			}
			puts("");
		}

		puts("");



		contador++;
	}

	return EXIT_SUCCESS;
}