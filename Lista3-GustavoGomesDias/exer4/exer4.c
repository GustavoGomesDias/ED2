#include <stdlib.h>
#include <stdio.h>

void preenche(int *mat, int linha, int coluna){
	int i;
	for(i = 0; i < 20; i++){
		mat[(i%20) + (i/20)] = i;
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