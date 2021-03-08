#ifndef __list_h__
#define __list_h__

typedef int info_t;

typedef struct list List;

List *create_list(int len);

int size(List *lst);

void insert_list(List *lst, info_t info, int pos);

void remove_elem(List *lst, int pos);

int search_elem(List *lst, int elem);

void print_lst(List *lst);

void free_list(List *lst);

#endif