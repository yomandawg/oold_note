'''
* We don't really care about the exact sequence of the data.
    - We only care that a given input, when fed into the map, gives the accurate output
    - tricky because computers care about values than relationships
* Hash Function
    - takes a string(or some other type of data) as input and returns an array index as output
    - hash map implementation needs to know the size of the array
    - compute a value using some scoring metric: hash value, hash code , or just the hash
    - hash map implementation then takes that hash value mod the size of the array
    - therefore, known as compresssion functions
    - much like an image that has been shrunk to a lower resolution
    - not a reversible process
* Writing the Hash function
    - hash function needs to be simple by design
    - performance - should be able to do quickly
    - also need to be able to take whatever type of data we want to use as a key
* Basic Hash Maps
    - array of fixed size
    - the storage location at the index given by a hash is called the hash bucket
* Hash Collisions
    - because of the compression, it's likely that our hash function might produce the same hash for different keys
    - separate chaining - avoids collisions by updating the underlying data structure; could be array of linked lists
* Separate chaining (effective for those that are good at giving unique indices; the linked lists never get very long)
    - the hash map takes the key and transforms it into a hash code
    - hash code is then converted into an index to an array using the modulus op.
    - if the value of the array at the hash function's returned index is empty, a new linked list is created with the value as the first element of the linked list.
    - if a linked list already exists at the address, append the value to the linked list given.
    - effective for hash functions that are particularly "good at giving unique indices", so the linked lists never get very long
    - for the worst-case: lookup performance is only as good as it would be on a linked list
* Saving Keys
    - collision resolution involves assigning two keys with the same hash to different parts of the underlying data structure
    - if we save both the key and the value, then we will be able to check against the saved key when we're accessing data in a hash map.
    1. calculate the hash for the key,
    2. find the appropriate index for that hash
    3. begin iterating through our linked list
* Open Addressing: Linear Probing
    - stick to the array as our underlying data structure, but we continue looking for a new index to save our data if the first result of our has function has a different key's data
    - probing: continuing to find new array indices in a fixed sequence until an empty index is found
    1. first check the array at index 3.
    2. upon noticing that our key is different from the key sitting in index 3,
    3. continue to the next index
    4. retrieve the info at the matched location
* Clustering
    - having a probe sequence change over time avoids clustering
    - clustering: when a single hash collision causes additional hash collisions
    - new key needs to be assigned to the next, next bucket over
    - maybe we could write a function that takes the key and returns a number of steps to jump to get to the next index
'''
'''
Hash map: a key-value store that uses an array and a hashing function to save and retreive values
Key: the identifier given to a value for later retrieval
Hash function: takse some input and returns a number
Compression function: transforms its inputs into smaller range of possible outputs

Recipe for saving to a hash table:
- take the key and plug it into the hash functino, getting the hash code
- modulo that hash code by the length of the underlying array, getting an array index
- check if the array at that index is empty, if so, save the value (and the key) there
- if the array is full at that index continue to the next possible position based on your collision strategy

Recipe for retrieving from a hash table:
- take the key and plug it into the hash function, getting the hash code
- modulo that hash code by the length of the underlying array, getting an array index
- check if the array at that index has contents, if so, check the key saved there
- if the key matche, return the value
- if not, continue to the next position depending on your collision strategy
'''

# crating the hash map class
'''
* in Python, we don't have an array data structure that uses a contiguous block of memory
* simulate an array by creating a list and keeping track of the size of the list with an additional integer variable
* not exactly a hash map but resembles
* python offers a built-in hash table implementation with dictionaries, though
'''

class HashMap:
    def __init__(self, array_size):
        self.array_size = array_size
        self.array = [None for item in range(array_size)]

    # hash function
    def hash(self, key):
        key_bytes = key.encode() # turn the key into a list of bytes and save into key_bytes
        hash_code = sum(key_bytes) # turn the bytes object into a hash code by sum, save into hash_code
        return hash_code # return the value
    
    # compression function
    def compressor(self, hash_code):
        return hash_code % self.array_size

    # setter
    def assign(self, key, value):
        array_index = self.compressor(self.hash(key))
        # self.array[array_index] = value
        current_array_value = self.array[array_index]

        if current_array_value is None: # assign if None
            self.array[array_index] = [key, value]
            return
        
        if current_array_value[0] == key: # reassign if same key
            self.array[array_index] = [key, value]
            return

        return # collision, holds different key


    # getter
    def retrieve(self, key):
        array_index = self.compressor(self.hash(key))
        # return self.array[array_index]
        possible_return_value = self.array[array_index]

        if possible_return_value is None: # None if empty
            return None

        if possible_return_value[0] == key: # return if matches
            return possible_return_value[1]

        return # holds different key


hash_map = HashMap(20)
hash_map.assign('gneiss', 'metamorphic')
print(hash_map.retrieve('gneiss'))