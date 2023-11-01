#!/usr/bin/env python3

''' Sorting Cards '''

from dataclasses import dataclass
import sys

import priority_queue

# Constants

RANKS = {
    'J': 11,
    'Q': 12,
    'K': 13,
    'A': 14,
}

# Classes

@dataclass
class Card:
    rank: str
    suit: str

    @property
    def key(self):
        return (RANKS.get(self.rank) or int(self.rank), self.suit)

    def __lt__(self, other):
        return self.key < other.key

# Main Execution

def main(stream=sys.stdin):
    cards = priority_queue.PriorityQueueBH(key=lambda c: c.key)

    for line in stream:
        rank, suit = line.split()
        cards.push(Card(rank, suit))

    while cards:
        print(cards.pop())

if __name__ == '__main__':
    main()
