/* Lecture 10: Queue */

#include "queue.h"

/* Node Structure */

Node *	node_create(int data, Node *next) {
    Node *n = malloc(sizeof(Node));
    if (n) {
    	n->data = data;
    	n->next = next;
    }
    return n;
}

void	node_delete(Node *n, bool recursive) {
    if (!n) {
    	return;
    }

    if (recursive) {
	node_delete(n->next, recursive);
    }
    free(n);
}

/* Queue Structure */

void	queue_push(Queue *q, int value) {
    Node *n = node_create(value, NULL);
    if (!q->tail) {
    	q->head = n;
    } else {
    	q->tail->next = n;
    }
    
    q->tail = n;
}

int	queue_pop(Queue *q) {
    Node *n = q->head;
    q->head = q->head->next;

    if (q->tail == n) {
    	q->tail = NULL;
    }

    int value = n->data;
    node_delete(n, false);
    return value;
}

int	queue_front(Queue *q) {
    return (q->head) ? q->head->data : -1;
}

bool	queue_empty(Queue *q) {
    return q->head == NULL;
}
