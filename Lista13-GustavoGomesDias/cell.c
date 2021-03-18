#include <stdio.h>
#include <stdlib.h>
#include "cell.h"


/* Exer1 */
struct cell{
    void *info;
    struct cell *next;
    void (*print)();
};

Cell* create_cell(void *info, void (*print)()){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->info = info;
    new_cell->print = print;
    return new_cell;
}

void print_int(int *info){
    printf("%d", *info);
}

void print_char(char *info){
    printf("%s", info);
}

void *get_info(Cell *arg1){
    return arg1->info;
}

void set_info(Cell *arg1, void* info){
    arg1->info = info;
}

Cell *get_next(Cell *arg1){
    return arg1->next;
}

void set_next(Cell *arg1, Cell *arg2){
    arg1->next = arg2;
}

void print_cell(Cell *c){
    (c->print)(c->info);
}