#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main(void)
{
    int i;
    signed int si;
    unsigned int ui;
    short int sh;
    long int lng;

    char c;
    signed char sc;

    float f;
    
    double d;
    long double ld;

    printf("C Data Type Sizes (Bytes)\n\n");

    printf("int: %zu\n", sizeof(i));
    printf("signed int: %zu\n", sizeof(si));
    printf("unsigned int: %zu\n", sizeof(ui));
    printf("short int: %zu\n", sizeof(sh));
    printf("long int: %zu\n\n", sizeof(lng));
    
    printf("Test int range:\n");

    printf("int range (limits.h): [%d, %d]\n", INT_MIN, INT_MAX);
    printf("int range calc:       [%.0f, %.0f]\n\n",
     -1 * pow(2, (8 * sizeof(i)) - 1), 
     pow(2, (8 * sizeof(i)) - 1) - 1);

    int my_int_max = pow(2, 31) - 1;
    int my_int_min = -1 * pow(2, 31);
    printf("my_int_max    :    %d\n", my_int_max);
    printf("my_int_max + 1:   %d\n", my_int_max + 1);
    printf("my_int_min    :   %d\n", my_int_min);
    printf("my_int_min - 1:    %d\n\n", my_int_min - 1);

    printf("Test unsigned int range:\n");
    printf("uint max (limits.h):   %u\n", UINT_MAX);
    printf("uint max (calc)    :   %.0f\n", pow(2, (8 * sizeof(ui))) - 1);
    
    unsigned int uint_max = pow(2, 32) - 1;
    printf("uint max + 1 (calc):   %u\n\n", uint_max + 1);

    printf("Octal and Hexadecimal:\n");
    int octal_16 = 020;
    int hexa_16 = 0x10;
    printf("Octal 16        : %d\n", octal_16);
    printf("Hexadecimal 16  : %d\n", hexa_16);

    printf("char: %zu\n", sizeof(c));
    printf("signed char: %zu\n\n", sizeof(sc));

    printf("float: %zu\n\n", sizeof(f));

    printf("double: %zu\n", sizeof(d));
    printf("long double: %zu\n", sizeof(ld));

}