#ifndef __matrix_h__
#define __matrix_h__
#include "cell.h"
#include "list.h"


typedef struct Matrix Matrix;

Matrix *create_header(int dimension);

// l = linha e c = coluna
Matrix *insert_lineM(Matrix *mat,int l, int c, float info);

void print_matrix(Matrix *mat);

#endif