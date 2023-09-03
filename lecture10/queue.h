/* Lecture 10: Queue */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    int   data;	    // Value associated with Node
    Node *next;	    // Pointer to next Node in Queue
};

Node *	node_create(int data, Node *next);
void	node_delete(Node *n, bool recursive);

/* Queue Structure */

typedef struct {
    Node *head;	    // Pointer to first Node in Queue
    Node *tail;	    // Pointer to last Node in Queue
} Queue;

void	queue_push(Queue *q, int value);
int	queue_pop(Queue *q);

int	queue_front(Queue *q);
bool	queue_empty(Queue *q);
