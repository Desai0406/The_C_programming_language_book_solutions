// **********************************************************Getline********************************************************
// #include <stdio.h>
// int getlinep(char *s)
// {
//     int c;
//     char *bs = s;
//     while (*s++ != '\0')
//     {
//         ;
//     }
//     return (s-bs);
// }

// int main()
// {
//     char arr[100], c;
//     int i;

//     printf("Enter a string: ");
//     for (i = 0; (c = getchar()) != '\n'; i++)
//     {
//         arr[i] = c;
//     }
//     arr[i] = '\0';
    
//     printf("The length of array is: %d", getlinep(arr));
//     return 0;
// }

// ******************************************************atoi***********************************************
#include <stdio.h>
void atoi(char *s)
{
    while (*s != '\0' && '0' <= *s <= '9')
    {
        *s = (*s - 48);
        s++;
    }
}

int main()
{
    char arr[] = "1987";
    char *arrp = arr;
    atoi(arr);
    for (int i = 0; *arrp != '\0'; arrp++)
    {
        printf("%d", *arrp);
    }
    
    return 0;
}
