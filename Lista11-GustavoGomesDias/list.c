#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list{
    info_t *info;
    int size;
};

List *create_list(int len){
    List *lst = (List *)malloc(sizeof(List));
    lst->info = malloc(sizeof(int) * len);
    lst->size = 0;
    return lst;
}

int size(List *lst){
    return lst->size;
}

void insert_list(List *lst, info_t info, int pos){
    if(pos <= 0){
        lst->info[0] = info;
    }else if(pos >= lst->size){
        lst->info[lst->size] = info;
    }else{
    lst->info[pos] = info;
    }
    if((lst->size - 1) <= pos){
        lst->size += 1;
    }
}

void remove_elem(List *lst, int pos){
    if(pos < 0 || pos > lst->size){
        printf("Posição inválida!\n");
    }else{
        int i;
        for(i = pos; i < lst->size; i++){
            lst->info[i] = lst->info[i + 1];
        }
        lst->size -= 1;
    }
}

int search_elem(List *lst, int elem){
    int i;
    for(i = 0; i < lst->size; i++){
        if(lst->info[i] == elem){
            return i;
        }
    }
    return -1;
}

void print_lst(List *lst){
    int i;
    for(i = 0; i < lst->size; i++){
        printf("%d° da lista => %d ", i, lst->info[i]);
    }
}


void free_list(List *lst){
    free(lst->info);
    free(lst);
}