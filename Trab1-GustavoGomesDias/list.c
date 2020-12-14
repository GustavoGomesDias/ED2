#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

struct list{
    Cell *first;
    Cell *last;
    int len;
};

List *create_list(){
    List *lst = malloc(sizeof(List) * 1);
    lst->first = NULL;
    lst->last = NULL;
    lst->len = 0;
    return lst;
}

int size_list(List *lst){
    return lst->len;
}

void insert_list(List *lst, info_t info, int pos){
    Cell *new_cell = create_cell(info);
    if(lst->first == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
        lst->len = 1;
    }else{
        if(pos < 1 || pos == 1){
            set_next(new_cell, lst->first);
            lst->first = new_cell;
            lst->len += 1;
        }else if(pos > lst->len){
            set_next(lst->last, new_cell);
            lst->last = new_cell;
            lst->len += 1;
        }else{
            int i = 1;
            Cell *tmp = lst->first;
            Cell *aux;
            while(i < pos){
                aux = tmp;
                tmp = get_next(tmp);
                i++;
            }
            set_next(new_cell, tmp);
            set_next(aux, new_cell);
            lst->len += 1;
        }
    }
}

void print_list(List *lst){
    Cell *tmp = lst->first;
    while(tmp != NULL){
        print_cell(tmp);
        tmp = get_next(tmp);
    }
}

void remove_list(List *lst, int pos){
    if(pos > lst->len || pos < 1){
        printf("Posição não encontrada.");
    }else{
        if(pos == 1){
            Cell *aux = lst->first;
            lst->first = get_next(lst->first);
            free_cell(aux);
            lst->len -= 1;
        }else if(pos == lst->len){
            Cell *tmp = lst->first;
            Cell *aux;
            while(get_next(tmp) != NULL){
                aux = tmp;
                tmp = get_next(tmp);
            }
            lst->last = aux;
            set_next(aux, NULL);
            free_cell(tmp);
            lst->len -= 1;
        }else{
            int i = 0;
            Cell *tmp = lst->first;
            Cell *aux;
            Cell *aux2;
            while(i < pos){
                aux2= aux;
                aux = tmp;
                tmp = get_next(tmp);
                i++;
            }
            set_next(aux2, tmp);
            free_cell(aux);
            lst->len -= 1;
        }
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
    free(lst);
}