#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que leia o nome de uma pessoa, a quantidade de provas realizadas por ela e suas
respectivas notas. O programa deve apresentar ao final o nome e a média das notas obtidas pela
pessoa.
*/

int main(){
	char nome[100];
	int qtd_prova, i;
	float nota, media;
	float cont_nota = 0;
	printf("Digite seu nome:\n");
	scanf("%[^\n]", nome);
	printf("\nQuantidades de provas feitas:\n");
	scanf("%d", &qtd_prova);
	for(i = 0; i < qtd_prova; i++){
		printf("Digite a nota da prova %d°:", (i+1));
		scanf("%f", &nota);
		cont_nota += nota;
	}
	media = cont_nota/qtd_prova;
	printf("%s, sua média é %.2f", nome, media);
	
	return 0;
}