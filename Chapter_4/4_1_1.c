// Returns index of first pattern match in source string
#include <stdio.h>
#include <string.h>

char patternorig[100] = "ould";

int get_line(char string[], int len)
{
    int i = 0;
    char c;

    while (i < len && (c = getchar()) != '\n')
    {
        string[i] = c;
        i++;
    }
    string[i] = '\0';

    return i;
}

int strindex(char string[], char pattern[])
{
    int j, k, i;
    for (i = 0; string[i] != '\0'; i++)
    {
        for (j = i, k = 0; pattern[k] != '\0', string[j] == pattern[k]; j++, k++)
        {
            ;
        }   

        if (k > 0 && pattern[k] == '\0')
        {
            return i;
        }
    }
    return -1;    
}

int main()
{
    char stringorig[100];

    int maxlen = 100;
        
    printf("Enter your string: \n");
    get_line(stringorig, maxlen);
    printf("Pattern at: %d\n", strindex(stringorig, patternorig));

    return 0;
}