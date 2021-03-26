#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cell.h"
#include "queue.h"

int main(){
    Queue *queue;
    queue = create_queue();
    queue = enqueue(queue, 1);
    queue = enqueue(queue, 2);
    queue = enqueue(queue, 3);
    queue = enqueue(queue, 4);
    queue = enqueue(queue, 5);
    if(queue == NULL){
        printf("Vazia!");
    }
    print(queue);
    dequeue(queue);
    print(queue);

    return 0;
}