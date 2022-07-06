// Recursion for reverse function in a string
#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int c;
    static int i = 0;
    static int j = 99; 

    if (i < j)
    {
        i++; 
        j--;
        reverse(s);   
    }
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        c = 0;

        i--;
        j++;
}

char string[100]; // Array declared here

int main()
{
    char c;
    int i;
  
    printf("Enter your string: ");
    for (i = 0; (c = getchar()) != '\n'; i++)
    {
        string[i] = c;
    }
    string[100] = '\0';

    reverse(string);

    for (int i = 0; i < 100; i++)
    {
        printf("%c", string[i]);
    }
    
    return 0;
}