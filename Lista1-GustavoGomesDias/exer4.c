#include <stdio.h>
#include <stdlib.h>
/* Fa ̧ca um programa que leia do teclado uma matriz 3 × 3 de float e normalize os seus valores,
dividindo-os pelo maior valor da matriz. Imprima a matriz normalizada. */

int main(){
    float matriz[3][3];
    float tmp;
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Num: ");
            scanf("%f", &matriz[i][j]);
        }
    }
    float maior = matriz[0][0];
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    if(maior != 0){
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                tmp = matriz[i][j];
                matriz[i][j] = (tmp/maior);
            }
        }
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}