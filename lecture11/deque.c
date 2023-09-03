/* Lecture 11: Deque */

#include "deque.h"

/* Node Structure */

Node *	node_create(int data, Node *next, Node *prev) {
    Node *n = malloc(sizeof(Node));
    if (n) {
    	n->data = data;
    	n->next = next;
    	n->prev = prev;
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

/* Deque Structure */

void	deque_push_front(Deque *d, int value) {
    Node *n = node_create(value, d->head, NULL);
    if (!d->head) {
    	d->tail = n;
    } else {
    	d->head->prev = n;
    }
    	
    d->head = n;
}

void	deque_push_back(Deque *d, int value) {
    Node *n = node_create(value, NULL, d->tail);
    if (!d->head) {
    	d->head = n;
    } else {
    	d->tail->next = n;
    }
    
    d->tail = n;
}

int	deque_pop_front(Deque *d) {
    Node *n = d->head;
    d->head = d->head->next;

    if (d->head) {
    	d->head->prev = NULL;
    }

    if (d->tail == n) {
    	d->tail = NULL;
    }

    int value = n->data;
    node_delete(n, false);
    return value;
}

int	deque_pop_back(Deque *d) {
    Node *n = d->tail;
    d->tail = d->tail->prev;

    if (d->tail) {
    	d->tail->next = NULL;
    }

    if (d->head == n) {
    	d->head = NULL;
    }

    int value = n->data;
    node_delete(n, false);
    return value;
}

bool	deque_empty(Deque *d) {
    return d->head == NULL;
}
