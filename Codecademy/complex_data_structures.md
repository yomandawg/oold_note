# Complex Data Structures

## Hash Maps

- Built on top of an array using a special indexing system
- A key-value storage with fast assignments and lookup
- A table that represents a map from a set of keys to a set of values
- Hash maps accomplish all this by using a *hash function*, which turns a key into an index into the underlying array
- A *hash collision* is when a hash function returns the same index for two different keys
  - *Separate chaining* - each array index points to a different data structure
  - *Open addressing* - a collision triggers a *probing* sequence to find where to store the value for a given key
    - Linear probing can cause *clustering* - a single hash collision causes  additional hash collisions

------

- *Hash map* - A key-value store that uses and array and a hashing function to save and retrieve values
- *Key* - the identifier given to a value for later retrieval
- *Hash function* - a function that takes some input and returns a number
- *Compression function* - a function that transforms its inputs into some smaller range of possible outputs
- Recipe for saving to a hash table:
  1. Take the key and plug it into the hash function, getting the hash code
  2. *Modulo* that hash code by the length of the underlying array, getting an array index
  3. Check if the array at that index is empty, if so, save the value (and the key) there
  4. If the array is full at that index, continue to the next possible position depending on your collision strategy
- Recipe for retrieving from a hash table:
  1. Take the key and plug it into the hash function,getting the hash code
  2. Modulo that hash code by the length of the underlying array, getting an array index
  3. Check if the array at that index has contents, if so, check the key saved there
  4. If the key matches the one you're looking for, return the value
  5. If the keys don't match, continue to the next position depending on your collision strategy

------

### Python Implementation

- Hash maps are efficient key-value stores
- Capable of assigning and retrieving data in the fastest way possible for a data structure
  - The underling data structure that they use is an array
- A value is stored at an array index determined by plugging the key into a hash function
- In Python, we don't have an array data structures that uses a contiguous block of memory
  - We are going to simulate an array by creating a list and keeping track of the size of the list with an additional integer variable

#### Open Addressing

```python
class HashMap:
  def __init__(self, array_size):
    self.array_size = array_size
    self.array = [None for item in range(array_size)]

  def hash(self, key, count_collisions=0):
    key_bytes = key.encode()
    hash_code = sum(key_bytes)
    return hash_code + count_collisions

  def compressor(self, hash_code):
    return hash_code % self.array_size

  def assign(self, key, value):
    array_index = self.compressor(self.hash(key))
    current_array_value = self.array[array_index]

    if current_array_value is None:
      self.array[array_index] = [key, value]
      return

    if current_array_value[0] == key:
      self.array[array_index] = [key, value]
      return

    # Collision!

    number_collisions = 1

    while(current_array_value[0] != key):
      new_hash_code = self.hash(key, number_collisions)
      new_array_index = self.compressor(new_hash_code)
      current_array_value = self.array[new_array_index]

      if current_array_value is None:
        self.array[new_array_index] = [key, value]
        return

      if current_array_value[0] == key:
        self.array[new_array_index] = [key, value]
        return

      number_collisions += 1

    return

  def retrieve(self, key):
    array_index = self.compressor(self.hash(key))
    possible_return_value = self.array[array_index]

    if possible_return_value is None:
      return None

    if possible_return_value[0] == key:
      return possible_return_value[1]

    retrieval_collisions = 1

    while (possible_return_value != key):
      new_hash_code = self.hash(key, retrieval_collisions)
      retrieving_array_index = self.compressor(new_hash_code)
      possible_return_value = self.array[retrieving_array_index]

      if possible_return_value is None:
        return None

      if possible_return_value[0] == key:
        return possible_return_value[1]

      retrieval_collisions += 1

    return
  

hash_map = HashMap(15)
hash_map.assign('gabbro', 'igneous')
hash_map.assign('sandstone', 'sedimentary')
hash_map.assign('gneiss', 'metamorphic')
print(hash_map.retrieve('gabbro'))
print(hash_map.retrieve('sandstone'))
print(hash_map.retrieve('gneiss'))
```

#### Separate Chaining

```python
from linked_list import Node, LinkedList

class HashMap:
    def __init__(self, size):
        self.array_size = size
        self.array = [LinkedList() for _ in range(self.array_size)]

    def hash(self, key):
        return sum(key.encode())

    def compress(self, hash_code):
        return hash_code % self.array_size

    def assign(self, key, value):
        array_index = self.compress(self.hash(key))
        payload = Node([key, value])
        list_at_array = self.array[array_index]
        for item in list_at_array:
            if key == item[0]:
                item[1] = value
                return
        list_at_array.insert(payload)

    def retrieve(self, key):
        array_index = self.compress(self.hash(key))
        list_at_index = self.array[array_index]
        for item in list_at_index:
            if key == item[0]:
                return item[1]
        return None
```

------

## Trees

* useful for modeling data that has a hierarchical relationship which moves in the direction from parent to child
* No child node will have more than one parent
* terms:
  * *root*: a node which has no parent. One per tree.
  * *parent*: a node which references other nodes.
  * *child*: nodes referenced by other nodes.
  * *siblings*: nodes which have the same parent.
  * *leaf*: nodes which have no children
  * *level*: the height or depth of the tree. Root nodes are at level 1, their children are at level 2, and so on.

---

### Python Implementation

```python
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
```

---

## Heaps

* heaps are used to maintain a maximum or minimum value in a dataset to act as a priority queue
* heaps tracking the maximum or minimum value are *max-heaps* and *min-heaps*
* these heaps are treated as a binary tree with two qualities:
  * the root is the minimum(maximum) value of the dataset
  * every child's value is greater than its parent
  * each node has at most two children; new elements are added from left to right
    * left child: `(index * 2 ) + 1`
    * right child: `(index * 2) + 1`
    * parent: `(index - 1) / 2` - not used on the root
* the tree representation is a conceptual; practically, we implement heaps in a sequential data structure like an array or a list
* when adding an item that violates the min-heap property, the new item goes through the restoration known as *heapify* or *heapifying*
  * adding an element to the bottom of the tree and moving upwards - *heapifying up*
  * swap the violating child with its parent until we restore the properties or there is no parent left(the new element becomes the new root)
  * to remove a node, for example the root node, instead of leaving two children orphaned, we'll swap the root node with the bottom rightmost child.
    * the bottom rightmost then violates the heap property therefore, heapfies down to restore the heap property

---

### Python Implementation

* Min-heap
  * keep track of the *minimum value*

```python
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
      print("Heap of {0} elements restored with {1} swaps"
            .format(element_count, swap_count))
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
      print("Heap of {0} elements restored with {1} swaps"
            .format(element_count, swap_count))
      print("")  
```

* `MinHeap` tracks the minimum element as the element at index `1` within an internal Python list
* use `.heapify_up()` to add elements to compare the new element with its parent, making swaps if it violates the heap property.
* when removing the minimum element, we swap it with the last element in the list.
  * use `.heapify_down()` to compare the new root with its children, swapping with the smaller child if necessary

---

## Graphs





