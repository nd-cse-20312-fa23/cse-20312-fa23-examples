#!/usr/bin/env python3

from dataclasses import dataclass

# Class

@dataclass
class Counter:
    data: int = 0

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
