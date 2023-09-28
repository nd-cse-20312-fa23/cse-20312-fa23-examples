/* integer.c */

#include "map.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Macros */

#define min(a, b)   (((a) < (b)) ? (a) : (b))

/* Functions */

int64_t count_operations(int64_t n, Map *cache) {
    // Base case: found
    if (n == 1) return 0;

    // Recursive: use rules
    /*
    if (n % 2)
	return min(count_operations(n - 1, cache), count_operations(n + 1, cache)) + 1;
    else
    	return count_operations(n / 2, cache) + 1;
    */

    // Recursive: memoization
    if (map_lookup(cache, n) < 0) {
    	size_t count = 1;
	if (n % 2)
	    count += min(count_operations(n - 1, cache), count_operations(n + 1, cache));
	else
	    count += count_operations(n / 2, cache);
	map_insert(cache, n, count);
    } 
    return map_lookup(cache, n);
}

/* Main Execution */

int main(int argc, char *argv[]) {
    int64_t n;
    Map *cache = map_create();

    while (scanf("%ld", &n) != EOF) {
    	printf("count_operations(%ld) = %ld\n", n, count_operations(n, cache));
    }

    map_delete(cache);
    return 0;
}
