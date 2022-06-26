#include <stdio.h>
int main()
{
    char c;
    int lastc;

    printf("Input your string here: \n");

    while ((c = getchar()) != '-')
    {      
        if ((c == ' ') || (c == '\t') || (c == '\n'))
        {
            if ((lastc == ' ') || (lastc == '\t') || (lastc == '\n'))
            {
                ;
            }

            else
            {
                printf("\n");
            }
        }

        else
        {
            putchar(c);
        }
    lastc = c;
    }
    return 0;
}

