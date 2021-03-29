#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cell.h"
#include "queue.h"
#include "multiqueue.h"

int main(){
    Queue *queue;
    queue = create_queue();
    queue = enqueue(queue, 1);
    queue = enqueue(queue, 2);
    queue = enqueue(queue, 3);
    queue = enqueue(queue, 4);
    queue = enqueue(queue, 5);
    
    Queue *queue2;
    queue2 = create_queue();
    queue2 = enqueue(queue2, 6);
    queue2 = enqueue(queue2, 7);
    queue2 = enqueue(queue2, 8);
    queue2 = enqueue(queue2, 9);
    queue2 = enqueue(queue2, 10);
    
    Queue *queue3;
    queue3 = create_queue();
    queue3 = enqueue(queue3, 11);
    queue3 = enqueue(queue3, 12);
    queue3 = enqueue(queue3, 13);
    queue3 = enqueue(queue3, 14);
    queue3 = enqueue(queue3, 15);
    
    multiQueue *multi = create_multi(3);
    insert(multi, queue);
    insert(multi, queue2);
    insert(multi, queue3);
    
    print_multi(multi, 0);
    print_multi(multi, 1);
    print_multi(multi, 2);

    return 0;
}