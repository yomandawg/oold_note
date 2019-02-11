# Linear Data Structures

## Node

* contain data, which can be a variety of date types
* contain links to other nodes, If a node has no links, or they are all `null`, you have reaced the end of the path you were following
* can be orphaned if there are no existing links to them

### Python Implementation

* basic node that contains data and one link to another node

* the node's data will be specified when creating the node and immutable.

* The link will be optional at initialization and can be updated

  ```python
  class Node:
    def __init__(self, value, link_node=None):
      self.value = value
      self.link_node = link_node
      
    # getters
    def get_value(self):
      return self.value
    
    def get_link_node(self):
      return self.link_node
  
    # setters
    def set_link_node(self, link_node):
      self.link_node = link_node
  
  yacko = Node("likes to yak")
  wacko = Node("has a penchant for hoarding snacks")
  dot = Node("enjoys spending time in movie lots")
  
  dot.set_link_node(wacko)
  yacko.set_link_node(dot)
  
  dots_data = yacko.get_link_node().get_value()
  wackos_data = dot.get_link_node().get_value()
  
  print(dots_data)
  print(wackos_data)    
  ```

  

## Linked List

* are comprised of nodes
* the nodes contain a link to the next node (and also the previous node for *bidirectional* linked lists)
* can be unidirectional or bidirectional
* are a basic data structure, and form the basis for many other date structures
* have a single head node, which serves as the first node in the list
* require some maintenance in order to add or remove nodes
* the methods we used are an example and depend on the exact use case and/or programming language being used

### Python Implementation

* each linked list is a sequential chain of nodes

* a node contains two elements: data and a link to the next node

  ```python
  class Node:
    def __init__(self, value, next_node=None):
      self.value = value
      self.next_node = next_node
      
    def get_value(self):
      return self.value
    
    def get_next_node(self):
      return self.next_node
    
    def set_next_node(self, next_node):
      self.next_node = next_node
  ```

* get the head node of the list

* add a new node to the beginning of the list

* print out the list values in order

* remove a node that has a particular value

  ```python
  class LinkedList:
    def __init__(self, value=None):
      self.head_node = Node(value)
    
    def get_head_node(self):
      return self.head_node
    
    def insert_beginning(self, new_value):
      new_node = Node(new_value)
      new_node.set_next_node(self.head_node)
      self.head_node = new_node
      
    def stringify_list(self):
      string_list = ""
      current_node = self.get_head_node()
      while current_node:
        string_list += str(current_node.get_value()) + "\n"
        current_node = current_node.get_next_node()
      return string_list
  
    def remove_node(self, value_to_remove):
      current_node = self.get_head_node()
      if current_node.get_value() == value_to_remove:
        self.head_node = current_node.get_next_node()
      else:
        while current_node:
          next_node = current_node.get_next_node()
          if next_node.get_value() == value_to_remove:
            current_node.set_next_node(next_node.get_next_node())
            current_node = None
          else:
            current_node = next_node
  ```

  ​                                                                                                 

## Stack

* Contains data nodes
* Support three main operations
  * Push adds data to the top of the stack
  * Pop removes and provides data from the top of the stack
  * Peek reveals data on the top of the stack
* Implementations include a linked list of array
* Can have a limited size
  * Pushing data onto a full stack results in a stack overflow
* Stacks process data Last In, First Out (*LIFO*)

### Python Implementation

```python
from node import Node

class Stack:
  def __init__(self, limit=1000):
    self.top_item = None
    self.size = 0
    self.limit = limit
  
  def push(self, value):
    if self.has_space():
      item = Node(value)
      item.set_next_node(self.top_item)
      self.top_item = item
      self.size += 1
      print("Adding {} to the pizza stack!".format(value))
    else:
      print("No room for {}!".format(value))

  def pop(self):
    if not self.is_empty():
      item_to_remove = self.top_item
      self.top_item = item_to_remove.get_next_node()
      self.size -= 1
      print("Delivering " + item_to_remove.get_value())
      return item_to_remove.get_value()
    print("All out of pizza.")

  def peek(self):
    if not self.is_empty():
      return self.top_item.get_value()
    print("Nothing to see here!")

  def has_space(self):
    return self.limit > self.size

  def is_empty(self):
    return self.size == 0
```



### Towers of Hanoi

> an ancient mathematical puzzle that starts off with three stacks and many disks

* move the stack of disks from the leftmost stack to the rightmost stack
  1. only one disk can be moved at a time
  2. each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod
  3. no disk may be placed on top of a smaller disk

