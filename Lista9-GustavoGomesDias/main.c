#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

int main(){
    int i;
    List *lst = create_list();

    for(i = 0; i < 10; i++){
        insert_list(lst, i, i);
    }
    
    print_list(lst);
    
    printf("\n");

    remove_elem(lst, 5);

    print_list(lst);

    free_list(lst);

    return 0;
}