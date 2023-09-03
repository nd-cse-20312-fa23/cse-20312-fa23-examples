/* Lecture 11: Deque */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    int   data;	    // Value associated with Node
    Node *next;	    // Pointer to next Node in Deque
    Node *prev;	    // Pointer to previous Node in Deque
};

Node *	node_create(int data, Node *next, Node *prev);
void	node_delete(Node *n, bool recursive);

/* Deque Structure */

typedef struct {
    Node *head;	    // Pointer to first Node in Deque
    Node *tail;	    // Pointer to last Node in Deque
} Deque;

void	deque_push_front(Deque *d, int value);
void	deque_push_back(Deque *d, int value);
int	deque_pop_front(Deque *d);
int	deque_pop_back(Deque *d);

bool	deque_empty(Deque *d);
