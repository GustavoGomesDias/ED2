#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "stack.h"

int main(){
    Stack *stk = create_stack(5);
    int i1 = 5;
    int i2 = 4;
    int i3 = 3;
    int i4 = 2;
    int i5 = 1;
    push(stk, &i1, print_int);
    push(stk, &i2, print_int);
    push(stk, &i3, print_int);
    push(stk, &i4, print_int);
    push(stk, &i5, print_int);

    peek(stk);

    Stack *stk2 = create_stack(5);
    char *a1 = "e";
    char *a2 = "d";
    char *a3 = "c";
    char *a4 = "b";
    char *a5 = "a";
    push(stk2, a1, print_char);
    push(stk2, a2, print_char);
    push(stk2, a3, print_char);
    push(stk2, a4, print_char);
    push(stk2, a5, print_char);

    peek(stk2);
    return 0;
}