/* Lecture 10: Linked List */

#include "list.h"

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

/* List Structure */

void	list_push(List *l, int value) {
    l->head = node_create(value, l->head);
}

int	list_pop(List *l) {
    Node *n = l->head;
    l->head = l->head->next;

    int value = n->data;
    node_delete(n, false);
    return value;
}

ssize_t	list_index(List *l, int value) {
    ssize_t index = 0;
    for (Node *curr = l->head; curr; curr = curr->next) {
    	if (curr->data == value)
    	    return index;
    	index++;
    }
    return -1;
}

int	list_at(List *l, size_t index) {
    size_t cindex = 0;
    Node  *curr   = l->head;

    while (curr && cindex != index) {
    	curr = curr->next;
    	cindex++;
    }

    return (curr && cindex == index) ? curr->data : -1;
}
