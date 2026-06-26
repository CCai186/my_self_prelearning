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

void quicksort(int start, int end)
{
    int mid;
    if (end > start) {
        mid = partition(start, end);
        quicksort(start, mid - 1);
        quicksort(mid + 1, end);
    }
}

int main(void)
{
    quicksort(0, LEN - 1);
    for (int i = 0; i < LEN; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}