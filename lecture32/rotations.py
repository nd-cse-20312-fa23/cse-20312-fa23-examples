#!/usr/bin/env python3

''' rotations.py

Demonstrate rotating binary trees.
'''

from dataclasses import dataclass
from typing      import Optional

# Classes

@dataclass
class Node:
    value:  int
    left:   Optional['Node'] = None
    right:  Optional['Node'] = None

# Functions

def rotate_right(p):
    ''' Rotate the sub-tree at parent node to the right.

        P               CL
       / \             /  \
      CL CR     =>    GL   P
     /  \                 / \
    GL  GR              GR   CR

    >>> tree = Node('A', left=Node('B'), right=Node('C'))
    >>> rotate_right(tree)
    Node(value='B', left=None, right=Node(value='A', left=None, right=Node(value='C', left=None, right=None)))

    >>> tree = Node('A', left=Node('B', left=Node('C'), right=Node('D')), right=Node('E'))
    >>> rotate_right(tree)
    Node(value='B', left=Node(value='C', left=None, right=None), right=Node(value='A', left=Node(value='D', left=None, right=None), right=Node(value='E', left=None, right=None)))
    '''
    cl, gr   = p.left, p.left.right
    cl.right = p
    p.left   = gr
    return cl

def rotate_left(p):
    ''' Rotate the sub-tree at parent node to the left.

        P               CR
       / \             /  \
      CL CR     =>    P   GR
     /  \            / \
    GL  GR          CL  GL

    >>> tree = Node('A', left=Node('B'), right=Node('C'))
    >>> rotate_left(tree)
    Node(value='C', left=Node(value='A', left=Node(value='B', left=None, right=None), right=None), right=None)

    >>> tree = Node('A', left=Node('B'), right=Node('C', left=Node('D'), right=Node('E')))
    >>> rotate_left(tree)
    Node(value='C', left=Node(value='A', left=Node(value='B', left=None, right=None), right=Node(value='D', left=None, right=None)), right=Node(value='E', left=None, right=None))
    '''
    cr, gl  = p.right, p.right.left
    cr.left = p
    p.right = gl
    return cr
