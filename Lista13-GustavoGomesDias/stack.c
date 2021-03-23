#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack{
    Cell *top;
    int len;
};

Stack *create_stack(int len){
    Stack *new = (Stack *) malloc(sizeof(Stack));
    new->top = NULL;
    new->len = len;
    return new;
}


void push(Stack *stk, void *info, void (*print)()){
    Cell *new = create_cell(info, print);
    if(stk->top == NULL){
        stk->top = new;
    }else{
        set_next(new, stk->top);
        stk->top = new;
    }
    stk->len += 1;
}


void pop(Stack *stk){
    if(get_next(stk->top) != NULL){
        Cell *aux = get_next(stk->top);
        stk->top = aux;
    }
    stk->len -= 1;
}

void peek(Stack *stk){
    if(stk->len != 0){
        printf("Topo ===> ");
        print_cell(stk->top);
        printf("\n");
    }else{
        printf("Pilha vazia!\n");
    }
}

void free_stack(Stack *stk){
    Cell *tmp = stk->top;
    if(tmp != NULL){
        while(get_next(tmp) != NULL){
            tmp = get_next(tmp);
            free(tmp);
        }
        free(stk->top);
        free(stk);
    }else{
        printf("Lista vazia!");
    }
}