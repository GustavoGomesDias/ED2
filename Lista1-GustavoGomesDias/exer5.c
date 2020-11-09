#include <stdio.h>
#include <stdlib.h>
/* Escreva um algoritmo que lˆe do teclado uma matriz 4 ×2 de inteiros. A seguir, troque os elementos
da primeira linha com os elementos da segunda linha e os da terceira linha com a quarta linha.
Imprima a matriz resultante. */

int main(){
    int matriz[4][2];
    int i, j, aux, aux2;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            printf("Num: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            if(i == 0 || i == 2){
                aux = matriz[i][j];
                aux2 = matriz[i+1][j];
                matriz[i][j] = aux2;
                matriz[i+1][j] = aux;
            }
        }
    }
    printf("\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}