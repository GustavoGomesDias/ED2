#include <stdlib.h>
#include <stdio.h>
#include "exer3.h"

int main(int argv, char **argc){
	int a = 1;
	int b = 2;
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d", a, b);
	
	return 0;
}