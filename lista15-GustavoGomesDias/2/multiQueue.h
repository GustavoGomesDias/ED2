#ifndef __muiltiQueue_h__
#define __muiltiQueue_h__
#include "cell.h"
#include "queue.h"

typedef struct multiQueue multiQueue;

multiQueue *create_multi(int d);


void insert(multiQueue *multi, Queue *queue);

void print_multi(multiQueue *multi, int pos);

void free_multi(multiQueue *multi);

#endif