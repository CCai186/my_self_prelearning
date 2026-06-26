#include <stdio.h>

int main(void)
{
    // 定义两个数组：源数组、目标数组
    // 类型、长度完全一致
    int source[5] = {10, 20, 30, 40, 50};
    int target[5];
    int len = 5;

    // 逐个元素拷贝
    for (int i = 0; i < len; i++) {
        target[i] = source[i];
    }

    // 测试
    // 源数组
    printf("=== 源数组 ===\n");
    for (int i = 0; i < len; i++) {
        printf("source[%d] = %d\n", i, source[i]);
    }

    // 拷贝后的目标数组
    printf("\n=== 拷贝后的目标数组 ===\n");
    for (int i = 0; i < len; i++) {
        printf("target[%d] = %d\n", i, target[i]);
    }

    // 验证：两个数组是完全独立的
    printf("\n=== 修改源数组的第一个元素 ===\n");
    source[0] = 999;
    printf("修改 source[0] = %d\n", source[0]);
    printf("目标 target[0]  = %d\n", target[0]);

    return 0;
}