#include <stdio.h>
#include <stdlib.h>

// 计数：1~100中出现数字9的次数
int count_9() {
    int count = 0;  // 累加器
    int i = 1;  // 循环变量
    while (i <= 100) {
        // 个位 9
        int digit_unit = i % 10;
        if (digit_unit == 9) {
            count++;
        }
        // 十位 9
        int digit_ten = (i / 10) % 10;
        if (digit_ten == 9) {
            count++;
        }
        i++; // +1
    }
    return count;
}

int main(void) {
    printf("1~100中9的个数：%d\n", count_9());

    return 0;
}