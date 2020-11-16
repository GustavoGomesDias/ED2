#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

int main(int argc, char **argv){
	int num;
	printf("Digite um número para saber se ele é perfeito: ");
	scanf("%d", &num);
	
	exer2(num);
	
	return 0;
}