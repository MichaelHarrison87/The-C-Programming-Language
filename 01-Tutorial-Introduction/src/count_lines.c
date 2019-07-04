#include <stdio.h>

/* Like count_chars, but counts number of lines in input
NB: CTRL+D is the shortcut for EOF*/

int main(){
    int c, cnt;

    cnt = 1; // start counting from 1 for the first line of input
    while ((c = getchar()) != EOF) {
        if (c == '\n'){ // note: need '\n' here, not "\n", as single-quotes (' ') gives the integer value of the given character
            cnt++;
        }
    }      
    printf("\nNumbers of lines is: %d\n", cnt);
    printf("c\n"); // prints c
    printf("%d\n", 'c'); // prints 99
    printf("EOF int value: %d\n", EOF); // prints -1
    // printf("%d\n", 'cc'); // doesn't work - can't enclose more than 1 char in ' '
}