```python
from stack import Stack

print("\nLet's play Towers of Hanoi!!")


#Create the Stacks
stacks = [] # stores the stacks

left_stack = Stack("Left")
middle_stack = Stack("Middle")
right_stack = Stack("Right")

stacks.append(left_stack)
stacks.append(middle_stack)
stacks.append(right_stack)


#Set up the Game
num_disks = int(input("\nHow many disks do you want to play with?\n"))
while num_disks < 3:
  num_disks = int(input("Enter a number greater than or equal to 3!\n"))

for i in range(num_disks, 0, -1):
  left_stack.push(i)

num_optimal_moves = 2**num_disks-1

print("\nThe fastest you can solve this game is in {}".format(num_optimal_moves))


#Get User Input
def get_input():
  choices = [stack.get_name()[0] for stack in stacks]
  while True:
    for i in range(len(stacks)):
      name = stacks[i].get_name()
      letter = choices[i]
      print("Enter {} for {}".format(letter, name))
    user_input = input()
    for i in range(len(stacks)):
      if user_input == choices[i]:
        return stacks[i]

        
#Play the Game
num_user_moves = 0

while right_stack.get_size() != num_disks:
  print("\n\n\n...Current Stacks...")
  for stack in stacks:
    stack.print_items()
  while True:
    print("\nWhich stack do you want to move from?\n")
    from_stack = get_input()
    print("\nWhich stack do you want to move to?\n")
    to_stack = get_input()
    if from_stack.get_size() == 0:
      "\n\nInvalid Move. Try Again"
    elif to_stack.get_size() == 0 or (from_stack.peek() < to_stack.peek()):
      disk = from_stack.pop()
      to_stack.push(disk)
      num_user_moves += 1
      break
    else:
      print("\n\nInvalid Move. Try Again")

    
print("\n\nYou completed the game in {} moves, and the optimal number of moves is {}".format(num_user_moves, num_optimal_moves))
```

```python
from node import Node

class Stack:
  def __init__(self, name):
    self.size = 0
    self.top_item = None
    self.limit = 1000
    self.name = name
  
  def push(self, value):
    if self.has_space():
      item = Node(value)
      item.set_next_node(self.top_item)
      self.top_item = item
      self.size += 1
    else:
      print("No more room!")

  def pop(self):
    if self.size > 0:
      item_to_remove = self.top_item
      self.top_item = item_to_remove.get_next_node()
      self.size -= 1
      return item_to_remove.get_value()
    print("This stack is totally empty.")

  def peek(self):
    if self.size > 0:
      return self.top_item.get_value()
    print("Nothing to see here!")

  def has_space(self):
    return self.limit > self.size

  def is_empty(self):
    return self.size == 0
  
  def get_size(self):
    return self.size
  
  def get_name(self):
    return self.name
  
  def print_items(self):
    pointer = self.top_item
    print_list = []
    while(pointer):
      print_list.append(pointer.get_value())
      pointer = pointer.get_next_node()
    print_list.reverse()
    print("{0} Stack: {1}".format(self.get_name(), print_list))
```



## Queue

* data structure which contains ordered set of data
* supports three main operations:
  * *enqueue* adds data to the back of the queue
  * *dequeue* removes and provides data from the front of the queue
  * *peek* provides data on the front of the queue
* can be implemented using a linked list or array
* *bounded queue* have a limited size
* enqueueing onto a full queue causes a queue overflow
* queues process data First In, First Out (*FIFO*)

### Python Implementation

```python
from node import Node

class Queue:
  def __init__(self, max_size=None):
    self.head = None
    self.tail = None
    self.max_size = max_size
    self.size = 0
    
  def enqueue(self, value):
    if self.has_space():
      item_to_add = Node(value)
      print("Adding " + str(item_to_add.get_value()) + " to the queue!")
      if self.is_empty():
        self.head = item_to_add
        self.tail = item_to_add
      else:
        self.tail.set_next_node(item_to_add)
        self.tail = item_to_add
      self.size += 1
    else:
      print("Sorry, no more room!")
         
  def dequeue(self):
    if self.get_size() > 0:
      item_to_remove = self.head
      print(str(item_to_remove.get_value()) + " is served!")
      if self.get_size() == 1:
        self.head = None
        self.tail = None
      else:
        self.head = self.head.get_next_node()
      self.size -= 1
      return item_to_remove.get_value()
    else:
      print("The queue is totally empty!")
  
  def peek(self):
    if self.size > 0:
      return self.head.get_value()
    else:
      print("No orders waiting!")
  
  def get_size(self):
    return self.size
  
  def has_space(self):
    if self.max_size == None:
      return True
    else:
      return self.max_size > self.get_size()
    
  def is_empty(self):
    return self.size == 0
```

