#include <stdio.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int binarysearch_first(int number)
{
    int mid, start = 0, end = LEN - 1;

    while (start <= end) {
        mid = start + (end - start) / 2;

        if (a[mid] < number) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (start < LEN && a[start] == number) {
        return start;
    } else {
        return -1;
    }
}

int main(void)
{
    printf("左边界折半查找\n");
    printf("2，第一次出现的下标：%d\n", binarysearch_first(2));
    printf("5，第一次出现的下标：%d\n", binarysearch_first(5));
    printf("0（不存在），结果：%d\n", binarysearch_first(0));
    printf("9（末尾元素），第一次出现的下标：%d\n", binarysearch_first(9));
    printf("1（开头元素），第一次出现的下标：%d\n", binarysearch_first(1));

    return 0;
}