// Concat strings using pointers
#include <stdio.h>

void strcatp(char *s, char *t)
{
    while (*s != '\0') // While value at address s is not equal to null...
    {
        s++; // Increment address by 1
    }

    while ((*s++ = *t++) != '\0') // For both while loops, the (not equal to null) part can be emitted as while condition stops at null value automatically.
    {
        ;
    }    
}


int main()
{
    char arr1[20] = "Hello sir", arr2[20] = ", how are youuu?"; 
    printf("%s\n", arr1);
    strcatp(arr1, arr2);
    printf("%s", arr1);
    
    return 0;
}