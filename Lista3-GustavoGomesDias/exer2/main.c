#include <stdlib.h>
#include <stdio.h>
#include "exer2.h"


int main(int argv, char **argc){
	int i, tam;
	printf("Tamanho do vetor: ");
	scanf("%d", &tam);
	int v[tam];
	for(i = 0; i < tam; i++){
		v[i] = i;
	}
	imprime(v, tam);
	return 0;
}