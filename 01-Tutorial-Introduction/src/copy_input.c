#include <stdio.h>

/* Uses getchar() to parse any input char-by-char, then prints it out with putchar() */

int main(){
    int c; // represent input as int, rather than char, as need to accomodate the end-of-file EOF indicator (which char doesn't)
    
    // EOF below is a symbolic constant from stdio.h, an integer outside the bounds of the ints that represent chars - so that it indentifies the end-of-file without being confused for a char
    while ((c = getchar()) != EOF) {
        putchar(c);
    }      
}