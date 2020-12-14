#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

/* Exer1 */
struct cell{
    int info;
    struct cell *next;
};

/* Exer4 */
Cell* create_cell(int info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->info = info;
    return new_cell;
}

Cell *get_next(Cell *arg1){
    return arg1->next;
}

void set_next(Cell *arg1, Cell *arg2){
    arg1->next = arg2;
}

/* Exer6 */
void print_cell(Cell *c){
    printf("%d ", c->info);
}

/* Exer8 */
void free_cell(Cell *arg1){
    free(arg1);
    arg1 = NULL;
}