/* table.h: Hash Table */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/* Constants */

#define TABLE_DEFAULT_CAPACITY	(1<<2)

/* Structures */

typedef struct {
    int    *buckets;
    size_t  capacity;
    size_t  size;
} Table;

/* Functions */

Table *	    table_create();
void	    table_delete(Table *t);

uint32_t    hash(int value);

void	    table_insert(Table *t, int value);
bool	    table_search(Table *t, int value);

void	    table_format(Table *t);
ssize_t	    table_locate(Table *t, int value);

