#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* Exer3 */
List *create_list(){
    return NULL;
}

/* Exer5 */
List* insert_first(List *lst, int info){
    Cell *new_cell = create_cell(info);
    Cell *tmp = lst;
    if(tmp == NULL){
        return new_cell;
    }
    set_next(new_cell, tmp);
    return new_cell;
}

/* Exer7 */
void print_list(List *lst){
    Cell *tmp = lst;
    if(tmp == NULL){
        printf("Lista vazia!");
    }
    while(tmp != NULL){
        print_cell(tmp);
        tmp = get_next(tmp);
    }
}

void free_list(List *lst){
    Cell *tmp = lst;
    Cell *aux;
    while(tmp != NULL){
        aux = get_next(tmp);
        free_cell(tmp);
        tmp = aux;
    }
}