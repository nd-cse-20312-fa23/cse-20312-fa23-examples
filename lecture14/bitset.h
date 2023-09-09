/* Lecture 14: Bitsets */

#pragma once

#include <stdbool.h>
#include <stdint.h>

/* Type Definitions */

typedef uint64_t    Bitset;

/* Functions */

void	bitset_add(Bitset *b, int value);
bool	bitset_contains(Bitset *b, int value);
void	bitset_remove(Bitset *b, int value);
