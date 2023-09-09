/* Lecture 12 */

#include "array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

#define WHITESPACE " \t\n"

/* Functions */

bool linear_search(Array *array, int target) {
    // Iterate through each item in array and check against target
    for (size_t i = 0; i < array->size; i++)
    	if (array->data[i] == target)
    	    return true;
    return false;
}

bool linear_search_r(Array *array, int target, int index) {
    // Base case: we reach end of array
    if (index >= array->size)
    	return false;

    // Base case: we found target
    if (array->data[index] == target)
	return true;

    // Recursive: check next item
    return linear_search_r(array, target, index + 1);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    char buffer[BUFSIZ];

    while (fgets(buffer, BUFSIZ, stdin)) {
    	Array *numbers = array_create();

	for (char *token = strtok(buffer, WHITESPACE); token; token = strtok(NULL, WHITESPACE)) {
    	    array_append(numbers, atoi(token));
	}

	if (!fgets(buffer, BUFSIZ, stdin)) {
	    break;
	}
	    
	puts(linear_search(numbers, atoi(buffer)) ? "YEAH" : "NOPE");
	puts(linear_search_r(numbers, atoi(buffer), 0) ? "YEAH" : "NOPE");

	array_delete(numbers);
    }
    return 0;
}
