#!/usr/bin/env python3

# Classes

from dataclasses import dataclass

@dataclass
class Node:
    value:  str
    left:   'Node' = None
    right:  'Node' = None

# Functions

def tree_values1(root: Node) -> list[Node]:
    if not root:
        return []

    return (
        tree_values1(root.left) + [root.value] + tree_values1(root.right)
    )

def tree_values2(root: Node) -> list[Node]:
    if not root:
        return
    
    yield from tree_values2(root.left)
    yield root.value
    yield from tree_values2(root.right)

# Main Execution

def main():
    tree = Node('V',
        Node('A', Node('P'), Node('R')),
        Node('M', Node('I'), Node('E'))
    )

    for value in tree_values1(tree):
        print(value)

    print()
    
    for value in tree_values2(tree):
        print(value)

if __name__ == '__main__':
    main()
