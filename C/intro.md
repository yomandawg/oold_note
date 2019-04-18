# C

```C
#include <stdio.h>
int main() {
    printf("asdf\n");
    return 0;
}
```

---

```C
#include <stdio.h>

int main() {
  printf("int: %d \n", sizeof(int)); // 4
  printf("float: %d \n", sizeof(float)); // 4
  printf("double: %d \n", sizeof(double)); // 8
  printf("char: %d \n", sizeof(char)); // 1

  return 0;
}
```

```C
#include <stdio.h>

int main() {
  int a, b;
  float salary = 56.23;
  char letter = 'Z';
  a = 8;
  b = 34;
  int c = a+b;

  printf("%d \n", c); // format specifiers
  printf("%f \n", salary);
  printf("%c \n", letter);

  return 0;
}
```

---

```C
#include <stdio.h>

int main() {
  const double PI = 3.14; // constant stores a value that cannot be changed from initiation
  printf("%f", PI);
    
  return 0;
}
```

```C
#include <stdio.h>

#define PI 3.14 // preprocessor directive `define`

int main() {
  printf("%f", PI);
  return 0;
}
// The difference between const and #define is that the former uses memory for storage and the latter does not.
```

---

```C
#include <stdio.h>

int main() {
  char a = getchar(); // returns the value of the next single character input

  printf("You entered: %c", a);

  return 0;
}
```

```C
#include <stdio.h>

int main() {
  char a[100];

  gets(a); // read input as an ordered sequence of characters(string)

  printf("You entered: %s", a);

  return 0;
}
```

```C
#include <stdio.h>

int main() {
  int a, b;
  printf("Enter two numbers:");
  scanf("%d %d", &a, &b); // &: address operator(location in memory of a variable)
  // scanf places an input value at a variable address, stops reading as soon as 'space' comes in

  printf("\nSum: %d", a+b);

  return 0;
}
```

---

```C
#include <stdio.h>

int main() {
  char a = getchar();

  printf("You entered: ");
  putchar(a); // outputs a single character

  return 0;
} 
```

```C
#include <stdio.h>

int main() {
  char a[100];

  gets(a); 

  printf("You entered: ");
  puts(a); // string

  return 0;
} 
```

```C
#include <stdio.h>

int main() {
  int a, b;
  printf("Enter two numbers:");
  scanf("%d %d", &a, &b);

  printf("\nSum: %d", a+b); // possible to add inside

  return 0;
}
```

```C
int x;
float num;
char text[20];
scanf("%d %f %s", &x, &num, text); // waits for input and then make assignments
```

```C
printf("The tree has %d apples.\n", 22); // formatted input
/* The tree has 22 apples. */
printf("\"Hello World!\"\n");
/* "Hello World!" */ 
printf("Color: %s, Number: %d, float: %5.2f \n", "red", 42, 3.14159);
/* Color: red, Number: 42, float:  3.14  */
printf("Pi = %3.2f", 3.14159); 
/* Pi = 3.14 */
printf("Pi = %8.5f", 3.14159); 
/* Pi =   3.14159 */
printf("Pi = %-8.5f", 3.14159); 
/* Pi = 3.14159 */
printf("There are %d %s in the tree.", 22, "apples");
/* There are 22 apples in the tree. */ 
```

`%%` symbol for just %

---

```C
#include <stdio.h>

int main() {
  float price = 6.50;
  int increase = 2;
  float new_price;

  new_price = price + increase; // compiler will convert the int values to float values
  printf("New price is %4.2f", new_price);
  /* Output: New price is 8.50 */

  return 0;
}
```

```C
float average;
int total = 23;
int count = 4;

average = (float) total / count; // type casting
/* average = 5.75 */
```

---

```C
#include <stdio.h>

int main() {
  int y;
  int x = 3;

  y = (x >= 5) ?  5 : x; // conditional expression

/* This is equivalent to:
  if (x >= 5)
    y = 5;
  else
    y = x;
*/

  return 0;
}
```

```C
int num = 3;

  switch (num) {
  case 1:
  case 9: // can handle multiple cases at one labels
    printf("One\n");
    break; // without break; the program execution falls through to the next case statement
  case 2:
    printf("Two\n");
    break;   
  case 3:
    printf("Three\n");
    break;   
  default: // when no other matches are made
    printf("Not 1, 2, or 3.\n");
}
```

