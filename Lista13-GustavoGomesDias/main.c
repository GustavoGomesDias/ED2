#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "stack.h"

int main(int argc, char **argv){
    Stack *stk = create_stack(argc - 1);
    printf("%d", argc);


    if(argc > 2){
        int cont;
        for(cont = argc - 1; cont >= 1; cont--){
            if(argv[cont][0] == '+'){
                push(stk, argv[cont], print_char);
            }else if(argv[cont][0] == '*'){
                push(stk, &argv[cont][0], print_char);
            }else{
                int k = atoi(argv[cont]);
                push(stk, &k, print_int);
            }
            peek(stk);
        }
    }
    
    calc(stk);

    return 0;
}