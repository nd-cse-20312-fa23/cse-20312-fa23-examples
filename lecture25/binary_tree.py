#!/usr/bin/env python3

''' binary_tree.py

This demonstrates two different ways to represent binary trees.
'''

# Linked Node Representation

from dataclasses import dataclass

@dataclass
class Node:
    value:  str
    left:   'Node' = None
    right:  'Node' = None

tree = Node('B', Node('I', Node('A'), Node('R')), Node('N', Node('Y')))

print('# Linked')
print(tree)
print(tree.value)
print(tree.left.value)
print(tree.left.right.value)

print()

# Array Based Representation

def left_child(index):
    return 2*index + 1

def right_child(index):
    return 2*index + 2

tree = 'BINARY'

print('# Array')
print(tree)
print(tree[0])
print(tree[left_child(0)])
print(tree[right_child(left_child(0))])
