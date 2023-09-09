/* Lecture 13: Set */

#include "search.h"
#include "set.h"

#include <stdio.h>
#include <string.h>

/* Functions */

void	set_add(Set *s, int value) {
    // Check if value is in set (skip if found to maintain uniqueness)
    if (set_contains(s, value))
    	return;

    // Search for insertion location
    size_t index;
    for (index = 0; index < s->size && s->data[index] < value; index++) {}

    // Insert into array
    array_insert(s, index, value);
}

bool	set_contains(Set *s, int value) {
    // Use binary search to determine if value is in the set
    return binary_search(s, value);
}

bool	set_empty(Set *s) {
    return s->size == 0;
}

void	set_dump(Set *s) {
    for (size_t i = 0; i < s->size; i++)
    	printf("%d\n", s->data[i]);
}
