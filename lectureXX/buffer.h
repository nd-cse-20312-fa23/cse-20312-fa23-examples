/* Lecture 09: Circular Buffer */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Structures */

typedef struct {
    int	    *data;	// Internal array
    size_t   capacity;  // Total number of elements
    size_t   size;	// Number of valid elements
    			
    size_t   head;	// Pointer to front of buffer (read)
    size_t   tail;	// Pointer to back of buffer (write)
} Buffer;

/* Functions */

Buffer*	buffer_create(size_t capacity);
void	buffer_delete(Buffer *buffer);

void	buffer_push(Buffer *buffer, int value);
int	buffer_pop(Buffer *buffer);
bool	buffer_empty(Buffer *buffer);