```C
#include <stdio.h>

int main() {
  int count = 1;
  
  do { // executes the loop statements before evaluating the expression; executes at least once
    printf("Count = %d\n", count);
    count++;
  } while (count < 8);
    
  return 0;
}
```

---

---

```C
#include <stdio.h>

int global1 = 0; // decalred outside all functions are global to the entire program
// including #define and etc.
// initialized

int main() {    
  int local1, local2;
  
  local1 = 5;
  local2 = 10;
  global1 = local1 + local2;
  printf("%d \n", global1);  /* 15 */
    
  return 0;
} 
```

```C
#include <stdio.h>

void say_hello();

int main() {    
  int i;

  for (i = 0; i < 5; i++) {
    say_hello();
  }
   
  return 0;
}

void say_hello() {
  static int num_calls = 1; 
    // have a local scope but are not destroyed when a function is exited
    // can be accessed every time the function is re-entered
    //initialized when declared and requires the prefix static

  printf("Hello number %d\n", num_calls);
  num_calls++;

} 
```

---

```C
void test(int k);

int main() {
  int i = 0;
    
  printf("The address of i is %x\n", &i); // hexadecimal(base-16, 0~F)
  test(i);
  printf("The address of i is %x\n", &i);
  test(i);

  return 0;
}

void test(int k) {
  printf("The address of k is %x\n", &k); // & address
}
```

```C
int j = 63;
int *p = NULL;
p = &j; 

printf("The address of j is %x\n", &j);
printf("p contains address %x\n", p);
printf("The value of j is %d\n", j);
printf("p is pointing to the value %d\n", *p); 
```

```C
int x = 5;
int y;
int *p = NULL;
p = &x;

y = *p + 2; /* y is assigned 7 */
y += *p;     /* y is assigned 12 */
*p = y;       /* x is assigned 12 */
(*p)++;      /* x is incremented to 13 */

printf("p is pointing to the value %d\n", *p);
```

```C
void swap (int *num1, int *num2);

int main() {
  int x = 25;
  int y = 100;

  printf("x is %d, y is %d\n", x, y); 
  swap(&x, &y);
  printf("x is %d, y is %d\n", x, y); 

  return 0;
}
 
void swap (int *num1, int *num2) {
  int temp;

  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
```

---

```C
int add_up (int *a, int num_elements);

int main() {
  int orders[5] = {100, 220, 37, 16, 98};

  printf("Total orders is %d\n", add_up(orders, 5)); 

  return 0;
}

int add_up (int *a, int num_elements) {
  int total = 0;
  int k;

  for (k = 0; k < num_elements; k++) {
    total += a[k];
  }

  return (total);
} 
```

```C
int * get_evens();

int main() {
  int *a;
  int k;

  a = get_evens(); /* get first 5 even numbers */
  for (k = 0; k < 5; k++)
    printf("%d\n", a[k]); // a[k] is the smae as *(a+k)

  return 0;
}

int * get_evens() {
  static int nums[5];
  int k;
  int even = 0;

  for (k = 0; k < 5; k++) {
    nums[k] = even += 2;
  }

  return (nums);
}
```

---

```C
#include <string.h>
strlen() - get length of a string
strcat() - merge two strings
strcpy() - copy one string to another
strlwr() - convert string to lower case
strupr() - conver string to upper case
strrev() - reverse string
strcmp() - compare two strings
```

```C
char first_name[25];
int age;
printf("Enter your first name and age: \n");
scanf("%s %d", first_name, &age); // read according to the format specifiers
// no need for & in string input because an array name acts as a pointer
```

```C
char full_name[50];
printf("Enter your full name: ");
gets(full_name); // reads input until a terminating newline(Enter key) -> possible for buffer overflow(happens when the string array isn't big enough for the typed text)
```

```C
char full_name[50];
printf("Enter your full name: ");
fgets(full_name, 50, stdin); // number of characters to read, and a pointer to where you want to read the string from
// stdin: standard input, which is the keyboard
// newline character is stored by fgets
```

