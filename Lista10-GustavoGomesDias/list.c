#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// NÃO CONSEGUI FAZER O INSERT_LIST 

struct list{
    int size;
    Cell *first, *last;
};

List *create_list(){
    List *lst = (List *) malloc(sizeof(List));
    lst->first = NULL;
    lst->last = NULL;
    lst->size = 0;
    return lst;
}

int size_list(List *lst){
    return lst->size;
}

void count_size(List *lst){
    lst->size += 1;
}

void insert_int(List *lst, void *info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_int(info);
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else{
        if(pos == 0){
            set_next(new_cell, lst->first);
            set_prev(lst->first, new_cell);
            lst->first = new_cell;
        }else if(pos >= (size_list(lst) -1 )){
            set_next(lst->last, new_cell);
            set_prev(new_cell, lst->last);
            lst->last = new_cell;
        }else{
            int i = 0;
            while(i != pos){
                tmp = get_next(tmp);
                i++;
            }
            set_next(new_cell, tmp);
            set_prev(new_cell, get_prev(tmp));
            set_prev(tmp, new_cell);
            set_next(get_prev(new_cell), new_cell);
        }
    }
    count_size(lst);
}

void insert_float(List *lst, void *info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_float(info);
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else{
        if(pos == 0){
            set_next(new_cell, lst->first);
            set_prev(lst->first, new_cell);
            lst->first = new_cell;
        }else if(pos >= (size_list(lst) -1 )){
            set_next(lst->last, new_cell);
            set_prev(new_cell, lst->last);
            lst->last = new_cell;
        }else{
            int i = 0;
            while(i != pos){
                tmp = get_next(tmp);
                i++;
            }
            set_next(new_cell, tmp);
            set_prev(new_cell, get_prev(tmp));
            set_prev(tmp, new_cell);
            set_next(get_prev(new_cell), new_cell);
        }
    }
    count_size(lst);
}

void insert_str(List *lst, void *info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_str(info);
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else{
        if(pos == 0){
            set_next(new_cell, lst->first);
            set_prev(lst->first, new_cell);
            lst->first = new_cell;
        }else if(pos >= (size_list(lst) -1 )){
            set_next(lst->last, new_cell);
            set_prev(new_cell, lst->last);
            lst->last = new_cell;
        }else{
            int i = 0;
            while(i != pos){
                tmp = get_next(tmp);
                i++;
            }
            set_next(new_cell, tmp);
            set_prev(new_cell, get_prev(tmp));
            set_prev(tmp, new_cell);
            set_next(get_prev(new_cell), new_cell);
        }
    }
    count_size(lst);
}

void insert_cell_list(List *lst, void *info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_cell_list(info);
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else{
        if(pos == 0){
            set_next(new_cell, lst->first);
            set_prev(lst->first, new_cell);
            lst->first = new_cell;
        }else if(pos >= (size_list(lst) -1 )){
            set_next(lst->last, new_cell);
            set_prev(new_cell, lst->last);
            lst->last = new_cell;
        }else{
            int i = 0;
            while(i != pos){
                tmp = get_next(tmp);
                i++;
            }
            set_next(new_cell, tmp);
            set_prev(new_cell, get_prev(tmp));
            set_prev(tmp, new_cell);
            set_next(get_prev(new_cell), new_cell);
        }
    }
    count_size(lst);
}

void remove_elem(List *lst, int pos){
    if(pos <=  0){
        Cell *aux = get_next(lst->first);
        Cell *aux2 = lst->first;
        
        free_cell(aux2);
        set_prev(aux, NULL);
        lst->first = aux;
    }else if(pos >=size_list(lst) - 1){
        Cell *aux = get_prev(lst->last);
        Cell *aux2 = lst->last;
        
        free_cell(aux2);
        set_next(aux, NULL);
        lst->last = aux;
    }else{
        int i = 0;
        Cell *tmp =lst->first;
        
        while(i != pos){
            tmp = get_next(tmp);
            i++;
        }
        Cell *aux = get_prev(tmp); 
        set_next(aux, get_next(tmp));
        set_prev(get_next(aux), aux);
    }
     lst->size += 1;
}

void print_list(List *lst){
    Cell *tmp = lst->first;
    if(tmp == NULL){
        printf("[]");
    }else{    
        printf("[");
        while(tmp != NULL){
            print_cell(tmp);
            if(get_next(tmp) != NULL){
                printf(", ");
            }
            tmp = get_next(tmp);
        }
        printf("]");
    }

}

void free_list(List *lst){
    Cell *tmp = lst->first;
    Cell *aux;
    while(tmp != NULL){
        aux = get_next(tmp);
        call_free(tmp);
        tmp = aux;
    }

    free(lst);
}