#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
char frase1[100],frase2[100];

int cantidad,cantidad2;

void imprimir_nombre(char[]);
bool par_o_non(char[]);
int array_size(char[]);
void main(){

  printf("Nombre y el tipo de cara del jugador 1\n");
  scanf("%[^\n]%*c",&frase1);
  printf("Numero de lanzamientos\n");
  scanf("%d%*c",&cantidad);
  int numeros[cantidad];
  printf("Los numeros caidos\n");
  for(int x=0;x<cantidad;x++){
    scanf("%d",&numeros[x]);
  }
  scanf("%*c");
  printf("Nombre y el tipo de cara del jugador \n");
  scanf("%[^\n]%*c",&frase2);
  printf("Numero de lanzamientos\n");
  scanf("%d",&cantidad2);
  int numeros2[cantidad2];
  printf("Los numeros caidos\n");
  scanf("%*c");
  for(int x=0;x<cantidad2;x++){
    scanf("%d",&numeros2[x]);
  }
  bool j1=par_o_non(frase1);
  bool j2=par_o_non(frase2);
  int contador1=0;
  for(int x=0;x<cantidad;x++){
    if(j1&&numeros[x]%2==0)
      contador1++;
  }
  int contador2=0;
  for(int x=0;x<cantidad2;x++){
    if(j1&&numeros2[x]%2==1)
      contador2++;
  }
  puts("##########################");
  imprimir_nombre(frase1);
  printf("\nellos ganaron %d veces\n",contador1);
  imprimir_nombre(frase2);
  printf("\nellos ganaron %d veces",contador2);


}
bool par_o_non(char frase[]){
  int cont=array_size(frase);
  if(frase[cont-1]=='r'&&frase[cont-2]=='a'&&frase[cont-3]=='p')
    return true;
  return false;
}
int array_size(char frase[]){
  int cont=0;
  while(frase[cont]!='\0'){
    cont++;
  }
  return cont;
}
void imprimir_nombre(char frase[]){
  for(int x=0;x<array_size(frase)-3;x++)
    printf("%c",frase[x]);
}