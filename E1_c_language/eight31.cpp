#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
int a[N]; // 存随机数的全局数组

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
}

int main(void)
{
    srand(time(NULL));
    gen_random(10);

    // 统计直方图
    int histogram[10] = {0};
    for (int i = 0; i < N; i++)
    {
        histogram[a[i]]++;
    }

    // 可视化直方图
    // 找到最大的次数，确定高度
    int max_height = 0;
    for (int i = 0; i < 10; i++)
    {
        if (histogram[i] > max_height)
            max_height = histogram[i];
    }

    // 最高行开始往下打印
    for (int h = max_height; h >= 1; h--)
    {
        for (int i = 0; i < 10; i++)
        {
            if (histogram[i] >= h)
                printf("*  ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // 最后打印横轴的数字
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ", i);
    }
    printf("\n");

    return 0;
}