#ifndef __cell_h__
#define __cell_h__
#include "list.h"

/* Exer2 */
typedef struct cell Cell;

Cell* create_int(void *info);

Cell* create_float(void *info);

Cell* create_str(void *info);

Cell* create_cell_list(void *info);

void print_int(int *info);

void print_float(float *info);

void print_str(char *info);

void print_cell(Cell *c);

void* get_info(Cell *arg1);
void set_info(Cell *arg1, void* info);

Cell *get_next(Cell *arg1);
void set_next(Cell *arg1, Cell *arg2);

Cell *get_prev(Cell *arg1);
void set_prev(Cell *arg1, Cell *arg2);

void print_cell(Cell *c);

void free_cell(Cell *arg1);

void call_free(Cell *arg1);

#endif