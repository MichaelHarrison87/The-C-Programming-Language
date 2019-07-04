# include <stdio.h>

// #define is used to specify symbolic constants (which are distinct from variables) of key importance. By convention they're written in upper case
// They are used essentially to tell the compiler that these values will never change
#define LOWER 0
#define UPPER 300
#define STEP 20
#define TITLE "Celsius-to-Fahrenheit" // symbolic constants can also be strings (and likely other things too)

/* Converts a table of Celsius temperatures to Fahrenheit,
for cels = 300, 280, ..., 0 */

int main() {
    float celsius;

    // Here we'll use a for() loop to print in reverse order
    printf("\n%s:\n", TITLE); // %s to print string
    for (celsius = UPPER; celsius >= LOWER; celsius = celsius - STEP){      
        printf("%3.0f %6.1f\n", celsius, (9.0 * celsius/5.0) + 32.0);
    }

    // Note the below is illegal as it tries to modify a symbolic constant (cf: variables, which can be given new values)
    // LOWER = LOWER + STEP;
    // printf(LOWER);
}