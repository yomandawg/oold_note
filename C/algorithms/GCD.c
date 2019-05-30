// greatest common divisor - 최대공약수

#include <stdio.h>

int gcd(int a, int b) {
    if (!a) return b;
    if (!b) return a;

    if (a == b) return a;

    if (a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}

int gcd_eff(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


int main() {
    int a = 98, b = 56;
    printf("GCD of %d and %d is %d", a, b, gcd(a, b));
    return 0;
}