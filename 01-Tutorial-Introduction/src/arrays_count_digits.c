#include <stdio.h>

/* Count numbers of digits, whitespace & other char in input */

int main(void){
    int c; 
    int num_whitespace, num_other;
    int digit_counts[10];

    // initialise counts
     num_whitespace = num_other = 0;
     for (int i=0; i<10; i++)
     {
         digit_counts[i] = 0;
     }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
        {
            digit_counts[c-'0']++;
        }
        else if (c ==' ' || c == '\t' || c == '\n') 
        {
            num_whitespace++;
        }
        else
        {
            num_other++;
        }
 
    }

    for (int i =0; i<10; i++)
    {
        printf("\nNum %d: %d", i, digit_counts[i]);
    }
    printf("\nNum whitespace: %d\n", num_whitespace);      
    printf("Num others: %d\n", num_other);     
}