#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

int main(int argv, char **argc){
    int i = 0;
    List *lst = create_list();
    for(i = 0; i < 10; i++){
        lst = insert_first(lst, i);
    }
    print_list(lst);
    free_list(lst);
    print_list(lst);
    return 0;
}