```C
#include <stdio.h>
int main()
{
  char city[40];
  printf("Enter your favorite city: ");
  gets(city);
  // Note: for safety, use
  // fgets(city, 40, stdin);

  fputs(city, stdout); // requires the name of the string and a pointer to where you want to print the string
  printf(" is a fun city.");

  return 0;
}
```

```C
#include <stdio.h>
int main()
{
  char city[40];
  printf("Enter your favorite city: ");
  gets(city);
  // Note: for safety, use
  // fgets(city, 40, stdin);

  puts(city); // takes only a string argument, but adds a newline to output

  return 0;
}
```

---

```C
#include <stdio.h>
int main()
{
  char info[100];
  char dept[ ] = "HR";
  int emp = 75;
  sprintf(info, "The %s dept has %d employees.", dept, emp); // formatted string
  printf("%s\n", info);

  return 0;
}
```

```C
#include <stdio.h>
int main()
{
  char info[ ] = "Snoqualmie WA 13190";
  char city[50];
  char state[50];
  int population;
  sscanf(info, "%s %s %d", city, state, &population); // scanning a string for values; function reads values from a string and stores them at the corresponding variable addresses
  printf("%d people live in %s, %s.", population, city, state);

  return 0;
}
```

---

```C
#include <stdio.h>
#include <string.h>
/*
strlen(str) Returns the length of the string stored in str, not including the NULL character.
strcat(str1, str2) Appends (concatenates) str2 to the end of str1 and returns a pointer to str1.
strcpy(str1, str2) Copies str2 to str1. This function is useful for assigning a string a new value.

strncat(str1, str2, n) Appends (concatenates) first n characters of str2 to the end of str1 and returns a pointer to str1.
strncpy(str1, str2, n) Copies the first n characters of str2 to str1.
strcmp(str1, str2) Returns 0 when str1 is equal to str2, less than 0 when str1 < str2, and greater than 0 when str1 > str2.
strncmp(str1, str2, n) Returns 0 when the first n characters of str1 is equal to the first n characters of str2, less than 0 when str1 < str2, and greater than 0 when str1 > str2.
strchr(str1, c) Returns a pointer to the first occurrence of char c in str1, or NULL if character not found.
strrchr(str1, c) Searches str1 in reverse and returns a pointer to the position of char c in str1, or NULL if character not found.
strstr(str1, str2) Returns a pointer to the first occurrence of str2 in str1, or NULL if str2 not found.
*/

int main()
{
  char s1[ ] = "The grey fox";
  char s2[ ] = " jumped.";
    
  strcat(s1, s2); // appends (concatenates) str2 to the end of str1 and returns a pointer to str1
  printf("%s\n", s1);
  printf("Length of s1 is %d\n", strlen(s1));
  strcpy(s1, s2); // copies str2 to str1
  printf("s1 is now %s \n", s1);

  return 0;
}
```

```C
#include <stdio.h>
/*
int atoi(str) Stands for ASCII to integer. Converts str to the equivalent int value. 0 is returned if the first character is not a number or no numbers are encountered.
double atof(str) Stands for ASCII to float. Converts str to the equivalent double value. 0.0 is returned if the first character is not a number or no numbers are encountered.
long int atol(str) Stands for ASCII to long int. Converts str to the equivalent long integer value. 0 is returned if the first character is not a number or no numbers are encountered.
*/
#include <stdio.h>
int main()
{
  char input[10];
  int num;
    
  printf("Enter a number: ");
  gets(input);
  num = atoi(input); // converts string to numeric value

  return 0;
}
```

---

```C
char *trip[] = { // no limit to string length
  "suitcase",
  "passport",
  "ticket"
};

printf("Please bring the following:\n");
for (int i = 0; i < 3; i++) {
  printf("%s\n", trip[i]);
}
```

---

```C
#include <stdio.h>
void say_hello(int num_times); /* function */

int main() {
  void (*funptr)(int);  /* function pointer */ // parentheses around
  funptr = say_hello;  /* pointer assignment */
  funptr(3);  /* function call */
    
  return 0;
}

void say_hello(int num_times) {
  int k;
  for (k = 0; k < num_times; k++)
    printf("Hello\n");
}
```

