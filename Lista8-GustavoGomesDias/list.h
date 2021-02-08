#ifndef __list_h__
#define __list_h__
#include "cell.h"

typedef struct list {
  int size;
  Cell *first, *last;
} List;

List *create_list();

void insert_first(List *lst, int info);

void print_list(List *lst);

void free_list(List *lst);

int size_list(List *lst);

int search_list(List *lst, int info);

void insert_list(List *lst, int info, int pos);

#endif