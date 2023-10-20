#!/usr/bin/env python3

from dataclasses import dataclass

# Class

@dataclass
class Counter:
    data: int = 0

    def increment(self, n: int=1) -> None:
        self.data += n

    @property
    def count(self) -> int:
        return self.data

    def __str__(self) -> str:
        return f'Counter({self.data})'

# Main Execution

c1 = Counter()
c2 = Counter(10)

c1.increment()
c2.increment()

print(c1.count)
print(c1)
print(c2.count)
print(c2)
