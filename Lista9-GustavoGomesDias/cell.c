#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

/* Exer1 */
struct cell{
    info_t info;
    struct cell *next, *prev;
};

Cell* create_cell(info_t info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->info = info;
    return new_cell;
}

info_t get_info(Cell *arg1){
    return arg1->info;
}

void set_info(Cell *arg1, info_t info){
    arg1->info = info;
}

Cell *get_next(Cell *arg1){
    return arg1->next;
}

void set_next(Cell *arg1, Cell *arg2){
    arg1->next = arg2;
}

Cell *get_prev(Cell *arg1){
    return arg1->prev;
}

void set_prev(Cell *arg1, Cell *arg2){
    arg1->prev = arg2;
}

void print_cell(Cell *c){
    printf("%d ", c->info);
}

void free_cell(Cell *arg1){
    free(arg1);
}