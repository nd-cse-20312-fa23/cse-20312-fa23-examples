#!/usr/bin/env python3

''' sssp.py

Example of Dijkstra's algorithm for single source shortest path.
'''

import collections
import heapq
import sys

# Types

Graph = dict[str, dict[str, int]]

# Build Graph

def read_graph(stream) -> Graph:
    ''' Read in directed graph '''
    graph: Graph = collections.defaultdict(dict)
    for line in sys.stdin:
        source, target, weight = line.split()
        graph[source][target] = int(weight)
    return graph

# Compute SSSP

def compute_sssp(graph: Graph, start: str) -> dict[str, int]:
    ''' Use Dijkstra's Algorithm to compute the single-source shortest path '''
    frontier: list[tuple[int, str]] = []
    visited:  dict[str, int]        = {}

    heapq.heappush(frontier, (0, start))

    while frontier:
        distance, vertex = heapq.heappop(frontier)

        if vertex in visited:
            continue

        visited[vertex] = distance

        for neighbor, weight in graph[vertex].items():
            heapq.heappush(frontier, (distance + weight, neighbor))

    return visited

# Main Execution

def main(stream=sys.stdin) -> None:
    # Read Graph
    graph   = read_graph(stream)

    # Compute SSSP
    start   = min(graph.keys())
    visited = compute_sssp(graph, start)

    # Display Distances
    for target in sorted((graph.keys()))[1:]:
        print(f'{start} -> {target} = {visited[target]}')

if __name__ == '__main__':
    main()
