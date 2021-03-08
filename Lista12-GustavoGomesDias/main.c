#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    List *lst = create_list(5);
    insert_list(lst, 1, 0);
    insert_list(lst, 2, 1);
    insert_list(lst, 3, 2);
    insert_list(lst, 4, 3);
    insert_list(lst, 5, 4);
    insert_list(lst, 6, 5);
    insert_list(lst, 7, 6);
    insert_list(lst, 8, 7);
    insert_list(lst, 9, 8);
    insert_list(lst, 10, 9);
    insert_list(lst, 18, 4);

    printf("Size - %d\n", size(lst));

    print_lst(lst);

    printf("\n");

    if(search_elem(lst, 6) != -1){
        printf("Posição do elemeneto - %d", search_elem(lst, 6));
    }else{
        printf("Elemento não está na lista!");
    }
    printf("\n");


    // free_list(lst);

    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);
    remove_elem(lst, 0);

    printf("Size - %d\n", size(lst));

    print_lst(lst);

    return 0;
}