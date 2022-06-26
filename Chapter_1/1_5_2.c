#include <stdio.h>
int main()
{
    char c;
    int count;

    // printf("\nEnter a string or character and place a '-' after you are done with your input.\n");

    count = 0;

    while ((c = getchar()) != '\n'){
        count = count + 1;
    }
    
    printf("The count is: %d", count);
    return 0;
}

// #include <stdio.h>
// int main()
// {
//     int count;
//     int c;
    
//     printf("\nEnter your strings here: ");
//     for (count = 0; (c = getchar()) != '\n'; ++count)
//     {
//        ;
//     }

//     printf("The number of characters inputted are: %d", count);
    
//     return 0;
// }