```C
#include <stdio.h>

int add(int num1, int num2);
int subtract(int num1, int num2);
int multiply(int num1, int num2);
int divide(int num1, int num2);

int main() 
{
  int x, y, choice, result;
  int (*op[4])(int, int);

  op[0] = add;
  op[1] = subtract;
  op[2] = multiply;
  op[3] = divide;
  printf("Enter two integers: ");
  scanf("%d%d", &x, &y);
  printf("Enter 0 to add, 1 to subtract, 2 to multiply, or 3 to divide: ");
  scanf("%d", &choice);
  result = op[choice](x, y);
  printf("%d", result);
    
  return 0;
}

int add(int x, int y) {
  return(x + y);
}

int subtract(int x, int y) {
  return(x - y);
}

int multiply(int x, int y) {
  return(x * y);
}

int divide(int x, int y) {
  if (y != 0)
    return (x / y);
  else
    return 0;
}
```

```C
int x = 33;
float y = 12.4;
char c = 'a';
void *ptr; // void pointer
  
ptr = &x;
printf("void ptr points to %d\n", *((int *)ptr)); // needs to type cast first
ptr = &y;
printf("void ptr points to %f\n", *((float *)ptr));
ptr = &c;
printf("void ptr points to %c", *((char *)ptr));
```

```C
#include <stdio.h>

void* square (const void* num); // void pointer function

int main() {
  int x, sq_int;
  x = 6;
  sq_int = square(&x);
  printf("%d squared is %d\n", x, sq_int);

  return 0;
}

void* square (const void *num) {
  int result;
  result = (*(int *)num) * (*(int *)num);
  return result;
}
```

```C
#include <stdio.h>
#include <stdlib.h>

int compare (const void *, const void *); 

int main() {
  int arr[5] = {52, 23, 56, 19, 4};
  int num, width, i;
  
  num = sizeof(arr)/sizeof(arr[0]);
  width = sizeof(arr[0]);
  qsort((void *)arr, num, width, compare);
  for (i = 0; i < 5; i++)
    printf("%d ", arr[ i ]);
    
  return 0;
}

int compare (const void *elem1, const void *elem2) {
  if ((*(int *)elem1) == (*(int *)elem2))
    return 0;
  else if ((*(int *)elem1) < (*(int *)elem2))
    return -1;
  else
    return 1;
}
```

---

---

```C
struct course { // user defined data type that groups related variables
  int id;
  char title[40];
  float hours; 
}; 
```

```C
struct student {
  int age;
  int grade;
  char name[40];
};

struct student s1 = {19, 9, "John"};
struct student s2 = {22, 10, "Batman"};

struct student s1;
s1 = (struct student) {19, 9, "John"}; // using typecast

struct student s1 
= { .grade = 9, .age = 19, .name = "John"}; 
```

```C
#include <stdio.h>
#include <string.h>

struct course {
  int id;
  char title[40];
  float hours; 
};

int main() {
  struct course cs1 = {341279, "Intro to C++", 12.5};
  struct course cs2;

  /* initialize cs2 */
  cs2.id = 341281;
  strcpy(cs2.title, "Advanced C++");
  cs2.hours = 14.25;
   
  /* display course info */
  printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
  printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);
  
  return 0;
}
```

---

```C
typedef struct { // eliminates the need to use the keyword struct when declaring variables
  int id;
  char title[40];
  float hours; 
} course; // name of the struct

course cs1; // structure tag is no longer used
course cs2; 
```

```C
typedef struct {
  int x;
  int y;
} point;

typedef struct {
  float radius;
  point center; // member of a structure may also be structures
} circle; 

circle c = {4.5, {1, 3}};
printf("%3.1f %d,%d", c.radius, c.center.x, c.center.y);
/* 4.5  1,3 */
```

---

```C
struct myStruct *struct_ptr;
// defines a pointer to the myStruct structure.

struct_ptr = &struct_var;
// stores the address of the structure variable struct_var in the pointer struct_ptr.

struct_ptr -> struct_mem;
// accesses the value of the structure member struct_mem.
```

```C
struct student{
  char name[50];
  int number;
  int age;
};

// Struct pointer as a function parameter
void showStudentData(struct student *st) {
  printf("\nStudent:\n");
  printf("Name: %s\n", st->name);
  printf("Number: %d\n", st->number);
  printf("Age: %d\n", st->age);
}
 
struct student st1 = {"Krishna", 5, 21};
showStudentData(&st1);
```

