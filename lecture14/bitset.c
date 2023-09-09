/* Lecture 14: Bitsets */

#include "bitset.h"

#include <assert.h>

/* Functions */

void	bitset_add(Bitset *b, int value) {
    assert(value < sizeof(Bitset)*8);
    *b |= (1<<value);
}

bool	bitset_contains(Bitset *b, int value) {
    assert(value < sizeof(Bitset)*8);
    return *b & (1<<value);
}

void	bitset_remove(Bitset *b, int value) {
    assert(value < sizeof(Bitset)*8);
    *b &= ~(1<<value);
}
