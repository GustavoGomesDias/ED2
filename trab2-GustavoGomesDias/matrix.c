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
        set_next_l(mat->head_l[i], NULL);
        set_next_c(mat->head_c[i], NULL);
    }

    return mat;
}

// l = linha e c = coluna
Matrix *insert_lineM(Matrix *mat, int l, int c, info_t info){
    if(get_next_l(mat->head_l[l]) == NULL){
        List *lst = create_list();
        lst = insert_line(lst, info, l, c);
        set_next_c(mat->head_l[l], lst);
        return mat;     
    }
    if(get_next_l(mat->head_l[l]) != NULL && get_column(mat->head_l[l]) > c){
        Cell *tmp = get_next_l(mat->head_l[l]);


         insert_line(lst, info, l, c);
        // set_next_l(mat->head_l[l], get_start(lst));
        return mat;
    }

}

void print_matrix(Matrix *mat){
    int i;
    for(i = 1; i <= mat->dimension; i++){
        Cell *tmp = mat->head_l[i];
        if(get_next_(tmp) != NULL){
            print_list(get_next_(tmp));
        }
    }
}   