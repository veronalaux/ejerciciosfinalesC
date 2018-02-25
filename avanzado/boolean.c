#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {

    char expresion[100] = "(V|V)&F&(F|V)";
    int i, j,k;
    int contador;
    int resultado[100];
    int parentesis[100];
    int fueraparen[100];

    for (i = 0; i < 100; i++) {
        switch (expresion[i]) {
            case'F':
                resultado[i] = 0;
                break;
            case'V':
                resultado[i] = 1;
                break;
            case'|':
                resultado[i] = 2;
                break;
            case'&':
                resultado[i] = 3;
                break;
            case'!':
                resultado[i] = 4;
                break;
            case'(':
                resultado[i] = 5;
                break;
            case')':
                resultado[i] = 6;
                break;
            case' ':
                resultado[i] = 7;
                break;
        }
    }

    for (j = 0; j < 100; j++) {
        contador = j;
        if (resultado[j] == 5) {
            do {
                parentesis[contador] = resultado[contador];
                //printf("%s",&expresion[contador]);
                contador++;
            } while (resultado[contador - 1] != 6);
        } else {
            fueraparen[j] = resultado[j];
            
        }
    }
    
    for(k=0;k<100;k++){
/*
        if(resultado[k] > 7 || resultado[k] < 0){
            break;
        }
*/
        printf("%d",parentesis[k]);
    }

    return 0;
}

