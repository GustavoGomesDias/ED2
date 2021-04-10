#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *create_list(){
    return NULL;
}

// l = linha, c = coluna
List *insert_line(List *lst, info_t info, int l, int c){
    Cell *new_cell = create_cell(info, l, c);
    Cell *tmp = lst;
    if(tmp == NULL){
        return new_cell;
    }else{
        Cell *aux;
        if(get_column(tmp) > c){
            set_next_l(new_cell, tmp);
            return new_cell;
        }
        if(get_next_l(tmp) != NULL){
            while(get_next_l(tmp) != NULL && c > get_column(tmp)){
                aux = tmp;
                tmp = get_next_l(tmp);
            }
            if(tmp != NULL && get_column(tmp) > c){
                set_next_l(aux, new_cell);
                set_next_l(new_cell, tmp);
            }else{
                set_next_l(tmp, new_cell);
            }
        }else{
            set_next_l(tmp, new_cell);
        }
    }
    return lst;
}

// l = linha, c = coluna
List *insert_column(List *lst, info_t info, int l, int c){
    Cell *new_cell = create_cell(info, l, c);
    Cell *tmp = lst;
    if(tmp == NULL){
        return new_cell;
    }else{
        Cell *aux;
        if(get_line(tmp) > l){
            set_next_c(new_cell, tmp);
            return new_cell;
        }

        if(get_next_c(tmp) != NULL){
            while(get_next_c(tmp) != NULL && l > get_line(tmp)){
                aux = tmp;
                tmp = get_next_c(tmp);
            }
            if(tmp != NULL && get_line(tmp) > l){
                set_next_c(aux, new_cell);
                set_next_c(new_cell, tmp);
            }else{
                set_next_c(tmp, new_cell);
            }
        }else{
            set_next_c(tmp, new_cell);
        }
    }
    return lst;
}

void print_list(List *lst){
    Cell *tmp = lst;
    while(tmp != NULL){
        printf("%d; %d; %f\n", get_line(tmp), get_column(tmp), get_info(tmp));
        tmp = get_next_l(tmp);
    }
}

void free_elemLine(List *lst, int column){
    Cell *tmp = lst;
    if(get_column(tmp) == column){
        if(get_next_l(tmp) != NULL){
            lst = get_next_l(tmp);
            free_cell(tmp);
        }else{
            free_cell(tmp);
        }
    }else{
        Cell *aux;
        while(get_column(tmp) != column && tmp != NULL){
            aux = tmp;
            tmp = get_next_l(tmp);
        }
        if(get_column(tmp) == column){
            if(get_next_l(tmp) != NULL){
                set_next_l(aux, get_next_l(tmp));
            }else{
                set_next_l(aux, NULL);
            }
            free_cell(tmp);
        }
    }
}

void free_elemColumn(List *lst, int line){
    Cell *tmp = lst;
    if(get_line(tmp) == line){
        if(get_next_l(tmp) != NULL){
            lst = get_next_l(tmp);
        }else{
            lst = NULL;
        }
        free_cell(tmp);
    }else{
        Cell *aux;
        while(get_line(tmp) != line && tmp != NULL){
            aux = tmp;
            tmp = get_next_l(tmp);
        }

        if(get_next_l(tmp) != NULL){
            set_next_l(aux, get_next_l(tmp));
        }else{
            set_next_l(aux, NULL);
        }
        free_cell(tmp);
    }
}