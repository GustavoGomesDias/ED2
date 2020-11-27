#include <stdlib.h>
#include <stdio.h>


void calcula(float l, float *area, float *perimetro){
	*area = l * l;
	*perimetro = l * 4;
}


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