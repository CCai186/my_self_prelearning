#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int find_second_min(void)
{
    int first_min, second_min;
    if (a[0] < a[1]) {
        first_min = a[0];
        second_min = a[1];
    } else {
        first_min = a[1];
        second_min = a[0];
    }

    for (int i = 2; i < LEN; i++) {
        int x = a[i];
        if (x < first_min) {
            second_min = first_min;
            first_min = x;
        } else if (x < second_min) {
            second_min = x;
        }
    }
    return second_min;
}

int main(void)
{
    printf("第二小值是：%d\n", find_second_min());
    return 0;
}