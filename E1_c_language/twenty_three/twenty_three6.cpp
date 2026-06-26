#include <stdio.h>

void test_const_char_pp()
{
    printf("const char **p\n");
    const char *p1 = "hello";
    const char *p2 = "world";

    const char **p = &p1;

    p = &p2;
    printf("改p，**p = %c\n", **p);

    *p = "new string";
    printf("改*p，*p = %s\n", *p);

    printf("**p只读，p和*p均可改指向\n\n");
}

void test_char_const_pp()
{
    printf("char *const *p\n");
    char str1[] = "hello";
    char str2[] = "world";
    char *const p1 = str1;
    char *const p2 = str2;

    char *const *p = &p1;

    p = &p2;
    printf("改p，**p = %c\n", **p);

    **p = 'A';
    printf("改**p，str2 = %s\n", str2);

    printf("*p只读，p和**p均可改指向\n\n");
}

void test_char_p_const_p()
{
    printf("char **const p\n");
    char str1[] = "hello";
    char str2[] = "world";
    char *p1 = str1;
    char *p2 = str2;

    char **const p = &p1;

    *p = str2;
    printf("改*p，**p = %c\n", **p);

    **p = 'B';
    printf("改**p，str2 = %s\n", str2);

    printf("p只读，*p和**p均可改指向\n\n");
}

int main(void)
{
    test_const_char_pp();
    test_char_const_pp();
    test_char_p_const_p();
    return 0;
}