#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
    int pivot = a[start];
    int i = start;
    int j = end;

    while (i < j) {
        while (i < j && a[j] >= pivot)
            j--;
        while (i < j && a[i] <= pivot)
            i++;
        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[start] = a[i];
    a[i] = pivot;
    return i;
}

int order_statistic(int start, int end, int k)
{
    int mid = partition(start, end);
    int rank = mid - start + 1;

    if (k == rank) {
        return a[mid];
    } else if (k < rank) {
        return order_statistic(start, mid - 1, k);
    } else {
        return order_statistic(mid + 1, end, k - rank);
    }
}

int main(void)
{
    printf("第1小：%d\n", order_statistic(0, LEN-1, 1));
    printf("第3小：%d\n", order_statistic(0, LEN-1, 3));
    printf("第5小：%d\n", order_statistic(0, LEN-1, 5));
    return 0;
}