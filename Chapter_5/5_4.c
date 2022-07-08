// Find prescence of string 2 in string 1's end
#include <stdio.h>

int strend(char *s, char *t)
{
    char *bs = s;
    while (*s != '\0')
    {
        s++;
    }

    char *bt = t;
    while (*t != '\0')
    {
        t++;
    }

    for (s, t ; *s == *t; s--, t--)
    {
        if (*t == *bt)
        {
            break;
        }   
    }

    if (*s == *t && *t == *bt && *s != '\0') // add * from t = bt
    {
        return 1;
    }
    
    return 0;
}

int main()
{
    char arr1[] = "Hello sir How are you";
    char arr2[] = "How are you";
    printf("%d", strend(arr1, arr2));
    return 0;
}