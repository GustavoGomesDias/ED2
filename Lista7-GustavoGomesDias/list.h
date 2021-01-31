#ifndef __list_h__
#define __list_h__
#include "cell.h"

typedef Cell List;

List *create_list();

// Exer5
List *insert_first(List *lst, int info);

// Exer2 e Exer5
List *insert_end(List *lst, int info);

// Exer4
List *insert_list(List *lst, int info, int pos);

// Exer1
int Size(List *lst);

// Exer2
int search(List *lst, int info);

// Exer6
List *remove_elem(List *lst, int pos);

// Exer7
List *search_remove(List *lst, int info);

// exer8
List *insert_decre(List *lst, int info);

void print_list(List *lst);


#endif