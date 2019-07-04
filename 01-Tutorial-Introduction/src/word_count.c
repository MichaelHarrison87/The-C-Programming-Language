#include <stdio.h>

#define IN 1 // inside the word
#define OUT 0 // outside the word

/* Count lines, words and chars in the input */

int main(){
    int c; 
    int num_lines, num_words, num_chars;
    int state;

    state = OUT;
    num_lines = num_words = num_chars = 0;

    while ((c = getchar()) != EOF) {
        num_chars++;

        if (c == '\n')
            num_lines++;
        
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
        } 
        else if (state == OUT) {
            state = IN;
            num_words++;
        }
    }

    printf("\nNum chars: %d\n", num_chars);  
    printf("Num lines: %d\n", num_lines);      
    printf("Num words: %d\n", num_words);     
}