# include <stdio.h>

/* Converts a table of Fahrenheit temperatures to Celsius,
for fahr = 0, 20, ..., 300 */

int main() {
    float fahr, celsius;
    int lower, upper, step;
    float x = 10.5; // Can initialise and assign variables in one go

    lower = 0;
    upper = 300;
    step = 20;

    printf("x=%.1f\n", x); // %f to print floats, the .1 governs numbers of decimal places (rounds up if 2nd dp is >=6, else down)
    printf("%.1f\n", 10.45); // prints 10.4
    printf("%.1f\n", 10.46); // prints 10.5
    printf("%d\n", 100); // %d to print ints

    printf("\nFahrenheit-to-Celsius:\n");
    fahr = lower;
    while (fahr <= upper) {
        
        // Note: since fahr is float, the below performs float division; but if had term (5/9) - this would perform integer division;
        celsius = 5 * (fahr-32)/9; 
        
        // However making use of floats explicit is good practice:
        celsius = (5.0/9.0) * (fahr - 32.0);
        
        printf("%3.0f %6.1f\n", fahr, celsius); // The numbers before the decimal point . ("%3.0f") specify the width of the field - which, here, print the column as right-justified
        fahr = fahr + step;
    }
}