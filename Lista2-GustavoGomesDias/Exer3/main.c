#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int main(int argc, char **argv){
	int i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &i);
	int num[i];
	preenche(num, i);
	exer3(num, i);
	
	return 0;
}