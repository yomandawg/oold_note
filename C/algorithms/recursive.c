#include <stdio.h>

int rec(int n) {
    printf("%d\n", n);
    if (n <= 0) return 0;
    rec(0);
}

int rec2(int n) {
    printf("%d\n", n);
    if (n <= 0) return 0;
    rec(n-1);
    return 0;
}

int main() {
    rec(3); // 3 0
    rec2(3); // 3 2 1 0
    return 0;
}