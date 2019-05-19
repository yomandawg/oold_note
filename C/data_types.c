#include <stdio.h>

#define YO 3.2 // another way to define constant

int main() {
    printf("int: %d\n", sizeof(int));
    printf("float: %d\n", sizeof(float));
    printf("double: %d\n", sizeof(float));
    printf("char: %d\n", sizeof(char));
    // C does not have a boolean type

    int my_var; // snake-case
    my_var = 42;
    // C is case-sensitive
    int myVar = 42;

    int a, b;
    float salary = 56.23;
    char letter = 'Z';
    a = 8;
    b = 34;
    int c = a+b;

    printf("%d\n", c);
    printf("%f\n", salary); // %f format specifier for float
    printf("%c\n", letter); // %c for char

    const double PI = 3.14;
    // constant stores a value that cannot be changed from its initial assignment
    // by using constants with meaningful names, code is easier to read and understand.
    // To distinguish constants from variables, a common practice is to use uppercase identifiers
    // the value of PI cannot be changed during program execution
    // constants must be initialized with a value when declared
    printf("%f\n", PI);
    printf("%f\n", YO);

    // before compilation, the preprocessor replaces every macro identifier in the code with its corresponding value from the directive
    // every occurrence of PI is replaced with 3.14
    // the final code sent to the compiler will already have the constant values in place
    // the difference between const and #define is that the former uses memory for storage and the latter does not

    return 0;
}