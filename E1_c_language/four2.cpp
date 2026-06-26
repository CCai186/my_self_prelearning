#include <stdio.h>
#include <stdlib.h>

void print_digits(int x) {
    int digit_unit = abs(x % 10);
    int digit_ten = abs((x / 10) % 10);
    printf("数字%d的个位是：%d，十位是：%d\n", x, digit_unit, digit_ten);
}

int main(void)
{
    print_digits(123);
    print_digits(-45);
    print_digits(6);
    print_digits(78);
    print_digits(-9);
    return 0;
}