#ifndef __list_h__
#define __list_h__
#include "cell.h"

/* Exer2 */
typedef Cell List;

List *create_list();

/* Exer5 */
List* insert_first(List *lst, int info);

/* Exer7 */
void print_list(List *lst);

void free_list(List *lst);

#endif