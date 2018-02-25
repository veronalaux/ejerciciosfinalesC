#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

char respuesta;

char cadena[5];
cadena[0] = 'V';
cadena[1] = 'V';
cadena[2] = 'F';
cadena[3] = 'F';
cadena[4] = 'V';
int i;

for(i=0;i<5;i++){
    if(cadena[i] == 'V'){
        respuesta = true;
        printf("True");
    }else{
        respuesta = false;
        printf("False");
    }
}

    return 0;
}