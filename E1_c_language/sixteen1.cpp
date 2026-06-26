#include <stdio.h>

int countbit(unsigned int x)
{
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

unsigned int multiply(unsigned int x, unsigned int y)
{
    unsigned int result = 0;
    while (y) {
        if (y & 1) {
            result += x;
        }
        x <<= 1;
        y >>= 1;
    }
    return result;
}

unsigned int rotate_right(unsigned int x, int n)
{
    n %= 32;
    if (n == 0) return x;
    return (x >> n) | (x << (32 - n));
}

int main()
{
    printf("countbit测试\n");
    printf("0x00 中1的个数: %d\n", countbit(0));
    printf("0xFF 中1的个数: %d\n", countbit(0xFF));
    printf("0xFFFFFFFF 中1的个数: %d\n\n", countbit(0xFFFFFFFF));

    printf("multiply测试\n");
    printf("3 * 5 = %u\n", multiply(3, 5));
    printf("12 * 10 = %u\n", multiply(12, 10));
    printf("0 * 100 = %u\n\n", multiply(0, 100));

    printf("rotate_right测试\n");
    printf("0x12345678 右移4位: 0x%08X\n", rotate_right(0x12345678, 4));
    printf("0x00000001 右移1位: 0x%08X\n", rotate_right(1, 1));
    printf("0x80000000 右移1位: 0x%08X\n", rotate_right(0x80000000, 1));

    return 0;
}