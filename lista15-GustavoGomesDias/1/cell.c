#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cell.h"

struct Cell{
    int num;
    struct Cell *prev, *next;
};

Cell *create_cell(){
    Cell *new_cell = (Cell *)malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    return new_cell;
}

int get_info(Cell *arg1){
    return arg1->num;
}

void set_info(Cell *arg1, int info){
    arg1->num = info;
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

void free_cell(Cell *arg1){
    free(arg1);
}