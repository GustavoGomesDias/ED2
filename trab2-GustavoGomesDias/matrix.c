#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct Matrix{
    Cell **head_l;
    Cell **head_c;
    int dimension;
};

Matrix *create_header(int dimension){
    int i;
    Matrix *mat = (Matrix *) malloc(sizeof(Matrix));

    mat->head_l = malloc(sizeof(Cell *) * (dimension + 1));
    mat->head_c = malloc(sizeof(Cell *) * (dimension + 1));
    mat->dimension = dimension;

    for(i = 0; i < (dimension + 1); i++){
        mat->head_l[i] = NULL;
        mat->head_c[i] = NULL;
    }

    return mat;
}