```C
#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char title[40];
  float hours; 
} course;

void update_course(course *class);
void display_course(course class);

int main() {
  course cs2;
  update_course(&cs2); // takes a pointer as the parameter
  display_course(cs2); // takes the structure by value
  return 0;
}

void update_course(course *class) {
  strcpy(class->title, "C++ Fundamentals");
  class->id = 111;
  class->hours = 12.30;
}

void display_course(course class) {
  printf("%d\t%s\t%3.2f\n", class.id, class.title, class.hours);
}
```

```C
#include <stdio.h>

typedef struct {
  int h;
  int w;
  int l;
} box;

int main() {
  box boxes[3] = {{2, 6, 8}, {4, 6, 6}, {2, 6, 9}};
  int k, volume;
  
  for (k = 0; k < 3; k++) {
    volume = boxes[k].h*boxes[k].w*boxes[k].l; // . used to access members of the element
    printf("box %d volume %d\n", k, volume);
  }
  return 0;
}
```

---

```C
union val { // allows to store different data types in the same memory location
    // different from structures in that it uses the same memory location for all its member
    // used for memory management
    // largest member data type is used to determine the size of the memory to share and then all members use this one location
    // this process also helps limit memory fragmentation
  int int_num;
  float fl_num;
  char str[20]; 
};

union val u1;
union val u2;
u2 = u1; // you can assign one union to another of the same type
// assigning values overrides the previous
```

```C
union val {
  int int_num;
  float fl_num;
  char str[20]; 
};
  
union val test;

test.int_num = 123; // access the members of a union variable
test.fl_num = 98.76;
strcpy(test.str, "hello");

printf("%d\n", test.int_num);
printf("%f\n", test.fl_num);
printf("%s\n", test.str); // last assignment overrides previous assignments, which is why str stores a value and accessing int_num and fl_num is meaningless
```

```C
typedef struct {
  char make[20];
  int model_year;
  int id_type; /* 0 for id_num, 1 for VIN */
  union { // union inside structure
    int id_num;
    char VIN[20]; 
  } id; // union name required at the end of the declaration
} vehicle;

vehicle car1;
strcpy(car1.make, "Ford");
car1.model_year = 2017;
car1.id_type = 0;
car1.id.id_num = 123098; // union member
```

---

```C
union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

union val info; 
union val *ptr = NULL; // points to the memory location allocated to the union
ptr = &info;
ptr->int_num = 10; // access the union members through a pointer(--> operator required)
// (*ptr).int_num == ptr->int_num
printf("info.int_num is %d", info.int_num); 
```

```C
union id {
  int id_num;
  char name[20]; 
};

void set_id(union id *item) { // func can have union parameters that accept arguments by value
    // for a func to change the actual value in a union mem loc, pointer parameters are required
  item->id_num = 42;
}

void show_id(union id item) {
  printf("ID is %d", item.id_num);
} 
```

```C
union val {
  int int_num;
  float fl_num;
  char str[20]; 
};

union val nums[10]; // array can store unions
int k;

for (k = 0; k < 10; k++) {
  nums[k].int_num = k; // accessible with the index number
}

for (k = 0; k < 10; k++) {
  printf("%d  ", nums[k].int_num);
} 
```

---

---

## Memory Management

> stack - automatic allocation of memory
>
> heap -  a pool of memory used for dynamic memory allocation

* when you declare a variable using a basic data type, C automatically allocates space for the variable in an area of memory called the **stack**

```C
int x; // int allocated 4 bytes
printf("%d", sizeof(x)); /* output: 4 */
```

* an array with a specified size is allocated *contiguous blocks* of memory with each block the size for one element

```C
int arr[10]; // int(4bytes)*10 == 40bytes
printf("%d", sizeof(arr)); /* output: 40 */
```

* so long as your program explicitly declares a basic data type or an array size, memory is automatically managed
* **Dynamic memory allocation** is the process of allocating and freeing memory as needed
  * can prompt at runtime for the number of array elements and then create an array with that many elements
  * dynamic memory is managed with pointers that point to newly allocated blocks of memory in an area called the **heap**
