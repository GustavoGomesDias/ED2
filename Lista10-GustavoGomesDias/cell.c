#include <stdio.h>
#include <stdlib.h>
#include "cell.h"


/* Exer1 */
struct cell{
    void *info;
    struct cell *next, *prev;
    void (*print)();
    void (*func_free)();
};

Cell* create_int(void *info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->info = info;
    new_cell->print = print_int;
    new_cell->func_free = free_cell;
    return new_cell;
}

Cell* create_float(void *info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->info = info;
    new_cell->print = print_float;
    new_cell->func_free = free_cell;
    return new_cell;
}

Cell* create_str(void *info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->info = info;
    new_cell->print = print_str;
    new_cell->func_free = free_cell;
    return new_cell;
}

Cell* create_cell_list(void *info){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->next = NULL;
    new_cell->prev = NULL;
    new_cell->info = info;
    new_cell->print = print_list;
    new_cell->func_free = free_list;
    return new_cell;
}

void print_int(int *info){
    printf("%d", *info);
}

void print_float(float *info){
    printf("%3.3f", *info);
}

void print_str(char *info){
    printf("%s", info);
}

void print_cell(Cell *c){
    (c->print)(c->info);
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

Cell *get_prev(Cell *arg1){
    return arg1->prev;
}

void set_prev(Cell *arg1, Cell *arg2){
    arg1->prev = arg2;
}

void free_cell(Cell *c){
    free(c);
}

void call_free(Cell *arg1){
    (arg1->func_free)(arg1);
}