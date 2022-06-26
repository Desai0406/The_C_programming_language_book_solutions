#include <stdio.h>
#include <string.h>
char *squeeze(char s1[], char s2[]) // Matching chars and deleting if same
{
    int i, j, s2len, flag;
    i = j = flag = 0;

    s2len = strlen(s2);

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        flag = 0;
        for (int k = 0; k < s2len; k++)
        {
            if (s1[i] == s2[k])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            s1[j] = s1[i];
            j++;
        }
    }
    s1[j] = '\0';
    return s1;
}

void print(char arr[]) // Printing function
{ 
    printf("The processed string is: ");
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i]);
    }
}

int main()
{   
    char str1[100];
    char str2[100];
    char *str;

    printf("Enter your string 1: ");
    scanf("%s", str1);
    printf("Enter your string 2: ");
    scanf("%s", str2);

    str = squeeze(str1, str2);
    print(str);
    return 0;
}