#!/usr/bin/env python3

# Class

class Counter:
    def __init__(self, n=0):
        self.data = n

    def increment(self, n=1):
        self.data += n

    def decrement(self, n=1):
        self.data -= n

    @property
    def count(self):
        return self.data

# Main Execution

c1 = Counter()
c2 = Counter(10)

c1.increment()
c2.decrement()

print(c1.count)
print(c2.count)
