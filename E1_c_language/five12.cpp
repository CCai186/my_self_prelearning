#include <stdio.h>
#include <math.h>

double myround(double x) {
    return floor(x + 0.5);
}

int main(void) {
    printf("%f \n", myround(-3.51));
    printf("%f \n", myround(4.49));
    printf("%f \n", myround(3.5));
    printf("%f \n", myround(-2.5));
    printf("%f \n", myround(-3.5));

    return 0;
}