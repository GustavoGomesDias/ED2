#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

int main(int argv, char **argc){
    int i;
    List *lst = create_list();
    for(i = 0; i < 10; i++){
        insert_list(lst, i, i);
    }
    print_list(lst);

    printf("\n");

    insert_list(lst, 11, -1);

    print_list(lst);

    // printf("Size %d", size_list(lst));

    // printf("Posição - %d (se for -1 é por que não está na lista).", search_list(lst, 0));

    return 0;
}