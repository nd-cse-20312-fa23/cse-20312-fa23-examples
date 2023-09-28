/* fibonacci.c */

#include "map.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Functions */

int64_t fibonacci(int64_t n, Map *cache) {
    // Base cases
    if (n == 0) {
    	return 0;
    } else if (n <= 2) {
    	return 1;
    }

    // Recursive
    // return fibonacci(n - 1) + fibonacci(n - 2);

    // Recursive: Memoized
    if (map_lookup(cache, n) < 0) {
    	map_insert(cache, n, fibonacci(n - 1, cache) + fibonacci(n - 2, cache));
    }

    return map_lookup(cache, n);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int64_t n;
    Map *cache = map_create();

    /*
    map_insert(cache, 0, 0);
    map_insert(cache, 1, 1);
    map_insert(cache, 2, 1);
    */

    while (scanf("%ld", &n) != EOF) {
    	printf("fibonacci(%ld) = %ld\n", n, fibonacci(n, cache));
    }

    map_delete(cache);
    return 0;
}
