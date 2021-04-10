#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#include "matrix.h"

int main(){
    Matrix *mat = create_header(5);
    mat = insert_lineM(mat, 1, 2, 3);
    mat = insert_lineM(mat, 1, 3, 5);
    mat = insert_lineM(mat, 1, 4, 6);
    mat = insert_lineM(mat, 1, 5, 7);


    print_matrix(mat);
    return 0;
}