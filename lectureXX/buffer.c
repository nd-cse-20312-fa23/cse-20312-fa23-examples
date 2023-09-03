/* Lecture 09: Circular Buffer */

#include "buffer.h"

/* Functions */

Buffer*	buffer_create(size_t capacity) {
    // Allocate Buffer structure
    Buffer *buffer = calloc(1, sizeof(Buffer));
    // Initialize Buffer attributes
    if (buffer) {
    	buffer->capacity = capacity;
    	buffer->data     = calloc(buffer->capacity, sizeof(int));
    	if (!buffer->data) {
    	    free(buffer);
    	    return NULL;
	}
    }
    return buffer;
}

void	buffer_delete(Buffer *buffer) {
    // Release internal data array
    free(buffer->data);
    // Release Buffer structure
    free(buffer);
}

void	buffer_push(Buffer *buffer, int value) {
    // Store value at tail
    buffer->data[buffer->tail] = value;
    // Advance tail: wrap back to front if necessary
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    // Increment size
    buffer->size++;
}

int	buffer_pop(Buffer *buffer) {
    // Copy value at head
    int value = buffer->data[buffer->head];
    // Advance head: wrap back to front if necessary
    buffer->head = (buffer->head + 1) % buffer->capacity;
    // Decrement size
    buffer->size--;
    // Return copied value
    return value;
}

bool	buffer_empty(Buffer *buffer) {
    return buffer->size == 0;
}
