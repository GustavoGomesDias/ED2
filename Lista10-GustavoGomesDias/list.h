#ifndef __list_h__
#define __list_h__
#include "cell.h"

typedef struct list List;

List *create_list();

int size_list(List *lst);

void count_size(List *lst);

void insert_int(List *lst, void *info, int pos);

void insert_float(List *lst, void *info, int pos);

void insert_str(List *lst, void *info, int pos);

void insert_cell_list(List *lst, void *info, int pos);

void remove_elem(List *lst, int pos);

void print_list(List *lst);

void free_list(List *lst);

#endif