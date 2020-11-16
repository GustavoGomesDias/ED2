#include <stdlib.h>
#include <stdio.h>

void exer4(int *vetor, int linha, int coluna){
	int i, j;
	for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			printf("%d ", vetor[i * coluna + j]);
		}
		printf("\n");
	}
}