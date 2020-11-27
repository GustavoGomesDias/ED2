#include <stdlib.h>
#include <stdio.h>


void imprime(int *v, int tam){
	int i;
	for(i = 0; i < tam; i++){
		printf("%d ", v[i]);
	}
}