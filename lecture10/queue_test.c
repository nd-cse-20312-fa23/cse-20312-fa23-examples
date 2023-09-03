/* Lecture 10: Queue */

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    Queue q = {0};
    
    printf("queue_empty() = %d\n", queue_empty(&q));

    queue_push(&q, 5);
    printf("queue_front() = %d\n", queue_front(&q));
    queue_push(&q, 7);
    printf("queue_front() = %d\n", queue_front(&q));
    queue_push(&q, 4);
    printf("queue_front() = %d\n", queue_front(&q));

    printf("queue_empty() = %d\n", queue_empty(&q));

    while (!queue_empty(&q)) {
    	puts("");
    	printf("queue_pop()   = %d\n", queue_pop(&q));
	printf("queue_front() = %d\n", queue_front(&q));
    }
    
    queue_push(&q, 9);
    queue_push(&q, 1);
    queue_push(&q, 5);
    
    while (!queue_empty(&q)) {
    	puts("");
    	printf("queue_pop()   = %d\n", queue_pop(&q));
	printf("queue_front() = %d\n", queue_front(&q));
    }

    node_delete(q.head, true);
    return 0;
}
