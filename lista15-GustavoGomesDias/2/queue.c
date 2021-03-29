#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct queue{
    Cell **start;
    Cell **end;
    int tam;
};

Queue *create_queue(){
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->start = malloc(sizeof(Cell *));
    queue->end = malloc(sizeof(Cell *));
    queue->start[0] = NULL;
    queue->end[0] = NULL;
    queue->tam = 0;
    return queue;
}

Queue *enqueue(Queue *queue, int info){
    Cell *new_cell = create_cell();
    set_info(new_cell, info);
    Cell *tmp = queue->start[0];
    if(tmp == NULL){
        queue->start[0] = new_cell;
		queue->end[0] = new_cell;
        queue->tam += 1;
        return queue;
    }
    while (get_next(tmp) != NULL){
        tmp = get_next(tmp);
    }
    set_next(tmp, new_cell);
    queue->end[0] = new_cell;
    queue->tam += 1;
    return queue;
}

void dequeue(Queue *queue){
    Cell *tmp = queue->start[0];
    queue->start[0] = get_next(tmp);
    printf("%d foi retirado.\n", get_info(tmp));
    set_next(tmp, NULL);
    queue->tam -= 1;
}

void print(Queue *queue){
    Cell *tmp = queue->start[0];
    while(tmp != NULL){
        printf("%d ", get_info(tmp));
        tmp = get_next(tmp);
    }
    printf("\n");
}

void peek(Queue *queue){
    Cell *tmp = queue->start[0];
    printf("%d é o primeiro item da fila.", get_info(tmp));
}


void free_queue(Queue *queue){
    Cell *tmp = queue->start[0];
	Cell *aux;
    while(get_next(tmp) != NULL){
        aux = get_next(tmp);
        free_cell(tmp);
        tmp = aux;
    }
    free(queue->start);
    free(queue->end);
    free(queue);
}

int size(Queue *queue){
    return queue->tam;
}