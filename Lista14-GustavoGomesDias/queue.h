#ifndef __queue_h__
#define __queue_h__
#include "cell.h"

typedef struct queue Queue;

Queue *create_queue();

Queue *enqueue(Queue *queue, int info);

void dequeue(Queue *queue);

void print(Queue *queue);

void peek(Queue *queue);


#endif