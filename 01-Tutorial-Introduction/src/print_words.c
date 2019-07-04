#include <stdio.h>

#define IN 1 // inside the word
#define OUT 0 // outside the word

/* Prints input, one word per line */

int main(void)
{
    int c, state;
    state = IN;

    while ((c = getchar()) != EOF) 
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        } 
        else if (state == OUT) 
        {
            state = IN;
            putchar('\n');
        }
        putchar(c);
    }

}