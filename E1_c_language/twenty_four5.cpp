#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_sort(void *base, size_t nmemb, size_t size,
                 int (*cmp)(const void *, const void *))
{
    char *arr = (char *)base;
    char *tmp = (char *)malloc(size);
    if (tmp == NULL) return;

    for (size_t i = 1; i < nmemb; i++) {
        memcpy(tmp, arr + i * size, size);
        size_t j = i;
        while (j > 0 && cmp(arr + (j - 1) * size, tmp) > 0) {
            memcpy(arr + j * size, arr + (j - 1) * size, size);
            j--;
        }
        memcpy(arr + j * size, tmp, size);
    }
    free(tmp);
}

void *binary_search(const void *key, const void *base, size_t nmemb,
                    size_t size, int (*cmp)(const void *, const void *))
{
    const char *arr = (const char *)base;
    size_t low = 0, high = nmemb;

    while (low < high) {
        size_t mid = low + (high - low) / 2;
        const void *mid_elem = arr + mid * size;
        int ret = cmp(key, mid_elem);
        if (ret == 0)
            return (void *)mid_elem;
        else if (ret < 0)
            high = mid;
        else
            low = mid + 1;
    }
    return NULL;
}

int cmp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int nums[] = {12, 3, 7, 22, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("排序前：");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    insert_sort(nums, n, sizeof(int), cmp_int);

    printf("排序后：");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    int target = 7;
    int *found = (int *)binary_search(&target, nums, n, sizeof(int), cmp_int);
    printf("查找%d：%s\n", target, found ? "找到" : "未找到");

    target = 100;
    found = (int *)binary_search(&target, nums, n, sizeof(int), cmp_int);
    printf("查找%d：%s\n", target, found ? "找到" : "未找到");

    return 0;
}