#ifndef __list_h__
#define __list_h__
#include "cell.h"

typedef Cell List;

List *create_list();

List *insert_line(List *lst, info_t info, int l, int c);
List *insert_column(List *lst, info_t info, int l, int c);

void print_list(List *lst);

void free_line(List *lst, int column);

void free_column(List *lst, int line);

#endif