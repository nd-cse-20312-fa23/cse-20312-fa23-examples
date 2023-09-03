/* Lecture 11: Deque */

#include "deque.h"

#include <stdio.h>
#include <stdlib.h>

/* Constants */

const int DATA[] = {5, 4, 7, 0, 1, -1};

/* Main Execution */

int main(int argc, char *argv[]) {
    Deque d = {0};
    
    puts("Stack (Front)"); {
    	for (const int *i = DATA; *i >= 0; i++) {
	    deque_push_front(&d, *i);
	}

	while (!deque_empty(&d)) {
	    printf("deque_pop() = %d\n", deque_pop_front(&d));
	}
    } puts("");
    
    puts("Stack (Back)"); {
    	for (const int *i = DATA; *i >= 0; i++) {
	    deque_push_back(&d, *i);
	}

	while (!deque_empty(&d)) {
	    printf("deque_pop() = %d\n", deque_pop_back(&d));
	}
    } puts("");
    
    puts("Queue (Back -> Front)"); {
    	for (const int *i = DATA; *i >= 0; i++) {
	    deque_push_back(&d, *i);
	}

	while (!deque_empty(&d)) {
	    printf("deque_pop() = %d\n", deque_pop_front(&d));
	}
    } puts("");
    
    puts("Queue (Front -> Back)"); {
    	for (const int *i = DATA; *i >= 0; i++) {
	    deque_push_front(&d, *i);
	}

	while (!deque_empty(&d)) {
	    printf("deque_pop() = %d\n", deque_pop_back(&d));
	}
    } puts("");
    
    node_delete(d.head, true);
    return 0;
}
