#include <stdio.h>
#define OUT 0 // out of word
#define IN 1 // In the word
#define LASTC 'a'
int main() // Count characters, words and lines
{
    int lines, words, c, chct;
    char lastc; 
    chct = lines = words = 0;
    lastc = ' ';

    printf("Enter your string: \n");

    while ((c = getchar()) != '-')
    {
        ++chct;
        if (c == '\n')
        {
            ++lines; // logic is correct as the lines seem empty (empty space of size 3 lines is visible but they are escape characters, hence invisible but existing.)
        }

        if (c == '\n' || c == '\t' || c == ' ') // check for if (c == '' || '' || ''  ) --> Wrong results 
        {
            if (lastc == '\t' || lastc == ' ' || lastc == '\n')
            {
                putchar(c);
            }
    
            else
            {
                ++words;
                putchar(c);
            }
        }

        else
        {
            putchar(c);
        }
        lastc = c;
    }

    printf("\nThe number of lines: %d\n", lines);
    printf("The number of words: %d\n", words);
    printf("The number of characters: %d\n", chct);
    
    return 0;
}