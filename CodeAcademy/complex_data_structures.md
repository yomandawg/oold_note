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

------

### Blossom

