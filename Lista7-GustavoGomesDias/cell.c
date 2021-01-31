#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

struct cell{
    int info;
    struct cell *next;
};

Cell *create_cell(){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->info = 0;
    return new_cell;
}

Cell *get_next(Cell *arg1){
    return arg1->next;
}

void set_next(Cell *arg1, Cell *arg2){
    arg1->next = arg2;
}

int get_info(Cell *arg1){
    return arg1->info;
}

void set_info(Cell *arg1, int info){
    arg1->info = info;
}

void print_cell(Cell *arg1){
    printf("%d ", arg1->info);
}

void free_cell(Cell *arg1){
    free(arg1);
}