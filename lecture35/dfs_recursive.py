#!/usr/bin/env python3

''' dfs_recursive.py 

Perform a DFS traversal of graph using recursion.
'''

from collections import defaultdict
import sys

# Functions

def read_graph(stream=sys.stdin):
    graph = defaultdict(list)

    for line in stream:
        source, target = map(int, line.split())
        graph[source].append(target)

    return graph

def dfs(graph, vertex, visited):
    # Base Case: Already visited
    if vertex in visited:
        return

    # Mark as visited
    visited.add(vertex)

    # Process vertex
    print(vertex)

    # Recursive case: Visit all neighbors
    for neighbor in graph[vertex]:
        dfs(graph, neighbor, visited)

# Main Execution

def main(stream=sys.stdin):
    graph = read_graph(stream)

    dfs(graph, min(graph.keys()), set())

if __name__ == '__main__':
    main()
