#include <stdio.h>
#include <stdlib.h>
#include "multiQueue.h"

struct multiQueue {
    Queue **queue;
    int size;
    int d;
};

multiQueue *create_multi(int d){
    int i;
    multiQueue *new = (multiQueue *) malloc(sizeof(multiQueue));
    new->d = d;
    new->size = 0;
    new->queue = malloc(sizeof(Queue *) * (d));
    for(i = 0; i < d; i++){
        new->queue[0] = NULL;
    }

    return new;
}


void insert(multiQueue *multi, Queue *queue){
    if(multi->queue[0] == NULL){
        multi->queue[0] = queue;
        multi->size = size(queue);
    }
    else{
        int i = 0;
        while(multi->queue[i] != NULL){
            i++;
        }
        multi->queue[i] = queue;
        multi->size += size(queue);
    }
}

void print_multi(multiQueue *multi, int pos){
    print(multi->queue[pos]);
}


void free_multi(multiQueue *multi){
    int i;
    while(i <= multi->d){
        free_queue(multi->queue[i]);
        i++;
    }
    free(multi->queue);
    free(multi);
}