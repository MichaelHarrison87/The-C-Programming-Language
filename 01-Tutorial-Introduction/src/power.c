#include <stdio.h>

// Function prototype - illustrates format of function; declaration and implementation of it must agree. e.g. is base below is float, get compiler error
// Function prototypes are not strictly necessary, but are apparently good practice/convention (?)
int power(int m, int n);


int main(void)
{
    for(int i = 0; i<10; i++)
    {
        printf("%d^3 = %d\n", i, power(i,3));
    }
}

int power(int base, int n)
{
    /* Raises base to n^th power; e.g. power(2,5)=32 */
    int result = 1;

    for(int i=0; i<n; i++)
    {
        result = result * base;
    }
    return result;
}