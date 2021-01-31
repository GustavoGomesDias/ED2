#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *create_list(){
    return NULL;
}

/* Exer2
List *insert_end(List *lst, int info){
    Cell *tmp = lst;
    Cell *new_cell = create_cell();
    set_info(new_cell, info);
    if(tmp == NULL){
        return new_cell;
    }
    while(get_next(tmp) != NULL){
        tmp = get_next(tmp);
    }

    set_next(tmp, new_cell);
    return lst;
} */

// Exer5
List *insert_first(List *lst, int info){
    lst = insert_list(lst, info, 0);
    return lst;
}

// Exer5
List *insert_end(List *lst, int info){
    lst = insert_list(lst, info, Size(lst));
    return lst;
}

// Exer4
List* insert_list(List *lst, int info, int pos){
    int i = 0;
    Cell *aux;
    Cell *tmp = lst;

    Cell *new_cell = create_cell();
    set_info(new_cell, info);

    if(tmp == NULL){
        return new_cell;
    }
    
    if(pos <= 0){
        set_next(new_cell, tmp);
        return new_cell;
    }

    if(pos >= Size(lst)){
        while(get_next(tmp) != NULL){
            tmp = get_next(tmp);
        }

        set_next(tmp, new_cell);
        return lst;
    }
    
    while(i < pos){
        aux = tmp;
        tmp = get_next(tmp);
        i++;
    }

    set_next(aux, new_cell);
    set_next(new_cell, tmp);
    return lst;
}

// Exer1
int Size(List *lst){
    Cell *tmp = lst;
    int i = 0;
    while(tmp != NULL){
        tmp = get_next(tmp);
        i++;
    }
    return i;
}

// Exer2
int search(List *lst, int info){
    Cell *tmp = lst;
    int i = 0;
    while(tmp != NULL){
        if(get_info(tmp) == info){
            return i;
        }
        tmp = get_next(tmp);
        i++;
    }
    return -1;
}

// Exer6
List *remove_elem(List *lst, int pos){
    int i = 0;
    Cell *tmp = lst;
    Cell *aux, *aux2;
    
    if(pos == 0){
        aux = get_next(tmp);
        return aux;
        free_cell(tmp);
    }

    while(i != pos){
        aux = tmp;
        tmp = get_next(tmp);
        i++;
    }
    
    if(get_next(tmp) != NULL){
        aux2 = get_next(tmp);
        set_next(aux, aux2);
        free_cell(tmp);
        return lst;
    }

    free_cell(tmp);
    set_next(aux, NULL);
    return lst;

}

// Exer7
List *search_remove(List *lst, int info){
    lst = remove_elem(lst, search(lst, info));
    return lst;
}

// Exer8
List *insert_decre(List *lst, int info){
    Cell *tmp = lst;
    Cell *aux;
    Cell *new_cell = create_cell();
    set_info(new_cell, info);
    
    if(tmp == NULL){
        return new_cell;
    }
    
    if(get_info(tmp) == info){
        set_next(new_cell, tmp);
        return new_cell;
    }

    while(info < get_info(tmp)){
        aux = tmp;
        tmp = get_next(tmp);
    }
    
    if(get_next(tmp) == NULL){
        set_next(tmp, new_cell);
        return lst;
    }

    // printf("Tmp - %d", get_info(aux));

    set_next(aux, new_cell);
    set_next(new_cell, tmp);
    return lst;
}


void print_list(List *lst){
    Cell *tmp = lst;
    while(tmp != NULL){
        print_cell(tmp);
        tmp = get_next(tmp);
    }
}