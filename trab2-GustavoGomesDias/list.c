#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct List{
    Cell *start;
};

List *create_list(){
    List *lst = (List *) malloc(sizeof(List));
    lst->start = NULL;

    return lst;
}
