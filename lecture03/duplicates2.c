/* duplicates2.c: table version */

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "library.h"

/* Functions */

bool has_duplicates(int *array, size_t n) {
    // Time:	O(n)
    // Space:	O(n*n)

    // Demo: malloc(n) -> segfault -> gdb
    bool *seen   = calloc(n*n, sizeof(bool));
    bool  result = false;

    for (size_t i = 0; i < n; i++) {
    	if (seen[array[i]]) {
    	    result = true;
    	    goto finish;
	}
    	seen[array[i]] = true;
    }

    // Demo: forget to do this (valgrind)
finish:
    free(seen);
    return result;
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int numbers[NUMBERS_MAX] = {0};
    srand(time(NULL));
    make_random_array(numbers, NUMBERS_MAX);
    puts(has_duplicates(numbers, NUMBERS_MAX) ? "Yeah" : "Nope");
    return 0;
}
