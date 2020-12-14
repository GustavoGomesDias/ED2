#ifndef __cell_h__
#define __cell_h__

typedef int info_t;

typedef struct cell Cell;

Cell* create_cell(info_t info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

void print_cell(Cell *c);

void free_cell(Cell *arg1);

#endif