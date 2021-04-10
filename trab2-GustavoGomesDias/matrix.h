#ifndef __matrix_h__
#define __matrix_h__
#include "cell.h"
#include "list.h"


typedef struct Matrix Matrix;

Matrix *create_header(int dimension);

// l = linha e c = coluna
Matrix *insert_lineM(Matrix *mat,int line, int ccolumn, info_t info);

Matrix *insert_columnM(Matrix *mat, int line, int column, info_t info);

void print_matrix(Matrix *mat);

#endif