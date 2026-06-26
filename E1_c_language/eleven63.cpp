#include <stdio.h>

double mypow_loop(double x, int n)
{
    double result = 1.0;
    double base = x;

    while (n > 0) {
        if (n % 2 == 1) {
            result *= base;
        }
        base *= base;
        n = n / 2;
    }

    return result;
}

double mypow_recursive(double x, int n)
{
    if (n == 0)
        return 1.0;

    double half = mypow_recursive(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return half * half * x;
    }
}

int main(void)
{
    printf("2^10循环 = %.0f\n", mypow_loop(2, 10));
    printf("2^10递归 = %.0f\n", mypow_recursive(2, 10));
    printf("3^5循环 = %.0f\n", mypow_loop(3, 5));
    return 0;
}