* in addition, there is **statically managed data** in main memory for variables that persist for the lifetime of the program

* `stdlib.h` library includes memory management functions

```C
malloc(bytes) // Returns a pointer to a contiguous block of memory that is of size bytes.

calloc(num_items, item_size) // Returns a pointer to a contiguous block of memory that has num_items items, each of size item_size bytes. Typically used for arrays, structures, and other derived data types. The allocated memory is initialized to 0.

realloc(ptr, bytes) // Resizes the memory pointed to by ptr to size bytes. The newly allocated memory is not initialized.

free(ptr) // Releases the block of memory pointed to by ptr. When you no longer need a block of allocated memory
```



#### malloc

* `malloc()`
  * allocates a specified number of contiguous bytes in memory

```C
#include <stdlib.h>

int *ptr;
/* a block of 10 ints */
ptr = malloc(10 * sizeof(*ptr)); // returns a pointer to the allocateed memory

if (ptr != NULL) {
  *(ptr + 2) = 50;  // assign 50 to third int - can be views as an array
}

free(ptr); // release memory for later use
```

* allocated memory is contiguous and can be treated as an `array`
* pointer arithmetic is used to traverse the array instead of using brackets
* if the allocation is unsuccessful, `NULL` is returned - need to include code to check for a `NULL` pointer

* `free()`
  * release memory for later use



#### calloc & realloc

* `calloc()` - allocates memory based on the size of a specific item, such as a sturcture

```C
typedef struct {
  int num;
  char *info; // using a pointer for the info member allows any length string to be stored
} record;

record *recs;
int num_recs = 2;
int k;
char str[ ] = "This is information";

recs = calloc(num_recs, sizeof(record)); // allocates blocks of memory within a contiguous block of memory for an array of stucture elements
if (recs != NULL) {
  for (k = 0; k < num_recs; k++) {
    (recs+k)->num = k;
    (recs+k)->info = malloc(sizeof(str));
    strcpy((recs+k)->info, str);
  }
} 
```

* dynamically allocated structures are the basis of *linked lists* and *binary trees* as well as other data structures

* `realloc()` - expands a current block to include additional memory

```C
int *ptr;
ptr = malloc(10 * sizeof(*ptr));  
if (ptr != NULL) {
  *(ptr + 2) = 50;  /* assign 50 to third int */
}
ptr = realloc(ptr, 100 * sizeof(*ptr)); // leaves the original content in memory, but expands the block to allow for more storage
*(ptr + 30) = 75; 
```



#### Allocating memory for strings

* when allocating memory for a string pointer, you may want to use string length rather than the `sizeof` operator for calculating bytes

```C
char str20[20];
char *str = NULL;

strcpy(str20, "12345");
str = malloc(strlen(str20) + 1); // better memory management because you aren't allocating more space than is needed to a pointer.
// When using strlen to determine the number of bytes needed for a string, be sure to incldue one extra byte for the NULL character '\0'
// a char is always one byte, so there is no need to multiply the memory requirements by sizeof(char)
strcpy(str, str20);
printf("%s", str); 
```



#### Dynamic arrays

* many algorithms implement a dynamic array because this allows the number of elements to grow as needed
* typically use a structure to keep track of current array size, current capacity, and a pointer to the elements

```C
typedef struct {
  int *elements; // pointer to the elements
  int size; // array size
  int cap; // array capacity
} dyn_array;

dyn_array arr;

/* initialize array */
arr.size = 0;
arr.elements = calloc(1, sizeof(arr.elements));
arr.cap = 1;  /* room for 1 element */

// to expand by more elements
arr.elements = realloc(arr.elements, (5 + arr.cap) * sizeof(arr.elements));
if (arr.elements != NULL)
  arr.cap += 5; /* increase capacity */ 

// adding an element to the array increases its size
if (arr.size < arr.cap) {
  arr.elements[arr.size] = 50;
  arr.size++;
} else {
  printf("Need to expand the array.");
}
```

---

---

#### exit

```C
int x = 10;
int y = 0;

if (y != 0)
  printf("x / y = %d", x/y);
else {
  printf("Divisor is 0. Program exiting.");
  exit(EXIT_FAILURE); // avoid a program crash - closes any open file connections and processes
} 
```

---

---

## Preprocessor

