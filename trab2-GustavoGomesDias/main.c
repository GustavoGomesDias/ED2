#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#include "matrix.h"

int main(){
    Matrix *mat = create_header(5);
    insert_mat(mat, 1, 2, 3);
    insert_mat(mat, 1, 3, 5);
    insert_mat(mat, 1, 4, 6);
    insert_mat(mat, 1, 5, 7);

    remove_mat(mat, 1, 5);

    print_matrix(mat);
    return 0;
}