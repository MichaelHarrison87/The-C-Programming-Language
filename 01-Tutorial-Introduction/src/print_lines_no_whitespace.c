#include <stdio.h>
#define MAXLINE 1000 // max input line size

// Function prototypes
int get_line_length(char line[], int limit); // reads a char array representing a line and the a size limit, returns the length of the line


int main(void)
{
    /* Prints each without leading or trailing whitespace (tabs, spaces) */
    int len; // length of current line
    char line[MAXLINE]; // character array to store current line
    int lead_end, trail_start; // indices for the end of the leading whitespace, and start of trailing whitespace

    while((len = get_line_length(line, MAXLINE)) > 0){
        lead_end = trail_start = 0; // reset for each line

        // print whole line by char, for reference:
        printf("Len: %d\n", len);
        printf("Ref Line: ");
        for (int i=0; i<len; i++)
            printf("'%c': %d", line[i], (line[i] != ' ') && (line[i] != '\t')); 
        printf("\nLead: %d, Trail: %d", lead_end, trail_start);
        printf("\n--------------------\n");

        // Find end of leading whitespace: walk through each char until encounter non-whitespace
        int i = 0;
        while ((i < len) && ((line[i] == ' ') || (line[i] == '\t'))){
            i++;   
        }
        lead_end = i;

        // Find end of trailing whitespace - walk backwards through the line until encounter non-whitespace
        int j = len-1;
        while ((j >= 0) && (trail_start == 0)){
             if ((line[j] != ' ') && (line[j] != '\t'))
                trail_start = j;
            j--;            
        }

        if (lead_end == 0 && trail_start == 0){
            printf("Both 0: %d %d\n", lead_end, trail_start);
            printf("%s",line);
        } else{
            printf("Lead End: %d, Trail Start: %d\n", lead_end, trail_start);
            printf("Remove Whitespace: '");
            for (int i = lead_end; i<= trail_start; i++){
                printf("%c", line[i]);
            }
            printf("'");
        }
        printf("\n--------------------\n");
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

    // if (c=='\n')
    // {
    //     line[len] = c;
    //     len++;
    // }
    
    line[len] = '\0'; // Used here to signify end-of-line - it's the "null character", i.e. the char whose value is 0; C itself signifies the end of strings with null, so this follows that convention
    return len;
}