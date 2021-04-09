#ifndef __list_h__
#define __list_h__
#include "cell.h"

typedef struct List List;

List *create_list();

void insert_line(List *lst, float info, int l, int c);
void insert_column(List *lst, float info, int l, int c);

Cell *get_start(List *lst);

void print_list(Cell *start);

#endif