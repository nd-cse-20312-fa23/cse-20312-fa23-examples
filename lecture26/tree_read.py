#!/usr/bin/env python3

''' tree_read.py

Read in tree in BFS format using divide and conquer.

'''

from dataclasses import dataclass
import sys

# Classes

@dataclass
class Node:
    value:  int
    left:   'Node' = None
    right:  'Node' = None

# Functions

def tree_read(array, index=0):
    ''' Use divide and conquer to read binary tree in BFS format '''
    # Base Case: Invalid Node
    if index >= len(array) or not array[index]:
        return None

    # Divide and Conquer and Combine
    return Node(
        value = array[index],
        left  = tree_read(array, 2*index + 1),
        right = tree_read(array, 2*index + 2),
    )

# Main Execution

def main():
    ''' For each line, read the BFS tree and print out the root node '''
    for line in sys.stdin:
        strs = line.split()             # Separate individual strings in line
        ints = [int(s) for s in strs]   # Convert each string into an int and collec into list
        tree = tree_read(ints)

        print(tree)

if __name__ == '__main__':
    main()
