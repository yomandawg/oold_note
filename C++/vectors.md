# Vectors

> useful ways of storing data in C++

* `#include`  - preprocessor directive that tells the compiler to include whatever library that follows.

```c++
#include <vector>
// std::vector<type> name; // vector syntax
std::vector<int> calories_today;
// the type of the vector cannot be changed after the declaration
```

```c++
// store a latitude and a longitude
std::vector<double> location = {42.651443, -73.749302};

// can initialize vecotr by presizing
std::vector<double> location(2); // sizeof 2
// looks like {0.0, 0.0} since 0.0 is the default value for double
```



#### Index

* index* refers to an element's position within an ordered list.
  * vectors are 0-indexed; the first element has index 0, the second index 1, and so on.

```c++
std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
// char at index 0, 1, 2, 3, 4 is 'a', 'e', 'i', 'o', 'u'

//to output each of the elements:
std::cout << vowels[0] << "\n";
std::cout << vowels[1] << "\n";
std::cout << vowels[2] << "\n";
std::cout << vowels[3] << "\n";
std::cout << vowels[4] << "\n";
```



#### Adding and Removing Elements

* we can grow the vector as needed
* `.push_back()` - add  a new element at the end of the vector
* `.pop_back()` -remove elements at the end of the vector

```c++
std:vector<std::string> dna = {"ATG", "ACG"};

dna.push_back("GTG");
dna.push_back("CTG");
dna.pop_back(); // has no return value though!
```



