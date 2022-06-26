#include <stdio.h>
#include <string.h>

int squeeze(char s1[], char s2[]) 
{
    int i, j, s2len, flag;
    i = j = flag = 0;

    s2len = strlen(s2);

    for (i = 0; s1[i] != '\0'; i++)
    {
        flag = 0;
        for (int k = 0; k < s2len; k++)
        {
            if (s1[i] == s2[k])
            {
                flag = 1;
                printf("The letter %c is found in your string 2 at index position: ", s1[i]);
                return i;
            }
        }
    }
    s1[j] = '\0';

    if (flag == 0)
    {
        return -1;
    }
}

int main()
{   
    char str1[100];
    char str2[100];
    int ind;

    printf("Enter your string 1: ");
    scanf("%s", str1);
    printf("Enter your string 2: ");
    scanf("%s", str2);

    ind = squeeze(str1, str2);
    printf("%d", ind);
    return 0;
}