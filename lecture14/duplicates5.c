/* duplicates5.c: bitset version */

#include "bitset.h"
#include "library.h"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

/* Constants */

#define BITS (sizeof(Bitset)*8)

/* Functions */

bool has_duplicates(int *array, size_t n) {
    Bitset  *bs = calloc(n*n/BITS, sizeof(Bitset));
    bool result = false;

    for (size_t i = 0; i < n; i++) {
    	size_t bs_index = array[i] / BITS;
    	size_t bs_value = array[i] % BITS;
    	if (bitset_contains(&bs[bs_index], bs_value)) {
    	    result = true;
	    goto finish;
	}

    	bitset_add(&bs[bs_index], bs_value);
    }

finish:
    free(bs);
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
