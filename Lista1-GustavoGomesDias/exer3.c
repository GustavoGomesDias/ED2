#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que lˆe um vetor de inteiros e “remove” os elementos contendo o valor 0 (transfira-
os para o final do vetor). Mostre o vetor resultante na tela.

Exemplo: O vetor 0 1 3 -1 0 0 5 fica 1 3 -1 5 0 0 0. */

int main(){
    int i, j, cont, tam;
    printf("Tamanho do vetor: ");
    scanf("%d", &tam);
    int vetor[tam];
    for(i = 0; i < tam; i++){
        printf("Digite os números: ");
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < tam; i++){
        if(vetor[i] == 0){
            cont++;
        }
    }
    for(i = 0; i < tam; i++){
        if(i > 0 && vetor[i-1] == 0){
            for(j = (i-1); j < tam; j++){
                vetor[j] = vetor[j+1];
            }
        }
        if(vetor[i] == 0){
            for(j = i; j < tam; j++){
                vetor[j] = vetor[j+1];
            }
        }
    }
    for(i = 0; i <= cont; i++){
        vetor[tam - i] = 0;
    }
    printf("\n");
    for(i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}