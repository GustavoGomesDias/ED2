#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int main(int argc, char **argv){
	int i, j, linha, coluna;
	int cont = 0;
	printf("Digite o número de linhas: ");
	scanf("%d", &linha);
	printf("Digite o número de colunas: ");
	scanf("%d", &coluna);
	int mat[linha][coluna];
	for(i = 0; i < linha; i++){
		for(j = 0; j < coluna; j++){
			mat[i][j] = cont;
			cont++;
		}
	}
	print_mat((int *) mat, linha, coluna);
	exer5((int *) mat, linha, coluna);
	printf("\n");
	print_mat((int *) mat, linha, coluna);
	
	return 0;
}