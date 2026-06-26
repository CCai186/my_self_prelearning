#include <stdio.h>
int main(void)
{
    int x, n, result;

    // x=17,n=4，预期5
    x=17, n=4;
    result = (x + n -1)/n;
    printf("x=%d,n=%d，向上取整结果：%d\n", x,n,result);
    
    return 0;
}