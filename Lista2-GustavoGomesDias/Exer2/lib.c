#include <stdlib.h>
#include <stdio.h>

void exer2(int num){
	int i;
	int soma = 0;
	if(num == 1 || num == 2){
		printf("Não é um número perfeito!");
	}
	
	for(i = 1; i < num; i++){
		if(num%i == 0){
			soma += i;
		}
	}
	if(soma == num){
		printf("É um número perfeito");
	}else{
		printf("Não é um número perfeito!");
	}
	
}