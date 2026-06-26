#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *ret = dest;
    while ((*dest++ = *src++) != '\0');
    return ret;
}
int main(void)
{
    char buf[100];
    my_strcpy(buf, "Hello, strcpy!");
    printf("拷贝结果：%s\n", buf);
    return 0;
}