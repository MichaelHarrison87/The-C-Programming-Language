#include <stdio.h>

#define MAXLINE 1000

/* Set the below as global variables - so their values can be used in several functions, and persist across several function calls */ 
int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
void copy(void);

int main(void)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = get_line()) > 0){
        if(len > max){
            max =  len;
            copy();
        }
    }
    
    // Print the longest line
    if (max > 0){
        printf("\n%s\n", longest);
    }
}

int get_line(void)
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && ((c = getchar()) != EOF) && (c != '\n'); i++){
        line[i] = c;
    }

    if (c == '\n'){
        line[i] = c;
        i++;
    }

    line[i] = '\0';
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0'){
        i++;
    }
}