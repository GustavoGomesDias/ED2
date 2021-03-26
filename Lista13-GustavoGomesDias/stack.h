#ifndef __stack_h__
#define __stack_h__
#include "cell.h"

typedef struct stack Stack;

Stack *create_stack(int len);

void push(Stack *stk, void *info, void (*print)());

void pop(Stack *stk);

void peek(Stack *stk);

void calc(Stack *stk);

void free_stack(Stack *stk);

#endif