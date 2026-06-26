#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int prime = 1;
    int i;
    // 检查到sqrt(n)够了
    for (i = 2; i <= sqrt(n) && prime; i++) {
        if (n % i == 0) {
            prime = 0;
        }
    }
    return prime;
}

int main(void)
{
    int i;
    for (i = 1; i <= 100; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}