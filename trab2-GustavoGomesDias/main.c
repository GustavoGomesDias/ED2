#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"
#include "matrix.h"

int main(){
    Matrix *mat = create_header(5);
    mat = insert_lineM(mat, 1, 2, 3);
    // mat = insert_lineM(mat, 1, 2, 4);


    // print_matrix(mat);
    return 0;
}