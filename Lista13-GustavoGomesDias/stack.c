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

void calc(Stack *stk){
    if(stk->len == 3){
        int *i = ((int *) get_info(stk->top));
        int *i2 = (int *) get_info(get_next(stk->top));
        printf("%d", *i);
        printf("%d", *i2);
        Cell *tmp = get_next(stk->top);
        char *c = (char *) get_info(get_next(tmp));
        if(&c  == '+'){
            printf("aqui");
        }else{
            printf("%d", ((*i) * (*i2)));
        }
    }
    // else{
    //     int *i = ((int *) get_info(stk->top));
    //     int *i2 = (int *) get_info(get_next(stk->top));
    //     Cell *tmp = get_next(stk->top);
    //     int result = 0;
        
    //     char *c = (char *) get_info(get_next(tmp));
    //     if(&c  == '+'){
    //         result = *i + *i2;
    //     }else{
    //         result = *i * *i2;
    //     }

    //     Cell *tmp2 = get_next(get_next(tmp));
    //     while(get_next(tmp2) != NULL){
    //         char *c = (char *) get_info(get_next(tmp));
    //         if(*c == '+'){
    //             int *k = (int *) get_info(get_next(get_next(tmp2)));
    //             result += *k; 
    //         }else{
    //             int *k = (int *) get_info(get_next(get_next(tmp2)));
    //             result *= *k;
    //         }
    //         tmp2 = get_next(tmp2);
    //     }
    //     printf("%d", result);
    // }
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