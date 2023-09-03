/* Lecture 09: Linked List */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Node Structure */

typedef struct Node Node;
struct Node {
    int   data;	    // Value associated with Node
    Node *next;	    // Pointer to next Node in List
};

Node *	node_create(int data, Node *next);
void	node_delete(Node *n, bool recursive);

/* List Structure */

typedef struct {
    Node *head;	    // Pointer to first Node in List
} List;

void	list_push(List *l, int value);
int	list_pop(List *l);

ssize_t	list_index(List *l, int value);
int	list_at(List *l, size_t index);
