#include <stdio.h>

int main() {
    char a = getchar(); // returns the value of the next single char input

    printf("You entered: %c\n", a); // the input is stored in a


    char b[100]; // char array: string
    gets(b); // read input as an ordered sequence of characters, also called a string

    printf("You enterd: %s\n", b); // a string is stored in a char array


    int c;
    scanf("%d", &c); // scans input that matches format specifiers
    // & sign is the address operator
    // gives the address, or location in memory, of a variable
    // this is needed because scanf places an input value at a variable address
    printf("you enterd: %d\n", c);

    int d, e;
    printf("Enter two numbers:");
    scanf("%d %d", &d, &e); // stops reading as soon as it encounters a space, so text such as "Hello World" is two separate inputs for scanf()
    printf("\nSum: %d", d+e);


    char A = getchar();
    printf("You entered: ");
    putchar(A); // outputs a single character


    char B[100];
    gets(B);
    printf("You entered: ");
    puts(B); // displace output as a string


    int C;
    scanf("%d", &C); // scans input that matches format specifiers
    printf("You enterd: %d", C);


    int x;
    float num;
    char text[20];
    scanf("%d %f %s", &x, &num, text);
    // a call to scanf function scans input according to format specifiers that convert input as necessary
    // if input can't be converted, then the assignment isn't made
    // & must be used to access the variable addresses
    // & isn't needed for a string because a string name acts as a pointer
    
    // Format specifiers begin with a percent sign % and are used to assign values to corresponding arguments after the control string.
    // Blank, tabs, and newlines are ignored.
    // A format specifier can include several options along with a conversion character:
    //  %[*][max_field]conversion character
    // The optional * will skip the input field
    // The optional max_width gives the maximum number of characters to assign to an input field
    // The conversion character converts the argument, if necessary, to the indicated type:
    // d decimal // c character // s string // f float // x hexadecimal

    int q, w;
    char text2[20];

    scanf("%2d %d %*f %5s", &q, &w, text2);
    // take the first two int, take the rest, ignore float, max_length of 5 string
    // input: 1234 5.7 elephant
    printf("%d %d %s", q, w, text2);
    // output: 12 34 eleph

    // printf function requires a format string which can include escape sequences for outputting speicial characters and format specifiers that are replaced by values
    printf("The tree has %d apples.\n", 22);
    printf("\"Hello World!\"\n");
    // \n new line
    // \t horizontal tab
    // \b backspace
    // \' single quote
    // \" double quote

    // format specifiers begin with a percent sign % and are replcaed by corresponding arguments after the format string.
    // A format specifier can inlude several options along with a conversion character
    // %[-][width].[precision]conversion character
    // The optional - specifies left alignment of the data in the string
    // the optional width gives the minumum number of characters for the data
    // the period . separates the width from the precision
    // the optional precision gives the number of decimal places for numeric data.
    // if s is used as the conversion character, then precision determines the number of characters to print
    // the conversion character converts the arguemnt, if necessary, to the indicated type:
    // d decimal
    // c character
    // s string
    // f float
    // s scientific notation
    // x hexadecimal

    printf("Color: %s, Number: %d, float: %5.2f\n", "red", 42, 3.14159);
    // Color: red, Number: 42, float: 3.14
    printf("Pi = %3.2f", 3.14159);
    // Pi = 3.14
    printf("Pi = %8.5f", 3.14159);
    // Pi = 3.14159
    printf("Pi = %-8.5f", 3.14159);
    // Pi =3.14159
    printf("There are %d %s in the tree.", 22, "apples");
    // There are 22 apples in the tree.


    // Type Conversion
    // in an operation involving both floats and ints, the compiler will convert the int values to float values
    // when you want to force the result of an expression to a different type you can perform explicit type conversion by type casting, as in the statements
    float average;
    int total = 23;
    int count = 4;
    average = (float) total/count;
    // average = 5.75
    // without the type casting, average will be assigned 5

    return 0;
}