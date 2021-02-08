#ifndef __cell_h__
#define __cell_h__

/* Exer2 */
typedef struct cell Cell;

Cell* create_cell(int info);

int get_info(Cell *arg1);
void set_info(Cell *arg1, int info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

void print_cell(Cell *c);

void free_cell(Cell *arg1);

#endif