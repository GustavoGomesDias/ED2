#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

int main(int argv, char **argc){
    int i;
    List *lst = create_list();
    for(i = 0; i < 10; i++){
        lst = insert_first(lst, i);
        // lst = insert_end(lst, i);
        // lst = insert_list(lst, i, i);

    }

    // printf("O tamanho da lista é %d.", Size(lst));

    // int num;
    // printf("Digite o número que você deseja: ");
    // scanf("%d", &num);
    
    // printf("A posição do elemento é %d.", search(lst, num));
    
    // lst = remove_elem(lst, num);
    // print_list(lst);

    // lst = search_remove(lst, num);
    // print_list(lst);

    print_list(lst);

    printf("\n");

    lst = insert_decre(lst, 1);

    print_list(lst);
    
    return 0;
}