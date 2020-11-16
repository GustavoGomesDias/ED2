#include <stdlib.h>
#include <stdio.h>

void preenche(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		vetor[i] = i;
	}
}

void exer3(int *vetor, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", vetor[i]);
	}
}