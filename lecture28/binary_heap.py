#!/usr/bin/env python3

''' binary_heap.py

This demonstrates using Python's built-in binary heap module: heapq.
'''

import heapq

heap = [5, 7, 4]

heapq.heapify(heap)
print(heap)

heapq.heappush(heap, 6)
print(heap)

print(heapq.heappop(heap))
print(heap)
