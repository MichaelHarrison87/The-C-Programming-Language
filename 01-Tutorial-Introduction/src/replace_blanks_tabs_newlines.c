#include <stdio.h>

/* Repeats input provided back to the user, but replaces blank spaces, tabs and newlines by "_", "\t" & "\n"  */

int main(){
    int c;
    while ((c = getchar()) != EOF) {
        
        switch(c){
            case ' ':  putchar('_');                break;
            case '\t': putchar('\\'); putchar('t'); break;
            case '\n': putchar('\\'); putchar('n'); break;
            case '\b': putchar('\\'); putchar('b'); break;
            case '\\': putchar('\\');               break;
            default:   putchar(c);                  break;
        }
     
    }      
}