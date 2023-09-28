/* hash.c: Hash Function */

#include "hash.h"

/* Functions */

uint32_t    hash(int value) {
    return value * 2654435761;
}
