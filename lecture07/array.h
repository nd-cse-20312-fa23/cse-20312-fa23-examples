/* Lecture 07: Dynamic Array */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

/* Structure */

typedef struct {
    int	    *data;	// Internal array
    size_t   size;	// Number of valid elements
    size_t   capacity;	// Total number of elements
} Array;

/* Functions */

Array*	array_create();
void	array_delete(Array *array);
void	array_append(Array *array, int value);
int	array_at(Array *array, size_t index);
ssize_t	array_index(Array *array, int value);
void	array_remove(Array *array, size_t index);
