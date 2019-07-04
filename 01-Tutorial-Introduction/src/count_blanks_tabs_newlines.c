#include <stdio.h>

/* Like count_chars, but counts number of blank spaces, tabs and newlines in input*/

int main(){
    int c, cnt_blanks, cnt_tabs, cnt_newlines;

    cnt_blanks = 0;
    cnt_tabs = 0;
    cnt_newlines = 0;

    while ((c = getchar()) != EOF) {
        
        // blanks
        if (c == ' '){
            cnt_blanks++;
        }
                
        // tabs
        if (c == '\t'){
            cnt_tabs++;
        }

        // newlines 
        if (c == '\n'){
            cnt_newlines++;
        }
    }      
    printf("\nNumber of blanks is: %d\n", cnt_blanks);
    printf("Number of tabs is: %d\n", cnt_tabs);
    printf("Number of newlines is: %d\n", cnt_newlines);
}