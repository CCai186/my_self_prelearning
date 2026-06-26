#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int find_min(void)
{
    int min = a[0];
    for (int i = 1; i < LEN; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main(void)
{
    printf("最小值是：%d\n", find_min());
    return 0;
}