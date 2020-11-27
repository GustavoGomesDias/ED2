#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
	int c = *a;
	int d = *b;
	*b = c;
	*a = d;
}

int main(int argv, char **argc){
	int a = 1;
	int b = 2;
	
	swap(&a, &b);
	printf("%d %d", a, b);
	
	return 0;
}