#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
	int c = *a;
	int d = *b;
	*b = c;
	*a = d;
}

