#include <stdlib.h>
#include <stdio.h>

void exer5(int *vetor, int linha, int coluna){
	int i, j, aux, aux2;
	for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			if(i == 0){
				aux = vetor[i * coluna + j];
				aux2 = vetor[(i + 1) * coluna + j];
				vetor[i * coluna + j] = aux2;
				vetor[(i + 1) * coluna + j] = aux;
			}
		}
	}
}

void print_mat(int *vetor, int linha, int coluna){
	int i, j;
	for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			printf("%d ", vetor[i * coluna + j]);
		}
		printf("\n");
	}
}