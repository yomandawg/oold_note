'''
* graphs are the perfect data structure for modeling networks
    - nodes(vertices), edges(connection)
* path: vertices which are connected by any number of intermediate edges
    - no path exists: a graph is disconnected
* weighted - edges have a number or cost associated with traveling between the vertices
* directed edges restrict the direction of movement between vertices
    - cycle: ends on the vertex where it began

* adjacency matrix
    - spreadsheet
* graph
* adjacency list
    - each vertex contains a list of the vertices where an edge exists
'''

class Vertex:
    def __init__(self, value):
        self.value = value
        self.edges = {}

    def add_edge(self, vertex, weight = 0):
        self.edges[vertex] = weight

    def get_edges(self):
        return list(self.edges.keys())


class Graph:
    def __init__(self, directed = False):
        self.graph_dict = {}
        self.directed = directed

    def add_vertex(self, vertex):
        self.graph_dict[vertex.value] = vertex

    def add_edge(self, from_vertex, to_vertex, weight = 0):
        self.graph_dict[from_vertex.value].add_edge(to_vertex.value, weight)
        if not self.directed:
            self.graph_dict[to_vertex.value].add_edge(from_vertex.value, weight)

    def find_path(self, start_vertex, end_vertex):
        start = [start_vertex]
        seen = {}
        while len(start) > 0:
            current_vertex = start.pop(0)
            seen[current_vertex] = True
            print("Visiting " + current_vertex)
            if current_vertex == end_vertex:
                return True
            else:
                vertices_to_visit = set(self.graph_dict[current_vertex].edges.keys())
                start += [vertex for vertex in vertices_to_visit if vertex not in seen]
        return False

'''
Vertex
* uses a dict as an adjacency list to store connected vertices
* connected vertex names are keys and the edge weights are values
* has methods to add edges and return a list of connected vertices

Graph
* can be initialized as a directed graph, where edges are set in one direction
* stores every vertex inside a dictionary
    - vertex data is the key and the vertex instance is the value
* has  methods to add vertices, edges between vertices, and determine if a path exists between two vertices
'''