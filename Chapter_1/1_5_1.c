#include <stdio.h>
int main()
{
    int c;

    printf("Enter your input character: \n");

    while ((c = getchar()) != '\n'){
        printf("The output character is: ");
        putchar(c);
        printf("\n");
        // c = getchar(); // This will skip 1 extra character by incrementing at the while loop start.
    }

    return 0;
} 