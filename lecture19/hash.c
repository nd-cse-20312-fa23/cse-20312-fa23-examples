/* hash.c: Hash Function */

#include "hash.h"

#include <stdint.h>

/* Functions */

size_t	hash(const void *s, size_t n) {
    // Very bad and dumb hash: add up characters and then use Knuth's
    // multiplicative hash
    
    uint32_t value = 0;
    uint8_t *bytes = (uint8_t *)s;

    for (size_t b = 0; b < n; b++) {
    	value += bytes[b];
    }

    return value * 2654435761;
}
