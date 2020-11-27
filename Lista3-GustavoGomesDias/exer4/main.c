#include <stdlib.h>
#include <stdio.h>
#include "exer4.h"


int main(int argv, char **argc){
	int mat[5][4];
	preenche((int *) mat, 5, 4);
	print_mat((int *) mat, 5, 4);
	return 0;
}