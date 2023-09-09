/* Lecture 13: Set (Dynamic Array) */

#pragma once

#include "array.h"

#include <stdbool.h>
#include <stdlib.h>

/* Structures */

typedef Array Set;

/* Macros */

#define set_create()	array_create()
#define set_delete(s)	array_delete(s)

/* Functions */

void	set_add(Set *s, int value);
bool	set_contains(Set *s, int value);
void	set_dump(Set *s);
