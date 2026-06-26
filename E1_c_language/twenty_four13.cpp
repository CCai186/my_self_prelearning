#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    uint64_t total = 0;
    const size_t step = 1024 * 1024;
    void *p;
    while (1) {
        total += step;
        *(char *)p = 0;
    }

    return 0;
}