#!/usr/bin/env python3

''' mst.py

Example of Dijkstra's algorithm and Prim's algorithm.
'''

import collections
import heapq
import sys

# Types

Graph = dict[str, dict[str, int]]

# Build Graph

def read_graph() -> Graph:
    graph: Graph = collections.defaultdict(dict)
    for line in sys.stdin:
        source, target, weight = line.split()
        graph[source][target] = int(weight)
        graph[target][source] = int(weight)
    return graph

# Compute SSSP

def compute_sssp(graph: Graph, start: str) -> dict[str, str]:
    frontier = [(0, start, start)]
    visited  = {}

    while frontier:
        distance, target, source = heapq.heappop(frontier)

        if target in visited:
            continue

        visited[target] = source

        for neighbor, weight in graph[target].items():
            heapq.heappush(frontier, (distance + weight, neighbor, target))

    return visited

def reconstruct_path(visited: dict[str, str], source: str, target: str) -> list[str]:
    path = []
    curr = target

    while curr != source:
        path.append(curr)
        curr = visited[curr]

    path.append(source)
    return path[::-1]

# Compute MST

def compute_mst(graph: Graph, start: str) -> dict[str, str]:
    frontier = [(0, start, start)]
    visited  = {}

    while frontier:
        weight, target, source = heapq.heappop(frontier)

        if target in visited:
            continue

        visited[target] = source

        for neighbor, weight in graph[target].items():
            heapq.heappush(frontier, (weight, neighbor, target))

    return visited

# Main Execution

def main() -> None:
    graph = read_graph()
    start = min(graph.keys())

    # SSSP
    sssp  = compute_sssp(graph, start)
    print('SSSP')
    for target in sorted(graph.keys())[1:]:
        path = reconstruct_path(sssp, start, target)
        print(f'{start} -> {target} = {" ".join(path)}')

    # MST
    mst   = compute_mst(graph, start)
    edges = sorted((min(s, t), max(s, t)) for s, t in mst.items() if s != t)

    print('MST')
    print(sum(graph[s][t] for s, t in edges))
    for source, target in edges:
        print(source, target)

if __name__ == '__main__':
    main()
