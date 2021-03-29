#ifndef __cell_h__
#define __cell_h__

typedef struct Cell Cell;

Cell *create_cell();

int get_info(Cell *arg1);
void set_info(Cell *arg1, int info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

Cell *get_prev(Cell *arg1);
void set_prev(Cell *arg1, Cell *arg2);

void free_cell(Cell *arg1);

#endif