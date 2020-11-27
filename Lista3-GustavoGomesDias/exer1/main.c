#include <stdlib.h>
#include <stdio.h>
#include "exer1.h"

int main(int argv, char **argc){
	float l;
	printf("Lado do quadrado: ");
	scanf("%f", &l);
	float area;
	float perimetro;
	
	calcula(l, &area, &perimetro);
	printf("Área é  %.2f e o Perímetro %.2f", area, perimetro);
	return 0;
}