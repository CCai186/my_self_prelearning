#include <stdio.h>
#include <stdlib.h>

// 循环 GCD
int gcd_loop(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a % b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

// 循环 Fibonacci
int fib_loop(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int a = 1, b = 1;
    int i = 2;
    while (i <= n) {
        int next = a + b;
        a = b;
        b = next;
        i++;
    }
    return b;
}

// test
int main(void) {
    // test GCD
    printf("=== GCD ===\n");
    printf("gcd_loop(12, 8) = %d\n", gcd_loop(12, 8));
    printf("gcd_loop(-12, 8) = %d\n", gcd_loop(-12, 8));

    // test Fibonacci
    printf("\n=== Fibonacci ===\n");
    printf("fib_loop(0) = %d\n", fib_loop(0));
    printf("fib_loop(1) = %d\n", fib_loop(1));
    printf("fib_loop(5) = %d\n", fib_loop(5));

    return 0;
}