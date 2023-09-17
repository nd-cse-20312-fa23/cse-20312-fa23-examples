/* Lecture 15: Utilities */

#pragma once

#include <stdlib.h>

/* Constants */

#define NUMBERS_MAX (1<<16)

/* Functions */

void	swap(int *a, int *b);
void	dump_array(int *a, size_t n);
void	make_random_array(int *array, size_t n);
