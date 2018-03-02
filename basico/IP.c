#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char ip[10][32];
int numeros[10][4];

void bintoint(int);

int main(){
  int repeticiones;
  char temporal=',';
  scanf("%d%*c",&repeticiones);
  for(int rep=0;rep<repeticiones;rep++){
    scanf("%[^\n]%*c",&ip[rep][0]);
  }
  bintoint(repeticiones);
  for(int rep=0;rep<repeticiones;rep++){
    for(int x=0;x<4;x++){
      printf("%d.",numeros[rep][x]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
void bintoint(int repeticiones){
  int suma;
  int recorrido;
  for(int rep=0;rep<repeticiones;rep++){
    for(int x=0;x<4;x++){
      suma=0;
      for(int y=0;y<8;y++){
        suma+=(ip[rep][y+8*x]-48)*pow(2,7-y);
        numeros[rep][x]=(int)suma;
      }
    }
  }
}