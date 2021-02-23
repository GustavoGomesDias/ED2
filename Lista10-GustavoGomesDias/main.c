#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "list.h"

// [3456, "abc", 657.444, ["xyz", 3424, []], "oi"]


int main(){
    List *lst = create_list();
    int i = 3456;
    char *c = "abc";
    float f = 657.444;
    insert_int(lst, &i, 0);
    insert_float(lst, &f, 1);
    insert_str(lst, c, 2);
    char *c2 = "xyz";
    int k = 3424;
    List *n = create_list();
    List *lst2 = create_list();
    insert_str(lst2, c2, 0);
    insert_int(lst2, &k, 1);
    insert_cell_list(lst2, n, 2);
    char *oi = "oi";
    insert_cell_list(lst, lst2, 3);
    insert_str(lst, oi, 4);
    print_list(lst);


    return 0;
}