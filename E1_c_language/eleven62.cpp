#include <stdio.h>
#include <math.h>

double mysqrt(double y)
{
    double start, end, mid;
    const double eps = 0.001;

    if (y >= 1) {
        start = 0;
        end = y;
    } else {
        start = y;
        end = 1;
    }

    while (end - start > eps) {
        mid = (start + end) / 2;
        double square = mid * mid;

        if (square < y) {
            start = mid;
        } else {
            end = mid;
        }
    }

    return (start + end) / 2;
}

int main(void)
{
    printf("sqrt(4) = %.3f\n", mysqrt(4));
    printf("sqrt(2) = %.3f\n", mysqrt(2));
    printf("sqrt(0.25) = %.3f\n", mysqrt(0.25));
    return 0;
}