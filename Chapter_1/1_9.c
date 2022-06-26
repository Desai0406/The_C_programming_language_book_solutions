#include <stdio.h>
#define NONBLANK 'a' // #define  (what to replace)  (in place of what in the program)
int main()
{
    char c;
    int lastc = NONBLANK;

    printf("Enter your input: ");
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            putchar(c);
        }

        if (c == ' ')
        {
            if (lastc != ' ')
            {
                putchar(c);
            }   
            else
            {
                ; // do nothing hence not printing a blank i.e. putchar(c), where c is a blank character is not printed.
            }
                     
        }
        lastc = c;
    }
    
    return 0;
}