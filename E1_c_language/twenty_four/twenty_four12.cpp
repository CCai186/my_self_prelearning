#include <stdio.h>
#include <stddef.h>

static int is_blank(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char *shrink_space(char *dest, const char *src, size_t n)
{
    if (n == 0)
        return dest;

    char *dst = dest;
    const char *src_ptr = src;
    int in_space = 0;

    while (*src_ptr != '\0' && (size_t)(dst - dest) < n - 1) {
        char c = *src_ptr;
        if (is_blank(c)) {
            if (!in_space) {
                *dst++ = ' ';
                in_space = 1;
            }
        } else {
            *dst++ = c;
            in_space = 0;
        }
        src_ptr++;
    }

    *dst = '\0';
    return dest;
}

int main(void)
{
    const char input[] = 
        "This Content hoho       is ok\n"
        "        ok?\n"
        "\n"
        "        file system\n"
        "uttered words   ok ok      ?\n"
        "end.";

    char buf[256];
    shrink_space(buf, input, sizeof(buf));

    printf("原字符串：\n%s\n\n", input);
    printf("压缩后：\n%s\n", buf);
    return 0;
}