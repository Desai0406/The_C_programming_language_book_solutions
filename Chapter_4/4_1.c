// Returns index of last pattern match in source string
#include <stdio.h>
#include <string.h>

char patternorig[100] = "ould";

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

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
    reverse(string);
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
            reverse(string);
            printf("The pattern is found starting at index: ");
            return (strlen(string) - strlen(pattern) - i);
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
    reverse(patternorig);

    printf("%d", strindex(stringorig, patternorig));

    return 0;
}