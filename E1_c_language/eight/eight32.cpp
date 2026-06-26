#include <stdio.h>

#define N 3
#define M 2

int a[N] = {1, 2, 3}; // 原始数组
int result[M];        // 存组合结果

// 打印数组的前len个元素
void print_part(int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 全排列（N==M）
void permute_all(int start)
{
    if (start == N)
    {
        print_part(N);
        return;
    }

    for (int i = start; i < N; i++)
    {
        int temp = a[start];
        a[start] = a[i];
        a[i] = temp;
        permute_all(start + 1);
        temp = a[start];
        a[start] = a[i];
        a[i] = temp;
    }
}

// 从N个里取M个
void permute_nm(int start)
{
    if (start == M)
    {
        print_part(M);
        return;
    }
    for (int i = start; i < N; i++)
    {
        int temp = a[start];
        a[start] = a[i];
        a[i] = temp;

        permute_nm(start + 1);

        temp = a[start];
        a[start] = a[i];
        a[i] = temp;
    }
}

// 从N个里取M个
void combine(int start, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i < N; i++)
    {
        result[depth] = a[i];
        combine(i + 1, depth + 1);
    }
}

int main(void)
{
    printf("全排列（N=%d）：\n", N);
    permute_all(0);

    printf("\n从N=%d里取M=%d：\n", N, M);
    permute_nm(0);

    printf("\n从N=%d里取M=%d：\n", N, M);
    combine(0, 0);

    return 0;
}