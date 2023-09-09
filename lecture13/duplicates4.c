/* duplicates4.c: set version */

#include "set.h"
#include "library.h"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/* Functions */

bool has_duplicates(int *array, size_t n) {
    // Time:	O(n*n)
    // Space:	O(n)
    Set      *s = set_create();
    bool result = false;

    for (size_t i = 0; i < n; i++) {
    	if (set_contains(s, array[i])) {
    	    result = true;
	    goto finish;
	}

	set_add(s, array[i]);
    }

finish:
    set_delete(s);
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
