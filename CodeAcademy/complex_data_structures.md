# Complex Data Structures

## Hash Maps

* Built on top of an array using a special indexing system
* A key-value storage with fast assignments and lookup
* A table that represents a map from a set of keys to a set of values
* Hash maps accomplish all this by using a *hash function*, which turns a key into an index into the underlying array
* A *hash collision* is when a hash function returns the same index for two different keys
  * *Separate chaining* - each array index points to a different data structure
  * *Open addressing* - a collision triggers a *probing* sequence to find where to store the value for a given key
    * Linear probing can cause *clustering* - a single hash collision causes  additional hash collisions

---

* *Hash map* - A key-value store that uses and array and a hashing function to save and retrieve values
* *Key* - the identifier given to a value for later retrieval
* *Hash function* - a function that takes some input and returns a number
* *Compression function* - a function that transforms its inputs into some smaller range of possible outputs

* Recipe for saving to a hash table:
  1. Take the key and plug it into the hash function, getting the hash code
  2. *Modulo* that hash code by the length of the underlying array, getting an array index
  3. Check if the array at that index is empty, if so, save the value (and the key) there
  4. If the array is full at that index, continue to the next possible position depending on your collision strategy

* Recipe for retrieving from a hash table:
  1. Take the key and plug it into the hash function,getting the hash code
  2. Modulo that hash code by the length of the underlying array, getting an array index
  3. Check if the array at that index has contents, if so, check the key saved there
  4. If the key matches the one you're looking for, return the value
  5. If the keys don't match, continue to the next position depending on your collision strategy

---

### Python Implementation



