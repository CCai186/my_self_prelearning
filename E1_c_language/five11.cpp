#include <stdio.h>

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int main(void) {
    printf("%d \n", is_leap_year(2000));
    printf("%d \n", is_leap_year(1999));
    printf("%d \n", is_leap_year(2004));
    
    return 0;
}