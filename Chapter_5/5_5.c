// Strcpy for first n elements using pointers only
#include <stdio.h>

void strcatn(char *s, char *t, int n) // Copy first n elements of string t to string s
{
    while (*s != '\0')
    {
        s++;
    }

    for (int i = 0; i < n; i++, s++, t++)
    {
        *s = *t;
    }
}

void strcpyn(char *s, char *t, int n)
{
    int i = 0;
    while (i < n)
    {
        *s++ = *t++;
        i++;
    }
}

int strcmpn(char *s, char *t, int n)
{
    int i = 0;
    while (i < n)
    {
        if (*s++ == *t++)
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1; 
}

int main()
{
    char arr1[] = "Hello sir"; // Placed as global to initialize for strcat
    char arr2[] = "Hell y are you"; // Use char arrays as per need.

    // string concat
    // printf("%s\n", arr1);  // Before
    // strcpyn(arr1, arr2, 5);
    // printf("%s", arr1);  // After

    // string copy
    // printf("%s\n", arr1); // Before
    // strcpyn(arr1, arr2, 7);
    // printf("%s", arr1); // After

    // string compare
    // printf("%d", strcmpn(arr1, arr2, 4));

    return 0;
}