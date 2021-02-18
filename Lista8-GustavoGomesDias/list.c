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
    free(lst);
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

void insert_last(List *lst, int info){
    Cell *tmp = lst->last;
    Cell *new_cell = create_cell(info);
    if(tmp != NULL){
        set_next(tmp, new_cell);
        lst->last = new_cell;
    }else{
        lst->first = new_cell;
        lst->last = new_cell;
    }
    lst->size += 1;
}


void insert_list(List *lst, int info, int pos){
    Cell *tmp = lst->first;
    Cell *new_cell = create_cell(info);
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else{
        if(pos <= 0){
            set_next(new_cell, tmp);
            lst->first = new_cell;
        }else if(pos >= size_list(lst)){
            set_next(lst->last, new_cell);
            lst->last = new_cell;
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
        }
    }
    lst->size += 1;
}


void insert_last2(List *lst, int info){
    insert_list(lst, info, size_list(lst));

}

void insert_first2(List *lst, int info){
    insert_list(lst, info, 0);
}

void remove_list(List *lst, int pos){
    int i = 0;
    Cell *tmp = lst->first;
    Cell *aux, *aux2;
    
    if(pos == 0){
        aux = lst->first;
        lst->first = get_next(aux);
        free_cell(aux);
    }else if(pos >= size_list(lst) - 1){
        while(tmp != lst->last){
            aux = tmp;
            tmp = get_next(tmp);
        }
        aux2 = lst->last;
        free_cell(aux2);
        lst->last = aux;
        set_next(aux, NULL);
        
    }else{
        while(i != pos){
            aux = tmp;
            tmp = get_next(tmp);
            i++;
        }
        aux2 = get_next(tmp);
        set_next(aux, aux2);
        free_cell(tmp);
    }
    lst->size -=1;
}

void remove_elem(List *lst, int info){
    remove_list(lst, search_list(lst, info));
}


void insert_ordered(List *lst, int info){
    Cell *tmp = lst->first;
    Cell *aux;
    Cell *new_cell = create_cell(info);
    
    if(tmp == NULL){
        lst->first = new_cell;
        lst->last = new_cell;
    }else if(get_info(tmp) == info){
        set_next(new_cell, tmp);
        lst->first = new_cell;
    }else if(get_info(lst->last) == info){
        set_next(lst->last, new_cell);
        lst->last = new_cell;
    }else{
        while(get_info(tmp) < info && get_next(tmp) != NULL){
            aux = tmp;
            tmp = get_next(tmp);
        }
        if(lst->first == tmp){
            if(get_info(tmp) > info){
                set_next(new_cell, tmp);
                lst->first = new_cell;
            }else{
                set_next(tmp, new_cell);
            }
        }else if(get_next(tmp) == NULL){
            set_next(tmp, new_cell);
            lst->last = new_cell;
        }else{
            set_next(aux, new_cell);
            set_next(new_cell, tmp);
        }
    }
    lst->size += 1;
}