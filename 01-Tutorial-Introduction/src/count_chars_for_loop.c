#include <stdio.h>

/* Same as count_chars, but use a for loop*/

int main(){
    long cnt;
    for (cnt=0; getchar() != EOF; cnt++) {
        ; // for loop must have a body, but we leave it empty
    }      
    printf("\nNumbers of chars is: %ld\n", cnt);
}