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
        mat->head_l[i] = create_cell(0, 0, 0);
        mat->head_c[i] = create_cell(0, 0, 0);
    }

    return mat;
}

// l = linha e c = coluna
Matrix *insert_lineM(Matrix *mat, int line, int column, info_t info){
    // Retira se for 0 como entrada
    if(info == 0){
        if(get_next_l(mat->head_l[line]) != NULL){
            List *lst = get_next_l(mat->head_l[line]);
            
            // Tenho que criar um free na list pra manejar os heads
            // free_elemLine(lst, column);
        }
        return mat;
    }
    
    Cell *tmp = get_next_l(mat->head_l[line]);

    if(tmp == NULL){    
        List *lst = create_list();
        lst = insert_line(lst, info, line, column);
        set_next_l(mat->head_l[line], lst);
        return mat;
    }

    if(tmp != NULL && get_column(tmp) > column){
        List *lst = tmp;
        lst = insert_line(lst, info, line, column);
        mat->head_l[line] = lst;
        return mat;
    }

    List *lst = tmp;
    lst = insert_line(lst, info, line, column);
    return mat;    
    
}

Matrix *insert_columnM(Matrix *mat, int line, int column, info_t info){
    // Retira se for 0 como entrada
    if(info == 0){
        if(get_next_c(mat->head_c[column]) != NULL){
            List *lst = get_next_c(mat->head_c[column]);
            
            // Tenho que criar um free na list pra manejar os heads
            // free_elemcolumn(lst, column);
        }
        return mat;
    }
    
    Cell *tmp = get_next_c(mat->head_c[column]);

    if(tmp == NULL){    
        List *lst = create_list();
        lst = insert_column(lst, info, line, column);
        set_next_c(mat->head_c[column], lst);
        return mat;
    }

    if(tmp != NULL && get_line(tmp) > column){
        List *lst = tmp;
        lst = insert_column(lst, info, line, column);
        mat->head_c[column] = lst;
        return mat;
    }

    List *lst = tmp;
    lst = insert_column(lst, info, line, column);
    return mat;    
    
}

void print_matrix(Matrix *mat){
    int i;
    for(i = 1; i <= mat->dimension; i++){
        Cell *tmp = mat->head_l[i];
        if(get_next_l(tmp) != NULL){
            print_list(get_next_l(tmp));
        }
    }
}   