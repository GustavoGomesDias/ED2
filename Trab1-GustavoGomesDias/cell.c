#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

struct cell{
    info_t info;
    struct cell *next;
};

Cell* create_cell(info_t info){
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

void print_cell(Cell *c){
    printf("%d ", c->info);
}

void free_cell(Cell *arg1){
    free(arg1);
    arg1 = NULL;
}