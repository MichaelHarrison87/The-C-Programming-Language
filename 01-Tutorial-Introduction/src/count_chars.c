#include <stdio.h>

/* Uses getchar() to parse any input char-by-char, then counts the number of chars*/

int main(){
    long cnt = 0;

    // EOF below is a symbolic constant from stdio.h, an integer outside the bounds of the ints that represent chars - so that it indentifies the end-of-file without being confused for a char
    while (getchar() != EOF) {
        cnt++; // can also treat ++ as an operator and prefix it - ++cnt; would also work here
    }      
    printf("\nNumbers of chars is: %ld\n", cnt);
}