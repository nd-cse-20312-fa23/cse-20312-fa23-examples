/* pair.h: Pair Structure */

#pragma once

/* Structure */

typedef struct Pair Pair;
struct Pair {
    int	  key;
    int   value;
    Pair *next;
};

/* Functions */

Pair *	pair_create(int key, int value, Pair *next);
void	pair_delete(Pair *p);
