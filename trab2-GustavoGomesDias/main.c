#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#include "matrix.h"

int main(int argc, char **argv){
    Matrix *m1, *m2, *m3;
	FILE *file = NULL;
	FILE *file1 = NULL;
	file = fopen(argv[1], "r");
	file1 = fopen(argv[2], "r");
	
	int dimension, i, j;
	info_t info;	
	fscanf(file, "%d", &dimension);
	m1 = create_header(dimension);
	fseek(file, 2, SEEK_SET);
	
	while(fscanf(file, "%d; %d; %g", &i, &j, &info) != EOF){
		insert_mat(m1, i, j, info);
	}
	
	int dimension2, k, l;
	info_t info1;	
	fscanf(file1, "%d", &dimension2);
	m2 = create_header(dimension2);
	fseek(file1, 2, SEEK_SET);
	while(fscanf(file1, "%d; %d; %g", &k, &l, &info1) != EOF){
		insert_mat(m2, k, l, info1);
	}
	
	print_matrix(m1);
	printf("\n");
	print_matrix(m2);
	printf("\n");
	
	m3 = sun(m1, m2);
	print_matrix(m3);

	fclose(file);
	fclose(file1);
    return 0;
}