#include <stdio.h>
void increment(int x)
{
	x = x + 1;
	printf("函数里，x变成：%d\n", x);
}
int main(void)
{
	int i = 1, j = 2;
	printf("调用前，i是：%d\n", i);
	increment(i);
	printf("调用后，i是：%d\n", i);
	return 0;
}