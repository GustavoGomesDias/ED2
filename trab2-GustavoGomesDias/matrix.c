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
        set_next_l(mat->head_l[line], lst);
        return mat;
    }

    List *lst = tmp;
    lst = insert_line(lst, info, line, column);
    return mat;    
    
}

Matrix *insert_columnM(Matrix *mat, int line, int column, info_t info){
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

void remove_line(Matrix *mat, int line, int column){
    Cell *tmp = mat->head_l[line];
    if(get_next_l(tmp) == NULL){
        free_cell(tmp);
        mat->head_l[line] = NULL;   
    }else{
        if(get_line(tmp) == line && get_column(tmp) == column && get_next_l(tmp) != NULL){
            List *lst = tmp;
            free_line(lst, column);
            mat->head_l[line] = lst;
        }else{
            List *lst = tmp;
            free_line(lst, column);
        }
    }
}

void remove_column(Matrix *mat, int line, int column){
    Cell *tmp = mat->head_c[column];
    if(get_next_c(tmp) == NULL){
        free_cell(tmp);
        mat->head_c[column] = NULL;   
    }else{
        if(get_line(tmp) == line && get_column(tmp) == column && get_next_c(tmp) != NULL){
            List *lst = tmp;
            free_column(lst, line);
            mat->head_c[column] = lst;
        }else{
            List *lst = tmp;
            free_column(lst, line);
        }
    }
}


void remove_mat(Matrix *mat, int line, int column){
    remove_line(mat, line, column);
    remove_column(mat, line, column);
}

void insert_mat(Matrix *mat, int line, int column, info_t info){
    // Retira se for 0 como entrada
    if(info == 0){
        remove_mat(mat, line, column);
    }else{
        mat = insert_lineM(mat, line, column, info);
        mat = insert_columnM(mat, line, column, info);
    }
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

void free_mat(Matrix *mat){
    int i;
    for(i = 1; i <= mat->dimension; i++){
        Cell *tmp = mat->head_l[i];
        while(tmp != NULL){
            remove_mat(mat, get_line(tmp), get_column(tmp));
            tmp = get_next_l(tmp);
        }
    }
    free(mat->head_l);
    free(mat->head_c);
    free(mat);
}

Matrix *sun(Matrix *mat1, Matrix *mat2){
    int i;
    int dimension =  mat1->dimension;
    Matrix *result = create_header(dimension);

    for(i = 1; i <= dimension; i++){
        Cell *tmp = get_next_l(mat1->head_l[i]);

        while(tmp != NULL){
            insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
            tmp = get_next_l(tmp);
        }
    }

    for(i = 1; i <= dimension; i++){
        Cell *tmp = get_next_l(mat2->head_l[i]);
        Cell *res = get_next_l(result->head_l[i]);
        
        if(res == NULL){
            while(tmp != NULL){
                insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
                tmp = get_next_l(tmp);
            }
        }else{
            int flag = 0;
            while(tmp != NULL){
                Cell *res = get_next_l(result->head_l[i]);
                while(res != NULL){
                    if(get_line(res) == get_line(tmp) && get_column(res) == get_column(tmp)){
                        info_t info = get_info(tmp) + get_info(res);
                        set_info(res, info);
                       flag++;
                    }
                    res = get_next_l(res);
                }

                if(flag != 1){
                    insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
                }
                flag = 0;
                tmp = get_next_l(tmp);
            }
        }
    }

    return result;
}

// Matrix *sun(Matrix *mat1, Matrix *mat2){
//     int i;
//     int dimension =  mat1->dimension;
//     Matrix *result = create_header(dimension);
//     for(i = 1; i <= dimension; i++){

//         Cell *tmp = get_next_l(mat1->head_l[i]);
//         Cell *tmp2 = get_next_l(mat2->head_l[i]);
//         if(tmp == NULL || tmp2 == NULL){

//             if(tmp != NULL && tmp2 == NULL){
//                 while (tmp != NULL){
//                     insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
//                     tmp = get_next_l(tmp);
//                 }
//             }

//             if(tmp == NULL && tmp2 != NULL){
//                 while (tmp2 != NULL){
//                     insert_mat(result, get_line(tmp2), get_column(tmp2), get_info(tmp2));
//                     tmp2 = get_next_l(tmp2);
//                 }
//             }

//         }else{

//             while(tmp != NULL && tmp2 != NULL){
//                 if(get_line(tmp) == get_line(tmp) && get_column(tmp) == get_column(tmp)){
//                     insert_mat(result, get_line(tmp), get_column(tmp), (get_info(tmp) + get_info(tmp2)));
//                 }else{
//                     insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
//                     insert_mat(result, get_line(tmp2), get_column(tmp2), get_info(tmp2));
//                 }
//                 tmp = get_next_l(tmp);
//                 tmp2 = get_next_l(tmp2);
//             }   

//             // if(get_next_l(tmp) != NULL || get_next_l(tmp2) != NULL){

                
//             // }

//             if(get_next_l(tmp) != NULL && get_next_l(tmp2) == NULL){
//                 while (tmp != NULL){
//                     insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
//                     tmp = get_next_l(tmp);
//                 }
//             }

//             if(get_next_l(tmp) == NULL && get_next_l(tmp2) != NULL){
//                 while (tmp2 != NULL){   
//                     insert_mat(result, get_line(tmp2), get_column(tmp2), get_info(tmp2));
//                     tmp2 = get_next_l(tmp2);
//                 }
//             }

//                 // if(get_next_l(tmp) != NULL && get_next_l(tmp2) != NULL){
//                 //     while(tmp != NULL){
//                 //         insert_mat(result, get_line(tmp), get_column(tmp), get_info(tmp));
//                 //         tmp = get_next_l(tmp);
//                 //     }

//                 //     while(tmp2 != NULL){

//                 //         insert_mat(result, get_line(tmp2), get_column(tmp2), get_info(tmp2));

//                 //         tmp2 = get_next_l(tmp2);
//                 //     }
//                 // }

//         }
//     }

//     return result;
// }