# C++ Functions

> reuse code
>
> test individual functions
>
> make modifications within a single function, without altering the program structure

### main()

* every valid c++ program has at least one funciton - `main()`

```c++
/*
return_type function_name(parameter list)
{
	body of the function
}
*/
int main() // return type declared before its name; functions without returning a value: void
{
    // code 
    return 0;
}
```

* `void` is  a basic data type that defines a valueless state

* function declaration is required when you define a function in one source file and you call that function in another file
  * call a function prior to using it
  * or declare then, define later

```c++
#include <iostream>
using namespace std;

void printSomething(); // function declaration

int main() {
    printSomething(); // function calling
    return 0;
}

void printSomething() { // function definition
    cout << "hi";
}
```

```c++
void printSomething(int x) // declare formal parameters
{
    cout << x;
}
// formal parameters behave within the function similarly to other local variables.
// they are created upon entering the function, and are destroyed upon exiting the function
```

```c++
#include <iostream>
using namespace std;

void printSomething(int x){
    cout << x;
}

int main() {
    printSomething(42); // 42
}
// making changes to the parameter within the function does not alter the argument
```

```c++
int addNumbers(int x, int y){
    int result = x + y;
    return result;
}

int main() {
    cout << addNumbers(50, 25); // 75
    int x = addNumbers(35, 7); // can also assign the returned value to a variable
    cout << x; 42
}
```

* `rand` function
  * `<cstdlib>` - defines several general purpose functions, including dynamic memory management, random number gen, etc.
  * returns only a pseudo-random number; each time the code is run, it generates the same numbers

```c++
#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    cout << rand();
    for (int x = 1; x <= 10; x++) {
        cout << rand() << endl;
    }
    for (int x = 1; x <= 10; x++) {
        cout << 1 + (rand()%6) << endl; // modulo operator
    }
}
```

* `srand` function
  * generate truly random numbers
  * specify a *seed* value as its parameter, which is used for the `rand()` function's algorithm

```c++
int main() {
    srand(98); // changing the seed value changes the return of rand()
    for (int x=1; x<=10; x++) {
        cout << 1 + (rand()%6) << endl;
    }
}
```

```c++
#include <ctime> // contains definitions of functions to get and manipulate date and time information

int main() {
    srand(time(0)); // use the time as a seed value - get the number of seconds on your sys time
    // time(0) - return the current second count - different seed for each time
    for (int x=1; x<=10; x++){
        cout << 1+(rand()%6) << endl;
    }
}
```



#### default values

* you can specify a default value for each of the last parameters
  * if the corresponding argument is missing when you call a function, use it

```c++
int sum(int a, int b=42) {
    int result = a+b;
    return(result);
}

int main() {
    int x = 24;
    int y = 36;
    
    int result = sum(x, y); // calling the function for both parameters
    cout << result << endl;
    
    result = sum(x); // calling the function w/o b; use the default
    cout << result << endl;
    
    return 0;
}
```

```c++
int volume(int l=1, int w=1, int h=1){
    return l*w*h;
}

int main() {
    cout << volume() << endl;
    cout << volume(5) << endl;
    cout << volume(2, 3) << endl;
}
```



#### overloading

* allows to create multiple functions with the same name, so long as they have different parameters
* the def. of the function must differ from each other by the types and/or the number of arguments in the argument list

```c++
void printNumber(int a) { // effective with integer arguments only
    cout << a;
}
void printNumber(float a) { // overloading: effective with float arguments only
    cout << a;
}

int main() {
    int a = 16;
    float b = 54.541;
    printNumber(a); // for int
    printNUmber(b); // for float
}
```

* you cannot overload function declarations that differ only by return type

```c++
// this is an error; only differece in return type not allowed
int printName(int a) {}
float printName(int b) {}
double printName(int c) {}
```



#### Recursion

* factorial

```c++
int factorial(int n) {
    if (n==1) { // base case
        return 1; // exit condition
    }
    else {
        return n*factorial(n-1); // recursive condition
    }
}
int main() {
    cout << factorial(5); // 120
}
```



#### passing array and functions

* array can also be passed to a function as an argument
* the parameter should be defined as an array using square brackets

```c++
void printArray(int arr[], int size) { // specify the array's name with square brackets
    for(int x=0; x<size; x++) { // iterates over the array
        cout << arr[x] << endl;
    }
}
int main() {
    int myArr[3] = {42, 33, 88};
    printArray(myArr, 3); // array parameter
}
```



#### passing by pointers

* two ways to pass arguments - by default, C++ calls *by value*
  * By value 
    * copies the argument's actual value into the function's formal parameter
    * can make changes to the parameter within the function without having any effect on the argument
    * *original argument is not modified by the function*
      * faster and more effective
  * By reference
    * copies the argument's reference into the formal parameter
    * the reference is used to access the actual argument used in the call
    * *any change made to the parameter affects the argument*
      * when your function needs to modify the argument
      * when you need to pass a data type, that uses a lot of memory and is expensive to copy

```c++
/* pass by reference - argument pointers are passed to the funciton
copies an argument's address into the formal parameter.
inside the funciton, the address is used to access the actual argument used in the call.
changes made to the parameter affect the argument */
void myFunc(int *x){
    *x = 100;
}
int main() {
    int var = 20;
    myFunc(&var); // passed the address-of variable directly to the function: pointer as its parameter
    cout << var; // 100: changed the argument's value, as accessed it via the pointer
}
```

