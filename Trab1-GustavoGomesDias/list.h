#ifndef __list_h__
#define __list_h__

typedef struct list List;

List *create_list();

int size_list(List *lst);

void insert_list(List *lst, info_t info, int pos);

void remove_list(List *lst, int pos);

void print_list(List *lst);

void free_list(List *lst);

#endif