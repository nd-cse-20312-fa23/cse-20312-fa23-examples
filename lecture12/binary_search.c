/* Lecture 12 */

#include "array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

#define WHITESPACE " \t\n"

/* Functions */

bool binary_search(Array *array, int target) {
    int start = 0;		    // Start of range to search
    int end   = array->size - 1;    // End of range to search

    // Iterate as long as there are numbers in range to search
    while (start <= end) {
    	// Compute midpoint of range
    	int middle   = (start + end) / 2;
    	int midpoint = array->data[middle];

    	// Check if target is found
    	if (midpoint == target)
    	    return true;

	// Adjust range
    	if (midpoint > target)
    	    end   = middle - 1; // Go left
	else
	    start = middle + 1; // Go right
    }

    return false;
}

bool binary_search_r(Array *array, int target, int start, int end) {
    // Base case: no more numbers to search
    if (start > end)
    	return false;

    // Base case: we found target
    int middle   = (start + end) / 2;
    int midpoint = array->data[middle];
    if (midpoint == target)
	return true;

    // Recursive: go left or right
    if (midpoint > target)
	return binary_search_r(array, target, start, middle - 1);
    else
	return binary_search_r(array, target, middle + 1, end);
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
	    
	puts(binary_search(numbers, atoi(buffer)) ? "YEAH" : "NOPE");
	puts(binary_search_r(numbers, atoi(buffer), 0, numbers->size - 1) ? "YEAH" : "NOPE");

	array_delete(numbers);
    }
    return 0;
}
