# C++

> Object-oriented into C

* fast, flexible
* well-supported



```c++
#include <iostream> // include libraries

int main() // the main() function
{ // beginning of function
    std::cout << "Hello World\n"; // what the program does
} // end of function
```

* `std::cout`  - 표준 입출력 character output stream(연속적 데이터 열)
* `<<` - operator



* compiled language
  * *compiler* - translate it from a human-readable form to machine language

* `g++ hello.cpp` 
  * compiler command &rarr; executable `a.out` file
* `./a.out` 
  * execute &rarr; loaded to computer memory and CPU(central processing unit) one instruction at a time

* to give executable file a specific name, `g++ hello.cpp -o hello`
  * `./hello`



## Data types

> represents a particular piece of the computer's memory
>
> The OS allocates memory and selects what will be stored in the reserved memory based on the variable's data type
>
> The data type defines the proper use of an identifier, what kind of data can be stored, and which types of operations can be performed

|  type  |         usage          |     examples      | size(sizeof operator)                      |
| :----: | :--------------------: | :---------------: | ------------------------------------------ |
|  int   |        integer         |      0, 420       | 4-8bytes(varies according to architecture) |
| double |     floating-point     |   3.14, -200.0    | 8-16byte                                   |
|  char  |       character        |     'a', '@'      | 1byte integer(ASCII)                       |
| string | sequence of characters |  "Hello World!"   |                                            |
|  bool  |      truth values      | true(1), false(0) | 1byte                                      |
| float  |     floating-point     |                   | 4byte                                      |

```c++
// sizeof(data type)
cout << "char: " << sizeof(char) << endl;
cout << "int: " << sizeof(int) << endl;
cout << "float: " << sizeof(float) << endl;
cout << "double: " << sizeof(double) << endl;
int var = 50;
cout << "var: " << sizeof(var) << endl;
/* Outputs depending on computer and compiler
char: 1
int: 4
float: 4
double: 8
var: 4
*/ 
```

```c++
double myArr[10];
cout << sizeof(myArr) << endl; // 80 = 8*10
int numbers[100];
cout << sizeof(numbers)/sizeof(numbers[0]); // 100 = 100/1
```



```c++
#include <iostream> // standard stream objects that input/output data
using namespace std;

int main()
{
    int variable = 10;
    int a, b; // defines two varibles at once
    int c = 30;
    int d = 15;
    int sum = a+b; // possible to add right away
    cout << variable;
    return 0;
};
// output = 10
```

```c++
int main()
{
    int a;
    cout << "enter number\n"; // used to write output to std output(screen)
    cin >> a; // used to read from the std input device(keyboard)
    cin >> b;
    sum = a+b;
    cout << "sum is: " << sum << endl; // writes a new line to output
    return 0;
};
```

#### Data types

```c++
unsigned long int a;
/*
signed - can hold both negative and positive values
unsigend - only positive values
short - half of the default size
long - twice the default size
*/
```

#### Strings

```c++
#include <string> // included in the <iostream>
using namepace std;

int main() {
    string a = "I am learning";
    return 0;
};
```

#### Arrays

* store collection of data
  * collection of variables that are all of the same type

```c++
int a[5];
int b[5] = {11, 45, 62, 70, 88}; // number of {} cannot exceed the number within []
int b[] = {11, 45, 62, 70, 88}; // can omit the size of the array

cout << b[0] << endl; // outputs 11
cout << b[3] << endl; // outputs 8-

b[2] = 42; // assigns a value to b[2]
```

```c++
int myArr[5];

for(int x=0; x<5; x++){
    myArr[x] = 42;
    cout << x << ": " << myArr[x] <<endl;
};
/* Outputs
0: 42
1: 42
...
*/
int arr[] = {11, 35, 62, 555, 989};
int sum = 0;
for(int x=0; x<5; x++){
    sum += arr[x];
};
cout << sum << endl; // 1652
```

* Multi-Dimensional Arrays

```c++
// type name[size1][size2]...[sizeN];
int x[3][4];
int y[2][3] = {
    {2, 3, 4}, // 1st row
    {8, 9, 10} // 2nd row
};
cout << y[0][2] << endl; // 4
string threeD[42][8][3]; // can contain an unlimited number of dimensions
```





## Pointers

> every variable is a memory location, which has its address defined
>
> that address can be accessed using the ampersand(&) operator(address-of operator), which denotes an address in memory

```c++
int score = 5;
cout << &score <<endl; // 0x29fee8 memory address

int *ip; // pointer to an integer
double *dp; // pointer to a double
float *fp; // to a float
char *ch; // char
```

* **pointer** is a variable, with the address of another variable as its value
  * must be declared before working with it
  * `*` sign to declare
* dynamic memory allocation cannot be performed without pointers
* long *hexadecimal* number that represents a memory address

```c++
int score = 5;
int *scorePtr; // pointer to an integer
scorePtr = &score; // assign the address to a variable(&score) to the pointer(scorePtr)

cout << scorePtr < endl; // 0x29fee8
```



* pointer operations
  * Address-of(&) operator: returns the memory address of its operand
  * Content-of;dereference(*) operator: returns the value of the variable located at the address specified by its operand 

```c++
int var = 50;
int *p;
p = &var;
cout << var << endl; // 50
cout << p << endl; // 0x29fee8
cout << *p << endl; // 50 (the value of the variable stored in the pointer p)

// dereference * is basically an alias for the variable the pointer points to
int x = 5;
int *p = &x;
x = x+4;
x = *p+4; // see man this is the same!
*p = *p+4;
// all equivalent, returns the same result
// as p is pointing to the variable x, dereferencing the pointer(*p) is representing exactly the same as the varialble x
```



#### Dynamic Memory

* allocated address can be stored in a **pointer**
  * can be dereferenced to access the variable

```c++
int *p = new int; // dynamically allocated memory for an integer
*p = 5;
// the pointer p is stored in the stack as a local variable, and holds the heap's allocated address as its value.
// the value 5 is stored at that address in the heap
```

* for local variables on the stack, managing memory is carried out automatically.
* on the heap, it's necessary to manually handle the dynamically allocated memory, and use the `delete` operator to free up the memory when it's no longer needed
  * `delete pointer;` - releases the memory pointed to by pointer

```c++
int *p = new int; // request memory
*p = 5; // store value
cout << *p << endl; // use value
delete p; // free up the memory
```

* forgetting to free up memory that has been allocated with the `new` keyword will result in memory leaks, because that memory will stay allocated until the program shuts down



* the delete operator frees up the memory allocated for the variable, but does not delete the pointer itself, as the pointer is stored on the stack.
* pointers that are left pointing to non-existent memory locations are called **dangling pointers**

```c++
int *p = new int; // request memory
*p = 5; //store value
delete p; // free up the memory
// now p is a dangling pointer
p = new int; // reuse for a new address
```

* the *NULL* pointer is a constant with a value of zero that is defined in several of the std libraries, including iostream.
* it's a good practice to assign `NULL` to a pointer variable when you declare it, in case you do not have exact address to be assigned.
  * `int *ptr = NULL;`

```c++
int *p = NULL; // pointer initialized with null
p = new int[20]; // request memory
delete [] p; // delete array pointed to by p
```

* dynamic memory allocation is useful in many situations, such as when your program depends on input. As an example, when your program needs to read an image file, it doesn't know in advance the size of the image file and the memory necessary to store the image

