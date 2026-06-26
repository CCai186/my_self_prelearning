#include <stdio.h>
#include <stdarg.h>

static void print_int(long long num)
{
    char buf[20];
    int i = 0, neg = 0;

    if (num < 0) {
        neg = 1;
        num = -num;
    }
    if (num == 0)
        buf[i++] = '0';
    while (num > 0) {
        buf[i++] = '0' + num % 10;
        num /= 10;
    }
    if (neg) putchar('-');
    while (i > 0) putchar(buf[--i]);
}

static void print_double(double d)
{
    int neg = 0;
    if (d < 0) {
        neg = 1;
        d = -d;
    }
    long long intp = (long long)d;
    long long frac = (long long)((d - intp) * 1000000.0 + 0.5);
    if (frac >= 1000000) {
        intp++;
        frac -= 1000000;
    }
    if (neg) putchar('-');
    print_int(intp);
    putchar('.');
    char fbuf[6];
    for (int j = 5; j >= 0; j--) {
        fbuf[j] = '0' + frac % 10;
        frac /= 10;
    }
    for (int j = 0; j < 6; j++) putchar(fbuf[j]);
}

void myprintf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                    print_int(va_arg(ap, int));
                    break;
                case 'f':
                    print_double(va_arg(ap, double));
                    break;
                case '%':
                    putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    break;
            }
        } else {
            putchar(*format);
        }
        format++;
    }
    va_end(ap);
}

int main(void)
{
    myprintf("整数: %d %d\n", 123, -456);
    myprintf("浮点数: %f\n", 3.14159);
    myprintf("百分比: 100%%\n");
    return 0;
}