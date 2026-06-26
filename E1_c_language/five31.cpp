#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int main(void) {
    printf("%d\n", gcd(12, 8));
    printf("%d \n", gcd(-12, 8));
    printf("%d \n", gcd(100, 25));
    printf("%d \n", gcd(0, 5));
    printf("%d \n", gcd(7, 5));
}