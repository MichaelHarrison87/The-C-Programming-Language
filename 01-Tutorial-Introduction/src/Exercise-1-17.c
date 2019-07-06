/* 
Exercise 1.17: Print only lines that are longer than some given length 
*/

#include <stdio.h>
#define MAXLINE 1000 // max input line size
#define MINLINE 4 // only prints lines longer than this many characters

// Function prototypes
int get_line_length(char line[], int limit); // reads a char array representing a line and the a size limit, returns the length of the line

int main(void)
{
    int len; // length of current line
    char line[MAXLINE]; // character array to store current line

    while ((len = get_line_length(line, MAXLINE)) > 0){
        if (len > MINLINE + 1) // don't count the newline char
            printf("\n%s\n", line);
    }
    printf("\n");
}


int get_line_length(char line[], int limit)
{
    /* Modifies the line char array (in-place, as pass-by-ref), inputting each user input character until it encounters a newline or EOF; the newline char counts towards the line length (so an "empty" line is of length 1) 
    Also returns the line's length, incrementing it from 0 as the user inputs chars.  */
    int c, len;

    // Note: using limit below, instead of (limit - 1) results in a Segmentation Fault at runtime if the line length (including newline) equals or exceeds MAXLINE
    for (len=0; (len < limit - 1) && ((c=getchar()) != EOF) && (c != '\n'); len++)
        line[len] = c;

    // Don't print the newline char
    if (c=='\n'){
        len++;
        line[len] = '\0';
    } else{
        line[len] = '\0'; // Used here to signify end-of-line - it's the "null character", i.e. the char whose value is 0; C itself signifies the end of strings with null, so this follows that convention
    }
    return len;
}