#ifndef __cell_h__
#define __cell_h__

typedef struct cell Cell;

Cell *create_cell();

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

int get_info(Cell *arg1);
void set_info(Cell *arg1, int info);

void print_cell(Cell *arg1);

void free_cell(Cell *arg1);

#endif