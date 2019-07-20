/* 
Exercise 1.20: Detab - replace tabs in the input with proper number of blanks to space to the next tab stop 

NOTE: tab works in blocks of 8 - so if I've entered '123456', the tab would then add 2 spaces, whereas '1234' + tab would add 4 spaces: 
'123456  '
'1234    '
'1       '
etc

This cycles to the next tab block if have exceeded 8 chars:
'12345678abcd    '
'12345678abcdef  '

For successive tabs, the first completes the current block, then the next is a full block of 8:
'1234567         '
'1234            '

(Above is at least per my WSL Ubuntu 18.04 terminal, and VS Code - so perhaps this is a standard)
*/

#include <stdio.h>

#define MAXLINE 1000 // max input line size
#define TAB_WIDTH 8 // number of blank chars a tab corresponds to

// Function prototypes
int get_line_length(char line[], int limit); // reads a char array representing a line and the a size limit, returns the length of the line
void copy(char from[], char to[]);

int main(void)
{
    int len; // length of current line
    char line[MAXLINE]; // character array to store current line

    while((len = get_line_length(line, MAXLINE)) > 0){       
        
        // Reinitialise the output array with each input line, as otherwsie can carry-forward input from previous lines 
        char detab_line[MAXLINE] = "";
        copy(line, detab_line);
        printf("%s\n", detab_line);
    }
}


int get_line_length(char line[], int limit)
{
    /* Modifies the line char array (in-place, as pass-by-ref), inputting each user input character until it encounters a newline or EOF; the newline char counts towards the line length (so an "empty" line is of length 1) 
    Also returns the line's length, incrementing it from 0 as the user inputs chars.  */
    int c, len;

    // Note: using limit below, instead of (limit - 1) results in a Segmentation Fault at runtime if the line length (including newline) equals or exceeds MAXLINE
    for (len=0; (len < limit - 1) && ((c=getchar()) != EOF) && (c != '\n'); len++)
    {
        line[len] = c;
    }

    if (c=='\n')
    {
        line[len] = c;
        len++;
    }
    
    line[len] = '\0'; // Used here to signify end-of-line - it's the "null character", i.e. the char whose value is 0; C itself signifies the end of strings with null, so this follows that convention
    return len;
}


void copy(char from[], char to[])
{
    int from_counter=0;
    int to_counter=0;
    int tab_block=0; // tracks where in the tab's block of 8 chars we are (originally kept track using the from_counter, but was incorrect for successive tabs)
    int tab_spaces=0; // number of remaining spaces in the tab block 

    while(from[from_counter] != '\0' && from[from_counter] != '\n'){   
        
        // If copying tab space, instead copy in the appropriate number of blank spaces; else copy the char as-is
        if(from[from_counter] == '\t'){
            tab_spaces = TAB_WIDTH - (tab_block % TAB_WIDTH);
            for(int j=0; j<tab_spaces; j++){
                to[to_counter] = '-';
                to_counter++;
            }
            
            // Reset tab location:
            tab_block = 0;     
        
        } else{
            to[to_counter] = from[from_counter];
            to_counter++;
            tab_block++;
        }    
        from_counter++;
    }
}
