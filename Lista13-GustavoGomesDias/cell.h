#ifndef __cell_h__
#define __cell_h__

typedef struct cell Cell;

Cell* create_cell(void *info, void (*print)());

void print_int(int *info);
void print_char(char *info);

void *get_info(Cell *arg1);
void set_info(Cell *arg1, void* info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

void print_cell(Cell *arg1);

#endif