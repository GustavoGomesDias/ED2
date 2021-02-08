#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Exer3
List *create_list(){
    List *lst = malloc(sizeof(List) * 1);
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
    return lst;
}

void insert_first(List *lst, int info){
    Cell *new_cell = create_cell(info);
    if(lst->first != NULL){
        set_next(new_cell, lst->first);
    }
    if(lst->last == NULL){
        lst->last = new_cell;
    }
    lst->first = new_cell;
    lst->size += 1;
}

void print_list(List *lst){
    Cell *tmp = lst->first;
    if(tmp == NULL){
        printf("Lista vazia!");
    }
    while(tmp != NULL){
        print_cell(tmp);
        tmp = get_next(tmp);
    }

}

void free_list(List *lst){
    Cell *tmp = lst->first;
    Cell *aux;
    while(tmp != NULL){
        aux = get_next(tmp);
        free_cell(tmp);
        tmp = aux;
    }
}


int size_list(List *lst){
    return lst->size;
}

// Tentar modificar para colocar como void
int search_list(List *lst, int info){
    Cell *tmp = lst->first;
    int i = 0;
    if(info == get_info(lst->last)){
        return (size_list(lst) - 1);
    }else{
        while(tmp != NULL){
            if(get_info(tmp) == info){
                return i;
            }
            tmp = get_next(tmp);
            i++;
        }
    }
    return -1;
}


void insert_list(List *lst, int info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_cell(info);

    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
        lst->size += 1;
    }else{
        if(pos <= 0){
            set_next(new_cell, tmp);
            lst->first = new_cell;
            lst->size += 1;
        }else if(pos >= size_list(lst)){
            set_next(lst->last, new_cell);
            lst->last = new_cell;
            lst->size += 1;
        }else{
            int i = 0;
            Cell *aux;
            while(i < pos){
                aux = tmp;
                tmp = get_next(tmp);
                i++;
            }
            set_next(aux, new_cell);
            set_next(new_cell, tmp);
            lst->size += 1;
        }
    }
}
