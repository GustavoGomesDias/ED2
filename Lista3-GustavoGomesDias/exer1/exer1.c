#include <stdlib.h>
#include <stdio.h>

void calcula(float l, float *area, float *perimetro){
	*area = l * l;
	*perimetro = l * 4;
}