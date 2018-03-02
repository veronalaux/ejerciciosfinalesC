#include <stdio.h>
#include <stdlib.h>

/**
* Funcion encargada de buscar el patron de la matriz A
* en la matriz B.
*/
void buscarPatron(int renglonA, int columnaA, char A[][columnaA], int renglonB, int columnaB, char B[][columnaB] );

int main(){
	int n, renglonA, columnaA, renglonB, columnaB;
//	printf("ingresa el numero de veces que se ejecutara el programa: ");
	scanf( "%d%*c", &n );
	puts( "" );
	int repeticiones = 0;
	while( repeticiones < n ){
	//	printf("ingresa el tamano de la matriz A: ");
		scanf( "%d%d%*c", &renglonA, &columnaA );
		char A[ renglonA ][ columnaA ];
		for( int i = 0; i < renglonA; i ++ )
		
			scanf( "%[^\n]%*c", A[i] );
		 puts( "" );
		scanf( "%d%d%*c", &renglonB, &columnaB );
		char B[ renglonB ][ columnaB ];
		for( int i = 0; i < renglonB; i++ )
			scanf( "%[^\n]%*c", B[ i ] );
		puts( "" );
		buscarPatron( renglonA, columnaA, A, renglonB, columnaB, B );
		puts( "" );
		for( int i = 0; i < renglonB; i++ ){
			for( int j = 0; j < columnaB; j++ )
				printf( "%c", B[i][j] );
			puts( "" );
		}
		puts( "" );
		repeticiones++;
	}
	return EXIT_SUCCESS;
}

void buscarPatron( int renglonA, int columnaA, char A[][columnaA], int renglonB, int columnaB, char B[][columnaB] ){
	int bandera;
	for( int i = 0; i <= renglonB - renglonA; i++ )
		for( int j = 0; j <= columnaB - columnaA; j++ ){
			if( B[i][j] == A[0][0] ){
				bandera = 1; 
				for( int m = 0; m < renglonA && bandera == 1; m++ )
					for( int n = 0; n < columnaA; n++ ){
						if( B[ i + m ][j + n ] == A[ m ][ n ] )
							;
						else{
							bandera = 0;
							break;
						}
					}
				if( bandera == 1 ){
					for( int m = 0; m < renglonA; m++ )
						for( int n = 0; n < columnaA; n++ ){
							if( B[i + m][j + n] == '1' )
								B[ i + m ][ j + n ] = '2';
							else
								B[i + m ][ j + n ] = '*';
						}			
				}
		}
	}
}
//iz a derecha y hacia abajo 