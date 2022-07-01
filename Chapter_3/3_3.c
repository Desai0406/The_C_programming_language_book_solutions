#include <stdio.h>
#include <string.h>
void expand(char s1[], char s2[])
{
    char c;
    int i, j;
    i = j = 0;

    while ((c = s1[i++]) != '\0')
    {
        if (s1[i] == '-' && s1[i + 1] >= c)
        {
            i++;
            while (c < s1[i])
            {
                s2[j] = c;
                j++;
                c++;
            }   
        }

        else
        {
            s2[j] = c;
            j++;
        }
    }
    s2[j] = '\0';
}

int main()
{
    char arr1[100];
    char arr2[100];
    char c;

    for (int i = 0; i < 100; i++)
    {
        arr1[i] = arr2[i] = 0;
    }

    printf("Enter your string: ");
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        arr1[i] = c;
    }
    
    expand(arr1, arr2);
    printf("%s", arr2);

    return 0;
}