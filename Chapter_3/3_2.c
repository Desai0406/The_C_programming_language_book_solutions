#include <stdio.h>
#include <string.h>

char * escape(char s[], char t[])
{
    int length = strlen(t);
    int j; // As the size difference of resulting (copied array) and original input array is different, A second iterator should be used while the first should iterate the original array till it ends. 

    for (int i = j = 0; i < length; j++, i++)
    {
        switch (t[i])
        {
        case '\t': 
            s[j] = '\\';
            j++;
            s[j] = 't';
            break;
        
        default:
            s[j] = t[i];
            break;
        }
    }
    return s;
}

int main()
{
    int length = 0;
    char c;
    char * cpstring;

    char tstring[100]; // Declaring array tstring
    char sstring[100]; // Declaring array sstring

    for (int i = 0; i < 100; i++) // Initializing the arrays
    {
        tstring[i] = 0;
        sstring[i] = 0;
    }  
    
    printf("Enter a string: "); // Taking input for array tstring
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        tstring[i] = c;
    }

    cpstring = escape(sstring, tstring);
    printf("%s", cpstring);

    return 0;
}