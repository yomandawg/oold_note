'''
# Tree
* essential data structure for storing hierarchial data with a directed flow
* similar to linked lists and graphs, trees are composed of nodes which hold data.
* Nodes store references to zero or more other tree nodes
* `root`, `parent`, `child`, `sibling` node
* a node with no children: `leaf` node
* each node has at most one parent
* each time we move from a parent to a child, `level` down
* depending on the orientation, `height` or `depth

# Binary Search Tree
* type of tree where each parent can have no more than two children
    - left, right child
* left child must be lesser than their parent, right child greater
'''

class TreeNode:
    def __init__(self, value):
        self.value = value # data
        self.children = [] # references to other nodes

    def add_child(self, child_node):
        # creates parent-child relationship
        print("Adding " + child_node.value)
        self.children.append(child_node) 
        
    def remove_child(self, child_node):
        # removes parent-child relationship
        print("Removing " + child_node.value + " from " + self.value)
        self.children = [child for child in self.children if child is not child_node]

    def traverse(self):
        # moves through each node referenced from self downwards
        nodes_to_visit = [self]
        while len(nodes_to_visit) > 0:
            current_node = nodes_to_visit.pop()
            print(current_node.value)
            nodes_to_visit += current_node.children
