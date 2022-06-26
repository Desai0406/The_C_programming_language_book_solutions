#include <stdio.h>
int main()
{
    int c, i, bspaces, other;
    int digit[10];

    bspaces = other = 0; 
    for (int i = 0; i <= 9; i++) // initializing the array
    {
        digit[i] = 0;
    }

    printf("Enter your input: \n");

    while ((c = getchar()) != '-')
    {
        if (c >= '0' && c <= '9')
        {
            ++digit[c - '0']; // why not ++digit[c]; ?
            // putchar(c);
        }

        else if (c == '\n' || c == '\t' || c == ' ')
        {
            ++bspaces;
            // putchar(c);
        }

        else
        {
            ++other;
            // putchar(c);
        }
    }

    printf("The digit Array: \n");
    for (int i = 0; i <= 9; i++)
    {
        printf("Number of %d's: %d\n", i, (digit[i]));
    }

    printf("Blank spaces: %d\n", bspaces);
    printf("Other digits: %d\n", other);   
    return 0;
}