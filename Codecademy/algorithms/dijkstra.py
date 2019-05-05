'''
Dijkstra's Algorithms
* shortest distance between vertices
* finding the optimal route to a destination or transferring data in a computer network

1. instantiate a dictionary that will eventually map vertices to their distance from the start vertex
2. assign the start vertex a distance of 0 in a min heap
3. assign every other vertex a distance of infinity in a min heap
4. remove the vertex with the smallest distance from the min heap and set that to the current vertex
5. for the current vertex, consider all of its adjacent vertices and calculate the distance to them as (dsit to the current vertex) + (edge weight of current vertex to adjacent vertex)
6. if this new distance is less than the current distance, replace the current distance
7. repeat 4 and 5 until the heap is empty
8. after the heap is empty, return the distances

* searching through graphs => O(E+V)
* keeping track of distances => min-heap (O(log(V)))
=> worst case: O((E+V)logV)
'''

# 우선순위 큐 쓰는 이유: 최단거리부터 조사하기 위해!

# use heap to track of all the distances
from heapq import heappop, heappush
from math import inf

graph = {
        'A': [('B', 10), ('C', 3)],
        'C': [('D', 2)],
        'D': [('E', 10)],
        'E': [('A', 7)],
        'B': [('C', 3), ('D', 2)]
    }


def dijkstras(graph, start):
    distances = {}

    for vertex in graph:
        distances[vertex] = inf

    distances[start] = 0
    vertices_to_explore = [(0, start)]

    while vertices_to_explore:
        current_distance, current_vertex = heappop(vertices_to_explore)
        
        for neighbor, edge_weight in graph[current_vertex]:
            new_distance = current_distance + edge_weight

            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                heappush(vertices_to_explore, (new_distance, neighbor))
            
    return distances

distances_from_d = dijkstras(graph, 'D')
print("\n\nShortest Distances: {0}".format(distances_from_d))