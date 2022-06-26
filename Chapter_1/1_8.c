#include <stdio.h>
int main()
{
    int tabs;
    char c;

    printf("Enter your string(s): ");
    tabs = 0;
    while ((c = getchar()) != '-')
    {
        if (c == '\t') // Change and place the desired escape sequence character here to count its occurance.
        {
            tabs = tabs + 1;
        }
    }
    printf("The number of tabs are: %d", tabs);
    return 0;
}

// version 2 using for loop.
// #include <stdio.h>
// int main()
// {
//     int count;
//     char c;

//     count = 0;
//     printf("Enter your input: ");
//     for (char c = 0; (c = getchar()) != '-'; c++)
//     {
//         if (c == '\n')
//         {
//             count++;
//         }
//     }
//     printf("The number of lines are: %d", count);
//     return 0;
// }