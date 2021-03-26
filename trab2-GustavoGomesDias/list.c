#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct List{
    Cell *start;
};

List *create_list(){
    List *lst = (List *) malloc(sizeof(List));
    lst->start = NULL;

    return lst;
}

// l = linha, c = coluna
void insert_line(List *lst, float info, int l, int c){
    Cell *new_cell = create_cell(info, l, c);
    Cell *tmp = lst->start;
    Cell *aux;
    if(tmp == NULL){
        lst->start = new_cell;
    }
    
    if(get_column(tmp) > c){
        set_next_l(new_cell, tmp);
        lst->start = new_cell;
    }

    if(get_next_l(tmp) != NULL){
        while(get_next_l(tmp) != NULL && c > get_column(tmp)){
            aux = tmp;
            tmp = get_next_l(tmp);
        }
        if(tmp != NULL && get_next_c(tmp) > c){
            set_next_l(aux, new_cell);
            set_next_l(new_cell, tmp);
        }else{
            set_next_l(tmp, new_cell);
        }
    }
}

// l = linha, c = coluna
void insert_column(List *lst, float info, int l, int c){
    Cell *new_cell = create_cell(info, l, c);
    Cell *tmp = lst->start;
    Cell *aux;
    if(tmp == NULL){
         lst->start = new_cell;
    }
    
    if(get_line(tmp) > l){
        set_next_c(new_cell, tmp);
    }

    if(get_next_c(tmp) != NULL){
        while(get_next_c(tmp) != NULL && l > get_line(tmp)){
            aux = tmp;
            tmp = get_next_c(tmp);
        }
        if(tmp != NULL && get_next_c(tmp) > l){
            set_next_c(aux, new_cell);
            set_next_c(new_cell, tmp);
        }else{
            set_next_c(tmp, new_cell);
        }
    }
}