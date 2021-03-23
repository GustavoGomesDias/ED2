#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "stack.h"

int main(int argc, char **argv){
    Stack *stk = create_stack(argc);

    int i = atoi(argv[1]);
    int i2 = atoi(argv[2]);
    push(stk, &i, print_int);
    push(stk, &i2, print_int);

    int cont;
    for(cont = 3; cont < argc; cont++){
        if(argv[cont][0] == '+'){
            push(stk, argv[cont], print_char);
        }else if(argv[cont][0] == '*'){
            push(stk, &argv[cont][0], print_char);
        }else{
            int k = atoi(argv[cont]);
            push(stk, &k, print_int);
        }
    }
    
    
    
    return 0;
}