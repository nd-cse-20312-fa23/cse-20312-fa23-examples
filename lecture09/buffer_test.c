/* Lecture 09: Circular Buffer */

#include "buffer.h"

#include <assert.h>
#include <stdio.h>

/* Main Execution */

int main(int argc, char *argv[]) {
    // Create buffer
    Buffer *buffer = buffer_create(1<<2);
    assert(buffer);

    // Push values into buffer
    buffer_push(buffer, 1);
    buffer_push(buffer, 2);
    buffer_push(buffer, 3);
    buffer_push(buffer, 4);

    // Pop values from buffer
    while (!buffer_empty(buffer)) {
    	printf("%d\n", buffer_pop(buffer));
    }

    // Delete buffer
    buffer_delete(buffer);
    return 0;
}
