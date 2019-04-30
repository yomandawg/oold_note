'''
heaps are used to maintain a maximum or minumum value in a dataset
* ex) always want the most important thing done first
    - priority queue(max heap)
* efficient to keep track of min, max val
* Shortest path: Dijkstra's Algorithms
* Heap Sort

* min heap
    - root is the min value
    - every child's value is greater than its parent
    - retrieve then update
    - reprentation as binary trees
        - each node has at most two children
        - added from left to right until filling the entire level
        - leave no gaps in the array
            - left child: `(index*2)+1`
            - right child: `(index*2)+2`
            - parent: `(index-1)/2`
                - not for the root

* adding an element (heapify up)
    - adding => heapify(restoration)
        - add to the bottom of the tree and heapify up
    - swap the offending child with its parent until restoration
* removing an element (heapify down)
    - removing the parent => two children orphaned!
        => swap the root node then remove the bottom rightmost
    - heapify down by choosing the leseer of the two values
'''

# # import random number generator
# from random import randrange

'''
MinHeap stores two pieces of info
1. python list of the elements within the heap
2. count of the elements within the heap
* sentinel element at the beginning as `None` for convenience
    - save us the trouble of checking whether the list is empty / simplify the methods
'''

# None is the first value
# element at index 1 is the min value
# every child element in the list must be larger than their parent

# use list for storing internal element
# modeling by binary tree
# child and parent are determined by their relative indices

class MinHeap:
    def __init__(self):
        self.heap_list = [None]
        self.count = 0

    def parent_idx(self, idx):
        return idx // 2

    def left_child_idx(self, idx):
        return idx * 2

    def right_child_idx(self, idx):
        return idx * 2 + 1

    def child_present(self, idx):
        return self.left_child_idx(idx) <= self.count
    
    def retrieve_min(self):
        if self.count == 0:
            print("No items in heap")
            return None
        
        min = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.count]
        self.count -= 1
        self.heap_list.pop()
        self.heapify_down()
        return min

    def add(self, element):
        self.count += 1
        self.heap_list.append(element)
        self.heapify_up()


    def get_smaller_child_idx(self, idx):
        if self.right_child_idx(idx) > self.count:
            return self.left_child_idx(idx)
        else:
            left_child = self.heap_list[self.left_child_idx(idx)]
            right_child = self.heap_list[self.right_child_idx(idx)]
        if left_child < right_child:
            return self.left_child_idx(idx)
        else:
            return self.right_child_idx(idx)
        
    def heapify_up(self):
        idx = self.count
        swap_count = 0
        while self.parent_idx(idx) > 0:
            if self.heap_list[self.parent_idx(idx)] > self.heap_list[idx]:
                swap_count += 1
                tmp = self.heap_list[self.parent_idx(idx)]
                self.heap_list[self.parent_idx(idx)] = self.heap_list[idx]
                self.heap_list[idx] = tmp
            idx = self.parent_idx(idx)

        element_count = len(self.heap_list)
        if element_count > 10000:
            print("Heap of {0} elements restored with {1} swaps".format(element_count, swap_count))
            print("")    
        
    def heapify_down(self):
        idx = 1
        # starts at 1 because we swapped first and last elements
        swap_count = 1
        while self.child_present(idx):
            smaller_child_idx = self.get_smaller_child_idx(idx)
            if self.heap_list[idx] > self.heap_list[smaller_child_idx]:
                swap_count += 1
                tmp = self.heap_list[smaller_child_idx]
                self.heap_list[smaller_child_idx] = self.heap_list[idx]
                self.heap_list[idx] = tmp
            idx = smaller_child_idx

        element_count = len(self.heap_list)
        if element_count >= 10000:
            print("Heap of {0} elements restored with {1} swaps".format(element_count, swap_count))
            print("")  

# MinHeap tracks the minimum element as the element at index 1 within an internal list
# when adding elements, we use `heapify_up()` to compare the new element with its parent
# children must be greater than their parents
# efficient in maintaining the heap properties