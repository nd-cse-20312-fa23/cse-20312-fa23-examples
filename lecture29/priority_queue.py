#!/usr/bin/env python3

''' Priority Queue

Multiple implementations of a Priority Queue (Minimum)
'''

from heapq import heapify, heappush, heappop

# Classes

class PriorityQueueSA:

    def __init__(self, data=None, key=None):
        ''' Construct and initialize Priority Queue with internal sorted array

        >>> pq = PriorityQueueSA()
        >>> pq.data
        []
        >>> pq.key(1)
        1

        >>> pq = PriorityQueueSA([1, 2, 3])
        >>> pq.data
        [3, 2, 1]
        >>> pq.key(1)
        1

        >>> pq = PriorityQueueSA([1, 2, 3], lambda x: -x)
        >>> pq.data
        [1, 2, 3]
        >>> pq.key(1)
        -1
        '''
        self.key  = key if key else lambda x: x
        self.data = sorted(data, key=self.key, reverse=True) if data else []

    def push(self, value):
        ''' Add value to Priority Queue

        >>> pq = PriorityQueueSA([1, 2, 3])
        >>> pq.push(4)
        >>> pq.data
        [4, 3, 2, 1]

        >>> pq = PriorityQueueSA([1, 2, 3], lambda x: -x)
        >>> pq.push(4)
        >>> pq.data
        [1, 2, 3, 4]
        '''
        self.data.append(value)
        self.data.sort(key=self.key, reverse=True)

    def pop(self):
        ''' Return maximum value in Priority Queue

        >>> pq = PriorityQueueSA([1, 2, 3])
        >>> pq.pop()
        1

        >>> pq = PriorityQueueSA([1, 2, 3], lambda x: -x)
        >>> pq.pop()
        3
        '''
        return self.data.pop()

    def __len__(self):
        ''' Return number of values in Priority Queue

        >>> len(PriorityQueueSA())
        0

        >>> len(PriorityQueueSA([3, 2, 1]))
        3
        '''
        return len(self.data)

class PriorityQueueBH:

    def __init__(self, data=None, key=None):
        ''' Construct and initialize Priority Queue with internal sorted array

        >>> pq = PriorityQueueBH()
        >>> pq.data
        []
        >>> pq.key(1)
        1

        >>> pq = PriorityQueueBH([1, 2, 3])
        >>> pq.data
        [(1, 1), (2, 2), (3, 3)]
        >>> pq.key(1)
        1

        >>> pq = PriorityQueueBH([1, 2, 3], lambda x: -x)
        >>> pq.data
        [(-3, 3), (-2, 2), (-1, 1)]
        >>> pq.key(1)
        -1
        '''
        self.key  = key if key else lambda x: x
        self.data = [(self.key(x), x) for x in (data or [])]
        heapify(self.data)

    def push(self, value):
        ''' Add value to Priority Queue

        >>> pq = PriorityQueueBH([1, 2, 3])
        >>> pq.push(4)
        >>> pq.data
        [(1, 1), (2, 2), (3, 3), (4, 4)]

        >>> pq = PriorityQueueBH([1, 2, 3], lambda x: -x)
        >>> pq.push(4)
        >>> pq.data
        [(-4, 4), (-3, 3), (-1, 1), (-2, 2)]
        '''
        heappush(self.data, (self.key(value), value))

    def pop(self):
        ''' Return number of values in Priority Queue

        >>> pq = PriorityQueueBH([1, 2, 3])
        >>> pq.pop()
        1

        >>> pq = PriorityQueueBH([1, 2, 3], lambda x: -x)
        >>> pq.pop()
        3
        '''
        return heappop(self.data)[1]

    def __len__(self):
        ''' Return number of values in Priority Queue

        >>> len(PriorityQueueBH())
        0

        >>> len(PriorityQueueBH([1, 2, 3]))
        3
        '''
        return len(self.data)
