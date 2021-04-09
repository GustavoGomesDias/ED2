#include <stdio.h>
#include <stdlib.h>
#include "cell.h"

struct Cell{
    float info;
    int line, column;
    struct Cell *next_l, *next_c;
};

Cell *create_cell(float info, int line, int column){
    Cell *new_cell = (Cell *) malloc(sizeof(Cell));
    new_cell->info = info;
    new_cell->line = line;
    new_cell->column = column;
    new_cell->next_l = NULL;
    new_cell->next_c = NULL;

    return new_cell;
}

float get_info(Cell *arg1){
    return arg1->info;
}

void set_info(Cell *arg1, float info){
    arg1->info = info;
}

Cell *get_next_l(Cell *arg1){
    return arg1->next_l;
}

void set_next_l(Cell *arg1, Cell *arg2){
    arg1->next_l = arg2;
}

int get_line(Cell *arg1){
	return arg1->line;
	// Pega a linha
}

void set_line(Cell *arg1, int line){
	arg1->line = line;
	// Seta a linha
}

int get_column(Cell *arg1){
	return arg1->column;
	// Pega a coluna
}

void set_column(Cell *arg1, int columns){
	arg1->column = columns;
	// Seta a coluna
}

Cell *get_next_c(Cell *arg1){
    return arg1->next_c;
}

void set_next_c(Cell *arg1, Cell *arg2){
    arg1->next_c = arg2;
}

void free_cell(Cell *arg1){
    free(arg1);
}