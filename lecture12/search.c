/* Lecture 12 */

#include "search.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

#define WHITESPACE  " \t\n"

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
	
	puts(binary_search(numbers, atoi(buffer)) ? "YEAH" : "NOPE");
	puts(binary_search_r(numbers, atoi(buffer), 0, numbers->size - 1) ? "YEAH" : "NOPE");

	puts("");

	array_delete(numbers);
    }
    return 0;
}
