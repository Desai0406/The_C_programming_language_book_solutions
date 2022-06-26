#include <stdio.h>
int main()
{
    int lim = 10;
    char c = 'a';
    char s[lim];

    printf("Enter string: ");
    for (int i = 0; i < lim; i++)
    {
        if ((c = getchar()) == '\n')
        {
            break;
        }
        
        s[i] = c;
    }
    
    s[lim] = '\0';
    printf("%s", s);
    return 0;
}