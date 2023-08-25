/* Lecture 07: Dynamic Array */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure */

typedef struct {
    int	    *data;
    size_t   size;
    size_t   capacity;
} Array;

/* Constants */

const size_t ARRAY_DEFAULT_CAPACITY = 1<<2;

/* Functions */

Array*	array_create() {
    // Allocate Array structure
    Array *array = malloc(sizeof(Array));	

    // Initialize Array attributes
    if (array) {					
    	array->capacity = ARRAY_DEFAULT_CAPACITY;
    	array->size     = 0;
    	array->data	= calloc(array->capacity, sizeof(int));
    	if (!array->data) {
    	    free(array);
    	    return NULL;
	}
    }

    return array;
}

void	array_delete(Array *array) {
    // Release internal allocations
    free(array->data);
    // Release Array structure
    free(array);
}

void	array_append(Array *array, int value) {
    // Resize if necessary
    if (array->size == array->capacity) {
    	array->capacity *= 2;	// Double the capacity
    	array->data      = realloc(array->data, array->capacity*sizeof(int));
    }

    // Store value at end of array
    array->data[array->size] = value;
    array->size++;
}

int	array_at(Array *array, size_t index) {
    // Make sure we only access valid elements
    assert(index < array->size);
    return array->data[index];
}

ssize_t	array_index(Array *array, int value) {
    // Scan internal array for first element that matches value            
    for (size_t index = 0; index < array->size; index++)
    	if (array->data[index] == value)
    	    return index;

    return -1;
}

void	array_remove(Array *array, size_t index) {
    // Make sure we only access valid elements
    assert(index < array->size);
    // Compute how many bytes we need to shift (ie. # of elements x size of each element)
    size_t bytes = (array->size - index - 1)*sizeof(int);
    // Move elements after index forward (over current element)
    memmove(array->data + index, array->data + index + 1, bytes);
    array->size--;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    // Create Array
    Array* array = array_create();
    
    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);

    // Append to Array
    array_append(array, 4);
    array_append(array, 6);
    array_append(array, 5);
    array_append(array, 5);
    array_append(array, 6);

    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);

    // Access elements in Array
    for (size_t i = 0; i < array->size; i++) {
    	printf("array[%lu] = %d\n", i, array_at(array, i));
    }

    // Search for elements in Array
    printf("array_index(4) = %ld\n", array_index(array, 4));
    printf("array_index(5) = %ld\n", array_index(array, 5));
    printf("array_index(6) = %ld\n", array_index(array, 6));
    printf("array_index(7) = %ld\n", array_index(array, 7));

    // Remove elements from Array
    array_remove(array, 1);
    array_remove(array, 2);
    
    printf("array->size     = %lu\n", array->size);
    printf("array->capacity = %lu\n", array->capacity);
    
    for (size_t i = 0; i < array->size; i++) {
    	printf("array[%lu] = %d\n", i, array_at(array, i));
    }

    array_delete(array);
    return 0;
}
