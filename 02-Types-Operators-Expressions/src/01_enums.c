#include <stdio.h>

// enums let us associate sequences of names with sequences of integers:
// Specify them outside of main - they're used in lieu of #define constants

enum abc {a, b, c}; // integer sequences starts at 0 by default
enum def {d=4, e, f}; // but can specify alternative starting points
enum ghi {g=50, h=100, i=-6}; // and can specify the integer corresponding to each name individually
enum year {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}; // can use enum integer values in a for loop
enum skip {one = 1, two, three, seven = 7, eight, twelve = 12, thirteen}; // successive enum names increment the previous name's integer value, but can remap values further along the list

// Note: enum names must be unique across the entire program (not just within individual enums), or else get a compilation error 
// e.g. enum new {a, bb, cc} wouldn't be permitted as name 'a' is already taken in abc above

int main(void){
    printf("\na: %d", a);
    printf("\nb: %d", b);
    printf("\nc: %d\n", c);

    printf("\nd: %d", d);
    printf("\ne: %d", e);
    printf("\nf: %d\n", f);

    printf("\ng: %d", g);
    printf("\nh: %d", h);
    printf("\ni: %d\n\n", i);

    for (int i = JAN; i <= DEC; i++){
        printf("Month %d\n", i);
    }

    printf("\n\none: %d", one);
    printf("\ntwo: %d", two);
    printf("\nthree: %d", three);
    printf("\nseven: %d", seven);
    printf("\neight: %d", eight);
    printf("\ntwelve: %d", twelve);
    printf("\nthirteen: %d\n\n", thirteen);
}
