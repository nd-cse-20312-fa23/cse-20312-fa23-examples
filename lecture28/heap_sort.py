#!/usr/bin/env python3

''' heap_sort.py

Heap Sort implementation using heapq.
'''

import heapq
import sys

# Functions

def heap_sort(data: list) -> list:
    ''' Order the items in data by using a binary heap to perform heap sort.

    Time:  O(nlogn)
    Space: O(n)

    >>> heap_sort([3, 0, 0, 6, 2])
    [0, 0, 2, 3, 6]
    '''
    # Convert list into a heap
    heap = data[:]                  # Create copy
    heapq.heapify(heap)

    # Repeatedly remove smallest value and add to resulting list
    ordered = []
    while heap:
        value = heapq.heappop(heap)
        ordered.append(value)

    return ordered
    
# Main Execution

def main(stream=sys.stdin) -> None:
    ''' Sort the words in each line of input.

    >>> import io
    >>> main(io.StringIO('3 0 0 6 2'))
    [0, 0, 2, 3, 6]
    '''
    for line in stream:
        strs = line.split()         # Split words in line into individual strings
        ints = list(map(int, strs)) # Convert each individual strings into ints

        print(heap_sort(ints))

if __name__ == '__main__':
    main()
