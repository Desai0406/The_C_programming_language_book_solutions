#include <stdio.h>
int main()
{
    int c;

    printf("Enter your input: ");

    while((c = getchar()) != '\n')
    {
        if (c == '\t')
        {
            printf("\\t");
        }

        if (c == '\b')
        {
            printf("\\b");
        }

        if (c == '\\')
        {
            printf("\\\\");
        }

        if (c != '\t')
        {
            if (c != '\b')
            {
                if (c != '\\')
                {
                    putchar(c);
                }
            }
        }
    }
    return 0;
}