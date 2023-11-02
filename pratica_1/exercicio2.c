#include <stdio.h>


void main() {
    float a = 3.14159, b = 2.71828;

    float temp = a;
    a = b;
    b = temp;

    printf("\nPI = %f", b);
    printf("\nEULER = %f", a);;
}
