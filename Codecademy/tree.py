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
        self.value = value
        self.children = []

    def __repr__(self, level=0):
        # Helper method to print tree
        ret = "--->" * level + repr(self.value) + "\n"
        for child in self.children:
            ret += child.__repr__(level+1)
        return ret

    def add_child(self, child_node):
        self.children.append(child_node)