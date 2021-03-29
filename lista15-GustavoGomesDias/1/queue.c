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

    while(get_next(tmp) != NULL && info > get_info(tmp)){
        tmp = get_next(tmp);
    }
    
    if(get_info(tmp) == get_info(queue->start[0])){
        // new_cell <-> tmp <-> next_tmp
        if(info > get_info(tmp)){
            set_next(tmp, new_cell);
            set_prev(new_cell, tmp); 
            queue->end[0] = new_cell;
        }else{
            set_next(new_cell, tmp);
            set_prev(tmp, new_cell);
            queue->start[0] = new_cell;
        }
    }else{
        if(get_info(tmp) == get_info(queue->end[0]) && info > get_info(tmp)){
            set_next(tmp, new_cell);
            set_prev(new_cell, tmp);    
            queue->end[0] = new_cell;
        }else{
            // prev_tmp <-> new_cell <-> tmp 
            set_next(get_prev(tmp), new_cell);
            set_next(new_cell, tmp);
            set_prev(new_cell, get_prev(tmp));
            set_prev(tmp, new_cell);
        }
    }
    queue->tam += 1;
    return queue;
}

void dequeue(Queue *queue){
    Cell *tmp = queue->start[0];
    queue->start[0] = get_next(tmp);
    printf("%d foi retirado.\n", get_info(tmp));
    set_next(tmp, NULL);
    set_prev(queue->start[0], NULL);
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

void size(Queue *queue){
    printf("O tamanho da fila é %d.", queue->tam);
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